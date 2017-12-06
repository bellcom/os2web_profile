<?php
/**
 * @file
 * os2web_contentpage.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function os2web_contentpage_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_os2web_base_field_case'.
  $field_bases['field_os2web_base_field_case'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_os2web_base_field_case',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'os2web_esdh_field',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'os2web_esdh_field_case_ident',
  );

  // Exported field_base: 'field_os2web_base_field_casesort'.
  $field_bases['field_os2web_base_field_casesort'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_os2web_base_field_casesort',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        '0,0' => 'Dokumenttitel - stigende',
        '0,1' => 'Dokumenttitel - faldende',
        '1,0' => 'Opdateret - stigende',
        '1,1' => 'Opdateret - faldende',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_os2web_base_field_doc'.
  $field_bases['field_os2web_base_field_doc'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_os2web_base_field_doc',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'os2web_esdh_field',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'os2web_esdh_field_doc_ident',
  );

  // Exported field_base: 'field_piwik_stats'.
  $field_bases['field_piwik_stats'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_piwik_stats',
    'indexes' => array(
      'hits' => array(
        0 => 'nb_hits',
        1 => 'entry_nb_actions',
      ),
      'rate' => array(
        0 => 'bounce_rate',
        1 => 'exit_rate',
      ),
      'visits' => array(
        0 => 'nb_visits',
        1 => 'entry_nb_visits',
        2 => 'exit_nb_visits',
      ),
    ),
    'locked' => 0,
    'module' => 'piwik_stats',
    'settings' => array(
      'period' => 'day',
      'show_in_statistics_page' => 1,
    ),
    'translatable' => 0,
    'type' => 'piwik_stats',
  );

  // Exported field_base: 'field_piwik_stats_aar'.
  $field_bases['field_piwik_stats_aar'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_piwik_stats_aar',
    'indexes' => array(
      'hits' => array(
        0 => 'nb_hits',
        1 => 'entry_nb_actions',
      ),
      'rate' => array(
        0 => 'bounce_rate',
        1 => 'exit_rate',
      ),
      'visits' => array(
        0 => 'nb_visits',
        1 => 'entry_nb_visits',
        2 => 'exit_nb_visits',
      ),
    ),
    'locked' => 0,
    'module' => 'piwik_stats',
    'settings' => array(
      'period' => 'year',
      'show_in_statistics_page' => 1,
    ),
    'translatable' => 0,
    'type' => 'piwik_stats',
  );

  // Exported field_base: 'field_piwik_stats_maaned'.
  $field_bases['field_piwik_stats_maaned'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_piwik_stats_maaned',
    'indexes' => array(
      'hits' => array(
        0 => 'nb_hits',
        1 => 'entry_nb_actions',
      ),
      'rate' => array(
        0 => 'bounce_rate',
        1 => 'exit_rate',
      ),
      'visits' => array(
        0 => 'nb_visits',
        1 => 'entry_nb_visits',
        2 => 'exit_nb_visits',
      ),
    ),
    'locked' => 0,
    'module' => 'piwik_stats',
    'settings' => array(
      'period' => 'month',
      'show_in_statistics_page' => 1,
    ),
    'translatable' => 0,
    'type' => 'piwik_stats',
  );

  // Exported field_base: 'field_piwik_stats_uge'.
  $field_bases['field_piwik_stats_uge'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_piwik_stats_uge',
    'indexes' => array(
      'hits' => array(
        0 => 'nb_hits',
        1 => 'entry_nb_actions',
      ),
      'rate' => array(
        0 => 'bounce_rate',
        1 => 'exit_rate',
      ),
      'visits' => array(
        0 => 'nb_visits',
        1 => 'entry_nb_visits',
        2 => 'exit_nb_visits',
      ),
    ),
    'locked' => 0,
    'module' => 'piwik_stats',
    'settings' => array(
      'period' => 'week',
      'show_in_statistics_page' => 1,
    ),
    'translatable' => 0,
    'type' => 'piwik_stats',
  );

  return $field_bases;
}
