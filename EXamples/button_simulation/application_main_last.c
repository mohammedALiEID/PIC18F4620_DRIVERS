/* 
 * File:   main_application.c
 * Author: mohammed_ali
 *
 * Created on December 2, 2023, 4:23 PM
 */

/*section ***include ******************/
#include "application_main.h"

/*section ***global variables ******************/
button_confg_t but_active_high= {.button_port=PORTC_INDEX ,.button_pin = PIN2 , 
.button_status = BUTTON_RELEASED ,.button_active_status=BUTTON_ACTIVE_HIGH};

button_confg_t but_active_low= {.button_port=PORTD_INDEX ,.button_pin = PIN0 , 
.button_status = BUTTON_RELEASED ,.button_active_status=BUTTON_ACTIVE_LOW};

led_confg_t led1={.port_index=PORTC_INDEX,.pin_index= PIN0 ,.led_status =  LED_OFF};
led_confg_t led2={.port_index=PORTC_INDEX,.pin_index= PIN1 ,.led_status =  LED_OFF};

Std_ReturnType ret = 0 ;
button_state_t but_active_low_st ;
button_state_t but_active_high_st ;
int main( ) {
    
  general_initialization() ;
  
  while(1){
      
      ret=button_read_status(&but_active_low,&but_active_low_st) ;
      
      if (but_active_low_st==BUTTON_PRESSED){
          
          ret=led_turn_on(&led1) ;
           
      }
      else {
          
          ret=led_turn_off(&led1) ;
      }
      
      
      ret=button_read_status(&but_active_high,&but_active_high_st) ;
      if (but_active_high_st==BUTTON_PRESSED){
          
          ret=led_turn_on(&led2) ;
         
          
          
      }
      else {
          
          ret=led_turn_off(&led2) ;
      }
      
      
      
  
      
  }
  

    return (EXIT_SUCCESS);
}




void general_initialization(void){
    
 ret=led_intialize(&led1);
 ret=led_intialize(&led2);
 ret=button_intialization(&but_active_low) ;    
 ret=button_intialization(&but_active_high) ;
    
}