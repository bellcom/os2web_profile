<?php
/**
 * @file
 * os2web_esdh_reference_fields.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function os2web_esdh_reference_fields_field_default_field_bases() {
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

  return $field_bases;
}
