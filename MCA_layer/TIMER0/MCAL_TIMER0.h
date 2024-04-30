/* 
 * File:   MCAL_TIMER0.h
 * Author: sayr3
 *
 * Created on January 15, 2024, 3:59 AM
 */

#ifndef MCAL_TIMER0_H
#define	MCAL_TIMER0_H

/*section:*********includes*******************************/
#include "MCAL_TIMER_confg.h" 
#include "../interrupt/mcal_internal_interrupt.h"
#include"../GPIO/mcal_GPIO.h"

/*section:*********macro declaration*********************/

#define TIMER0_8BIT_REGISTER              0x1
#define TIMER0_16BIT_REGISTER             0x0
#define TIMER0_COUNTER_MODE               0x1
#define TIMER0_TIMER_MODE                 0x0
#define TIMER0_FALLING_EDGE               0x1
#define TIMER0_RISING_EDGE                0x0
#define TIMER0_PRESCALER_DISABLE_cfg      0x1
#define TIMER0_PRESCALER_ENABLE_cfg       0x0

/*section:*********macro functions declaration **********/
#define TIMER0_MODULE_ON()                             (T0CONbits.TMR0ON = 1) 
#define TIMER0_MODULE_off()                            (T0CONbits.TMR0ON = 0) 
#define TIMER0_8BIT_REGISTER_MODE()                    (T0CONbits.T08BIT = 1)
#define TIMER0_16BIT_REGISTER_MODE()                   (T0CONbits.T08BIT = 0)
#define TIMER0_COUNTER_MODE_ENABLE()                   (T0CONbits.T0CS  = 1)
#define TIMER0_TIMER_MODE_ENABLE()                     (T0CONbits.T0CS = 0)
#define TIMER0_FALLING_EDGE_ENABLE()                   (T0CONbits.T0SE = 1)
#define TIMER0_RISING_EDGE_ENABLE()                    (T0CONbits.T0SE = 0)
#define TIMER0_PRESCALER_DISABLE()                     (T0CONbits.PSA = 1)
#define TIMER0_PRESCALER_ENABLE()                      (T0CONbits.PSA = 0)



/*section:*********data types ***************************/
typedef enum {
    
  TIMER0_PRESCALER_DIV_BY_2 = 0 ,
  TIMER0_PRESCALER_DIV_BY_4  ,      
  TIMER0_PRESCALER_DIV_BY_8  ,
  TIMER0_PRESCALER_DIV_BY_16  ,
  TIMER0_PRESCALER_DIV_BY_32  ,
  TIMER0_PRESCALER_DIV_BY_64 ,
  TIMER0_PRESCALER_DIV_BY_128  ,
  TIMER0_PRESCALER_DIV_BY_256  
        
}TIMER0_prescaler_select_t;


typedef struct {
    #if (TIMER0_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)  
    void(*TIMER0_interruptHandler)(void) ;
    interrupt_priorty_t TIMER0_priority ;
    #endif
    TIMER0_prescaler_select_t TIMER0_prescaler_value  ;
    uint_16 TIMER0_preloaded_value  ;
    uint_8 TIMER0_register_size : 1 ;
    uint_8 TIMER0_mode : 1 ;
    uint_8 TIMER0_COUNTER_Edge: 1 ;
    uint_8 TIMER0_prescaler_status :1 ;
    uint_8 TIMER0_Reserved :4 ;
   
    
    
}TIMER0_CONFG_t;

/*section:*********functions declaration*****************/

Std_ReturnType TIMER0_INITIALIZE(const TIMER0_CONFG_t*_timer0 ) ;
Std_ReturnType TIMER0_DEINITIALIZE(const TIMER0_CONFG_t*_timer0 ) ;
Std_ReturnType TIMER0_WRITE_VALUE(const TIMER0_CONFG_t*_timer0  , uint_16 value) ;
Std_ReturnType TIMER0_READ_VALUE(const TIMER0_CONFG_t*_timer0  , uint_16 *return_value) ;
#endif	/* MCAL_TIMER0_H */

