/* 
 * File:   main_application.c
 * Author: mohammed_ali
 *
 * Created on December 2, 2023, 4:23 PM
 */

/*section ***include ******************/
#include "application_main.h"

/*section ***global variables ******************/

led_confg_t led1 ={.port_index =  PORTC_INDEX ,.pin_index =PIN0 , .led_status = LED_OFF};
led_confg_t led2 = {.port_index = PORTC_INDEX ,.pin_index =PIN1 , .led_status = LED_OFF};
led_confg_t led3 = {.port_index = PORTC_INDEX ,.pin_index =PIN2 , .led_status = LED_OFF};
led_confg_t led4 = {.port_index = PORTC_INDEX ,.pin_index =PIN3 , .led_status = LED_OFF};



Std_ReturnType ret = 0 ;
int main( ) {
    
    
  general_initialization() ;
  
  while(1){
  ret= led_turn_toggle(&led1);
  ret= led_turn_toggle(&led2);
  ret= led_turn_toggle(&led3);
  ret= led_turn_toggle(&led4);
          __delay_ms(500);
      
  }
  

    return (EXIT_SUCCESS);
}




void general_initialization(void){
    
  ret=  led_intialize(&led1);
  ret=  led_intialize(&led2); 
  ret=  led_intialize(&led3);
  ret=  led_intialize(&led4);
    
    
    
}