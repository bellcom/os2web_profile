<?php
/**
 * @file
 * os2web_base.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function os2web_base_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "panels" && $api == "layouts") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function os2web_base_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function os2web_base_image_default_styles() {
  $styles = array();

  // Exported image style: os2web_base_style_content.
  $styles['os2web_base_style_content'] = array(
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 460,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
      2 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 460,
          'height' => 260,
          'anchor' => 'center-center',
        ),
        'weight' => 2,
      ),
    ),
    'label' => 'os2web_base_style_content',
  );

  // Exported image style: os2web_base_style_image.
  $styles['os2web_base_style_image'] = array(
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 470,
          'height' => 230,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'os2web_base_style_image',
  );

  // Exported image style: os2web_base_style_medium.
  $styles['os2web_base_style_medium'] = array(
    'effects' => array(
      5 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 460,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
      6 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 460,
          'height' => 260,
          'anchor' => 'center-center',
        ),
        'weight' => 2,
      ),
    ),
    'label' => 'os2web_base_style_medium',
  );

  // Exported image style: os2web_base_style_news_big.
  $styles['os2web_base_style_news_big'] = array(
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 214,
          'height' => 116,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'os2web_base_style_news_big',
  );

  // Exported image style: os2web_base_style_news_medium.
  $styles['os2web_base_style_news_medium'] = array(
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 180,
          'height' => 140,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'os2web_base_style_news_medium',
  );

  // Exported image style: os2web_base_style_news_small.
  $styles['os2web_base_style_news_small'] = array(
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 60,
          'height' => 69,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'os2web_base_style_news_small',
  );

  // Exported image style: os2web_base_style_rotating.
  $styles['os2web_base_style_rotating'] = array(
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 460,
          'height' => 260,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'os2web_base_style_rotating',
  );

  // Exported image style: os2web_base_style_rotating_small.
  $styles['os2web_base_style_rotating_small'] = array(
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 161,
          'height' => 65,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'os2web_base_style_rotating_small',
  );

  // Exported image style: os2web_gallery_thumbnails.
  $styles['os2web_gallery_thumbnails'] = array(
    'label' => 'OS2web gallery thumbnails',
    'effects' => array(
      14 => NULL,
      15 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 290,
          'height' => 290,
        ),
        'weight' => -9,
      ),
    ),
  );

  return $styles;
}
