/* 
 * File:   ecual_relay.h
 * Author: sayr3
 *
 * Created on December 13, 2023, 2:28 AM
 */

#ifndef ECUAL_RELAY_H
#define	ECUAL_RELAY_H

/*section:*********includes*******************************/
#include "ecual_relay_confg.h" 
#include "../../MCA_layer/GPIO/mcal_GPIO.h"

/*section:*********data types ***************************/
typedef enum {
  RELAY_ON ,
  RELAY_OFF
  
}relay_status_t;

typedef struct {
    uint_8 port_index :3 ;
    uint_8 pin_index : 3 ;
    uint_8 relay_status :1 ;
    uint_8 reserved : 1 ;
  
}relay_t;


/*section:*********macro declaration*********************/


/*section:*********macro functions declaration **********/


/*section:*********functions declaration*****************/

Std_ReturnType relay_initialization (const relay_t*relay) ;
Std_ReturnType relay_energization (const relay_t*relay) ;
Std_ReturnType relay_deenergization (const relay_t*relay) ;

#endif	/* ECUAL_RELAY_H */

