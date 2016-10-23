<?php
/**
 * @file
 * os2web_case_and_document_referenced.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function os2web_case_and_document_referenced_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'field_collection_item-field_os2web_paragraphs-field_os2web_base_case_ref'.
  $field_instances['field_collection_item-field_os2web_paragraphs-field_os2web_base_case_ref'] = array(
    'bundle' => 'field_os2web_paragraphs',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Vis alle dokumenter der er tilknyttet en sag.
Der kan søges i dette felt på sagsnummeret og på sagens titel.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'links' => 0,
          'view_mode' => 'list',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_os2web_base_case_ref',
    'label' => 'Sagsreference',
    'required' => 0,
    'settings' => array(
      'select2_integration' => array(
        'hide_id' => 0,
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
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 9,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_os2web_paragraphs-field_os2web_base_doc_ref'.
  $field_instances['field_collection_item-field_os2web_paragraphs-field_os2web_base_doc_ref'] = array(
    'bundle' => 'field_os2web_paragraphs',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Vis et eller flere dokumenter.
Der kan søges i dette felt på sagsnummeret og på dokumentets titel.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'links' => 0,
          'view_mode' => 'list',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_os2web_base_doc_ref',
    'label' => 'Dokument reference',
    'required' => 0,
    'settings' => array(
      'select2_integration' => array(
        'hide_id' => 0,
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
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 10,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Dokument reference');
  t('Sagsreference');
  t('Vis alle dokumenter der er tilknyttet en sag.
Der kan søges i dette felt på sagsnummeret og på sagens titel.');
  t('Vis et eller flere dokumenter.
Der kan søges i dette felt på sagsnummeret og på dokumentets titel.');

  return $field_instances;
}
