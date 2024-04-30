/* 
 * File:   MCAL_TIMER3.h
 * Author: sayr3
 *
 * Created on January 20, 2024, 9:07 PM
 */

#ifndef MCAL_TIMER3_H
#define	MCAL_TIMER3_H

/*section:*********includes*******************************/
#include "MCAL_TIMER3_CONFG.h"
#include "../interrupt/mcal_internal_interrupt.h"
#include"../GPIO/mcal_GPIO.h"

/*section:*********macro declaration*********************/
#define TIMER3_COUNTER_MODE                      0x1
#define TIMER3_TIMER_MODE                        0x0
#define TIMER3_ASYNC_COUNTER_MODE                0x1
#define TIMER3_SYNC_COUNTER_MODE                 0x0


#define TIMER3_PRESCALER_DIV_BY_1                0x0
#define TIMER3_PRESCALER_DIV_BY_2                0x1
#define TIMER3_PRESCALER_DIV_BY_4                0x2
#define TIMER3_PRESCALER_DIV_BY_8                0x3

#define TIMER3_RW_16BIT_REGISTER                 0x1
#define TIMER3_RW_8BIT_REGISTER                  0x0

/*section:*********macro functions declaration **********/
#define TIMER3_MODULE_ON()                             (T3CONbits.TMR3ON= 1) 
#define TIMER3_MODULE_off()                            (T3CONbits.TMR3ON = 0) 
#define TIMER3_COUNTER_MODE_ENABLE()                   (T3CONbits.TMR3CS = 1)
#define TIMER3_TIMER_MODE_ENABLE()                     (T3CONbits.TMR3CS = 0)
#define TIMER3_ASYNC_COUNTER_ENABLE()                  (T3CONbits.T3SYNC =1)
#define TIMER3_SYNC_COUNTER_ENABLE()                   (T3CONbits.T3SYNC = 0)

#define TIMER3_PRESCALER_SELECT(_prescaler_)           (T3CONbits.T3CKPS =_prescaler_)

#define TIMER3_RW_16BIT_REGISTER_ENABLE()              (T3CONbits.RD16 =1)
#define TIMER3_RW_8BIT_REGISTER_ENABLE()               (T3CONbits.RD16 =0)

/*section:*********data types ***************************/
typedef struct {
 #if (TIMER3_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)  
    void(*TIMER3_interruptHandler)(void) ;
    interrupt_priorty_t TIMER3_priority ;
 #endif
uint_16 TIMER3_preload_value  ; 
uint_8 TIMER3_mode : 1 ;
uint_8 TIMER3_counter_mode : 1 ;     
uint_8 TIMER3_prescaler_value :2 ;
uint_8 TIMER3_RW_register_mode : 1 ;
uint_8 TIMER3_reserved : 3 ;
   
    
}TIMER3_CONFG_t;


/*section:*********functions declaration*****************/

Std_ReturnType TIMER3_INITIALIZE(const TIMER3_CONFG_t*_timer3 ) ;
Std_ReturnType TIMER3_DEINITIALIZE(const TIMER3_CONFG_t*_timer3 ) ;
Std_ReturnType TIMER3_WRITE_VALUE(const TIMER3_CONFG_t*_timer3  , uint_16 value) ;
Std_ReturnType TIMER3_READ_VALUE(const TIMER3_CONFG_t*_timer3  , uint_16 *return_value) ;






#endif	/* MCAL_TIMER3_H */

