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
      $exclude = TRUE;
       switch ($item->item_type) {
        case 'file':
          if ($this->options['exclude_files']) {
            $index_file_bundles = array_flip($this->options['index_file_bundles']);
            $index_file_default = (bool) $this->options['index_file_default'];
            $file = $item->file;
            $usages = file_usage_list($file);
             if (isset($usages['file']['node'])) {
               foreach ($usages['file']['node'] as $nid => $count) {
                 $node = node_load($nid);
                 if (($node->status==1) && (isset($index_file_bundles[$node->type]) !== $index_file_default)) {
                   $exclude = FALSE;
                 }
               }
             }
          }
          else  {
            $exclude = FALSE;
          }
        break;
        case 'node' :
          if($this->options['exclude_nodes']) {
            if ($item->node->status) {
              $exclude = FALSE;
            }
          }
          else {
            $exclude = FALSE;
          }
        break;
        case 'field_collection_item' :
          if ($this->options['exclude_field_collection_item']) {
            $node = $item->field_collection_item->hostEntity();
            if ($node->status) {
              $exclude = FALSE;
            }
          }
          else {
            $exclude = FALSE;
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
    $options = array();

    if ($this->supportsIndex($this->index)) {
      if ($this->isMultiEntityIndex()) {
        $info = entity_get_info();
        $unsupported_types = array();
        if (in_array('node', $this->index->options['datasource']['types'])) {
          $info = entity_get_info('node');
          foreach ($info['bundles'] as $bundle => $bundle_info) {
            $options[$bundle] = isset($bundle_info['label']) ? $bundle_info['label'] : $bundle;
          }
        }
      }
    }
    $form['exclude_nodes'] = array(
        '#type' => 'checkbox',
        '#title' => t('Exclude unpublished node from indexing'),
        '#default_value' => isset($this->options['exclude_nodes']) ? $this->options['exclude_nodes'] : 0,
    );

    $form['exclude_field_collection_item'] = array(
        '#type' => 'checkbox',
        '#title' => t('Exclude paragraph from indexing, if node it is attahced is unpublished.'),
        '#default_value' => isset($this->options['exclude_field_collection_item']) ? $this->options['exclude_field_collection_item'] : 0,
    );

    $form['exclude_files'] = array(
        '#type' => 'checkbox',
        '#title' => t('Exclude file from indexing, if node it is attahced is unpublished.'),
        '#default_value' => isset($this->options['exclude_files']) ? $this->options['exclude_files'] : 0,
    );
    if(!empty($options)) {
      $form['index_file_default'] = array(
        '#type' => 'radios',
        '#title' => t('Files attached to which nodes should be indexed?'),
        '#default_value' => isset($this->options['index_file_default']) ? $this->options['index_file_default'] : 1,
        '#options' => array(
          1 => t('All but those from one of the selected bundles'),
          0 => t('Only those from the selected bundles'),
        ),
      );
      $form['index_file_bundles'] = array(
        '#type' => 'select',
        '#title' => t('Bundles'),
        '#default_value' => isset($this->options['index_file_bundles']) ? $this->options['index_file_bundles'] : array(),
        '#options' => $options,
        '#size' => min(4, count($options)),
        '#multiple' => TRUE,
      );
    }

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
