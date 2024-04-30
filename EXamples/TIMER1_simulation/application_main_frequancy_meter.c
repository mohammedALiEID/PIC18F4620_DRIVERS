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
                            .TIMER0_interruptHandler = TIMER0_ISR_APP ,.TIMER0_preloaded_value = 0 ,
                            .TIMER0_prescaler_status =TIMER0_PRESCALER_DISABLE_cfg ,
                            .TIMER0_prescaler_value =TIMER0_PRESCALER_DIV_BY_4 ,
                            .TIMER0_register_size =TIMER0_16BIT_REGISTER};

TIMER0_CONFG_t TIMER0_timer_obj ={.TIMER0_COUNTER_Edge=TIMER0_RISING_EDGE ,.TIMER0_mode=TIMER0_TIMER_MODE ,
                            .TIMER0_interruptHandler = TIMER0_ISR_APP ,.TIMER0_preloaded_value = 3036 ,
                            .TIMER0_prescaler_status =TIMER0_PRESCALER_ENABLE_cfg ,
                            .TIMER0_prescaler_value =TIMER0_PRESCALER_DIV_BY_32 ,
                            .TIMER0_register_size =TIMER0_16BIT_REGISTER};


TIMER1_CONFG_t TIMER1_timer_obj ={.TIMER1_OSC_status=TIMER1_OSC_DISABLE_cnfg ,
                                  .TIMER1_RW_register_mode=TIMER1_RW_16BIT_REGISTER ,
                                  .TIMER1_interruptHandler =TIMER1_ISR_APP ,
                                  .TIMER1_mode =TIMER1_TIMER_MODE ,
                                  .TIMER1_preload_value=15536 ,
                                  .TIMER1_prescaler_value=TIMER1_PRESCALER_DIV_BY_4 ,
                                  .TIMER1_priority =interrupt_low_prioity ,
                                   } ;

TIMER1_CONFG_t TIMER1_counter_obj ={.TIMER1_OSC_status=TIMER1_OSC_DISABLE_cnfg ,
                                  .TIMER1_RW_register_mode=TIMER1_RW_16BIT_REGISTER ,
                                  .TIMER1_interruptHandler =TIMER1_ISR_APP ,
                                  .TIMER1_mode =TIMER1_COUNTER_MODE ,
                                  .TIMER1_preload_value=0 ,
                                  .TIMER1_prescaler_value=TIMER1_PRESCALER_DIV_BY_1 ,
                                  .TIMER1_priority =interrupt_low_prioity ,
                                  .TIMER1_counter_mode =TIMER1_ASYNC_COUNTER_MODE ,
                                   } ;


uint_16 TIMER1_ret_value = 0 ;

Std_ReturnType ret = 0 ;

int main() {
   
 
  general_initialization() ;
  
 
    
  while(1){
   
     
  }
      
     
          
    
      
    return (EXIT_SUCCESS);
}
 
  
  
  

void general_initialization(void) {
    
   ECUAL_peripherals_initialization();
   ret=TIMER1_INITIALIZE(&TIMER1_counter_obj) ;
   ret=TIMER0_INITIALIZE(&TIMER0_timer_obj) ;
}

void TIMER0_ISR_APP(void) {
   
    ret = TIMER1_READ_VALUE(&TIMER1_counter_obj ,&TIMER1_ret_value) ;
    ret = TIMER1_WRITE_VALUE(&TIMER1_counter_obj , 0) ;
   

}
void TIMER1_ISR_APP(void) {
  
     
     ret =led_turn_toggle(&led1) ;  
}
