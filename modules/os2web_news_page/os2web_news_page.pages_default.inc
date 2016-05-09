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
  $display->layout = 'threecol_33_34_33_stacked';
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
    ),
  );
  $display->cache = array();
  $display->title = 'Nyheder %placering:name';
  $display->uuid = 'c2197d92-5acf-49da-8087-b348436807c7';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-fbc95b9f-3073-4def-9926-7124a6ff51b8';
    $pane->panel = 'bottom';
    $pane->type = 'views_panes';
    $pane->subtype = 'os2web_news_page-panel_pane_4';
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
      'css_class' => 'well',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'fbc95b9f-3073-4def-9926-7124a6ff51b8';
    $display->content['new-fbc95b9f-3073-4def-9926-7124a6ff51b8'] = $pane;
    $display->panels['bottom'][0] = 'new-fbc95b9f-3073-4def-9926-7124a6ff51b8';
    $pane = new stdClass();
    $pane->pid = 'new-eb58bb75-44be-42ea-91d8-5ac045cb3aa3';
    $pane->panel = 'bottom';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'RSS feed ikon',
      'title' => '',
      'body' => '<a href="/nyheder/all/all/rss.xml" target="_blank">RSS</a>',
      'format' => 'plain_text',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'eb58bb75-44be-42ea-91d8-5ac045cb3aa3';
    $display->content['new-eb58bb75-44be-42ea-91d8-5ac045cb3aa3'] = $pane;
    $display->panels['bottom'][1] = 'new-eb58bb75-44be-42ea-91d8-5ac045cb3aa3';
    $pane = new stdClass();
    $pane->pid = 'new-f5ab0e9d-270a-422a-ba48-62921bbfa88a';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'os2web_news_page-panel_pane_2';
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
      'css_class' => 'well',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f5ab0e9d-270a-422a-ba48-62921bbfa88a';
    $display->content['new-f5ab0e9d-270a-422a-ba48-62921bbfa88a'] = $pane;
    $display->panels['left'][0] = 'new-f5ab0e9d-270a-422a-ba48-62921bbfa88a';
    $pane = new stdClass();
    $pane->pid = 'new-1013bc87-2924-4833-a464-67b288921b34';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'os2web_news_page-panel_pane_3';
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
      'css_class' => 'well',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1013bc87-2924-4833-a464-67b288921b34';
    $display->content['new-1013bc87-2924-4833-a464-67b288921b34'] = $pane;
    $display->panels['middle'][0] = 'new-1013bc87-2924-4833-a464-67b288921b34';
    $pane = new stdClass();
    $pane->pid = 'new-75ae12c0-b3cd-4e3f-a036-38344eb7c306';
    $pane->panel = 'right';
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
      'css_class' => 'well',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '75ae12c0-b3cd-4e3f-a036-38344eb7c306';
    $display->content['new-75ae12c0-b3cd-4e3f-a036-38344eb7c306'] = $pane;
    $display->panels['right'][0] = 'new-75ae12c0-b3cd-4e3f-a036-38344eb7c306';
    $pane = new stdClass();
    $pane->pid = 'new-95758ef9-1908-4686-b0d3-6ad524a16b50';
    $pane->panel = 'top';
    $pane->type = 'views_panes';
    $pane->subtype = 'os2web_news_page-panel_pane_1';
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
      'css_class' => 'well',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '95758ef9-1908-4686-b0d3-6ad524a16b50';
    $display->content['new-95758ef9-1908-4686-b0d3-6ad524a16b50'] = $pane;
    $display->panels['top'][0] = 'new-95758ef9-1908-4686-b0d3-6ad524a16b50';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-95758ef9-1908-4686-b0d3-6ad524a16b50';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['os2web_news_page'] = $page;

  return $pages;

}
