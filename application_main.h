/* 
 * File:   application_main.h
 * Author: mohammed ali
 *
 * Created on December 2, 2023, 7:12 PM
 */

#ifndef APPLICATION_MAIN_H
#define	APPLICATION_MAIN_H





/*section:*********includes*******************************/
#include "ECUA_layer/ecual_layer_initalization.h"
#include "MCA_layer/interrupt/mcal_external_inrerrupt.h"
#include "MCA_layer/EEPROM/MCAL_EEPROM.h" 
#include "MCA_layer/ADC/MCAL_ADC.h"
#include "MCA_layer/TIMER0/MCAL_TIMER0.h"
#include "MCA_layer/TIMER1/MCAL_TIMER1.h"
#include"MCA_layer/TIMER2/MCAL_TIMER2.h" 
#include"MCA_layer/TIMER3/MCAL_TIMER3.h"
#include"MCA_layer/CCP1/Mcal_CCP1.h" 
#include "MCA_layer/USART/MCAL_USART.h"
/*section:*********data types ***************************/


/*section:*********macro declaration*********************/


/*section:*********macro functions declaration **********/


/*section:*********functions declaration*****************/

void general_initialization(void) ;
void TIMER0_ISR_APP(void) ;
void TIMER1_ISR_APP(void) ;
void TIMER2_ISR_APP(void) ;
void TIMER3_ISR_APP(void) ;
void CCP1_capture_ISR_APP(void) ;
void CCP1_compare_ISR_APP(void) ;
void EUSART_TX_ISR_APP(void) ;
void EUSART_RX_ISR_APP(void) ;
void EUSART_FERROR_ISR_APP(void) ;
void EUSART_OERROR_ISR_APP(void) ;
#endif	/* APPLICATION_MAIN_H */

