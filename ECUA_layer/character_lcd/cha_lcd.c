/* 
 * File:   cha_lcd.c
 * Author: mohammed_ali
 *
 * Created on December 2, 2023, 6:01 PM
 */
/*section:***********includes*******************************/
#include"cha_lcd.h"
/*section:*********static functions declaration*****************/
static Std_ReturnType lcd_send_4bit(const cha_lcd_4bit_t*lcd , uint_8 data_command ) ;
static Std_ReturnType lcd_4bit_send_enable_signal(const cha_lcd_4bit_t*lcd  )  ;
static Std_ReturnType lcd_8bit_send_enable_signal(const cha_lcd_8bit_t*lcd  ) ;
static Std_ReturnType lcd_8bit_set_cursor(const cha_lcd_8bit_t*lcd ,uint_8 row , uint_8 column ) ;
static Std_ReturnType lcd_4bit_set_cursor(const cha_lcd_4bit_t*lcd ,uint_8 row , uint_8 column ) ;
/*section:*********functions definition*****************/
/**
 * 
 * @param lcd
 * @return 
 */
Std_ReturnType lcd_4bit_initalize (const cha_lcd_4bit_t*lcd ) {
    
     Std_ReturnType ret = E_OK  ;
    
    if (NULL==lcd) {
        ret = E_NOT_OK ;
      
    }
        
    else {
        
      ret = gpio_pin__ALL_initaliztion(&(lcd->lcd_RS))  ;
      ret = gpio_pin__ALL_initaliztion(&(lcd->lcd_E))  ;
      ret = gpio_pin__ALL_initaliztion(&(lcd->lcd_R_W))  ;
        
      for (int data_pin_counter = 0 ; data_pin_counter<4 ;data_pin_counter++){
          
          ret = gpio_pin__ALL_initaliztion(&(lcd->lcd_data[data_pin_counter]))  ;
          
         
      }
      
        __delay_ms(20) ;
        ret=lcd_4bit_send_command(lcd ,function_set_8bit_mode_2_line_font_8_5) ;
        __delay_ms(5) ;
        ret=lcd_4bit_send_command(lcd ,function_set_8bit_mode_2_line_font_8_5) ;
        
        __delay_us(105) ;
        ret=lcd_4bit_send_command(lcd ,function_set_8bit_mode_2_line_font_8_5) ;
       
           
        ret=lcd_4bit_send_command(lcd ,clear_display) ;
        ret=lcd_4bit_send_command(lcd ,return_home) ;
        ret=lcd_4bit_send_command(lcd ,entery_mode_set_increment_display_shift_OFF) ;
        ret=lcd_4bit_send_command(lcd ,display_off_underline_cursor_on_blinking_cursor_off) ;
        ret=lcd_4bit_send_command(lcd ,function_set_4bit_mode_2_line_font_8_5) ;
        ret=lcd_4bit_send_command(lcd , start_address_of_DDRAM) ;
     
      
        
    }
       
    return ret ;
    
    
}
/**
 * 
 * @param lcd
 * @param command
 * @return 
 */
Std_ReturnType lcd_4bit_send_command (const cha_lcd_4bit_t*lcd , uint_8 command) {
    
    Std_ReturnType ret = E_OK  ;
    
    if (NULL==lcd) {
        ret = E_NOT_OK ;
      
    }
        
    else {
       ret = gpio_pin_write_logic(&(lcd->lcd_R_W) , LOW) ; 
       ret = gpio_pin_write_logic(&(lcd->lcd_RS) , LOW) ; 
        
       ret = lcd_send_4bit(lcd ,(command>>4) ) ;
       ret =lcd_4bit_send_enable_signal(lcd) ;
       ret = lcd_send_4bit(lcd ,(command) ) ;
       ret =lcd_4bit_send_enable_signal(lcd) ;
        
        
        
    }
       
    return ret ;
    
    
    
}
/**
 * 
 * @param lcd
 * @param data
 * @return 
 */
Std_ReturnType lcd_4bit_send_char_data (const cha_lcd_4bit_t*lcd , uint_8 data) {
    Std_ReturnType ret = E_OK  ;
    
    if (NULL==lcd) {
        ret = E_NOT_OK ;
      
    }
        
    else {
        
       ret = gpio_pin_write_logic(&(lcd->lcd_R_W) , LOW) ; 
       ret = gpio_pin_write_logic(&(lcd->lcd_RS) , HIGH) ; 
        
       ret = lcd_send_4bit(lcd ,(data>>4) ) ;
       ret =lcd_4bit_send_enable_signal(lcd) ;
       ret = lcd_send_4bit(lcd ,(data) ) ;
       ret =lcd_4bit_send_enable_signal(lcd) ;
        
        
        
        
        
        
    }
       
    return ret ;
    
    
    
    
}
/**
 * 
 * @param lcd
 * @param row
 * @param column
 * @param data
 * @return 
 */
Std_ReturnType lcd_4bit_send_char_data_pos (const cha_lcd_4bit_t*lcd ,uint_8 row , uint_8 column , uint_8 data) {
    
    Std_ReturnType ret = E_OK  ;
    
    if (NULL==lcd) {
        ret = E_NOT_OK ;
      
    }
        
    else {
        
        ret =lcd_4bit_set_cursor (lcd ,row ,column) ;
        ret = lcd_4bit_send_char_data(lcd,data) ;
        
        
        
        
    }
       
    return ret ;
    
    
    
}
/**
 * 
 * @param lcd
 * @param str
 * @return 
 */
Std_ReturnType lcd_4bit_send_string (const cha_lcd_4bit_t*lcd , uint_8 *str) {
    Std_ReturnType ret = E_OK  ;
    
    if (NULL==lcd) {
        ret = E_NOT_OK ;
      
    }
        
    else {
        
        while(*str){
            
            
            ret =lcd_4bit_send_char_data (lcd ,*str++) ;
            
            
        }
        
        
        
        
        
        
    }
       
    return ret ;
    
    
    
    
}
/**
 * 
 * @param lcd
 * @param row
 * @param column
 * @param str
 * @return 
 */
Std_ReturnType lcd_4bit_send_string_pos (const cha_lcd_4bit_t*lcd ,uint_8 row , uint_8 column , uint_8 *str) {
    
    Std_ReturnType ret = E_OK  ;
    
    if (NULL==lcd) {
        ret = E_NOT_OK ;
      
    }
        
    else {
        
        
         ret =lcd_4bit_set_cursor (lcd ,row ,column) ; 
         
         ret = lcd_4bit_send_string (lcd ,str) ;
        
        
        
        
    }
       
    return ret ;
    
    
    
}
/**
 * 
 * @param lcd
 * @param row
 * @param column
 * @param _cha
 * @param mem_pos
 * @return 
 */
Std_ReturnType lcd_4bit_send_custom_char_pos (const cha_lcd_4bit_t*lcd ,uint_8 row , uint_8 column ,const uint_8 _cha[] ,uint_8 mem_pos) {
    
    Std_ReturnType ret = E_OK  ;
    
    if (NULL==lcd) {
        ret = E_NOT_OK ;
      
    }
        
    else {
        
        
        
         ret=lcd_4bit_send_command(lcd  , start_address_of_CGRAM+(8*mem_pos)) ;
        for (uint_8 counter = 0 ; counter<8 ;counter++){
            
            ret=lcd_4bit_send_char_data(lcd, _cha[counter]) ;
            
        }
        
        ret=lcd_4bit_send_char_data_pos(lcd , row ,column ,mem_pos) ;
        
        
        
        
        
    }
       
    return ret ;
    
    
    
}


/**
 * 
 * @param lcd
 * @return 
 */

Std_ReturnType lcd_8bit_initalize (const cha_lcd_8bit_t*lcd ){
    
    Std_ReturnType ret = E_OK  ;
    
    if (NULL==lcd) {
        ret = E_NOT_OK ;
      
    }
        
    else {
        
      ret = gpio_pin__ALL_initaliztion(&(lcd->lcd_RS))  ;
      ret = gpio_pin__ALL_initaliztion(&(lcd->lcd_E))  ;
      ret = gpio_pin__ALL_initaliztion(&(lcd->lcd_R_W))  ;
        
      for (int data_pin_counter = 0 ; data_pin_counter<8 ;data_pin_counter++){
          
          ret = gpio_pin__ALL_initaliztion(&(lcd->lcd_data[data_pin_counter]))  ;
          
         
      }
        
        __delay_ms(20) ;
        ret=lcd_8bit_send_command(lcd ,function_set_8bit_mode_2_line_font_8_5) ;
        __delay_ms(5) ;
        ret=lcd_8bit_send_command(lcd ,function_set_8bit_mode_2_line_font_8_5) ;
        
        __delay_us(105) ;
        ret=lcd_8bit_send_command(lcd ,function_set_8bit_mode_2_line_font_8_5) ;
        
        ret=lcd_8bit_send_command(lcd ,clear_display) ;
        ret=lcd_8bit_send_command(lcd ,return_home) ;
        ret=lcd_8bit_send_command(lcd ,entery_mode_set_increment_display_shift_OFF) ;
        ret=lcd_8bit_send_command(lcd ,display_on_underline_cursor_off_blinking_cursor_off) ;
        ret=lcd_8bit_send_command(lcd ,function_set_8bit_mode_2_line_font_8_5) ;
        ret=lcd_8bit_send_command(lcd , start_address_of_DDRAM) ;

         
    }
       
    return ret ;
    
    
    
}
/**
 * 
 * @param lcd
 * @param command
 * @return 
 */
Std_ReturnType lcd_8bit_send_command (const cha_lcd_8bit_t*lcd , uint_8 command) {
    
    Std_ReturnType ret = E_OK  ;
    
    if (NULL==lcd) {
        ret = E_NOT_OK ;
      
    }
        
    else {
        
       ret = gpio_pin_write_logic(&(lcd->lcd_R_W) , LOW) ; 
       ret = gpio_pin_write_logic(&(lcd->lcd_RS) , LOW) ; 
       for (uint_8 pin_counter = 0 ;pin_counter <8 ; pin_counter++){
           
          ret =gpio_pin_write_logic(&(lcd->lcd_data[pin_counter]) , (command>>pin_counter)&((uint_8)0x1) ) ;
           
       }
        
       ret=lcd_8bit_send_enable_signal(lcd) ;
        
        
        
    }
       
    return ret ;
    
    
    
}
/**
 * 
 * @param lcd
 * @param data
 * @return 
 */
Std_ReturnType lcd_8bit_send_char_data (const cha_lcd_8bit_t*lcd , uint_8 data) {
    
    Std_ReturnType ret = E_OK  ;
    
    if (NULL==lcd) {
        ret = E_NOT_OK ;
      
    }
        
    else {
        
        
          
       ret = gpio_pin_write_logic(&(lcd->lcd_R_W) , LOW) ; 
       ret = gpio_pin_write_logic(&(lcd->lcd_RS) , HIGH) ; 
       for (uint_8 pin_counter = 0 ;pin_counter <8 ; pin_counter++){
           
          ret =gpio_pin_write_logic(&(lcd->lcd_data[pin_counter]) , (data>>pin_counter)&((uint_8)0x1) ) ;
           
       }
        
       ret=lcd_8bit_send_enable_signal(lcd) ;
        
        
        
        
        
    }
       
    return ret ;
    
    
    
}
/**
 * 
 * @param lcd
 * @param row
 * @param column
 * @param data
 * @return 
 */
Std_ReturnType lcd_8bit_send_char_data_pos (const cha_lcd_8bit_t*lcd ,uint_8 row , uint_8 column , uint_8 data) {
    
    Std_ReturnType ret = E_OK  ;
    
    if (NULL==lcd) {
        ret = E_NOT_OK ;
      
    }
        
    else {
        
        ret =lcd_8bit_set_cursor(lcd ,row ,column ) ;
        
        ret = lcd_8bit_send_char_data(lcd ,data) ;
        
        
        
        
        
        
    }
       
    return ret ;
    
    
    
}
/**
 * 
 * @param lcd
 * @param str
 * @return 
 */
Std_ReturnType lcd_8bit_send_string (const cha_lcd_8bit_t*lcd , uint_8 *str) {
    Std_ReturnType ret = E_OK  ;
    
    if (NULL==lcd) {
        ret = E_NOT_OK ;
      
    }
        
    else {
        
        while (*str) {
            
            ret = lcd_8bit_send_char_data(lcd ,*str++) ;
            
           
            
        }
        
        
        
        
        
        
    }
       
    return ret ;
    
    
    
    
}
/**
 * 
 * @param lcd
 * @param row
 * @param column
 * @param str
 * @return 
 */
Std_ReturnType lcd_8bit_send_string_pos (const cha_lcd_8bit_t*lcd ,uint_8 row , uint_8 column , uint_8 *str){
    
    Std_ReturnType ret = E_OK  ;
    
    if (NULL==lcd) {
        ret = E_NOT_OK ;
      
    }
        
    else {
        
        ret =lcd_8bit_set_cursor(lcd , row ,column) ;
        
         
        while (*str) {
            
            ret = lcd_8bit_send_char_data(lcd ,*str++) ;
            
           
            
        }
        
        
        
        
        
    }
       
    return ret ;
    
    
    
}
/**
 * 
 * @param lcd
 * @param row
 * @param column
 * @param _cha
 * @param mem_pos
 * @return 
 */
Std_ReturnType lcd_8bit_send_custom_char_pos (const cha_lcd_8bit_t*lcd ,uint_8 row , uint_8 column ,const uint_8 _cha[] ,uint_8 mem_pos) {
    
    Std_ReturnType ret = E_OK  ;
    
    if (NULL==lcd) {
        ret = E_NOT_OK ;
      
    }
        
    else {
        
        
        ret=lcd_8bit_send_command(lcd  , start_address_of_CGRAM+(8*mem_pos)) ;
        for (uint_8 counter = 0 ; counter<8 ;counter++){
            
            ret=lcd_8bit_send_char_data(lcd, _cha[counter]) ;
            
        }
        
        ret=lcd_8bit_send_char_data_pos(lcd , row ,column ,mem_pos) ;
        
        
        
    }
       
    return ret ;
    
    
    
}

/**
 * 
 * @param value
 * @param str
 */
Std_ReturnType convert_uint_8_to_string(uint_8 value  , uint_8*str){
   
    uint_8 STR_TEMP[4] ;
    uint_8 counter = 0 ;
    Std_ReturnType ret = E_OK  ;
    
    if (NULL==str) {
        ret = E_NOT_OK ;
      
    }
        
    else {
        
         memset(str ,' ' ,3 ) ;
         str[3]='\0' ;
        sprintf(STR_TEMP , "%i" , value) ; 
        
        while (STR_TEMP[counter]!='\0'){
           str[counter] =STR_TEMP[counter] ;
            
            counter++ ;
           
        }
         counter = 0 ;
        
        
        
        
    }
       
    return ret ;
    
    
    
    
}
/**
 * 
 * @param value
 * @param str
 */
Std_ReturnType convert_uint_16_to_string(uint_16 value ,uint_8*str){
    
    uint_8 STR_TEMP[6] ;
    uint_8 counter = 0 ;
    Std_ReturnType ret = E_OK  ;
    
    if (NULL==str) {
        ret = E_NOT_OK ;
      
    }
        
    else {
        
         memset(str ,' ' ,5 ) ;
         str[5]='\0' ;
        sprintf(STR_TEMP , "%i" , value) ; 
        
        while (STR_TEMP[counter]!='\0'){
           str[counter] =STR_TEMP[counter] ;
            
            counter++ ;
           
        }
         counter = 0 ;
        
        
        
        
    }
       
    return ret ;
    
    
    
}
/**
 * 
 * @param value
 * @param str
 */
Std_ReturnType convert_uint_32_to_string(uint_32 value , uint_8*str){

    uint_8 STR_TEMP[11] ;
    uint_8 counter = 0 ;
    Std_ReturnType ret = E_OK  ;
    
    if (NULL==str) {
        ret = E_NOT_OK ;
      
    }
        
    else {
        
         memset(str ,' ' ,10 ) ;
         str[10]='\0' ;
        sprintf(STR_TEMP , "%i" , value) ; 
        
        while (STR_TEMP[counter]!='\0'){
           str[counter] =STR_TEMP[counter] ;
            
            counter++ ;
           
        }
         counter = 0 ;
        
        
        
        
    }
       
    return ret ;
    
    
    
    
}
Std_ReturnType convert_sint_8_to_string(sint_8 value  , uint_8*str){
   
    uint_8 STR_TEMP[5] ;
    uint_8 counter = 0 ;
    Std_ReturnType ret = E_OK  ;
    
    if (NULL==str) {
        ret = E_NOT_OK ;
      
    }
        
    else {
        
         memset(str ,' ' ,4 ) ;
         str[4]='\0' ;
        sprintf(STR_TEMP , "%i" , value) ; 
        
        while (STR_TEMP[counter]!='\0'){
           str[counter] =STR_TEMP[counter] ;
            
            counter++ ;
           
        }
         counter = 0 ;
        
        
        
        
    }
       
    return ret ;
    
    
    
    
}
Std_ReturnType convert_sint_16_to_string(sint_16 value ,uint_8*str){
    
    uint_8 STR_TEMP[7] ;
    uint_8 counter = 0 ;
    Std_ReturnType ret = E_OK  ;
    
    if (NULL==str) {
        ret = E_NOT_OK ;
      
    }
        
    else {
        
         memset(str ,' ' ,6 ) ;
         str[6]='\0' ;
        sprintf(STR_TEMP , "%i" , value) ; 
        
        while (STR_TEMP[counter]!='\0'){
           str[counter] =STR_TEMP[counter] ;
            
            counter++ ;
           
        }
         counter = 0 ;
        
        
        
        
    }
       
    return ret ;
    
    
    
}
Std_ReturnType convert_sint_32_to_string(sint_32 value , uint_8*str){

    uint_8 STR_TEMP[12] ;
    uint_8 counter = 0 ;
    Std_ReturnType ret = E_OK  ;
    
    if (NULL==str) {
        ret = E_NOT_OK ;
      
    }
        
    else {
        
         memset(str ,' ' ,11 ) ;
         str[11]='\0' ;
        sprintf(STR_TEMP , "%i" , value) ; 
        
        while (STR_TEMP[counter]!='\0'){
           str[counter] =STR_TEMP[counter] ;
            
            counter++ ;
           
        }
         counter = 0 ;
        
        
        
        
    }
       
    return ret ;
    
    
    
    
}
static Std_ReturnType lcd_send_4bit(const cha_lcd_4bit_t*lcd , uint_8 data_command )  {
    
    
     Std_ReturnType ret = E_OK  ;
    
    if (NULL==lcd) {
        ret = E_NOT_OK ;
      
    }
        
    else {
        
        ret = gpio_pin_write_logic(&(lcd->lcd_data[0]) ,(data_command>>0)&(uint_8)0x1) ;
        ret = gpio_pin_write_logic(&(lcd->lcd_data[1]) ,(data_command>>1)&(uint_8)0x1) ;
        ret = gpio_pin_write_logic(&(lcd->lcd_data[2]) ,(data_command>>2)&(uint_8)0x1) ;
        ret = gpio_pin_write_logic(&(lcd->lcd_data[3]) ,(data_command>>3)&(uint_8)0x1) ;
        
        
        
    }
       
    return ret ;
    
    
    
    
    
    
    
}
static Std_ReturnType lcd_4bit_send_enable_signal(const cha_lcd_4bit_t*lcd  ) {
    
   Std_ReturnType ret = E_OK  ;
    
    if (NULL==lcd) {
        ret = E_NOT_OK ;
      
    }
        
    else {
        
        ret = gpio_pin_write_logic(&(lcd->lcd_E) , HIGH) ;
        __delay_us(5) ;
         ret = gpio_pin_write_logic(&(lcd->lcd_E) , LOW) ;
        
    }
       
    return ret ;
    
    
}
static Std_ReturnType lcd_8bit_send_enable_signal(const cha_lcd_8bit_t*lcd  ) {
    
   Std_ReturnType ret = E_OK  ;
    
    if (NULL==lcd) {
        ret = E_NOT_OK ;
      
    }
        
    else {
        
        ret = gpio_pin_write_logic(&(lcd->lcd_E) , HIGH) ;
        __delay_us(5) ;
         ret = gpio_pin_write_logic(&(lcd->lcd_E) , LOW) ;
        
    }
       
    return ret ;
    
    
}
static Std_ReturnType lcd_8bit_set_cursor(const cha_lcd_8bit_t*lcd ,uint_8 row , uint_8 column ) {
    
   Std_ReturnType ret = E_OK  ;
    
    if (NULL==lcd) {
        ret = E_NOT_OK ;
      
    }
        
    else {
        column-- ;
        switch(row){
            case ROW1 : ret = lcd_8bit_send_command(lcd , 0x80+column) ;  break ;
            case ROW2 : ret = lcd_8bit_send_command(lcd , 0xC0+column) ;  break ;
            case ROW3 : ret = lcd_8bit_send_command(lcd , 0x94+column) ;  break ;
            case ROW4 : ret = lcd_8bit_send_command(lcd , 0xD4+column) ;  break ;
            default : break ;
            
            
            
            
            
        }
        
        
    }
       
    return ret ;
    
    
    
}

static Std_ReturnType lcd_4bit_set_cursor(const cha_lcd_4bit_t*lcd ,uint_8 row , uint_8 column ) {
    
   Std_ReturnType ret = E_OK  ;
    
    if (NULL==lcd) {
        ret = E_NOT_OK ;
      
    }
        
    else {
        column-- ;
        switch(row){
            case ROW1 : ret = lcd_4bit_send_command(lcd , 0x80+column) ;  break ;
            case ROW2 : ret = lcd_4bit_send_command(lcd , 0xC0+column) ;  break ;
            case ROW3 : ret = lcd_4bit_send_command(lcd , 0x94+column) ;  break ;
            case ROW4 : ret = lcd_4bit_send_command(lcd , 0xD4+column) ;  break ;
            default : break ;
            
            
            
            
            
        }
        
        
    }
       
    return ret ;
}