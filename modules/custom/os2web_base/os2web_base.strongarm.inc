<?php
/**
 * @file
 * os2web_base.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function os2web_base_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_os2web_base_tax_promoteto_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_os2web_base_tax_promoteto_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_os2web_base_tax_site_structure_pattern';
  $strongarm->value = '[term:parents:join-path]/[term:name]';
  $export['pathauto_taxonomy_term_os2web_base_tax_site_structure_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_os2web_taxonomies_tax_editor_tag_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_os2web_taxonomies_tax_editor_tag_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_os2web_taxonomies_tax_kle_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_os2web_taxonomies_tax_kle_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_os2web_taxonomies_tax_org_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_os2web_taxonomies_tax_org_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_os2web_taxonomies_tax_places_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_os2web_taxonomies_tax_places_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_os2web_taxonomies_tax_politics_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_os2web_taxonomies_tax_politics_pattern'] = $strongarm;

  return $export;
}
