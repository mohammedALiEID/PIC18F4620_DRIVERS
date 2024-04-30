/* 
 * File:   ecual_seven_segment.c
 * Author: sayr3
 *
 * Created on December 16, 2023, 7:46 PM
 */
/*section ***include ******************/
#include "ecual_seven_segment.h"

/*section ***global variables ******************/
/**
 * @brief initialize seven segment configuration
 * @param s_segment pointer to seven_segment configuration 
 * @return status of the function 
            (E_OK) the function done successfully 
            (E_NOT_OK) the function has issue to do the action
 */
Std_ReturnType  seven_segment_initialization (const seven_segment_t*s_segment ) {
    
    Std_ReturnType ret = E_OK  ; 
    if (NULL==s_segment){
        
      ret=ret = E_NOT_OK ;   
        
    }
    else {
        ret =gpio_pin__ALL_initaliztion(&(s_segment->seven_segment_pin[0])) ;
        ret =gpio_pin__ALL_initaliztion(&(s_segment->seven_segment_pin[1])) ;
        ret =gpio_pin__ALL_initaliztion(&(s_segment->seven_segment_pin[2])) ;
        ret =gpio_pin__ALL_initaliztion(&(s_segment->seven_segment_pin[3])) ;
        
        
        
    }
    
    return ret ; 
    
    
}
/**
 * @breif write number on seven segment 
 * @param s_segment pointer to seven_segment configuration 
 * @param number the number value 
 * @return status of the function 
            (E_OK) the function done successfully 
            (E_NOT_OK) the function has issue to do the action 
 */
Std_ReturnType  seven_segment_write_number (const seven_segment_t*s_segment  , uint_8 number) {
    
    Std_ReturnType ret = E_OK  ; 
    if ((NULL==s_segment)||(number>9)){
        
      ret=ret = E_NOT_OK ;   
        
    }
    else {
        
      ret= gpio_pin_write_logic (&(s_segment->seven_segment_pin[0]),(number&0x1)) ;
      ret= gpio_pin_write_logic (&(s_segment->seven_segment_pin[1]),((number>>1)&0x1)) ;
      ret= gpio_pin_write_logic (&(s_segment->seven_segment_pin[2]),((number>>2)&0x1)) ;
      ret= gpio_pin_write_logic (&(s_segment->seven_segment_pin[3]),((number>>3)&0x1)) ;
        
        
        
        
        
    }
    
    return ret ; 
    
    
}