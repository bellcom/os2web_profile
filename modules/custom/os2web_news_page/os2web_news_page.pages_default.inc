<?php
/**
 * @file
 * os2web_news_page.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function os2web_news_page_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'os2web_news_page';
  $page->task = 'page';
  $page->admin_title = 'OS2web News Page';
  $page->admin_description = '';
  $page->path = 'nyheder/!placering';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'placering' => array(
      'id' => 1,
      'identifier' => 'Taksonomiterm: ID',
      'name' => 'term',
      'settings' => array(
        'input_form' => 'term',
        'vids' => array(
          11 => '11',
          8 => '8',
          2 => 0,
          6 => 0,
          10 => 0,
          4 => 0,
          12 => 0,
          13 => 0,
          5 => 0,
          7 => 0,
          3 => 0,
          1 => 0,
          9 => 0,
        ),
        'breadcrumb' => 1,
        'transform' => 1,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_os2web_news_page_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'os2web_news_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'os2web-news-page',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
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
      'middle' => NULL,
      'right' => NULL,
      'bottom' => NULL,
      'content' => NULL,
      'sidebar' => NULL,
      'dark_section_1' => NULL,
      'light_section_1' => NULL,
      'light_section_0' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Nyheder %placering:name';
  $display->uuid = 'a6a3927e-1ee7-47a4-8e05-8066c9aef885';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_os2web_news_page_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-85aa3c0e-cede-492d-9f46-7380545bf2e9';
  $pane->panel = 'content';
  $pane->type = 'block';
  $pane->subtype = 'os2web_news_page-news_view_block_with_filter';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
    'css_class' => '',
    'template_suggestion' => 'plain',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '85aa3c0e-cede-492d-9f46-7380545bf2e9';
  $display->content['new-85aa3c0e-cede-492d-9f46-7380545bf2e9'] = $pane;
  $display->panels['content'][0] = 'new-85aa3c0e-cede-492d-9f46-7380545bf2e9';
  $pane = new stdClass();
  $pane->pid = 'new-8f73bf7d-1db1-4f0a-a050-7a438dd5caae';
  $pane->panel = 'light_section_0';
  $pane->type = 'views_panes';
  $pane->subtype = 'os2web_news_page-panel_pane_1';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'arguments' => array(
      'field_os2web_base_field_struct_tid' => '%placering:name',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => '',
    'template_suggestion' => 'plain',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '8f73bf7d-1db1-4f0a-a050-7a438dd5caae';
  $display->content['new-8f73bf7d-1db1-4f0a-a050-7a438dd5caae'] = $pane;
  $display->panels['light_section_0'][0] = 'new-8f73bf7d-1db1-4f0a-a050-7a438dd5caae';
  $pane = new stdClass();
  $pane->pid = 'new-a0f6e46c-f1af-4e4a-a47f-850c014623b1';
  $pane->panel = 'sidebar';
  $pane->type = 'views';
  $pane->subtype = 'news_filter';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '5',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block',
    'override_title' => 1,
    'override_title_text' => 'Vælg i kategori',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => '',
    'template_suggestion' => 'views_panes',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a0f6e46c-f1af-4e4a-a47f-850c014623b1';
  $display->content['new-a0f6e46c-f1af-4e4a-a47f-850c014623b1'] = $pane;
  $display->panels['sidebar'][0] = 'new-a0f6e46c-f1af-4e4a-a47f-850c014623b1';
  $pane = new stdClass();
  $pane->pid = 'new-a68c6609-6b92-4659-9e48-b433fe6f9984';
  $pane->panel = 'sidebar';
  $pane->type = 'views_panes';
  $pane->subtype = 'os2web_news_page-panel_pane_5';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'arguments' => array(
      'field_os2web_base_field_struct_tid' => '%placering:name',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => '',
    'template_suggestion' => 'views_panes',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'a68c6609-6b92-4659-9e48-b433fe6f9984';
  $display->content['new-a68c6609-6b92-4659-9e48-b433fe6f9984'] = $pane;
  $display->panels['sidebar'][1] = 'new-a68c6609-6b92-4659-9e48-b433fe6f9984';
  $pane = new stdClass();
  $pane->pid = 'new-92912015-5111-4611-8e01-8466f6b46053';
  $pane->panel = 'sidebar';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'RSS feed ikon',
    'title' => '',
    'body' => '<p><a href="/nyheder/all/all/rss.xml" target="_blank">RSS</a></p>
',
    'format' => 'full_html',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '92912015-5111-4611-8e01-8466f6b46053';
  $display->content['new-92912015-5111-4611-8e01-8466f6b46053'] = $pane;
  $display->panels['sidebar'][2] = 'new-92912015-5111-4611-8e01-8466f6b46053';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-8f73bf7d-1db1-4f0a-a050-7a438dd5caae';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['os2web_news_page'] = $page;

  return $pages;

}
