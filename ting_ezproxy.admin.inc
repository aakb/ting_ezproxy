<?php
/**
 * @file
 * @todo: Missing description.
 */


/**
 * Settings form for global ting_ezproxy customization.
 */
function ting_ezproxy_settings_form() {

  $form = array(
    '#tree' => TRUE,
  );

  $default = variable_get('ting_ezproxy', array());
  $form['ting_ezproxy'] = array(
    '#type' => 'fieldset',
    '#title' => t('Configuration'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['ting_ezproxy']['domain'] = array(
    '#type' => 'textfield',
    '#title' => t('Ezproxy domain'),
    '#description' => t('Domain for exproxy with http without ending slash'),
    '#default_value' => isset($default['domain']) ? $default['domain'] : 'http://someproxydomain',
  );

  $form['ting_ezproxy']['citizen'] = array(
    '#type' => 'textfield',
    '#title' => t('Citizen usergroup'),
    '#description' => t('Ezproxy group for citizen users'),
    '#default_value' => isset($default['citizen']) ? $default['citizen'] : 'citizengroup',
  );

  $form['ting_ezproxy']['secret'] = array(
    '#type' => 'textfield',
    '#title' => t('MD5 secret'),
    '#description' => t('Ezproxy MD5 secret for ticket constrution'),
    '#default_value' => isset($default['secret']) ? $default['secret'] : 'megethemmeligkode123',
  );

  $form['ting_ezproxy']['category'] = array(
    '#type' => 'textfield',
    '#title' => t('Library: categories where citizen belong to'),
    '#description' => t('List of categories where citizen belong to'),
    '#default_value' => isset($default['category']) ? $default['category'] : '01,02,03',
  );

  $form['ting_ezproxy']['block'] = array(
    '#type' => 'textfield',
    '#title' => t('Library: list of blockkode not allowed'),
    '#description' => t('List of blockkode not allowed'),
    '#default_value' => isset($default['block']) ? $default['block'] : '',
  );

  $form['ting_ezproxy']['text_anonymous'] = array(
    '#type' => 'textarea',
    '#title' => t('Text for anonymous users'),
    '#default_value' => isset($default['text_anonymous']) ? $default['text_anonymous'] : '',
    '#cols' => 60,
    '#rows' => 5,
    '#description' => t('This are shown with loginform - use @loginform for that'),
  );

  $form['ting_ezproxy']['text_loggedin'] = array(
    '#type' => 'textarea',
    '#title' => t('Text for logged in users'),
    '#default_value' => isset($default['text_loggedin']) ? $default['text_loggedin'] : '',
    '#cols' => 60,
    '#rows' => 5,
    '#description' => t('This are the last text shown with tokenurl - use @tokenurl for that'),
  );

  $form['ting_ezproxy']['loggedin_time'] = array(
    '#type' => 'textfield',
    '#title' => t('Time to show loggedin-page'),
    '#description' => t('Integer: wait n secounds before automatic redirect. Use 0 to redirect immediately and -1 to disable'),
    '#default_value' => isset($default['loggedin_time']) ? $default['loggedin_time'] : '10',
  );

  $form['ting_ezproxy']['text_wrongcategory'] = array(
    '#type' => 'textarea',
    '#title' => t('Text for users in wrong category'),
    '#default_value' => isset($default['text_wrongcategory']) ? $default['text_wrongcategory'] : '',
    '#cols' => 60,
    '#rows' => 5,
    '#description' => t('This text will show for logged in users with wrong category'),
  );

  $form['ting_ezproxy']['text_error'] = array(
    '#type' => 'textarea',
    '#title' => t('Text for error of some kind'),
    '#default_value' => isset($default['text_error']) ? $default['text_error'] : '',
    '#cols' => 60,
    '#rows' => 5,
    '#description' => t('This text will show for users who are blocked or because of other error'),
  );

  return system_settings_form($form);
}
