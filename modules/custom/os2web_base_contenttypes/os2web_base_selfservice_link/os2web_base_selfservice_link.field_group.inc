<?php
/**
 * @file
 * os2web_base_selfservice_link.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function os2web_base_selfservice_link_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hidden|node|os2web_base_selfservice_link|form';
  $field_group->group_name = 'group_hidden';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_selfservice_link';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Skjult',
    'weight' => '10',
    'children' => array(
      0 => 'field_os2web_base_field_direct',
      1 => 'field_os2web_base_field_grp_id',
      2 => 'field_os2web_base_field_kle_ref',
      3 => 'field_os2web_base_field_ref_node',
      4 => 'field_os2web_base_field_source',
      5 => 'field_os2web_base_field_struct',
      6 => 'field_os2web_base_field_type',
      7 => 'metatags',
      8 => 'path',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Skjult',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-hidden field-group-div hidden',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_hidden|node|os2web_base_selfservice_link|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_os2web_base_group_taxono|node|os2web_base_iframe|form';
  $field_group->group_name = 'group_os2web_base_group_taxono';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_iframe';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Taksonomi',
    'weight' => '8',
    'children' => array(
      0 => 'field_os2web_base_field_kle_ref',
      1 => 'field_os2web_base_field_edi_tags',
      2 => 'field_os2web_base_field_organiz',
      3 => 'field_os2web_base_field_loca_ref',
      4 => 'field_os2web_base_field_politics',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_os2web_base_group_taxono|node|os2web_base_iframe|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Skjult');
  t('Taksonomi');

  return $field_groups;
}
