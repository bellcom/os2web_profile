<?php

/**
 * @file
 * Search API data alteration callback.
 */
class SearchApiAttachmentsMultiIndexFileContentAlterSettings extends SearchApiAttachmentsAlterSettings {

  /**
   * {@inheritdoc}
   */
  public function alterItems(array &$items) {
    parent::alterItems($items);
    foreach ($items as &$item) {
      if (isset($item->attachments_content)) {
        if (!$item->attachments_content) {
          $item->bellcom_elasticsearch_multi_index_file_entity_content = '';
        }
        else {
          $item->bellcom_elasticsearch_multi_index_file_entity_content = $item->attachments_content;
        }
      }
      else {
        $item->bellcom_elasticsearch_multi_index_file_entity_content = '';
      }
    }
  }

  /**
   * {@inheritdoc}
   */
  public function isFileIndexable($file, $item, $field_name = NULL) {
    $isIndexable = parent::isFileIndexable($file, $item, $field_name);

    // Only doing additional checks if file is indexable up to this point.
    if ($isIndexable) {
      // Sometimes file comes as an array.
      if (is_array($file)) {
        $file = (object) $file;
      }

      // Getting media folder tid.
      $field_folder = field_get_items('file', $file, 'field_folder');
      $file_folder_folder_tid = NULL;
      if (!empty($field_folder)) {
        $field_folder = reset($field_folder);
        $file_folder_folder_tid = $field_folder['tid'];
      }

      // Excluding the file from index, if the 'exclude_empty_media_folders'
      // option is set and media folder tid is empty.
      if (isset($this->options['exclude_empty_media_folders'])) {
        if ($this->options['exclude_empty_media_folders']) {
          if (!$file_folder_folder_tid) {
            $isIndexable = FALSE;
          }
        }
      }

      if (isset($this->options['exclude_files_attached_to_unpublished_content']) && $isIndexable) {
        $usages = file_usage_list($file);
        if (isset($usages['file']['node'])) {
          $indexFile = FALSE;
          foreach ($usages['file']['node'] as $nid => $count) {
            $node = node_load($nid);
            if ($node->status === NODE_PUBLISHED) {
              $indexFile = TRUE;
            }
          }
        }
        $isIndexable = $indexFile;

      }
    }

    return $isIndexable;
  }

  /**
   * {@inheritdoc}
   */
  public function propertyInfo() {
    $ret = array();

    $ret['bellcom_elasticsearch_multi_index_file_entity_content'] = array(
      'label' => 'Bellcom elasticsearch file entity content',
      'description' => 'Alternative way of indexing content of the file, when file entity is indexed directly (not though the attachment)',
      'type' => 'text',
    );

    return $ret;
  }

  public function configurationForm() {
    $form = parent::configurationForm();

    $voc = taxonomy_vocabulary_machine_name_load('media_folders');
    if ($voc) {
      $form['exclude_empty_media_folders'] = array(
        '#type' => 'checkbox',
        '#title' => t('Exclude empty media folders'),
        '#multiple' => TRUE,
        '#default_value' => isset($this->options['exclude_empty_media_folders']) ? $this->options['exclude_empty_media_folders'] : FALSE,
        '#description' => t('If the file with no media folder shall be excluded.'),
      );
    }
    $form['exclude_files_attached_to_unpublished_content'] = array(
        '#type' => 'checkbox',
        '#title' => t('Exclude file from indexing, if node it is attahced is unpublished.'),
        '#default_value' => isset($this->options['exclude_files_attached_to_unpublished_content']) ? $this->options['exclude_files_attached_to_unpublished_content'] : 0,
    );

    return $form;
  }

}
