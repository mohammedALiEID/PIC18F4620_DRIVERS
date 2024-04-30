/* 
 * File:   main_application.c
 * Author: mohammed_ali
 *
 * Created on December 2, 2023, 4:23 PM
 */

/*section ***include ******************/
#include "application_main.h"

/*section ***global variables ******************/

uint_8 segment_common_anod[10]={ 0XC0 , 0XF9 , 0XA4 ,0XB0 , 0X99 ,0X92 ,0X82 ,0XF8 ,0X80 ,0X90 };
uint_8 segment_common_cathod[10]={ 0X3F , 0X06 , 0X5B ,0X4F, 0X66 ,0X6D ,0X7D ,0X07,0X7F,0X6F };

Std_ReturnType ret = 0 ;


int main() {
    
  general_initialization() ;
  
  while(1){
      
      for (int i = 0 ; i<10 ;i++){
           ret =  gpio_port_write_logic(PORTC_INDEX ,segment_common_anod[i]); 
      
          for (int j = 0 ; j<10 ;j++){
          
            ret =  gpio_port_write_logic(PORTD_INDEX ,segment_common_anod[j]); 
              __delay_ms(100);
              
          }
   
         
      }
    
   }
    return (EXIT_SUCCESS);
}




void general_initialization(void){
    
    
    ret=gpio_port_direction_initalize(PORTC_INDEX , 0x80);
    ret =  gpio_port_write_logic(PORTC_INDEX ,segment_common_anod[0]); 
    ret=gpio_port_direction_initalize(PORTD_INDEX , 0x80);
 ret =  gpio_port_write_logic(PORTD_INDEX ,segment_common_anod[0]); 
}
