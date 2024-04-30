/* 
 * File:   MCAL_TIMER0.c
 * Author: sayr3
 *
 * Created on January 15, 2024, 3:59 AM
 */
/*section:***********includes*******************************/
#include "MCAL_TIMER0.h"
/*section:*********static helper functions declaration*****************/ 
static inline Std_ReturnType TIMER0_prescaler_CONFG(const TIMER0_CONFG_t*_timer0) ;
static inline Std_ReturnType TIMER0_MODE_CONFG(const TIMER0_CONFG_t*_timer0) ;
static inline Std_ReturnType TIMER0_register_size_CONFG(const TIMER0_CONFG_t*_timer0) ;
/*section:*********functions definition*****************/
static void(*TIMER0_INTERRUPT_HANDLER)(void)  =NULL ;

static uint_16 Timer0_preloaded_value = 0 ;
 



/**
 * 
 * @param _timer0
 * @return 
 */
Std_ReturnType TIMER0_INITIALIZE(const TIMER0_CONFG_t*_timer0 ) {
    Std_ReturnType ret =E_OK ;
    if (NULL==_timer0){
        
        ret=E_NOT_OK  ;
        
    }
    else {
        TIMER0_MODULE_off() ;
        
       ret&= TIMER0_MODE_CONFG(_timer0) ;
       ret&=TIMER0_register_size_CONFG(_timer0) ;
       ret&=TIMER0_prescaler_CONFG(_timer0) ; 
       ret&=TIMER0_WRITE_VALUE(_timer0 ,_timer0->TIMER0_preloaded_value) ;
        Timer0_preloaded_value =_timer0->TIMER0_preloaded_value ;
       /************interrupt section******************/
       #if (TIMER0_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)
        TIMER0_INTERRUPT_DISABLE() ; 
        TIMER0_INTERRUPT_CLEAR_FLAG()  ;
        TIMER0_INTERRUPT_HANDLER =_timer0->TIMER0_interruptHandler ;
        #if (INRERRUPT_PRIORITY_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE) 
             INTERRUPT_PRIORITY_LEVELS_ENABLE() ;  
             if (interrupt_low_prioity==_timer0->TIMER0_priority ){
                 INTERRUPT_GLOBAL_INTERRUPT_ENABLE_LOW()  ;
                 TIMER0_INTERRUPT_SET_LOW_PRIORITY()  ;
                 
             }
             else if (interrupt_HIGH_prioity==_timer0->TIMER0_priority){
                 INTERRUPT_GLOBAL_INTERRUPT_ENABLE_HIGH()  ;
                 TIMER0_INTERRUPT_SET_HIGH_PRIORITY() ;
             }
             else {INTERRUPT_GLOBAL_INTERRUPT_ENABLE_LOW()  ; TIMER0_INTERRUPT_SET_LOW_PRIORITY()  ;}
             
        #else
       INTERRUPT_GLOBAL_INTERRUPT_ENABLE()  ;
       INTERRUPT_PERIPHERAL_INTERRUPT_ENABLE()   ;
        
        #endif
        
        TIMER0_INTERRUPT_ENABLE()  ;
       
       
        #endif
       
       
        
        TIMER0_MODULE_ON() ;
        
        
    }
    
    
    
    return ret ;
    
} 
/**
 * 
 * @param timer0
 * @return 
 */
Std_ReturnType TIMER0_DEINITIALIZE(const TIMER0_CONFG_t*_timer0 )  {
    Std_ReturnType ret =E_OK ;
    if (NULL==_timer0){
        
        ret=E_NOT_OK  ;
        
    }
    else {
        
         TIMER0_MODULE_off() ; 
         /***interrupt section*/
        #if (TIMER0_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)
             TIMER0_INTERRUPT_DISABLE() ; 
         
        #endif
        
        
        
    }
    
    
    
    return ret ;
    
    
}
/**
 * 
 * @param timer0
 * @param value
 * @return 
 */
Std_ReturnType TIMER0_WRITE_VALUE(const TIMER0_CONFG_t*_timer0  , uint_16 value)  {
    
    Std_ReturnType ret =E_OK ;
    if (NULL==_timer0){
        
        ret=E_NOT_OK  ;
        
    }
    else {
        
        TMR0H =(uint_8)((value>>8)) ;
        TMR0L =(uint_8)(value) ;
        
        
        
        
        
    }
    
    
    
    return ret ;
    
} 

/**
 * 
 * @param timer0
 * @param return_value
 * @return 
 */
Std_ReturnType TIMER0_READ_VALUE(const TIMER0_CONFG_t*_timer0  , uint_16 *return_value)  {
    Std_ReturnType ret =E_OK ;
    uint_8 timer0_L = 0 ;
    uint_8 timer0_H = 0 ;
    if ((NULL==_timer0)||(NULL==return_value)){
        
        ret=E_NOT_OK  ;
        
    }
    else {
        
       timer0_L =TMR0L ;
       timer0_H =TMR0H ;
       *return_value =(uint_16)((timer0_H<<8)|(timer0_L)) ;
        
        
        
    }
    
    
    
    return ret ;
    
} 
    
static inline Std_ReturnType TIMER0_prescaler_CONFG(const TIMER0_CONFG_t*_timer0) {
    
    Std_ReturnType ret =E_OK ;
    if (NULL==_timer0){
        
        ret=E_NOT_OK  ;
        
    }
    else {
        if (TIMER0_PRESCALER_DISABLE_cfg==_timer0->TIMER0_prescaler_status){
            
           TIMER0_PRESCALER_DISABLE()  ;
        }
        else if (TIMER0_PRESCALER_ENABLE_cfg==_timer0->TIMER0_prescaler_status){
            
             TIMER0_PRESCALER_ENABLE()   ;
        T0CONbits.T0PS =_timer0->TIMER0_prescaler_value ;
        }
        else {ret=E_NOT_OK  ;}
        
    }
    
    
    
    return ret ;
    
}
static inline Std_ReturnType TIMER0_MODE_CONFG(const TIMER0_CONFG_t*_timer0) {
    
    Std_ReturnType ret =E_OK ;
    if (NULL==_timer0){
        
        ret=E_NOT_OK  ;
        
    }
    else {
        
        if(_timer0->TIMER0_mode ==TIMER0_TIMER_MODE){
            
           TIMER0_TIMER_MODE_ENABLE() ;
        }
        else if (_timer0->TIMER0_mode ==TIMER0_COUNTER_MODE){
            
            TIMER0_COUNTER_MODE_ENABLE() ;
            set_bit(TRISA ,_TRISA_TRISA4_POSITION) ; /*configure T0CKI as input*/
            if(_timer0->TIMER0_COUNTER_Edge==TIMER0_FALLING_EDGE){
                
                TIMER0_FALLING_EDGE_ENABLE() ;
            }
            else if (_timer0->TIMER0_COUNTER_Edge==TIMER0_RISING_EDGE){
                TIMER0_RISING_EDGE_ENABLE()  ;
            }
            else {ret=E_NOT_OK ;}
            
        }
        
        else {  ret=E_NOT_OK ;} 
        
        
    }
    
    
    
    return ret ;
}
static inline Std_ReturnType TIMER0_register_size_CONFG(const TIMER0_CONFG_t*_timer0) {
    
    Std_ReturnType ret =E_OK ;
    if (NULL==_timer0){
        
        ret=E_NOT_OK  ;
        
    }
    else {
        if (TIMER0_8BIT_REGISTER==_timer0->TIMER0_register_size){
            
            TIMER0_8BIT_REGISTER_MODE() ;
        }
        else if (TIMER0_16BIT_REGISTER==_timer0->TIMER0_register_size){
            
            TIMER0_16BIT_REGISTER_MODE() ;
        }
        else { ret=E_NOT_OK  ;}
        
        
        
    }
    
    
    
    return ret ;
}
void TIMER0_ISR(void) {
 #if (TIMER0_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)   
 TIMER0_INTERRUPT_CLEAR_FLAG() ;
#endif
 TMR0H =(uint_8)(Timer0_preloaded_value>>8) ;
 TMR0L = (uint_8)(Timer0_preloaded_value) ;
 if(TIMER0_INTERRUPT_HANDLER){
     
     TIMER0_INTERRUPT_HANDLER() ;
 }
 else {/*nothing*/}
    
    
}