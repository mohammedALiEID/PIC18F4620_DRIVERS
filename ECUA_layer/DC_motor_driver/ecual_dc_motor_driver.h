/* 
 * File:   ecual_dc_motor_driver.h
 * Author: sayr3
 *
 * Created on December 13, 2023, 11:55 PM
 */

#ifndef ECUAL_DC_MOTOR_DRIVER_H
#define	ECUAL_DC_MOTOR_DRIVER_H

/*section:*********includes*******************************/
#include"ecual_dc_motor_driver_confg.h"
#include "../../MCA_layer/GPIO/mcal_GPIO.h"

/*section:*********data types ***************************/
typedef enum {
 MOTOR_OFF = 0 ,
 MOTOR_ON ,

}motor_status_t;
/*     /////////////////////another method but i will create 2 pin_confg_t variable in each function calling to pass it to GPIO interfaces
 typedef struct {
    uint_8 motor_port : 3 ;
    uint_8 motor_pin : 3 ;
    uint_8 motor_status : 1 ;  

}motor_pin_t;
 
typedef struct {
   motor_pin_t motor[2] ; 
   
}motor_t;
 
 
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* the best  solution to prevent that repeated creating variable in each calling to make struct from pin_confg_t im motor_t */
typedef struct {
    
  pin_confg_t motor_pin[2];  
    
}motor_t;



/*section:*********macro declaration*********************/


/*section:*********macro functions declaration **********/


/*section:*********functions declaration*****************/

Std_ReturnType motor_driver_intialization (const motor_t*_motor) ;
Std_ReturnType motor_driver_forward (const motor_t*_motor) ;
Std_ReturnType motor_driver_backward (const motor_t*_motor) ;
Std_ReturnType motor_driver_stop (const motor_t*_motor) ;




#endif	/* ECUAL_DC_MOTOR_DRIVER_H */

