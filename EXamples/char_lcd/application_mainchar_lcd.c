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
void welcom_message (void) ;
void loading_screen(void) ;

int main() {
    
  general_initialization() ;
     
   welcom_message() ;
 
  while(1){
      
      
         loading_screen() ;
      
    
              
  }
  
    return (EXIT_SUCCESS);
}




void general_initialization(void){
    
    ECUAL_peripherals_initialization() ;
    
   
}
void welcom_message (void) {
    for (uint_8 counter = 0 ; counter<2 ; counter++){
        
        ret =lcd_8bit_send_string_pos(&lcd2 ,1,7 ,"hello" );
    ret =lcd_8bit_send_string_pos(&lcd2 ,2,5 ,"mohammed" );
    __delay_ms(1000) ;
    ret = lcd_8bit_send_command(&lcd2 , clear_display) ;
     __delay_ms(1000) ;
        
    }
    
    
    
}

void loading_screen(void){
    ret =lcd_8bit_send_string_pos(&lcd2 ,1,1 ,"loading" );  
    for (uint_8 counter = 8 ; counter<15 ; counter++){
   
   ret =lcd_8bit_send_string_pos(&lcd2 ,1,counter ,"." ); 
         __delay_ms(500) ;
  
    }
    
        ret = lcd_8bit_send_string_pos(&lcd2 , 1,8,"       ") ;
    
    
}
/**
 * move ALLAH NOOR right to left and versa vice 
 * 
 * 
 * 
 * 
 * 
 * 
 * ret =lcd_4bit_send_string_pos(&lcd1 ,2,1,"allah akbar") ;
 *  for (uint_8 columns_counter = 5 ; columns_counter<=8 ;columns_counter++){
          
       ret =lcd_4bit_send_string_pos(&lcd1 ,1,columns_counter,"ALLAH NOOR") ;
      __delay_ms(300) ;
      
      ret = lcd_4bit_send_char_data_pos(&lcd1 , 1 ,columns_counter , ' ') ;
      
      
      }
       ret =lcd_4bit_send_string_pos(&lcd1 ,1,8,"          ") ;
       
      for (uint_8 columns_counter =8; columns_counter>=5 ;columns_counter--){
          
       ret =lcd_4bit_send_string_pos(&lcd1 ,1,columns_counter,"ALLAH NOOR") ;
      __delay_ms(300) ;
      
      ret = lcd_4bit_send_char_data_pos(&lcd1 , 1 ,columns_counter+9 , ' ') ;
      
      
      }
        ret =lcd_4bit_send_string_pos(&lcd1 ,1,5,"          ") ;
 
 
 
 */