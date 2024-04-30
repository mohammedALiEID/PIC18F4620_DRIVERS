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

CCP_cnfg_t ccp1_obj = {.CCP_MODE = CCP_COMPARE_MODE_SELECT, .CCP_select = CCP1_SEL,
    .CCP_PIN.direction = OUTPUT, .CCP_PIN.logic = LOW,
    .CCP_PIN.pin = PIN2, .CCP_PIN.port = PORTC_INDEX,
    .CCP1_interruptHandler = CCP1_compare_ISR_APP,
    .CCP_Ca_Co_timer = CCP1_CCP2_Timer3,
    .CCP1_P1ority = interrupt_HIGH_prioity,
    .CCP_MODE_variant = CCP_COMPARE_MODE_TOGGLE_PIN_CCPx_ON_MATCH};



volatile uint_8 ccp1_flag = 0 ;


Std_ReturnType ret = 0;

int main() {

  ret = CCP_compare_mode_set_value(&ccp1_obj ,30000) ;
    general_initialization();
    
  

    while (1) {







    }





    return (EXIT_SUCCESS);
}

void general_initialization(void) {

    ECUAL_peripherals_initialization();

  
    ret = CCP_INITIALIZE(&ccp1_obj);
    ret = TIMER3_INITIALIZE(&timer3_obj);
}

void CCP1_compare_ISR_APP(void) {
    ccp1_flag++ ;
    if(1==ccp1_flag){
     ret =TIMER3_WRITE_VALUE(&timer3_obj ,0) ;
     ret = CCP_compare_mode_set_value(&ccp1_obj, 20000) ;
      
       
    }
    
    else if (2==ccp1_flag){
        ccp1_flag=0 ;
        ret =TIMER3_WRITE_VALUE(&timer3_obj ,0) ;
        ret = CCP_compare_mode_set_value(&ccp1_obj ,30000) ;
     
        
    }
  
    

}

void TIMER3_ISR_APP(void) {
    

}