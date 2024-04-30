/* 
 * File:   main_application.c
 * Author: mohammed_ali
 *
 * Created on December 2, 2023, 4:23 PM
 */

/*section ***include ******************/
#include "application_main.h"


/*section ***global variables ******************/
void INT0_ISR_APP(void) ;
void INT1_ISR_APP(void) ;
void INT2_ISR_APP(void) ;
Interrupt_INTX_t INT0_OBJ ={.EXT_INTERRUPT_HANDLER=INT0_ISR_APP ,.edge=interrupt_INTX_rising_edge ,
                            .priorty=interrupt_HIGH_prioity ,.source=interrupt_INT0 ,
                            .mcu_pin.port =PORTB_INDEX ,.mcu_pin.pin=PIN0 ,.mcu_pin.direction=INPUT ,
                            .mcu_pin.logic=LOW};

Interrupt_INTX_t INT1_OBJ ={.EXT_INTERRUPT_HANDLER=INT1_ISR_APP ,.edge=interrupt_INTX_falling_edge ,
                            .priorty=interrupt_low_prioity ,.source=interrupt_INT1 ,
                            .mcu_pin.port =PORTB_INDEX ,.mcu_pin.pin=PIN1 ,.mcu_pin.direction=INPUT ,
                            .mcu_pin.logic=LOW};
Interrupt_INTX_t INT2_OBJ ={.EXT_INTERRUPT_HANDLER=INT2_ISR_APP ,.edge=interrupt_INTX_rising_edge ,
                            .priorty=interrupt_HIGH_prioity ,.source=interrupt_INT2 ,
                            .mcu_pin.port =PORTB_INDEX ,.mcu_pin.pin=PIN2 ,.mcu_pin.direction=INPUT ,
                            .mcu_pin.logic=LOW};

Std_ReturnType ret = 0 ;

int main() {
   
 
  general_initialization() ;
     
    
  while(1){
      
     
      
  }
    return (EXIT_SUCCESS);
}
 
  
  
  

void general_initialization(void) {
    
   ECUAL_peripherals_initialization();
   ret =Interrupt_INTX_Initialize(&INT0_OBJ) ;
   ret =Interrupt_INTX_Initialize(&INT1_OBJ) ;
   ret =Interrupt_INTX_Initialize(&INT2_OBJ) ;
} 

void INT0_ISR_APP(void){
    
  ret = led_turn_toggle(&led1) ;  

    
}
void INT1_ISR_APP(void){
      
  ret = led_turn_toggle(&led2) ;  

}
void INT2_ISR_APP(void){
    
  ret = led_turn_toggle(&led3) ;  
    
}