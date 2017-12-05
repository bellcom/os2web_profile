<?php
/**
 * @file
 * os2web_base_selfservice_link.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function os2web_base_selfservice_link_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__os2web_base_selfservice_link';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '7',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '12',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__os2web_base_selfservice_link'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_os2web_base_selfservice_link';
  $strongarm->value = '0';
  $export['language_content_type_os2web_base_selfservice_link'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_os2web_base_selfservice_link';
  $strongarm->value = array();
  $export['menu_options_os2web_base_selfservice_link'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_os2web_base_selfservice_link';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_os2web_base_selfservice_link'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_os2web_base_selfservice_link';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_os2web_base_selfservice_link'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_os2web_base_selfservice_link';
  $strongarm->value = '0';
  $export['node_preview_os2web_base_selfservice_link'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_os2web_base_selfservice_link';
  $strongarm->value = 0;
  $export['node_submitted_os2web_base_selfservice_link'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_os2web_base_iframe_pattern';
  $strongarm->value = '';
  $export['pathauto_node_os2web_base_iframe_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_os2web_base_selfservice_link_pattern';
  $strongarm->value = 'noindex/[node:title]';
  $export['pathauto_node_os2web_base_selfservice_link_pattern'] = $strongarm;

  return $export;
}
