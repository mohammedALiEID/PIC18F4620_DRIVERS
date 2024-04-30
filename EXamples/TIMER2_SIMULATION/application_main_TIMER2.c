/* 
 * File:   main_application.c
 * Author: mohammed_ali
 *
 * Created on December 2, 2023, 4:23 PM
 */

/*section ***include ******************/
#include "application_main.h"


/*section ***global variables ******************/

TIMER2_CONFG_t Timer2_obj ={.TIMER2_interruptHandler =TIMER2_ISR_APP ,
                            .TIMER2_postscaler_value =TIMER2_POSTSCALER_DIV_BY_16 ,
                            .TIMER2_prescaler_value =TIMER2_PRESCALER_DIV_BY_1 ,
                            .TIMER2_preload_value =249 } ;

Std_ReturnType ret = 0 ;

int main() {
   
 
  general_initialization() ;
  
 
    
  while(1){
   
     
  }
      
     
          
    
      
    return (EXIT_SUCCESS);
}
 
  
  
  

void general_initialization(void) {
    
   ECUAL_peripherals_initialization();
   
   ret =TIMER2_INITIALIZE(&Timer2_obj) ;
}


void TIMER2_ISR_APP(void) {
  
     
     ret =led_turn_toggle(&led1) ;  
}
