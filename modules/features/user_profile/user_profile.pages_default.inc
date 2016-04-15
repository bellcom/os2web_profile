<?php
/**
 * @file
 * user_profile.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function user_profile_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_view__panel_context_787539bf-ea25-43e5-9640-699aece147b7';
  $handler->task = 'user_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'User profile',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'full-width-dark-light-dark-with-right-sidebar-8-4';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '148371e1-7d06-4f3b-aabf-7a139ea106da';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-aac322a3-9190-4db0-8dac-b66e71aaad70';
    $pane->panel = 'content';
    $pane->type = 'user_picture';
    $pane->subtype = 'user_picture';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_entity_id:user_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'aac322a3-9190-4db0-8dac-b66e71aaad70';
    $display->content['new-aac322a3-9190-4db0-8dac-b66e71aaad70'] = $pane;
    $display->panels['content'][0] = 'new-aac322a3-9190-4db0-8dac-b66e71aaad70';
    $pane = new stdClass();
    $pane->pid = 'new-b309fe29-fbd0-49d2-9cc8-f3ddb3be51f0';
    $pane->panel = 'light_section_1';
    $pane->type = 'views';
    $pane->subtype = 'forfatters_indhold';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '100',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_1',
      'context' => array(
        0 => 'argument_entity_id:user_1.uid',
      ),
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b309fe29-fbd0-49d2-9cc8-f3ddb3be51f0';
    $display->content['new-b309fe29-fbd0-49d2-9cc8-f3ddb3be51f0'] = $pane;
    $display->panels['light_section_1'][0] = 'new-b309fe29-fbd0-49d2-9cc8-f3ddb3be51f0';
    $pane = new stdClass();
    $pane->pid = 'new-9848ac7e-a6fc-47ae-bde5-b8577b91da7c';
    $pane->panel = 'sidebar';
    $pane->type = 'token';
    $pane->subtype = 'user:created';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'sanitize' => 1,
      'context' => 'argument_entity_id:user_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9848ac7e-a6fc-47ae-bde5-b8577b91da7c';
    $display->content['new-9848ac7e-a6fc-47ae-bde5-b8577b91da7c'] = $pane;
    $display->panels['sidebar'][0] = 'new-9848ac7e-a6fc-47ae-bde5-b8577b91da7c';
    $pane = new stdClass();
    $pane->pid = 'new-0de93985-2a26-41f4-9e9e-3365fca710f6';
    $pane->panel = 'sidebar';
    $pane->type = 'token';
    $pane->subtype = 'user:mail';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'sanitize' => 1,
      'context' => 'argument_entity_id:user_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '0de93985-2a26-41f4-9e9e-3365fca710f6';
    $display->content['new-0de93985-2a26-41f4-9e9e-3365fca710f6'] = $pane;
    $display->panels['sidebar'][1] = 'new-0de93985-2a26-41f4-9e9e-3365fca710f6';
    $pane = new stdClass();
    $pane->pid = 'new-dd44527c-924e-4717-896a-67bc00023401';
    $pane->panel = 'sidebar';
    $pane->type = 'token';
    $pane->subtype = 'user:last-login';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'sanitize' => 1,
      'context' => 'argument_entity_id:user_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'dd44527c-924e-4717-896a-67bc00023401';
    $display->content['new-dd44527c-924e-4717-896a-67bc00023401'] = $pane;
    $display->panels['sidebar'][2] = 'new-dd44527c-924e-4717-896a-67bc00023401';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['user_view__panel_context_787539bf-ea25-43e5-9640-699aece147b7'] = $handler;

  return $export;
}
