<?php
/**
 * @file
 * os2web_base.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function os2web_base_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_edit_panel_context';
  $handler->task = 'node_edit';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Indholdsside',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '.panels-flexible-node_edit-inside { padding: 10px}',
    'contexts' => array(
      0 => array(
        'identifier' => 'Redigeringsformular',
        'keyword' => 'node_add',
        'name' => 'node_add_form',
        'type' => 'os2web_base_contentpage',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'os2web_base_contentpage' => 'os2web_base_contentpage',
            ),
          ),
          'context' => 'argument_node_edit_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible:node_edit';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'lead' => NULL,
      'top_left' => NULL,
      'top_center' => NULL,
      'top_right' => NULL,
      'middle_left' => NULL,
      'middle_right' => NULL,
      'bottom' => NULL,
      'center' => NULL,
      'venstre' => NULL,
      'h__jre' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '4a09a054-3926-4157-9002-a157c729a6d5';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2e28ed08-826a-4a37-aca2-e678b9058389';
    $pane->panel = 'center';
    $pane->type = 'form';
    $pane->subtype = 'form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_node_edit_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '2e28ed08-826a-4a37-aca2-e678b9058389';
    $display->content['new-2e28ed08-826a-4a37-aca2-e678b9058389'] = $pane;
    $display->panels['center'][0] = 'new-2e28ed08-826a-4a37-aca2-e678b9058389';
    $pane = new stdClass();
    $pane->pid = 'new-855f5ab1-95a6-44f0-b7d7-34f4791c483c';
    $pane->panel = 'center';
    $pane->type = 'node_form_buttons';
    $pane->subtype = 'node_form_buttons';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_node_edit_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '855f5ab1-95a6-44f0-b7d7-34f4791c483c';
    $display->content['new-855f5ab1-95a6-44f0-b7d7-34f4791c483c'] = $pane;
    $display->panels['center'][1] = 'new-855f5ab1-95a6-44f0-b7d7-34f4791c483c';
    $pane = new stdClass();
    $pane->pid = 'new-237eed34-fbea-4225-880e-9482aebd8f7e';
    $pane->panel = 'h__jre';
    $pane->type = 'node_form_buttons';
    $pane->subtype = 'node_form_buttons';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_node_edit_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '237eed34-fbea-4225-880e-9482aebd8f7e';
    $display->content['new-237eed34-fbea-4225-880e-9482aebd8f7e'] = $pane;
    $display->panels['h__jre'][0] = 'new-237eed34-fbea-4225-880e-9482aebd8f7e';
    $pane = new stdClass();
    $pane->pid = 'new-ca42a435-1051-45fb-ae38-d62d30f5dc7e';
    $pane->panel = 'h__jre';
    $pane->type = 'node_form_publishing';
    $pane->subtype = 'node_form_publishing';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_node_edit_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'ca42a435-1051-45fb-ae38-d62d30f5dc7e';
    $display->content['new-ca42a435-1051-45fb-ae38-d62d30f5dc7e'] = $pane;
    $display->panels['h__jre'][1] = 'new-ca42a435-1051-45fb-ae38-d62d30f5dc7e';
    $pane = new stdClass();
    $pane->pid = 'new-68f1a123-f559-4e09-b0e7-02e9ac08ab51';
    $pane->panel = 'venstre';
    $pane->type = 'node_form_title';
    $pane->subtype = 'node_form_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_node_edit_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '68f1a123-f559-4e09-b0e7-02e9ac08ab51';
    $display->content['new-68f1a123-f559-4e09-b0e7-02e9ac08ab51'] = $pane;
    $display->panels['venstre'][0] = 'new-68f1a123-f559-4e09-b0e7-02e9ac08ab51';
    $pane = new stdClass();
    $pane->pid = 'new-efd4b121-3119-4ae0-b4ba-0fed4e5e6291';
    $pane->panel = 'venstre';
    $pane->type = 'node_form_path';
    $pane->subtype = 'node_form_path';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_node_edit_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'efd4b121-3119-4ae0-b4ba-0fed4e5e6291';
    $display->content['new-efd4b121-3119-4ae0-b4ba-0fed4e5e6291'] = $pane;
    $display->panels['venstre'][1] = 'new-efd4b121-3119-4ae0-b4ba-0fed4e5e6291';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_edit_panel_context'] = $handler;

  return $export;
}
