/* 
 * File:   ECUAL_led.c
 * Author: mohammed_ali
 *
 * Created on December 2, 2023, 6:01 PM
 */

/*section:***********includes*******************************/
#include "ECUAL_led.h"
/*section:*********functions definition*****************/


/**
 * @breif initialize the led 
 * @param led_confg LED module configuration
 * @return status of the function 
            (E_OK) the function done successfully 
            (E_NOT_OK) the function has issue to do the action  
 */
Std_ReturnType led_intialize (const led_confg_t *led_confg) {
   Std_ReturnType ret =E_OK   ;
   
   if(NULL==led_confg){
       ret =E_NOT_OK ;
       
   }
   else {
      pin_confg_t pin_confg ={.port=led_confg->port_index , .pin=led_confg->pin_index,
                           .direction=OUTPUT,.logic=led_confg->led_status };

       gpio_pin__ALL_initaliztion(&pin_confg) ;
       
       
       
       
       
       
   }
    
   return ret ;
    
}
/**
 * @breif turn on the led 
 * @param led_confg LED module configuration
 * @return status of the function 
            (E_OK) the function done successfully 
            (E_NOT_OK) the function has issue to do the action 
 */
Std_ReturnType led_turn_on(const led_confg_t *led_confg) {
    Std_ReturnType ret =E_OK   ;
   if(NULL==led_confg){
       ret =E_NOT_OK ;
       
   }
   else {
       pin_confg_t pin_confg ={.port=led_confg->port_index , .pin=led_confg->pin_index,
                           .direction=OUTPUT,.logic= led_confg->led_status };
gpio_pin_write_logic(& pin_confg ,HIGH ) ;
       
   }
    
   return ret ;
    
    
}
/**
 * @breif turn off the led 
 * @param led_confg LED module configuration
 * @return status of the function 
            (E_OK) the function done successfully 
            (E_NOT_OK) the function has issue to do the action 
 */
Std_ReturnType led_turn_off(const led_confg_t *led_confg) {
    Std_ReturnType ret =E_OK   ;
   if(NULL==led_confg){
       ret =E_NOT_OK ;
       
   }
   else {
        pin_confg_t pin_confg ={.port=led_confg->port_index , .pin=led_confg->pin_index,
                           .direction=OUTPUT,.logic= led_confg->led_status };
gpio_pin_write_logic(& pin_confg ,LOW ) ;
       
   }
    
   return ret ;
    
    
}
/**
 * @breif toggle  the led  status
 * @param led_confg LED module configuration
 *@return status of the function 
            (E_OK) the function done successfully 
            (E_NOT_OK) the function has issue to do the action 
 */
Std_ReturnType led_turn_toggle(const led_confg_t *led_confg) {
   Std_ReturnType ret =E_OK   ;
   if(NULL==led_confg){
       ret =E_NOT_OK ;
       
   }
   else {
        pin_confg_t pin_confg ={.port=led_confg->port_index , .pin=led_confg->pin_index,
                           .direction=OUTPUT,.logic= led_confg->led_status };
gpio_pin_toggle_logic(&pin_confg ) ;
       
   }
    
   return ret ; 
    
    
}
