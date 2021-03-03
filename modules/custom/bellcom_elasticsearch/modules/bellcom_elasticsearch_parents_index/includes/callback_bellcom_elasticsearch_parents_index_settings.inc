<?php

/**
 * @file
 * Search API data alteration callback.
 */
class SearchApiParentsIndexAlterSettings extends SearchApiAbstractAlterCallback {

  /**
   * {@inheritdoc}
   */
  public function alterItems(array &$items) {

    foreach ($items as &$item) {

      if ($item->item_type == 'taxonomy_term') {

        // Get all children taxonomies
        $children_terms = taxonomy_get_children($item->taxonomy_term->tid);
        foreach ($children_terms as $child_term) {

          if (!strpos($item->bellcom_elasticsearch_parents_index, $child_term->name)) {
            $item->bellcom_elasticsearch_parents_index .= ' ' . $child_term->name;
          }
        }

        // Get all nodes with this taxonomy linked
        $linked_nodes = taxonomy_select_nodes($item->taxonomy_term->tid, FALSE, FALSE);
        foreach ($linked_nodes as $linked_node) {
          if (!strpos($item->bellcom_elasticsearch_parents_index, $linked_node->title)) {
            $item->bellcom_elasticsearch_parents_index .= ' ' . $linked_node->title;
          }
        }
      }
    }
  }

  /**
   * {@inheritdoc}
   */
  public function propertyInfo() {
    $ret = array();

    $ret['bellcom_elasticsearch_parents_index'] = array(
      'label' => 'Bellcom Elastisearch Parents Index',
      'description' => 'Add information about its parents to taxonomy terms',
      'type' => 'text',
    );

    return $ret;
  }

}
