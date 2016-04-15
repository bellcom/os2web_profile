<?php
/**
 * @file
 * os2web_base.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function os2web_base_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_indstillinger|taxonomy_term|os2web_base_tax_site_structure|form';
  $field_group->group_name = 'group_indstillinger';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'os2web_base_tax_site_structure';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_term';
  $field_group->data = array(
    'label' => 'Indstillinger',
    'weight' => '45',
    'children' => array(
      0 => 'field_alternative_display',
      1 => 'field_list_as_spotboks',
      2 => 'field_os2web_base_field_contact',
      3 => 'field_os2web_base_field_ext_link',
      4 => 'field_os2web_base_field_hidlinks',
      5 => 'field_os2web_base_field_related',
      6 => 'field_os2web_base_hide_contact',
      7 => 'field_os2web_base_hide_sidebar',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-indstillinger field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_indstillinger|taxonomy_term|os2web_base_tax_site_structure|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_selvbetjening|taxonomy_term|os2web_base_tax_site_structure|form';
  $field_group->group_name = 'group_selvbetjening';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'os2web_base_tax_site_structure';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_term';
  $field_group->data = array(
    'label' => 'Selvbetjeningslinks',
    'weight' => '44',
    'children' => array(
      0 => 'field_os2web_base_field_selfserv',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-selvbetjening field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_selvbetjening|taxonomy_term|os2web_base_tax_site_structure|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_spotbokse|taxonomy_term|os2web_base_tax_site_structure|form';
  $field_group->group_name = 'group_spotbokse';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'os2web_base_tax_site_structure';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_term';
  $field_group->data = array(
    'label' => 'Spotbokse',
    'weight' => '43',
    'children' => array(
      0 => 'field_os2web_base_field_spotbox',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-spotbokse field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_spotbokse|taxonomy_term|os2web_base_tax_site_structure|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Indstillinger');
  t('Selvbetjeningslinks');
  t('Spotbokse');

  return $field_groups;
}
