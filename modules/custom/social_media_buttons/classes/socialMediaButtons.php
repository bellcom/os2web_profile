<?php

class SocialMediaButtons
{
    private $url;
    private $pageTitle;
    
    function __construct() {
        $this->url = $GLOBALS['base_url'].request_uri();
        $this->pageTitle = drupal_get_title();
    }
    
    public function Buttons($button_to_return) {
        if($button_to_return == 'Facebook') {
            $path = drupal_get_path('module', 'social_media_buttons');
            drupal_add_js($path . '/js/trigger.js');
            $button_values = array();
            $button_values['button'] = '<a class="social_media_button_link" href="http://www.facebook.com/sharer/sharer.php?u='.$this->url.'&title='.$this->pageTitle.'"><img src="/'.$path.'/img/facebook.png" /></a>';           
            
            return $button_values;
        }
        
        if($button_to_return == 'Twitter') {
            $path = drupal_get_path('module', 'social_media_buttons');
            drupal_add_js($path . '/js/trigger.js');
            $button_values = array();
            $button_values['button'] = '<a class="social_media_button_link" href="http://twitter.com/intent/tweet?status='.$this->pageTitle.'+'.$this->url.'"><img src="/'.$path.'/img/twitter.png" /></a>';

            return $button_values;
        }
        
        if($button_to_return == 'LinkedIn') {
            $path = drupal_get_path('module', 'social_media_buttons');
            drupal_add_js($path . '/js/trigger.js');
            $button_values = array();
            $button_values['button'] = '<a class="social_media_button_link" href="http://www.linkedin.com/shareArticle?mini=true&url='.$this->url.'&title='.$this->pageTitle.'&source='.$this->pageTitle.'.dk"><img src="/'.$path.'/img/linkedin.jpg" /></a>';

            return $button_values;
        }
    }
}

