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
                      .A_D_port_confg =ADC_channel_AN0_to_AN11_analog_functionality ,
                      .aquisition_time=ADC_aquisition_time_12TAD ,
                      .clock_source=ADC_clock_source_FOSC_OVER_2 ,
                      .result_format=RESULT_left_justified ,
                      .voltage_ref =voltage_ref_disable} ;

uint_16 adc_result0 ,adc_result1 ,adc_result2 , adc_result12 ;


int main() {
   
 
  general_initialization() ;

    
  while(1){
     
      ret =ADC_Get_conversion_one_step_blocking(&ADC_obj1 ,ADC_CHANNEL_AN0 ,&adc_result0) ;
      
      ret =ADC_Get_conversion_one_step_blocking(&ADC_obj1 ,ADC_CHANNEL_AN1 ,&adc_result1) ;
      
      ret =ADC_Get_conversion_one_step_blocking(&ADC_obj1 ,ADC_CHANNEL_AN2 ,&adc_result2) ;
      
      ret =ADC_Get_conversion_one_step_blocking(&ADC_obj1 ,ADC_CHANNEL_AN12 ,&adc_result12) ;

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