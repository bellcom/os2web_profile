<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
$query = new EntityFieldQuery();
$result = $query->entityCondition('entity_type', 'node')
      ->propertyCondition('type', 'os2web_meetings_meeting')
      ->fieldCondition('field_os2web_meetings_searchdata', 'value',  "NULL", '!=')
      ->execute();
 if (isset($result['node']) && is_array($result['node'])) {
    //Now get all the other entities, that aren't in the list you just retrieved 
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->propertyCondition('type', 'os2web_meetings_meeting')
      ->entityCondition('entity_id', array_keys($result['node']), 'NOT IN');
    $result = $query->execute();  
  }
 if(isset($result['node']) && is_array($result['node'])) {
  $meetings = node_load_multiple(array_keys($result['node']));
  foreach ($meetings as $meeting) {
    os2web_meetings_update_search_index($meeting);
    print 'Updated meeting ' . $meeting->nid . PHP_EOL;
  }
 }  