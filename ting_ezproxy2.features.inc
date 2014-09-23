<?php
/**
 * @file
 * ting_ezproxy2.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ting_ezproxy2_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "pm_existing_pages" && $api == "pm_existing_pages") {
    return array("version" => "1");
  }
}
