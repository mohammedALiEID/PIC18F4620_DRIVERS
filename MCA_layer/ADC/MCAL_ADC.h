/* 
 * File:   MCAL_ADC.h
 * Author: sayr3
 *
 * Created on January 8, 2024, 6:52 PM
 */

#ifndef MCAL_ADC_H
#define	MCAL_ADC_H

/*section:*********includes*******************************/
#include "MCAL_ADC_confg.h"
#include <pic18f4620.h> 
#include "../mcal_std_types.h" 
#include "../GPIO/mcal_GPIO.h" 
#include "../interrupt/mcal_internal_interrupt.h"

/*section:*********macro declaration*********************/
/* 
 * @breif PCFG3:PCFG0: A/D Port Configuration Control bits
 *  ADC_channel_AN0_to_AN3_analog_functionality  : Pins AN0 , AN1 ,AN2 ,AN3 are analog functionality
 * the rest AN4 ,AN5 ,AN6,AN7,AN8,AN9 ,AN10,AN11 ,AN12 are digital functionality
 * 
 */
#define ADC_channel_AN0_analog_functionality          0XE
#define ADC_channel_AN0_to_AN1_analog_functionality   0XD
#define ADC_channel_AN0_to_AN2_analog_functionality   0XC
#define ADC_channel_AN0_to_AN3_analog_functionality   0XB
#define ADC_channel_AN0_to_AN4_analog_functionality   0XA
#define ADC_channel_AN0_to_AN5_analog_functionality   0X9
#define ADC_channel_AN0_to_AN6_analog_functionality   0X8
#define ADC_channel_AN0_to_AN7_analog_functionality   0X7
#define ADC_channel_AN0_to_AN8_analog_functionality   0X6
#define ADC_channel_AN0_to_AN9_analog_functionality   0X5
#define ADC_channel_AN0_to_AN10_analog_functionality  0X4
#define ADC_channel_AN0_to_AN11_analog_functionality  0X3
#define ADC_channel_ALL_analog_functionality          0X2
#define ADC_channel_ALL_Digital_functionality         0XF

#define RESULT_right_justified                     0x1U
#define RESULT_left_justified                      0x0U
#define voltage_ref_enable                         0x1U 
#define voltage_ref_disable                        0x0U
/*section:*********macro functions declaration **********/

#define ADC_MODULE_ON()                          (ADCON0bits.ADON = 1)
#define ADC_MODULE_OFF()                         (ADCON0bits.ADON = 0) 
#define ADC_initalize_conversion()               (ADCON0bits.GO_nDONE = 1) 
#define ADC_conversion_status()                  (ADCON0bits.GO_nDONE ) 
#define ADC_analog_digital_port_confg(_confg)    (ADCON1bits.PCFG =_confg)
#define ADC_RESULT_right_justified()             (ADCON2bits.ADFM = 1) 
#define ADC_RESULT_left_justified()              (ADCON2bits.ADFM = 0) 
 /* 
 * @breif Voltage Reference Configuration bits
 * ADC_voltage_ref_enable() : Enable external voltage ref VREF- (AN2) / VREF+ (AN3)
 * ADC_voltage_ref_disable() : Use VSS VDD as voltage reference
 */


#define ADC_voltage_ref_enable()     do{ADCON1bits.VCFG0 = 1;\
                                        ADCON1bits.VCFG1 = 1 ;\
                                        }while(0)

#define ADC_voltage_ref_disable()    do{ADCON1bits.VCFG0 = 0;\
                                        ADCON1bits.VCFG1 = 0 ;\
                                        }while(0)




/*section:*********data types ***************************/
typedef enum {
    
          ADC_CHANNEL_AN0 = 0 ,  
          ADC_CHANNEL_AN1  ,
          ADC_CHANNEL_AN2  ,
          ADC_CHANNEL_AN3  ,
          ADC_CHANNEL_AN4  ,
          ADC_CHANNEL_AN5  ,
          ADC_CHANNEL_AN6  ,
          ADC_CHANNEL_AN7  ,
          ADC_CHANNEL_AN8  ,
          ADC_CHANNEL_AN9  ,
          ADC_CHANNEL_AN10 ,
          ADC_CHANNEL_AN11 ,
          ADC_CHANNEL_AN12 ,
    
}ADC_channel_select_t;

/* 
 * @breif A/D Acquisition Time Select bits
 * @NOTE : It is the time which holding capacitor take to charge
 */
typedef enum {
   ADC_aquisition_time_0TAD = 0 , 
   ADC_aquisition_time_2TAD ,
   ADC_aquisition_time_4TAD  , 
   ADC_aquisition_time_6TAD ,
   ADC_aquisition_time_8TAD , 
   ADC_aquisition_time_12TAD ,
   ADC_aquisition_time_16TAD ,
   ADC_aquisition_time_20TAD 
}ADC_aquisition_time_t;
/* 
 * @breif A/D Conversion Clock Select bits
 * @NOTE : select the frequency of the clock source of ADC to determine TAD
 */
typedef enum {
     ADC_clock_source_FOSC_OVER_2 =0 ,
     ADC_clock_source_FOSC_OVER_8 ,
     ADC_clock_source_FOSC_OVER_32 ,
     ADC_FRC_clock_derived_from_AD_RC_oscillator,        
     ADC_clock_source_FOSC_OVER_4 ,
     ADC_clock_source_FOSC_OVER_16 ,
     ADC_clock_source_FOSC_OVER_64 , 
             
}ADC_clock_source_t;

typedef enum {
    CONVERSION_NOT_COMPLETE =0 ,
    CONVERSION_COMPLETE 
  
}conversion_status_t;



typedef struct {
     #if (ADC_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)
          void (*ADC_interrupthandler)(void) ;
    #if (INRERRUPT_PRIORITY_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)
       interrupt_priorty_t priorty ;
    #endif
    #endif
    ADC_clock_source_t clock_source ;
    ADC_aquisition_time_t aquisition_time ;
    ADC_channel_select_t  ADC_channel ;
    uint_8 voltage_ref : 1 ;
    uint_8 result_format : 1 ;
    uint_8 A_D_port_confg : 4 ;
    uint_8 ADC_reserved  : 2 ;
    
}ADC_confg_t;

/*section:*********functions declaration*****************/
Std_ReturnType ADC_init(const ADC_confg_t*_ADC);
Std_ReturnType ADC_deinit(const ADC_confg_t*_ADC);
Std_ReturnType ADC_select_channel(const ADC_confg_t*_ADC ,ADC_channel_select_t channel) ;
Std_ReturnType ADC_start_conversion(const ADC_confg_t*_ADC) ;
Std_ReturnType ADC_Get_conversionStatus(const ADC_confg_t*_ADC ,conversion_status_t *conversion_status) ;
Std_ReturnType ADC_Get_conversionRsult(const ADC_confg_t*_ADC ,uint_16 *conversion_result) ;
Std_ReturnType ADC_Get_conversion_one_step_blocking(const ADC_confg_t*_ADC ,ADC_channel_select_t channel ,
                                           uint_16 *conversion_result) ;
Std_ReturnType ADC_INTERRUPT_START_CONVERSION(const ADC_confg_t*_ADC ,ADC_channel_select_t channel) ;
                                           

#endif	/* MCAL_ADC_H */

