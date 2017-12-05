# Social Media Buttons V.1
## Drupal 7.x module

## Description
This module is designed to do one thing, and one thing only:

Providing a custom content pane, that shows 3 social media share buttons.

## Release notes V.1

## Dependencies

* Panels
* Ctools
* Page Manager

These modules are required for this module to be enabled, since we use those for displaying our buttons.

## Keep in mind
Okay so theres a couple of things to keep in mind when using this module.

* The content div wich contains content that you want to share should have css class " .content ".

The module needs this because we are using jquery for implementing correct content in

```html
<head> <meta> 
```
tags,

As for, as i know drupal has this class on default themes.

If you do not set " .content " class on content div, the module will still work, but the crawler that Facebook and LinkedIn
Uses, will not get content the recomended way.

* Images in article/content to share. 
Facebook states that the first time, a user hits the share button no image will be displayed, because the crawler
hasnt found the image yead.

https://developers.facebook.com/docs/sharing/best-practices
under Pre-caching images section.


# Upcomming features
* Posibility to choose diferent button styles from admin page.
* Vertical and horizontal buttons alignment.

# Known issues

## Facebook URL debugger

Because the module is providing its meta information throug jquery on document ready, the URL debugger doesn´t get

the information needed when providing the URL to debug.

You will still be apple to see what the shared content will look like, but you cannot pre chache the content.

I will look into this on V.2
