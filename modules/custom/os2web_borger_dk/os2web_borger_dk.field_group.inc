<?php
/**
 * @file
 * os2web_borger_dk.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function os2web_borger_dk_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hidden|node|os2web_borger_dk_article|form';
  $field_group->group_name = 'group_hidden';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_borger_dk_article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Skjult',
    'weight' => '5',
    'children' => array(
      0 => 'field_os2web_borger_dk_formterm',
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
  $field_groups['group_hidden|node|os2web_borger_dk_article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_os2web_base_group_3|node|os2web_borger_dk_article|form';
  $field_group->group_name = 'group_os2web_base_group_3';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_borger_dk_article';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_os2web_base_group_content';
  $field_group->data = array(
    'label' => 'Indstillinger',
    'weight' => '5',
    'children' => array(
      0 => 'field_os2web_base_hide_contact',
      1 => 'field_os2web_base_hide_sidebar',
      2 => 'field_os2web_base_field_struct',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-os2web-base-group-3 field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_os2web_base_group_3|node|os2web_borger_dk_article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_os2web_base_group_content|node|os2web_borger_dk_article|form';
  $field_group->group_name = 'group_os2web_base_group_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_borger_dk_article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Borger.dk artikle',
    'weight' => '1',
    'children' => array(
      0 => 'group_os2web_base_group_general',
      1 => 'group_os2web_borger_dk_text',
      2 => 'group_os2web_base_group_images',
      3 => 'group_relationer',
      4 => 'group_os2web_base_group_3',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-os2web-base-group-content field-group-htabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_os2web_base_group_content|node|os2web_borger_dk_article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_os2web_base_group_general|node|os2web_borger_dk_article|form';
  $field_group->group_name = 'group_os2web_base_group_general';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_borger_dk_article';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_os2web_base_group_content';
  $field_group->data = array(
    'label' => 'tekst',
    'weight' => '1',
    'children' => array(
      0 => 'field_os2web_borger_dk_header',
      1 => 'field_os2web_borger_dk_pagetitle',
      2 => 'field_os2web_borger_dk_post_text',
      3 => 'field_os2web_borger_dk_pre_text',
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
  $field_groups['group_os2web_base_group_general|node|os2web_borger_dk_article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_os2web_base_group_images|node|os2web_borger_dk_article|form';
  $field_group->group_name = 'group_os2web_base_group_images';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_borger_dk_article';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_os2web_base_group_content';
  $field_group->data = array(
    'label' => 'Billeder og filer',
    'weight' => '3',
    'children' => array(
      0 => 'field_os2web_borger_dk_image',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-os2web-base-group-images field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_os2web_base_group_images|node|os2web_borger_dk_article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_os2web_borger_dk_text|node|os2web_borger_dk_article|form';
  $field_group->group_name = 'group_os2web_borger_dk_text';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_borger_dk_article';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_os2web_base_group_content';
  $field_group->data = array(
    'label' => 'Borger tekst',
    'weight' => '2',
    'children' => array(
      0 => 'body',
      1 => 'field_os2web_borger_dk_borgerurl',
      2 => 'field_os2web_borger_dk_byline',
      3 => 'field_os2web_borger_dk_legislati',
      4 => 'field_os2web_borger_dk_recommend',
      5 => 'field_os2web_borger_dk_selfservi',
      6 => 'field_os2web_borger_dk_shortlist',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-os2web-borger-dk-text field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_os2web_borger_dk_text|node|os2web_borger_dk_article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_relationer|node|os2web_borger_dk_article|form';
  $field_group->group_name = 'group_relationer';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_borger_dk_article';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_os2web_base_group_content';
  $field_group->data = array(
    'label' => 'Relationer',
    'weight' => '4',
    'children' => array(
      0 => 'field_os2web_base_field_contact',
      1 => 'field_os2web_base_field_related',
      2 => 'field_os2web_base_field_selfserv',
      3 => 'field_os2web_base_field_spotbox',
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
  $field_groups['group_relationer|node|os2web_borger_dk_article|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Billeder og filer');
  t('Borger tekst');
  t('Borger.dk artikle');
  t('Indstillinger');
  t('Relationer');
  t('Skjult');
  t('tekst');

  return $field_groups;
}
