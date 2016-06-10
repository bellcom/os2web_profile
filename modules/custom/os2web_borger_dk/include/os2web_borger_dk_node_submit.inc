<?php
/**
 * @file borger.dk node submit.
 */

// Update article Now.
/**
 * Function os2web_borger_dk_sync_submit().
 */
function os2web_borger_dk_sync_submit($form, &$form_state) {
  // Get the node->nid from the form['#node'].
  $nid = $form['#node']->nid;

  // Update the article
  os2web_borger_dk_update_article($nid);

  drupal_set_message(t('The article has been updated with content from Borger.dk'), 'status');
  drupal_goto('node/' . $nid . '/edit');
}

// Update microarticle Now.
/**
 * Function os2web_borger_dk_microarticles_update_submit().
 */
function os2web_borger_dk_microarticles_update_submit($form, &$form_state) {
  // Get the node->nid from the form['#node'].
  $nid = $form['#node']->nid;

  // First we find the external_id, and last_update time for this article.
  $data = db_query('SELECT external_id, last_updated FROM {os2web_borger_dk_article} WHERE nid = :nid', array(
    ':nid' => $nid))->fetchObject();

  // Then we fetch the article item from the Borger.dk webservice.
  $article = _os2web_borger_dk_GetArticleByID($data->external_id);

  if (empty($article['Exceptions']) && empty($article['error'])) {
    // First we load the corresponding node.
    $node = node_load($nid, NULL, TRUE);
    $body = '';
    foreach ($article['kernetekst'] as $div => $content) {
      $body .= $content . "\n";
    }
    // Only update the body text.
    $node->body[LANGUAGE_NONE][0]['value'] = $body;
    node_save($node);

    // Update microarticle field setting.
     _os2web_borger_dk_microarticle_helper($body, $node, FALSE);

    // And we notify the user that the article has been updated.
    drupal_set_message(t('The microarticles have been updated'), 'status');
  }
  else {
    // We notify the user the exceptions or error.
    drupal_set_message(t('There was an error updating microarticles. Please try it later.'), 'status');
  }
  drupal_goto('node/' . $nid . '/edit');
}


/**
 * Implements hook_node_submit().
 */
function os2web_borger_dk_node_submit(&$node, $form, &$form_state) {
  if ($node->type == 'os2web_borger_dk_article') {
    // We must check if this is a "brand new" article or if it exists in the
    // database already (NB: That's how we find out if it is brand new or not)
    // Get the node->nid from the form['#node'].
    $nid = (!empty($form_state['values']['nid'])) ? $form_state['values']['nid'] : NULL;
    if (!empty($nid)) {
      // We have a node and should fetch field-values from form_state
      // nid, external_id, external_url, field_settings,
      // published_date, last_update.
      // EXCEPT: ONLY field_settings CAN BE UPDATED!!
      $field_settings = $form_state['values']['os2web_borger_dk_field_settings'];
      // Check admin field settings : are there fields set as hidden by admin.
      $admin_display_fields = variable_get('os2web_borger_dk_display');
      foreach ($admin_display_fields as $type => $items) {
        if (!$admin_display_fields[$type]) {
          $field_settings[$type] = $type;
        }
      }

      $serialized_data = serialize($field_settings);
      db_update('os2web_borger_dk_article')
          ->fields(array('field_settings' => $serialized_data))
          ->condition('nid', $nid, '=')
          ->execute();

      // Microarticles.---
      $microarticle = variable_get('os2web_borger_dk_microarticle_active');
      // If microarticle is set up to show.
      if ($microarticle) {
        $field_microarticle_settings = array();
        $body_text = isset($node->body[LANGUAGE_NONE][0]['value']) ? $node->body[LANGUAGE_NONE][0]['value'] : '';

        $article_text = _os2web_borger_dk_microarticle_helper($body_text, $node, FALSE);

        $node->body[LANGUAGE_NONE][0]['value'] = $article_text;
        $node->body[LANGUAGE_NONE][0]['safe_value'] = $article_text;

      }
      // End of Micro articles.
      // All other fields are handled by the normal Drupal field-handling.
    }
    else {
      // We do not(!) have a node->nid and this is a brand new node.
      // We must get the Borger.dk-URL, fetch the article, and store
      // the borger.dk-article content (i.e. the new node).

      $titles_autocomplete = variable_get('borger_dk_article_titles_sync', FALSE);
      $borger_dk_url = $form_state['values']['os2web_borger_dk_article_url_text'];
      $borger_dk_title = $form_state['values']['os2web_borger_dk_article_title_text'];
      $search_method = $form_state['values']['os2web_borger_dk_article_title_search'];

      if ($search_method) {
        // The title has been autocompleted, and we must find the ArticleID.
        $matches = array();
        $aid = -1;
        // This preg_match() looks for the last pattern like [33334]
        // and if found extracts the numeric portion.
        $result = preg_match('/\(ID:([0-9]+)\)$/', $borger_dk_title, $matches);
        if ($result > 0) {
          // If $result is nonzero, we found a match and can use
          // it as the index into $matches.
          $aid = $matches[$result];
          $sql = "SELECT `ArticleID`, `ArticleStatus` FROM {os2web_borger_dk_article_titles} WHERE `ArticleID` = " . $aid . " LIMIT 1";
          $data = db_query($sql)->fetchObject();
          if ($data->ArticleStatus < 0) {
            // This article is no longer availlable and we tell the user so.
            drupal_set_message(t('The Borger.dk article with title "!title" is no longer availlable', array(
              '!title' => $borger_dk_title)), 'warning');
            drupal_goto('node/add/os2web-borger-dk-article');
            return;
          }
          elseif ($data->ArticleStatus > 0) {
            $allow_duplicate_import = variable_get('os2web_borger_dk_import_duplicate', 0);
            if (!$allow_duplicate_import) {
              // We have already imported this article
              // and node->nid = ArticleStatus.
              drupal_set_message(t('The Borger.dk article with title "!title" has already been imported.', array(
                '!title' => $borger_dk_title)), 'status');
              drupal_set_message(t('You can re-import the article by clicking on the "Update now"-button below.'), 'status');
              drupal_goto('node/' . $data->ArticleStatus . '/edit');
              return;
            }
          }
          elseif ($data->ArticleStatus == 0) {
            $aid = $data->ArticleID;
          }
        }
        else {
          // Lets look for the text directly in our Title list.
          drupal_set_message(t('No Borger.dk article with title "!title" exists.', array(
            '!title' => $borger_dk_title)), 'warning');
          drupal_goto('node/add/os2web-borger-dk-article');
        }
        if (isset($aid) && $aid >= 0) {
          // We have not imported this article before, and we do so now.
          $article = _os2web_borger_dk_GetArticleByID($aid);
        }
        else {
          $borger_dk_title = preg_replace('/ \(ID:([0-9]+)\)$/', '', $borger_dk_title);
          drupal_set_message(t('Could not find any Borger.dk article with title "!title"', array(
            '!title' => $borger_dk_title)), 'warning');
          drupal_goto('node/add/os2web-borger-dk-article');
          return;
        }
      }
      else {
        // Now we fetch the article item from the Borger.dk webservice.
        $article = _os2web_borger_dk_GetArticleByUrl($borger_dk_url);
        if (!empty($article['Exceptions']) || !empty($article['error'])) {
          drupal_set_message(t('An error occured or an exception was thrown by the Borger.dk webservice for the specified URL.'), 'error');
          drupal_set_message(t('You can fetch this article when the webservice is responsive again.'), 'error');
          drupal_goto('node/add/os2web-borger-dk-article');
          return;
        }
      }
      $node = _os2web_borger_dk_create_article_node($nid, $article, NULL);
    }
  }
}
function _os2web_borger_dk_add_node_menu($node, $existing_parent = array()) {
  $menu_name = variable_get('build_borger_menu_under_menu');
  $node->menu = array(
    'link_title' => $node->title,
    'menu_name' => $menu_name,
    'description' => '',
    'plid' => $existing_parent['mlid'],
    'enabled' => 1,
  );
  menu_node_save($node);
  return $node;
}
