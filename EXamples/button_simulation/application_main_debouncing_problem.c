/* 
 * File:   main_application.c
 * Author: mohammed_ali
 *
 * Created on December 2, 2023, 4:23 PM
 */

/*section ***include ******************/
#include "application_main.h"


/*section ***global variables ******************/
uint_8 counter = 0 ;
uint_16 butt_validation_counter=0 ;
button_state_t butt_read_status = BUTTON_RELEASED ;
button_state_t butt_valid_status = BUTTON_RELEASED ;
button_state_t button_last_valid_status = BUTTON_RELEASED ;
Std_ReturnType ret = 0 ;


int main() {
   
 
  general_initialization() ;

  
    
  while(1){
     
      ret = button_read_status(&but_active_high ,&butt_read_status) ;
      /***************************debouncing******************************/
      /**here i need to wait butt_validation_counter to reach 500 to change from program to another 
       * but to increment 1 need to wait the delay of current program so this method for debouncing not effective 
       * so we can use timer to debounce or use another technique ex : interrupt  */
      
      
       if (BUTTON_PRESSED==butt_read_status){
           butt_validation_counter++ ;
           if (butt_validation_counter>500){
              butt_valid_status = BUTTON_PRESSED ;
              
           }
           
       }
       else {
           butt_valid_status = BUTTON_RELEASED ;
           butt_validation_counter = 0 ;
           
           
       }
           
      
      if (button_last_valid_status!=butt_valid_status){
          button_last_valid_status =butt_valid_status ;
          if (BUTTON_PRESSED==butt_valid_status){
              if (counter==3){
              
              counter= 0 ;
          }
          
          counter++ ;
          
      }
      
     
          
      }
      
       switch(counter){
          case 1 : program1() ; break ;
          case 2 : program2() ; break ;
          case 3 : program3() ; break ;
          

          }
          
      
      
  }   
      
      
    return (EXIT_SUCCESS);
}
 
  
  
  

void general_initialization(void) {
    
   ECUAL_peripherals_initialization();
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