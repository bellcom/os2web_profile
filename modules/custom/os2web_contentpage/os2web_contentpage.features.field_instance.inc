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

  // Exported field_instance:
  // 'field_collection_item-field_os2web_paragraphs-field_os2web_base_field_case'.
  $field_instances['field_collection_item-field_os2web_paragraphs-field_os2web_base_field_case'] = array(
    'bundle' => 'field_os2web_paragraphs',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'os2web_esdh_field',
        'settings' => array(),
        'type' => 'os2web_esdh_field_case_ident_for',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_os2web_base_field_case',
    'label' => 'Sag',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'os2web_esdh_field',
      'settings' => array(),
      'type' => 'os2web_esdh_field_case_ident_wid',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_os2web_paragraphs-field_os2web_base_field_casesort'.
  $field_instances['field_collection_item-field_os2web_paragraphs-field_os2web_base_field_casesort'] = array(
    'bundle' => 'field_os2web_paragraphs',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_os2web_base_field_casesort',
    'label' => 'Sortering',
    'required' => 0,
    'settings' => array(
      'select2_integration' => array(
        'styling' => array(
          'dropdownAutoWidth' => 0,
          'placeholder' => '',
        ),
        'use_select2' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'content_taxonomy_opt_groups' => FALSE,
        'use_select2' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_os2web_paragraphs-field_os2web_base_field_doc'.
  $field_instances['field_collection_item-field_os2web_paragraphs-field_os2web_base_field_doc'] = array(
    'bundle' => 'field_os2web_paragraphs',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'os2web_esdh_field',
        'settings' => array(),
        'type' => 'os2web_esdh_field_doc_ident_for',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_os2web_base_field_doc',
    'label' => 'Dokument',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'os2web_esdh_field',
      'settings' => array(),
      'type' => 'os2web_esdh_field_doc_ident_wid',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-os2web_base_contentpage-body'.
  $field_instances['node-os2web_base_contentpage-body'] = array(
    'bundle' => 'os2web_base_contentpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<ul><li>Skriv en god og fyldestgørende tekst. Tænk på at der er forskellige typer læsere til teksten, og at ikke alle har den fornødne viden til at fortolke svære ord.</li>
<li>Husk at tilføje relaterede interne og eksterne links under fanen Relationer. Det giver de besøgende en bedre oplevelse af et helstøbt website.</li>
</ul>',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'includeable' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'related_block' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 600,
        ),
        'type' => 'text_trimmed',
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
    'field_name' => 'body',
    'label' => 'Indhold',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'blokindhold' => 'blokindhold',
          'email' => 'email',
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'blokindhold' => array(
              'weight' => -7,
            ),
            'email' => array(
              'weight' => 0,
            ),
            'filtered_html' => array(
              'weight' => -10,
            ),
            'full_html' => array(
              'weight' => -9,
            ),
            'plain_text' => array(
              'weight' => -8,
            ),
          ),
        ),
      ),
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

  // Exported field_instance:
  // 'node-os2web_base_contentpage-field_os2web_base_field_case'.
  $field_instances['node-os2web_base_contentpage-field_os2web_base_field_case'] = array(
    'bundle' => 'os2web_base_contentpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'os2web_esdh_field',
        'settings' => array(),
        'type' => 'os2web_esdh_field_case_ident_for',
        'weight' => 26,
      ),
      'includeable' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
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
    'field_name' => 'field_os2web_base_field_case',
    'label' => 'Sag',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'os2web_esdh_field',
      'settings' => array(),
      'type' => 'os2web_esdh_field_case_ident_wid',
      'weight' => 13,
    ),
  );

  // Exported field_instance:
  // 'node-os2web_base_contentpage-field_os2web_base_field_casesort'.
  $field_instances['node-os2web_base_contentpage-field_os2web_base_field_casesort'] = array(
    'bundle' => 'os2web_base_contentpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 28,
      ),
      'includeable' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
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
    'field_name' => 'field_os2web_base_field_casesort',
    'label' => 'Sortering',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'options',
      'settings' => array(
        'content_taxonomy_opt_groups' => FALSE,
        'use_select2' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 14,
    ),
  );

  // Exported field_instance:
  // 'node-os2web_base_contentpage-field_os2web_base_field_contact'.
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
        'weight' => 21,
      ),
      'includeable' => array(
        'label' => 'above',
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
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 16,
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
        'weight' => 16,
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
      'weight' => 14,
    ),
  );

  // Exported field_instance:
  // 'node-os2web_base_contentpage-field_os2web_base_field_doc'.
  $field_instances['node-os2web_base_contentpage-field_os2web_base_field_doc'] = array(
    'bundle' => 'os2web_base_contentpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'os2web_esdh_field',
        'settings' => array(),
        'type' => 'os2web_esdh_field_doc_ident_for',
        'weight' => 27,
      ),
      'includeable' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
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
    'field_name' => 'field_os2web_base_field_doc',
    'label' => 'Dokument',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'os2web_esdh_field',
      'settings' => array(),
      'type' => 'os2web_esdh_field_doc_ident_wid',
      'weight' => 15,
    ),
  );

  // Exported field_instance:
  // 'node-os2web_base_contentpage-field_os2web_base_field_edi_tags'.
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
        'weight' => 23,
      ),
      'includeable' => array(
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
      'search_result' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 18,
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
        'weight' => 18,
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

  // Exported field_instance:
  // 'node-os2web_base_contentpage-field_os2web_base_field_ext_link'.
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
        'weight' => 15,
      ),
      'includeable' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 15,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
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
    'field_name' => 'field_os2web_base_field_ext_link',
    'label' => 'Unikke eksterne links	',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
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
      'title_label_use_field_label' => FALSE,
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

  // Exported field_instance:
  // 'node-os2web_base_contentpage-field_os2web_base_field_hidlinks'.
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
        'weight' => 17,
      ),
      'includeable' => array(
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
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
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

  // Exported field_instance:
  // 'node-os2web_base_contentpage-field_os2web_base_field_image'.
  $field_instances['node-os2web_base_contentpage-field_os2web_base_field_image'] = array(
    'bundle' => 'os2web_base_contentpage',
    'deleted' => 0,
    'description' => '<p>Det er muligt at tilføje flere billeder. De vil vises i rotation. Hvis billedet ikke passer til formatet vil det blive beskåret automatisk. Det er muligt at ændre beskæringen efterfølgende.</p>',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
      'includeable' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
      'related_block' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
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
        'weight' => 6,
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
          'fredericia_content_image' => 'fredericia_content_image',
          'os2web_spotbox_image' => 0,
        ),
      ),
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '620x295',
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
        ),
        'allowed_types' => array(
          'audio' => 0,
          'document' => 0,
          'image' => 'image',
          'video' => 0,
        ),
        'browser_plugins' => array(
          'media_browser_plus--media_browser_my_files' => 'media_browser_plus--media_browser_my_files',
          'media_browser_plus--media_browser_thumbnails' => 'media_browser_plus--media_browser_thumbnails',
          'media_default--media_browser_1' => 0,
          'media_default--media_browser_my_files' => 0,
          'upload' => 'upload',
        ),
      ),
      'type' => 'media_generic',
      'weight' => -3,
    ),
  );

  // Exported field_instance:
  // 'node-os2web_base_contentpage-field_os2web_base_field_kle_ref'.
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
        'weight' => 22,
      ),
      'includeable' => array(
        'label' => 'above',
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
      'search_result' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 17,
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

  // Exported field_instance:
  // 'node-os2web_base_contentpage-field_os2web_base_field_loca_ref'.
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
        'weight' => 24,
      ),
      'includeable' => array(
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
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 19,
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

  // Exported field_instance:
  // 'node-os2web_base_contentpage-field_os2web_base_field_organiz'.
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
        'weight' => 25,
      ),
      'includeable' => array(
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
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 20,
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
        'weight' => 20,
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

  // Exported field_instance:
  // 'node-os2web_base_contentpage-field_os2web_base_field_politics'.
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
        'weight' => 18,
      ),
      'includeable' => array(
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
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 13,
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

  // Exported field_instance:
  // 'node-os2web_base_contentpage-field_os2web_base_field_promote'.
  $field_instances['node-os2web_base_contentpage-field_os2web_base_field_promote'] = array(
    'bundle' => 'os2web_base_contentpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'includeable' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
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
    'field_name' => 'field_os2web_base_field_promote',
    'label' => 'Forfrem til',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 16,
    ),
  );

  // Exported field_instance:
  // 'node-os2web_base_contentpage-field_os2web_base_field_related'.
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
        'weight' => 16,
      ),
      'includeable' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
      'search_result' => array(
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
        'weight' => 11,
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

  // Exported field_instance:
  // 'node-os2web_base_contentpage-field_os2web_base_field_selfserv'.
  $field_instances['node-os2web_base_contentpage-field_os2web_base_field_selfserv'] = array(
    'bundle' => 'os2web_base_contentpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<ul>
<li>Selvbetjeningsløsningerne skal være oprettet af en administrator før de kan indsættes.</li>
<li>Selvbetjeninger findes ved at bruge feltet til at søge på det interne kaldenavn</li>
</ul>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 19,
      ),
      'includeable' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'related_block' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
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

  // Exported field_instance:
  // 'node-os2web_base_contentpage-field_os2web_base_field_spotbox'.
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
        'weight' => 20,
      ),
      'includeable' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'related_block' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 15,
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

  // Exported field_instance:
  // 'node-os2web_base_contentpage-field_os2web_base_field_struct'.
  $field_instances['node-os2web_base_contentpage-field_os2web_base_field_struct'] = array(
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
      'includeable' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_os2web_base_field_struct',
    'label' => 'Portalkategori',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'content_taxonomy_opt_groups' => 0,
        'use_select2' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 15,
    ),
  );

  // Exported field_instance:
  // 'node-os2web_base_contentpage-field_os2web_base_field_summary'.
  $field_instances['node-os2web_base_contentpage-field_os2web_base_field_summary'] = array(
    'bundle' => 'os2web_base_contentpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Teksten vil stå fremhævet øverst på siden.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'includeable' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'related_block' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
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
    'field_name' => 'field_os2web_base_field_summary',
    'label' => 'Intro / Resume (maks 2 linier!)',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'blokindhold' => 'blokindhold',
          'email' => 'email',
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'blokindhold' => array(
              'weight' => -7,
            ),
            'email' => array(
              'weight' => 0,
            ),
            'filtered_html' => array(
              'weight' => -10,
            ),
            'full_html' => array(
              'weight' => -9,
            ),
            'plain_text' => array(
              'weight' => -8,
            ),
          ),
        ),
      ),
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

  // Exported field_instance:
  // 'node-os2web_base_contentpage-field_os2web_base_field_sympage'.
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
          'node_reference_view_mode' => 'includeable',
        ),
        'type' => 'node_reference_node',
        'weight' => 3,
      ),
      'includeable' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
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

  // Exported field_instance:
  // 'node-os2web_base_contentpage-field_os2web_base_field_video'.
  $field_instances['node-os2web_base_contentpage-field_os2web_base_field_video'] = array(
    'bundle' => 'os2web_base_contentpage',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'includeable' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
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
        'weight' => 7,
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
          'fredericia_content_image' => 0,
          'os2web_spotbox_image' => 0,
          'svendborg_spotbox' => 0,
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

  // Exported field_instance:
  // 'node-os2web_base_contentpage-field_os2web_base_field_webform'.
  $field_instances['node-os2web_base_contentpage-field_os2web_base_field_webform'] = array(
    'bundle' => 'os2web_base_contentpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(
          'node_reference_view_mode' => 'includeable',
        ),
        'type' => 'node_reference_node',
        'weight' => 2,
      ),
      'includeable' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
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

  // Exported field_instance:
  // 'node-os2web_base_contentpage-field_os2web_base_hide_contact'.
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
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 13,
      ),
      'includeable' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
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

  // Exported field_instance:
  // 'node-os2web_base_contentpage-field_os2web_base_hide_sidebar'.
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
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
      'includeable' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
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

  // Exported field_instance:
  // 'node-os2web_base_contentpage-field_os2web_paragraphs'.
  $field_instances['node-os2web_base_contentpage-field_os2web_paragraphs'] = array(
    'bundle' => 'os2web_base_contentpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'includeable' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
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
        'weight' => 2,
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

  // Exported field_instance: 'node-os2web_base_contentpage-field_piwik_stats'.
  $field_instances['node-os2web_base_contentpage-field_piwik_stats'] = array(
    'bundle' => 'os2web_base_contentpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
      'includeable' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
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
    'field_name' => 'field_piwik_stats',
    'label' => 'Piwik Stats Dag',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'piwik_stats',
      'settings' => array(),
      'type' => 'piwik_stats_hidden',
      'weight' => 51,
    ),
  );

  // Exported field_instance:
  // 'node-os2web_base_contentpage-field_piwik_stats_aar'.
  $field_instances['node-os2web_base_contentpage-field_piwik_stats_aar'] = array(
    'bundle' => 'os2web_base_contentpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'includeable' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
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
    'field_name' => 'field_piwik_stats_aar',
    'label' => 'Piwik Stats År',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'piwik_stats',
      'settings' => array(),
      'type' => 'piwik_stats_hidden',
      'weight' => 52,
    ),
  );

  // Exported field_instance:
  // 'node-os2web_base_contentpage-field_piwik_stats_maaned'.
  $field_instances['node-os2web_base_contentpage-field_piwik_stats_maaned'] = array(
    'bundle' => 'os2web_base_contentpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'includeable' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
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
    'field_name' => 'field_piwik_stats_maaned',
    'label' => 'Piwik Stats Måned',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'piwik_stats',
      'settings' => array(),
      'type' => 'piwik_stats_hidden',
      'weight' => 50,
    ),
  );

  // Exported field_instance:
  // 'node-os2web_base_contentpage-field_piwik_stats_uge'.
  $field_instances['node-os2web_base_contentpage-field_piwik_stats_uge'] = array(
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
      'includeable' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
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
    'field_name' => 'field_piwik_stats_uge',
    'label' => 'Piwik Stats Uge',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'piwik_stats',
      'settings' => array(),
      'type' => 'piwik_stats_hidden',
      'weight' => 53,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('<p>Det er muligt at tilføje flere billeder. De vil vises i rotation. Hvis billedet ikke passer til formatet vil det blive beskåret automatisk. Det er muligt at ændre beskæringen efterfølgende.</p>');
  t('<ul>
<li>Selvbetjeningsløsningerne skal være oprettet af en administrator før de kan indsættes.</li>
<li>Selvbetjeninger findes ved at bruge feltet til at søge på det interne kaldenavn</li>
</ul>');
  t('<ul><li>Skriv en god og fyldestgørende tekst. Tænk på at der er forskellige typer læsere til teksten, og at ikke alle har den fornødne viden til at fortolke svære ord.</li>
<li>Husk at tilføje relaterede interne og eksterne links under fanen Relationer. Det giver de besøgende en bedre oplevelse af et helstøbt website.</li>
</ul>');
  t('Afsnit');
  t('Billede');
  t('Dokument');
  t('Egennavne/stednavne');
  t('Forfrem til');
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
  t('Piwik Stats Dag');
  t('Piwik Stats Måned');
  t('Piwik Stats Uge');
  t('Piwik Stats År');
  t('Politik');
  t('Portalkategori');
  t('Sag');
  t('Selvbetjening');
  t('Skjul automatisk relaterede links');
  t('Skjul højre kontaktblok');
  t('Skjul højre sidebar');
  t('Sortering');
  t('Spotboxe');
  t('Stikord');
  t('Teksten vil stå fremhævet øverst på siden.');
  t('Unikke eksterne links	');
  t('Unikke relaterede links');
  t('Video');
  t('Webform');

  return $field_instances;
}
