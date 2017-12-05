<?php
/**
 * @author: Stanislav Kutasevits, stan@bellcom.dk
 *
 * This script will loop through all content that reference os2web_borger_dk_article and update those references to corresponding borger_dk_article
 *
 **/
$time_start = microtime(TRUE);
print('==========================' . PHP_EOL);
print('Started bellcom_borger_dk_update_unique_links_field.php' . PHP_EOL);

//find all fields that use os2web_borger_dk_articles
$fields = field_read_fields(array('field_name' => 'field_os2web_base_field_related'));
foreach ($fields as $field) {
  $field_instances = field_read_instances(array('field_id' => $field['id']));
  foreach ($field_instances as $field_instance) {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', $field_instance['entity_type'])
      ->entityCondition('bundle', $field_instance['bundle'])
      ->fieldCondition('field_os2web_base_field_related', 'nid', 'NULL', '!=');

    $result = $query->execute();

    if (isset($result['node'])) {
      $nids = array_keys($result['node']);
      $nodes = entity_load('node', $nids);

      foreach ($nodes as $node) {
        $needs_saving = FALSE;
        for ($i = 0; $i < count($node->field_os2web_base_field_related['und']); $i++) {
          $related_node = node_load($node->field_os2web_base_field_related['und'][$i]['nid']);
          if ($related_node->type == 'os2web_borger_dk_article') {
            print($related_node->title . ' [' . $node->field_os2web_base_field_related['und'][$i]['nid'] . ']');
            print(' -> ');
            $new_article = bellcom_borger_dk_get_corresponding_new_article($related_node);
            if ($new_article) {
              print($new_article->title . ' [' . $new_article->nid . '] ');
              $node->field_os2web_base_field_related['und'][$i]['nid'] = $new_article->nid;
              $needs_saving = true;
            }
            print_r(PHP_EOL . PHP_EOL);
          }
        }

        if ($needs_saving) {
          node_save($node);
          print_r('Saved node: ' . $node->nid);
          print_r(PHP_EOL . PHP_EOL);
        }
      }
    }

    if (isset($result['taxonomy_term'])) {
      $tids = array_keys($result['taxonomy_term']);
      $terms = entity_load('taxonomy_term', $tids);

      foreach ($terms as $term) {
        $needs_saving = FALSE;
        for ($i = 0; $i < count($term->field_os2web_base_field_related['und']); $i++) {
          $related_node = node_load($term->field_os2web_base_field_related['und'][$i]['nid']);
          if ($related_node->type == 'os2web_borger_dk_article') {
            print($related_node->title . ' [' . $term->field_os2web_base_field_related['und'][$i]['nid'] . ']');
            print(' -> ');
            $new_article = bellcom_borger_dk_get_corresponding_new_article($related_node);
            if ($new_article) {
              print($new_article->title . ' [' . $new_article->nid . '] ');
              $term->field_os2web_base_field_related['und'][$i]['nid'] = $new_article->nid;
              $needs_saving = true;
            }
            print_r(PHP_EOL . PHP_EOL);
          }
        }

        if ($needs_saving) {
          taxonomy_term_save($term);
          print_r('Saved term: ' . $term->tid);
          print_r(PHP_EOL . PHP_EOL);
        }
      }
    }
  }
}

print('==========================' . PHP_EOL);
print('Finished bellcom_borger_dk_update_unique_links_field.php' . PHP_EOL);
print('Total execution time: ' . (microtime(TRUE) - $time_start) . ' seconds' . PHP_EOL);
print('==========================' . PHP_EOL);