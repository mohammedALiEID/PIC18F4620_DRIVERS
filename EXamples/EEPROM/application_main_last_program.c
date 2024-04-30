/* 
 * File:   main_application.c
 * Author: mohammed_ali
 *
 * Created on December 2, 2023, 4:23 PM
 */

/*section ***include ******************/
#include "application_main.h"


/*section ***global variables ******************/
volatile uint_8 programe_selection = 0 ;
Std_ReturnType ret = 0 ;
void INT0_ISR_APP(void) ;
Interrupt_INTX_t INT0_OBJ ={.EXT_INTERRUPT_HANDLER=INT0_ISR_APP ,.edge=interrupt_INTX_rising_edge ,
                            .priorty=interrupt_HIGH_prioity ,.source=interrupt_INT0 ,
                            .mcu_pin.port =PORTB_INDEX ,.mcu_pin.pin=PIN0 ,.mcu_pin.direction=INPUT ,
                            .mcu_pin.logic=LOW};


int main() {
   
 
  general_initialization() ;

  ret =DATA_EEPROM_READ_BYTE(0X3FF ,&programe_selection) ;
    
  while(1){
     
      
      
       switch(programe_selection){
          case 1 : program1() ; break ;
          case 2 : program2() ; break ;
          case 3 : program3() ; break ;
          

          }
          
      
      
  }   
      
      
    return (EXIT_SUCCESS);
}
 
  
  
  

void general_initialization(void) {
    
   ECUAL_peripherals_initialization();
   ret = Interrupt_INTX_Initialize(&INT0_OBJ) ;
}

void INT0_ISR_APP(void) {
    
    
    if (programe_selection==3){
        
        programe_selection = 0 ;
    }
    programe_selection ++ ;
    
    ret =DATA_EEPROM_WRITE_BYTE(0X3FF ,programe_selection) ;
    
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