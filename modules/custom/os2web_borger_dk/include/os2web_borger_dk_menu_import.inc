<?php
/**
 * @file Borger.dk menu import.
 */

 /**
 * Function os2web_borger_dk_import_menu_now_form_submit().
 */
function os2web_borger_dk_import_menu_now_form_submit($form, &$form_state) {
  if (($form_state['submitted'] == 1) && ($form_state['input']['op'] == 'Import Borger.dk-menu now')) {
    // Next we get a list of all menu-items from the Borger.dk-webservice.
    $menu_items_availlable = _os2web_borger_dk_GetAllSites();

    if (!empty($menu_items_availlable['Exceptions']) || !empty($menu_items_availlable['error'])) {
      $msg = 'An error occured while fetching the Borger.dk menus. Last succesful update was at: %success';
      watchdog('Borger.dk-articles', $msg, $variables = array('%success' => $updated_at));
      return;
    }

    $parent_array = array();
    // Make a array of parenet id : parent name.
    foreach ($menu_items_availlable as $item) {
      $item_site_id = $item['SiteID'];
      $parent_array[$item_site_id] = $item['SiteTitle'];
    }
    $total = count($menu_items_availlable);
    // $menu_name = $form['build_borger_menu_under_menu']['#value'];
    $menu_name = variable_get('build_borger_menu_under_menu');

    os2web_borger_dk_create_custom_menu($menu_items_availlable, $total, $parent_array, $menu_name);
  }
}

/**
 * Function os2web_borger_dk_create_custom_menu().
 *
 * Create a custom menu.
 */
function os2web_borger_dk_create_custom_menu($menu_items_availlable, $total, $parent_array, $menu_name) {
  $borger_dk_menu = variable_get('os2web_borger_dk_borger_dk_menu_name', t('Borger.dk menu'));
  if ($menu_name == 'borgerdkmenu2' && $borger_dk_menu == 'Borger.dk menu') {
    $existing_menu = db_query('SELECT * FROM {menu_custom} WHERE menu_name = :menu_name',
                       array('menu_name' => $menu_name))->fetchAssoc();
    if (!$existing_menu) {
      $menu = array();
      $menu['menu_name'] = 'borgerdkmenu2';
      $menu['title'] = $borger_dk_menu;
      $menu['description'] = "The <em>Presentation tabs</em> menu contains links to presentation detail";
      menu_save($menu);
    }
  }

  $operations[] = array();
  // Then import the menu from Borger.dk and tag all imported articles.
  $operations[] = array('_os2web_borger_dk_menus_cronbatch_wrapper', array($total));

  $groups = array_chunk($menu_items_availlable, 10);
  foreach ($groups as $gid => $group) {
    // Set the batch operation to import 10 menu items each time.
    $operations[] = array(
      '_os2web_borger_dk_import_menu_items',
      array($group, $total, $parent_array, $menu_name),
    );
  }

  $batch = array(
    'operations' => $operations,
    'title' => t('Importing menu from Borger.dk'),
    'init_message' => t('Import job is starting.'),
    'progress_message' => t('Processed @current out of @total.'),
    'finished' => 'os2web_borger_dk_batch_menu_import_finished',
  );
  // Finally we execute the batch process(es).
  batch_set($batch);

}

/**
 * Function _os2web_borger_dk_import_menu_items().
 */
function _os2web_borger_dk_import_menu_items($group, $total, $parent_array, $menu_name, &$context) {
  if (empty($context['sandbox'])) {
    $context['sandbox'] = array();
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['max'] = $total;
  }
  $menu_to_term = variable_get('os2web_borger_dk_choose_term', 0);
  $vocab_name = variable_get('build_borger_menu_under_vocabulary', 'os2web_base_tax_site_structure');
  $vocab = taxonomy_vocabulary_machine_name_load($vocab_name);
  if ($vocab) {
    $vid = $vocab->vid;
  }
  else {
    $vid = FALSE;
  }

  foreach ($group as $item) {
    $item_site_id = $item['SiteID'];
    $item_pid = $item['ParentID'];
    $menu_item = array();
    $mlid = db_query('SELECT * FROM {menu_links} WHERE link_title= :link_title AND menu_name = :menu_name', array('link_title' => $item['SiteTitle'], 'menu_name' => $menu_name))->fetchAssoc();
    // The first menu item from Borger.dk does NOT contain a parent ID.
    // 'Emner', it is the root of Borger.dk menu tree structure.
    if (empty($item['ParentID']) && $item['SiteTitle'] == 'Emner') {
      // If the menu link is NOT existed.
      if (!$mlid) {


        $item['SiteTitle'] = 'Borger';
        if (!$vid && !$menu_to_term) {
          $nid = _os2web_borger_dk_create_menu_page($item);
          $node = node_load($nid);
          _os2web_borger_dk_add_node_menu($node, array());
        }
        else {
          $borger = taxonomy_get_term_by_name('Borger', $vocab_name);
          if (!$borger) {
            $borger = taxonomy_get_term_by_name('Emner', $vocab_name);
          }

          if (!$borger) {
            // Create a new top level term programmatically.
            $item['SiteTitle'] = 'Borger';
            _os2web_borger_dk_create_menu_term($item, $vid, array(), $vocab_name);
          }
        }

      }
      // Update our progress information.
      $context['sandbox']['progress']++;
    }
    else {

      if (!$vid && !$menu_to_term) {
      // If the menu link is NOT existed.
      $existing_parent = db_query('SELECT * FROM {menu_links} WHERE link_title= :link_title AND menu_name = :menu_name', array('link_title' => $parent_array[$item_pid], 'menu_name' => $menu_name))->fetchAssoc();
        if ($existing_parent && !$mlid) {
          // Create a menu page for the Menu item (path).
          $nid = _os2web_borger_dk_create_menu_page($item);
          $node = node_load($nid);
          _os2web_borger_dk_add_node_menu($node, $existing_parent);
        }
      }
      else {
        $mlid = taxonomy_get_term_by_name($item['SiteTitle'], $vocab_name);
        // If the menu link is NOT existed.

        $existing_parent = taxonomy_get_term_by_name($parent_array[$item_pid], $vocab_name);

        if (!$mlid) {
          if (!empty($existing_parent)) {
            $existing_parent = reset($existing_parent);
            // Create a term for the Menu item (path).
            _os2web_borger_dk_create_menu_term($item, $vid, array($existing_parent->tid), $vocab_name);
          }
        }
      }
      // Update our progress information.
      $context['sandbox']['progress']++;
    }
  }
  $context['finished'] = 1;
}
/**
 * Function _os2web_borger_dk_create_menu_page().
 */
function _os2web_borger_dk_create_menu_page($item) {
  $type = variable_get('os2web_borger_dk_menus_menu_page', 'os2web_base_contentpage');
  $result = db_query('SELECT * FROM {node} WHERE type = :type AND title = :title',
                     array('type' => $type, 'title' => $item['SiteTitle']))->fetchAssoc();
  if (!$result) {
    $node = new stdClass();
    $node->uid = 1;
    $node->created = !empty($node->date) ? strtotime($node->date) : REQUEST_TIME;
    $node->validated = TRUE;

    // Insert default value of a new node.
    $node->type = $type;
    $node->title = $item['SiteTitle'];
    $node->body[LANGUAGE_NONE]['0']['value'] = '';
    $node->body[LANGUAGE_NONE]['0']['safe_value'] = '';
    $node->body[LANGUAGE_NONE][0]['format'] = BORGERDK_TEXT_FORMAT_HTML;
    $node = node_submit($node);
    node_save($node);
    return $node->nid;
  }
  else {
    return $result['nid'];
  }

}

/**
 * Function _os2web_borger_dk_create_menu_term().
 */
function _os2web_borger_dk_create_menu_term($item, $vid, $tid, $vocab_name = NULL) {
  $vocab_name = variable_get('build_borger_menu_under_vocabulary', 'os2web_base_tax_site_structure');
  // Create a new term programmatically under 'Borger'.
  $newterm = new stdClass();
  $newterm->name = $item['SiteTitle']; // The name of the term
  $newterm->vid = $vid; // The ID of the parent vocabulary
  $newterm->vocabulary_machine_name = $vocab_name;
  $newterm->description = '';
  $newterm->parent = array($tid);
  taxonomy_term_save($newterm);
  return $newterm->tid;

}


/**
 * Function _os2web_borger_dk_menus_cronbatch_wrapper().
 *
 * A batch-wrapper so that the cronbatch function can
 * also be run via the browser, and not just as a cron-job.
 */
function _os2web_borger_dk_menus_cronbatch_wrapper($max_count, &$context) {
  // _os2web_borger_dk_menus_cronbatch(TRUE);
  $context['sandbox']['progress']++;
  $context['message'] = t("Importing the menu from Borger.dk.");
  $context['finished'] = 1;
}
/**
 * Function _os2web_borger_dk_create_menustructure_cronbatch_wrapper().
 */
function _os2web_borger_dk_create_menustructure_cronbatch_wrapper($max_count, &$context) {
  $context['sandbox']['progress']++;
  $context['message'] = t("Creating Borger.dk menu structure.");
  $context['finished'] = 1;
}
/**
 * Function os2web_borger_dk_batch_article_import_finished().
 *
 * When menu structure is imported, show message and go
 * to next process: import articles.
 */
function os2web_borger_dk_batch_menu_import_finished($success, $results, $operations) {
  if ($success) {
    drupal_set_message(t('The Borger.dk menu items are imported.'));
    drupal_set_message(t('You can now import all articles from Borger.dk'));
  }
  else {
    $error_operation = reset($operations);
    drupal_set_message(t('An error occurred while processing @operation with arguments : @args', array(
      '@operation' => $error_operation[0], '@args' => print_r($error_operation[0], TRUE))));
  }
  menu_cache_clear_all();
  // _os2web_borger_dk_import_all_articles();
  drupal_goto('admin/config/os2web_borger_dk/settings');
}
/**
 * Function os2web_os2web_borger_dk_create_borger_dk_menu_now_form_submit().
 *
 * Create links to articles under a chosen menu.
 */
function os2web_borger_dk_create_borger_dk_menu_now_form_submit($form, &$form_state) {
  if ($form_state['submitted'] == 1) {

    // Next we get a list of all menu-items from the Borger.dk-webservice.

    $menu_items_availlable = _os2web_borger_dk_GetAllSites();

    if (!empty($menu_items_availlable['Exceptions']) || !empty($menu_items_availlable['error'])) {
      $msg = 'An error occured while fetching the Borger.dk menus. Last succesful update was at: %success';
      watchdog('Borger.dk-articles', $msg, $variables = array('%success' => $updated_at));
      return;
    }

    $total = count($menu_items_availlable);
    $menu_name = variable_get('build_borger_menu_under_menu');
    $operations[] = array();
    // Then import the menu from Borger.dk and tag all imported articles.
    $operations[] = array('_os2web_borger_dk_create_menustructure_cronbatch_wrapper', array($total));

    foreach ($menu_items_availlable as $item) {
      $operations[] = array(
        '_os2web_borger_dk_create_borger_dk_meun_structure',
        array($item, $total, $menu_name),
      );
    }
    /*  $groups = array_chunk($menu_items_availlable, 10);
    foreach ($groups as $gid => $group) {
      // Set the batch operation to import 10 menu items each time.
      $operations[] = array('_os2web_borger_dk_create_borger_dk_meun_structure', array($group, $total));
    }*/

    $batch = array(
      'operations' => $operations,
      'title' => t('Create Borger.dk menu structure'),
      'init_message' => t('Create job is starting.'),
      'progress_message' => t('Processed @current out of @total.'),
      'finished' => 'os2web_borger_dk_batch_menustructure_create_finished',
    );
    // Finally we execute the batch process(es).
    batch_set($batch);
  }
}
/**
 * Function _os2web_borger_dk_create_borger_dk_meun_structure().
 */
function _os2web_borger_dk_create_borger_dk_meun_structure($item, $total, $menu_name, &$context) {
  if (empty($context['sandbox'])) {
    $context['sandbox'] = array();
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['max'] = $total;
  }

  // Search each menu link under the given menu_name.
  $pid = db_query('SELECT * FROM {menu_links} WHERE link_title= :link_title AND menu_name = :menu_name',
                  array('link_title' => $item['SiteTitle'], 'menu_name' => $menu_name))->fetchAssoc();
  if ($pid) {
    // If the menu link is existed, then get all article
    // IDs in the menu link page.

    $article_ids = _os2web_borger_dk_GetArticleIDsBySiteID($item['SiteID']);
    // When there are articles with IDs under the page.
    if (!empty($article_ids)) {
      foreach ($article_ids as $id => $value) {
        // TODO: check if the links is existed.!!!!
        // Check if article is existed.
        $result = db_query("SELECT `ArticleID`, `ArticleStatus`, `ArticleTitle` FROM {os2web_borger_dk_article_titles}
                           WHERE `ArticleID` = " . $value);
        if ($result) {
          foreach ($result as $row) {
            $article_title = $row->ArticleTitle;
            $query = 'SELECT * FROM {menu_links} WHERE link_title= :link_title AND menu_name = :menu_name  AND plid = :plid';
            $mlid = db_query($query, array(
                      'link_title' => $article_title,
                      'menu_name' => $menu_name,
                      'plid' => $pid['mlid'],
                      )
                    )->fetchAssoc();
            if ($mlid) {

              $menu_to_term = variable_get('os2web_borger_dk_choose_term', 0);
              $vocab_name = variable_get('build_borger_menu_under_vocabulary', 'os2web_base_tax_site_structure');
              $vocab = taxonomy_vocabulary_machine_name_load($vocab_name);
              if ($vocab) {
                $vid = $vocab->vid;
              }
              else {
                $vid = FALSE;
              }
              if ($menu_to_term && $vid) {
                // Delete the term.
                $tid = db_query('SELECT tid FROM {taxonomy_menu} WHERE mlid = :mlid', array(':mlid' => $mlid['mlid'],))->fetchField();

                taxonomy_term_delete($tid);
              }

                return;

            }
            if ($row->ArticleStatus > 0) {

              $node = node_load($row->ArticleStatus);
              _os2web_borger_dk_add_node_menu($node, $pid);

            }
            // If the article is NOT imported yet, so import it.
            else {
              $article = _os2web_borger_dk_GetArticleByID($value, FALSE);

              if (empty($article['Exceptions']) && empty($article['error'])) {

                $nid = FALSE;
                $node = _os2web_borger_dk_create_article_node($nid, $article, $pid);
              }
            }
          }
        }
        // If article is NOT existed, then import by articleID.
        else {
          _os2web_borger_dk_import_supplement_article($value, $pid);
        }
        // Update our progress information.
        $context['sandbox']['progress']++;
      }
    }
    /*
    // TODO: list links for menu page.here!
    $node_id = $pid['link_path'];
    $node_id = substr($node_id, 5, strlen($node_id)-1);

    $body_content = '';
    $children = db_query('SELECT * FROM {menu_links} WHERE plid= :plid AND menu_name = :menu_name',
                              array('plid' => $pid['mlid'], 'menu_name' => $menu_name));
    if ($children) {
      foreach ($children as $child) {
        $body_content = $body_content . "<p><a href= '". $child->link_path ."'> " . $child->link_title ." </a>" . "\n";
      }

      if (!empty($node_id)) {
        $node = node_load($node_id);
        $node->body[LANGUAGE_NONE]['0']['value'] = $body_content;
        $node->body[LANGUAGE_NONE]['0']['safe_value'] = $body_content;
        $node->body[LANGUAGE_NONE][0]['format'] = BORGERDK_TEXT_FORMAT_HTML;
        node_save($node);
      }
    }*/
  }

  $context['finished'] = 1;
}
/**
 * Function os2web_borger_dk_batch_menustructure_create_finished().
 */
function os2web_borger_dk_batch_menustructure_create_finished($success, $results, $operations) {
  if ($success) {
    $menu_name = variable_get('build_borger_menu_under_menu');

    drupal_set_message(t('Borger.dk menu structure import is finished.'));
    drupal_set_message(t('You can view the menu structure here "!url".',
                         array('!url' => l(t('Borger.dk menu structure'), 'admin/structure/menu/manage/' . $menu_name))));
  }
  else {
    $error_operation = reset($operations);
    drupal_set_message(t('An error occurred while processing @operation with arguments : @args', array(
      '@operation' => $error_operation[0], '@args' => print_r($error_operation[0], TRUE))));
  }
  menu_cache_clear_all();

  // Finished.
  drupal_goto('admin/config/os2web_borger_dk/settings');
}

/**
 * Function _os2web_borger_dk_parse_borgerdk_menu_item().
 *
 * This function parses a Borger.dk-MenuItemDescription and extracts all
 * the field values we want for our Borger.dk-menu-structure.
 */
function _os2web_borger_dk_parse_borgerdk_menu_item($menu_item) {
  // First we extract the directly accessible fields
  // from the ArticleDescription.
  $pid = (isset($menu_item->ParentID)) ? $menu_item->ParentID : '';
  $borgerdk_menu = array(
    'ParentID' => $pid,
    'SiteID' => $menu_item->SiteID,
    'SiteName' => html_entity_decode($menu_item->SiteName, ENT_NOQUOTES, 'UTF-8'),
    'SiteTitle' => $menu_item->SiteTitle,
  );

  return $borgerdk_menu;
}
/**
 * Function _os2web_borger_dk_tag_borger_dk_articles().
 */
function _os2web_borger_dk_tag_borger_dk_articles($menu = array(), $update_items = array()) {
  $not_tagged = array();

  foreach ($menu as $id => $item) {
    // First we check if this is an imported article or not.
    $tid = (isset($item['tid'])) ? $item['tid'] : FALSE;
    $ptid = (isset($item['ptid'])) ? $item['ptid'] : FALSE;
    if ($tid) {
      if (isset($item['Links']) && is_array($item['Links'])) {
        $term = taxonomy_term_load($tid);
        if ($term) {
          // The term was found and we tag all linked articles.
          foreach ($item['Links'] as $lid => $litem) {
            // We only tag imported articles.
            $aid = (isset($item['ArticleID'])) ? $item['ArticleID'] : FALSE;
            if ($aid && isset($update_items[$aid])) {
              $node = node_load($update_items[$aid]);
              $node->field_os2web_borger_dk_formterm[LANGUAGE_NONE][$tid] = (array) $term;

              node_save($node);
            }
          }
        }
        else {
          // Could not find the correct term.
          foreach ($item['Links'] as $lid => $litem) {
            $not_tagged[$lid] = $litem;
          }
        }
      }
    }
    // Now we go recursive on any and all child-elements.
    if (isset($item['nl']) && is_array($item['nl'])) {
      $errors = _os2web_borger_dk_tag_borger_dk_articles($item['nl'], $update_items);
      if (!empty($errors)) {
        $not_tagged = array_merge($not_tagged, $errors);
      }
    }
  }

  return $not_tagged;
}
