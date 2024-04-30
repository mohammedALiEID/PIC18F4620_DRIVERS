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
button_state_t but_active_high_last_st=BUTTON_RELEASED ;
led_status led_st = LED_OFF ;
int main() {
    
  general_initialization() ;
  
  while(1){
      
                 
      ret=button_read_status(&but_active_high,&but_active_high_st) ;
      
      /////////////////method to remove the  bounce instead of the timer/////////////////////
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
      
      /////////////////////////////////////////////////////////////////////////////
      
      if(but_active_high_last_valid_st!=but_active_high_valid_st){
          but_active_high_last_valid_st=but_active_high_valid_st ;
          
           if ((but_active_high_valid_st==BUTTON_PRESSED)&&(flag==0)){
          
          ret= led_turn_on(&led1);
          flag = 1 ;
          
      }
      else if ((but_active_high_valid_st==BUTTON_PRESSED)&&(flag==1)) {
          
          ret= led_turn_off(&led1);
          flag = 0 ;
          
      }  
          
          
      }
     
          
      
  
     
      
  }
  ////////////////////another method/////////////////////////////////////////////////////////////////////////////
       /*
      if (but_active_high_last_valid_st!=but_active_high_valid_st){
          
          but_active_high_last_valid_st=but_active_high_valid_st ;
          if (BUTTON_PRESSED==but_active_high_valid_st){
              
              
              if (led_st==LED_OFF ){
              ret= led_turn_on(&led1);
              led_st=LED_ON ;
               
              
          }
          else {
              
              ret= led_turn_off(&led1); 
              led_st=LED_OFF ;
          }
          
          
              
          }
          
          
          
          
      }
      */
  
  

    return (EXIT_SUCCESS);
}




void general_initialization(void){
    
 ret=led_intialize(&led1);
 ret=button_intialization(&but_active_high) ;
    
}