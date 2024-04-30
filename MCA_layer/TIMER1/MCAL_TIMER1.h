/* 
 * File:   MCAL_TIMER1.h
 * Author: sayr3
 *
 * Created on January 19, 2024, 1:09 AM
 */

#ifndef MCAL_TIMER1_H
#define	MCAL_TIMER1_H


/*section:*********includes*******************************/
#include "MCAL_TIMER1_confg.h"
#include "../interrupt/mcal_internal_interrupt.h"
#include"../GPIO/mcal_GPIO.h"

/*section:*********macro declaration*********************/
#define TIMER1_COUNTER_MODE                      0x1
#define TIMER1_TIMER_MODE                        0x0
#define TIMER1_ASYNC_COUNTER_MODE                0x1
#define TIMER1_SYNC_COUNTER_MODE                 0x0
#define TIMER1_OSC_ENABLE_cnfg                   0x1
#define TIMER1_OSC_DISABLE_cnfg                  0x0

#define TIMER1_PRESCALER_DIV_BY_1                0x0
#define TIMER1_PRESCALER_DIV_BY_2                0x1
#define TIMER1_PRESCALER_DIV_BY_4                0x2
#define TIMER1_PRESCALER_DIV_BY_8                0x3


#define TIMER1_RW_16BIT_REGISTER                 0x1
#define TIMER1_RW_8BIT_REGISTER                  0x0
/*section:*********macro functions declaration **********/
#define TIMER1_MODULE_ON()                             (T1CONbits.TMR1ON = 1) 
#define TIMER1_MODULE_off()                            (T1CONbits.TMR1ON = 0) 
#define TIMER1_COUNTER_MODE_ENABLE()                   (T1CONbits.TMR1CS = 1)
#define TIMER1_TIMER_MODE_ENABLE()                     (T1CONbits.TMR1CS = 0)
#define TIMER1_ASYNC_COUNTER_ENABLE()                  (T1CONbits.T1SYNC =1)
#define TIMER1_SYNC_COUNTER_ENABLE()                   (T1CONbits.T1SYNC = 0)
#define TIMER1_OSC_ENABLE()                            (T1CONbits.T1OSCEN = 1)
#define TIMER1_OSC_DISABLE()                           (T1CONbits.T1OSCEN = 0)
#define TIMER1_PRESCALER_SELECT(_prescaler_)           (T1CONbits.T1CKPS =_prescaler_)

/**TIRUN=1 Device clock is derived from Timer1 oscillator*/
/**TIRUN=0 Device clock is derived from another source*/
#define TIMER1_SYSTEM_CLK_STATUS()                     (T1CONbits.T1RUN)
#define TIMER1_RW_16BIT_REGISTER_ENABLE()              (T1CONbits.RD16 =1)
#define TIMER1_RW_8BIT_REGISTER_ENABLE()               (T1CONbits.RD16 =0)
/*section:*********data types ***************************/


typedef struct {
 #if (TIMER1_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)  
    void(*TIMER1_interruptHandler)(void) ;
    interrupt_priorty_t TIMER1_priority ;
 #endif
uint_16 TIMER1_preload_value  ; 
uint_8 TIMER1_mode : 1 ;
uint_8 TIMER1_counter_mode : 1 ;    
uint_8 TIMER1_OSC_status : 1 ;  
uint_8 TIMER1_prescaler_value :2 ;
uint_8 TIMER1_RW_register_mode : 1 ;
uint_8 TIMER1_reserved : 2 ;
   
    
}TIMER1_CONFG_t;

/*section:*********functions declaration*****************/

Std_ReturnType TIMER1_INITIALIZE(const TIMER1_CONFG_t*_timer1 ) ;
Std_ReturnType TIMER1_DEINITIALIZE(const TIMER1_CONFG_t*_timer1 ) ;
Std_ReturnType TIMER1_WRITE_VALUE(const TIMER1_CONFG_t*_timer1  , uint_16 value) ;
Std_ReturnType TIMER1_READ_VALUE(const TIMER1_CONFG_t*_timer1  , uint_16 *return_value) ;




#endif	/* MCAL_TIMER1_H */

