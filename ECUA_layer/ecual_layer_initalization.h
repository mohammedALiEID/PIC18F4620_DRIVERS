/* 
 * File:   ecual_layer_initalization.h
 * Author: sayr3
 *
 * Created on December 17, 2023, 10:05 PM
 */

#ifndef ECUAL_LAYER_INITALIZATION_H
#define	ECUAL_LAYER_INITALIZATION_H


/*section:*********includes*******************************/

#include "LED/ECUAL_led.h"
#include "button/ecual_button.h"
#include "relay/ecual_relay.h"
#include "DC_motor_driver/ecual_dc_motor_driver.h"
#include "seven_segment/ecual_seven_segment.h"
#include "keypad/ecual_keypad.h"
#include "character_lcd/cha_lcd.h"


/*section:*********data types ***************************/
extern led_confg_t led1 ;
extern led_confg_t led2 ;
extern button_confg_t but_active_high ;
extern button_confg_t but_active_low ;
extern seven_segment_t seven_segment1 ;
extern pin_confg_t segment1_enable ;
extern pin_confg_t segment2_enable ;
extern keypad_t keyp1 ;
extern cha_lcd_4bit_t lcd1 ;
extern cha_lcd_8bit_t lcd2 ;
extern motor_t motor1 ;
extern motor_t motor2 ;
/*section:*********macro declaration*********************/


/*section:*********macro functions declaration **********/


/*section:*********functions declaration*****************/
void ECUAL_peripherals_initialization(void) ;




#endif	/* ECUAL_LAYER_INITALIZATION_H */
