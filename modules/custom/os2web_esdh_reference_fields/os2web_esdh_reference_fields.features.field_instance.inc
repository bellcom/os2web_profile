<?php
/**
 * @file
 * os2web_esdh_reference_fields.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function os2web_esdh_reference_fields_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'field_collection_item-field_os2web_paragraphs-field_os2web_base_field_case'.
  $field_instances['field_collection_item-field_os2web_paragraphs-field_os2web_base_field_case'] = array(
    'bundle' => 'field_os2web_paragraphs',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'os2web_esdh_field',
        'settings' => array(),
        'type' => 'os2web_esdh_field_case_ident_for',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_os2web_base_field_case',
    'label' => 'Sag',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'os2web_esdh_field',
      'settings' => array(),
      'type' => 'os2web_esdh_field_case_ident_wid',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_os2web_paragraphs-field_os2web_base_field_casesort'.
  $field_instances['field_collection_item-field_os2web_paragraphs-field_os2web_base_field_casesort'] = array(
    'bundle' => 'field_os2web_paragraphs',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_os2web_base_field_casesort',
    'label' => 'Sortering',
    'required' => 0,
    'settings' => array(
      'select2_integration' => array(
        'styling' => array(
          'dropdownAutoWidth' => 0,
          'placeholder' => '',
        ),
        'use_select2' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'content_taxonomy_opt_groups' => FALSE,
        'use_select2' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_os2web_paragraphs-field_os2web_base_field_doc'.
  $field_instances['field_collection_item-field_os2web_paragraphs-field_os2web_base_field_doc'] = array(
    'bundle' => 'field_os2web_paragraphs',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'os2web_esdh_field',
        'settings' => array(),
        'type' => 'os2web_esdh_field_doc_ident_for',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_os2web_base_field_doc',
    'label' => 'Dokument',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'os2web_esdh_field',
      'settings' => array(),
      'type' => 'os2web_esdh_field_doc_ident_wid',
      'weight' => 7,
    ),
  );

  // Exported field_instance:
  // 'node-os2web_base_contentpage-field_os2web_base_field_case'.
  $field_instances['node-os2web_base_contentpage-field_os2web_base_field_case'] = array(
    'bundle' => 'os2web_base_contentpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'os2web_esdh_field',
        'settings' => array(),
        'type' => 'os2web_esdh_field_case_ident_for',
        'weight' => 26,
      ),
      'includeable' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_os2web_base_field_case',
    'label' => 'Sag',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'os2web_esdh_field',
      'settings' => array(),
      'type' => 'os2web_esdh_field_case_ident_wid',
      'weight' => 13,
    ),
  );

  // Exported field_instance:
  // 'node-os2web_base_contentpage-field_os2web_base_field_casesort'.
  $field_instances['node-os2web_base_contentpage-field_os2web_base_field_casesort'] = array(
    'bundle' => 'os2web_base_contentpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 28,
      ),
      'includeable' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_os2web_base_field_casesort',
    'label' => 'Sortering',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'options',
      'settings' => array(
        'content_taxonomy_opt_groups' => FALSE,
        'use_select2' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 14,
    ),
  );

  // Exported field_instance:
  // 'node-os2web_base_contentpage-field_os2web_base_field_doc'.
  $field_instances['node-os2web_base_contentpage-field_os2web_base_field_doc'] = array(
    'bundle' => 'os2web_base_contentpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'os2web_esdh_field',
        'settings' => array(),
        'type' => 'os2web_esdh_field_doc_ident_for',
        'weight' => 27,
      ),
      'includeable' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_os2web_base_field_doc',
    'label' => 'Dokument',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'os2web_esdh_field',
      'settings' => array(),
      'type' => 'os2web_esdh_field_doc_ident_wid',
      'weight' => 15,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Dokument');
  t('Sag');
  t('Sortering');

  return $field_instances;
}
