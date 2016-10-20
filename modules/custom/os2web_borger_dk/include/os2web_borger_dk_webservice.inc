<?php

/**
 * @file include borger.dk webservice functions.
 */

/*
 * Function: Create Soap client.
 *
 * @param $webservice  the name of borger.dk webservice function.
 *        $service_parameters  the parameters to the webservice.
 */
function _os2web_borger_dk_create_soap_client($webservice = 'GetAllSites', $service_parameters = NULL) {
  $wsdl = variable_get('os2web_borger_dk_webservice', 'https://www.borger.dk/_vti_bin/borger/ArticleExport.svc?wsdl');
  if (isset($service_parameters['url'])) {
    $la = os2web_borger_dk_check_import_article_language_byURL($service_parameters['url']);

    if ($la == 'en') {
      $wsdl = variable_get('os2web_borger_dk_english_webservice', 'https://lifeindenmark.borger.dk/_vti_bin/borger/ArticleExport.svc?wsdl');
    }
  }
  if (isset($service_parameters['language']) && $service_parameters['language'] == 'en') {
    $wsdl = variable_get('os2web_borger_dk_english_webservice', 'https://lifeindenmark.borger.dk/_vti_bin/borger/ArticleExport.svc?wsdl');
  }

  // We use a soap-client to fetch the specified article from Borger.dk.
  $client = new SoapClient($wsdl, array('exceptions' => 0));
  $result_article = $client->$webservice($service_parameters);
  $result_error = array();

  if (is_soap_fault($result_article)) {
    // An error was encountered and we examine it more closely.
    $error = _os2web_borger_dk_translate_soap_fault(2, $result_article->faultcode, $result_article->faultstring);
    return $result_error['error'] = $error;
  }

  return $result_article;
}
/**
 * Funtion : Get articleIds from each pages/site.
 */
function _os2web_borger_dk_GetArticleIDsBySiteID($site_id, $use_constraints = TRUE) {
  $error = array();
  // The ID of the Borger.dk-site to get must be given as argument.
  if (empty($site_id)) {
    return $error;
  }
  $ids = array();

  // Then we execute our webservice-request.
  $array_get_article_ids = array('siteID' => $site_id);

  $result_article = _os2web_borger_dk_create_soap_client('GetArticleIDsBySiteID', $array_get_article_ids);

  if (is_array($result_article) && isset($result_article['error'])) {

    return $result_article;
  }
  else {
    $article_ids = $result_article->GetArticleIDsBySiteIDResult;
    if (isset($article_ids->ArticleShortDescription)) {
      if (is_array($article_ids->ArticleShortDescription)) {
        foreach ($article_ids->ArticleShortDescription as $article_id) {
          $ids[] = $article_id->ArticleID;
        }
      }
      else {
        $ids[] = $article_ids->ArticleShortDescription->ArticleID;
      }
    }
  }
  return $ids;
}

/**
 * Function _os2web_borger_dk_GetAllArticles().
 */
function _os2web_borger_dk_GetAllArticles($la = 'da') {
  // This function uses the Borger.dk Webservice
  // GetAllArticles in order to fetch a list of
  // availlable articles (by title).
  $errors = array();

  _os2web_borger_dk_check_webservice_constraints();
  $result_list = _os2web_borger_dk_create_soap_client('GetAllArticles',array('language' => $la));

  if (is_array($result_article) && isset($result_article['error'])) {
    return $result_article;
  }

  $article_items = array();
  // Then we get the result-list from the specified webservice.
  $article_list = $result_list->GetAllArticlesResult;
  if (is_soap_fault($article_list)) {
    $errors = _os2web_borger_dk_translate_soap_fault('GetAllArticlesResult', $article_list->faultcode, $article_list->faultstring);

    return $errors;
  }
  else {
    // Now we step through all the fetched articles and convert them to arrays
    // of wanted field-sets.
    // NB!!: The webservice places ONE found article directly in the response.
    // But TWO found articles are placed in an array.
    if (is_array($article_list->ArticleDescription)) {
      foreach ($article_list->ArticleDescription as $id => $article) {
        $new_item = _os2web_borger_dk_parse_borgerdk_article_desc($article);
        $article_items[] = $new_item;
      }
    }
    else {
      foreach ($article_list as $id => $article) {
        $new_item = _os2web_borger_dk_parse_borgerdk_article_desc($article);
        $article_items[] = $new_item;
      }
    }
  }

  return $article_items;
}

/**
 * Function _os2web_borger_dk_GetArticlesByIDs().
 */
function _os2web_borger_dk_GetArticlesByIDs($borgerdk_ids = NULL, $updated_after = NULL, $la = 'da') {
  // This function uses the Borger.dk WebService GetArticlesByIDs
  // in order to fetch a list of Borger.dk-articles by article-IDs
  // and an "updateAfter"-datestamp.
  // We must have an array of items to fetch either specified by a list of
  // articleIDs or specified by an updatedAfter timestamp.
  if (empty($borgerdk_ids) && empty($updated_after)) {
    return array();
  }

  $errors = array();
  // Then we can start using a new soap-client to find
  // the article-ID from the Borger.dk-URL.

  // First we make sure to keep requests/minute within given limits.
   _os2web_borger_dk_check_webservice_constraints();
  if (empty($updated_after) && !empty($borgerdk_ids)) {
    // We have a specified list of articles to fetch.
    // Then we execute our webservice-request.
    $result_list = _os2web_borger_dk_create_soap_client('GetArticlesByIDs', array('articleIDs' => $borgerdk_ids, 'language' => $la));

  }
  elseif (!empty($updated_after) && empty($borgerdk_ids)) {

    // We have a specified date, and want all articles that have been
    // updated since the given date.
    $result_list = _os2web_borger_dk_create_soap_client('GetArticlesByIDs', array('updatedAfter' => $updated_after));
  }
  elseif (!empty($updated_after) && !empty($borgerdk_ids)) {

    // We have a specified date, and a specified list of article-IDs. We
    // want all articles from that list that has also been updated since
    // the given date.
    $parameters = array(
      'articleIDs' => $borgerdk_ids,
      'updatedAfter' => $updated_after,
      'language' => $la,
    );
    $result_list = _os2web_borger_dk_create_soap_client('GetArticlesByIDs', $parameters);

  }

  // Return error if there is.
  if (is_array($result_list) && isset($result_list['error'])) {

    return $result_list;
  }

  // Continue to fetch article.
  $article_items = array();
  // Then we get the result-list from the specified webservice.
  $article_list = $result_list->GetArticlesByIDsResult;
  if (is_soap_fault($article_list)) {
    $errors = _os2web_borger_dk_translate_soap_fault('GetArticlesByIDsResult', $article_list->faultcode, $article_list->faultstring);

    return $errors;
  }
  else {
    // Now we step through all the fetched articles and convert them to arrays
    // of wanted field-sets.
    $found_ids = array();
    // NB!!: The webservice places ONE found article directly in the response.
    // But TWO found articles are placed in an array.
    if (is_array($article_list->Article)) {
      foreach ($article_list->Article as $id => $article) {
        $new_item = _os2web_borger_dk_parse_borgerdk_article($article);
        $found_ids[$new_item['external_id']] = 1;
        $article_items[] = $new_item;
      }
    }
    else {
      foreach ($article_list as $id => $article) {
        $new_item = _os2web_borger_dk_parse_borgerdk_article($article);
        $found_ids[$new_item['external_id']] = 1;
        $article_items[] = $new_item;
      }
    }
    // Now we check if all the wanted articles was found.
    if (!empty($borgerdk_ids)) {
      foreach ($borgerdk_ids as $id) {
        if (empty($found_ids[$id])) {
          $article_items[] = array(
            'external_id' => $id,
            'no_updates' => 1,
          );
        }
      }
    }
  }

  return $article_items;
}

/**
 * Function _os2web_borger_dk_GetArticleByUrl().
 */
function _os2web_borger_dk_GetArticleByUrl($borgerdk_url) {
  // This function uses the Borger.dk WebServices
  // GetArticleIDByUrl and GetArticleByID in order
  // to fetch a Borger.dk-article by its URL.
  $error = array();
  // The URL of the Borger.dk-article to get must
  // be given as argument.
  if (empty($borgerdk_url)) {
    return $error;
  }


  // First we make sure to keep requests/minute within given limits.
  _os2web_borger_dk_check_webservice_constraints();
  // Then we execute our webservice-request.
  $result_list = _os2web_borger_dk_create_soap_client('GetArticleIDByUrl', array('url' => $borgerdk_url));

  // Return error if there is.
  if (is_array($result_list) && isset($result_list['error'])) {

    return $result_list;
  }
  else {
    // If no errors was encountered we fetch the resulting ArticleID.
    $id2get = $result_list->GetArticleIDByUrlResult->ArticleID;

    $la = os2web_borger_dk_check_import_article_language_byURL($borgerdk_url);

    if (!$la) {
      $la = 'da';
    }
    // Then we use the article-ID to fetch the actual Borger.dk-article.
    $article = _os2web_borger_dk_GetArticleByID($id2get, $la);
  }

  return $article;
}

/**
 * Function _os2web_borger_dk_GetArticleByID().
 */
function _os2web_borger_dk_GetArticleByID($borgerdk_id, $la = 'da') {
  // Check the admin setting.
  $admin_municipality = variable_get('os2web_borger_dk_municipality_active');
  // This function uses the Borger.dk WebService
  // GetArticleByID in order to fetch a Borger.dk-article
  // by its article-ID.
  $error = array();
  // The ID of the Borger.dk-article to get must be given as argument.
  if (empty($borgerdk_id)) {
    return $error;
  }

  $array_get_article = array('articleID' => $borgerdk_id, 'language' => $la);

  // If municipality is set, then get article by id and municipality code.
  if ($admin_municipality != 0) {
    $array_get_article['municipalityCode'] = $admin_municipality;
  }

  $result_list = _os2web_borger_dk_create_soap_client('GetArticleByID', $array_get_article);

  // Return error if there is.
  if (is_array($result_list) && isset($result_list['error'])) {

    return $result_list;
  }
  else {
    $article = $result_list->GetArticleByIDResult;
    if (is_soap_fault($article)) {
      // An error was encountered and we examine it more closely.
      $error = _os2web_borger_dk_translate_soap_fault($borgerdk_id, $article->faultcode, $article->faultstring);
      return $error;
    }
  }

  return _os2web_borger_dk_parse_borgerdk_article($article);
}

/**
 * Function _os2web_borger_dk_GetAllSites().
 *
 * This function uses the Borger.dk Webservice GetAllSites
 * in order to fetch the menu-structure from Borger.dk
 */
function _os2web_borger_dk_GetAllSites($use_constraints = TRUE) {
  $errors = array();
  $menu_items = array();

  // First we make sure to keep requests/minute within given limits.
  if ($use_constraints) {
    _os2web_borger_dk_check_webservice_constraints();
  }
  // Then we execute our webservice-request.
  $result_list = _os2web_borger_dk_create_soap_client('GetAllSites', $array_get_article);

  // Return error if there is.
  if (is_array($result_list) && isset($result_list['error'])) {

    return $result_list;
  }

  $menu_items = array();
  // Then we get the result-list from the specified webservice.
  $menu_list = $result_list->GetAllSitesResult;
  if (is_soap_fault($menu_list)) {
    $errors = _os2web_borger_dk_articles_translate_soap_fault('GetAllSitesResult', $menu_list->faultcode, $menu_list->faultstring);

    return $errors;
  }
  else {
    // Now we step through all the fetched menu-items and
    // convert them to arrays of wanted field-sets.
    if (is_array($menu_list->Site)) {
      foreach ($menu_list->Site as $id => $menu_item) {
        $new_item = _os2web_borger_dk_parse_borgerdk_menu_item($menu_item);
        $menu_items[] = $new_item;
      }
    }
    else {
      $new_item = _os2web_borger_dk_parse_borgerdk_menu_item($menu_list->Site);
      $menu_items[] = $new_item;
    }
  }

  return $menu_items;
}


/**
 * Function _os2web_borger_dk_parse_borgerdk_article().
 */
function _os2web_borger_dk_parse_borgerdk_article($article) {
  // This function can parse a Borger.dk XML-article and extract
  // all the field values we want for our Drupal-nodes.
  $borgerdk_article = array(
    'title' => html_entity_decode($article->ArticleTitle, ENT_NOQUOTES, 'UTF-8'),
    'header' => html_entity_decode($article->ArticleHeader, ENT_NOQUOTES, 'UTF-8'),
    'external_id' => $article->ArticleID,
    'external_url' => $article->ArticleUrl,
    'last_updated' => $article->LastUpdated,
    'published_date' => $article->PublishingDate,
  );

  // English article remove <img>
  $import_english = variable_get('os2web_borger_dk_import_english', 0);
  if ($import_english) {
    $article->Content = preg_replace("/<img[^>]+\>/i", "", $article->Content);
  }

  // We need to parse (using simpleXML) the content in order to f
  // ind embedded field-values:
  // Based on example from:
  // http://stackoverflow.com/questions/66358
  // 49/can-simplexml-be-used-to-rifle-through-html
  $doc = new DOMDocument('1.0', 'UTF-8');
  $doc->strictErrorChecking = FALSE;
  // yx@bellcom.dk: disable the Warning:
  // DOMDocument::loadHTML(): ID faktaboks already defined.
  @$doc->loadHTML('<?xml encoding="UTF-8">' . $article->Content);
  $xml = simplexml_import_dom($doc);

  $links_xml = _os2web_borger_dk_get_xml_by_query($xml, "//*[@id='selvbetjeningslinks']");
  $borgerdk_article['selvbetjeningslinks'] = _os2web_borger_dk_create_general_html($links_xml);

  $lov_xml = _os2web_borger_dk_get_xml_by_query($xml, "//*[@id='lovgivning']");
  $borgerdk_article['lovgivning'] = _os2web_borger_dk_create_general_html($lov_xml);
  $borgerdk_article['kernetekst'] = _os2web_borger_dk_create_kernetekst_html($xml);


  $byline_xml = _os2web_borger_dk_get_xml_by_query($xml, "//*[@id='byline']");
  $byline = _os2web_borger_dk_create_general_html($byline_xml->div);
  if (FALSE !== strpos($byline, '<div>Skrevet af')) {
    $byline = trim($byline);
    $new_byline = preg_replace("/<div>(Skrevet af .+?)<\/div>/i", "$1", $byline, 1);
    if (0 < strlen($new_byline)) {
      // We only overwrite the byline if we found some replacement text.
      $byline = $new_byline;
    }
  }
  $borgerdk_article['byline'] = $byline;

  $anbefaler_xml = _os2web_borger_dk_get_xml_by_query($xml, "//*[@id='anbefaler']");
  $borgerdk_article['anbefaler'] = _os2web_borger_dk_create_general_html($anbefaler_xml);

  $huskeliste_xml = _os2web_borger_dk_get_xml_by_query($xml, "//*[@id='huskeliste']");
  $borgerdk_article['huskeliste'] = _os2web_borger_dk_create_general_html($huskeliste_xml);

  $lovgivning_xml = _os2web_borger_dk_get_xml_by_query($xml, "//*[@id='lovgivning']");
  $borgerdk_article['lovgivning'] = _os2web_borger_dk_create_general_html($lovgivning_xml);


  // yx@bellcom.dk: add 'faktaboks' case since Borger.dk updated,
  // some of selvbetjeningslinks contains ID as 'faktaboks'
  // instead of 'selvbetjeningslinks'.
  if (!isset($borgerdk_article['selvbetjeningslinks'])) {

    foreach ($xml->body->div as $div) {
      if ($div->attributes()->id == 'faktaboks') {
        $text = _os2web_borger_dk_create_html_from_xml($div->h2);

        // &#8203;  str string from borger.dk
        $text = str_replace('&#8203;', '', $text);
        preg_match("/Selvbetjening/", $text, $text_2);

        if (isset($text_2[0])) {
          $borgerdk_article['selvbetjeningslinks'] = _os2web_borger_dk_create_general_html($div);
        }
      }
    }
  }

  // Finally we check if the article contained embedded errors.
  $dom_html = $doc->saveHTML();
  if (strpos($dom_html, 'Exception has been thrown by the target of an invocation')) {
    $borgerdk_article['Exceptions'] = 1;
  }
  return $borgerdk_article;
}

/**
 * Returns an XML object of the inner-HTML contained in the borger.dk XML response.
 */
function _os2web_borger_dk_get_xml_by_query($xml, $xpath_query) {

  $html = '';
  $item = $xml->xpath($xpath_query);

  if (count($item) > 0) {

    // Turn xpath query result into HTML
    while(list(,$node) = each($item)) {
      $html .= $node->asXML();
    }

    // Test if more than one element was returned. This can happen, since sometimes there are
    // several elements with the same ID in the borger.dk HTML.
    if (count($item) > 1) {
      // Elements were continated. Log this to dblog.

      watchdog('OS2Web Borger.dk', 'Dual id\'s in structure when using Xpath query "'. $xpath_query .'"" Elements were concatinated');
    }
  }
  else {
    // Noting returned by query. $html variable must contain an element in order for
    // proceeding code not to error, so we fill in a dummy <span>
    $html .= '<span></span>';
  }

  $new_dom = new DOMDocument('1.0', 'UTF-8');
  $new_dom->strictErrorChecking = FALSE;
  @$new_dom->loadHTML('<?xml encoding="UTF-8">' . $html);
  $xml = simplexml_import_dom($new_dom);
  return $xml;
}

/**
 * Function _os2web_borger_dk_parse_borgerdk_article_desc().
 */
function _os2web_borger_dk_parse_borgerdk_article_desc($article) {
  // This function parses a Borger.dk-ArticleDescription and
  // extracts all the field values we want for our list of
  // titles (for autocompletion etc).
  // First we extract the directly accessible fields from the
  // ArticleDescription.
  $borgerdk_title = array(
    'ArticleID' => $article->ArticleID,
    'ArticleTitle' => html_entity_decode($article->ArticleTitle, ENT_NOQUOTES, 'UTF-8'),
    'ArticleUrl' => $article->ArticleUrl,
    'LastUpdated' => $article->LastUpdated,
    'PublishingDate' => $article->PublishingDate,
  );

  // Then we find all FORM-elements and create a new serialized array.
  $form_elements = array(
    'FormServiceAreas' => (isset($article->FormServiceAreas)) ? $article->FormServiceAreas : NULL,
    'FormTaskAreas' => (isset($article->FormTaskAreas)) ? $article->FormTaskAreas : NULL,
  );

  $form_tasks = array();
  $article_formtasks = $article->FormTasks;
  if ((isset($article_formtasks->FormTask)) && is_array($article_formtasks->FormTask)) {
    foreach ($article_formtasks->FormTask as $id => $formtask) {
      $task = array(
        'FormTaskName' => $formtask->FormTaskName,
        'FormTaskNumber' => $formtask->FormTaskNumber,
      );
      $form_tasks[] = $task;
    }
  }
  else {
    if (isset($article_formtasks->FormTask)) {
      $single_task = $article_formtasks->FormTask;
      $task = array(
        'FormTaskName' => $single_task->FormTaskName,
        'FormTaskNumber' => $single_task->FormTaskNumber,
      );
      $form_tasks[] = $task;
    }
  }
  // Then we add the found FORM-elements to the return array.
  $form_elements['FormTasks'] = $form_tasks;
  $borgerdk_title['FORMFields'] = serialize($form_elements);

  return $borgerdk_title;
}

/**
 * Function _os2web_borger_dk_create_kernetekst_html().
 */
function _os2web_borger_dk_create_kernetekst_html($xml) {
  // This function steps through the so called microArticle's
  // and converts plus concatenates each element as HTML.
  $microarticles = _os2web_borger_dk_get_xml_by_query($xml, "//*[starts-with(@id, 'microArticle')]");

  $output = array();
  $counter = 1;
  $baseclass = 'mArticle';
  foreach ($microarticles->body->div as $microarticle) {

    $div_attr = $microarticle->attributes()->id;
    $search = '<div id="' . $div_attr . '">';
    $replace = '<div class="microArticle" id="microArticle' . $counter . '">';
    $html = _os2web_borger_dk_create_html_from_xml($microarticle, $search, $replace);

    // We replace the first <h2>-tag with <h2 class="mArticleX">.
    $pattern = '/<h2>/';
    $replacement = '<h2 class="mArticle" id="' . $baseclass . $counter . '">';
    $html = preg_replace($pattern, $replacement, $html, 1);

    // We replace the first <h3>-tag with <h2 class="mArticleX">.
    $pattern = '/<h3>/';
    $replacement = '<h2 class="mArticle" id="' . $baseclass . $counter . '">';
    $html = preg_replace($pattern, $replacement, $html, 1);

    // We replace the first </h3>-tag with </h2>.
    $pattern = '/<\/h3>/';
    $replacement = '</h2>';
    $html = preg_replace($pattern, $replacement, $html, 1);

    // And we replace the first <div>-tag with <div class="mArticleX">.
    $pattern = '/<div>/';
    $replacement = '<div class="' . $baseclass . $counter . ' mArticle">';
    $html = preg_replace($pattern, $replacement, $html, 1);

    $output["$div_attr"] = $html;

    // Then we update the counter for the next kernetekst-div.
    $counter += 1;

  }

  return $output;
}

/**
 * This function converts a list of XML elements to HTML.
 */
function _os2web_borger_dk_create_general_html($xml) {
  $output = '';

  // We convert each of the XML elements to HTML.
  foreach ($xml as $element) {
    // We use a general method to convert XML to HTML.
    $output .= _os2web_borger_dk_create_html_from_xml($element);
    $output .= "\n";
  }

  return $output;
}

/**
 * This function converts XML-entities to ordinary HTML.
 */
function _os2web_borger_dk_create_html_from_xml($xml, $search = NULL, $replace = NULL) {
  // DOMDocuments converts special characters to HTML-characters, and we
  // need to replace some of those back into danish letters. Also <br/>-tags
  // gets replaced with <br>-tags, and we need to convert those as well.
  $substitute = array(
    '<br>' => '<br />',
    '&aelig;' => '%C3%A6',
    '&Aelig;' => '%C3%86',
    '&AElig;' => '%C3%86',
    '&oslash;' => '%C3%B8',
    '&Oslash;' => '%C3%98',
    '&aring;'  => '%C3%A5',
    '&Aring;'  => '%C3%85',
    '&rsquo;' => '%26rsquo%3B',
    '&ndash;' => '%26ndash%3B',
    '&eacute;' => '%26eacute%3B',
  );
  // If the function is called with a special replacement-string we add
  // the search- and replace-strings to the default substitution array.
  if (!empty($search) && !empty($replace)) {
    $substitute[$search] = $replace;
  }

  // Then we convert the XML to HTML, and substitute special characters.
  $dom = new DOMDocument('1.0', 'UTF-8');
  $dom->loadXML($xml->asXML());
  $dom_html = $dom->saveHTML();
  $dom_html = strtr($dom_html, $substitute);
  $dom_html = urldecode($dom_html);

  return $dom_html;
}

/**
 * Function _os2web_borger_dk_translate_soap_fault().
 */
function _os2web_borger_dk_translate_soap_fault($function, $faultcode, $faultstring) {
  // This function is used to translate SoapClient-errors
  // from string-elements to an array of
  // "real"/"usable" error-information.
  $error = array(
    'error' => 1,
    'error_function' => $function,
    'error_code' => $faultcode,
    'error_string' => $faultstring,
  );

  // We set up an array of known SoapClient errors
  // array of: 'error_type' => '/regex-pattern to use/'.
  $known_errors = array(
    'not_found' => '/^No articles found with ids \'(\d*)\'/',
  );

  // Now we examine the faultstring more closely.
  if ($faultcode == "s:Client") {
    // Then we might know something about that error-type.
    foreach ($known_errors as $error_type => $error_text) {
      $matches = array();
      if (1 == preg_match($error_text, $faultstring, $matches)) {
        // We found a known error type.
        $error['error_type'] = $error_type;

        // Now lets see if there are known matches / digits to return.
        switch ($error_type) {
          case 'not_found':
            $error['not_found_id'] = $matches[1];
            break;

          default:
            break;
        }

        // Finally we break out of the loop for finding this error.
        break;
      }
    }
  }

  return $error;
}

/**
 * Function _os2web_borger_dk_check_webservice_constraints().
 *
 * Checking if the webservice constraints has been reached, and in that case
 * delaying the script.
 */
function _os2web_borger_dk_check_webservice_constraints() {
  $time = time();

  // We start of by getting the webservice request-limits.
  $webservice_request_limit = variable_get('os2web_borger_dk_webservice_request_limit', 100);
  $webservice_time_limit = variable_get('os2web_borger_dk_webservice_time_limit', 60);

  // And we keep track of the number of webservice-requests per timeperiod.
  $os2web_borger_dk_article_count_no = variable_get('os2web_borger_dk_webservice_request_counter', 0);
  $os2web_borger_dk_article_start_time = variable_get('os2web_borger_dk_webservice_time_counter', 0);

  // We restart the counters if the timer is too old.
  if ($os2web_borger_dk_article_start_time < ($time - $webservice_time_limit)) {
    $os2web_borger_dk_article_count_no = 0;
    $os2web_borger_dk_article_start_time = $time;
    variable_set('os2web_borger_dk_webservice_request_counter', $os2web_borger_dk_article_count_no);
    variable_set('os2web_borger_dk_webservice_time_counter', $os2web_borger_dk_article_start_time);
  }

  // Then we check if the limits has been reached, and it's time for a break.
  if (($webservice_time_limit >= ($time - $os2web_borger_dk_article_start_time)) &&
      ($webservice_request_limit <= $os2web_borger_dk_article_count_no)) {
    // We have reached the work-load limit of 100 items per minute, and must
    // take a small break or the webservice will stop answering us.
    sleep($webservice_time_limit - ($time - $os2web_borger_dk_article_start_time));

    // Then we reset/store the counters for limiting the webservice work-load.
    $os2web_borger_dk_article_count_no = 0;
    $os2web_borger_dk_article_start_time = time();
    variable_set('os2web_borger_dk_webservice_time_counter', $os2web_borger_dk_article_start_time);
  }
}
