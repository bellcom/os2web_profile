<?php
/**
 * @author: Stanislav Kutasevits, stan@bellcom.dk
 *
 * This script will empty the description field of all terms in the selected vocabulary.
 **/

$time_start = microtime(true);
print('==========================' . PHP_EOL);
print('Started clear_field_description.cron.php' . PHP_EOL);
print('==========================' . PHP_EOL);

print('Loading all terms' . PHP_EOL);

$vocabulary = taxonomy_vocabulary_machine_name_load('section');
$terms = entity_load('taxonomy_term', FALSE, array('vid' => $vocabulary->vid));
print('Terms count: ' . sizeof($terms) . PHP_EOL);

foreach ($terms as $term) {
  print('Terms loaded: ' . $term->name . ' [' . $term->tid . ']'. PHP_EOL);
  $term->description = '';
  taxonomy_term_save($term);
  print('Terms saved: ' . $term->name . ' [' . $term->tid . ']'. PHP_EOL);
  //print $term->tid . ': ' . $term->description .  PHP_EOL;
}

print('==========================' . PHP_EOL);
print('Finished  clear_field_description.cron.php' . PHP_EOL);
print('Total execution time: ' . (microtime(true) - $time_start) . ' seconds' . PHP_EOL);
print('==========================' . PHP_EOL);