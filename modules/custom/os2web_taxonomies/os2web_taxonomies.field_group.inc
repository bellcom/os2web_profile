<?php
/**
 * @file
 * os2web_taxonomies.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function os2web_taxonomies_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_billeder|taxonomy_term|os2web_base_tax_site_structure|form';
  $field_group->group_name = 'group_billeder';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'os2web_base_tax_site_structure';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_term';
  $field_group->data = array(
    'label' => 'Billeder og filer',
    'weight' => '14',
    'children' => array(
      0 => 'field_os2web_base_field_banner',
      1 => 'field_os2web_base_field_logo',
      2 => 'field_os2web_base_field_image',
      3 => 'field_os2web_base_field_media',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Billeder og filer',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-billeder field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_billeder|taxonomy_term|os2web_base_tax_site_structure|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_billeder|taxonomy_term|os2web_taxonomies_tax_portal_cat|form';
  $field_group->group_name = 'group_billeder';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'os2web_taxonomies_tax_portal_cat';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_term';
  $field_group->data = array(
    'label' => 'Billeder',
    'weight' => '11',
    'children' => array(
      0 => 'field_os2web_base_field_image',
      1 => 'field_os2web_base_field_banner',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-billeder field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_billeder|taxonomy_term|os2web_taxonomies_tax_portal_cat|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_indhold|taxonomy_term|os2web_taxonomies_tax_portal_cat|form';
  $field_group->group_name = 'group_indhold';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'os2web_taxonomies_tax_portal_cat';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_term';
  $field_group->data = array(
    'label' => 'Indhold',
    'weight' => '10',
    'children' => array(
      0 => 'field_os2web_base_field_spotbox',
      1 => 'field_os2web_base_field_selfserv',
      2 => 'field_os2web_base_field_kle_ref',
      3 => 'field_termtekst',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Indhold',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-indhold field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_indhold|taxonomy_term|os2web_taxonomies_tax_portal_cat|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_indstillinger|taxonomy_term|os2web_taxonomies_tax_portal_cat|form';
  $field_group->group_name = 'group_indstillinger';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'os2web_taxonomies_tax_portal_cat';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_term';
  $field_group->data = array(
    'label' => 'Indstillinger',
    'weight' => '12',
    'children' => array(
      0 => 'field_list_as_spotboks',
      1 => 'field_ikon',
      2 => 'field_os2web_base_field_contact',
      3 => 'path',
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
  $field_groups['group_indstillinger|taxonomy_term|os2web_taxonomies_tax_portal_cat|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_term|taxonomy_term|os2web_base_tax_site_structure|form';
  $field_group->group_name = 'group_term';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'os2web_base_tax_site_structure';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Term',
    'weight' => '3',
    'children' => array(
      0 => 'group_indstillinger',
      1 => 'group_selvbetjening',
      2 => 'group_spotbokse',
      3 => 'group_billeder',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-term field-group-htabs',
      ),
    ),
  );
  $field_groups['group_term|taxonomy_term|os2web_base_tax_site_structure|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_term|taxonomy_term|os2web_taxonomies_tax_portal_cat|form';
  $field_group->group_name = 'group_term';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'os2web_taxonomies_tax_portal_cat';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Term',
    'weight' => '1',
    'children' => array(
      0 => 'group_indhold',
      1 => 'group_billeder',
      2 => 'group_indstillinger',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-term field-group-htabs',
      ),
    ),
  );
  $field_groups['group_term|taxonomy_term|os2web_taxonomies_tax_portal_cat|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Billeder');
  t('Billeder og filer');
  t('Indhold');
  t('Indstillinger');
  t('Term');

  return $field_groups;
}
