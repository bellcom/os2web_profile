<?php
/**
 * @file
 * os2web_taxonomies.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function os2web_taxonomies_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'os2web_base_term_nodes';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'OS2web Base Term  Nodes';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Portalkategori (field_os2web_base_field_struct) */
  $handler->display->display_options['arguments']['field_os2web_base_field_struct_tid']['id'] = 'field_os2web_base_field_struct_tid';
  $handler->display->display_options['arguments']['field_os2web_base_field_struct_tid']['table'] = 'field_data_field_os2web_base_field_struct';
  $handler->display->display_options['arguments']['field_os2web_base_field_struct_tid']['field'] = 'field_os2web_base_field_struct_tid';
  $handler->display->display_options['arguments']['field_os2web_base_field_struct_tid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_os2web_base_field_struct_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_os2web_base_field_struct_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_os2web_base_field_struct_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_os2web_base_field_struct_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_os2web_base_field_struct_tid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'os2web_base_contentpage' => 'os2web_base_contentpage',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['argument_input'] = array(
    'field_os2web_base_field_struct_tid' => array(
      'type' => 'context',
      'context' => 'entity:node.field_os2web_base_field_struct',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Indhold: Portalkategori (field_os2web_base_field_struct)',
    ),
  );
  $translatables['os2web_base_term_nodes'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Alle'),
    t('Content pane'),
    t('View panes'),
  );
  $export['os2web_base_term_nodes'] = $view;

  return $export;
}
