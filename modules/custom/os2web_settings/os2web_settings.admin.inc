<?php
/**
 * @file
 * This file describes the admin form for os2web
 */

function os2web_settings_settings_form($form, $form_state) {

  $form['os2web_settings_config_group'] = array(
    '#type' => 'fieldset',
    '#title' => t('OS2web'),
  );
  $form['os2web_settings_config_group']['os2web_settings_techmaster_email'] = array(
    '#type' => 'textfield',
    '#title' => 'OS2web webmaster email. This email will recieve error emails from OS2web.',
    '#description' => 'Seperate multiple emails with commas.',
    '#default_value' => variable_get('os2web_settings_techmaster_email', NULL),
  );
  $form['os2web_settings_config_group']['os2web_settings_sanetize_filename'] = array(
    '#type' => 'checkbox',
    '#title' => 'Use transliteration module for sanetize bilag\'s filename',
    '#description' => 'This decides whether a contrib transliteration module wll be used for sanetize bilag\'s filename during import or custom function in os2web_esdh_provider module.',
    '#default_value' => variable_get('os2web_settings_sanetize_filename', TRUE),
  );

  return system_settings_form($form);
}
