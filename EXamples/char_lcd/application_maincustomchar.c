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
uint_8 pattern1 [8] = {0x00, 0x0E,0x1F,0x11,0x11, 0x11, 0x1F,0x00} ;
uint_8 pattern2 [8] = {0x00, 0x0E,0x1F,0x11,0x11, 0x1F, 0x1F,0x00} ;
uint_8 pattern3 [8] = {0x00, 0x0E,0x1F,0x11,0x1F, 0x1F, 0x1F,0x00} ;
uint_8 pattern4 [8] = {0x00, 0x0E,0x1F,0x1F,0x1F, 0x1F, 0x1F,0x00} ;
int main() {
   
 
  general_initialization() ;
      ret=lcd_8bit_send_custom_char_pos(&lcd2 , 1 ,20 ,pattern1 ,0) ;__delay_ms(100) ;
      ret=lcd_8bit_send_custom_char_pos(&lcd2 , 1 ,19 ,pattern2 ,1) ;__delay_ms(100) ;
      ret=lcd_8bit_send_custom_char_pos(&lcd2 , 1 ,18,pattern3  ,2) ;__delay_ms(100) ;
      ret=lcd_8bit_send_custom_char_pos(&lcd2 , 1 ,17 ,pattern4 ,3) ;__delay_ms(100) ;
    
  while(1){
      
     
      ret=lcd_4bit_send_custom_char_pos(&lcd1 , 1 ,20 ,pattern1 ,0) ;__delay_ms(100) ;
      ret=lcd_4bit_send_custom_char_pos(&lcd1 , 1 ,20 ,pattern2 ,0) ;__delay_ms(100) ;
      ret=lcd_4bit_send_custom_char_pos(&lcd1 , 1 ,20 ,pattern3 ,0) ;__delay_ms(100) ;
      ret=lcd_4bit_send_custom_char_pos(&lcd1 , 1 ,20 ,pattern4 ,0) ;__delay_ms(100) ;
     
      
      
  }
    return (EXIT_SUCCESS);
}
 
  
  
  

void general_initialization(void) {
    
   ECUAL_peripherals_initialization();
    
}



