/* 
 * File:   ecual_button.h
 * Author: sayr3
 *
 * Created on December 11, 2023, 9:17 PM
 */

#ifndef ECUAL_BUTTON_H
#define	ECUAL_BUTTON_H


/*section:*********includes*******************************/
#include"../../MCA_layer/GPIO/mcal_GPIO.h"
#include"ecual_button_confg.h" 


/*section:*********data types ***************************/
typedef enum {
   BUTTON_RELEASED ,
   BUTTON_PRESSED
    
}button_state_t;

typedef enum {
   BUTTON_ACTIVE_LOW ,
  BUTTON_ACTIVE_HIGH ,
    
}button_active_state_t;

typedef struct {
   uint_8 button_port :3 ;
   uint_8 button_pin : 3  ;
   uint_8 button_status :1  ;
   uint_8 button_active_status : 1 ;
   
   
}button_confg_t;



/*section:*********macro declaration*********************/


/*section:*********macro functions declaration **********/


/*section:*********functions declaration*****************/

Std_ReturnType button_intialization (button_confg_t*button) ;
Std_ReturnType button_read_status (button_confg_t*button ,button_state_t*button_status ) ;






#endif	/* ECUAL_BUTTON_H */

