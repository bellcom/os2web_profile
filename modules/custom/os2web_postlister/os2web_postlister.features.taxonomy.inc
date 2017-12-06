<?php
/**
 * @file
 * os2web_postlister.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function os2web_postlister_taxonomy_default_vocabularies() {
  return array(
    'postlister' => array(
      'name' => 'Postlister',
      'machine_name' => 'postlister',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
