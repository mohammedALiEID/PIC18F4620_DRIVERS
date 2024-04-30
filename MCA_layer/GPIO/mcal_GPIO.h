/* 
 * File:   _mcal_GPIO.h
 * Author: mohammed_ali
 *
 * Created on December 2, 2023, 6:01 PM
 */

#ifndef MCAL_GPIO_H
#define	MCAL_GPIO_H




/*section:*********includes*******************************/
#include <pic18f4620.h>
#include "../mcal_std_types.h"
#include "../../MCA_layer/device_configuration/device_configure.h"
#include "mcal_gpio_confg.h"


/*section:*********data types ***************************/

typedef enum {
    PORTA_INDEX=0 ,
    PORTB_INDEX ,        
    PORTC_INDEX , 
    PORTD_INDEX ,
    PORTE_INDEX ,
    
}port_index_t;

typedef enum {
    PIN0 =0 ,
    PIN1 ,        
    PIN2 , 
    PIN3 ,
    PIN4 ,
    PIN5 , 
    PIN6,
    PIN7 ,
}pin_index_t;

typedef enum {
    OUTPUT=0 ,
    INPUT ,        
   
}direction_t;

typedef enum {
    LOW =0 ,
    HIGH ,        
   
}logic_t;
typedef struct {
   uint_8 port   :3 ;  /**@ref port_index_t **/
   uint_8 pin     :3 ; /**@ref pin_index_t **/
   uint_8 direction :1  ; /**@ref direction_t **/
   uint_8 logic :1 ;/**@ref logic_t **/
} pin_confg_t ;




/*section:*********macro declaration*********************/
#define BIT_MASK (uint_8)1
#define PORT__MAX_NUMBER   5
#define PIN_MAX_NUMBER   8
#define PORTC_MASK 0xFF ;
/*section:*********macro functions declaration **********/
#define HWREG(x)                          (*(( volatile unint_8*)(x)))
#define set_bit(reg,bit_pos)              (reg|=(BIT_MASK<<bit_pos))    
#define clear_bit(reg,bit_pos)            (reg&=~(BIT_MASK<<bit_pos))
#define toggle_bit(reg,bit_pos)           (reg^=(BIT_MASK<<bit_pos))
#define read_bit(reg , bit_pos)           ((reg>>bit_pos)&BIT_MASK )

/*section:*********functions declaration*****************/

Std_ReturnType gpio_pin_direction_initalize(const pin_confg_t *pin_confg ) ;
Std_ReturnType gpio_pin_get_direction_status(const pin_confg_t *pin_confg ,direction_t *direction_status) ;
Std_ReturnType gpio_pin_write_logic(const pin_confg_t *pin_confg ,logic_t logic) ;
Std_ReturnType gpio_pin_read_logic(const pin_confg_t *pin_confg ,logic_t* logic) ;
Std_ReturnType gpio_pin_toggle_logic(const pin_confg_t *pin_confg ) ;
Std_ReturnType gpio_pin__ALL_initaliztion(const pin_confg_t *pin_confg ) ;

Std_ReturnType gpio_port_direction_initalize(port_index_t port ,uint_8 direction ) ;
Std_ReturnType gpio_port_get_direction_status(port_index_t port  ,uint_8 *direction_status) ;
Std_ReturnType gpio_port_write_logic( port_index_t port ,uint_8 logic) ;
Std_ReturnType gpio_port_read_logic(port_index_t port  ,uint_8* logic) ;
Std_ReturnType gpio_port_toggle_logic(port_index_t port ) ;


















#endif	/* MCAL_GPIO_H */

