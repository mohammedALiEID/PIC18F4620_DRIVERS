/* 
 * File:   Mcal_CCP1.h
 * Author: sayr3
 *
 * Created on January 24, 2024, 10:51 PM
 */

#ifndef MCAL_CCP1_H
#define	MCAL_CCP1_H

/*section:*********includes*******************************/

#include"Mcal_CCP1_confg.h" 
#include "../interrupt/mcal_internal_interrupt.h"
#include"../GPIO/mcal_GPIO.h"
/*section:*********macro declaration*********************/
#define CCP_MODULE_DISABLE                            0X0
#define CCP_CAPTURE_MODE_1_FALLING_EDGE               0X4
#define CCP_CAPTURE_MODE_1_RISING_EDGE                0X5
#define CCP_CAPTURE_MODE_4_RISING_EDGE                0X6
#define CCP_CAPTURE_MODE_16_RISING_EDGE               0X7

#define CCP_COMPARE_MODE_TOGGLE_PIN_CCPx_ON_MATCH     0X2
#define CCP_COMPARE_MODE_SET_PIN_CCPx_HIGH            0X8
#define CCP_COMPARE_MODE_SET_PIN_CCPx_LOW             0X9
#define CCP_COMPARE_MODE_GENERAT_SW_INTERRUPT         0XA
#define CCP_COMPARE_MODE_TRIGGER_SPECIAL_EVENT        0XB
#define CCP_PWM_MODE                                  0XC

#define CCP_CAPTURE_NOT_completed                     0X0
#define CCP_CAPTURE_completed                         0X1
#define CCP_COMPARE_NOT_completed                     0X0
#define CCP_COMPARE_completed                         0X1


#define CCP_TIMER2_PRESCALER_DIV_BY_1                 1
#define CCP_TIMER2_PRESCALER_DIV_BY_4                 4
#define CCP_TIMER2_PRESCALER_DIV_BY_16                16


#define CCP_TIMER2_POSTSCALER_DIV_BY_1                1
#define CCP_TIMER2_POSTSCALER_DIV_BY_2                2
#define CCP_TIMER2_POSTSCALER_DIV_BY_3                3
#define CCP_TIMER2_POSTSCALER_DIV_BY_4                4
#define CCP_TIMER2_POSTSCALER_DIV_BY_5                5
#define CCP_TIMER2_POSTSCALER_DIV_BY_6                6
#define CCP_TIMER2_POSTSCALER_DIV_BY_7                7
#define CCP_TIMER2_POSTSCALER_DIV_BY_8                8
#define CCP_TIMER2_POSTSCALER_DIV_BY_9                9
#define CCP_TIMER2_POSTSCALER_DIV_BY_10               10
#define CCP_TIMER2_POSTSCALER_DIV_BY_11               11
#define CCP_TIMER2_POSTSCALER_DIV_BY_12               12
#define CCP_TIMER2_POSTSCALER_DIV_BY_13               13
#define CCP_TIMER2_POSTSCALER_DIV_BY_14               14
#define CCP_TIMER2_POSTSCALER_DIV_BY_15               15
#define CCP_TIMER2_POSTSCALER_DIV_BY_16               16


/*section:*********macro functions declaration **********/
#define CCP1_SELECT_MODE(_MODE_)              (CCP1CONbits.CCP1M =_MODE_)
#define CCP2_SELECT_MODE(_MODE_)              (CCP2CONbits.CCP2M =_MODE_)
/*section:*********data types ***************************/

 typedef enum {
    
  CCP_CAPTURE_MODE_SELECT = 0 ,  
  CCP_COMPARE_MODE_SELECT  ,  
  CCP_PMW_MODE_SELECT  ,  
}ccp1_mode_t;
  
typedef enum {
    CCP1_SEL =0 ,
    CCP2_SEL
    
}CCP_select_t;

typedef enum {
   CCP1_CCP2_Timer1=0,
   CCP1_Timer1_CCP2_Timer3 ,        
   CCP1_CCP2_Timer3 
    
    
}CCP_CA_CO_Timer_t;

typedef union {
    
    struct {
       
        
        uint_8 CCPR_low ;
        uint_8 CCPR_high;
    };
    struct{
       
        uint_16 CCPR_16bit ;
        
    };
    
    
} CCP_data_reg_t;


typedef struct {
CCP_select_t CCP_select ;   
ccp1_mode_t CCP_MODE ;    
CCP_CA_CO_Timer_t CCP_Ca_Co_timer ;
pin_confg_t CCP_PIN ;
uint_8 CCP_MODE_variant ;
#if (CCP1_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)  
    void(*CCP1_interruptHandler)(void) ;
    interrupt_priorty_t CCP1_P1ority ;
 #endif
#if (CCP2_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)  
    void(*CCP2_interruptHandler)(void) ;
    interrupt_priorty_t CCP2_P1ority ;
 #endif

#if (CCP1_CONFG_MODE_SELECTED ==CCP_PWM_MODE_SELECTED)||(CCP2_CONFG_MODE_SELECTED==CCP_PWM_MODE_SELECTED)
uint_32 PWM_frequency ;
uint_8 TIMER2_prescaler_value :2 ;
uint_8 TIMER2_postscaler_value :4 ;
#endif


    
}CCP_cnfg_t;

/*section:*********functions declaration*****************/

Std_ReturnType CCP_INITIALIZE(const CCP_cnfg_t*_ccp) ;
Std_ReturnType CCP_DEINITIALIZE(const CCP_cnfg_t*_ccp) ;

#if (CCP1_CONFG_MODE_SELECTED ==CCP_CAPTURE_MODE_SELECTED)||(CCP2_CONFG_MODE_SELECTED==CCP_CAPTURE_MODE_SELECTED)
Std_ReturnType CCP_IS_CAPTURE_competed(const CCP_cnfg_t*_ccp , uint_8 *_capture_status) ;
Std_ReturnType CCP_capture_mode_read_value(const CCP_cnfg_t*_ccp , uint_16 *captured_value) ;


#endif



#if (CCP1_CONFG_MODE_SELECTED ==CCP_COMPARE_MODE_SELECTED)||(CCP2_CONFG_MODE_SELECTED==CCP_COMPARE_MODE_SELECTED)
Std_ReturnType CCP_IS_compare_completed(const CCP_cnfg_t*_ccp,uint_8 *_compare_status) ;
Std_ReturnType CCP_compare_mode_set_value (const CCP_cnfg_t*_ccp,uint_16 compared_value) ;


#endif



#if (CCP1_CONFG_MODE_SELECTED ==CCP_PWM_MODE_SELECTED)||(CCP2_CONFG_MODE_SELECTED==CCP_PWM_MODE_SELECTED)


Std_ReturnType CCP_PWM_set_duty_cycle(const CCP_cnfg_t*_ccp,uint_8 _duty) ;
Std_ReturnType CCP_PWM_start(const CCP_cnfg_t*_ccp) ;
Std_ReturnType CCP_PWM_stop(const CCP_cnfg_t*_ccp) ;
#endif


































#endif	/* MCAL_CCP1_H */

