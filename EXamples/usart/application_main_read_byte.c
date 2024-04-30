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




uint_8 received_data = 0 ;

Std_ReturnType ret = 0;

int main() {

 
    general_initialization();
    
  
 
    while (1) {

   ret =EUSART_ASYNC_READBYTE_blocking(&usart_obj ,&received_data ) ;
 
   if (received_data=='a'){
       
       
       ret = led_turn_on(&led1); 
  }
   else if (received_data=='b'){
       
       ret=led_turn_off(&led1) ;
   }


    }





    return (EXIT_SUCCESS);
}

void general_initialization(void) {

    ECUAL_peripherals_initialization();

    ret =EUSART_ASYNC_INIT(&usart_obj) ;
}


void EUSART_TX_ISR_APP(void) {
    ret =led_turn_toggle(&led1) ;
    
    
}
