<?php
/**
 * @file
 * os2web_base_rotating_image.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function os2web_base_rotating_image_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function os2web_base_rotating_image_node_info() {
  $items = array(
    'os2web_base_rotating_image' => array(
      'name' => t('Billedekarrusel'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Overskrift'),
      'help' => '',
    ),
  );
  return $items;
}
