<?php

/**
 * @file
 * This file describes the MM plugin as implemented by Acadre
 */

// Set this to the publication-id ie. 1577 for file XML_1577.
define('ACADRE_MM_PUB_FOCUS', FALSE);
// Misc. magic numbers.
define('ACADRE_MM_ACCESS_OPEN', 1);
define('ACADRE_MM_ACCESS_LUKKET', 2);
define('ACADRE_MM_ACCESS_PERSON', 3);
define('MM_REPUBLISH_SUBVERSION', TRUE);

/**
 * Plugin definition with callbacks
 */
$plugin = array(
  'description' => t('Acadre ESDH MM Backend'),
  'version' => 1,
  'test' => 'os2web_acadre_esdh_mm_test',
  'get_import_list' => 'os2web_acadre_esdh_mm_get_import_list',
  'import_meeting' => 'os2web_acadre_esdh_mm_import_meeting',
  'post_import_process' => '_os2web_acadre_esdh_mm_order_addenums',
);

/**
 * For plugin testing purposes.
 */
function os2web_acadre_esdh_mm_test($stuff) {
  return 'Test successful. Recieved: ' . $stuff;
}

/**
 * Returns a list of meeting_ids for import. In our case a list of uri's of xml files.
 *
 * @return array
 *   List of URIs
 */
function os2web_acadre_esdh_mm_get_import_list() {
  /*
   * For the acadre service, we need to miport meetings from xml files.
   * We will enumerate the list with the publication-id as parsed from the filename.
   */

  // Debug bit set in os2web_esdh_provider settings.
  $debug = variable_get('os2web_esdh_provider_debug_info');

  $uris = array();
  foreach (file_scan_directory(variable_get('os2web_meetings_path', ACADRE_MM_IMPORT_DIR), '/\.xml$/i', array('recurse' => FALSE)) as $xml_file) {
    $pub_id = (int) str_replace('XML_', '', $xml_file->name);
    if (is_numeric($pub_id)) {
      $uris[] = array('id' => $pub_id, 'uri' => $xml_file->uri);
    }
    else {
      $uris[] = array('id' => $xml_file->name, 'uri' => $xml_file->uri);
    }
  }
  if (ACADRE_MM_PUB_FOCUS !== FALSE) {
    // We wish to only handle a single publication, så we return only that.
    if (isset($uris[ACADRE_MM_PUB_FOCUS])) {
      $uris = array(
        ACADRE_MM_PUB_FOCUS => $uris[ACADRE_MM_PUB_FOCUS],
      );
    }
  }

  $debug && error_log('MM Import - ' . count($uris) . ' uris found.');
  return $uris;
}

/**
 * Imports a meeting, and return the import as a structured array.
 *
 * @param object $meeting
 *   Meeting XML object.
 *
 * @return array
 *   List of meeting_structures to save
 */
function os2web_acadre_esdh_mm_import_meeting($meeting) {
  // Debug bit set in os2web_esdh_provider settings.
  $debug = variable_get('os2web_esdh_provider_debug_info');

  $file = $meeting['uri'];
  if ($file === FALSE) {
    os2web_meetings_order_addenums();
  }
  $meetings = array();
  if (is_file(drupal_realpath($file))) {
    $manifest = simplexml_load_file(drupal_realpath($file));
    if (is_object($manifest)) {
      $agenda_id = (int) array_shift($manifest->xpath("/root/table[@name='agenda']/fields/field/@sysid"));
      $items_xml = $manifest->xpath("//table[@name='producedAgenda']/fields");
      if (empty($items_xml)) {
        watchdog('acadre MM', 'Empty list of import items in %file.', array('%file' => $file), WATCHDOG_WARNING);
      }
      foreach ($items_xml as $xml_item) {
        $debug && error_log('MM Import - Found meeting ' . $meeting['uri'] . ' - '. timer_read('mm_import') . 'ms');
        $agendainfo = array(
          // 'sysid' => (int) array_shift($xml_item->xpath('field/@sysid')),
          'sysid' => $agenda_id,
          'publish' => (int) array_shift($xml_item->xpath('field/@publish')),
          'access' => (string) array_shift($xml_item->xpath('field/@access')),
          'filesfolder' => (string) array_shift($xml_item->xpath('field/@filesfolder')),
          'xmlfilename' => (string) array_shift($xml_item->xpath('field/@xmlfilename')),
          'docfilename' => (string) array_shift($xml_item->xpath('field/@docfilename')),
          'type' => (int) array_shift($xml_item->xpath('field/@type')),
        );

        if ($agendainfo['publish'] === 1 &&
            $agendainfo['access'] !== 'Lukket' &&
            $agendainfo['filesfolder'] != '') {
          $agenda_uri = implode('/', array(
            variable_get('os2web_meetings_path', ACADRE_MM_IMPORT_DIR),
            $agendainfo['filesfolder'],
            $agendainfo['xmlfilename']));
          $agendainfo['agenda_uri'] = $agenda_uri;
          $imported = _os2web_acadre_esdh_import_meeting($agendainfo);

          if (is_array($imported)) {
            $imported['publish'] = TRUE;
            $imported['meeting_sub_id'] = (int) array_shift($xml_item->xpath('field/@sysid'));
            $imported['agenda_xmlid'] = (int) array_shift($xml_item->xpath('field/@xmlFusionID'));
            $meetings[] = $imported;
          }

        }
        else {
          $message = 'Meeting !id, agenda !sub_id, wasnt allowed to be published from xml !file. [publish]=!publish, [access]=!access, [filesfolder]=!filesfolder';
          $entries = array(
            '!id' => $agenda_id,
            '!sub_id' => (int) array_shift($xml_item->xpath('field/@sysid')),
            '!publish' => $agendainfo['publish'],
            '!access' => $agendainfo['access'],
            '!filesfolder' => $agendainfo['filesfolder'],
            '!file' => $file,
          );
          watchdog('acadre MM', $message, $entries, WATCHDOG_WARNING);
          if (function_exists('_os2web_esdh_provider_send_statusmail')) {
            _os2web_esdh_provider_send_statusmail(t($message, $entries), TRUE);
          }

          // Publication not published or public.
          $meetings[] = array(
            'system_id' => $agendainfo['sysid'],
            'publish' => FALSE,
            'meeting_sub_id' => (int) array_shift($xml_item->xpath('field/@sysid'))
          ) + os2web_esdh_provider_default_meeting();
        }
      }
    }
    else {
      watchdog('acadre MM', 'Failed to parse XML in %file during import.', array('%file' => $file), WATCHDOG_WARNING);
    }
  }
  return $meetings;
}

/**
 * Imports a meeting from filesystem.
 *
 * @param array $info
 *   Meeting info block derived from XML.
 *
 * @return mixed
 *   Meeting_struct array for an accepted import, else FALSE
 */
function _os2web_acadre_esdh_import_meeting($info) {

  // Debug bit set in os2web_esdh_provider settings.
  $debug = variable_get('os2web_esdh_provider_debug_info');
  $debug && error_log('MM Import - import meeting from XML - sysid=' . $info['sysid'] . ' - ' . timer_read('mm_import') . 'ms');

  if (($real_path = _os2web_acadre_esdh_similar_file_exists(drupal_realpath($info['agenda_uri']))) !== FALSE) {
    $xml = simplexml_load_file($real_path);
    if ((string) array_shift($xml->xpath("//table[@name='location']/fields/field[@name='name']"))) {
      $location = (string) array_shift($xml->xpath("//table[@name='location']/fields/field[@name='name']"));
    }
    else {
      $location = (string) array_shift($xml->xpath("//table[@name='meeting']/fields/field[@name='location']"));
    }
    $meeting = array(
      'title' => (string) array_shift($xml->xpath("//table[@name='meeting']/fields/field[@name='name']")),
      'meeting_id' => (string) array_shift($xml->xpath("//table[@name='meeting']/fields/field[@name='sysid']")),
      'system_id' => $info['sysid'],
      'path' => $real_path,
      'publication_id' => (string) array_shift($xml->xpath("//table[@name='agenda']/fields/field[@name='sysid']")),
      'creation_date' => strtotime((string) array_shift($xml->xpath("//table[@name='agenda']/fields/field[@name='producedate']"))),
      'description' => (string) array_shift($xml->xpath("//table[@name='agenda']/fields/field[@name='description']")),
      'meeting_date_start' => (string) array_shift($xml->xpath("//table[@name='meeting']/fields/field[@name='date']")),
      'meeting_date_finish' => (string) array_shift($xml->xpath("//table[@name='meeting']/fields/field[@name='finish']")),
      'committee' => (string) array_shift($xml->xpath("//table[@name='committee']/fields/field[@name='name']")),
      'committee_id' => (string) array_shift($xml->xpath("//table[@name='committee']/fields/field[@name='sysid']")),
      'location' => $location,
      'items' => array(),
    );

    $publish_committee = array_map('trim', explode(',', variable_get('os2web_meetings_approved_committee', ACADRE_MM_DEFAULT_APPROVED)));
    if ($meeting['committee'] == '' || !in_array($meeting['committee_id'], $publish_committee)) {
      watchdog('acadre MM', 'Ignored agenda from %committee .', array('%committee' => $meeting['committee']));
      return FALSE;
    }

    // Participants.
    $participants = $xml->xpath("//table[@name='meeting']/table[@name='meetmember']/table[@name='member']");
    foreach ($participants as $participant) {
      // Check if the absent is true, then skip.
      $absent = (int) array_shift($participant->xpath("fields/field[@name='absent']"));
      if ($absent == 0) {
        $meeting['participants'][] = (string) array_shift($participant->xpath("fields/field[@name='name']"));
      }
      else {
        $meeting['participants_cancellation'][] = (string) array_shift($participant->xpath("fields/field[@name='name']"));
      }
    }

    // Fix dates:
    $date_obj = date_create($meeting['meeting_date_start']);
    date_timezone_set($date_obj, timezone_open('UTC'));
    $meeting['meeting_date_start'] = date_format($date_obj, 'Y-m-d H:i');
    $date_obj = date_create($meeting['meeting_date_finish']);
    date_timezone_set($date_obj, timezone_open('UTC'));
    $meeting['meeting_date_finish'] = date_format($date_obj, 'Y-m-d H:i');

    // Full Doc:
    $meeting['full_doc'] = array(
      'uri' => implode('/', array(
        variable_get('os2web_meetings_path', ACADRE_MM_IMPORT_DIR),
        $info['filesfolder'],
        $info['docfilename'])),
      'title' => $meeting['title'],
    );

    // Type:
    switch ($info['type']) {
      case 1:
        $meeting['type'] = 'Dagsorden';
        break;

      case 2:
        $meeting['type'] = 'Referat';
        break;

      default:
        $meeting['type'] = 'Anden';
        watchdog('acadre MM', 'Unknown meeting type value: %type', array('%type' => $meeting['type']), WATCHDOG_WARNING);
    }

    foreach ($xml->xpath("//table[@name='agendaitemparents']") as $item_xml) {
      $item_content_xml = array_shift($item_xml->xpath("table[@name='agendaitem']"));
      if (($item = _os2web_acadre_esdh_import_item($info, $item_content_xml)) !== FALSE) {
        $meeting['items'][] = $item;
      }
    }
    // Apply defaults, just in case we missed something.
    $meeting += os2web_esdh_provider_default_meeting();
    return $meeting;
  }
  else {
    // Requested file not found.
    watchdog('acadre MM', 'Failed to read agenda manifest file %uri', array('%uri' => $info['agenda_uri']), WATCHDOG_WARNING);
  }
  return FALSE;
}

/**
 * Imports a single item for an agenda.
 *
 * @param array $info
 *   Import info array
 * @param SimpleXMLElement $xml
 *   Xml segment containing the item
 *
 * @return array
 *   The imported item.
 */
function _os2web_acadre_esdh_import_item($info, $xml) {
  // Debug bit set in os2web_esdh_provider settings.
  $debug = variable_get('os2web_esdh_provider_debug_info');

  $xml_id = $xml->xpath("../fields/field[@name='sort']");
  $xml_name = $xml->xpath("fields/field[@name='name']");
  $xml_access = $xml->xpath("fields/field[@name='accessname']");
  $xml_publishlevel =  $xml->xpath("fields/field[@name='publishlevel']");

  $id = (int) array_shift($xml_id);
  $publish_level = (int) array_shift($xml_publishlevel);
  $name = ($publish_level == 5 && variable_get('os2web_meeting_import_agendas_in_closed_bullet', FALSE)) ? variable_get('os2web_meeting_import_anonymous_agenda_title', "Anonymiseret") :(string) array_shift($xml_name);
  $access = (string) array_shift($xml_access);

  $item = array(
    'id' => $id,
    'title' => 'Punkt ' . $id . ' ' . $name,
    'access' => $access,
    'publishlevel' => $publish_level,
    'bullets' => array(),
    'enclosures' => array(),
  );

  $debug && error_log('MM Import - Import item from XML - id=' . $id . ' - ' . timer_read('mm_import') . 'ms');
  // Deny closed content.
  if (variable_get('os2web_meeting_import_agendas_in_closed_bullet', FALSE) || $item['access'] !== 'Lukket') {
    // Process attachments.
    foreach ($xml->xpath("table[@name='bullet']") as $bullet_xml) {
      if (($bullet = _os2web_acadre_esdh_import_bullet($info, $bullet_xml)) !== FALSE) {
        if (is_int($bullet['sort']) && $bullet['sort'] > 0) {
          $item['bullets'][$bullet['sort'] - 1] = $bullet;
        }
        else {
          $item['bullets'][] = $bullet;
        }
      }
    }
    // Process enclosures.
    foreach ($xml->xpath("table[@name='enclosure']") as $enclosure) {
      $filename_in = (string) array_shift($enclosure->xpath("fields/field[@name='filename']"));
      if (strlen($filename_in) > 0) {
        $item['enclosures'][] = array(
          'uri' => implode('/', array(
            variable_get('os2web_meetings_path', ACADRE_MM_IMPORT_DIR),
            $info['filesfolder'],
            $filename_in)),
          'title' => trim((string) array_shift($enclosure->xpath("fields/field[@name='name']"))),
          'access' => ACADRE_MM_ACCESS_OPEN == (int) array_shift($enclosure->xpath("fields/field[@name='access']")),
          'publishlevel' => array_shift($enclosure->xpath("fields/field[@name='publishlevel']")),
        );
      }
    }
  }
  $item += os2web_esdh_provider_default_item();
  return $item;
}

/**
 * Imports a single bullet for an agenda item.
 *
 * @param array $info
 *   Import info array
 * @param SimpleXMLElement $bullet_xml
 *   Xml segment containing the bullet
 *
 * @return array
 *   The imported bullet.
 */
function _os2web_acadre_esdh_import_bullet($info, $bullet_xml) {
  // Debug bit set in os2web_esdh_provider settings.
  $debug = variable_get('os2web_esdh_provider_debug_info');
  $debug && error_log('MM Import - import bullet - ' . timer_read('mm_import') . 'ms');

  $xml_title = $bullet_xml->xpath("fields/field[@name='bulletname']");
  $xml_body = $bullet_xml->xpath("fields/field[@name='bulletcontent']");
  $xml_sort = $bullet_xml->xpath("fields/field[@name='bulletsortorder']");

  $bullet = array(
    'title' => (string) array_shift($xml_title),
    'body' => (string) array_shift($xml_body),
    'sort' => (int) array_shift($xml_sort),
  );
  if ($bullet['body'] === '') {
    return FALSE;
  }
  $bullet += os2web_esdh_provider_default_bullet();
  return $bullet;
}

/**
 * Case insensitive fileexists(). Code from comments on php.net.
 *
 * @param string $filename
 *   File name to check.
 *
 * @return mixed
 *   False if file not found, case corrected filename if found.
 */
function _os2web_acadre_esdh_similar_file_exists($filename) {
  if (file_exists($filename)) {
    return $filename;
  }
  $lcase_filename = strtolower($filename);
  foreach (glob(dirname($filename) . '/*') as $file) {
    if (strtolower($file) == $lcase_filename) {
      return $file;
    }
  }
  return FALSE;
}

/**
 * This function will set up the addenum connections for meetings.
 * @TODO: Rid this of drupal specific code.
 */
function _os2web_acadre_esdh_mm_order_addenums($drush = FALSE) {
  if (!lock_acquire(__FUNCTION__)) {
    return;
  }

  // Debug bit set in os2web_esdh_provider settings.
  $debug = variable_get('os2web_esdh_provider_debug_info');
  $debug && timer_start('_os2web_acadre_esdh_mm_order_addenums') && error_log('MM Import - Start of addendums - ' . timer_read('_os2web_acadre_esdh_mm_order_addenums') . 'ms - ' . memory_get_usage());

  $rev_meetings = array();

  // Find all meetings and gather meeting and agenda_ids.
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node', '=')
        ->propertyCondition('type', 'os2web_meetings_meeting', '=');
  $nodes_result = $query->execute();

  if (!isset($nodes_result['node'])) {
    return;
  }
  $nodes = $nodes_result['node'];

  // Load necessary fields into the node object.
  $fields = field_info_instances('node', 'os2web_meetings_meeting');
  field_attach_load('node', $nodes, FIELD_LOAD_CURRENT, array('field_id' => $fields['field_os2web_meetings_addendum']['field_id']));
  field_attach_load('node', $nodes, FIELD_LOAD_CURRENT, array('field_id' => $fields['field_os2web_meetings_id']['field_id']));
  field_attach_load('node', $nodes, FIELD_LOAD_CURRENT, array('field_id' => $fields['field_os2web_meetings_system_id']['field_id']));

  // Meetings as: $meetings[<meeting_id>][<system_id>][<node_id>] .
  $meetings = array();

  $nids_with_addendums = array();

  $debug && error_log('MM Import - Retrieve nodes with addendums from ' . count($nodes) . ' nodes - ' . timer_read('_os2web_acadre_esdh_mm_order_addenums') . 'ms - ' . memory_get_usage());
  // Loop through all meeting nodes, and generate an array with meeting grouped.
  foreach ($nodes as $node) {
    $addenum_to = field_get_items('node', $node, 'field_os2web_meetings_addendum');
    if (isset($addenum_to[0]['nid']) && is_numeric($addenum_to[0]['nid'])) {
      $nids_with_addendums[$node->nid] = $node->nid;
    }
    $meeting_id = field_get_items('node', $node, 'field_os2web_meetings_id');
    $meeting_sys_id = field_get_items('node', $node, 'field_os2web_meetings_system_id');
    if (!isset($meeting_id[0]['value']) || !isset($meeting_sys_id[0]['value'])) {
      $debug && error_log('MM Import - Missing meeting_id or meeting_sub_id for nid=' . $node->nid);
      continue;
    }
    if (isset($meetings[$meeting_id[0]['value']][$meeting_sys_id[0]['value']])) {
      // Duplicate meeting detected.
      watchdog('acadre MM', 'Duplicate import found for meeting %mid. Deleting nid=%nid.', array('%mid' => $meeting_id['value'], '%nid' => $node->nid), WATCHDOG_WARNING);
      node_delete($node->nid);
    }
    else {
      $meetings[$meeting_id[0]['value']][$meeting_sys_id[0]['value']] = $node->nid;
    }
  }

  $debug && error_log('MM Import - Update addendums on ' . count($meetings) . ' nodes - ' . timer_read('_os2web_acadre_esdh_mm_order_addenums') . 'ms - ' . memory_get_usage());
  // Run through the meeting array, to determine the addendums.
  foreach ($meetings as $m_id => $meeting) {
    // Lowest system id first.
    ksort($meeting);
    if (in_array($m_id, $rev_meetings)) {
      $meeting = array_reverse($meeting);
    }
    // Lowest system id is primary.
    $primary = $nodes[array_shift($meeting)];
    $addenum_to = field_get_items('node', $primary, 'field_os2web_meetings_addendum');
    if (!empty($addenum_to[0]['nid'])) {
      $primary->field_os2web_meetings_addendum[LANGUAGE_NONE] = array();
      node_save($primary);
    }
    while ($next = array_shift($meeting)) {
      // Set up references for addenum agendas.
      $node = $nodes[$next];
      if ($primary) {
        $addenum_to = field_get_items('node', $node, 'field_os2web_meetings_addendum');
        $addenum_to = is_array($addenum_to) ? array_shift(array_shift($addenum_to)) : FALSE;
        // Save time by only updating what is needed.
        if ($addenum_to != $primary->nid) {
          // error_log(basename(__FILE__) . ':' . __LINE__ . ' Var: $primary = ' . print_r($primary->nid, 1));
          // error_log(basename(__FILE__) . ':' . __LINE__ . ' Var: $addenum_to = ' . print_r($addenum_to, 1));
          $node->field_os2web_meetings_addendum[LANGUAGE_NONE][0]['nid'] = $primary->nid;
          node_save($node);
        }
      }
      else {
        error_log('MARK - ' . basename(__FILE__) . ':' . __LINE__ . ' in ' . __FUNCTION__ . '()');
        error_log(basename(__FILE__) . ':' . __LINE__ . " jm@bellcom.dk: wanted to delete $node->nid");
        // node_delete($node->nid);
      }
      // Remove node from final nids_with_addendums.
      unset($nids_with_addendums[$node->nid]);
      if ($drush === TRUE) {
        if ($primary) {
          drush_log("Updated meeting $m_id..", 'ok');
        }
        else {
          drush_log("Removed stale addenum $m_id..", 'ok');
        }
      }
    }
  }

  $debug && error_log('MM Import - Start reset addendums on ' . count($nids_with_addendums) . ' nodes - ' . timer_read('_os2web_acadre_esdh_mm_order_addenums') . 'ms - ' . memory_get_usage());
  // Remove any addendums from nodes which hasnt been proccessed.
  foreach ($nids_with_addendums as $nid) {
    // Load the node from the local variable.
    $node = $nodes[$nid];
    $node->field_os2web_meetings_addendum = array();
    node_save($node);
    if ($drush === TRUE) {
      drush_log("Resetting $nid..", 'ok');
    }
  }
  $debug && error_log('MM Import - End of addendums - ' . timer_read('_os2web_acadre_esdh_mm_order_addenums') . 'ms - ' . memory_get_usage());
  lock_release(__FUNCTION__);
}
