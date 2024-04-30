/* 
 * File:   ecual_relay.c
 * Author: mohammed_ali
 *
 * Created on December 13, 2023, 2:33 am
 */

/*section:***********includes*******************************/
#include "ecual_relay.h"

/*section:*********functions definition*****************/

/**
 * initialize the relay
 * @param relay pointer to relay configuration 
 *@return status of the function 
            (E_OK) the function done successfully 
            (E_NOT_OK) the function has issue to do the action 
 */
 
Std_ReturnType relay_initialization (const relay_t*relay) {
    Std_ReturnType ret = E_OK ;
    if(relay==NULL){
        
        ret =  E_NOT_OK ;
        
    }
    else {
        pin_confg_t pin_confg ={.port=relay->port_index , .pin=relay->pin_index , .direction = OUTPUT ,.logic=LOW};
        
        
        gpio_pin__ALL_initaliztion(&pin_confg) ;
        
        
    }
    
    return ret ;
}
/**
 * @breif   energize the relay 
 * @param relay pointer to relay configuration 
 * @return status of the function 
            (E_OK) the function done successfully 
            (E_NOT_OK) the function has issue to do the action 
 */
 
Std_ReturnType relay_energization (const relay_t*relay) {
    
    Std_ReturnType ret = E_OK ;
    if(relay==NULL){
        
        ret =  E_NOT_OK ;
        
    }
    else {
        pin_confg_t pin_confg ={.port=relay->port_index , .pin=relay->pin_index , .direction = OUTPUT ,.logic=LOW};
        
        
        gpio_pin_write_logic(&pin_confg , HIGH) ;
        
        
    }
    
    return ret ;
    
    
    
    
    
    
}
/**
 * @breif deenergize the relay 
 * @param relay pointer to relay configuration 
 * @return @return status of the function 
            (E_OK) the function done successfully 
            (E_NOT_OK) the function has issue to do the action 
 */
 
Std_ReturnType relay_deenergization (const relay_t*relay) {
    
    Std_ReturnType ret = E_OK ;
    if(relay==NULL){
        
        ret =  E_NOT_OK ;
        
    }
    else {
        pin_confg_t pin_confg ={.port=relay->port_index , .pin=relay->pin_index , .direction = OUTPUT ,.logic=LOW};
        
        
        gpio_pin_write_logic(&pin_confg , LOW) ;
        
        
    }
    
    return ret ;
    
    
}