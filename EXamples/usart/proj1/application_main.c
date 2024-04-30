/* 
 * File:   main_application.c
 * Author: mohammed_ali
 *
 * Created on December 2, 2023, 4:23 PM
 */

/*section ***include ******************/
#include "application_main.h"


/*section ***global variables ******************/

USART_CONFG_t usart_obj={.baudrat =9600 ,.baudrat_gen_confg =BAUDRAT_ASYNC_16BIT_LOW_SPEED ,

                          .usart_tx_cfg.usart_TX_9bit_enable=EUSART_ASYNC_9BIT_TX_DISABLE ,
                          .usart_tx_cfg.usart_TX_enable=EUSART_ASYNC_TX_ENABLE ,
                          .usart_tx_cfg.usart_TX_interrupt_enable=EUSART_ASYNC_TX_INTERRUPT_DISABLE ,

                          .usart_rx_cfg.usart_RX_9bit_enable=EUSART_ASYNC_9BIT_RX_DISABLE ,
                          .usart_rx_cfg.usart_RX_enable=EUSART_ASYNC_RX_ENABLE ,
                          .usart_rx_cfg.usart_RX_interrupt_enable=EUSART_ASYNC_RX_INTERRUPT_DISABLE ,

                          .USART_TX_INTTERRUPT_HANDLER =EUSART_TX_ISR_APP ,
                          .USART_RX_INTTERRUPT_HANDLER =NULL ,
                          .USART_FRAME_ERROR_HANDLER =NULL ,
                          .USART_OVERRRUN_ERROR_HANDLER =NULL};





uint_8 recived_value = 0 ;
Std_ReturnType ret = 0;

int main() {

 
    general_initialization();
    
  
 
    while (1) {
        
//        ret =EUSART_ASYNC_WRITEBYTE_blocking(&usart_obj, 'a') ;
//        __delay_ms(1000) ;
//        
//        
//       ret =EUSART_ASYNC_WRITEBYTE_blocking(&usart_obj, 'c') ;
        
//       __delay_ms(1000) ;
        
        
        ret =EUSART_ASYNC_READBYTE_NON_blocking(&usart_obj,&recived_value) ;
        
         if (E_OK==ret){
   
    if (recived_value=='a'){
       
       
       ret = led_turn_on(&led1); 
       
       ret =EUSART_ASYNC_WRITE_STRING_blocking(&usart_obj ,"LED ON\r" ,  7) ;
   }
    
    
    
   else if (recived_value=='c'){
       
       ret=led_turn_off(&led1) ;
        ret =EUSART_ASYNC_WRITE_STRING_blocking(&usart_obj ,"LED OFF\r" ,  8) ;
   }
   else {}
   
   
   }
 
  
   else {} 

        
        
        
        
        
    }
    
    
    
    
    
    
    

    return (EXIT_SUCCESS);
}

void general_initialization(void) {

    ECUAL_peripherals_initialization();

    ret =EUSART_ASYNC_INIT(&usart_obj) ;
}


void EUSART_TX_ISR_APP(void) {
  
    
    
}
