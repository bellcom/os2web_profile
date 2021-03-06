<?php

define("DATE_FORMAT", variable_get('date_format_os2web_base_date_only', 'd-m-Y'));


function bellcom_elasticsearch_kle_settings_page() {
  drupal_add_library('system', 'ui.datepicker');
  drupal_add_js(array(
    'bellcom_elasticsearch' => array(
      'dateFormat' => bellcom_elasticsearch_get_js_date_format()
    )
  ), 'setting');
  drupal_add_js(drupal_get_path('module', 'bellcom_elasticsearch') . '/js/bellcom_elasticsearch.js', 'file');

  return views_embed_view("bellcom_elasticsearch_kle_terms");
}

function bellcom_elasticsearch_term_fields($form, $form_state) {

  $form['bellcom_elasticsearch_term_field_names'] = array(
    '#type' => 'textfield',
    '#description' => t('User "," to seperate term reference field machine names'),
    '#default_value' => variable_get('bellcom_elasticsearch_term_field_names', 'field_os2web_borger_dk_kle,field_os2web_base_field_kle_ref'),
    '#size' => 100,
  );

  return system_settings_form($form);
}

function bellcom_elasticsearch_update_kle($tid, $weight, $from, $until) {
  $fields = array('weight' => $weight);

  if ($from && $from != 0) {
    $from_date = date_create_from_format(DATE_FORMAT, $from);
    if (is_object($from_date)) {
      $fields['from_date'] = date("Y-m-d 0:0:0", date_timestamp_get($from_date));
    }
  }
  else {
    $fields['from_date'] = NULL;
  }

  if ($until && $until != 0) {
    $until_date = date_create_from_format(DATE_FORMAT, $until);
    if (is_object($until_date)) {
      $fields['until_date'] = date("Y-m-d 23:59:59", date_timestamp_get($until_date));
    }
  }
  else {
    $fields['until_date'] = NULL;
  }

  if (bellcom_elasticsearch_get_kle_by_tid($tid)) { //not found, means that it was neven added
    $rowCount = db_update('bellcom_elasticsearch_kle')
      ->fields($fields)
      ->condition('tid', $tid)
      ->execute();
  }
  else {
    $fields['tid'] = $tid;
    $rowCount = db_insert('bellcom_elasticsearch_kle')
      ->fields($fields)
      ->execute();
  }
}

function bellcom_elasticsearch_get_kle_by_tid($tid) {
  $kle = db_select('bellcom_elasticsearch_kle', 'i')
    ->fields('i')
    ->condition('tid', $tid)
    ->execute()
    ->fetchAll();

  return array_pop($kle);
}

/**
 * Implement hook_views_query_alter()
 *
 * @param $view
 * @param $query
 */
function bellcom_elasticsearch_views_query_alter(&$view, &$query) {
  if ($view->name === 'bellcom_elasticsearch_kle_terms') {
    $query->where[1]['conditions'][0]['value'] = array();

    $term_fields = variable_get('bellcom_elasticsearch_term_field_names', 'field_os2web_borger_dk_kle,field_os2web_base_field_kle_ref');
    $fields = explode(',', $term_fields);
    foreach ($fields as $field) {
      $field_info = field_info_field($field);
      if (isset($field_info['settings']['allowed_values'])) {
        $vocabulary = taxonomy_vocabulary_machine_name_load($field_info['settings']['allowed_values'][0]['vocabulary']);
        $query->where[1]['conditions'][0]['value'][] = $vocabulary->vid;
      }
    }
  }
}

function bellcom_elasticsearch_phrase_catcher_settings_page() {
  drupal_add_library('system', 'ui.datepicker');
  drupal_add_js(array(
    'bellcom_elasticsearch' => array(
      'dateFormat' => bellcom_elasticsearch_get_js_date_format()
    )
  ), 'setting');
  drupal_add_js(drupal_get_path('module', 'bellcom_elasticsearch') . '/js/bellcom_elasticsearch.js', 'file');

  $html = '';

  //add form
  $form = drupal_get_form('bellcom_elasticsearch_phrase_catcher_form');
  $html .= drupal_render($form);

  //display table
  $header = array(
    array(
      'data' => t('Phrase'),
      'field' => 't.phrase',
    ),
    array(
      'data' => t('Exclusive'),
      'field' => 't.exclusive',
    ),
    array(
      'data' => t('Entity ID (NID or TID)'),
      'field' => 't.nid',
    ),
    array(
      'data' => t('Is term'),
      'field' => 't.is_term',
    ),
    array(
      'data' => t('From'),
      'field' => 't.from_date',
    ),
    array(
      'data' => t('Until'),
      'field' => 't.until_date',
    ),
    array(
      'data' => t('Weight'),
      'field' => 't.weight',
    ),
  );

  $query = db_select('bellcom_elasticsearch_phrase_catcher', 't')->extend('TableSort');
  $query->fields('t');

  $result = $query->orderByHeader($header)->execute();

  $rows = array();
  foreach ($result as $row) {
    $from_date = '';
    $until_date = '';
    if ($row->from_date) {
      $from_date = date_create_from_format('Y-m-d H:i:s', $row->from_date);
      $from_date = date(DATE_FORMAT, date_timestamp_get($from_date));
    }
    if ($row->until_date) {
      $until_date = date_create_from_format('Y-m-d H:i:s', $row->until_date);
      $until_date = date(DATE_FORMAT, date_timestamp_get($until_date));
    }
    $exclusive = $row->exclusive ? 'checked' : '';
    $is_term= $row->is_term ? 'checked' : '';
    $data = array();
    $data[] = '<span class="display-field display-phrase">' . $row->phrase . '</span><input type="text" value="' . $row->phrase . '" class="form-text edit-field phrase" style="display: none;">';
    $data[] = '<input type="checkbox" class="display-input exclusive" disabled ' . $exclusive . '>';
    $data[] = '<span class="display-field display-nid">' . $row->nid . '</span><input type="text" value="' . $row->nid . '" class="form-text edit-field nid" style="display: none;">';
    $data[] = '<input type="checkbox" class="display-input is-term" disabled ' . $is_term . '>';
    $data[] = '<span class="display-field display-from">' . $from_date . '</span><input type="text" value="' . $from_date . '" class="form-text edit-field from datepicker" style="display: none;">';
    $data[] = '<span class="display-field display-until">' . $until_date . '</span><input type="text" value="' . $until_date . '" class="form-text edit-field until datepicker" style="display: none;">';
    $data[] = '<span class="display-field display-weight">' . $row->weight . '</span><input type="text" value="' . $row->weight . '" class="form-text edit-field weight" style="display: none;">';
    $data[] .= '<a href="#" class="edit-link">Edit</a><a class="submit-link" style="display: none;" href="#">Submit</a>&nbsp;<span class="submitted" style="display: none;">OK</span>'
        .'<a class="delete-link" style="display: none;" href="#">Delete</a>';

    $rows[] = array('data' => $data, 'class' => array('row_phrase'), 'data-id' => array($row->id));
  }

  $header[] = array('data' => 'Edit');

  // Build the table for the nice output.
  $build['tablesort_table'] = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
  );
  $html .= drupal_render($build);

  return $html;
}

function bellcom_elasticsearch_phrase_catcher_form($form, &$form_state) {
  // Provide a text field.
  $form['phrase'] = array(
    '#title' => t('New phrase'),
    '#type' => 'textfield',
    '#required' => TRUE,
  );

  // Provide a submit button.
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Add phrase',
  );

  return $form;
}

function bellcom_elasticsearch_phrase_catcher_form_submit($form, $form_state) {
  $rowCount = db_insert('bellcom_elasticsearch_phrase_catcher')
    ->fields(array(
      'phrase' => $form_state['values']['phrase']
    ))
    ->execute();
}

function bellcom_elasticsearch_update_phrase($id) {
  $fields = array(
    'phrase' => $_GET['phrase'],
    'exclusive' => ($_GET['exclusive'] === 'true') ? 1 : 0,
    'nid' => $_GET['nid'],
    'weight' => $_GET['weight'],
    'is_term' => ($_GET['is_term'] === 'true') ? 1 : 0,
  );

  $from = $_GET['from'];
  if ($from && $from != 0) {
    $from_date = date_create_from_format(DATE_FORMAT, $from);
    if (is_object($from_date)) {
      $fields['from_date'] = date("Y-m-d 0:0:0", date_timestamp_get($from_date));
    }
  }
  else {
    $fields['from_date'] = NULL;
  }

  $until = $_GET['until'];
  if ($until && $until != 0) {
    $until_date = date_create_from_format(DATE_FORMAT, $until);
    if (is_object($until_date)) {
      $fields['until_date'] = date("Y-m-d 23:59:59", date_timestamp_get($until_date));
    }
  }
  else {
    $fields['until_date'] = NULL;
  }

  db_update('bellcom_elasticsearch_phrase_catcher')
    ->fields($fields)
    ->condition('id', $id)
    ->execute();
}

function bellcom_elasticsearch_get_js_date_format() {
  $SYMBOLS_MATCHING = array(
    // Day
    'd' => 'dd',
    'D' => 'D',
    'j' => 'd',
    'l' => 'DD',
    'N' => '',
    'S' => '',
    'w' => '',
    'z' => 'o',
    // Week
    'W' => '',
    // Month
    'F' => 'MM',
    'm' => 'mm',
    'M' => 'M',
    'n' => 'm',
    't' => '',
    // Year
    'L' => '',
    'o' => '',
    'Y' => 'yy',
    'y' => 'y',
    // Time
    'a' => '',
    'A' => '',
    'B' => '',
    'g' => '',
    'G' => '',
    'h' => '',
    'H' => '',
    'i' => '',
    's' => '',
    'u' => ''
  );
  $jqueryui_format = "";
  $escaping = FALSE;
  $php_format = DATE_FORMAT;
  for ($i = 0; $i < strlen($php_format); $i++) {
    $char = $php_format[$i];
    if ($char === '\\') // PHP date format escaping character
    {
      $i++;
      if ($escaping) {
        $jqueryui_format .= $php_format[$i];
      }
      else {
        $jqueryui_format .= '\'' . $php_format[$i];
      }
      $escaping = TRUE;
    }
    else {
      if ($escaping) {
        $jqueryui_format .= "'";
        $escaping = FALSE;
      }
      if (isset($SYMBOLS_MATCHING[$char])) {
        $jqueryui_format .= $SYMBOLS_MATCHING[$char];
      }
      else {
        $jqueryui_format .= $char;
      }
    }
  }
  return $jqueryui_format;
}

function bellcom_elasticsearch_content_type_weight_settings_page($form, $form_state) {
  //dpm(node_type_get_types());
  foreach (node_type_get_types() as $type) {
    $form['bellcom_elasticsearch_content_type_weight_' . $type->type] = array(
      '#title' => $type->name . ' (' . $type->type . ')',
      '#type' => 'select',
      '#options' => array(
        '0.001' => '0.001',
        '0.002' => '0.002',
        '0.003' => '0.003',
        '0.004' => '0.004',
        '0.005' => '0.005',
        '0.01' => '0.01',
        '0.02' => '0.02',
        '0.03' => '0.03',
        '0.04' => '0.04',
        '0.05' => '0.05',
        '0.1' => '0.1',
        '0.2' => '0.2',
        '0.3' => '0.3',
        '0.4' => '0.4',
        '0.5' => '0.5',
        '1' => '1 (not changing)',
        '2' => '2',
        '3' => '3',
        '4' => '4',
        '5' => '5',
        '10' => '10',
        '25' => '25',
        '50' => '50',
        '75' => '75',
        '100' => '100',
        '1000' => '1000',
        '2500' => '2500',
        '5000' => '5000',
        '7500' => '7500',
        '10000' => '10000',
      ),
      '#default_value' => variable_get('bellcom_elasticsearch_content_type_weight_' . $type->type, '1'),
      '#description' => t('Select number to multiply the content type relevancy, selecting 1 will have no effect'),
    );
  }

  return system_settings_form($form);
}
/**
 * Delete callback for a single phrase
 *
 * @param $id
 */
function bellcom_elasticsearch_delete_phrase($id) {
  db_delete('bellcom_elasticsearch_phrase_catcher')
    ->condition('id', $id)
    ->execute();
}