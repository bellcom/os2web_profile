<?php
/**
 * @file
 * piwik_fredericia_prod_settings.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function piwik_fredericia_prod_settings_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'piwik_site_id';
  $strongarm->value = '2';
  $export['piwik_site_id'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'piwik_url_http';
  $strongarm->value = 'http://piwik.fredericia.bellcom.dk/';
  $export['piwik_url_http'] = $strongarm;

  return $export;
}
