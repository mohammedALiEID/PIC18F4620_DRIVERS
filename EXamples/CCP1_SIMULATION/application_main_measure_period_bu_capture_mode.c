/* 
 * File:   main_application.c
 * Author: mohammed_ali
 *
 * Created on December 2, 2023, 4:23 PM
 */

/*section ***include ******************/
#include "application_main.h"


/*section ***global variables ******************/

TIMER3_CONFG_t timer3_obj = {.TIMER3_RW_register_mode = TIMER3_RW_16BIT_REGISTER,
    .TIMER3_interruptHandler = TIMER3_ISR_APP,
    .TIMER3_mode = TIMER3_TIMER_MODE,
    .TIMER3_preload_value = 0,
    .TIMER3_prescaler_value = TIMER3_PRESCALER_DIV_BY_1,
    .TIMER3_priority = interrupt_low_prioity};

CCP_cnfg_t ccp1_obj = {.CCP_MODE = CCP_CAPTURE_MODE_SELECT, .CCP_select = CCP1_SEL,
    .CCP_PIN.direction = INPUT, .CCP_PIN.logic = LOW,
    .CCP_PIN.pin = PIN2, .CCP_PIN.port = PORTC_INDEX,
    .CCP1_interruptHandler = CCP1_capture_ISR_APP,
    .CCP_Ca_Co_timer = CCP1_CCP2_Timer3,
    .CCP1_P1ority = interrupt_HIGH_prioity,
    .CCP_MODE_variant = CCP_CAPTURE_MODE_1_RISING_EDGE,};

volatile uint_8 ccp1_flag = 0;
volatile uint_32 TIMER3_overflow = 0;
volatile uint_8 CCP1_second_flag = 0;
volatile uint_16 second_captured_value = 0;
uint_32 total_captured_value = 0;
uint_32 freq = 0;





Std_ReturnType ret = 0;

int main() {


    general_initialization();

    while (1) {


        if (CCP1_second_flag == 2) {

            CCP1_second_flag = 0;

            total_captured_value = (TIMER3_overflow * 65536) + second_captured_value;
            freq = (uint_32) (1 / ((total_captured_value) / 1000000.0));
            TIMER3_overflow = 0;

        } else {
        }





    }





    return (EXIT_SUCCESS);
}

void general_initialization(void) {

    ECUAL_peripherals_initialization();

    
    ret = CCP_INITIALIZE(&ccp1_obj);
    ret = TIMER3_INITIALIZE(&timer3_obj);
}

void CCP1_capture_ISR_APP(void) {

    ccp1_flag++;
    CCP1_second_flag++;
    if (ccp1_flag == 1) {
        ret = TIMER3_WRITE_VALUE(&timer3_obj, 0);
        TIMER3_overflow = 0;
        
    } else if (ccp1_flag == 2)
 {

         ccp1_flag = 0;
         
        ret = CCP_capture_mode_read_value(&ccp1_obj, &second_captured_value);
       

    }


}

void TIMER3_ISR_APP(void) {
    TIMER3_overflow++;


}