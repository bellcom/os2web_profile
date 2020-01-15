<?php

/**
 * @file
 * Search API data alteration callback.
 */

class SearchApiAlterExcludeUnpublishedContentAlterSettings extends SearchApiAbstractAlterCallback {

  /**
   * {@inheritdoc}
   */
  public function alterItems(array &$items) {
    foreach ($items as $id => $item) {
      $exclude = FALSE;


      switch ($item->item_type) {
        case 'node' :
          if ($this->options['exclude_nodes']) {
            if ($item->node->status == NODE_NOT_PUBLISHED) {
              $exclude = TRUE;
            }
          }
          break;
        case 'field_collection_item' :
          if ($this->options['exclude_field_collection_item']) {
            $node = $item->field_collection_item->hostEntity();
            if (!$node || $node->status == NODE_NOT_PUBLISHED) {
              $exclude = TRUE;
            }
          }
          break;
      }
      if ($exclude) {
        unset($items[$id]);
      }
    }

  }

   /**
   * {@inheritdoc}
   */
  public function configurationForm() {
    $form['exclude_nodes'] = array(
      '#type' => 'checkbox',
      '#title' => t('Exclude unpublished node from indexing'),
      '#default_value' => isset($this->options['exclude_nodes']) ? $this->options['exclude_nodes'] : 0,
    );

    $form['exclude_field_collection_item'] = array(
      '#type' => 'checkbox',
      '#title' => t('Exclude paragraph from indexing, if host node is unpublished.'),
      '#default_value' => isset($this->options['exclude_field_collection_item']) ? $this->options['exclude_field_collection_item'] : 0,
    );

    return $form;
  }
  /**
   * Determines whether a certain entity type has any bundles.
   *
   * @param array $entity_info
   *   The entity type's entity_get_info() array.
   *
   * @return bool
   *   TRUE if the entity type has bundles, FALSE otherwise.
   */
  protected static function hasBundles(array $entity_info) {
    return !empty($entity_info['entity keys']['bundle']) && !empty($entity_info['bundles']);
  }

}
