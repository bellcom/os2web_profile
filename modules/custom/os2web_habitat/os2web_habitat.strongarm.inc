<?php
/**
 * @file
 * os2web_habitat.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function os2web_habitat_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'habitat_disable_dev';
  $strongarm->value = array(
    0 => 'piwik',
    1 => 'piwik_fredericia_prod_settings',
  );
  $export['habitat_disable_dev'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'habitat_disable_preprod';
  $strongarm->value = array(
    0 => 'piwik',
    1 => 'piwik_fredericia_prod_settings',
  );
  $export['habitat_disable_preprod'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'habitat_disable_prod';
  $strongarm->value = array(
    0 => 'habitat_ui',
    1 => 'stage_file_proxy',
    2 => 'dblog',
  );
  $export['habitat_disable_prod'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'habitat_disable_test';
  $strongarm->value = array(
    0 => 'piwik',
    1 => 'piwik_fredericia_prod_settings',
  );
  $export['habitat_disable_test'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'habitat_enable_dev';
  $strongarm->value = array(
    0 => 'stage_file_proxy',
  );
  $export['habitat_enable_dev'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'habitat_enable_preprod';
  $strongarm->value = array(
    0 => 'stage_file_proxy',
    1 => 'syslog',
    2 => 'reroute_email',
  );
  $export['habitat_enable_preprod'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'habitat_enable_prod';
  $strongarm->value = array(
    0 => 'syslog',
    1 => 'piwik_fredericia_prod_settings',
  );
  $export['habitat_enable_prod'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'habitat_enable_test';
  $strongarm->value = array(
    0 => 'stage_file_proxy',
    1 => 'syslog',
    2 => 'reroute_email',
  );
  $export['habitat_enable_test'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'habitat_habitats';
  $strongarm->value = array(
    0 => 'dev',
    1 => 'test',
    2 => 'preprod',
    3 => 'prod',
  );
  $export['habitat_habitats'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'habitat_variable';
  $strongarm->value = 'environment';
  $export['habitat_variable'] = $strongarm;

  return $export;
}
