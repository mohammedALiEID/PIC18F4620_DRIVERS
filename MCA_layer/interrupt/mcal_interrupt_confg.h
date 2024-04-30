/* 
 * File:   mcal_interrupt_confg.h
 * Author: sayr3
 *
 * Created on December 29, 2023, 1:02 PM
 */

#ifndef MCAL_INTERRUPT_CONFG_H
#define	MCAL_INTERRUPT_CONFG_H

/*section:*********includes*******************************/
#include <pic18f4620.h>
#include "../std_libraries.h"
#include "../mcal_std_types.h"
#include "../../MCA_layer/device_configuration/device_configure.h"
#include "../compiler.h"
#include "mcal_interrupt_genrator_cfg.h"
#include "../GPIO/mcal_GPIO.h"


/*section:*********macro declaration*********************/
#define INTERRUPT_ENABLE                    0X1
#define INTERRUPT_DISABLE                   0X0
#define INTERRUPT_CHECKED                   0X1
#define INTERRUPT_NOT_CHECKED               0X0



/*section:*********macro functions declaration **********/
#if (INRERRUPT_PRIORITY_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)
#define INTERRUPT_PRIORITY_LEVELS_ENABLE()           (RCONbits.IPEN=1)
#define INTERRUPT_PRIORITY_LEVELS_DISABLE()          (RCONbits.IPEN=0)
#define INTERRUPT_GLOBAL_INTERRUPT_ENABLE_HIGH()     (INTCONbits.GIEH=1)
#define INTERRUPT_GLOBAL_INTERRUPT_DISABLE_HIGH()    (INTCONbits.GIEH=0)
#define INTERRUPT_GLOBAL_INTERRUPT_ENABLE_LOW()      (INTCONbits.GIEL=1)
#define INTERRUPT_GLOBAL_INTERRUPT_DISABLE_LOW()     (INTCONbits.GIEL=0)
#else 
#define INTERRUPT_GLOBAL_INTERRUPT_ENABLE()          (INTCONbits.GIE=1)
#define INTERRUPT_GLOBAL_INTERRUPT_DISABLE()         (INTCONbits.GIE=0)
#define INTERRUPT_PERIPHERAL_INTERRUPT_ENABLE()      (INTCONbits.PEIE=1)
#define INTERRUPT_PERIPHERAL_INTERRUPT_DISABLE()     (INTCONbits.PEIE=0)


#endif

/*section:*********data types ***************************/

typedef enum{
   interrupt_low_prioity = 0 ,
   interrupt_HIGH_prioity 
    
}interrupt_priorty_t;




/*section:*********functions declaration*****************/







#endif	/* MCAL_INTERRUPT_CONFG_H */

