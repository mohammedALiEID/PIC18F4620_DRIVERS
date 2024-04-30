/* 
 * File:   MCAL_ADC.c
 * Author: sayr3
 *
 * Created on January 8, 2024, 6:52 PM
 */
/*section:***********includes*******************************/
#include "MCAL_ADC.h"
/*section:*********static helper functions declaration*****************/
static inline void ADC_configure_channel_as_input(ADC_channel_select_t channel) ;
static inline void ADC_configure_voltage_ref(const ADC_confg_t*_ADC) ;
static inline void ADC_configure_result_format(const ADC_confg_t*_ADC);

static void (*ADC_INTERRUPT_HANDLER)(void)=NULL ;
/*section:*********functions definition*****************/

/**
 * @breif initialize ADC converter
 * @preconditions NON
 * @param _ADC pointer to ADC configuration
 * @return status of the function 
            (E_OK) the function done successfully 
            (E_NOT_OK) the function has issue to do the action
 */
Std_ReturnType ADC_init(const ADC_confg_t*_ADC){
    Std_ReturnType ret =E_OK ;
    if (NULL==_ADC){
        
        ret=E_NOT_OK  ;
        
    }
    else {
        ADC_MODULE_OFF()   ;
        
        ADCON2bits.ACQT =(_ADC->aquisition_time) ;
        ADCON2bits.ADCS =(_ADC->clock_source) ;
        ADCON0bits.CHS =(_ADC->ADC_channel) ;
        ADC_configure_channel_as_input(_ADC->ADC_channel) ;
        ADC_configure_voltage_ref(_ADC );
        ADC_configure_result_format(_ADC) ;
        ADC_analog_digital_port_confg((_ADC->A_D_port_confg)) ;
        
       #if (ADC_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)
        ADC_INTERRUPT_DISABLE()  ;
        ADC_INTERRUPT_CLEAR_FLAG()   ;
        ADC_INTERRUPT_HANDLER =_ADC->ADC_interrupthandler ;
        #if (INRERRUPT_PRIORITY_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)
             INTERRUPT_PRIORITY_LEVELS_ENABLE()  ; 
        if (interrupt_low_prioity==_ADC->priorty){
            INTERRUPT_GLOBAL_INTERRUPT_ENABLE_LOW() ;
            ADC_INTERRUPT_SET_LOW_PRIORITY() ;
        }
        else if (interrupt_HIGH_prioity==_ADC->priorty){
            INTERRUPT_GLOBAL_INTERRUPT_ENABLE_HIGH() ;
            ADC_INTERRUPT_SET_HIGH_PRIORITY() ;
            
        }
        #else
      INTERRUPT_GLOBAL_INTERRUPT_ENABLE() ;
      INTERRUPT_PERIPHERAL_INTERRUPT_ENABLE() ;
        #endif
  
         ADC_INTERRUPT_ENABLE()  ;
       #endif
        
        ADC_MODULE_ON()  ;
        
        
        
    }
    
    
    
    return ret ;
    
}
/**
 * 
 * @param _ADC
 * @return 
 */
Std_ReturnType ADC_deinit(const ADC_confg_t*_ADC){
    Std_ReturnType ret =E_OK ;
    if (NULL==_ADC){
        
        ret=E_NOT_OK  ;
        
    }
    else {
        
         ADC_MODULE_OFF()   ;
       #if (ADC_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)

          ADC_INTERRUPT_DISABLE()  ;
          ADC_INTERRUPT_CLEAR_FLAG()   ;
         
        
       #endif
        
    }
    
    
    
    return ret ;
    
}
/**
 * 
 * @param _ADC
 * @param channel
 * @return 
 */
Std_ReturnType ADC_select_channel(const ADC_confg_t*_ADC ,ADC_channel_select_t channel) {
    
    Std_ReturnType ret =E_OK ;
    if (NULL==_ADC){
        
        ret=E_NOT_OK  ;
        
    }
    else {
         ADCON0bits.CHS =(channel) ;
         ADC_configure_channel_as_input(channel) ;
        
    }
    
    
    
    return ret ;
}
/**
 * 
 * @param _ADC
 * @return 
 */
Std_ReturnType ADC_start_conversion(const ADC_confg_t*_ADC) {
    Std_ReturnType ret =E_OK ;
    if (NULL==_ADC){
        
        ret=E_NOT_OK  ;
        
    }
    else {
        
         ADC_initalize_conversion()  ;
        
    }
    
    
    
    return ret ;
    
}
/**
 * @breif get conversion status complete or not
 * @param _ADC pointer to ADC configuration
 * @param conversion_status return conversion status 
 * conversion_status: CONVERSION_NOT_COMPLETE conversion is not complete
 * conversion_status: CONVERSION_COMPLETE conversion is complete
 * @preconditions : ADC_init() , ADC_select_channel () ADC_start_conversion()
 * @return status of the function 
            (E_OK) the function done successfully 
            (E_NOT_OK) the function has issue to do the action
 */

Std_ReturnType ADC_Get_conversionStatus(const ADC_confg_t*_ADC ,conversion_status_t *conversion_status) {
    
    Std_ReturnType ret =E_OK ;
    if ((NULL==_ADC)||(NULL==conversion_status)){
        
        ret=E_NOT_OK  ;
        
    }
    else {
        
        *conversion_status = (conversion_status_t)(!(ADC_conversion_status())) ;
        
    }
    
    
    
    return ret ;
}
/**
 * @breif get conversion result 
 * @param _ADC pointer to ADC configuration
 * @param conversion_result return conversion result
 * @preconditions : ADC_init() ,ADC_select_channel, ADC_start_conversion() , conversion status is complete
 * @return status of the function 
            (E_OK) the function done successfully 
            (E_NOT_OK) the function has issue to do the action

 */
Std_ReturnType ADC_Get_conversionRsult(const ADC_confg_t*_ADC ,uint_16 *conversion_result) {
   Std_ReturnType ret =E_OK ;
    if ((NULL==_ADC)||(NULL==conversion_result)){
        
        ret=E_NOT_OK  ;
        
    }
    else {
        if (_ADC->result_format == RESULT_right_justified){
       
            *conversion_result = (uint_16)((ADRESH<<8)|(ADRESL)) ;
       
    }
    
    else if (_ADC->result_format == RESULT_left_justified){
          
          *conversion_result = (uint_16)((ADRESH<<2)|(ADRESL>>6)) ;
    }
    else {
        
         *conversion_result = (uint_16)((ADRESH<<8)|(ADRESL)) ;
    }
        
        
        
        
    }
    
    
    
    return ret ;
    
}
/**
 * 
 * @param _ADC
 * @param channel
 * @param conversion_result
 * @preconditions : ADC_init()
 * @return 
 */
Std_ReturnType ADC_Get_conversion_one_step_blocking(const ADC_confg_t*_ADC ,ADC_channel_select_t channel ,
                                           uint_16 *conversion_result) {
   Std_ReturnType ret =E_OK ;
    if ((NULL==_ADC)||(NULL==conversion_result)){
        
        ret=E_NOT_OK  ;
        
    }
    else {
        
        ret &= ADC_select_channel(_ADC ,channel) ;
        ret &= ADC_start_conversion(_ADC) ;
        
        while (ADCON0bits.GO_nDONE){ /*this while cause blocking until the conversion end*/
            
        }
       ret&= ADC_Get_conversionRsult(_ADC ,conversion_result) ;
        
        
    }
    
    
    
    return ret ;
    
}
/**
 * 
 * @param _ADC
 * @param channel
 * @return 
 */
Std_ReturnType ADC_INTERRUPT_START_CONVERSION(const ADC_confg_t*_ADC ,ADC_channel_select_t channel) {
    
    Std_ReturnType ret =E_OK ;
    if ((NULL==_ADC)){
        
        ret=E_NOT_OK  ;
        
    }
    else {
        
        ret &= ADC_select_channel(_ADC ,channel) ;
        ret &= ADC_start_conversion(_ADC) ;
        
       
        
    }
    
    
    
    return ret ;
    
    
    
    
}
static inline void ADC_configure_channel_as_input(ADC_channel_select_t channel) {
    
    switch(channel){
        
        case ADC_CHANNEL_AN0 :set_bit(TRISA ,_TRISA_RA0_POSITION) ;break ;
        case ADC_CHANNEL_AN1 :set_bit(TRISA ,_TRISA_RA1_POSITION) ;break ;
        case ADC_CHANNEL_AN2 :set_bit(TRISA ,_TRISA_RA2_POSITION) ;break ;
        case ADC_CHANNEL_AN3 :set_bit(TRISA ,_TRISA_RA3_POSITION) ;break ;
        case ADC_CHANNEL_AN4 :set_bit(TRISA ,_TRISA_RA5_POSITION) ;break ;
        case ADC_CHANNEL_AN5 :set_bit(TRISE ,_TRISE_RE0_POSITION) ;break ;
        case ADC_CHANNEL_AN6 :set_bit(TRISE ,_TRISE_RE1_POSITION) ;break ;
        case ADC_CHANNEL_AN7 :set_bit(TRISE ,_TRISE_RE2_POSITION) ;break ;
        case ADC_CHANNEL_AN8 :set_bit(TRISB ,_TRISB_RB2_POSITION) ;break ;
        case ADC_CHANNEL_AN9 :set_bit(TRISB ,_TRISB_RB3_POSITION) ;break ;
        case ADC_CHANNEL_AN10 :set_bit(TRISB ,_TRISB_RB1_POSITION) ;break ;
        case ADC_CHANNEL_AN11 :set_bit(TRISB ,_TRISB_RB4_POSITION) ;break ;
        case ADC_CHANNEL_AN12 :set_bit(TRISB ,_TRISB_RB0_POSITION) ;break ;
        
        default :  break ;
        
    }
    
    
}
static inline void ADC_configure_voltage_ref(const ADC_confg_t*_ADC){
    
    if (_ADC->voltage_ref == voltage_ref_enable){
        
        ADC_voltage_ref_enable()   ;
    }
    
    else if (_ADC->voltage_ref == voltage_ref_disable){
         ADC_voltage_ref_disable()   ;
        
    }
    else {
          ADC_voltage_ref_disable()   ;
        
    }
    
    
    
}
static inline void ADC_configure_result_format(const ADC_confg_t*_ADC){
    
    if (_ADC->result_format == RESULT_right_justified){
        ADC_RESULT_right_justified() ;
       
    }
    
    else if (_ADC->result_format == RESULT_left_justified){
          ADC_RESULT_left_justified() ;
        
    }
    else {
        ADC_RESULT_right_justified() ;  
        
    }
    
    
    
}



void ADC_ISR(void){
    #if (ADC_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)
         ADC_INTERRUPT_CLEAR_FLAG()   ;
    #endif
   if(ADC_INTERRUPT_HANDLER){
     ADC_INTERRUPT_HANDLER() ;
   }
     else{/*nothing*/}

}