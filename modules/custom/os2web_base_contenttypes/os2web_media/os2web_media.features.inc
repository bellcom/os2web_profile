<?php
/**
 * @file
 * os2web_media.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function os2web_media_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function os2web_media_node_info() {
  $items = array(
    'media' => array(
      'name' => t('Medier'),
      'base' => 'node_content',
      'description' => t('Video og audio.'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  return $items;
}
