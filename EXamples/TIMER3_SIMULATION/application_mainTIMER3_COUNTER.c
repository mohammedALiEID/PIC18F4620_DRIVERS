/* 
 * File:   main_application.c
 * Author: mohammed_ali
 *
 * Created on December 2, 2023, 4:23 PM
 */

/*section ***include ******************/
#include "application_main.h"


/*section ***global variables ******************/

    TIMER3_CONFG_t TIMER3_timer_obj ={
                                     .TIMER3_RW_register_mode=TIMER1_RW_16BIT_REGISTER ,
                                     .TIMER3_interruptHandler =TIMER3_ISR_APP ,
                                     .TIMER3_mode =TIMER3_COUNTER_MODE ,
                                     .TIMER3_preload_value=0 ,
                                     .TIMER3_prescaler_value=TIMER3_PRESCALER_DIV_BY_1 ,
                                     .TIMER3_priority =interrupt_low_prioity ,
                                   } ;
    uint_16 TIMER3_ret_value = 0 ;

Std_ReturnType ret = 0 ;

int main() {
   
 
  general_initialization() ;
  
 
    
  while(1){
   ret = TIMER3_READ_VALUE(&TIMER3_timer_obj ,&TIMER3_ret_value) ;
     
  }
      
  
          
    
      
    return (EXIT_SUCCESS);
}
 
  
  
  

void general_initialization(void) {
    
   ECUAL_peripherals_initialization();
   
   ret =TIMER3_INITIALIZE(&TIMER3_timer_obj) ;
}


void TIMER3_ISR_APP(void) {
  
     
     ret =led_turn_toggle(&led1) ;  
}
