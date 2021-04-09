<?php

/**
 * @file
 * Search API data alteration callback.
 */
class SearchApiClearHtmlAlterSettings extends SearchApiAbstractAlterCallback {

  /**
   * {@inheritdoc}
   */
  public function alterItems(array &$items) {
    foreach ($items as &$item) {
      foreach (explode(',', $this->options['fields_clear']) as $field_name) {   
        if (isset($item->node->{$field_name}) && is_array($item->node->{$field_name}['und'])) {
          foreach ($item->node->{$field_name}['und'] as $key => &$values){
            if (isset($values['value'])) {
              $item->node->{$field_name}['und'][$key]['value'] = preg_replace('/\[\[\{(.*?)\}\]\]/', "", strip_tags($values['value']));
            }  
            if (isset($values['manual_text'])) {
              $item->node->{$field_name}['und'][$key]['manual_text'] = preg_replace('/\[\[\{(.*?)\}\]\]/', "", strip_tags($values['manual_text']));

            }
          }
        }
      }
    }
  }

 public function configurationForm() {
    $parent_form = parent::configurationForm();
    unset($parent_form['number_indexed']);
    unset($parent_form['max_file_size']);
    unset($parent_form['excluded_private']);

    $parent_form['fields_clear'] = array(
      '#type' => 'textfield',
      '#title' => t('List of fields which should be cleared'),
      '#default_value' => isset($this->options['fields_clear']) ? $this->options['fields_clear'] : 'body',
      '#size' => 80,
      '#description' => t('The list of fields, which will be cleared out of json and html tags'),
    );

    return $parent_form;
  }
}
