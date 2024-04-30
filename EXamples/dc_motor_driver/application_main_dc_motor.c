/* 
 * File:   main_application.c
 * Author: mohammed_ali
 *
 * Created on December 2, 2023, 4:23 PM
 */

/*section ***include ******************/
#include "application_main.h"

/*section ***global variables ******************/



motor_t motor1= {.motor_pin[0].port =PORTC_INDEX ,.motor_pin[0].pin =PIN0 ,.motor_pin[0].direction=OUTPUT ,.motor_pin[0].logic =MOTOR_OFF,
                 .motor_pin[1].port =PORTC_INDEX ,.motor_pin[1].pin =PIN1 ,.motor_pin[1].direction=OUTPUT ,.motor_pin[1].logic =MOTOR_OFF};

motor_t motor2= {.motor_pin[0].port =PORTC_INDEX ,.motor_pin[0].pin =PIN2 ,.motor_pin[0].direction=OUTPUT ,.motor_pin[0].logic =MOTOR_OFF,
                 .motor_pin[1].port =PORTC_INDEX ,.motor_pin[1].pin =PIN3 ,.motor_pin[1].direction=OUTPUT ,.motor_pin[1].logic =MOTOR_OFF};

Std_ReturnType ret = 0 ;


int main() {
    
  general_initialization() ;
  
  while(1){
      
      ret= motor_driver_forward(&motor1) ;
      ret= motor_driver_forward(&motor2) ;
      
      __delay_ms(2000);
      
      ret= motor_driver_backward(&motor1) ;
      ret= motor_driver_backward(&motor2) ;
       __delay_ms(2000);
      ret= motor_driver_stop(&motor1) ;
      ret= motor_driver_stop(&motor2) ;
       __delay_ms(2000);
       ret= motor_driver_forward(&motor1) ;
       ret= motor_driver_backward(&motor2) ;
         __delay_ms(2000);
       ret= motor_driver_forward(&motor2) ;
       ret= motor_driver_backward(&motor1) ;
       __delay_ms(2000);
  }
    return (EXIT_SUCCESS);
}




void general_initialization(void){
    
 ret= motor_driver_intialization(&motor1);
  ret= motor_driver_intialization(&motor2);
}
