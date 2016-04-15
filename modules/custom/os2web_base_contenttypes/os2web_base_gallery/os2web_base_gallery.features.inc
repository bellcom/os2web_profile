<?php
/**
 * @file
 * os2web_base_gallery.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function os2web_base_gallery_ctools_plugin_api($module = NULL, $api = NULL) {
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
function os2web_base_gallery_node_info() {
  $items = array(
    'os2web_base_gallery' => array(
      'name' => t('Galleri'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Overskrift'),
      'help' => '',
    ),
  );
  return $items;
}
