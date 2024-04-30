/* 
 * File:   MCAL_TIMER2.c
 * Author: sayr3
 *
 * Created on January 20, 2024, 9:07 PM
 */

 /*section:***********includes*******************************/
  #include"MCAL_TIMER2.h"
/*section:*********static helper functions declaration*****************/ 

/*section:*********functions definition*****************/
static void(*TIMER2_INTERRUPT_HANDLER)(void)  =NULL ;

static uint_8 Timer2_preloaded_value = 0 ;

/**
 * 
 * @param _timer2
 * @return 
 */
Std_ReturnType TIMER2_INITIALIZE(const TIMER2_CONFG_t*_timer2 ) {
      
      Std_ReturnType ret =E_OK ;
    if (NULL==_timer2){
        
        ret=E_NOT_OK  ;
        
    }
    else {
        
        TIMER2_MODULE_off()  ;
        
        TIMER2_PRESCALER_SELECT(_timer2->TIMER2_prescaler_value) ;
        
        TIMER2_POSTSCALER_SELECT(_timer2->TIMER2_postscaler_value) ;
        
        TMR2 =(_timer2->TIMER2_preload_value) ; /*note in timer2 you can store in TMR2 OR PR2 but each
                                                 has different equation "look note book "if you want to use TIMER CALCULATOR 
                                                 store in PR2 to get accurate value  it is prefered to use TMR2 
                                                 CUZ in CCP module we will write at PR2 to prevent any conflict use 
                                                 here TMR2 and its equation to get accurate value **/
        Timer2_preloaded_value =(_timer2->TIMER2_preload_value) ;
        
           /************interrupt section******************/
       #if (TIMER2_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)
        TIMER2_INTERRUPT_DISABLE() ; 
        TIMER2_INTERRUPT_CLEAR_FLAG()  ;
        TIMER2_INTERRUPT_HANDLER =_timer2->TIMER2_interruptHandler ;
        #if (INRERRUPT_PRIORITY_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE) 
             INTERRUPT_PRIORITY_LEVELS_ENABLE() ;  
             if (interrupt_low_prioity==_timer2->TIMER2_priority ){
                 INTERRUPT_GLOBAL_INTERRUPT_ENABLE_LOW()  ;
                 TIMER2_INTERRUPT_SET_LOW_PRIORITY()  ;
                 
             }
             else if (interrupt_HIGH_prioity==_timer2->TIMER2_priority){
                 INTERRUPT_GLOBAL_INTERRUPT_ENABLE_HIGH()  ;
                 TIMER2_INTERRUPT_SET_HIGH_PRIORITY() ;
             }
             else {INTERRUPT_GLOBAL_INTERRUPT_ENABLE_LOW()  ; TIMER2_INTERRUPT_SET_LOW_PRIORITY()  ;}
             
        #else
       INTERRUPT_GLOBAL_INTERRUPT_ENABLE()  ;
       INTERRUPT_PERIPHERAL_INTERRUPT_ENABLE()   ;
        
        #endif
        
        TIMER2_INTERRUPT_ENABLE()  ;
       
       
        #endif
       
        
        
        
        
        
        
        
        TIMER2_MODULE_ON() ;
        
        
        
        
        
        
    }
    
    
    
    return ret ;
    
    
    
}
/**
 * 
 * @param _timer2
 * @return 
 */
Std_ReturnType TIMER2_DEINITIALIZE(const TIMER2_CONFG_t*_timer2 ) {
        
      Std_ReturnType ret =E_OK ;
    if (NULL==_timer2){
        
        ret=E_NOT_OK  ;
        
    }
    else {
         TIMER2_MODULE_off()   ;
          /***interrupt section*/
        #if (TIMER2_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)
             TIMER2_INTERRUPT_DISABLE() ; 
         
        #endif
        
    }
    
    
    
    return ret ;
    
    
    
    
}
/**
 * 
 * @param _timer2
 * @param value
 * @return 
 */
Std_ReturnType TIMER2_WRITE_VALUE(const TIMER2_CONFG_t*_timer2  , uint_8 value) {
        
      Std_ReturnType ret =E_OK ;
    if (NULL==_timer2){
        
        ret=E_NOT_OK  ;
        
    }
    else {
        
        
        TMR2 = value ;
        
    }
    
    
    
    return ret ;
    
    
    
    
}
/**
 * 
 * @param _timer2
 * @param return_value
 * @return 
 */
Std_ReturnType TIMER2_READ_VALUE(const TIMER2_CONFG_t*_timer2  , uint_8 *return_value) {
    
      Std_ReturnType ret =E_OK ;
   
    if ((NULL==_timer2)||(NULL==return_value)){
        
        ret=E_NOT_OK  ;
        
    }
    else {
        
      *return_value =TMR2 ;
        
        
    }
    
    
    
    return ret ;
    
}
/**
 * 
 */
void TIMER2_ISR(void) {
 #if (TIMER2_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)   
 TIMER2_INTERRUPT_CLEAR_FLAG() ;
#endif
 TMR2 =Timer2_preloaded_value ; // we dont need to reintialize PR2 in ISR cuz it constant but if we use TMR2 we must 
                                // reintialize it here cuz every compare match TMR2 is cleared 
 if(TIMER2_INTERRUPT_HANDLER){
     
     TIMER2_INTERRUPT_HANDLER() ;
     
 }
 else {/*nothing*/}
    
    
}