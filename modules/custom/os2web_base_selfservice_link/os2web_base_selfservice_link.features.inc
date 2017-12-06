<?php
/**
 * @file
 * os2web_base_selfservice_link.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function os2web_base_selfservice_link_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function os2web_base_selfservice_link_node_info() {
  $items = array(
    'os2web_base_iframe' => array(
      'name' => t('iFrame, Selvbetjeningsløsning mm.'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Overskrift'),
      'help' => '',
    ),
    'os2web_base_selfservice_link' => array(
      'name' => t('Selvbetjening'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Kaldenavn'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
