<?php

//Defining settings for panels
$plugin = array(
  'title' => t('Social Media Buttons'),
  'description' => t('This custom pane provides Social media buttons (Facebook, Twitter).'),
  'category' => t('Custom'),
  'single' => TRUE,
  'render callback' => 'social_media_buttons_content_type_render',
  'content type' => '[content_type]',
  'edit form' => 'social_media_buttons_edit_form',
  'admin info' => 'social_media_buttons_admin_info',
);

function social_media_buttons_content_type_render($subtype, $conf, $panel_args, $context) {
  
  $path = drupal_get_path('module', 'social_media_buttons');
  
  //Getting admin settings from admin page (the checkboxes selected by the user).
  require ($path . '/inc/return_module_variables.php');
  
  //Making the social media buttons (links) available here.
  require ($path . '/classes/socialMediaButtons.php');
    
  //Getting checkboxes values from return_module_variables.php.
  $default_value_array = social_media_buttons_return_variables();     
  
  $block = new stdClass();
  $block->title = '<div class="social-media-pane-title">'.t('Share').'</div>';
  $block->content = '<div class="social-media-buttons-wrapper">';
  
  $button = new SocialMediaButtons();
  
  //Making sure that buttons are selected.
  if(!empty($default_value_array)) {
      
    //Go throug all checkboxes. 
    foreach($default_value_array as $checked => $social_media_button) {
        //If they are checked, include the buttons.
        if($social_media_button != NULL) {
            $button_values = $button->Buttons($social_media_button);
            $block->content .= $button_values['button']; 
        }
    }
    $block->content .= '</div>';  
  }
  else
  {
      //If theres no buttons checked we just set content to nothing.
      $block->content = "";
  }
  return $block;
}

//Giving the users posibility of changing the title of the pane.
function social_media_buttons_admin_info($subtype, $conf, $contexts) {
    if (!empty($conf)) {
        $block = new stdClass;
        $block->title = $conf['override_title'] ? $conf['override_title_text'] : '';
        return $block;
        }
}

function social_media_buttons_edit_form($form, &$form_state) {
  return $form;
}

//Saving new inputs to the pane if any.
function social_media_buttons_edit_form_submit($form, &$form_state) {
    foreach (array_keys($form_state['plugin']['defaults']) as $key) {
        if (isset($form_state['values'][$key])) {
             $form_state['conf'][$key] = $form_state['values'][$key];
        }
    }
}