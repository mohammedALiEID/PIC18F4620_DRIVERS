/* 
 * File:   main_application.c
 * Author: mohammed_ali
 *
 * Created on December 2, 2023, 4:23 PM
 */

/*section ***include ******************/
#include "application_main.h"


/*section ***global variables ******************/
TIMER0_CONFG_t TIMER0_counter_obj ={.TIMER0_COUNTER_Edge=TIMER0_RISING_EDGE ,.TIMER0_mode=TIMER0_COUNTER_MODE ,
                            .TIMER0_interruptHandler = TIMER0_ISR_APP ,
                            .TIMER0_preloaded_value = 0 ,.TIMER0_prescaler_status =TIMER0_PRESCALER_DISABLE_cfg ,
                            .TIMER0_prescaler_value =TIMER0_PRESCALER_DIV_BY_4 ,.TIMER0_register_size =TIMER0_16BIT_REGISTER};
Std_ReturnType ret = 0 ;
uint_16 freq = 0;
int main() {
   
 
  general_initialization() ;
  
 
    
  while(1){
     
      
      ret =TIMER0_READ_VALUE(&TIMER0_counter_obj,&freq) ;
      ret =TIMER0_WRITE_VALUE(&TIMER0_counter_obj,0) ;
    __delay_ms(1000) ;
  
    
     
  }
      
     
          
    
      
    return (EXIT_SUCCESS);
}
 
  
  
  

void general_initialization(void) {
    
   ECUAL_peripherals_initialization();
   ret =TIMER0_INITIALIZE(&TIMER0_counter_obj) ;
   
}

void TIMER0_ISR_APP(void) {
  
    
}
void program1(void){
    
    ret= led_turn_on(&led1);
    __delay_ms(3);
    ret=led_turn_off(&led1) ;
     __delay_ms(3);
    
}
void program2(void){
    
    ret= led_turn_on(&led2);
    __delay_ms(3);
    ret=led_turn_off(&led2) ;
     __delay_ms(3);
    
}
void program3(void){
    
    
    ret=led_turn_off(&led1);
    ret=led_turn_off(&led2);
}