/* 
 * File:   mcal_interrupt_genrated_cfg.h
 * Author: sayr3
 *
 * Created on December 29, 2023, 6:07 PM
 */

#ifndef MCAL_INTERRUPT_GENRATOR_CFG_H
#define	MCAL_INTERRUPT_GENRATOR_CFG_H

/*section:*********includes*******************************/



/*section:*********data types ***************************/


/*section:*********macro declaration*********************/
#define INTERRUPT_FEATURE_ENABLE                              0X1
#define INTERRUPT_FEATURE_DISABLE                             0X0
#define INRERRUPT_PRIORITY_FEATURE_ENABLE                    INTERRUPT_FEATURE_DISABLE
#define EXTERNAL_INRERRUPT_INTX_FEATURE_ENABLE               INTERRUPT_FEATURE_ENABLE
#define EXTERNAL_INRERRUPT_ONCHANGE_FEATURE_ENABLE           INTERRUPT_FEATURE_ENABLE
#define ADC_INTERRUPT_FEATURE_ENABLE                         INTERRUPT_FEATURE_DISABLE
#define TIMER0_INTERRUPT_FEATURE_ENABLE                      INTERRUPT_FEATURE_ENABLE
#define TIMER1_INTERRUPT_FEATURE_ENABLE                      INTERRUPT_FEATURE_ENABLE
#define TIMER2_INTERRUPT_FEATURE_ENABLE                      INTERRUPT_FEATURE_ENABLE
#define TIMER3_INTERRUPT_FEATURE_ENABLE                      INTERRUPT_FEATURE_ENABLE
#define CCP1_INTERRUPT_FEATURE_ENABLE                        INTERRUPT_FEATURE_ENABLE
#define CCP2_INTERRUPT_FEATURE_ENABLE                        INTERRUPT_FEATURE_ENABLE
#define USART_ASYN_TX_INTERRUPT_FEATURE_ENABLE               INTERRUPT_FEATURE_ENABLE
#define USART_ASYN_RX_INTERRUPT_FEATURE_ENABLE               INTERRUPT_FEATURE_ENABLE
/*section:*********macro functions declaration **********/


/*section:*********functions declaration*****************/








#endif	/* MCAL_INTERRUPT_GENRATOR_CFG_H */

