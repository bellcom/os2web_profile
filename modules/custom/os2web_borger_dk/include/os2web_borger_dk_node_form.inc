<?php
/**
 * @file Borger.dk node form.
 */

/**
 * Function _os2web_borger_dk_autocomplete_callback().
 */
function _os2web_borger_dk_autocomplete_callback($string = '') {
  $matches = array();

  if ($string) {

    $query = db_select('os2web_borger_dk_article_titles', 'o')
      ->fields('o', array('ArticleID', 'ArticleStatus', 'ArticleTitle'))
      ->condition('o.ArticleStatus', 0, '>=')
      ->condition('o.ArticleTitle', db_like($string) . '%', 'LIKE')
      ->range(0, 10);
    $result = $query->execute();

    // Add matches to $matches.
    foreach ($result as $row) {
      if ($row->ArticleStatus > 0) {
        $row_name = $row->ArticleTitle . ' [*](ID:' . $row->ArticleID . ')';
      }
      else {
        $row_name = $row->ArticleTitle . ' (ID:' . $row->ArticleID . ')';
      }
      $matches[$row_name] = check_plain($row_name);
    }
  }
  drupal_json_output($matches);
}

/**
 * Implements hook_form_alter().
 */
function os2web_borger_dk_form_alter(&$form, &$form_state, $form_id) {
  static $os2web_borger_dk_falter_form;
  if (isset($form['type']) && isset($form['#node'])) {
    if ($form_id == 'os2web_borger_dk_article_node_form') {

      if (isset($os2web_borger_dk_falter_form) && !empty($os2web_borger_dk_falter_form)) {
        // If the static form-cache has already been build then
        // we simply return the form-cache value instead of
        // building the whole form twice per request.
        $form = $os2web_borger_dk_falter_form;
      }
      else {
        $node = $form_state['node'];
        $titles_autocomplete = variable_get('os2web_borger_dk_titles_sync', FALSE);
        if (!isset($node->nid) || isset($node->is_new)) {
          os2web_borger_dk_autocomplete_form($form, $form_state);
        }

        $locked_os2web_types = array(
          'field_os2web_borger_dk_borgerurl' => 1,
          'field_os2web_borger_dk_formterm' => 2,
        );
        $admin_display_fields = variable_get('os2web_borger_dk_display');

        $data = field_info_instances('node', 'os2web_borger_dk_article');
        // First we create a list of all field-names and labels.
        $checkbox_opts = array();
        $initial_values = array();

        $data['title'] = array('label' => 'Title');
        $visible_items = (isset($form['#node']->os2web_borger_dk_article['field_settings'])) ? $form['#node']->os2web_borger_dk_article['field_settings'] : NULL;
        $admin_last_settings = variable_get('os2web_borger_dk_admin_last_settings');

        foreach ($data as $type => $item) {
          if ((isset($locked_os2web_types[$type]) && $locked_os2web_types[$type] != 2)
          ||!isset($locked_os2web_types[$type])) {
            // Then we insert field label to our checkboxes options.
            $checkbox_opts[$type] = $item['label'];
            // admin-config says we should show this item as an option.
            if (isset($admin_display_fields[$type])) {
              if (empty($visible_items) || (!empty($visible_items) && !empty($visible_items[$type]))) {
                // If visible_items is empty that means we should use
                // admin-config or if the type of visible_items is set,
                // and set to be displayed then we add this type
                // to the default_values.
                $initial_values[] = $type;
              }
              else {
                if ($admin_last_settings[$type] != $admin_display_fields[$type]
                    && $visible_items[$type] == $admin_last_settings[$type]) {
                  $initial_values[] = $type;
                }
                else {
                  if ($admin_last_settings[$type] != $admin_display_fields[$type]
                      && $visible_items[$type] == $admin_last_settings[$type]) {
                    $initial_values[] = $type;
                  }
                }
              }
            }
          }
        }
        variable_set('os2web_borger_dk_admin_last_settings', $admin_display_fields);

        // This is the field fieldset.
        $form['fields_visible_formset'] = array(
          '#type' => 'fieldset',
          '#title' => t('Toggle display'),
          '#collapsible' => TRUE,
          '#description' => t('Set the visibility of article fields.'),
          '#group' => 'additional_settings',
        );
        $form['fields_visible_formset']['os2web_borger_dk_field_settings'] = array(
          '#type' => 'checkboxes',
          '#options' => $checkbox_opts,
          '#description' => t("Check or uncheck the respective fields"),
          '#default_value' => $initial_values,
          '#after_build' => array('os2web_borger_dk_process_checkboxes_os2web_borger_dk_article'),
          '#group' => 'additional_settings',
        );

        if (isset($form['#node']->nid)) {
          $form['actions']['os2web_borger_dk_synchronize'] = array(
            '#type' => 'submit',
            '#value' => t("Update article now"),
            '#weight' => 100,
            '#access' => variable_get('node_preview_' . $node->type, DRUPAL_OPTIONAL) != DRUPAL_REQUIRED || (!form_get_errors() && isset($form_state['node_preview'])),
            '#submit' => array('os2web_borger_dk_sync_submit'),
          );
        }
        $form['#after_build'][] = 'os2web_borger_dk_after_build';

        // Micro articles.
        if (isset($form['#node']->nid)) {
          $microarticle = variable_get('os2web_borger_dk_microarticle_active');
          $value_editable = variable_get('os2web_borger_dk_editable', array(NULL));
          // If microarticle is set up to show.
          if ($microarticle) {
            $field_microarticle_settings = (isset($form['#node']->os2web_borger_dk_microarticle['field_microarticle_settings'])) ? $form['#node']->os2web_borger_dk_microarticle['field_microarticle_settings'] : NULL;
            $body_text = (isset($form['body'][LANGUAGE_NONE]['0']['#entity']->body[LANGUAGE_NONE]['0']['value'])) ? $form['body'][LANGUAGE_NONE]['0']['#entity']->body[LANGUAGE_NONE]['0']['value'] : '';

            $form['body']['#access'] = FALSE;
            $doc = new DOMDocument();
            $doc->loadHTML('<?xml encoding="utf-8" ?>' . $body_text);
            $xpath = new DOMXPath($doc);
            $results = $xpath->query("//*[@class='microArticle']");

            $microno = 0;
            foreach ($results as $item) {
              foreach ($item->getElementsByTagName('h2') as $articletitle) {
                $title = trim($articletitle->nodeValue);
              }

              $text = '';
              foreach ($item->getElementsByTagName('div')->item(0)->childNodes as $articletext) {
                $text .= str_replace('&#13;', '', $doc->saveXML($articletext, LIBXML_NOEMPTYTAG));
              }

              $microno++;
              $checkboxno = 'os2web_borger_dk_micro_' . $microno;
              $h2_text_field = 'os2web_borger_dk_micro_h2_' . $microno;
              $text_area = 'os2web_borger_dk_micro_textarea_' . $microno;

              if ($microno >= 10) {
                $weight = '6.' . ($microno - 10);
              }
              else {
                $weight = '5.' . $microno;
              }
              // For each microarticle we build a fieldset, a textfield for
              // title, a textarea for div content and a checkbox for
              // visibility option.
              $form['os2web_borger_dk_micro_settings_' . $microno] = array(
                '#type' => 'fieldset',
                '#weight' => $weight,
              );
              $form['#group_children']['os2web_borger_dk_micro_settings_' . $microno] = 'group_os2web_borger_dk_text';
              $form['os2web_borger_dk_micro_settings_' . $microno][$h2_text_field] = array(
                '#type' => 'textfield',
                '#title' => t('Title of Microarticle') . ' ' . $microno,
                '#default_value' => variable_get($h2_text_field, $title),
              );
              // If body (article text) visible/editable option is checked
              // by ADMIN and EDITOR, then forms disabled is false.
              if ($visible_items['body'] === "body" && $admin_display_fields['body'] === "body" && $value_editable['body'] === "body") {
                $form['os2web_borger_dk_micro_settings_' . $microno][$text_area] = array(
                  // '#title' => t('Microarticle ' . $microno),
                  '#type' => 'textarea',
                  '#default_value' => trim($text),
                );

                $form['os2web_borger_dk_micro_settings_' . $microno][$checkboxno] = array(
                  '#type' => 'checkbox',
                  '#title' => t('Visible'),
                  '#description' => t("Check to display this microarticle"),
                  '#default_value' => isset($field_microarticle_settings[$microno]) ? $field_microarticle_settings[$microno] : 1,
                );
              }
              // If body (article text) display option is UNCHECKED
              // by ADMIN or EDITOR, then forms disabled is TRUE.
              else {
                $form['os2web_borger_dk_micro_settings_' . $microno][$text_area] = array(
                  '#title' => t('Microarticle') . ' ' . $microno,
                  '#type' => 'textarea',
                  '#disabled' => TRUE,
                  '#default_value' => trim($text),
                  '#description' => t("Please check 'Article text' visible option below in 'Toggle display', or in OS2web borger.dk Settings (Toggle display/Editable article fields) to show/edit this microarticle."),
                );
                // If this microarticle is NOT editable.
                if ($value_editable['body'] !== "body") {
                  $form['os2web_borger_dk_micro_settings_' . $microno][$checkboxno] = array(
                    '#type' => 'checkbox',
                    '#title' => t('Microarticle Visibility'),
                    '#description' => t("Check to display this microarticle"),
                    '#default_value' => isset($field_microarticle_settings[$microno]) ? $field_microarticle_settings[$microno] : 1,
                  );
                }
                else {
                  $form['os2web_borger_dk_micro_settings_' . $microno][$checkboxno] = array(
                    '#type' => 'checkbox',
                    '#title' => t('Microarticle Visibility'),
                    '#disabled' => TRUE,
                    '#description' => t("Check to display this microarticle"),
                    '#default_value' => isset($field_microarticle_settings[$microno]) ? $field_microarticle_settings[$microno] : 1,
                  );
                }
              }
            }
          }
        }

        if (isset($form['#node']->nid) && ($microarticle)) {
          $form['actions']['os2web_borger_dk_microarticles_update'] = array(
            '#type' => 'submit',
            '#value' => t("Update microarticle content"),
            '#weight' => 101,
            '#access' => variable_get('node_preview_' . $node->type, DRUPAL_OPTIONAL) != DRUPAL_REQUIRED || (!form_get_errors() && isset($form_state['node_preview'])),
            '#submit' => array('os2web_borger_dk_microarticles_update_submit'),
          );
        }
        // End of microarticles.
        // Before we exit this function we set the static form-cache value
        // so that later calls to this function handling the same request
        // can return much faster (instead of building the same form twice).
        $os2web_borger_dk_falter_form = $form;

      }
    }
  }
}

/**
 * Function os2web_borger_dk_autocomplete_form().
 */
function os2web_borger_dk_autocomplete_form(&$form, $form_state) {
  $titles_autocomplete = variable_get('os2web_borger_dk_titles_sync', FALSE);
  $title_search_state = (isset($form_state['values']['os2web_borger_dk_article_search_method'])) ? TRUE : FALSE;
  $url_search = !$title_search_state;

  $form['os2web_borger_dk_article_import'] = array(
    '#type' => 'fieldset',
    '#title' => t('Import Borger.dk Article'),
    '#collapsible' => FALSE,
  );

  $form['os2web_borger_dk_article_import']['os2web_borger_dk_article_url_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Borger.dk Article URL'),
    '#default_value' => (isset($form_state['values']['os2web_borger_dk_article_url_text'])) ? $form_state['values']['os2web_borger_dk_article_url_text'] : '',
    '#size' => 60,
    '#maxlength' => 255,
  );
  $import_english = variable_get('os2web_borger_dk_import_english', 0);
  if ($titles_autocomplete && !$import_english) {
    $form['os2web_borger_dk_article_import']['os2web_borger_dk_article_title_text'] = array(
      '#type' => 'textfield',
      '#title' => t('Borger.dk Article title'),
      '#default_value' => (isset($form_state['values']['os2web_borger_dk_article_title_text'])) ? $form_state['values']['os2web_borger_dk_article_title_text'] : '',
      '#autocomplete_path' => 'import/os2web_borger_dk/autocomplete',
      '#size' => 60,
      '#maxlength' => 255,
      '#attributes' => array('class' => array('auto_submit')),
    );

    $form['os2web_borger_dk_article_import']['os2web_borger_dk_article_title_search'] = array(
      '#type' => 'checkbox',
      '#title' => t('Search for Borger.dk Article by Title-search'),
      '#description' => t('If checked Borger.dk articles are found by title (by URL if un-checked).'),
      '#default_value' => ($url_search) ? 1 : 0,
      '#after_build' => array('_os2web_borger_dk_autocomplete_form_load_js'),
    );
  }
}

/**
 * Function _os2web_borger_dk_autocomplete_form_load_js().
 */
function _os2web_borger_dk_autocomplete_form_load_js($element) {
  $autosubmit_js = '
    $(document).ready(function(){
      Drupal.jsAC.prototype.select = function (node) {
        this.input.value = $(node).data("autocompleteValue");
        if(jQuery(this.input).hasClass("auto_submit")){
          this.input.form.submit();
        }
      };
    });';
  $must_auto_submit = variable_get('os2web_borger_dk_titles_search_auto_submit', FALSE);
  if (!$must_auto_submit) {
    $autosubmit_js = '';
  }
  $js = '(function ($) {
    Drupal.behaviors.switchfield = {
      attach: function(context, settings) {
        var checked1 = $("#edit-os2web-borger-dk-article-title-search").attr("checked");
        if (checked1) {
          $(".form-item-os2web-borger-dk-article-url-text").hide();
          $(".form-item-os2web-borger-dk-article-title-text").show();
        }
        else {
          $(".form-item-os2web-borger-dk-article-url-text").show();
          $(".form-item-os2web-borger-dk-article-title-text").hide();
        }

        $("#edit-os2web-borger-dk-article-title-search").click(function() {
          var checked = $(this).attr("checked");
          if (checked) {
            $(".form-item-os2web-borger-dk-article-url-text").hide(500);
            $(".form-item-os2web-borger-dk-article-title-text").show(500);
          }
          else {
            $(".form-item-os2web-borger-dk-article-url-text").show(500);
            $(".form-item-os2web-borger-dk-article-title-text").hide(500);
          }
        });' . $autosubmit_js . '
      }
    }
  })(jQuery);';
  drupal_add_js($js, 'inline');

  return $element;
}

/**
 * Function os2web_borger_dk_after_build().
 */
function os2web_borger_dk_after_build($form, &$form_state) {
  // Some of the fields are handled exclusively by OS2web.
  // These fields are required on node-add, and can NOT be
  // changed later on (ie. locked).
  $locked_os2web_types = array(
    'field_os2web_borger_dk_borgerurl' => 1,
    'field_os2web_borger_dk_kle' => 2,
    'field_os2web_borger_dk_formterm' => 2,
  );
  $nid = $form_state['values']['nid'];
  $admin_display_fields = variable_get('os2web_borger_dk_display', array(NULL));
  $microarticle = variable_get('os2web_borger_dk_microarticle_active');
  $admin_required_fields = variable_get('os2web_borger_dk_field_required', array(NULL));

  // First we check if this is a node/add-type by checking the node->nid.
  if (!empty($nid)) {
    // This is an old node that is being edited.
    // We must unset all form-elements that has been
    // marked as hidden in the admin-display-settings.
    foreach ($admin_display_fields as $type => $item) {
      if (empty($item) && empty($locked_os2web_types[$type])) {
        if (!$microarticle) {
          os2web_borger_dk_fix_disabled($form[$type]);
        }
      }
    }
    foreach ($admin_required_fields as $type => $item) {
      if ($item) {
        $form[$type]['#required'] = TRUE;
        $form[$type][LANGUAGE_NONE]['#required'] = TRUE;
        $form[$type][LANGUAGE_NONE][0]['#required'] = TRUE;
        $form[$type][LANGUAGE_NONE][0]['value']['#required'] = TRUE;
      }
    }
    // Then we must disable all fields that has been marked as
    // non-editable in the admin-editable-settings.
    $value_editable = variable_get('os2web_borger_dk_editable', array(NULL));
    foreach ($value_editable as $type => $editable) {
      if ((empty($editable) || !empty($locked_os2web_types[$type])) && !empty($form[$type])) {
        if (!$microarticle) {
          os2web_borger_dk_fix_disabled($form[$type]);
        }
      }
      if ($type == 'field_os2web_byline' && !empty($form[$type])) {
        $form[$type]['#format'] = BORGERDK_TEXT_FORMAT_PLAIN;
      }
    }

    // Finally we lock the special types.
    foreach ($locked_os2web_types as $type => $locked) {
      // If locked = 1 then disable the field.
      if (isset($form[$type]) && $locked == 1) {
        $form[$type]['#required'] = FALSE;
        $form[$type][LANGUAGE_NONE]['#required'] = FALSE;
        $form[$type][LANGUAGE_NONE][0]['#required'] = FALSE;
        $form[$type][LANGUAGE_NONE][0]['value']['#required'] = FALSE;
        os2web_borger_dk_fix_disabled($form[$type]);
      }
    }
  }
  else {
    // This is a brand new node-add form, and we must hide every
    // form-field.
    $data = field_info_instances('node', 'os2web_borger_dk_article');
    foreach ($data as $type => $item) {
      // Some fields must be checked before unsetting or php will
      // die because a string for instance can not be unset.
      if (!isset($locked_os2web_types[$type]) || $locked_os2web_types[$type] == 1) {
        // These fields can safely be unset (so they are hidden).
        hide($form[$type]);
      }
      if (isset($locked_os2web_types[$type]) && $locked_os2web_types[$type] == 2) {

        hide($form[$type][LANGUAGE_NONE]);
      }
    }
    $form['field_os2web_borger_dk_borgerurl']['#required'] = FALSE;
    $form['field_os2web_borger_dk_borgerurl'][LANGUAGE_NONE]['#required'] = FALSE;
    $form['field_os2web_borger_dk_borgerurl'][LANGUAGE_NONE][0]['#required'] = FALSE;
    $form['field_os2web_borger_dk_borgerurl'][LANGUAGE_NONE][0]['value']['#required'] = FALSE;
    $form['title']['#required'] = FALSE;
    $form['title']['#access'] = FALSE;

    if (isset($form['path']['pathauto']['#default_value'])) {
      $form['path']['pathauto']['#checked'] = FALSE;
    }
    $form['status'] = 0;
    $form['promote'] = 0;
  }

  return $form;
}

/**
 * Function os2web_borger_dk_process_checkboxes_os2web_borger_dk_article().
 */
function os2web_borger_dk_process_checkboxes_os2web_borger_dk_article(&$element) {

  $admin_display_fields = variable_get('os2web_borger_dk_display', array(NULL));
  if (!empty($element)) {
    foreach (element_children($element) as $key) {
      if (!isset($admin_display_fields[$key]) || $admin_display_fields[$key] == '0') {
        $element[$key]['#attributes'] = array('disabled' => 'disabled');
        $element[$key]['#description'] = t('Please go to OS2web Borger.dk settings to change the visibility for this field');
      }
    }
  }
  return $element;
}

/**
 * Function os2web_borger_dk_fix_disabled().
 */
function os2web_borger_dk_fix_disabled(&$elements) {
  foreach (element_children($elements) as $key) {
    if (isset($elements[$key]) && $elements[$key]) {
      // Recurse through all child elements.
      os2web_borger_dk_fix_disabled($elements[$key]);
    }
  }
  if (!isset($elements['#attributes'])) {
    $elements['#attributes'] = array();
  }
  $elements['#attributes']['disabled'] = 'disabled';
}
