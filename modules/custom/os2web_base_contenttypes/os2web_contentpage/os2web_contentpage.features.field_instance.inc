<?php
/**
 * @file
 * os2web_contentpage.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function os2web_contentpage_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-os2web_base_contentpage-body'
  $field_instances['node-os2web_base_contentpage-body'] = array(
    'bundle' => 'os2web_base_contentpage',
    'default_value' => array(
      0 => array(
        'summary' => '',
        'value' => '',
        'format' => 'filtered_html',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'related_block' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'spotbox' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Indhold',
    'required' => 0,
    'settings' => array(
      'display_summary' => 0,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-os2web_base_contentpage-field_os2web_base_field_contact'
  $field_instances['node-os2web_base_contentpage-field_os2web_base_field_contact'] = array(
    'bundle' => 'os2web_base_contentpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 16,
      ),
      'related_block' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'spotbox' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 15,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_os2web_base_field_contact',
    'label' => 'Kontaktblok',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'node_reference',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'autocomplete_path' => 'node_reference/autocomplete',
        'size' => 60,
      ),
      'type' => 'node_reference_autocomplete',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'node-os2web_base_contentpage-field_os2web_base_field_edi_tags'
  $field_instances['node-os2web_base_contentpage-field_os2web_base_field_edi_tags'] = array(
    'bundle' => 'os2web_base_contentpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Opmærk dit indhold med dine egne stikord.
<br>Dette giver mulighed for at sammenkoble relateret indhold i listevisninger mv.
<br>Adskil flere opmærkninger med komma.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 18,
      ),
      'related_block' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'spotbox' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 17,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_os2web_base_field_edi_tags',
    'label' => 'Stikord',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'content_taxonomy_autocomplete_new_terms' => 'allow',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'node-os2web_base_contentpage-field_os2web_base_field_ext_link'
  $field_instances['node-os2web_base_contentpage-field_os2web_base_field_ext_link'] = array(
    'bundle' => 'os2web_base_contentpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'spotbox' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_os2web_base_field_ext_link',
    'label' => 'Unikke eksterne links	',
    'required' => 0,
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'configurable_title' => 0,
        'rel' => '',
        'target' => '_blank',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'rel_remove' => 'default',
      'title' => 'required',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 0,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 47,
    ),
  );

  // Exported field_instance: 'node-os2web_base_contentpage-field_os2web_base_field_hidlinks'
  $field_instances['node-os2web_base_contentpage-field_os2web_base_field_hidlinks'] = array(
    'bundle' => 'os2web_base_contentpage',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
      'related_block' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'spotbox' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_os2web_base_field_hidlinks',
    'label' => 'Skjul automatisk relaterede links',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-os2web_base_contentpage-field_os2web_base_field_image'
  $field_instances['node-os2web_base_contentpage-field_os2web_base_field_image'] = array(
    'bundle' => 'os2web_base_contentpage',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'field_slideshow',
        'settings' => array(
          'slideshow_caption' => 'title',
          'slideshow_caption_link' => '',
          'slideshow_carousel_circular' => 0,
          'slideshow_carousel_follow' => 0,
          'slideshow_carousel_image_style' => '',
          'slideshow_carousel_scroll' => 1,
          'slideshow_carousel_skin' => '',
          'slideshow_carousel_speed' => 500,
          'slideshow_carousel_vertical' => 0,
          'slideshow_carousel_visible' => 3,
          'slideshow_colorbox_image_style' => '',
          'slideshow_colorbox_slideshow' => '',
          'slideshow_colorbox_slideshow_speed' => 4000,
          'slideshow_colorbox_speed' => 350,
          'slideshow_colorbox_transition' => 'elastic',
          'slideshow_controls' => 0,
          'slideshow_controls_pause' => 0,
          'slideshow_controls_position' => 'after',
          'slideshow_field_collection_image' => '',
          'slideshow_fx' => 'fade',
          'slideshow_image_style' => 'fredericia_content_image',
          'slideshow_link' => '',
          'slideshow_order' => '',
          'slideshow_pager' => '',
          'slideshow_pager_image_style' => '',
          'slideshow_pager_position' => 'after',
          'slideshow_pause' => 0,
          'slideshow_speed' => 1000,
          'slideshow_start_on_hover' => 0,
          'slideshow_timeout' => 4000,
        ),
        'type' => 'slideshow',
        'weight' => 1,
      ),
      'related_block' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'spotbox' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_os2web_base_field_image',
    'label' => 'Billede',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'alt_field_required' => 1,
      'default_image' => 0,
      'epsacrop' => array(
        'styles' => array(
          'os2web_spotbox_image' => 0,
          'fredericia_content_image' => 'fredericia_content_image',
          'fredericia_spotbox' => 0,
        ),
      ),
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'focus' => 0,
      'focus_lock_ratio' => 0,
      'focus_min_size' => '',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '900x419',
      'title_field' => 0,
      'title_field_required' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'public' => 'public',
          'ustream' => 0,
          'youtube' => 0,
        ),
        'allowed_types' => array(
          'application' => 0,
          'audio' => 0,
          'document' => 0,
          'image' => 'image',
          'video' => 0,
        ),
        'browser_plugins' => array(
          'media_browser_plus--media_browser_my_files' => 'media_browser_plus--media_browser_my_files',
          'media_browser_plus--media_browser_thumbnails' => 'media_browser_plus--media_browser_thumbnails',
          'media_default--media_browser_1' => 'media_default--media_browser_1',
          'media_default--media_browser_my_files' => 'media_default--media_browser_my_files',
          'media_internet' => 'media_internet',
          'upload' => 'upload',
          'youtube' => 0,
        ),
        'progress_indicator' => 'throbber',
      ),
      'type' => 'media_generic',
      'weight' => -3,
    ),
  );

  // Exported field_instance: 'node-os2web_base_contentpage-field_os2web_base_field_kle_ref'
  $field_instances['node-os2web_base_contentpage-field_os2web_base_field_kle_ref'] = array(
    'bundle' => 'os2web_base_contentpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Opmærk dit indhold med KLs Emneord.
<br>Se fuld oversigt på <a target="_blank" href="http://www.kle-online.dk">KLE-Online</a>.
<br>Adskil flere opmærkninger med komma.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 17,
      ),
      'related_block' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'spotbox' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 16,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_os2web_base_field_kle_ref',
    'label' => 'KL Emneord',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'content_taxonomy_autocomplete_new_terms' => 'deny',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-os2web_base_contentpage-field_os2web_base_field_loca_ref'
  $field_instances['node-os2web_base_contentpage-field_os2web_base_field_loca_ref'] = array(
    'bundle' => 'os2web_base_contentpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Opmærk dit indhold med steder fra kommunens GIS system.
<br>Dette giver mulighed for kortvisning.
<br>Adskil flere opmærkninger med komma.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 19,
      ),
      'related_block' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'spotbox' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 18,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_os2web_base_field_loca_ref',
    'label' => 'Egennavne/stednavne',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'content_taxonomy_autocomplete_new_terms' => 'deny',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-os2web_base_contentpage-field_os2web_base_field_media'
  $field_instances['node-os2web_base_contentpage-field_os2web_base_field_media'] = array(
    'bundle' => 'os2web_base_contentpage',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_table',
        'weight' => 5,
      ),
      'related_block' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'spotbox' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_os2web_base_field_media',
    'label' => 'PDF filer',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'PDF',
      'file_extensions' => 'pdf swf doc docx xlsx xls ppt pptx',
      'max_filesize' => '50 MB',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'public' => 'public',
          'youtube' => 0,
        ),
        'allowed_types' => array(
          'application' => 'application',
          'audio' => 'audio',
          'document' => 'document',
          'image' => 0,
          'video' => 0,
        ),
        'browser_plugins' => array(
          'media_default--media_browser_1' => 'media_default--media_browser_1',
          'media_default--media_browser_my_files' => 'media_default--media_browser_my_files',
          'media_internet' => 0,
          'upload' => 'upload',
          'youtube' => 0,
        ),
        'progress_indicator' => 'throbber',
      ),
      'type' => 'media_generic',
      'weight' => -1,
    ),
  );

  // Exported field_instance: 'node-os2web_base_contentpage-field_os2web_base_field_organiz'
  $field_instances['node-os2web_base_contentpage-field_os2web_base_field_organiz'] = array(
    'bundle' => 'os2web_base_contentpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Opmærk dit indhold med kommunens organisation.
<br>Dette giver mulighed for at sammenkoble relateret indhold i listevisninger mv.
<br>Adskil flere opmærkninger med komma.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 20,
      ),
      'related_block' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'spotbox' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 19,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_os2web_base_field_organiz',
    'label' => 'Organistation',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'content_taxonomy_autocomplete_new_terms' => 'deny',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-os2web_base_contentpage-field_os2web_base_field_politics'
  $field_instances['node-os2web_base_contentpage-field_os2web_base_field_politics'] = array(
    'bundle' => 'os2web_base_contentpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Opmærk dit indhold med politisk parti, råd, nævn eller udvalg.
<br>Dette giver mulighed for at sammenkoble relateret indhold i listevisninger mv.
<br>Adskil flere opmærkninger med komma.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 13,
      ),
      'related_block' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'spotbox' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_os2web_base_field_politics',
    'label' => 'Politik',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'content_taxonomy_autocomplete_new_terms' => 'deny',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-os2web_base_contentpage-field_os2web_base_field_related'
  $field_instances['node-os2web_base_contentpage-field_os2web_base_field_related'] = array(
    'bundle' => 'os2web_base_contentpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
      'spotbox' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_os2web_base_field_related',
    'label' => 'Unikke relaterede links',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'node_reference',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'autocomplete_path' => 'node_reference/autocomplete',
        'size' => 60,
      ),
      'type' => 'node_reference_autocomplete',
      'weight' => 45,
    ),
  );

  // Exported field_instance: 'node-os2web_base_contentpage-field_os2web_base_field_selfserv'
  $field_instances['node-os2web_base_contentpage-field_os2web_base_field_selfserv'] = array(
    'bundle' => 'os2web_base_contentpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
      'related_block' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'spotbox' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 13,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_os2web_base_field_selfserv',
    'label' => 'Selvbetjening',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'node_reference',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'autocomplete_path' => 'node_reference/autocomplete',
        'size' => 60,
      ),
      'type' => 'node_reference_autocomplete',
      'weight' => 44,
    ),
  );

  // Exported field_instance: 'node-os2web_base_contentpage-field_os2web_base_field_spotbox'
  $field_instances['node-os2web_base_contentpage-field_os2web_base_field_spotbox'] = array(
    'bundle' => 'os2web_base_contentpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 15,
      ),
      'related_block' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'spotbox' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_os2web_base_field_spotbox',
    'label' => 'Spotboxe',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'node_reference',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'autocomplete_path' => 'node_reference/autocomplete',
        'size' => 60,
      ),
      'type' => 'node_reference_autocomplete',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'node-os2web_base_contentpage-field_os2web_base_field_summary'
  $field_instances['node-os2web_base_contentpage-field_os2web_base_field_summary'] = array(
    'bundle' => 'os2web_base_contentpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'related_block' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'spotbox' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_os2web_base_field_summary',
    'label' => 'Intro / Resume (maks 2 linier!)',
    'required' => 0,
    'settings' => array(
      'display_summary' => 0,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 2,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-os2web_base_contentpage-field_os2web_base_field_sympage'
  $field_instances['node-os2web_base_contentpage-field_os2web_base_field_sympage'] = array(
    'bundle' => 'os2web_base_contentpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(
          'node_reference_view_mode' => 'teaser',
        ),
        'type' => 'node_reference_node',
        'weight' => 4,
      ),
      'spotbox' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_os2web_base_field_sympage',
    'label' => 'Indlejret side',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'node_reference',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'autocomplete_path' => 'node_reference/autocomplete',
        'size' => 60,
      ),
      'type' => 'node_reference_autocomplete',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'node-os2web_base_contentpage-field_os2web_base_field_video'
  $field_instances['node-os2web_base_contentpage-field_os2web_base_field_video'] = array(
    'bundle' => 'os2web_base_contentpage',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'file_entity',
        'settings' => array(
          'file_view_mode' => 'default',
        ),
        'type' => 'file_rendered',
        'weight' => 0,
      ),
      'spotbox' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_os2web_base_field_video',
    'label' => 'Video',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'alt_field_required' => 1,
      'default_image' => 0,
      'epsacrop' => array(
        'styles' => array(
          'os2web_spotbox_image' => 0,
          'fredericia_content_image' => 0,
          'fredericia_spotbox' => 0,
        ),
      ),
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'focus' => 0,
      'focus_lock_ratio' => 0,
      'focus_min_size' => '',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'title_field_required' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'public' => 'public',
          'ustream' => 'ustream',
          'youtube' => 'youtube',
        ),
        'allowed_types' => array(
          'application' => 0,
          'audio' => 0,
          'document' => 0,
          'image' => 0,
          'video' => 'video',
        ),
        'browser_plugins' => array(
          'media_browser_plus--media_browser_my_files' => 'media_browser_plus--media_browser_my_files',
          'media_browser_plus--media_browser_thumbnails' => 'media_browser_plus--media_browser_thumbnails',
          'media_default--media_browser_1' => 'media_default--media_browser_1',
          'media_default--media_browser_my_files' => 'media_default--media_browser_my_files',
          'media_internet' => 'media_internet',
          'upload' => 'upload',
          'youtube' => 0,
        ),
        'progress_indicator' => 'throbber',
      ),
      'type' => 'media_generic',
      'weight' => -2,
    ),
  );

  // Exported field_instance: 'node-os2web_base_contentpage-field_os2web_base_field_webform'
  $field_instances['node-os2web_base_contentpage-field_os2web_base_field_webform'] = array(
    'bundle' => 'os2web_base_contentpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'spotbox' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_os2web_base_field_webform',
    'label' => 'Webform',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'node_reference',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'autocomplete_path' => 'node_reference/autocomplete',
        'size' => 60,
      ),
      'type' => 'node_reference_autocomplete',
      'weight' => 15,
    ),
  );

  // Exported field_instance: 'node-os2web_base_contentpage-field_os2web_base_hide_contact'
  $field_instances['node-os2web_base_contentpage-field_os2web_base_hide_contact'] = array(
    'bundle' => 'os2web_base_contentpage',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 23,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_os2web_base_hide_contact',
    'label' => 'Skjul højre kontaktblok',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-os2web_base_contentpage-field_os2web_base_hide_sidebar'
  $field_instances['node-os2web_base_contentpage-field_os2web_base_hide_sidebar'] = array(
    'bundle' => 'os2web_base_contentpage',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 22,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_os2web_base_hide_sidebar',
    'label' => 'Skjul højre sidebar',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-os2web_base_contentpage-field_os2web_paragraphs'
  $field_instances['node-os2web_base_contentpage-field_os2web_paragraphs'] = array(
    'bundle' => 'os2web_base_contentpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'field_collection_fieldset',
        'settings' => array(
          'add' => 'Tilføj',
          'collapsed' => 1,
          'collapsible' => 1,
          'delete' => 'Slet',
          'description' => 1,
          'edit' => 'Redigér',
          'legend' => 'field_os2web_paragraph_title',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_fieldset_view',
        'weight' => 21,
      ),
      'spotbox' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_os2web_paragraphs',
    'label' => 'Afsnit',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 48,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Afsnit');
  t('Billede');
  t('Egennavne/stednavne');
  t('Indhold');
  t('Indlejret side');
  t('Intro / Resume (maks 2 linier!)');
  t('KL Emneord');
  t('Kontaktblok');
  t('Opmærk dit indhold med KLs Emneord.
<br>Se fuld oversigt på <a target="_blank" href="http://www.kle-online.dk">KLE-Online</a>.
<br>Adskil flere opmærkninger med komma.');
  t('Opmærk dit indhold med dine egne stikord.
<br>Dette giver mulighed for at sammenkoble relateret indhold i listevisninger mv.
<br>Adskil flere opmærkninger med komma.');
  t('Opmærk dit indhold med kommunens organisation.
<br>Dette giver mulighed for at sammenkoble relateret indhold i listevisninger mv.
<br>Adskil flere opmærkninger med komma.');
  t('Opmærk dit indhold med politisk parti, råd, nævn eller udvalg.
<br>Dette giver mulighed for at sammenkoble relateret indhold i listevisninger mv.
<br>Adskil flere opmærkninger med komma.');
  t('Opmærk dit indhold med steder fra kommunens GIS system.
<br>Dette giver mulighed for kortvisning.
<br>Adskil flere opmærkninger med komma.');
  t('Organistation');
  t('PDF filer');
  t('Politik');
  t('Selvbetjening');
  t('Skjul automatisk relaterede links');
  t('Skjul højre kontaktblok');
  t('Skjul højre sidebar');
  t('Spotboxe');
  t('Stikord');
  t('Unikke eksterne links	');
  t('Unikke relaterede links');
  t('Video');
  t('Webform');

  return $field_instances;
}
