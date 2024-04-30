/* 
 * File:   mcal_internal_interrupt.h
 * Author: sayr3
 *
 * Created on December 29, 2023, 11:42 AM
 */

#ifndef MCAL_INTERNAL_INTERRUPT_H
#define	MCAL_INTERNAL_INTERRUPT_H



/*section:*********includes*******************************/

#include "mcal_interrupt_confg.h"


/*section:*********macro declaration*********************/


/*section:*********macro functions declaration **********/

/*section:*********ADC INTERRUPT CONFG **********/
#if(ADC_INTERRUPT_FEATURE_ENABLE ==INTERRUPT_FEATURE_ENABLE)

#define ADC_INTERRUPT_ENABLE()                    (PIE1bits.ADIE=1) 
#define ADC_INTERRUPT_DISABLE()                   (PIE1bits.ADIE=0) 
#define ADC_INTERRUPT_CLEAR_FLAG()                (PIR1bits.ADIF=0) 

#if (INRERRUPT_PRIORITY_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)

#define ADC_INTERRUPT_SET_HIGH_PRIORITY()              (IPR1bits.ADIP = 1)
#define ADC_INTERRUPT_SET_LOW_PRIORITY()               (IPR1bits.ADIP = 0)

#endif 


#endif
/*section:********TIMER0 INTERRUPT CONFG **********/
#if (TIMER0_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)
#define TIMER0_INTERRUPT_ENABLE()                          (INTCONbits.TMR0IE = 1)            
#define TIMER0_INTERRUPT_DISABLE()                         (INTCONbits.TMR0IE = 0)
#define TIMER0_INTERRUPT_CLEAR_FLAG()                      (INTCONbits.TMR0IF = 0)

#if (INRERRUPT_PRIORITY_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)

#define   TIMER0_INTERRUPT_SET_HIGH_PRIORITY()            (INTCON2bits.TMR0IP =1 )        
#define   TIMER0_INTERRUPT_SET_LOW_PRIORITY()             (INTCON2bits.TMR0IP =0 )  
             

#endif 

#endif 
/*section:********TIMER1 INTERRUPT CONFG **********/
#if (TIMER1_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)
#define TIMER1_INTERRUPT_ENABLE()                          (PIE1bits.TMR1IE = 1)            
#define TIMER1_INTERRUPT_DISABLE()                         (PIE1bits.TMR1IE =0)      
#define TIMER1_INTERRUPT_CLEAR_FLAG()                      (PIR1bits.TMR1IF = 0)

#if (INRERRUPT_PRIORITY_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)

#define   TIMER1_INTERRUPT_SET_HIGH_PRIORITY()            ( IPR1bits.TMR1IP =1)        
#define   TIMER1_INTERRUPT_SET_LOW_PRIORITY()             ( IPR1bits.TMR1IP =0)  
             

#endif 

#endif 

/*section:********TIMER2 INTERRUPT CONFG **********/
#if (TIMER2_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)
#define TIMER2_INTERRUPT_ENABLE()                          (PIE1bits.TMR2IE = 1)            
#define TIMER2_INTERRUPT_DISABLE()                         (PIE1bits.TMR2IE = 0)      
#define TIMER2_INTERRUPT_CLEAR_FLAG()                      (PIR1bits.TMR2IF = 0)

#if (INRERRUPT_PRIORITY_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)

#define   TIMER2_INTERRUPT_SET_HIGH_PRIORITY()           (IPR1bits.TMR2IP  = 1 )        
#define   TIMER2_INTERRUPT_SET_LOW_PRIORITY()            (IPR1bits.TMR2IP  = 0 )   
             

#endif 

#endif 

/*section:********TIMER3 INTERRUPT CONFG **********/

#if (TIMER3_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)
#define TIMER3_INTERRUPT_ENABLE()                          (PIE2bits.TMR3IE = 1)            
#define TIMER3_INTERRUPT_DISABLE()                         (PIE2bits.TMR3IE = 0)   
#define TIMER3_INTERRUPT_CLEAR_FLAG()                      (PIR2bits.TMR3IF = 0)

#if (INRERRUPT_PRIORITY_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)

#define   TIMER3_INTERRUPT_SET_HIGH_PRIORITY()            (IPR2bits.TMR3IP = 1 )        
#define   TIMER3_INTERRUPT_SET_LOW_PRIORITY()             (IPR2bits.TMR3IP = 0 ) 
             

#endif 

#endif 
/*section:********CCP1 INTERRUPT CONFG **********/

#if (CCP1_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)
#define CCP1_INTERRUPT_ENABLE()                          (PIE1bits.CCP1IE =1)            
#define CCP1_INTERRUPT_DISABLE()                         (PIE1bits.CCP1IE =0)   
#define CCP1_INTERRUPT_CLEAR_FLAG()                      (PIR1bits.CCP1IF = 0)

#if (INRERRUPT_PRIORITY_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)

#define   CCP1_INTERRUPT_SET_HIGH_PRIORITY()            (IPR1bits.CCP1IP =1 )        
#define   CCP1_INTERRUPT_SET_LOW_PRIORITY()             (IPR1bits.CCP1IP =0) 
             

#endif 

#endif 
/*section:********CCP2 INTERRUPT CONFG **********/

#if (CCP2_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)
#define CCP2_INTERRUPT_ENABLE()                          (PIE2bits.CCP2IE =1)            
#define CCP2_INTERRUPT_DISABLE()                         (PIE2bits.CCP2IE =0)    
#define CCP2_INTERRUPT_CLEAR_FLAG()                      (PIR2bits.CCP2IF =0)

#if (INRERRUPT_PRIORITY_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)

#define   CCP2_INTERRUPT_SET_HIGH_PRIORITY()            (IPR2bits.CCP2IP=1)        
#define   CCP2_INTERRUPT_SET_LOW_PRIORITY()             (IPR2bits.CCP2IP=0)
             

#endif 

#endif 

/*section:********USART ASYNC TX INTERRUPT CONFG **********/

#if (USART_ASYN_TX_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)
#define USART_ASYN_TX_INTERRUPT_ENABLE()                          (PIE1bits.TXIE=1)            
#define USART_ASYN_TX_INTERRUPT_DISABLE()                         (PIE1bits.TXIE=0)    


#if (INRERRUPT_PRIORITY_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)

#define   USART_ASYN_TX_INTERRUPT_SET_HIGH_PRIORITY()            (IPR1bits.TXIP =1)        
#define   USART_ASYN_TX_INTERRUPT_SET_LOW_PRIORITY()             (IPR1bits.TXIP =0) 
             

#endif 

#endif 


/*section:********USART ASYNC RX INTERRUPT CONFG **********/

#if (USART_ASYN_RX_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)
#define USART_ASYN_RX_INTERRUPT_ENABLE()                          (PIE1bits.RCIE=1)            
#define USART_ASYN_RX_INTERRUPT_DISABLE()                         (PIE1bits.RCIE=0)    


#if (INRERRUPT_PRIORITY_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)

#define   USART_ASYN_RX_INTERRUPT_SET_HIGH_PRIORITY()            (IPR1bits.RCIP=1)        
#define   USART_ASYN_RX_INTERRUPT_SET_LOW_PRIORITY()             (IPR1bits.RCIP=0)  
             

#endif 

#endif 




/*section:*********data types ***************************/

/*section:*********functions declaration*****************/
void ADC_ISR(void) ;
void TIMER0_ISR(void) ;
void TIMER1_ISR(void) ;
void TIMER2_ISR(void) ;
void TIMER3_ISR(void) ;
void CCP1_ISR(void) ;
void CCP2_ISR(void) ;
void USART_ASYN_TX_ISR(void) ;
void USART_ASYN_RX_ISR(void) ;

#endif	/* MCAL_INTERNAL_INTERRUPT_H */

