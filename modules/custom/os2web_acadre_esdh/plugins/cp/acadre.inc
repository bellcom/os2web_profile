<?php
/**
 * @file
 * This file describes the Content pushing plugin as implemented by Acadre
 */
/**
 * Plugin definition with callbacks
 */
$plugin = array(
  'description' => t('Acadre ESDH Case Pushing backend'),
  'version' => 1,
  'handle_request' => 'os2web_acadre_esdh_cp_handle_request',
);
/**
 * This functions handles a request on the webservice API.
 */
function os2web_acadre_esdh_cp_handle_request() {
  if (!isset($_SERVER['PHP_AUTH_USER']) && $_SERVER['SERVER_ADDR'] != '192.168.2.52') {
    header('WWW-Authenticate: Basic realm="Fredericia.dk"');
    header('HTTP/1.0 401 Unauthorized');
    error_log(print_r($_SERVER,true));
    echo 'You are not allowed to access';
    exit;
  }
    #error_log(print_r($_SERVER,true));

#  if (!(isset($_SERVER['PHP_AUTH_PW']) && isset($_SERVER['PHP_AUTH_USER'])
#    && $_SERVER['PHP_AUTH_PW']==variable_get('os2web_cp_basic_auth_psw') &&  $_SERVER['PHP_AUTH_USER']==variable_get('os2web_cp_basic_auth_username'))) {
#    header('HTTP/1.0 403 Forbidden');
#    die('You are not allowed to access.');
#  }

  module_load_include('inc', 'os2web_acadre_esdh', 'plugins/cp/ArpService.class');
  if (isset($_GET['wsdl'])) {
    TraenPublishingDestinationSystemService::getWSDL($_GET['wsdl']);
    #error_log(' Her 1 ');
  }
  if (isset($_GET['xsd'])) {
    TraenPublishingDestinationSystemService::getXSD($_GET['xsd']);
    #error_log(' Her 2 ');
  }
  if (!lock_acquire(__FUNCTION__, 5)) {
    lock_wait(__FUNCTION__);
    #error_log(' Her 3 ');
    return os2web_acadre_esdh_cp_handle_request();
  }
  global $HTTP_RAW_POST_DATA;
  // Remove illegal XML characters.
  $data = preg_replace('/\&\#..F/', '', $HTTP_RAW_POST_DATA);
  if (variable_get('os2web_esdh_cp_provider_save_request', FALSE)) {
    file_unmanaged_save_data($data, 'public://soap/request-' . time() . '-' . uniqid() . '.xml', FILE_EXISTS_REPLACE);
  }
    #error_log(' Her 4 ');
  ini_set("soap.wsdl_cache_enabled", "1");
  $server = new SoapServer('http' . ((isset($_SERVER['HTTPS']) && $_SERVER['HTTPS'] === 'on') ? '' : '') . '://' . $_SERVER['SERVER_NAME'] . '/' . request_path() . '/?wsdl', array());
  $server->setObject(new TraenPublishingDestinationSystemService());
  $server->handle($data);
    #error_log(' Her 5 ');
  lock_release(__FUNCTION__);
}
