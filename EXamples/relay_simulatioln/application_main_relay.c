/* 
 * File:   main_application.c
 * Author: mohammed_ali
 *
 * Created on December 2, 2023, 4:23 PM
 */

/*section ***include ******************/
#include "application_main.h"

/*section ***global variables ******************/
button_confg_t but_active_high= {.button_port=PORTC_INDEX ,.button_pin = PIN0 , 
.button_status = BUTTON_RELEASED ,.button_active_status=BUTTON_ACTIVE_HIGH};

led_confg_t led1={.port_index=PORTC_INDEX,.pin_index= PIN2 ,.led_status =  LED_OFF};

relay_t relay1={.port_index=PORTC_INDEX ,.pin_index =PIN1 ,.relay_status = RELAY_OFF} ;


motor_t motor1= {.motor[0].motor_port =PORTC_INDEX ,.motor[0].motor_pin =PIN3 ,.motor[0].motor_status =MOTOR_OFF 
                 ,.motor[1].motor_port =PORTC_INDEX ,.motor[1].motor_pin =PIN4 ,.motor[1].motor_status =MOTOR_OFF };


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
               
               ret = relay_energization (&relay1) ;
               ret = led_turn_on(&led1);
          
          __delay_ms(5000) ;
          ret = led_turn_off(&led1);
          ret= relay_deenergization(&relay1);
  }
  
  
      }
  }
    return (EXIT_SUCCESS);
}




void general_initialization(void){
    
 ret=led_intialize(&led1);
 ret=button_intialization(&but_active_high) ;
 ret =relay_initialization(&relay1)   ;
 ret= motor_driver_intialization(&motor1);
}
