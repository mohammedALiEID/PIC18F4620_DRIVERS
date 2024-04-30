/* 
 * File:   main_application.c
 * Author: mohammed_ali
 *
 * Created on December 2, 2023, 4:23 PM
 */

/*section ***include ******************/
#include "application_main.h"


/*section ***global variables ******************/
uint_8 heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000,
  0b00000
};

Std_ReturnType ret = 0 ;
ADC_confg_t ADC_obj1 ={.ADC_channel =ADC_CHANNEL_AN0 ,
                      .A_D_port_confg =ADC_channel_AN0_to_AN8_analog_functionality ,
                      .aquisition_time=ADC_aquisition_time_12TAD ,
                      .clock_source=ADC_clock_source_FOSC_OVER_2 ,
                      .result_format=RESULT_left_justified ,
                      .voltage_ref =voltage_ref_enable} ;

uint_16 LM35_result0 = 0 ,LM35_result1=0  ;
sint_16 LM35_Celsius0 = 0 ,LM35_Celsius1 = 0 ;

uint_8 LM93_Celsius0_text[7] ;
uint_8 LM93_Celsius1_text[7] ;

int main() {
   
 
  general_initialization() ;
  ret = lcd_4bit_send_string_pos(&lcd1 ,1 ,7,"LM35 TEST") ;
  ret - lcd_4bit_send_custom_char_pos(&lcd1,2 ,10,heart,0) ;
  
  ret = lcd_4bit_send_string_pos(&lcd1 ,3 , 1,"TEMP0: ") ;
  ret = lcd_4bit_send_string_pos(&lcd1 ,4, 1,"TEMP1: ") ;
 
    
  while(1){
     
      
      ret =ADC_Get_conversion_one_step_blocking(&ADC_obj1 ,ADC_CHANNEL_AN0 ,&LM35_result0) ;
      
      ret =ADC_Get_conversion_one_step_blocking(&ADC_obj1 ,ADC_CHANNEL_AN1 ,&LM35_result1) ;
      
      LM35_Celsius0 =(LM35_result0-512) ;
      LM35_Celsius1 =(LM35_result1-512) ;
      
      if (LM35_Celsius0>30){
          
          
          ret =motor_driver_forward(&motor1) ;
      }
      else {
      
          ret=motor_driver_stop(&motor1) ;
      }
      if (LM35_Celsius1>35){
          
          
          ret =motor_driver_backward(&motor2) ;
      }
      else {
      
          ret=motor_driver_stop(&motor2) ;
      }
      
      
      
      
      ret = convert_sint_16_to_string(LM35_Celsius0 ,LM93_Celsius0_text) ;
      ret = lcd_4bit_send_string_pos(&lcd1 ,3 , 8,LM93_Celsius0_text) ;
      
      ret = convert_sint_16_to_string(LM35_Celsius1 ,LM93_Celsius0_text) ;
      ret = lcd_4bit_send_string_pos(&lcd1 ,4 , 8,LM93_Celsius0_text) ;
      
      
      }
     
          
    
      
    return (EXIT_SUCCESS);
}
 
  
  
  

void general_initialization(void) {
    
   ECUAL_peripherals_initialization();
   ret =ADC_init(&ADC_obj1) ;
   
}

void ADC_ISR_APP(void) {
    
     
    
}
void program1(void){
    
    ret= led_turn_on(&led1);
    __delay_ms(3);
    ret=led_turn_off(&led1) ;
     __delay_ms(3);
    
}
void program2(void){
    
    ret= led_turn_on(&led2);
    __delay_ms(3);
    ret=led_turn_off(&led2) ;
     __delay_ms(3);
    
}
void program3(void){
    
    
    ret=led_turn_off(&led1);
    ret=led_turn_off(&led2);
}