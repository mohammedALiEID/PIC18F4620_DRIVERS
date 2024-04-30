/* 
 * File:   ecual_layer_initalization.c
 * Author: sayr3
 *
 * Created on December 17, 2023, 10:05 PM
 */
/*section:***********includes*******************************/

#include "ecual_layer_initalization.h"
/*section:*********variables initialization *****************/
led_confg_t led1 ={.port_index =  PORTC_INDEX ,.pin_index =PIN0 , .led_status = LED_OFF};
led_confg_t led2 ={.port_index =  PORTC_INDEX ,.pin_index =PIN2 , .led_status = LED_OFF};

button_confg_t but_active_high= {.button_port=PORTC_INDEX ,.button_pin = PIN2 , 
                                 .button_status = BUTTON_RELEASED ,.button_active_status=BUTTON_ACTIVE_HIGH};

button_confg_t but_active_low= {.button_port=PORTD_INDEX ,.button_pin = PIN0 , 
                                .button_status = BUTTON_RELEASED ,.button_active_status=BUTTON_ACTIVE_LOW};

 motor_t motor1={.motor_pin[0].direction=OUTPUT ,.motor_pin[0].logic=LOW ,
                 .motor_pin[0].pin=PIN0 ,.motor_pin[0].port=PORTD_INDEX ,
                 .motor_pin[1].direction=OUTPUT ,.motor_pin[1].logic=LOW ,
                 .motor_pin[1].pin=PIN1 ,.motor_pin[1].port=PORTD_INDEX  };
 
motor_t motor2 ={.motor_pin[0].direction=OUTPUT ,.motor_pin[0].logic=LOW ,
                 .motor_pin[0].pin=PIN2 ,.motor_pin[0].port=PORTD_INDEX ,
                 .motor_pin[1].direction=OUTPUT ,.motor_pin[1].logic=LOW ,
                 .motor_pin[1].pin=PIN3 ,.motor_pin[1].port=PORTD_INDEX  };

seven_segment_t seven_segment1= {.seven_segment_pin[0].port=PORTC_INDEX ,.seven_segment_pin[0].pin=PIN0 ,
                                 .seven_segment_pin[0].direction=OUTPUT ,.seven_segment_pin[0].logic=LOW ,
                                 .seven_segment_pin[1].port=PORTC_INDEX ,.seven_segment_pin[1].pin=PIN1 ,
                                 .seven_segment_pin[1].direction=OUTPUT ,.seven_segment_pin[1].logic=LOW ,
                                 .seven_segment_pin[2].port=PORTC_INDEX ,.seven_segment_pin[2].pin=PIN2 ,
                                 .seven_segment_pin[2].direction=OUTPUT ,.seven_segment_pin[2].logic=LOW ,
                                 .seven_segment_pin[3].port=PORTC_INDEX ,.seven_segment_pin[3].pin=PIN3 ,
                                 .seven_segment_pin[3].direction=OUTPUT ,.seven_segment_pin[3].logic=LOW ,
                                 .segment_type = SEGMENT_COMMON_anod };

pin_confg_t segment1_enable = {.port =PORTD_INDEX ,.pin =PIN0 ,.direction = OUTPUT ,.logic = LOW};
pin_confg_t segment2_enable = {.port =PORTD_INDEX ,.pin =PIN1 ,.direction = OUTPUT ,.logic = LOW};

keypad_t keyp1 ={.keypad_rows_pin[0].port = PORTC_INDEX , .keypad_rows_pin[0].pin = PIN0 ,
                 .keypad_rows_pin[0].direction = OUTPUT , .keypad_rows_pin[0].logic =LOW ,
                 .keypad_rows_pin[1].port = PORTC_INDEX , .keypad_rows_pin[1].pin = PIN1 ,
                 .keypad_rows_pin[1].direction = OUTPUT , .keypad_rows_pin[1].logic =LOW ,
                 .keypad_rows_pin[2].port = PORTC_INDEX , .keypad_rows_pin[2].pin = PIN2 ,
                 .keypad_rows_pin[2].direction = OUTPUT , .keypad_rows_pin[2].logic =LOW ,
                 .keypad_rows_pin[3].port = PORTC_INDEX , .keypad_rows_pin[3].pin = PIN3 ,
                 .keypad_rows_pin[3].direction = OUTPUT , .keypad_rows_pin[3].logic =LOW ,
                 .keypad_coloumns_pin[0].port = PORTC_INDEX , .keypad_coloumns_pin[0].pin = PIN4 ,
                 .keypad_coloumns_pin[0].direction = INPUT  , .keypad_coloumns_pin[0].logic =LOW ,
                 .keypad_coloumns_pin[1].port = PORTC_INDEX , .keypad_coloumns_pin[1].pin = PIN5 ,
                 .keypad_coloumns_pin[1].direction = INPUT  , .keypad_coloumns_pin[1].logic =LOW ,
                 .keypad_coloumns_pin[2].port = PORTC_INDEX , .keypad_coloumns_pin[2].pin = PIN6 ,
                 .keypad_coloumns_pin[2].direction = INPUT  , .keypad_coloumns_pin[2].logic =LOW ,
                 .keypad_coloumns_pin[3].port = PORTC_INDEX , .keypad_coloumns_pin[3].pin = PIN7 ,
                 .keypad_coloumns_pin[3].direction = INPUT  , .keypad_coloumns_pin[3].logic =LOW , } ;
                 



cha_lcd_4bit_t lcd1 ={.lcd_RS.port=PORTC_INDEX ,.lcd_RS.pin=PIN0 ,.lcd_RS.direction=OUTPUT ,.lcd_RS.logic=LOW ,
                      .lcd_E.port=PORTC_INDEX ,.lcd_E.pin=PIN2 ,.lcd_E.direction=OUTPUT ,.lcd_E.logic=LOW ,
                      .lcd_R_W.port=PORTC_INDEX ,.lcd_R_W.pin=PIN1 ,.lcd_R_W.direction=OUTPUT ,.lcd_R_W.logic=LOW ,
                      .lcd_data[0].port=PORTC_INDEX ,.lcd_data[0].pin =PIN3 ,.lcd_data[0].direction=OUTPUT ,.lcd_data[0].logic=LOW,
                      .lcd_data[1].port=PORTC_INDEX ,.lcd_data[1].pin =PIN4 ,.lcd_data[1].direction=OUTPUT ,.lcd_data[1].logic=LOW,
                      .lcd_data[2].port=PORTC_INDEX ,.lcd_data[2].pin =PIN5 ,.lcd_data[2].direction=OUTPUT ,.lcd_data[2].logic=LOW ,
                      .lcd_data[3].port=PORTC_INDEX ,.lcd_data[3].pin =PIN6 ,.lcd_data[3].direction=OUTPUT ,.lcd_data[3].logic=LOW} ;




cha_lcd_8bit_t lcd2 ={.lcd_RS.port=PORTC_INDEX ,.lcd_RS.pin=PIN6 ,.lcd_RS.direction=OUTPUT ,.lcd_RS.logic=LOW ,
                      .lcd_E.port=PORTC_INDEX ,.lcd_E.pin=PIN7 ,.lcd_E.direction=OUTPUT ,.lcd_E.logic=LOW ,
                      .lcd_R_W.port=PORTA_INDEX ,.lcd_R_W.pin=PIN1 ,.lcd_R_W.direction=OUTPUT ,.lcd_R_W.logic=LOW ,
                      .lcd_data[0].port=PORTD_INDEX ,.lcd_data[0].pin =PIN0 ,.lcd_data[0].direction=OUTPUT ,.lcd_data[0].logic=LOW ,
                      .lcd_data[1].port=PORTD_INDEX ,.lcd_data[1].pin =PIN1 ,.lcd_data[1].direction=OUTPUT ,.lcd_data[1].logic=LOW ,
                      .lcd_data[2].port=PORTD_INDEX ,.lcd_data[2].pin =PIN2 ,.lcd_data[2].direction=OUTPUT ,.lcd_data[2].logic=LOW ,
                      .lcd_data[3].port=PORTD_INDEX ,.lcd_data[3].pin =PIN3 ,.lcd_data[3].direction=OUTPUT ,.lcd_data[3].logic=LOW ,
                      .lcd_data[4].port=PORTD_INDEX ,.lcd_data[4].pin =PIN4 ,.lcd_data[4].direction=OUTPUT ,.lcd_data[4].logic=LOW ,
                      .lcd_data[5].port=PORTD_INDEX ,.lcd_data[5].pin =PIN5 ,.lcd_data[5].direction=OUTPUT ,.lcd_data[5].logic=LOW ,
                      .lcd_data[6].port=PORTD_INDEX ,.lcd_data[6].pin =PIN6 ,.lcd_data[6].direction=OUTPUT ,.lcd_data[6].logic=LOW ,
                      .lcd_data[7].port=PORTD_INDEX ,.lcd_data[7].pin =PIN7 ,.lcd_data[7].direction=OUTPUT ,.lcd_data[7].logic=LOW} ;











/*section:*********function definition *****************/

void ECUAL_peripherals_initialization(void){
    Std_ReturnType ret = E_NOT_OK ;
    ret = led_intialize(&led1) ;
   
}