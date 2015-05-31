<?php
  
   if (!defined('DATE_FORMAT')){
       define ('DATE_FORMAT', 'Y-m-d\TH:i:s\Z');
   }

   /************************************************************************
    * REQUIRED
    *
    * * Access Key ID and Secret Acess Key ID, obtained from:
    * http://aws.amazon.com
    *
    * IMPORTANT: Your Secret Access Key is a secret, and should be known
    * only by you and AWS. You should never include your Secret Access Key
    * in your requests to AWS. You should never e-mail your Secret Access Key
    * to anyone. It is important to keep your Secret Access Key confidential
    * to protect your account.

    * DRUPAL AMAZON MWS: Do not change access keys here. They are changed inside Drupal.
    * View amazonmws configuration 
    ***********************************************************************/
       if (!defined('AWS_ACCESS_KEY_ID')){
            define('AWS_ACCESS_KEY_ID', variable_get('amazonmws_accesskeyid', "TEST"));
            ;
        }
       if (!defined('AWS_SECRET_ACCESS_KEY')){
            define('AWS_SECRET_ACCESS_KEY', variable_get('amazonmws_secretkey', "TEST"));
        }


   /************************************************************************
    * REQUIRED
    * 
    * All MWS requests must contain a User-Agent header. The application
    * name and version defined below are used in creating this value.
    ***********************************************************************/
       if (!defined('APPLICATION_NAME')){
            define('APPLICATION_NAME', variable_get('amazonmws_appname', "TEST"));
        }
       if (!defined('APPLICATION_VERSION')){
            define('APPLICATION_VERSION', variable_get('amazonmws_appversion', "TEST"));
        }
   /************************************************************************
    * REQUIRED
    * 
    * All MWS requests must contain the seller's merchant ID and
    * marketplace ID.
    ***********************************************************************/
       if (!defined('MERCHANT_ID')){
            define('MERCHANT_ID',variable_get('amazonmws_sellerid', "TEST"));
        }
       if (!defined('MARKETPLACE_ID')){
            define('MARKETPLACE_ID',variable_get('amazonmws_marketplaceid', "TEST"));
        }
   /************************************************************************ 
    * OPTIONAL ON SOME INSTALLATIONS
    *
    * Set include path to root of library, relative to current directory.
    * Only needed when running library from local directory.
    * If library is installed in PHP include path, this is not needed
    ***********************************************************************/   
    set_include_path(dirname(dirname(dirname(__FILE__))));  
    
   /************************************************************************ 
    * OPTIONAL ON SOME INSTALLATIONS  
    * 
    * Autoload function is reponsible for loading classes of the library on demand
    * 
    * NOTE: Only one __autoload function is allowed by PHP per each PHP installation,
    * and this function may need to be replaced with individual require_once statements
    * in case where other framework that define an __autoload already loaded.
    * 
    * However, since this library follow common naming convention for PHP classes it
    * may be possible to simply re-use an autoload mechanism defined by other frameworks
    * (provided library is installed in the PHP include path), and so classes may just 
    * be loaded even when this function is removed
    ***********************************************************************/   
/*     function __autoload($className){
 *       $filePath = str_replace('_', DIRECTORY_SEPARATOR, $className) . '.php';
 *       $includePaths = explode(PATH_SEPARATOR, get_include_path());
 *       foreach($includePaths as $includePath){
 *           if(file_exists($includePath . DIRECTORY_SEPARATOR . $filePath)){
 *               require_once $filePath;
 *               return;
 *           }
 *       }
 *   }
*/

/*Instead of using autoload, we will use this to include the necessary classes, using the dirname()*/

$base=dirname(dirname(__FILE__));
$includes = array(
   $base.'/Client.php',
   $base.'/Exception.php',
   $base.'/Interface.php',
   $base.'/Mock.php',
   $base.'/Model.php',
   //the following are in the Model folder  
   $base.'/Model/Address.php',
   $base.'/Model/GetOrderRequest.php',
   $base.'/Model/GetOrderResponse.php',
   $base.'/Model/GetOrderResult.php',
   $base.'/Model/GetServiceStatusRequest.php',
   $base.'/Model/GetServiceStatusResponse.php',
   $base.'/Model/GetServiceStatusResult.php',
   $base.'/Model/InvoiceData.php',
   $base.'/Model/ListOrderItemsByNextTokenRequest.php',
   $base.'/Model/ListOrderItemsByNextTokenResponse.php',
   $base.'/Model/ListOrderItemsByNextTokenResult.php',
   $base.'/Model/ListOrderItemsRequest.php',
   $base.'/Model/ListOrderItemsResponse.php',
   $base.'/Model/ListOrderItemsResult.php',
   $base.'/Model/ListOrdersByNextTokenRequest.php',
   $base.'/Model/ListOrdersByNextTokenResponse.php',
   $base.'/Model/ListOrdersByNextTokenResult.php',
   $base.'/Model/ListOrdersRequest.php',
   $base.'/Model/ListOrdersResponse.php',
   $base.'/Model/ListOrdersResult.php',
   $base.'/Model/Message.php',
   $base.'/Model/Money.php',
   $base.'/Model/OrderItem.php',
   $base.'/Model/Order.php',
   $base.'/Model/PaymentExecutionDetailItem.php',
   $base.'/Model/ResponseHeaderMetadata.php',
   $base.'/Model/ResponseMetadata.php',
);


foreach($includes as $file) {
     require_once $file;
}
  



