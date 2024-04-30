/* 
 * File:   ECual_led.h
 * Author: mohammed_ali
 *
 * Created on December 2, 2023, 6:50 PM
 */

#ifndef ECUAL_LED_H
#define	ECUAL_LED_H
 


/*section:*********includes*******************************/
#include "../../MCA_layer/GPIO/mcal_GPIO.h"
#include "ECUAL_LED_confg.h" 

/*section:*********data types ***************************/

typedef enum {
   LED_OFF ,
   LED_ON ,
    
} led_status ;

typedef struct {
    
   uint_8 port_index :3 ;
   uint_8 pin_index :3  ;
   uint_8 led_status : 1;
   uint_8 reserved : 1 ;
    
    
}  led_confg_t ;


/*section:*********macro declaration*********************/


/*section:*********macro functions declaration **********/


/*section:*********functions declaration*****************/
Std_ReturnType led_intialize (const led_confg_t *led_confg) ;
Std_ReturnType led_turn_on(const led_confg_t *led_confg) ;
Std_ReturnType led_turn_off(const led_confg_t *led_confg) ;
Std_ReturnType led_turn_toggle(const led_confg_t *led_confg) ;









#endif	/* ECUAL_LED_H */

