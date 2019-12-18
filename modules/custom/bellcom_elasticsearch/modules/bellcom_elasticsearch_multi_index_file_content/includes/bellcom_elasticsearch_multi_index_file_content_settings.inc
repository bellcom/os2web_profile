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
  public function propertyInfo() {
    $ret = array();

    $ret['bellcom_elasticsearch_multi_index_file_entity_content'] = array(
      'label' => 'Bellcom elasticsearch file entity content',
      'description' => 'Alternative way of indexing content of the file, when file entity is indexed directly (not though the attachment)',
      'type' => 'text',
    );

    return $ret;
  }
}
