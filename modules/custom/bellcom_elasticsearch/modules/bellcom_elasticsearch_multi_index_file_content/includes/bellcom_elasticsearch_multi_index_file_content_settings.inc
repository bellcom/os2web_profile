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

      // Excluding the file from index, if the 'include_file_media_folders'
      // option is not empty, but media folder tid is not within the allowed
      // list.
      if (isset($this->options['include_file_media_folders'])) {
        if (!empty($this->options['include_file_media_folders'])) {
          if (!in_array($file_folder_folder_tid, $this->options['include_file_media_folders'])) {
            $isIndexable = FALSE;
          }
        }
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
      $terms = taxonomy_get_tree($voc->vid);

      // Build the select options.
      $media_folder_options = array();
      foreach ($terms as $term) {
        $media_folder_options[$term->tid] = $term->name;
      }

      if ($media_folder_options) {
        $form['include_file_media_folders'] = array(
          '#type' => 'select',
          '#title' => t('Include file media folders'),
          '#options' => $media_folder_options,
          '#multiple' => TRUE,
          '#default_value' => isset($this->options['include_file_media_folders']) ? $this->options['include_file_media_folders'] : array(),
          '#description' => t('File entity media folder that are included into the indexing. If empty, all the media folder are indexed.'),
        );
      }
    }

    return $form;
  }

}
