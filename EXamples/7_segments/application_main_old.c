/* 
 * File:   main_application.c
 * Author: mohammed_ali
 *
 * Created on December 2, 2023, 4:23 PM
 */

/*section ***include ******************/
#include "application_main.h"

/*section ***global variables ******************/


pin_confg_t  led_0 = {
    
   . port = PORTC_INDEX ,
   .pin=  PIN0 ,
   .direction = OUTPUT ,
   .logic =  LOW ,
    
} ;
     
 pin_confg_t  led_1 = {
    
   . port = PORTC_INDEX ,
   .pin=  PIN1 ,
   .direction = OUTPUT ,
   .logic =  LOW ,
    
} ;
  
 pin_confg_t  led_2 = {
    
   . port = PORTC_INDEX ,
   .pin=  PIN2 ,
   .direction = OUTPUT ,
   .logic =  LOW  ,
    
} ;
 
  pin_confg_t  but_1 = {
    
   . port = PORTD_INDEX ,
   .pin=  PIN0 ,
   .direction =  INPUT ,
   .logic =  LOW  ,
    
} ;
 logic_t logic_but_st ;
 direction_t BUT1_direction_st ;
 Std_ReturnType ret  ;
 uint_8 portc_logic_st ,portc_directon_st  ;
int main( ) {
  
  
   // general_initialization() ;

   //ret =  gpio_pin_get_direction_status(&but_1 ,&BUT1_direction_st );
   while (1){
   ret =gpio_port_direction_initalize(PORTC_INDEX , 0x0);
   ret = gpio_port_get_direction_status(PORTC_INDEX,&portc_directon_st) ;
   ret =gpio_port_write_logic(PORTC_INDEX,0x00);
  // ret = gpio_port_read_logic(PORTC_INDEX,&portc_logic_st) ;
   __delay_ms(2000);
   ret=gpio_port_toggle_logic(PORTC_INDEX) ;
   ret = gpio_port_read_logic(PORTC_INDEX,&portc_logic_st) ;
   
   //ret =gpio_port_write_logic(PORTC_INDEX,0xAA);
   //ret = gpio_port_read_logic(PORTC_INDEX,&portc_logic_st) ;
      __delay_ms(2000);
      
      
      
   }  
   
   
   /*

   while (1){
        ret = gpio_pin_read_logic(&but_1,&logic_but_st);
        if( logic_but_st== HIGH){
       ret =gpio_pin_write_logic(&led_0,  HIGH) ;
       
       }
       else {
           ret =gpio_pin_write_logic(&led_0,  LOW) ;
           
           
       }
       ret =gpio_pin_write_logic(&led_1,  HIGH) ;
       ret =gpio_pin_write_logic(&led_2,  HIGH) ;
       __delay_ms(500);
       ret =gpio_pin_write_logic(&led_1,  LOW) ;
       ret =gpio_pin_write_logic(&led_2,  LOW) ;
         __delay_ms(500);
       
   }
      
      
       */
    
    
         
    return (EXIT_SUCCESS);
}

void general_initialization(void){
    
   ret= gpio_pin__ALL_initaliztion(&led_0);
   ret= gpio_pin__ALL_initaliztion(&led_1);
   ret= gpio_pin__ALL_initaliztion(&led_2);
   ret= gpio_pin__ALL_initaliztion(&but_1);
    
    
    
    
}