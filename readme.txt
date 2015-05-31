This module provides you with a set of rules and actions to sync your Ubercart shop with Amazon MWS.
It creates a database table of incoming Amazon orders, such that those orders are copied to Ubercart 
and assigned to a user of your choosing. The orders can be in two states, processed and copied to the site.
It uses PHP libraries provided by Amazon. The two current libraries at use are Orders and Feeds.
The module also provides ways of syncing updates back to Amazon. It creates a database table to mark
SKUs if their price or stock has been updated, or both.

Note that the module will place orders. Adjusting stock as a result of those orders is already possible,
and that is not the responsibility of this module.


The rules events provided are as follows:

Stock of a product is adjusted: it provides the SKU, the stock level before adjustment, and the amount by which it was changed.
Stock of a product is set: it provides the SKU, the stock level before adjustment, and the amount to which it was set.
MWS Cron is run: you can invoke this through rules_invoke_event('amazonmws_mws_cron') in a page or in a module such as Elysia cron.

The rules actions provided are as follows:
Push sku into a list of skus whose price has been updated.
Push sku into a list of skus whose stock has been updated.
Pull sku from a list of skus whose price has been updated.
Pull sku from a list of skus whose stock has been updated.
Download recent amazon orders that will later be copied to Ubercart orders.
Create Drupal orders for available products, from downloaded orders.
Set a stock to a quantity using a node id.
Upload all changed prices from marked skus to amazon.
Upload all changed stock quantities from marked skus to amazon.
Clear the list of updated prices to upload to amazon.
Clear the list of updated stocks to upload to amazon.

THIS MODULE INCLUDES A SETTINGS PAGE WHERE YOU CAN INPUT YOUR AMAZON SELLER ID, MARKETPLACE ID, KEY ID, SECRET KEY AND AMAZON ENDPOINTS.


FOR STOCK SET TO WORK, YOU NEED TO CHANGE THE UC_STOCK_SET FUNCTION IN UC_STOCK.MODULE.
EXAMPLE:

function uc_stock_set($sku, $qty) {
$stock=0;  
db_update('uc_product_stock')
    ->fields(array('stock' => $qty))
    ->condition('sku', $sku)
    ->execute();
    if(function_exists("amazonmws_ucstockset")){
        amazonmws_ucstockset($sku,0,$qty);
        }
}

FOR STOCK SET TO WORK, YOU NEEDO TO CHANGE UC_STOCK_EDIT_FORM_SUBMIT FUNCTION IN UC_STOCK.ADMIN.INC
EXAMPLE:

function uc_stock_edit_form_submit($form, &$form_state) {
  foreach (element_children($form_state['values']['stock']) as $id) {
    $stock = $form_state['values']['stock'][$id];

    db_merge('uc_product_stock')
      ->key(array('sku' => $stock['sku']))
      ->updateFields(array(
        'active' => $stock['active'],
        'stock' => $stock['stock'],
        'threshold' => $stock['threshold'],
      ))
      ->insertFields(array(
        'sku' => $stock['sku'],
        'active' => $stock['active'],
        'stock' => $stock['stock'],
        'threshold' => $stock['threshold'],
        'nid' => $form_state['values']['nid'],
      ))
      ->execute();
$sku=$stock['sku'];
$stk=$stock['stock'];

if(function_exists("amazonmws_ucstockset")){
amazonmws_ucstockset($sku, 0, $stk);
}


FOR THE STOCK ADJUSTED TO WORK, YOU NEED TO CHANGE THE UC_STOCK_ADJUST FUNCTION IN UC_STOCK.MODULE
EXAMPLE:

function uc_stock_adjust($sku, $qty, $check_active = TRUE) {
  $stock = db_query("SELECT active, stock FROM {uc_product_stock} WHERE sku = :sku", array(':sku' => $sku))->fetchObject();

  if ($check_active) {
    if (!$stock || !$stock->active) {
      return;
    }
  }

  db_update('uc_product_stock')
    ->expression('stock', 'stock + :qty', array(':qty' => $qty))
    ->condition('sku', $sku)
    ->execute();
if(function_exists("amazonmws_ucstockadjusted")){
amazonmws_ucstockadjusted($sku,$stock->stock,$qty);
}
module_invoke_all('uc_stock_adjusted');
}


