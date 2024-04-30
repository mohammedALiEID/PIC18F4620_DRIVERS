/* 
 * File:   main_application.c
 * Author: mohammed_ali
 *
 * Created on December 2, 2023, 4:23 PM
 */

/*section ***include ******************/
#include "application_main.h"

/*section ***global variables ******************/

Std_ReturnType ret = 0 ;
uint_8 value = 0 ;

int main() {
    
  general_initialization() ;
  
  while(1){
      
      ret = keypad_get_written_value(&keyp1 , &value) ;
      if('7'==value){
          
          ret = led_turn_on(&led1) ;
          __delay_ms(300) ;
          ret = led_turn_off(&led1) ;
          value = 0 ;
          
      }
      
      
      
   }
    return (EXIT_SUCCESS);
}




void general_initialization(void){
    
    ECUAL_peripherals_initialization() ;
    
   
}
