<?php
/**
 * @file
 * bellcom_borgerdk_migrate.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bellcom_borgerdk_migrate_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_indstillinger|node|borger_dk_article|form';
  $field_group->group_name = 'group_indstillinger';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'borger_dk_article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Indstillinger',
    'weight' => '6',
    'children' => array(
      0 => 'field_os2web_base_field_contact',
      1 => 'field_os2web_base_field_spotbox',
      2 => 'field_os2web_base_hide_sidebar',
      3 => 'field_os2web_base_field_struct',
      4 => 'field_os2web_base_field_promote',
      5 => 'field_os2web_base_field_weight',
      6 => 'field_os2web_base_hide_contact',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-indstillinger field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_indstillinger|node|borger_dk_article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_os2web_base_group_general|node|borger_dk_article|form';
  $field_group->group_name = 'group_os2web_base_group_general';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'borger_dk_article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tekst',
    'weight' => '4',
    'children' => array(
      0 => 'field_borger_dk_pre_text',
      1 => 'field_borger_dk_post_text',
      2 => 'field_borger_dk_header',
      3 => 'field_borger_dk_title',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-os2web-base-group-general field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_os2web_base_group_general|node|borger_dk_article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_relationer|node|borger_dk_article|form';
  $field_group->group_name = 'group_relationer';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'borger_dk_article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Relationer',
    'weight' => '5',
    'children' => array(
      0 => 'field_os2web_base_field_related',
      1 => 'field_os2web_base_field_ext_link',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-relationer field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_relationer|node|borger_dk_article|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Indstillinger');
  t('Relationer');
  t('Tekst');

  return $field_groups;
}
