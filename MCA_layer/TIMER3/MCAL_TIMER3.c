/* 
 * File:   MCAL_TIMER3.c
 * Author: sayr3
 *
 * Created on January 20, 2024, 9:07 PM
 */
/*section:***********includes*******************************/
#include"MCAL_TIMER3.h"
/*section:*********static helper functions declaration*****************/ 
static inline Std_ReturnType TIMER3_MODE_CONFG(const TIMER3_CONFG_t*_timer3) ;
/*section:*********functions definition*****************/
static void(*TIMER3_INTERRUPT_HANDLER)(void)  =NULL ;

static uint_16 Timer3_preloaded_value = 0 ;

/**
 * 
 * @param _timer3
 * @return 
 */
Std_ReturnType TIMER3_INITIALIZE(const TIMER3_CONFG_t*_timer3 ){
      Std_ReturnType ret =E_OK ;
    if (NULL==_timer3){
        
        ret=E_NOT_OK  ;
        
    }
    else {
        TIMER3_MODULE_off()   ;
        
       ret &= TIMER3_MODE_CONFG(_timer3) ;
       TIMER3_PRESCALER_SELECT(_timer3->TIMER3_prescaler_value) ;  
       TIMER3_RW_16BIT_REGISTER_ENABLE()     ;
       ret &=TIMER3_WRITE_VALUE(_timer3 ,_timer3->TIMER3_preload_value) ;
       Timer3_preloaded_value =(_timer3->TIMER3_preload_value) ;
         /************interrupt section******************/
       #if (TIMER3_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)
        TIMER3_INTERRUPT_DISABLE() ; 
        TIMER3_INTERRUPT_CLEAR_FLAG()  ;
        TIMER3_INTERRUPT_HANDLER =_timer3->TIMER3_interruptHandler ;
        #if (INRERRUPT_PRIORITY_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE) 
             INTERRUPT_PRIORITY_LEVELS_ENABLE() ;  
             if (interrupt_low_prioity==_timer3->TIMER3_priority ){
                 INTERRUPT_GLOBAL_INTERRUPT_ENABLE_LOW()  ;
                 TIMER3_INTERRUPT_SET_LOW_PRIORITY()  ;
                 
             }
             else if (interrupt_HIGH_prioity==_timer3->TIMER3_priority){
                 INTERRUPT_GLOBAL_INTERRUPT_ENABLE_HIGH()  ;
                 TIMER3_INTERRUPT_SET_HIGH_PRIORITY() ;
             }
             else {INTERRUPT_GLOBAL_INTERRUPT_ENABLE_LOW()  ; TIMER3_INTERRUPT_SET_LOW_PRIORITY()  ;}
             
        #else
       INTERRUPT_GLOBAL_INTERRUPT_ENABLE()  ;
       INTERRUPT_PERIPHERAL_INTERRUPT_ENABLE()   ;
        
        #endif
        
        TIMER3_INTERRUPT_ENABLE()  ;
       
       
        #endif
       
       
        
        
      TIMER3_MODULE_ON()  ;
        
    }
    
    
    
    return ret ;
    
    
    
}
/**
 * 
 * @param _timer3
 * @return 
 */
Std_ReturnType TIMER3_DEINITIALIZE(const TIMER3_CONFG_t*_timer3 ) {
      
      Std_ReturnType ret =E_OK ;
    if (NULL==_timer3){
        
        ret=E_NOT_OK  ;
        
    }
    else {
        TIMER3_MODULE_off()   ;
          /***interrupt section*/
        #if (TIMER3_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)
             TIMER3_INTERRUPT_DISABLE() ; 
         
        #endif
        
    }
    
    
    
    return ret ;
    
    
}
/**
 * 
 * @param _timer3
 * @param value
 * @return 
 */
Std_ReturnType TIMER3_WRITE_VALUE(const TIMER3_CONFG_t*_timer3  , uint_16 value) {
    
        Std_ReturnType ret =E_OK ;
    if (NULL==_timer3){
        
        ret=E_NOT_OK  ;
        
    }
    else {
        
          
        TMR3H =(uint_8)((value>>8)) ;
        TMR3L =(uint_8)(value) ;
        
        
        
        
    }
    
    
    
    return ret ;
    
    
}
/**
 * 
 * @param _timer3
 * @param return_value
 * @return 
 */
Std_ReturnType TIMER3_READ_VALUE(const TIMER3_CONFG_t*_timer3  , uint_16 *return_value) {
      
     Std_ReturnType ret =E_OK ;
    uint_8 timer3_L = 0 ;
    uint_8 timer3_H = 0 ;
    if ((NULL==_timer3)||(NULL==return_value)){
        
        ret=E_NOT_OK  ;
        
    }
    else {
        
       timer3_L =TMR3L ;
       timer3_H =TMR3H ;
       *return_value =(uint_16)((timer3_H<<8)|(timer3_L)) ;
        
        
        
    }
    
    
    
    return ret ;
    
    
}

static inline Std_ReturnType TIMER3_MODE_CONFG(const TIMER3_CONFG_t*_timer3) {
    
     
    Std_ReturnType ret =E_OK ;
    if (NULL==_timer3){
        
        ret=E_NOT_OK  ;
        
    }
    else {
        
        if(_timer3->TIMER3_mode ==TIMER3_TIMER_MODE){
            
           TIMER3_TIMER_MODE_ENABLE()    ;
        }
        else if (_timer3->TIMER3_mode ==TIMER3_COUNTER_MODE){
            
           TIMER3_COUNTER_MODE_ENABLE() ;
            set_bit(TRISC ,_TRISC_TRISC0_POSITION) ; /*configure T13CKI as input*/
            
            if(_timer3->TIMER3_counter_mode==TIMER3_ASYNC_COUNTER_MODE){
                
              TIMER3_ASYNC_COUNTER_ENABLE()  ;
            }
            else if (_timer3->TIMER3_counter_mode==TIMER3_SYNC_COUNTER_MODE){
                TIMER3_SYNC_COUNTER_ENABLE()  ;
            }
            else {ret=E_NOT_OK ;}
            
        }
        
        else {  ret=E_NOT_OK ;} 
        
        
    }
    
    
    
    return ret ;
    
    
}
void TIMER3_ISR(void) {
 #if (TIMER3_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)   
 TIMER3_INTERRUPT_CLEAR_FLAG() ;
#endif
 TMR3H = (uint_8)(Timer3_preloaded_value>>8) ;
 TMR3L = (uint_8)(Timer3_preloaded_value) ;
 if(TIMER3_INTERRUPT_HANDLER){
     
     TIMER3_INTERRUPT_HANDLER() ;
 }
 else {/*nothing*/}
    
    
}