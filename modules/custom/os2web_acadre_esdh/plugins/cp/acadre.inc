<?php
/**
 * @file
 * This file describes the Content pushing plugin as implemented by Acadre.
 */

/**
 * Plugin definition with callbacks.
 */
$plugin = array(
  'description' => t('Acadre ESDH Case Pushing backend'),
  'version' => 1,
  'handle_request' => 'os2web_acadre_esdh_cp_handle_request',
);

/**
 * This functions handles a request on the webservice API.
 *
 * @param string $ws_type
 *   The type of requested webservice.
 *
 * @return mixed
 *   Depends on request url and arguments return different data or actions.
 */
function os2web_acadre_esdh_cp_handle_request($ws_type = 'metadata') {
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

  // Load ARP Service Class based on $ws_type argument.
  switch ($ws_type) {
    case 'metadata':
      $class_name = 'ArpService';
      break;

    case 'file_transfer':
      $class_name = 'ArpServiceFileTransfer';
      break;
  }
  module_load_include('inc', 'os2web_acadre_esdh', 'plugins/cp/' . $ws_type . '/' . $class_name . '.class');

  if (isset($_GET['wsdl'])) {
    $class_name::getWSDL($_GET['wsdl']);
  }
  if (isset($_GET['xsd'])) {
    $class_name::getXSD($_GET['xsd']);
  }
  if (!lock_acquire(__FUNCTION__, 5)) {
    lock_wait(__FUNCTION__);
    return os2web_acadre_esdh_cp_handle_request();
  }

  global $HTTP_RAW_POST_DATA;

  // Remove illegal XML characters.
  $data = preg_replace('/\&\#..F/', '', $HTTP_RAW_POST_DATA);
  if (variable_get('os2web_esdh_cp_provider_save_request', FALSE)) {
    file_unmanaged_save_data($data, 'public://soap/request-' . time() . '-' . uniqid() . '.xml', FILE_EXISTS_REPLACE);
  }

  ini_set("soap.wsdl_cache_enabled", "1");
  $server = new SoapServer('http' . ((isset($_SERVER['HTTPS']) && $_SERVER['HTTPS'] === 'on') ? '' : '') . '://' . $_SERVER['SERVER_NAME'] . '/' . request_path() . '/?wsdl', array());
  $server->setObject(new $class_name());
  $server->handle($data);
  lock_release(__FUNCTION__);
}
