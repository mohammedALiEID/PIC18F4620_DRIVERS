/* 
 * File:   main_application.c
 * Author: mohammed_ali
 *
 * Created on December 2, 2023, 4:23 PM
 */

/*section ***include ******************/
#include "application_main.h"

/*section ***global variables ******************/

seven_segment_t seven_segment1= {.seven_segment_pin[0].port=PORTC_INDEX ,.seven_segment_pin[0].pin=PIN0 ,
                                 .seven_segment_pin[0].direction=OUTPUT ,.seven_segment_pin[0].logic=LOW ,
                                 .seven_segment_pin[1].port=PORTC_INDEX ,.seven_segment_pin[1].pin=PIN1 ,
                                 .seven_segment_pin[1].direction=OUTPUT ,.seven_segment_pin[1].logic=LOW ,
                                 .seven_segment_pin[2].port=PORTC_INDEX ,.seven_segment_pin[2].pin=PIN2 ,
                                 .seven_segment_pin[2].direction=OUTPUT ,.seven_segment_pin[2].logic=LOW ,
                                 .seven_segment_pin[3].port=PORTC_INDEX ,.seven_segment_pin[3].pin=PIN3 ,
                                 .seven_segment_pin[3].direction=OUTPUT ,.seven_segment_pin[3].logic=LOW ,
                                 .segment_type = SEGMENT_COMMON_anod };


Std_ReturnType ret = 0 ;

pin_confg_t segment1_enable = {.port =PORTD_INDEX ,.pin =PIN0 ,.direction = OUTPUT ,.logic = LOW};
pin_confg_t segment2_enable = {.port =PORTD_INDEX ,.pin =PIN1 ,.direction = OUTPUT ,.logic = LOW};
uint_8 num =90 ;
int main() {
    
  general_initialization() ;
  
  while(1){
      for ( uint_8 i = 0 ; i<50 ; i++){
          ret = seven_segment_write_number (&seven_segment1 , (uint_8)(num/10) ) ;
           ret =  gpio_pin_write_logic (&segment1_enable , HIGH) ;
   
    __delay_ms(10) ;
    ret =  gpio_pin_write_logic (&segment1_enable , LOW) ;
       ret = seven_segment_write_number (&seven_segment1 , (uint_8)(num%10) ) ;
    ret =  gpio_pin_write_logic (&segment2_enable , HIGH) ;

    __delay_ms(10) ;
   ret =  gpio_pin_write_logic (&segment2_enable , LOW) ;
  
          
      }
  
   
      num++ ;
      if (num==100){
          
          
          num = 0 ;
      }
     
      
      
   }
    return (EXIT_SUCCESS);
}




void general_initialization(void){
    
   ret= seven_segment_initialization (&seven_segment1) ;
   ret =gpio_pin__ALL_initaliztion(&segment1_enable) ;
   ret =gpio_pin__ALL_initaliztion(&segment2_enable) ;
}
