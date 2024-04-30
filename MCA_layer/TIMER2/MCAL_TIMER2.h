/* 
 * File:   MCAL_TIMER2.h
 * Author: sayr3
 *
 * Created on January 20, 2024, 9:07 PM
 */

#ifndef MCAL_TIMER2_H
#define	MCAL_TIMER2_H

/*section:*********includes*******************************/
#include"MCAL_TIMER2_CONFG.h"
#include "../interrupt/mcal_internal_interrupt.h"
#include"../GPIO/mcal_GPIO.h"

/*section:*********macro declaration*********************/
#define TIMER2_PRESCALER_DIV_BY_1                0x0
#define TIMER2_PRESCALER_DIV_BY_4                0x1
#define TIMER2_PRESCALER_DIV_BY_16               0x2


#define TIMER2_POSTSCALER_DIV_BY_1                0
#define TIMER2_POSTSCALER_DIV_BY_2                1
#define TIMER2_POSTSCALER_DIV_BY_3                2
#define TIMER2_POSTSCALER_DIV_BY_4                3
#define TIMER2_POSTSCALER_DIV_BY_5                4
#define TIMER2_POSTSCALER_DIV_BY_6                5
#define TIMER2_POSTSCALER_DIV_BY_7                6
#define TIMER2_POSTSCALER_DIV_BY_8                7
#define TIMER2_POSTSCALER_DIV_BY_9                8
#define TIMER2_POSTSCALER_DIV_BY_10               9
#define TIMER2_POSTSCALER_DIV_BY_11               10
#define TIMER2_POSTSCALER_DIV_BY_12               11
#define TIMER2_POSTSCALER_DIV_BY_13               12
#define TIMER2_POSTSCALER_DIV_BY_14               13
#define TIMER2_POSTSCALER_DIV_BY_15               14
#define TIMER2_POSTSCALER_DIV_BY_16               15





/*section:*********macro functions declaration **********/
#define TIMER2_MODULE_ON()                             (T2CONbits.TMR2ON = 1) 
#define TIMER2_MODULE_off()                            (T2CONbits.TMR2ON = 0) 
#define TIMER2_PRESCALER_SELECT(_prescaler_)           (T2CONbits.T2CKPS =_prescaler_)
#define TIMER2_POSTSCALER_SELECT(_prescaler_)          (T2CONbits.TOUTPS =_prescaler_)


/*section:*********data types ***************************/
typedef struct {
 #if (TIMER2_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)  
    void(*TIMER2_interruptHandler)(void) ;
    interrupt_priorty_t TIMER2_priority ;
 #endif
uint_8 TIMER2_preload_value  ; 
uint_8 TIMER2_prescaler_value :2 ;
uint_8 TIMER2_postscaler_value :4 ;
uint_8 TIMER2_reserved : 2 ;
   
    
}TIMER2_CONFG_t;

/*section:*********functions declaration*****************/

Std_ReturnType TIMER2_INITIALIZE(const TIMER2_CONFG_t*_timer2 ) ;
Std_ReturnType TIMER2_DEINITIALIZE(const TIMER2_CONFG_t*_timer2 ) ;
Std_ReturnType TIMER2_WRITE_VALUE(const TIMER2_CONFG_t*_timer2  , uint_8 value) ;
Std_ReturnType TIMER2_READ_VALUE(const TIMER2_CONFG_t*_timer2  , uint_8 *return_value) ;






#endif	/* MCAL_TIMER2_H */

