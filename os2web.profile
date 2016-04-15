<?php

/**
 * @file
 * This file includes all hooks to proper set up profile during install
 */

/**
 * Name of profile; visible in profile selection form.
 */
define('PROFILE_NAME', 'OS2Web Turnkey');

/**
 * Description of profile; visible in profile selection form.
 */
define('PROFILE_DESCRIPTION', 'Generisk Installation af OS2Web.');

/**
 * Implements hook_install_tasks().
 */
function os2web_install_tasks() {
  $task = array(
 //  'os2web_import_database' => array(
   //  'type' => 'normal',
 //    'display_name' => st('Import default database'),
 //  ),
//    'os2web_profile_prepare' => array(
//      'type' => 'normal',
//      'display_name' => st('Prepare OS2web..'),
//    ),
 //  'os2web_settings_form' => array(
 //    'display_name' => st('Setup OS2Web'),
 //    'type' => 'form',
 //  ),

  );
  return $task;
}

/**
 * Implements hook_profile_prepare().
 */
function os2web_profile_prepare() {
  drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);
  // Menu rebuild neccesary to load xpath_parser
  menu_rebuild();
  drupal_set_message('Database import complete, please reload this form to continue.', 'ok');
}



/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Allows the profile to alter the site configuration form.
 */
function os2web_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name with the server name.
  $form['site_information']['site_name']['#default_value'] = 'OS2Web';
  $form['update_notifications']['update_status_module']['#default_value'] = array(0, 0);
  $form['server_settings']['site_default_country']['#default_value'] = 'DK';
  $form['server_settings']['#access'] = FALSE;
  $form['update_notifications']['#access'] = FALSE;
  $form['admin_account']['account']['name']['#default_value'] = 'admin';
}


