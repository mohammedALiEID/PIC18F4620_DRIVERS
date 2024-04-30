

/* 
 * File:   ecual_keypad.h
 * Author: sayr3
 *
 * Created on December 17, 2023, 10:55 PM
 */

#ifndef ECUAL_KEYPAD_H
#define	ECUAL_KEYPAD_H

/*section:*********includes*******************************/
#include "../../MCA_layer/GPIO/mcal_GPIO.h"
#include "ecual_keypad_confg.h"

/*section:*********macro declaration*********************/
#define keypad_rows_pins_number     4 
#define keypad_coloumns_pins_number 4 
/*section:*********data types ***************************/
typedef struct {
    pin_confg_t keypad_rows_pin[keypad_rows_pins_number]  ;
    pin_confg_t keypad_coloumns_pin[keypad_coloumns_pins_number]  ;
    
    
}keypad_t;


/*section:*********macro functions declaration **********/


/*section:*********functions declaration*****************/

Std_ReturnType keypad_intialization (const keypad_t *keypad);
Std_ReturnType keypad_get_written_value (const keypad_t *keypad , uint_8 * value);





#endif	/* ECUAL_KEYPAD_H */

