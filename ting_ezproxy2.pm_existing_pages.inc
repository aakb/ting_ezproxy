<?php
/**
 * @file
 * ting_ezproxy2.pm_existing_pages.inc
 */

/**
 * Implements hook_pm_existing_pages_info().
 */
function ting_ezproxy2_pm_existing_pages_info() {
  $export = array();

  $pm_existing_page = new stdClass();
  $pm_existing_page->api_version = 1;
  $pm_existing_page->name = 'ting_ezproxy';
  $pm_existing_page->label = 'Ting EZproxy';
  $pm_existing_page->context = 'entity|node|nid';
  $pm_existing_page->paths = 'ting_ezproxy_authentication';
  $export['ting_ezproxy'] = $pm_existing_page;

  return $export;
}
