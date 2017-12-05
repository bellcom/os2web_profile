<?php

function social_media_buttons_return_variables()
{
    //Getting the stored values from the global variables.
    $value = variable_get('social_media_button_checkboxes');
    
     /*
     * Making this array so that we can filter the values from
     * variable_get by array.
     * Makes things more dynamic.
     */
    if($value) {
        foreach($value as $key) {
            if(is_array($key)) {
                foreach($key as $key2 => $values) {
                    $default_value_array[] = $values;
                }
            }
        }
        return $default_value_array;
    }
    
    
}
