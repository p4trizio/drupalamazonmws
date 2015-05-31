<?php


/**
 * Implements hook_menu() - This is for the configuration file at admin/config/amazonmws.
 */
function amazonmws_menu() {
  $items = array();

  $items['admin/config/amazonmws'] = array(
    'title' => 'AmazonMWS',
    'description' => 'Configuration for AmazonMWS Integration',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('amazonmws_form'),
    'access arguments' => array('access administration pages'),
    'type' => MENU_NORMAL_ITEM,
  );

  return $items;
}

/**
 * Page callback: 
 *
 * @see amazonmws_menu()
 */

function amazonmws_form($form, &$form_state) {
  $form['amazonmws_sellerid'] = array(
    '#type' => 'textfield',
    '#title' => t('Seller ID'),
    '#default_value' => variable_get('amazonmws_sellerid', "TEST"),
    '#size' => 50,
    '#maxlength' => 50,
    '#description' => t('Your Amazon Seller ID.'),
    '#required' => TRUE,
  );
  $form['amazonmws_marketplaceid'] = array(
    '#type' => 'textfield',
    '#title' => t('Marketplace ID'),
    '#default_value' => variable_get('amazonmws_marketplaceid', "TEST"),
    '#size' => 50,
    '#maxlength' => 50,
    '#description' => t('The Marketplace ID, each platform (es, uk, fr, etc) has a different Marketplace ID.'),
    '#required' => TRUE,
  );
  $form['amazonmws_accesskeyid'] = array(
    '#type' => 'textfield',
    '#title' => t('MWS Access Key ID'),
    '#default_value' => variable_get('amazonmws_accesskeyid', "TEST"),
    '#size' => 50,
    '#maxlength' => 50,
    '#description' => t('Access key ID needed to authenticate.'),
    '#required' => TRUE,
  );
  $form['amazonmws_secretkey'] = array(
    '#type' => 'textfield',
    '#title' => t('MWS Secret Key'),
    '#default_value' => variable_get('amazonmws_secretkey', "TEST"),
    '#size' => 50,
    '#maxlength' => 50,
    '#description' => t('Secret key needed to authenticate.'),
    '#required' => TRUE,
  ); 
  $form['amazonmws_appname'] = array(
    '#type' => 'textfield',
    '#title' => t('Application Name'),
    '#default_value' => variable_get('amazonmws_appname', "TEST"),
    '#size' => 50,
    '#maxlength' => 50,
    '#description' => t('Application name recorded on AmazonMWS records e.g. DrupalforExampleStore'),
    '#required' => TRUE,
  );
  $form['amazonmws_appversion'] = array(
    '#type' => 'textfield',
    '#title' => t('Application Version'),
    '#default_value' => variable_get('amazonmws_appversion', "TEST"),
    '#size' => 50,
    '#maxlength' => 50,
    '#description' => t('Application version recorded on AmazonMWS records e.g. 1.02'),
    '#required' => TRUE,
  );
  $form['amazonmws_serviceurl'] = array(
    '#type' => 'textfield',
    '#title' => t('Service URL'),
    '#default_value' => variable_get('amazonmws_serviceurl', "TEST"),
    '#size' => 50,
    '#maxlength' => 50,
    '#description' => t('Service url, e.g. https://mws-eu.amazonservices.com,or https://mws.amazonservices.ca - view http://docs.developer.amazonservices.com/en_UK/dev_guide/DG_Endpoints.html and
     http://docs.developer.amazonservices.com/en_UK/orders/2013-09-01/Orders_Overview.html'),
    '#required' => TRUE,
  );
    $form['amazonmws_serviceurlfeeds'] = array(
    '#type' => 'textfield',
    '#title' => t('Service URL'),
    '#default_value' => variable_get('amazonmws_serviceurlfeeds', "TEST"),
    '#size' => 50,
    '#maxlength' => 50,
    '#description' => t('Service url, e.g. https://mws-eu.amazonservices.com,or https://mws.amazonservices.ca - view http://docs.developer.amazonservices.com/en_UK/feeds/Feeds_Overview.html'),
    '#required' => TRUE,
  );
  return system_settings_form($form);
}
