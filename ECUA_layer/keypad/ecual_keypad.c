
/* 
 * File:   ecual_keypad.c
 * Author: sayr3
 *
 * Created on December 17, 2023, 10:55 PM
 */ 

/*section:***********includes*******************************/
#include "ecual_keypad.h"

/*section:*********functions definition*****************/


uint_8 keypad_symbols[keypad_rows_pins_number][keypad_coloumns_pins_number]={{'7','8','9','%'},
                                                                             {'4','5','6','x'},
                                                                             {'1','2','3','-'},
                                                                             {'&','0','=','+'}};



/**
 * @breif initialize the keypad pins 
 * @param keypad  pointer to keypad configuration 
 * @return status of the function 
            (E_OK) the function done successfully 
            (E_NOT_OK) the function has issue to do the action 
 */
Std_ReturnType keypad_intialization (const keypad_t *keypad){
    
    Std_ReturnType ret = E_OK  ;  
    if(NULL== keypad) {
        
        ret =E_NOT_OK ;
         
    }
    else {
        uint_8 row_counter = ZERO_INT ;
        uint_8 coloumns_counter =ZERO_INT;
         for(row_counter=ZERO_INT ; row_counter<keypad_rows_pins_number ;row_counter++ ){
             
             ret = gpio_pin__ALL_initaliztion (&(keypad->keypad_rows_pin[row_counter])) ;
             
         }
        
        for(coloumns_counter=ZERO_INT; coloumns_counter<keypad_coloumns_pins_number ;coloumns_counter++ ){
             
             ret = gpio_pin_direction_initalize (&(keypad->keypad_coloumns_pin[coloumns_counter])) ;
             
         }
        
        
        
        
        
        
    }
     
    return ret ;
}

/**
 * @breif get the written value from keypad 
 * @param keypad  pointer to keypad configuration 
 * @param value pointer to return the written value from keypad
 * @return status of the function 
            (E_OK) the function done successfully 
            (E_NOT_OK) the function has issue to do the action 
 */
Std_ReturnType keypad_get_written_value (const keypad_t *keypad , uint_8 * value){
    Std_ReturnType ret = E_OK  ;  
    if((NULL== keypad)||(NULL==value)){
        
        ret =E_NOT_OK ;
         
    }
    else {
        
        uint_8 row_counter = ZERO_INT ;
        uint_8 coloumns_counter =ZERO_INT;
        uint_8 row_clear_counter = ZERO_INT ;
        logic_t ret_logic = ZERO_INT ;
        
        for(row_counter=ZERO_INT ; row_counter<keypad_rows_pins_number ;row_counter++ ){
            for(row_clear_counter=ZERO_INT ; row_clear_counter<keypad_rows_pins_number ;row_clear_counter++ ){
                 ret = gpio_pin_write_logic(&(keypad->keypad_rows_pin[row_clear_counter]),LOW);
                
            }
             ret = gpio_pin_write_logic(&(keypad->keypad_rows_pin[row_counter]),HIGH);
                   for(coloumns_counter=ZERO_INT ; coloumns_counter<keypad_coloumns_pins_number ;coloumns_counter++ ){

                       ret = gpio_pin_read_logic(&(keypad->keypad_coloumns_pin[coloumns_counter]) ,&ret_logic ) ;
                       
                       if (ret_logic==HIGH) {
                           
                           
                           *value = keypad_symbols[row_counter][coloumns_counter];
                           
                       }
            
            
                   }
            
        }
        
        
    }
     
    return ret ;
    
    
    
    
}
