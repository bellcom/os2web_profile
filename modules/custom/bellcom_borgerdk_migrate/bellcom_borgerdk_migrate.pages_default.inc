<?php
/**
 * @file
 * bellcom_borgerdk_migrate.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function bellcom_borgerdk_migrate_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_58e84743-18a9-4236-abfc-38180d6af916';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -5;
  $handler->conf = array(
    'title' => 'Borger.dk Article',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'borger-dk-article',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'borger_dk_article' => 'borger_dk_article',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'full-width-dark-light-dark-with-right-sidebar-8-4';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'top' => NULL,
      'sidebar' => NULL,
      'content' => NULL,
      'bottom' => NULL,
      'dark_section_1' => NULL,
      'light_section_1' => NULL,
      'light_section_0' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'ece4379e-4bc0-43a3-9e39-59944aeb9668';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__panel_context_58e84743-18a9-4236-abfc-38180d6af916';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-22348682-51c5-4bd7-99d0-7c5254766755';
  $pane->panel = 'content';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_os2web_borger_dk_image';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'slideshow',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'slideshow_image_style' => 'fredericia_content_image',
      'slideshow_link' => '',
      'slideshow_caption' => '',
      'slideshow_caption_link' => '',
      'slideshow_fx' => 'fade',
      'slideshow_speed' => '1000',
      'slideshow_timeout' => '4000',
      'slideshow_order' => '',
      'slideshow_controls' => 0,
      'slideshow_controls_pause' => 0,
      'slideshow_controls_position' => 'after',
      'slideshow_pause' => 0,
      'slideshow_start_on_hover' => 0,
      'slideshow_pager' => '',
      'slideshow_pager_position' => 'after',
      'slideshow_pager_image_style' => 'fredericia_content_image',
      'slideshow_carousel_image_style' => 'fredericia_content_image',
      'slideshow_carousel_visible' => '3',
      'slideshow_carousel_scroll' => '1',
      'slideshow_carousel_speed' => '500',
      'slideshow_carousel_vertical' => 0,
      'slideshow_carousel_circular' => 0,
      'slideshow_carousel_follow' => 0,
      'slideshow_carousel_skin' => '',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'os2-full-width-image',
    'template_suggestion' => 'plain',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '22348682-51c5-4bd7-99d0-7c5254766755';
  $display->content['new-22348682-51c5-4bd7-99d0-7c5254766755'] = $pane;
  $display->panels['content'][0] = 'new-22348682-51c5-4bd7-99d0-7c5254766755';
  $pane = new stdClass();
  $pane->pid = 'new-483e6901-e978-4121-b2eb-1021e302eabd';
  $pane->panel = 'content';
  $pane->type = 'block';
  $pane->subtype = 'os2web_related_links-selfservice_links_block';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Selvbetjening',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'os2-box-quaternary',
    'template_suggestion' => '',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '483e6901-e978-4121-b2eb-1021e302eabd';
  $display->content['new-483e6901-e978-4121-b2eb-1021e302eabd'] = $pane;
  $display->panels['content'][1] = 'new-483e6901-e978-4121-b2eb-1021e302eabd';
  $pane = new stdClass();
  $pane->pid = 'new-4773af2b-a732-4ac5-ad64-c048b8e4e458';
  $pane->panel = 'content';
  $pane->type = 'node_content';
  $pane->subtype = 'node_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'links' => 0,
    'no_extras' => 0,
    'override_title' => 1,
    'override_title_text' => '',
    'identifier' => '',
    'link' => 0,
    'leave_node_title' => 1,
    'build_mode' => 'includeable',
    'context' => 'argument_entity_id:node_1',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => '',
    'template_suggestion' => '',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '4773af2b-a732-4ac5-ad64-c048b8e4e458';
  $display->content['new-4773af2b-a732-4ac5-ad64-c048b8e4e458'] = $pane;
  $display->panels['content'][2] = 'new-4773af2b-a732-4ac5-ad64-c048b8e4e458';
  $pane = new stdClass();
  $pane->pid = 'new-8a8a532c-b46d-4b02-b866-3e7f3656fbc4';
  $pane->panel = 'light_section_1';
  $pane->type = 'views_panes';
  $pane->subtype = 'os2web_node_display-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_entity_id:node_1',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '8a8a532c-b46d-4b02-b866-3e7f3656fbc4';
  $display->content['new-8a8a532c-b46d-4b02-b866-3e7f3656fbc4'] = $pane;
  $display->panels['light_section_1'][0] = 'new-8a8a532c-b46d-4b02-b866-3e7f3656fbc4';
  $pane = new stdClass();
  $pane->pid = 'new-54b1959e-2df8-4a68-a192-8ad73f00548c';
  $pane->panel = 'light_section_1';
  $pane->type = 'views';
  $pane->subtype = 'os2web_editor_information';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 2,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '1',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'default',
    'context' => array(
      0 => '',
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '54b1959e-2df8-4a68-a192-8ad73f00548c';
  $display->content['new-54b1959e-2df8-4a68-a192-8ad73f00548c'] = $pane;
  $display->panels['light_section_1'][1] = 'new-54b1959e-2df8-4a68-a192-8ad73f00548c';
  $pane = new stdClass();
  $pane->pid = 'new-9d75c774-b0ca-418f-98f8-7dcf5ac40f50';
  $pane->panel = 'sidebar';
  $pane->type = 'menu_tree';
  $pane->subtype = '_active';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'menu_name' => '_active',
    'parent_mlid' => '_active:0',
    'title_link' => 0,
    'admin_title' => 'Menu',
    'level' => '1',
    'follow' => 'child',
    'depth' => '1',
    'expanded' => 0,
    'sort' => 0,
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'os2-links-list',
    'template_suggestion' => 'menu_tree',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '9d75c774-b0ca-418f-98f8-7dcf5ac40f50';
  $display->content['new-9d75c774-b0ca-418f-98f8-7dcf5ac40f50'] = $pane;
  $display->panels['sidebar'][0] = 'new-9d75c774-b0ca-418f-98f8-7dcf5ac40f50';
  $pane = new stdClass();
  $pane->pid = 'new-81282eec-9ae4-46f7-9ed2-4ca9162090a0';
  $pane->panel = 'sidebar';
  $pane->type = 'block';
  $pane->subtype = 'os2web_related_links-node_related_links_block';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Læs også',
    'override_title_heading' => 'h3',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'os2-links-list',
    'template_suggestion' => 'block',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '81282eec-9ae4-46f7-9ed2-4ca9162090a0';
  $display->content['new-81282eec-9ae4-46f7-9ed2-4ca9162090a0'] = $pane;
  $display->panels['sidebar'][1] = 'new-81282eec-9ae4-46f7-9ed2-4ca9162090a0';
  $pane = new stdClass();
  $pane->pid = 'new-dfcb7571-f0c4-4e15-a16f-c50abb67082a';
  $pane->panel = 'sidebar';
  $pane->type = 'block';
  $pane->subtype = 'os2web_contact-os2web_contact';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Kontaktinformation',
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
  $pane->uuid = 'dfcb7571-f0c4-4e15-a16f-c50abb67082a';
  $display->content['new-dfcb7571-f0c4-4e15-a16f-c50abb67082a'] = $pane;
  $display->panels['sidebar'][2] = 'new-dfcb7571-f0c4-4e15-a16f-c50abb67082a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_58e84743-18a9-4236-abfc-38180d6af916'] = $handler;

  return $export;
}
