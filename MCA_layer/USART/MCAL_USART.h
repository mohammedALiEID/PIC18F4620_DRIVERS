/* 
 * File:   MCAL_USART.h
 * Author: sayr3
 *
 * Created on February 3, 2024, 11:05 PM
 */

#ifndef MCAL_USART_H
#define	MCAL_USART_H

/*section:*********includes*******************************/
#include "MCAL_USART_confg.h"
#include "../interrupt/mcal_internal_interrupt.h"
#include"../GPIO/mcal_GPIO.h"


/*section:*********macro declaration*********************/

/* Enable / Disable EUSART Module */
#define EUSART_MODULE_ENABLE                              1
#define EUSART_MODULE_DISABLE                             0
/* Selecting EUSART Working Mode */
#define EUSART_SYNC_MODE                                  1
#define EUSART_ASYNC_MODE                                 0
/* Baud Rate Generator Asynchronous Speed Mode */
#define EUSART_ASYNC_BRG_HIGH_RATE                        1
#define EUSART_ASYNC_BRG_LOW_RATE                         0
/* Baud Rate Generator Register Size */
#define EUSART_BRG_16BIT_REG                              1
#define EUSART_BRG_8BIT_REG                               0
/* EUSART Transmit Enable */
#define EUSART_ASYNC_TX_ENABLE                            1
#define EUSART_ASYNC_TX_DISABLE                           0
/* EUSART 9-Bit Transmit Enable */
#define EUSART_ASYNC_9BIT_TX_ENABLE                       1
#define EUSART_ASYNC_9BIT_TX_DISABLE                      0
/* EUSART Transmit Interrupt Enable */
#define EUSART_ASYNC_TX_INTERRUPT_ENABLE                  1
#define EUSART_ASYNC_TX_INTERRUPT_DISABLE                 0

/* EUSART Receiver Enable */
#define EUSART_ASYNC_RX_ENABLE                            1
#define EUSART_ASYNC_RX_DISABLE                           0

/* EUSART 9-Bit Receiver Enable */
#define EUSART_ASYNC_9BIT_RX_ENABLE                       1
#define EUSART_ASYNC_9BIT_RX_DISABLE                      0

/* EUSART Receiver Interrupt Enable */
#define EUSART_ASYNC_RX_INTERRUPT_ENABLE                  1
#define EUSART_ASYNC_RX_INTERRUPT_DISABLE                 0

/* EUSART Framing Error */
#define EUSART_FRAMING_ERROR_DETECTED                     1
#define EUSART_FRAMING_ERROR_CLEARED                      0
/* EUSART Overrun Error */
#define EUSART_OVERRUN_ERROR_DETECTED                     1
#define EUSART_OVERRUN_ERROR_CLEARED                      0


/*section:*********macro functions declaration **********/
#define EUSART_MODULE_ENABLE()                   (RCSTAbits.SPEN=1)
#define EUSART_MODULE_DISABLE()                  (RCSTAbits.SPEN=0)
/*section:*********data types ***************************/
typedef struct {
    
  interrupt_priorty_t usart_tx_priority ;
  uint_8 usart_TX_interrupt_enable : 1 ; 
  uint_8 usart_TX_enable : 1 ;
  uint_8 usart_TX_9bit_enable : 1 ;
  uint_8 usart_TX_reserved : 5;  
    
}USART_TX_cfg_t;
typedef struct {
  interrupt_priorty_t usart_rx_priority ;
  uint_8 usart_RX_interrupt_enable : 1 ;
  uint_8 usart_RX_enable : 1 ;
  uint_8 usart_RX_9bit_enable : 1 ;
  uint_8 usart_RX_reserved : 5;  
    
    
    
}USART_RX_cfg_t;

typedef enum {
    BAUDRAT_ASYNC_8BIT_LOW_SPEED =0,
    BAUDRAT_ASYNC_8BIT_HIGH_SPEED ,
    BAUDRAT_ASYNC_16BIT_LOW_SPEED ,
    BAUDRAT_ASYNC_16BIT_HIGH_SPEED ,
    BAUDRAT_ASYNC_8BIT ,
    BAUDRAT_ASYNC_16BIT 
    
}BAUDRAT_gen_t;

typedef union {
    
    struct{
       uint_8 usart_ferr :1 ;
       uint_8 usart_oerr :1 ;
       uint_8 usart_reerved :6;
       
        
    };
     
    uint_8 error_status ;
    
}USAERT_error_status_t;


typedef struct {
   uint_32 baudrat ;
   BAUDRAT_gen_t baudrat_gen_confg ;
   USART_TX_cfg_t usart_tx_cfg ;
   USART_RX_cfg_t usart_rx_cfg ;
   USAERT_error_status_t usart_error_status ; 
   
   void(*USART_TX_INTTERRUPT_HANDLER)(void) ;
   void(*USART_RX_INTTERRUPT_HANDLER)(void) ;
   void(*USART_FRAME_ERROR_HANDLER)(void) ;
   void(*USART_OVERRRUN_ERROR_HANDLER)(void) ;
}USART_CONFG_t;

/*section:*********functions declaration*****************/

Std_ReturnType EUSART_ASYNC_INIT(const USART_CONFG_t*_usart ) ;
Std_ReturnType EUSART_ASYNC_DEINIT(const USART_CONFG_t*_usart ) ;

Std_ReturnType EUSART_ASYNC_READBYTE_blocking(const USART_CONFG_t*_usart ,uint_8*_value ) ;
Std_ReturnType EUSART_ASYNC_READBYTE_NON_blocking(const USART_CONFG_t*_usart ,uint_8*_value ) ;

Std_ReturnType EUSART_ASYNC_RX_RESET(void) ;

Std_ReturnType EUSART_ASYNC_WRITEBYTE_blocking(const USART_CONFG_t*_usart ,uint_8 _data ) ;
Std_ReturnType EUSART_ASYNC_WRITE_STRING_blocking(const USART_CONFG_t*_usart ,uint_8* _data ,uint_16 str_len ) ;

#endif	/* MCAL_USART_H */

