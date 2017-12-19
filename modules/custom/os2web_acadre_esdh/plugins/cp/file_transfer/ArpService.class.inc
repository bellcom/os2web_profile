<?php

/**
 * @file
 * The Class extends the ARP service.
 */

/**
 * Class that holds the service.
 *
 * @TODO This object need should be refactored to interface and
 * implementation structure.
 */
class ArpService {
  /**
   * Dumps the wsdl for the serivce.
   */
  public static function getWSDL($wsdl = FALSE) {
    if ($wsdl) {
      $wsdl = str_replace('wsdl', '', $wsdl);
      $filename = 'FormpipeOMDestinationSystemFileService' . check_plain($wsdl + 1) . '.wsdl';
    }
    else {
      $filename = 'FormpipeOMDestinationSystemFileService.wsdl';
    }
    self::echoFile($filename);
  }

  /**
   * Dumps an xsd for the serivce.
   */
  public static function getXSD($xsd = FALSE) {
    if ($xsd) {
      $xsd = str_replace('xsd', '', $xsd);
      $filename = 'FormpipeOMDestinationSystemFileService' . check_plain($xsd + 1) . '.xsd';
    }
    else {
      $filename = 'FormpipeOMDestinationSystemFileService.xsd';
    }
    self::echoFile($filename);
  }

  /**
   * Echoes specified file.
   */
  private static function echoFile($filename) {
    $filename = dirname(__FILE__) . DIRECTORY_SEPARATOR . $filename;
    if (!file_exists($filename)) {
      drupal_not_found();
    }
    $handle = fopen($filename, 'r');
    $contents = fread($handle, filesize($filename));
    fclose($handle);

    drupal_add_http_header('Connection', 'close', FALSE);
    drupal_add_http_header('Content-Length', drupal_strlen($contents), TRUE);
    drupal_add_http_header('Content-Type', 'text/plain; charset=utf-8', TRUE);
    drupal_add_http_header('Date', date('r'), TRUE);

    echo format_string($contents, array(
      '!endpointurl' => 'http' . ((isset($_SERVER['HTTPS']) && $_SERVER['HTTPS'] === 'on') ? 's' : '') . '://' . $_SERVER['SERVER_NAME'] . '/' . request_path(),
    ));
    exit;
  }

  /************ PUBLIC API ***************/

  public function __call($name, $arguments) {
    watchdog('os2web_acadre_esdh', 'Unsupported request recieved: %req', array('%req' => $name), WATCHDOG_NOTICE);
  }
}
