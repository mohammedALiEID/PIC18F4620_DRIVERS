/* 
 * File:   main_application.c
 * Author: mohammed_ali
 *
 * Created on December 2, 2023, 4:23 PM
 */

/*section ***include ******************/
#include "application_main.h"


/*section ***global variables ******************/
TIMER0_CONFG_t TIMER0_obj ={.TIMER0_COUNTER_Edge=TIMER0_RISING_EDGE ,.TIMER0_mode=TIMER0_TIMER_MODE ,
                            .TIMER0_preloaded_value = 3036 ,.TIMER0_prescaler_status =TIMER0_PRESCALER_ENABLE_cfg ,
                            .TIMER0_prescaler_value =TIMER0_PRESCALER_DIV_BY_4 ,.TIMER0_register_size =TIMER0_16BIT_REGISTER};
Std_ReturnType ret = 0 ;
uint_8 TMR0500ms = 0 ;

int main() {
   
 
  general_initialization() ;
  
 
    
  while(1){
     
      
      if (INTCONbits.TMR0IF ==1){
      ret = TIMER0_WRITE_VALUE(&TIMER0_obj ,3036) ;
      INTCONbits.TMR0IF =0 ;
       ret =led_turn_toggle(&led1) ; 
       TMR0500ms++ ;
       if (2==TMR0500ms){
           ret =led_turn_toggle(&led2) ; 
           TMR0500ms = 0 ;
           
       }
               
      } 
      
      
      
     
      
      }
     
          
    
      
    return (EXIT_SUCCESS);
}
 
  
  
  

void general_initialization(void) {
    
   ECUAL_peripherals_initialization();
   ret =TIMER0_INITIALIZE(&TIMER0_obj) ;
   
}

void ADC_ISR_APP(void) {
    
     
    
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