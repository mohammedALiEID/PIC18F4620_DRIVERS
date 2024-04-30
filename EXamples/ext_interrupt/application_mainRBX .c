/* 
 * File:   main_application.c
 * Author: mohammed_ali
 *
 * Created on December 2, 2023, 4:23 PM
 */

/*section ***include ******************/
#include "application_main.h"


/*section ***global variables ******************/
void RB4_ISR_APP_HIGH(void) ;
void RB4_ISR_APP_LOW(void) ;
void RB5_ISR_APP_HIGH(void) ;
void RB5_ISR_APP_LOW(void) ;
void RB6_ISR_APP_HIGH(void) ;
void RB6_ISR_APP_LOW(void) ;
void RB7_ISR_APP_HIGH(void) ;
void RB7_ISR_APP_LOW(void) ;
Interrupt_RBX_t RB4_OBJ ={  .EXT_INTERRUPT_HANDLER_HIGH=RB4_ISR_APP_HIGH ,
                            .EXT_INTERRUPT_HANDLER_LOW=RB4_ISR_APP_LOW ,
                            .priorty=interrupt_HIGH_prioity ,
                            .mcu_pin.port =PORTB_INDEX ,.mcu_pin.pin=PIN4 ,
                            .mcu_pin.direction=INPUT ,
                            .mcu_pin.logic=LOW};

Interrupt_RBX_t RB5_OBJ ={   .EXT_INTERRUPT_HANDLER_HIGH=RB5_ISR_APP_HIGH ,
                            .EXT_INTERRUPT_HANDLER_LOW=RB5_ISR_APP_LOW ,
                            .priorty=interrupt_HIGH_prioity ,
                            .mcu_pin.port =PORTB_INDEX ,.mcu_pin.pin=PIN5 ,
                            .mcu_pin.direction=INPUT ,
                            .mcu_pin.logic=LOW};

Interrupt_RBX_t RB6_OBJ ={  .EXT_INTERRUPT_HANDLER_HIGH=RB6_ISR_APP_HIGH ,
                            .EXT_INTERRUPT_HANDLER_LOW=RB6_ISR_APP_LOW ,
                            .priorty=interrupt_HIGH_prioity ,
                            .mcu_pin.port =PORTB_INDEX ,.mcu_pin.pin=PIN6 ,
                            .mcu_pin.direction=INPUT ,
                            .mcu_pin.logic=LOW};

Interrupt_RBX_t RB7_OBJ ={  .EXT_INTERRUPT_HANDLER_HIGH=RB7_ISR_APP_HIGH ,
                            .EXT_INTERRUPT_HANDLER_LOW=RB7_ISR_APP_LOW ,
                            .priorty=interrupt_HIGH_prioity ,
                            .mcu_pin.port =PORTB_INDEX ,.mcu_pin.pin=PIN7 ,
                            .mcu_pin.direction=INPUT ,
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
   ret =Interrupt_RBX_Initialize(&RB4_OBJ) ;
   ret =Interrupt_RBX_Initialize(&RB5_OBJ) ;
   ret =Interrupt_RBX_Initialize(&RB6_OBJ) ;
   ret =Interrupt_RBX_Initialize(&RB7_OBJ) ;
} 



void RB4_ISR_APP_HIGH(void){
     ret = led_turn_on(&led1) ;  
}
void RB4_ISR_APP_LOW(void) {
     ret = led_turn_on(&led2) ;  
}
void RB5_ISR_APP_HIGH(void) {
     ret = led_turn_off(&led1) ;  
}
void RB5_ISR_APP_LOW(void) {
     ret = led_turn_off(&led2) ;  
}
void RB6_ISR_APP_HIGH(void) {
     ret = led_turn_on(&led3) ;  
}
void RB6_ISR_APP_LOW(void) {
     ret = led_turn_on(&led4) ;  
}
void RB7_ISR_APP_HIGH(void) {
     ret = led_turn_off(&led3) ;  
}
void RB7_ISR_APP_LOW(void){
     ret = led_turn_off(&led4) ;  
}