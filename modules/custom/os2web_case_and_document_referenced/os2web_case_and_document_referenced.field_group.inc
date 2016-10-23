<?php
/**
 * @file
 * os2web_esdh_reference_fields.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function os2web_esdh_reference_fields_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_os2web_base_group_esdh|field_collection_item|field_os2web_paragraphs|form';
  $field_group->group_name = 'group_os2web_base_group_esdh';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_os2web_paragraphs';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sager og dokumenter',
    'weight' => '6',
    'children' => array(
      1 => 'field_os2web_base_case_ref',
      2 => 'field_os2web_base_doc_ref',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-os2web-base-group-esdh field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_os2web_base_group_esdh|field_collection_item|field_os2web_paragraphs|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sager og dokumenter');

  return $field_groups;
}
