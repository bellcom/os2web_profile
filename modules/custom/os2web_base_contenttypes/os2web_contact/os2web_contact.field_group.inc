<?php
/**
 * @file
 * os2web_contact.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function os2web_contact_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_afsnit_tab|node|os2web_contact_contact|form';
  $field_group->group_name = 'group_afsnit_tab';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_contact_contact';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Afsnit',
    'weight' => '43',
    'children' => array(
      0 => 'field_afsnit',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Afsnit',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-afsnit-tab field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_afsnit_tab|node|os2web_contact_contact|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Afsnit');

  return $field_groups;
}
