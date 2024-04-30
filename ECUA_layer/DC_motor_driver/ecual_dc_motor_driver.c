/* 
 * File:   ecual_dc_motor_driver.c
 * Author: sayr3
 *
 * Created on December 13, 2023, 11:56 PM
 */
 
/*section:***********includes*******************************/
#include "ecual_dc_motor_driver.h"

/*section:*********functions definition*****************/

/**
 * @breif initialize motor  
 * @param _motor pointer to motor configuration 
 *@return status of the function 
            (E_OK) the function done successfully 
            (E_NOT_OK) the function has issue to do the action 
 */


Std_ReturnType motor_driver_intialization (const motor_t*_motor) {
     Std_ReturnType ret = E_OK ;
    if(_motor==NULL){
        
        ret =  E_NOT_OK ;
        
    }
    else {
        
        ret = gpio_pin__ALL_initaliztion (&(_motor->motor_pin[0]));
        ret = gpio_pin__ALL_initaliztion (&(_motor->motor_pin[1]));
    }
    
    return ret ;
    
    
}
/**
 * @breif move motor forward
 * @param _motor pointer to motor configuration 
 *@return status of the function 
            (E_OK) the function done successfully 
            (E_NOT_OK) the function has issue to do the action 
 */
Std_ReturnType motor_driver_forward (const motor_t*_motor) {
    Std_ReturnType ret = E_OK ;
    if(_motor==NULL){
        
        ret =  E_NOT_OK ;
        
    }
    else {
     
        ret = gpio_pin_write_logic(&(_motor->motor_pin[0]) ,HIGH) ;
        ret = gpio_pin_write_logic(&(_motor->motor_pin[1]) ,LOW) ;
        
        
        
    }
    
    return ret ;
    
    
    
}
/**
 * @breif move motor backward
 * @param _motor pointer to motor configuration 
 *@return status of the function 
            (E_OK) the function done successfully 
            (E_NOT_OK) the function has issue to do the action 
 */
Std_ReturnType motor_driver_backward (const motor_t*_motor) {
    Std_ReturnType ret = E_OK ;
    if(_motor==NULL){
        
        ret =  E_NOT_OK ;
        
    }
    else {
      
       ret = gpio_pin_write_logic(&(_motor->motor_pin[0]) ,LOW) ;
        ret = gpio_pin_write_logic(&(_motor->motor_pin[1]) ,HIGH) ;
        
        
        
        
        
    }
    
    return ret ;
    
    
    
}
/**
 * @breif stop motor 
 * @param _motor pointer to motor configuration 
 *@return status of the function 
            (E_OK) the function done successfully 
            (E_NOT_OK) the function has issue to do the action 
 */
Std_ReturnType motor_driver_stop (const motor_t*_motor) {
    
    Std_ReturnType ret = E_OK ;
    if(_motor==NULL){
        
        ret =  E_NOT_OK ;
        
    }
    else {
      
       
       ret = gpio_pin_write_logic(&(_motor->motor_pin[0]) ,LOW) ;
        ret = gpio_pin_write_logic(&(_motor->motor_pin[1]) ,LOW) ;
        
        
        
        
        
    }
    
    return ret ;
    
    
}
