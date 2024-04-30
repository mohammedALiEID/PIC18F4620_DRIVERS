/* 
 * File:   main_application.c
 * Author: mohammed_ali
 *
 * Created on December 2, 2023, 4:23 PM
 */

/*section ***include ******************/
#include "application_main.h"


/*section ***global variables ******************/



USART_CONFG_t usart_int_obj2={.baudrat =9600 ,.baudrat_gen_confg =BAUDRAT_ASYNC_16BIT_LOW_SPEED ,

                          .usart_tx_cfg.usart_TX_9bit_enable=EUSART_ASYNC_9BIT_TX_DISABLE ,
                          .usart_tx_cfg.usart_TX_enable=EUSART_ASYNC_TX_ENABLE ,
                          .usart_tx_cfg.usart_TX_interrupt_enable=EUSART_ASYNC_TX_INTERRUPT_ENABLE ,

                          .usart_rx_cfg.usart_RX_9bit_enable=EUSART_ASYNC_9BIT_RX_DISABLE ,
                          .usart_rx_cfg.usart_RX_enable=EUSART_ASYNC_RX_ENABLE ,
                          .usart_rx_cfg.usart_RX_interrupt_enable=EUSART_ASYNC_RX_INTERRUPT_ENABLE ,

                          .USART_TX_INTTERRUPT_HANDLER =NULL ,
                          .USART_RX_INTTERRUPT_HANDLER =EUSART_RX_ISR_APP ,
                          .USART_FRAME_ERROR_HANDLER =EUSART_FERROR_ISR_APP ,
                          .USART_OVERRRUN_ERROR_HANDLER =EUSART_OERROR_ISR_APP};



uint_8 recived_value = 0 ;

Std_ReturnType ret = 0;

int main() {

 
    general_initialization();
    
    // ret= EUSART_ASYNC_WRITEBYTE_blocking(&usart_int_obj2 ,'a') ;

 
    while (1) {

    
        
        
        
        
        
        
   }
 
  

        
        
        
        
        
    
    
    
    
    
    
    
    

    return (EXIT_SUCCESS);
}

void general_initialization(void) {

    ECUAL_peripherals_initialization();

    ret =EUSART_ASYNC_INIT(&usart_int_obj2) ;
}


void EUSART_TX_ISR_APP(void) {
  
 
    
}
void EUSART_RX_ISR_APP(void) {
   
 ret =EUSART_ASYNC_READBYTE_NON_blocking(&usart_int_obj2 ,&recived_value) ;
        
        switch(recived_value){
            
            case 'a' :
                ret =led_turn_on(&led1) ;
                 __delay_ms(500) ;
                ret= EUSART_ASYNC_WRITEBYTE_blocking(&usart_int_obj2 ,'c') ;
               
                break ;
             case 'b' :
                ret =led_turn_off(&led1) ;
                    __delay_ms(500) ;
                ret= EUSART_ASYNC_WRITEBYTE_blocking(&usart_int_obj2 ,'d') ;
                
                break ;
           
            default  :  break ;
                
                
                
            
            
        }
      
    
}
void EUSART_FERROR_ISR_APP(void) {
   uint_8 temp = 0 ;
   temp =RCREG ; // to clear Frame error
 
}
void EUSART_OERROR_ISR_APP(void) {
  
    ret=EUSART_ASYNC_RX_RESET() ;//to clear overrun error
    
}