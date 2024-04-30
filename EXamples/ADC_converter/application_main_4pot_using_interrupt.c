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
ADC_confg_t ADC_obj1 ={.ADC_channel =ADC_CHANNEL_AN0 ,.ADC_interrupthandler =ADC_ISR_APP ,
                      .A_D_port_confg =ADC_channel_AN0_to_AN8_analog_functionality ,
                      .aquisition_time=ADC_aquisition_time_4TAD ,
                      .clock_source=ADC_aquisition_time_12TAD ,
                      .result_format=RESULT_right_justified ,
                      .voltage_ref =voltage_ref_disable} ;

uint_16 adc_result0 = 0 ,adc_result1=0 , adc_result2=0 , adc_result3=0 ;

uint_8 ADC_result0_text[6] ;
uint_8 ADC_result1_text[6] ;
uint_8 ADC_result2_text[6] ;
uint_8 ADC_result3_text[6] ;
volatile uint_8 request =0;
int main() {
   
 
  general_initialization() ;
  ret = lcd_4bit_send_string_pos(&lcd1 ,1 ,7,"LCD TEST") ;
  __delay_ms(1000) ;
  ret =lcd_4bit_send_command(&lcd1,clear_display) ;
  ret = lcd_4bit_send_string_pos(&lcd1 ,1 , 1,"POT0: ") ;
  ret = lcd_4bit_send_string_pos(&lcd1 ,2 , 1,"POT1: ") ;
  ret = lcd_4bit_send_string_pos(&lcd1 ,3 , 1,"POT2: ") ;
  ret = lcd_4bit_send_string_pos(&lcd1 ,4 , 1,"POT3: ") ;
    
  while(1){
     
      if (request==0){
          
      ret= ADC_INTERRUPT_START_CONVERSION(&ADC_obj1 ,ADC_CHANNEL_AN0) ;
     
      }
      else if (request==1){
      ret= ADC_INTERRUPT_START_CONVERSION(&ADC_obj1 ,ADC_CHANNEL_AN1) ;
      
      }
      else if (request==2){
      ret = ADC_INTERRUPT_START_CONVERSION(&ADC_obj1 ,ADC_CHANNEL_AN2) ;
      
      
      
      }
     
      else if (request==3){
          
      ret= ADC_INTERRUPT_START_CONVERSION(&ADC_obj1 ,ADC_CHANNEL_AN3) ;
      
          
      }
      else {
          
          /*nothing*/
      
      }
     
         if (511==adc_result0){
          
          ret =led_turn_on(&led1) ;
          
          }
          else {
              
          ret =led_turn_off(&led1) ;

          }
      
      
      ret = convert_uint_16_to_string(adc_result0 ,ADC_result0_text) ;
      ret = lcd_4bit_send_string_pos(&lcd1 ,1 , 7,ADC_result0_text) ;
      
      ret = convert_uint_16_to_string(adc_result1 ,ADC_result1_text) ;
      ret = lcd_4bit_send_string_pos(&lcd1 ,2 , 7,ADC_result1_text) ;
      
      ret = lcd_4bit_send_string_pos(&lcd1 ,3 , 7,ADC_result2_text) ;
      ret=convert_uint_16_to_string(adc_result2 ,ADC_result2_text) ;
      
      ret = convert_uint_16_to_string(adc_result3 ,ADC_result3_text) ;
      ret = lcd_4bit_send_string_pos(&lcd1 ,4 , 7,ADC_result3_text) ;
     
      }
     
          
          
      
    
      
      
    return (EXIT_SUCCESS);
}
 
  
  
  

void general_initialization(void) {
    
   ECUAL_peripherals_initialization();
   ret =ADC_init(&ADC_obj1) ;
   
}

void ADC_ISR_APP(void) {
    
      if (request==0){
       ret=ADC_Get_conversionRsult(&ADC_obj1,&adc_result0) ;
       request = 1 ;
      }
      else if (request==1){
      ret=ADC_Get_conversionRsult(&ADC_obj1,&adc_result1) ;
         request = 2 ;
      }
      else if (request==2){
      ret=ADC_Get_conversionRsult(&ADC_obj1,&adc_result2) ;
         request = 3 ;
      }
      else if (request==3){
      ret=ADC_Get_conversionRsult(&ADC_obj1,&adc_result3) ;
         request = 0 ;
      }
      else {/*nothing*/}
          
   
    
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