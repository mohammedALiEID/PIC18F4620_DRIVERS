/* 
 * File:   main_application.c
 * Author: mohammed_ali
 *
 * Created on December 2, 2023, 4:23 PM
 */

/*section ***include ******************/
#include "application_main.h"

/*section ***global variables ******************/


Std_ReturnType ret = 0 ;
uint_8 num= 1 ;
uint_8 dual_7s =0 ;

uint_8 hours = 23 , minutes = 59  , seconds = 50 ;

int main() {
    
  general_initialization() ;
  
  while(1){
      for(int i = 0 ; i<;i++){
           ret = gpio_port_write_logic(PORTD_INDEX ,0x3E); 
     ret = gpio_port_write_logic(PORTC_INDEX ,(uint_8)hours/10); 
     __delay_us(3333) ;
   ret = gpio_port_write_logic(PORTD_INDEX ,0x3D); 
     ret = gpio_port_write_logic(PORTC_INDEX ,(uint_8)hours%10); 
       __delay_us(3333) ;
      /////////////////////////////////////////////////////////////
   ret = gpio_port_write_logic(PORTD_INDEX ,0x3B); 
     ret = gpio_port_write_logic(PORTC_INDEX ,(uint_8)minutes/10); 
      __delay_us(3333) ;
   ret = gpio_port_write_logic(PORTD_INDEX ,0x37); 
     ret = gpio_port_write_logic(PORTC_INDEX ,(uint_8)minutes%10); 
   __delay_us(3333) ;
///////////////////////////////////////////////////////////////////////
       ret = gpio_port_write_logic(PORTD_INDEX ,0x2f); 
     ret = gpio_port_write_logic(PORTC_INDEX ,(uint_8)seconds/10); 
     __delay_us(3333) ;
   ret = gpio_port_write_logic(PORTD_INDEX ,0x1f); 
     ret = gpio_port_write_logic(PORTC_INDEX ,(uint_8)seconds%10); 
       __delay_us(3333) ;
      
      //////////////////////////////////////////////////////////////////
      
          
      }
      
    seconds ++ ;
    if(seconds==60){
        minutes++ ;
        
        seconds = 0;
    }
    if (minutes==60){
        
        minutes = 0 ;
        hours++ ;
        
    }
    if (hours==24){
        
        minutes = 0 ;
        seconds =0 ;
        hours =0 ;
    }
     
   }
    return (EXIT_SUCCESS);
}




void general_initialization(void){
    
    
    ret=gpio_port_direction_initalize(PORTC_INDEX , 0xf0) ;
    ret=gpio_port_direction_initalize(PORTD_INDEX , 0xc0) ;
    ret = gpio_port_write_logic(PORTC_INDEX ,0x0); 
  
}
