/* 
 * File:   main_application.c
 * Author: mohammed_ali
 *
 * Created on December 2, 2023, 4:23 PM
 */

/*section ***include ******************/
#include "application_main.h"

/*section ***global variables ******************/
button_confg_t but_active_high= {.button_port=PORTC_INDEX ,.button_pin = PIN2 , 
.button_status = BUTTON_RELEASED ,.button_active_status=BUTTON_ACTIVE_HIGH};



led_confg_t led1={.port_index=PORTC_INDEX,.pin_index= PIN0 ,.led_status =  LED_OFF};


Std_ReturnType ret = 0 ;
button_state_t but_active_high_st= BUTTON_RELEASED;
uint_8 flag = 0 ;
uint_16 but_active_high_validation_counter =0 ;
button_state_t but_active_high_valid_st=BUTTON_RELEASED ;
button_state_t but_active_high_last_valid_st=BUTTON_RELEASED ;
uint_8 counter = 0 ;

int main() {
    
  general_initialization() ;
  
  while(1){
      
                 
      ret=button_read_status(&but_active_high,&but_active_high_st) ;
      
      /////////////////method to remove the  bounce/////////////////////
      if ((but_active_high_st==BUTTON_PRESSED)){
          but_active_high_validation_counter++ ;
          if (but_active_high_validation_counter>500){
               but_active_high_valid_st =BUTTON_PRESSED ;
          }
      }
      else {
            but_active_high_valid_st =BUTTON_RELEASED ;
             but_active_high_validation_counter = 0 ;
              
          }
      
      
      
      
      
      
      if(but_active_high_last_valid_st!=but_active_high_valid_st){////////////////////////to prevent doing action during pressing on button
          but_active_high_last_valid_st=but_active_high_valid_st ;
          
           if ((but_active_high_valid_st==BUTTON_PRESSED)){
               if (3==counter ){
                   
                   counter=0 ;
               }
               counter++ ;
               
               switch(counter){
                   case 1 : program1(); break;
                   case 2 : program2(); break ;
                   case 3 : program3(); break ;
                   default : break ;
                   
                   
                   
               }
          
      }
     
          
      
  
     
      }
          
          
          
          
  }
  
  

    return (EXIT_SUCCESS);
}




void general_initialization(void){
    
 ret=led_intialize(&led1);
 ret=button_intialization(&but_active_high) ;
    
}
void program1(void){
  ret=led_turn_on(&led1);
__delay_ms(500);
ret=led_turn_off(&led1);
    
}
void program2(void){
    for (int i=0 ;i<2 ;i++){
 ret=led_turn_on(&led1);
__delay_ms(500);
ret=led_turn_off(&led1);
     __delay_ms(500);   
    }
    
}
void program3(void){
     for (int j=0 ;j<3 ;j++){
 ret=led_turn_on(&led1);
__delay_ms(500);
ret=led_turn_off(&led1);
__delay_ms(500);
     }
}