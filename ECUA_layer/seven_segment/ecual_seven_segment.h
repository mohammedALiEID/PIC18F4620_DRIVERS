/* 
 * File:   ecual_seven_segment.h
 * Author: sayr3
 *
 * Created on December 16, 2023, 7:45 PM
 */

#ifndef ECUAL_SEVEN_SEGMENT_H
#define	ECUAL_SEVEN_SEGMENT_H

/*section:*********includes*******************************/

#include "ecual_seven_segment_confg.h"
#include "../../MCA_layer/GPIO/mcal_GPIO.h"

/*section:*********data types ***************************/
typedef enum{
    SEGMENT_COMMON_cathod ,
    SEGMENT_COMMON_anod 

}segment_type_t;
typedef struct {
    
    pin_confg_t seven_segment_pin[4] ;
    segment_type_t segment_type ;
    
}seven_segment_t;
/*section:*********macro declaration*********************/
#define SEVEN_SEGMENT_PIN0 0x0 
#define SEVEN_SEGMENT_PIN1 0x1 
#define SEVEN_SEGMENT_PIN2 0x2 
#define SEVEN_SEGMENT_PIN3 0x3 

/*section:*********macro functions declaration **********/


/*section:*********functions declaration*****************/

Std_ReturnType  seven_segment_initialization (const seven_segment_t*s_segment ) ;
Std_ReturnType  seven_segment_write_number (const seven_segment_t*s_segment  , uint_8 number) ;


















#endif	/* ECUAL_SEVEN_SEGMENT_H */

