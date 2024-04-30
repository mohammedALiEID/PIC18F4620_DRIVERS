/* 
 * File:   mcal_external_inrerrupt.h
 * Author: sayr3
 *
 * Created on December 29, 2023, 12:57 PM
 */

#ifndef MCAL_EXTERNAL_INRERRUPT_H
#define	MCAL_EXTERNAL_INRERRUPT_H

/*section:*********includes*******************************/
#include "mcal_interrupt_confg.h"


/*section:*********macro declaration*********************/


/*section:*********macro functions declaration **********/

#if (EXTERNAL_INRERRUPT_INTX_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)

#define EXT_INT0_INTERRUPT_ENABLE()                      (INTCONbits.INT0IE=1)
#define EXT_INT0_INTERRUPT_disable()                     (INTCONbits.INT0IE=0)
#define EXT_INT0_INTERRUPT_CLEAR_FLAG()                  (INTCONbits.INT0IF=0)
#define EXT_INT0_SET_RISING_EDGE()                       (INTCON2bits.INTEDG0=1)
#define EXT_INT0_SET_FALLING_EDGE()                      (INTCON2bits.INTEDG0=0)
/*********************************************************************************/
#define EXT_INT1_INTERRUPT_ENABLE()                      (INTCON3bits.INT1IE=1)
#define EXT_INT1_INTERRUPT_disable()                     (INTCON3bits.INT1IE=0)
#define EXT_INT1_INTERRUPT_CLEAR_FLAG()                  (INTCON3bits.INT1IF=0)
#define EXT_INT1_SET_RISING_EDGE()                       (INTCON2bits.INTEDG1=1)
#define EXT_INT1_SET_FALLING_EDGE()                      (INTCON2bits.INTEDG1=0)
#if (INRERRUPT_PRIORITY_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)
#define EXT_INT1_SET_HIGH_PRIORITY()                     (INTCON3bits.INT1IP=1)
#define EXT_INT1_SET_low_PRIORITY()                      (INTCON3bits.INT1IP=0)
#endif
/*********************************************************************************/
#define EXT_INT2_INTERRUPT_ENABLE()                      (INTCON3bits.INT2IE=1)
#define EXT_INT2_INTERRUPT_disable()                     (INTCON3bits.INT2IE=0)
#define EXT_INT2_INTERRUPT_CLEAR_FLAG()                  (INTCON3bits.INT2IF=0)
#define EXT_INT2_SET_RISING_EDGE()                       (INTCON2bits.INTEDG2=1)
#define EXT_INT2_SET_FALLING_EDGE()                      (INTCON2bits.INTEDG2=0)
#if (INRERRUPT_PRIORITY_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)
#define EXT_INT2_SET_HIGH_PRIORITY()                     (INTCON3bits.INT2IP=1)
#define EXT_INT2_SET_low_PRIORITY()                      (INTCON3bits.INT2IP=0)
#endif
/*********************************************************************************/

#endif

#if (EXTERNAL_INRERRUPT_ONCHANGE_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)

#define EXT_RBX_INTERRUPT_ENABLE()                       (INTCONbits.RBIE=1)      
#define EXT_RBX_INTERRUPT_DISABLE()                      (INTCONbits.RBIE=0) 
#define EXT_RBX_INTERRUPT_CLEAR_FLAG()                   (INTCONbits.RBIF=0) 

#if (INRERRUPT_PRIORITY_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)

#define EXT_RBX_INTERRUPT_SET_HIGH_PRIORITY()            (INTCON2bits.RBIP =1) 
#define EXT_RBX_INTERRUPT_SET_LOW_PRIORITY()             (INTCON2bits.RBIP =0) 

#endif


#endif


/*section:*********data types *****************************/

typedef enum{
    interrupt_INTX_falling_edge = 0 ,
    interrupt_INTX_rising_edge 
    
}interrupt_INTX_edge_t;

typedef enum{
   interrupt_INT0 = 0 ,
   interrupt_INT1  ,
   interrupt_INT2  
    
}interrupt_INTX_source_t;
typedef struct{
  void(*EXT_INTERRUPT_HANDLER)(void);
  pin_confg_t mcu_pin ;
  interrupt_INTX_edge_t edge ;
  interrupt_priorty_t priorty ;
  interrupt_INTX_source_t source ;
    
}Interrupt_INTX_t;

typedef struct{
  void(*EXT_INTERRUPT_HANDLER_HIGH)(void);
  void(*EXT_INTERRUPT_HANDLER_LOW)(void);
  pin_confg_t mcu_pin ;
  interrupt_priorty_t priorty ;

}Interrupt_RBX_t;

/*section:*********functions declaration*****************/

Std_ReturnType Interrupt_INTX_Initialize(const Interrupt_INTX_t*int_obj) ;
Std_ReturnType Interrupt_INTX_DEInitialize(const Interrupt_INTX_t*int_obj) ;

Std_ReturnType Interrupt_RBX_Initialize(const Interrupt_RBX_t*int_obj) ;
Std_ReturnType Interrupt_RBX_DEInitialize(const Interrupt_RBX_t*int_obj) ;

/*section:*********INTX_ISR_declaration*****************/

void INT0_ISR(void) ;
void INT1_ISR(void) ;
void INT2_ISR(void) ;
void RB4_ISR_HIGH(void) ;
void RB4_ISR_LOW(void) ;
void RB5_ISR_HIGH(void) ;
void RB5_ISR_LOW(void) ;
void RB6_ISR_HIGH(void) ;
void RB6_ISR_LOW(void) ;
void RB7_ISR_HIGH(void) ;
void RB7_ISR_LOW(void) ;
#endif	/* MCAL_EXTERNAL_INRERRUPT_H */

