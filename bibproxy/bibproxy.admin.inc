<?php

// $Id: bibproxy.admin.inc,v 1.2.2.6 2010/07/14 02:29:42 ferdi Exp $


/**
 * Settings form for global bibproxy custimazation 
 */
function bibproxy_settings_form(){

  $form = array(
    '#tree' => TRUE
  );

  $default = variable_get('bibproxy', array());
  $form['bibproxy'] = array(
    '#type' => 'fieldset',
    '#title' => t('Configuration'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['bibproxy']['domain'] = array(
    '#type' => 'textfield',
    '#title' => t('Ezproxy domain'),
    '#description' => t('Domain for exproxy with http without ending slash'),
    '#default_value' => isset($default['domain']) ? $default['domain'] : 'http://someproxydomain',
  );
/*  $form['bibproxy']['loggedin'] = array(
    '#type' => 'textfield',
    '#title' => t('Logged-in usergroup'),
    '#description' => t('Ezproxy group for logged-in users'),
    '#default_value' => isset($default['loggedin']) ? $default['loggedin'] : 'loggedingroup',    
  );
*/
  $form['bibproxy']['citizen'] = array(
    '#type' => 'textfield',
    '#title' => t('Citizen usergroup'),
    '#description' => t('Ezproxy group for citizen users'),
    '#default_value' => isset($default['citizen']) ? $default['citizen'] : 'citizengroup',    
  );
  $form['bibproxy']['secret'] = array(
    '#type' => 'textfield',
    '#title' => t('MD5 secret'),
    '#description' => t('Ezproxy MD5 secret for ticket constrution'),
    '#default_value' => isset($default['secret']) ? $default['secret'] : 'megethemmeligkode123',    
  );  

  $form['bibproxy']['category'] = array(
    '#type' => 'textfield',
    '#title' => t('Library: categories where citizen belong to'),
    '#description' => t('List of categories where citizen belong to'),
    '#default_value' => isset($default['category']) ? $default['category'] : '01,02,03',    
  );   
  $form['bibproxy']['block'] = array(
    '#type' => 'textfield',
    '#title' => t('Library: list of blockkode not allowed'),
    '#description' => t('List of blockkode not allowed'),
    '#default_value' => isset($default['block']) ? $default['block'] : '',    
  );

  $form['bibproxy']['text_anonymous'] = array(
    '#type' => 'textarea',
    '#title' => t('Text for anonymous users'),
    '#default_value' =>  isset($default['text_anonymous']) ? $default['text_anonymous'] : '',    
    '#cols' => 60,
    '#rows' => 5,
    '#description' => t('This are shown with link to loginform - use @loginurl for that'),
  );  
  
  $form['bibproxy']['text_loggedin'] = array(
    '#type' => 'textarea',
    '#title' => t('Text for logged in users'),
    '#default_value' =>  isset($default['text_loggedin']) ? $default['text_loggedin'] : '',    
    '#cols' => 60,
    '#rows' => 5,
    '#description' => t('This are the last text shown with tokenurl - use @tokenurl for that'),
  );  

  $form['bibproxy']['text_wrongcategory'] = array(
    '#type' => 'textarea',
    '#title' => t('Text for users in wrong category'),
    '#default_value' =>  isset($default['text_wrongcategory']) ? $default['text_wrongcategory'] : '',    
    '#cols' => 60,
    '#rows' => 5,
    '#description' => t('This text will show for logged in users with wrong category'),
  );    
  
  $form['bibproxy']['text_error'] = array(
    '#type' => 'textarea',
    '#title' => t('Text for error of some kind'),
    '#default_value' =>  isset($default['text_error']) ? $default['text_error'] : '',    
    '#cols' => 60,
    '#rows' => 5,
    '#description' => t('This text will show for users who are blocked or because of other error'),
  ); 
  
  

  return system_settings_form($form);
}
