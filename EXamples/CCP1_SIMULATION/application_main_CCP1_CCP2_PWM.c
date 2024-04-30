/* 
 * File:   main_application.c
 * Author: mohammed_ali
 *
 * Created on December 2, 2023, 4:23 PM
 */

/*section ***include ******************/
#include "application_main.h"


/*section ***global variables ******************/


TIMER2_CONFG_t timer2_obj = {.TIMER2_interruptHandler = NULL,
    .TIMER2_postscaler_value = TIMER2_POSTSCALER_DIV_BY_1,
    .TIMER2_prescaler_value = TIMER2_PRESCALER_DIV_BY_1,
    .TIMER2_preload_value = 0};


CCP_cnfg_t ccp1_obj = {.CCP_MODE = CCP_PMW_MODE_SELECT,.CCP_select =CCP1_SEL ,
    .CCP_PIN.direction = OUTPUT, .CCP_PIN.logic = LOW,
    .CCP_PIN.pin = PIN2, .CCP_PIN.port = PORTC_INDEX,
    .CCP1_interruptHandler = NULL,
    .PWM_frequency = 20000,
    .TIMER2_postscaler_value = CCP_TIMER2_POSTSCALER_DIV_BY_1,
    .TIMER2_prescaler_value = CCP_TIMER2_PRESCALER_DIV_BY_1,
};



CCP_cnfg_t ccp2_obj = {.CCP_MODE = CCP_PMW_MODE_SELECT,.CCP_select =CCP2_SEL ,
    .CCP_PIN.direction = OUTPUT, .CCP_PIN.logic = LOW,
    .CCP_PIN.pin = PIN1, .CCP_PIN.port = PORTC_INDEX,
    .CCP1_interruptHandler = NULL,
    .PWM_frequency = 20000,
    .TIMER2_postscaler_value = CCP_TIMER2_POSTSCALER_DIV_BY_1,
    .TIMER2_prescaler_value = CCP_TIMER2_PRESCALER_DIV_BY_1,
};


Std_ReturnType ret = 0;

int main() {


    general_initialization();
    ret =CCP_PWM_set_duty_cycle(&ccp1_obj ,90) ;
    ret =CCP_PWM_set_duty_cycle(&ccp2_obj ,10) ;
    ret =CCP_PWM_start(&ccp1_obj) ;
    ret =CCP_PWM_start(&ccp2_obj) ;
    while (1) {

    }





    return (EXIT_SUCCESS);
}

void general_initialization(void) {

    ECUAL_peripherals_initialization();
    ret = CCP_INITIALIZE(&ccp1_obj) ;
    ret = CCP_INITIALIZE(&ccp2_obj) ;
    ret = TIMER2_INITIALIZE(&timer2_obj);

}

void CCP1_ISR_APP(void) {



}
