/* 
 * File:   ecual_button.c
 * Author: mohammed_ali
 *
 * Created on December 2, 2023, 6:01 PM
 */

/*section:***********includes*******************************/
#include "ecual_button.h"
/*section:*********functions definition*****************/

/**
 * @breif initialization button function 
 * @param button pointer to button configuration 
 *@return status of the function 
            (E_OK) the function done successfully 
            (E_NOT_OK) the function has issue to do the action  
 */
Std_ReturnType button_intialization (button_confg_t*button) {
     Std_ReturnType ret =E_OK   ;
   
   if(NULL==button){
       ret =E_NOT_OK ;
       
   }
   else {
       pin_confg_t pin_confg ={.port=button->button_port ,.pin=button->button_pin ,.direction=INPUT ,.logic =button->button_active_status};
    
   ret= gpio_pin_direction_initalize(&pin_confg) ;
    
   }
     return ret ;
    
}
/**
 * @breif read button status function 
 * @param button pointer to button configuration 
 * @param button_status return button status 
 * @return status of the function 
            (E_OK) the function done successfully 
            (E_NOT_OK) the function has issue to do the action 
 */
Std_ReturnType button_read_status (button_confg_t*button ,button_state_t*button_status ) {
    Std_ReturnType ret =E_OK   ;
    
    if ((NULL==button )||(NULL==button_status)){
    
    ret = E_NOT_OK ;
    
    }
    
    else {
         pin_confg_t pin_confg ={.port=button->button_port ,.pin=button->button_pin ,.direction=INPUT ,.logic =button->button_active_status};
         logic_t pin_logic =LOW;
       ret=  gpio_pin_read_logic(&pin_confg ,& pin_logic) ;
       switch(button->button_active_status){
           case   BUTTON_ACTIVE_LOW :
               
               if( pin_logic==LOW){
                   *button_status = BUTTON_PRESSED ;
                   
               }
               else {
                   *button_status = BUTTON_RELEASED ;
                   
               }
               break ;
               
           case BUTTON_ACTIVE_HIGH :
               
               if( pin_logic==HIGH){
                   *button_status = BUTTON_PRESSED ;
                   
               }
               else {
                   *button_status = BUTTON_RELEASED ;
                   
               }
               break ;
           
           default :
               ret = E_NOT_OK ;
               break ;
               
       }
         
        
        
    }
    
    return ret ;
    
    
}