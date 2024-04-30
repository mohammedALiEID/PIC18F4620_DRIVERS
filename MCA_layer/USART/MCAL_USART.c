/* 
 * File:   MCAL_USART.c
 * Author: sayr3
 *
 * Created on February 3, 2024, 11:05 PM
 */
/*section:***********includes*******************************/
#include "MCAL_USART.h"



/*section:*********static helper functions declaration*****************/ 
static Std_ReturnType EUSART_BRG_CONFG(const USART_CONFG_t*_usart) ;
static Std_ReturnType EUSART_ASYN_TX_CONFG(const USART_CONFG_t*_usart) ;
static Std_ReturnType EUSART_ASYN_RX_CONFG(const USART_CONFG_t*_usart) ;

/*section:*********functions definition*****************/
#if (USART_ASYN_TX_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)
static void(*USART_ASYNC_TX_INTERRUPT_HANDLER)(void)  =NULL ;
#endif

#if (USART_ASYN_RX_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)
static void(*USART_ASYNC_RX_INTERRUPT_HANDLER)(void)  =NULL ;
static void(*USART_ASYNC_FERRO_HANDLER)(void)  =NULL ;
static void(*USART_ASYNC_OERRO_HANDLER)(void)  =NULL ;
#endif

/**
 * 
 * @param _usart
 * @return 
 */
Std_ReturnType EUSART_ASYNC_INIT(const USART_CONFG_t*_usart ) {
   Std_ReturnType ret =E_OK ;
    if (NULL==_usart){
        
        ret=E_NOT_OK  ;
        
    }
    else {
        
        
        EUSART_MODULE_DISABLE() ;
        
        TRISCbits.RC6 = 1 ;
        TRISCbits.RC7 = 1 ;
        
     ret = EUSART_BRG_CONFG(_usart) ;
     ret =EUSART_ASYN_TX_CONFG(_usart) ;
     ret =EUSART_ASYN_RX_CONFG(_usart) ;
   
     
     
    
        EUSART_MODULE_ENABLE() ;
    }
     return ret ;
}
/**
 * 
 * @param _usart
 * @return 
 */
Std_ReturnType EUSART_ASYNC_DEINIT(const USART_CONFG_t*_usart ) {
     Std_ReturnType ret =E_OK ;
    if (NULL==_usart){
        
        ret=E_NOT_OK  ;
        
    }
    else {
    
         EUSART_MODULE_DISABLE() ;
         
        #if (USART_ASYN_TX_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)

             USART_ASYN_TX_INTERRUPT_DISABLE()  ;
      
       #endif
        
     
        #if (USART_ASYN_RX_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)

             USART_ASYN_RX_INTERRUPT_DISABLE()  ;
      
       #endif
    
    }
    
     return ret ;
    
}
/**
 * 
 * @param _usart
 * @param _value
 * @return 
 */
Std_ReturnType EUSART_ASYNC_READBYTE_blocking(const USART_CONFG_t*_usart ,uint_8*_value ) {
     Std_ReturnType ret =E_OK ;
    if ((NULL==_usart)||(NULL==_value)){
        
        ret=E_NOT_OK  ;
        
    }
    else {
    
        while(!(PIR1bits.RCIF)) ;
        
        *_value=RCREG ;
    
    
    }
    
     return ret ;
    
}
/**
 * 
 * @param _usart
 * @param _value
 * @return 
 */
Std_ReturnType EUSART_ASYNC_READBYTE_NON_blocking(const USART_CONFG_t*_usart ,uint_8*_value ) {
     Std_ReturnType ret =E_NOT_OK ;
    if ((NULL==_usart)||(NULL==_value)){
        
        ret=E_NOT_OK  ;
        
    }
    else {
    
        if (1==(PIR1bits.RCIF)){
            *_value=RCREG ;
           ret=E_OK  ;  
            
        }
        
        else {
              ret=E_NOT_OK  ;
            
        }
        
       
    
    
    }
    
     return ret ;
    
    
    
}
/**
 * 
 * @return 
 */
Std_ReturnType EUSART_ASYNC_RX_RESET(void) {
    Std_ReturnType ret =E_OK ;
    
    
    RCSTAbits.CREN = 0 ; // disable receiving
    RCSTAbits.CREN = 1 ;  // enable receiving 
    
    
    
    return ret ;

}


/**
 * 
 * @param _usart
 * @param _data
 * @return 
 */
Std_ReturnType EUSART_ASYNC_WRITEBYTE_blocking(const USART_CONFG_t*_usart ,uint_8 _data ) {
     Std_ReturnType ret =E_OK ;
    if (NULL==_usart){
        
        ret=E_NOT_OK  ;
        
    }
    else {
        
       
    
     while(!(TXSTAbits.TRMT))  ;
     
     TXREG =_data ;
     #if (USART_ASYN_TX_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)
    USART_ASYN_TX_INTERRUPT_ENABLE()    ;
    #endif
     
    
    }
    
     return ret ;
    
}

/**
 * 
 * @param _usart
 * @param _data
 * @param str_len
 * @return 
 */
Std_ReturnType EUSART_ASYNC_WRITE_STRING_blocking(const USART_CONFG_t*_usart ,uint_8* _data ,uint_16 str_len ) {
     Std_ReturnType ret =E_OK ;
    if ((NULL==_usart)||(NULL==_data)){
        
        ret=E_NOT_OK  ;
        
    }
    else {
    
        for (uint_8 char_counter=ZERO_INT ;char_counter<str_len ;char_counter++ ){
            
              ret =EUSART_ASYNC_WRITEBYTE_blocking(_usart ,_data[char_counter]) ;
            
        }
        
    }
    
     return ret ;
    
    
}



/**
 * 
 * @param _usart
 * @return 
 */
static Std_ReturnType EUSART_BRG_CONFG(const USART_CONFG_t*_usart){
     Std_ReturnType ret =E_OK ;
    if (NULL==_usart){
        
        ret=E_NOT_OK  ;
        
    }
    else {
        float_32 baud_rate_temp =0 ;
        switch (_usart->baudrat_gen_confg) {
            
            case BAUDRAT_ASYNC_8BIT_LOW_SPEED  :
                TXSTAbits.SYNC =EUSART_ASYNC_MODE ;
                BAUDCONbits.BRG16 =EUSART_BRG_8BIT_REG ;
                TXSTAbits.BRGH =EUSART_ASYNC_BRG_LOW_RATE ;
                baud_rate_temp =((_XTAL_FREQ/(float)_usart->baudrat)/64)-1 ;
                
                break ;
             
            case BAUDRAT_ASYNC_8BIT_HIGH_SPEED  :
                TXSTAbits.SYNC =EUSART_ASYNC_MODE ;
                BAUDCONbits.BRG16 =EUSART_BRG_8BIT_REG ;
                TXSTAbits.BRGH =EUSART_ASYNC_BRG_HIGH_RATE ;
                baud_rate_temp =((_XTAL_FREQ/(float)_usart->baudrat)/16)-1 ;
                break ;
             
            case BAUDRAT_ASYNC_16BIT_LOW_SPEED  :
                
                TXSTAbits.SYNC =EUSART_ASYNC_MODE ;
                BAUDCONbits.BRG16 =EUSART_BRG_16BIT_REG ;
                TXSTAbits.BRGH =EUSART_ASYNC_BRG_LOW_RATE ;
                baud_rate_temp =((_XTAL_FREQ/(float)_usart->baudrat)/16)-1 ;
                break ;
             
            case BAUDRAT_ASYNC_16BIT_HIGH_SPEED  :
                
                TXSTAbits.SYNC =EUSART_ASYNC_MODE ;
                BAUDCONbits.BRG16 =EUSART_BRG_16BIT_REG ;
                TXSTAbits.BRGH =EUSART_ASYNC_BRG_HIGH_RATE ;
                baud_rate_temp =((_XTAL_FREQ/(float)_usart->baudrat)/4)-1 ;
                break ;
             
            case BAUDRAT_ASYNC_8BIT  :
                TXSTAbits.SYNC =EUSART_ASYNC_MODE ;
                BAUDCONbits.BRG16 =EUSART_BRG_8BIT_REG ;
                 baud_rate_temp =((_XTAL_FREQ/(float)_usart->baudrat)/4)-1 ;
                break ;
             
            case BAUDRAT_ASYNC_16BIT  :
                TXSTAbits.SYNC =EUSART_ASYNC_MODE ;
                BAUDCONbits.BRG16 =EUSART_BRG_16BIT_REG ;
                baud_rate_temp =((_XTAL_FREQ/(float)_usart->baudrat)/4)-1 ;
                break ;
            default :  ret=E_NOT_OK  ; break ;       

            
            
        }
        SPBRG =(uint_8)((uint_32)baud_rate_temp);
        SPBRGH =(uint_8) (((uint_32)baud_rate_temp)>>8) ;  
    
    
    }
    
    
    
     return ret ;
    
    
    
}
/**
 * 
 * @param _usart
 * @return 
 */
static Std_ReturnType EUSART_ASYN_TX_CONFG(const USART_CONFG_t*_usart){
     Std_ReturnType ret =E_OK ;
    if (NULL==_usart){
        
        ret=E_NOT_OK  ;
        
    }
    else {
        
        if(EUSART_ASYNC_TX_ENABLE==_usart->usart_tx_cfg.usart_TX_enable){
            
                 /**enable transmitting configuration*/
            TXSTAbits.TXEN =EUSART_ASYNC_TX_ENABLE ;
            
                      /**interrupt configuration*/
 /*****************************************************************************************************************/           
            if(EUSART_ASYNC_TX_INTERRUPT_ENABLE==_usart->usart_tx_cfg.usart_TX_interrupt_enable){
                
           #if (USART_ASYN_TX_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)
                USART_ASYN_TX_INTERRUPT_DISABLE()   ;
                USART_ASYNC_TX_INTERRUPT_HANDLER=_usart->USART_TX_INTTERRUPT_HANDLER ;
           #if (INRERRUPT_PRIORITY_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE) 
             INTERRUPT_PRIORITY_LEVELS_ENABLE() ;  
             if (interrupt_low_prioity==_usart->usart_tx_cfg.usart_tx_priority){
                 INTERRUPT_GLOBAL_INTERRUPT_ENABLE_LOW()  ;
                 USART_ASYN_TX_INTERRUPT_SET_LOW_PRIORITY();
                    
                 }
             else if (interrupt_HIGH_prioity==_usart->usart_tx_cfg.usart_tx_priority){
                INTERRUPT_GLOBAL_INTERRUPT_ENABLE_HIGH()  ;
               USART_ASYN_TX_INTERRUPT_SET_HIGH_PRIORITY()   ;
                }
             else {INTERRUPT_GLOBAL_INTERRUPT_ENABLE_LOW()  ; USART_ASYN_TX_INTERRUPT_SET_LOW_PRIORITY()   ;}
             
           #else
           INTERRUPT_GLOBAL_INTERRUPT_ENABLE()  ;
           INTERRUPT_PERIPHERAL_INTERRUPT_ENABLE()   ;
        
           #endif
                
                 USART_ASYN_TX_INTERRUPT_ENABLE()   ;
                
                
            #endif
                
            }
            else if (EUSART_ASYNC_TX_INTERRUPT_DISABLE==_usart->usart_tx_cfg.usart_TX_interrupt_enable){
                
                USART_ASYN_TX_INTERRUPT_DISABLE()   ;
                
            }
            else{/*nothing*/}
            
 /******************************************************************************************************************/           
                                      /**9bit TX configuration*/
 /*******************************************************************************************************************/           
            if(EUSART_ASYNC_9BIT_TX_ENABLE==_usart->usart_tx_cfg.usart_TX_9bit_enable){
                
                
                TXSTAbits.TX9 = 1 ;
                
            }
            else if (EUSART_ASYNC_9BIT_TX_DISABLE==_usart->usart_tx_cfg.usart_TX_9bit_enable){
                 TXSTAbits.TX9 = 0 ;
                
            }
            
            else {/*nothing*/}
            
            
 /**********************************************************************************************************************/           
            
        }
        
        else if(EUSART_ASYNC_TX_DISABLE==_usart->usart_tx_cfg.usart_TX_enable) {
               TXSTAbits.TXEN =EUSART_ASYNC_TX_DISABLE ;
            
        }
        
        
         else{/*nothing*/}
        
    
    }
     
     
    
     return ret ;
    
    
    
}
/**
 * 
 * @param _usart
 * @return 
 */
static Std_ReturnType EUSART_ASYN_RX_CONFG(const USART_CONFG_t*_usart){
    
      Std_ReturnType ret =E_OK ;
    if (NULL==_usart){
        
        ret=E_NOT_OK  ;
        
    }
    else {
     
        if(EUSART_ASYNC_RX_ENABLE==_usart->usart_rx_cfg.usart_RX_enable){
            
                 /**enable receiving configuration*/
            RCSTAbits.CREN =EUSART_ASYNC_RX_ENABLE ;
            
                      /**interrupt configuration*/
 /*****************************************************************************************************************/           
            if(EUSART_ASYNC_RX_INTERRUPT_ENABLE==_usart->usart_rx_cfg.usart_RX_interrupt_enable){
                
           #if (USART_ASYN_RX_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)
                USART_ASYN_RX_INTERRUPT_DISABLE()   ;
                USART_ASYNC_RX_INTERRUPT_HANDLER=_usart->USART_RX_INTTERRUPT_HANDLER ;
                USART_ASYNC_FERRO_HANDLER =_usart->USART_FRAME_ERROR_HANDLER ;
                USART_ASYNC_OERRO_HANDLER =_usart->USART_OVERRRUN_ERROR_HANDLER ;
                
                
           #if (INRERRUPT_PRIORITY_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE) 
             INTERRUPT_PRIORITY_LEVELS_ENABLE() ;  
             if (interrupt_low_prioity==_usart->usart_rx_cfg.usart_rx_priority){
                 INTERRUPT_GLOBAL_INTERRUPT_ENABLE_LOW()  ;
                 USART_ASYN_RX_INTERRUPT_SET_LOW_PRIORITY();
                    
                 }
             else if (interrupt_HIGH_prioity==_usart->usart_rx_cfg.usart_rx_priority){
                INTERRUPT_GLOBAL_INTERRUPT_ENABLE_HIGH()  ;
               USART_ASYN_RX_INTERRUPT_SET_HIGH_PRIORITY()   ;
                }
             else {INTERRUPT_GLOBAL_INTERRUPT_ENABLE_LOW()  ; USART_ASYN_RX_INTERRUPT_SET_LOW_PRIORITY()   ;}
             
           #else
           INTERRUPT_GLOBAL_INTERRUPT_ENABLE()  ;
           INTERRUPT_PERIPHERAL_INTERRUPT_ENABLE()   ;
        
           #endif
                
                 USART_ASYN_RX_INTERRUPT_ENABLE()   ;
                
                
            #endif
                
            }
            else if (EUSART_ASYNC_RX_INTERRUPT_DISABLE==_usart->usart_rx_cfg.usart_RX_interrupt_enable){
                
                USART_ASYN_RX_INTERRUPT_DISABLE()   ;
                
            }
            else{/*nothing*/}
            
 /******************************************************************************************************************/           
                                      /**9bit TX configuration*/
 /*******************************************************************************************************************/           
            if(EUSART_ASYNC_9BIT_RX_ENABLE==_usart->usart_rx_cfg.usart_RX_9bit_enable){
                
                
                RCSTAbits.RX9= 1 ;
                
            }
            else if (EUSART_ASYNC_9BIT_TX_DISABLE==_usart->usart_tx_cfg.usart_TX_9bit_enable){
                RCSTAbits.RX9= 0 ;
                
            }
            
            else {/*nothing*/}
            
            
 /**********************************************************************************************************************/           
            
        }
        
        else if(EUSART_ASYNC_RX_DISABLE==_usart->usart_rx_cfg.usart_RX_enable) {
               RCSTAbits.CREN =EUSART_ASYNC_RX_DISABLE ;
            
        }
        
        
         else{/*nothing*/}
        
    
    }
     
     
    
     return ret ;
    
}






/**
 * 
 */
void USART_ASYN_TX_ISR(void) {
 #if (USART_ASYN_TX_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)
 USART_ASYN_TX_INTERRUPT_DISABLE()   ;
 #endif
 if(USART_ASYNC_TX_INTERRUPT_HANDLER){
     
     USART_ASYNC_TX_INTERRUPT_HANDLER() ;
 }
 else {/*nothing*/}
    
    
}
/**
 * 
 */
void USART_ASYN_RX_ISR(void) {
  uint_8 temp = 0 ;
   
 if(USART_ASYNC_RX_INTERRUPT_HANDLER){
     
     USART_ASYNC_RX_INTERRUPT_HANDLER() ;
 }
 else {/*nothing*/}
  temp =RCREG ; // to clear the RCIF  ,you can remove it if you use read function in ISR of RX
 
  if(1==RCSTAbits.FERR){
  if(USART_ASYNC_FERRO_HANDLER){
     
     USART_ASYNC_FERRO_HANDLER() ;
 }
 else {/*nothing*/}
  
  }
 else {/*nothing*/}
 
 if(1==RCSTAbits.OERR){
 if(USART_ASYNC_OERRO_HANDLER){
     
     USART_ASYNC_OERRO_HANDLER() ;
 }
 
 else {/*nothing*/}
 
 }
else {/*nothing*/}
    
    
}