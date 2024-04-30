/* 
 * File:   MCAL_TIMER1.c
 * Author: sayr3
 *
 * Created on January 19, 2024, 1:09 AM
 */
/*section:***********includes*******************************/
#include "MCAL_TIMER1.h" 
/*section:*********static helper functions declaration*****************/ 
static inline Std_ReturnType TIMER1_MODE_CONFG(const TIMER1_CONFG_t*_timer1) ;
static inline Std_ReturnType TIMER1_OSC_CONFG(const TIMER1_CONFG_t*_timer1) ;

/*section:*********functions definition*****************/
static void(*TIMER1_INTERRUPT_HANDLER)(void)  =NULL ;

static uint_16 Timer1_preloaded_value = 0 ;




Std_ReturnType TIMER1_INITIALIZE(const TIMER1_CONFG_t*_timer1 ) {
     Std_ReturnType ret =E_OK ;
    if (NULL==_timer1){
        
        ret=E_NOT_OK  ;
        
    }
    else {
        TIMER1_MODULE_off()   ;
        
       ret &= TIMER1_MODE_CONFG(_timer1) ;
       TIMER1_PRESCALER_SELECT(_timer1->TIMER1_prescaler_value) ;  
       TIMER1_RW_16BIT_REGISTER_ENABLE()     ;
       ret &=  TIMER1_OSC_CONFG(_timer1) ;
       ret &=TIMER1_WRITE_VALUE(_timer1 ,_timer1->TIMER1_preload_value) ;
       Timer1_preloaded_value =(_timer1->TIMER1_preload_value) ;
         /************interrupt section******************/
       #if (TIMER1_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)
        TIMER1_INTERRUPT_DISABLE() ; 
        TIMER1_INTERRUPT_CLEAR_FLAG()  ;
        TIMER1_INTERRUPT_HANDLER =_timer1->TIMER1_interruptHandler ;
        #if (INRERRUPT_PRIORITY_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE) 
             INTERRUPT_PRIORITY_LEVELS_ENABLE() ;  
             if (interrupt_low_prioity==_timer1->TIMER1_priority ){
                 INTERRUPT_GLOBAL_INTERRUPT_ENABLE_LOW()  ;
                 TIMER1_INTERRUPT_SET_LOW_PRIORITY()  ;
                 
             }
             else if (interrupt_HIGH_prioity==_timer1->TIMER1_priority){
                 INTERRUPT_GLOBAL_INTERRUPT_ENABLE_HIGH()  ;
                 TIMER1_INTERRUPT_SET_HIGH_PRIORITY() ;
             }
             else {INTERRUPT_GLOBAL_INTERRUPT_ENABLE_LOW()  ; TIMER1_INTERRUPT_SET_LOW_PRIORITY()  ;}
             
        #else
       INTERRUPT_GLOBAL_INTERRUPT_ENABLE()  ;
       INTERRUPT_PERIPHERAL_INTERRUPT_ENABLE()   ;
        
        #endif
        
        TIMER1_INTERRUPT_ENABLE()  ;
       
       
        #endif
       
       
        
        
      TIMER1_MODULE_ON()  ;
        
    }
    
    
    
    return ret ;
    
    
    
}
Std_ReturnType TIMER1_DEINITIALIZE(const TIMER1_CONFG_t*_timer1 ) {
    
      Std_ReturnType ret =E_OK ;
    if (NULL==_timer1){
        
        ret=E_NOT_OK  ;
        
    }
    else {
        TIMER1_MODULE_off()   ;
          /***interrupt section*/
        #if (TIMER1_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)
             TIMER1_INTERRUPT_DISABLE() ; 
         
        #endif
        
    }
    
    
    
    return ret ;
    
    
}
Std_ReturnType TIMER1_WRITE_VALUE(const TIMER1_CONFG_t*_timer1  , uint_16 value) {
      Std_ReturnType ret =E_OK ;
    if (NULL==_timer1){
        
        ret=E_NOT_OK  ;
        
    }
    else {
        
          
        TMR1H =(uint_8)((value>>8)) ;
        TMR1L =(uint_8)(value) ;
        
        
        
        
    }
    
    
    
    return ret ;
    
    
    
}
Std_ReturnType TIMER1_READ_VALUE(const TIMER1_CONFG_t*_timer1  , uint_16 *return_value) {
    
     Std_ReturnType ret =E_OK ;
    uint_8 timer1_L = 0 ;
    uint_8 timer1_H = 0 ;
    if ((NULL==_timer1)||(NULL==return_value)){
        
        ret=E_NOT_OK  ;
        
    }
    else {
        
       timer1_L =TMR1L ;
       timer1_H =TMR1H ;
       *return_value =(uint_16)((timer1_H<<8)|(timer1_L)) ;
        
        
        
    }
    
    
    
    return ret ;
    
    
}
static inline Std_ReturnType TIMER1_MODE_CONFG(const TIMER1_CONFG_t*_timer1) {
    
    Std_ReturnType ret =E_OK ;
    if (NULL==_timer1){
        
        ret=E_NOT_OK  ;
        
    }
    else {
        
        if(_timer1->TIMER1_mode ==TIMER1_TIMER_MODE){
            
           TIMER1_TIMER_MODE_ENABLE()    ;
        }
        else if (_timer1->TIMER1_mode ==TIMER1_COUNTER_MODE){
            
           TIMER1_COUNTER_MODE_ENABLE() ;
            set_bit(TRISC ,_TRISC_TRISC0_POSITION) ; /*configure T013CKI as input*/
            
            if(_timer1->TIMER1_counter_mode==TIMER1_ASYNC_COUNTER_MODE){
                
              TIMER1_ASYNC_COUNTER_ENABLE()  ;
            }
            else if (_timer1->TIMER1_counter_mode==TIMER1_SYNC_COUNTER_MODE){
                TIMER1_SYNC_COUNTER_ENABLE()  ;
            }
            else {ret=E_NOT_OK ;}
            
        }
        
        else {  ret=E_NOT_OK ;} 
        
        
    }
    
    
    
    return ret ;
}
static inline Std_ReturnType TIMER1_OSC_CONFG(const TIMER1_CONFG_t*_timer1) {
    
     Std_ReturnType ret =E_OK ;
    if (NULL==_timer1){
        
        ret=E_NOT_OK  ;
        
    }
    else {
        
        if (_timer1->TIMER1_OSC_status ==TIMER1_OSC_ENABLE_cnfg ){
            
            
        TIMER1_OSC_ENABLE()    ;                         
 
        }
        else if (_timer1->TIMER1_OSC_status ==TIMER1_OSC_DISABLE_cnfg){
            
            TIMER1_OSC_DISABLE()  ;
        }
        
        
    } 
        
  
    
    
    return ret ;
    
    
    
    
}

void TIMER1_ISR(void) {
 #if (TIMER1_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)   
 TIMER1_INTERRUPT_CLEAR_FLAG() ;
#endif
 TMR1H = (uint_8)(Timer1_preloaded_value>>8) ;
 TMR1L = (uint_8)(Timer1_preloaded_value) ;
 if(TIMER1_INTERRUPT_HANDLER){
     
     TIMER1_INTERRUPT_HANDLER() ;
 }
 else {/*nothing*/}
    
    
}