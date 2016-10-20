<?php
/**
 * @file
 * os2web_esdh_reference_fields.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function os2web_esdh_reference_fields_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}
