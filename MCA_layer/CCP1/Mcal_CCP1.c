/* 
 * File:   Mcal_CCP1.c
 * Author: sayr3
 *
 * Created on January 24, 2024, 10:51 PM
 */
/*section:***********includes*******************************/
#include"Mcal_CCP1.h"
/*section:*********static helper functions declaration*****************/
static Std_ReturnType CCP_Capture_mod_confg(const CCP_cnfg_t*_ccp);
static Std_ReturnType CCP_Compare_mod_confg(const CCP_cnfg_t*_ccp);
static Std_ReturnType CCP_PWM_mod_confg(const CCP_cnfg_t*_ccp);
static Std_ReturnType CCP_Interrupt_confg(const CCP_cnfg_t*_ccp);
static Std_ReturnType CCP_capture_compare_Timer_confg(const CCP_cnfg_t*_ccp);

/*section:*********functions definition*****************/
static void(*CCP1_INTERRUPT_HANDLER)(void) = NULL;
static void(*CCP2_INTERRUPT_HANDLER)(void) = NULL;

Std_ReturnType CCP_INITIALIZE(const CCP_cnfg_t*_ccp) {
    Std_ReturnType ret = E_OK;
    if (NULL == _ccp) {

        ret = E_NOT_OK;

    } else {


        if (CCP1_SEL == _ccp->CCP_select) {
            CCP1_SELECT_MODE(CCP_MODULE_DISABLE);

        } else if (CCP2_SEL == _ccp->CCP_select) {
            CCP2_SELECT_MODE(CCP_MODULE_DISABLE);
        } else {
            ret = E_NOT_OK;
        }


        if (CCP_CAPTURE_MODE_SELECT == _ccp->CCP_MODE) {
            /**initialize pin ccp1 as input*/
            ret = gpio_pin_direction_initalize(&(_ccp->CCP_PIN));
            ret = CCP_Capture_mod_confg(_ccp);



        } else if (CCP_COMPARE_MODE_SELECT == _ccp->CCP_MODE) {
            /**initialize pin ccp1 as output*/
            ret = gpio_pin__ALL_initaliztion(&(_ccp->CCP_PIN));
            ret = CCP_Compare_mod_confg(_ccp);


        } else if (CCP_PMW_MODE_SELECT == _ccp->CCP_MODE) {

            /**initialize pin ccp1 as output*/
            ret = gpio_pin__ALL_initaliztion(&(_ccp->CCP_PIN));

#if (CCP1_CONFG_MODE_SELECTED ==CCP_PWM_MODE_SELECTED)||(CCP2_CONFG_MODE_SELECTED==CCP_PWM_MODE_SELECTED)        
            ret = CCP_PWM_mod_confg(_ccp);
#endif



        } else {
            ret = E_NOT_OK;
        }


        /************interrupt section******************/

        ret = CCP_Interrupt_confg(_ccp);



    }



    return ret;


}

Std_ReturnType CCP_DEINITIALIZE(const CCP_cnfg_t*_ccp) {
    Std_ReturnType ret = E_OK;
    if (NULL == _ccp) {

        ret = E_NOT_OK;

    } else {
        if (CCP1_SEL == _ccp->CCP_select) {


            CCP1_SELECT_MODE(CCP_MODULE_DISABLE);
            /***interrupt section*/
#if (CCP1_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)
            CCP1_INTERRUPT_DISABLE();

#endif

        } else if (CCP2_SEL == _ccp->CCP_select) {
            CCP2_SELECT_MODE(CCP_MODULE_DISABLE);
            /***interrupt section*/
#if (CCP2_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)
            CCP2_INTERRUPT_DISABLE();

#endif

        } else {
            ret = E_NOT_OK;
        }


    }



    return ret;



}

#if (CCP1_CONFG_MODE_SELECTED ==CCP_CAPTURE_MODE_SELECTED)||(CCP2_CONFG_MODE_SELECTED==CCP_CAPTURE_MODE_SELECTED)

Std_ReturnType CCP_IS_CAPTURE_competed(const CCP_cnfg_t*_ccp, uint_8 *_capture_status) {
    Std_ReturnType ret = E_OK;
    if ((NULL == _capture_status) || (NULL == _ccp)) {

        ret = E_NOT_OK;

    } else {


        if (CCP1_SEL == _ccp->CCP_select) {

            if (CCP_CAPTURE_completed == PIR1bits.CCP1IF) {
                *_capture_status = CCP_CAPTURE_completed;
                CCP1_INTERRUPT_CLEAR_FLAG();


            } else {
                *_capture_status = CCP_CAPTURE_NOT_completed;

            }


        } else if (CCP2_SEL == _ccp->CCP_select) {

            if (CCP_CAPTURE_completed == PIE2bits.CCP2IE) {
                *_capture_status = CCP_CAPTURE_completed;
                CCP2_INTERRUPT_CLEAR_FLAG();


            } else {
                *_capture_status = CCP_CAPTURE_NOT_completed;

            }

        } else {
            ret = E_NOT_OK;
        }


    }



    return ret;



}

Std_ReturnType CCP_capture_mode_read_value(const CCP_cnfg_t*_ccp, uint_16 *captured_value) {
    Std_ReturnType ret = E_OK;
    CCP_data_reg_t ccp_temp_reg = {.CCPR_16bit = 0};

    if ((NULL == captured_value) || (NULL == _ccp)) {

        ret = E_NOT_OK;

    } else {

        if (CCP1_SEL == _ccp->CCP_select) {

            ccp_temp_reg.CCPR_low = CCPR1L;
            ccp_temp_reg.CCPR_high = CCPR1H;
            *captured_value = ccp_temp_reg.CCPR_16bit;

            /**or *captured_value=(uint_16)((CCPR1H<<8)|CCPR1L) */


        } else if (CCP2_SEL == _ccp->CCP_select) {

            ccp_temp_reg.CCPR_low = CCPR2L;
            ccp_temp_reg.CCPR_high = CCPR2H;
            *captured_value = ccp_temp_reg.CCPR_16bit;

        } else {
            ret = E_NOT_OK;
        }


    }



    return ret;


}


#endif



#if (CCP1_CONFG_MODE_SELECTED ==CCP_COMPARE_MODE_SELECTED)||(CCP2_CONFG_MODE_SELECTED==CCP_COMPARE_MODE_SELECTED)

Std_ReturnType CCP_IS_compare_completed(const CCP_cnfg_t*_ccp, uint_8 *_compare_status) {
    Std_ReturnType ret = E_OK;
    if ((NULL == _compare_status) || (NULL == _ccp)) {

        ret = E_NOT_OK;

    } else {


        if (CCP1_SEL == _ccp->CCP_select) {

            if (CCP_COMPARE_completed == PIR1bits.CCP1IF) {
                *_compare_status = CCP_COMPARE_completed;
                CCP1_INTERRUPT_CLEAR_FLAG();


            } else {
                *_compare_status = CCP_COMPARE_NOT_completed;

            }


        } else if (CCP2_SEL == _ccp->CCP_select) {

            if (CCP_COMPARE_completed == PIE2bits.CCP2IE) {
                *_compare_status = CCP_COMPARE_completed;
                CCP2_INTERRUPT_CLEAR_FLAG();


            } else {
                *_compare_status = CCP_COMPARE_NOT_completed;

            }

        } else {
            ret = E_NOT_OK;
        }




    }



    return ret;


}

Std_ReturnType CCP_compare_mode_set_value(const CCP_cnfg_t*_ccp, uint_16 compared_value) {
    Std_ReturnType ret = E_OK;

    if (NULL == _ccp) {

        ret = E_NOT_OK;

    } else {
        CCP_data_reg_t ccp_temp_data_reg = {.CCPR_16bit = 0};
        ccp_temp_data_reg.CCPR_16bit = compared_value;
        if (CCP1_SEL == _ccp->CCP_select) {


            CCPR1L = ccp_temp_data_reg.CCPR_low;
            CCPR1H = ccp_temp_data_reg.CCPR_high;


        } else if (CCP2_SEL == _ccp->CCP_select) {
            CCPR2L = ccp_temp_data_reg.CCPR_low; /***or CCPR1L =(uint_8)compared_value ;CCPR1H =(uint_8)(compared_value>>8) */
            CCPR2H = ccp_temp_data_reg.CCPR_high;
        } else {
            ret = E_NOT_OK;
        }



    }

    return ret;


}


#endif



#if (CCP1_CONFG_MODE_SELECTED ==CCP_PWM_MODE_SELECTED)||(CCP2_CONFG_MODE_SELECTED==CCP_PWM_MODE_SELECTED)

Std_ReturnType CCP_PWM_set_duty_cycle(const CCP_cnfg_t*_ccp, uint_8 _duty) {
    Std_ReturnType ret = E_OK;

    if (NULL == _ccp) {

        ret = E_NOT_OK;

    } else {


        uint_16 L_duty_value = (uint_16) ((float) (PR2 + 1)*((float) _duty / 100.0)*4.0);

        if (CCP1_SEL == _ccp->CCP_select) {

            CCP1CONbits.DC1B = (uint_8) (L_duty_value & 0x0003);
            CCPR1L = (uint_8) (L_duty_value >> 2);

        } else if (CCP2_SEL == _ccp->CCP_select) {
            CCP2CONbits.DC2B = (uint_8) (L_duty_value & 0x0003);
            CCPR2L = (uint_8) (L_duty_value >> 2);

        } else {
            ret = E_NOT_OK;
        }


    }

    return ret;

}

Std_ReturnType CCP_PWM_start(const CCP_cnfg_t*_ccp) {
    Std_ReturnType ret = E_OK;

    if (NULL == _ccp) {

        ret = E_NOT_OK;

    } else {
        if (CCP1_SEL == _ccp->CCP_select) {

            CCP1_SELECT_MODE(CCP_PWM_MODE);

        } else if (CCP2_SEL == _ccp->CCP_select) {
            CCP2_SELECT_MODE(CCP_PWM_MODE);
        } else {
            ret = E_NOT_OK;
        }

    }
    return ret;



}

Std_ReturnType CCP_PWM_stop(const CCP_cnfg_t*_ccp) {
    Std_ReturnType ret = E_OK;

    if (NULL == _ccp) {

        ret = E_NOT_OK;

    } else {

        if (CCP1_SEL == _ccp->CCP_select) {
            CCP1_SELECT_MODE(CCP_MODULE_DISABLE);

        } else if (CCP2_SEL == _ccp->CCP_select) {
            CCP2_SELECT_MODE(CCP_MODULE_DISABLE);
        } else {
            ret = E_NOT_OK;
        }


    }


    return ret;



}
#endif

static Std_ReturnType CCP_Capture_mod_confg(const CCP_cnfg_t*_ccp) {

    Std_ReturnType ret = E_OK;

    if (NULL == _ccp) {

        ret = E_NOT_OK;

    } else {

        if (CCP1_SEL == _ccp->CCP_select) {
            switch (_ccp->CCP_MODE_variant) {

                case CCP_CAPTURE_MODE_1_FALLING_EDGE:
                    CCP1_SELECT_MODE(CCP_CAPTURE_MODE_1_FALLING_EDGE);
                    break;
                case CCP_CAPTURE_MODE_1_RISING_EDGE:
                    CCP1_SELECT_MODE(CCP_CAPTURE_MODE_1_RISING_EDGE);
                    break;
                case CCP_CAPTURE_MODE_4_RISING_EDGE:
                    CCP1_SELECT_MODE(CCP_CAPTURE_MODE_4_RISING_EDGE);
                    break;
                case CCP_CAPTURE_MODE_16_RISING_EDGE:
                    CCP1_SELECT_MODE(CCP_CAPTURE_MODE_16_RISING_EDGE);
                    break;

                default: ret = E_NOT_OK;
                    break;
            }

        } else if (CCP2_SEL == _ccp->CCP_select) {
            switch (_ccp->CCP_MODE_variant) {

                case CCP_CAPTURE_MODE_1_FALLING_EDGE:
                    CCP2_SELECT_MODE(CCP_CAPTURE_MODE_1_FALLING_EDGE);
                    break;
                case CCP_CAPTURE_MODE_1_RISING_EDGE:
                    CCP2_SELECT_MODE(CCP_CAPTURE_MODE_1_RISING_EDGE);
                    break;
                case CCP_CAPTURE_MODE_4_RISING_EDGE:
                    CCP2_SELECT_MODE(CCP_CAPTURE_MODE_4_RISING_EDGE);
                    break;
                case CCP_CAPTURE_MODE_16_RISING_EDGE:
                    CCP2_SELECT_MODE(CCP_CAPTURE_MODE_16_RISING_EDGE);
                    break;

                default: ret = E_NOT_OK;
                    break;
            }
        } else {
            ret = E_NOT_OK;
        }

        ret = CCP_capture_compare_Timer_confg(_ccp);
    }


    return ret;




}

static Std_ReturnType CCP_Compare_mod_confg(const CCP_cnfg_t*_ccp) {

    Std_ReturnType ret = E_OK;

    if (NULL == _ccp) {

        ret = E_NOT_OK;

    } else {

        if (CCP1_SEL == _ccp->CCP_select) {
            switch (_ccp->CCP_MODE_variant) {

                case CCP_COMPARE_MODE_TOGGLE_PIN_CCPx_ON_MATCH:
                    CCP1_SELECT_MODE(CCP_COMPARE_MODE_TOGGLE_PIN_CCPx_ON_MATCH);
                    break;
                case CCP_COMPARE_MODE_SET_PIN_CCPx_HIGH:
                    CCP1_SELECT_MODE(CCP_COMPARE_MODE_SET_PIN_CCPx_HIGH);
                    break;
                case CCP_COMPARE_MODE_SET_PIN_CCPx_LOW:
                    CCP1_SELECT_MODE(CCP_COMPARE_MODE_SET_PIN_CCPx_LOW);
                    break;
                case CCP_COMPARE_MODE_GENERAT_SW_INTERRUPT:
                    CCP1_SELECT_MODE(CCP_COMPARE_MODE_GENERAT_SW_INTERRUPT);
                    break;
                case CCP_COMPARE_MODE_TRIGGER_SPECIAL_EVENT:
                    CCP1_SELECT_MODE(CCP_COMPARE_MODE_TRIGGER_SPECIAL_EVENT);
                    break;

                default: ret = E_NOT_OK;
                    break;
            }

        } else if (CCP2_SEL == _ccp->CCP_select) {
            switch (_ccp->CCP_MODE_variant) {

                case CCP_COMPARE_MODE_TOGGLE_PIN_CCPx_ON_MATCH:
                    CCP2_SELECT_MODE(CCP_COMPARE_MODE_TOGGLE_PIN_CCPx_ON_MATCH);
                    break;
                case CCP_COMPARE_MODE_SET_PIN_CCPx_HIGH:
                    CCP2_SELECT_MODE(CCP_COMPARE_MODE_SET_PIN_CCPx_HIGH);
                    break;
                case CCP_COMPARE_MODE_SET_PIN_CCPx_LOW:
                    CCP2_SELECT_MODE(CCP_COMPARE_MODE_SET_PIN_CCPx_LOW);
                    break;
                case CCP_COMPARE_MODE_GENERAT_SW_INTERRUPT:
                    CCP2_SELECT_MODE(CCP_COMPARE_MODE_GENERAT_SW_INTERRUPT);
                    break;
                case CCP_COMPARE_MODE_TRIGGER_SPECIAL_EVENT:
                    CCP2_SELECT_MODE(CCP_COMPARE_MODE_TRIGGER_SPECIAL_EVENT);
                    break;

                default: ret = E_NOT_OK;
                    break;
            }
        } else {
            ret = E_NOT_OK;
        }

        ret = CCP_capture_compare_Timer_confg(_ccp);

    }


    return ret;

}
#if (CCP1_CONFG_MODE_SELECTED ==CCP_PWM_MODE_SELECTED)||(CCP2_CONFG_MODE_SELECTED==CCP_PWM_MODE_SELECTED)

static Std_ReturnType CCP_PWM_mod_confg(const CCP_cnfg_t*_ccp) {

    Std_ReturnType ret = E_OK;

    if (NULL == _ccp) {

        ret = E_NOT_OK;

    } else {

        if (CCP1_SEL == _ccp->CCP_select) {
            if (CCP_PWM_MODE == _ccp->CCP_MODE_variant) {
                CCP1_SELECT_MODE(CCP_PWM_MODE);

            } else {
                /*nothing*/
            }
            PR2 = (uint_8) ((_XTAL_FREQ / ((_ccp->PWM_frequency)*4.0 *
                    (_ccp->TIMER2_postscaler_value)*(_ccp->TIMER2_prescaler_value))) - 1);

        } else if (CCP2_SEL == _ccp->CCP_select) {
            if (CCP_PWM_MODE == _ccp->CCP_MODE_variant) {
                CCP2_SELECT_MODE(CCP_PWM_MODE);

            } else {
                /*nothing*/
            }

            PR2 = (uint_8) ((_XTAL_FREQ / ((_ccp->PWM_frequency)*4.0 *
                    (_ccp->TIMER2_postscaler_value)*(_ccp->TIMER2_prescaler_value))) - 1);
        } else {
            ret = E_NOT_OK;
        }



    }


    return ret;

}
#endif

static Std_ReturnType CCP_Interrupt_confg(const CCP_cnfg_t*_ccp) {

    Std_ReturnType ret = E_OK;

    if (NULL == _ccp) {

        ret = E_NOT_OK;

    } else {

        if (CCP1_SEL == _ccp->CCP_select) {

#if (CCP1_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)
            CCP1_INTERRUPT_DISABLE();
            CCP1_INTERRUPT_CLEAR_FLAG();
            CCP1_INTERRUPT_HANDLER = _ccp->CCP1_interruptHandler;
#if (INRERRUPT_PRIORITY_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE) 
            INTERRUPT_PRIORITY_LEVELS_ENABLE();
            if (interrupt_low_prioity == _ccp->CCP1_P1ority) {
                INTERRUPT_GLOBAL_INTERRUPT_ENABLE_LOW();
                CCP1_INTERRUPT_SET_LOW_PRIORITY();

            } else if (interrupt_HIGH_prioity == _ccp->CCP1_P1ority) {
                INTERRUPT_GLOBAL_INTERRUPT_ENABLE_HIGH();
                CCP1_INTERRUPT_SET_HIGH_PRIORITY();
            } else {
                INTERRUPT_GLOBAL_INTERRUPT_ENABLE_LOW();
                CCP1_INTERRUPT_SET_LOW_PRIORITY();
            }

#else
            INTERRUPT_GLOBAL_INTERRUPT_ENABLE();
            INTERRUPT_PERIPHERAL_INTERRUPT_ENABLE();

#endif

            CCP1_INTERRUPT_ENABLE();


#endif



        } else if (CCP2_SEL == _ccp->CCP_select) {
#if (CCP2_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)
            CCP2_INTERRUPT_DISABLE();
            CCP2_INTERRUPT_CLEAR_FLAG();
            CCP2_INTERRUPT_HANDLER = _ccp->CCP2_interruptHandler;
#if (INRERRUPT_PRIORITY_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE) 
            INTERRUPT_PRIORITY_LEVELS_ENABLE();
            if (interrupt_low_prioity == _ccp->CCP2_P1ority) {
                INTERRUPT_GLOBAL_INTERRUPT_ENABLE_LOW();
                CCP2_INTERRUPT_SET_LOW_PRIORITY();

            } else if (interrupt_HIGH_prioity == _ccp->CCP2_P1ority) {
                INTERRUPT_GLOBAL_INTERRUPT_ENABLE_HIGH();
                CCP2_INTERRUPT_SET_HIGH_PRIORITY();
            } else {
                INTERRUPT_GLOBAL_INTERRUPT_ENABLE_LOW();
                CCP2_INTERRUPT_SET_LOW_PRIORITY();
            }

#else
            INTERRUPT_GLOBAL_INTERRUPT_ENABLE();
            INTERRUPT_PERIPHERAL_INTERRUPT_ENABLE();

#endif

            CCP2_INTERRUPT_ENABLE();


#endif
        } else {
            ret = E_NOT_OK;
        }


    }


    return ret;

}

static Std_ReturnType CCP_capture_compare_Timer_confg(const CCP_cnfg_t*_ccp) {

    Std_ReturnType ret = E_OK;

    if (NULL == _ccp) {

        ret = E_NOT_OK;

    } else {

        switch (_ccp->CCP_Ca_Co_timer) {

            case CCP1_CCP2_Timer1:
                T3CONbits.T3CCP1 = 0;
                T3CONbits.T3CCP2 = 0;
                break;
            case CCP1_Timer1_CCP2_Timer3:
                T3CONbits.T3CCP1 = 1;
                T3CONbits.T3CCP2 = 0;
                break;
            case CCP1_CCP2_Timer3:
                T3CONbits.T3CCP1 = 1;
                T3CONbits.T3CCP2 = 1;
                break;
            default: ret = E_NOT_OK;
                break;
        }



    }


    return ret;

}

void CCP1_ISR(void) {
#if (CCP1_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)   
    CCP1_INTERRUPT_CLEAR_FLAG();
#endif

    if (CCP1_INTERRUPT_HANDLER) {

        CCP1_INTERRUPT_HANDLER();
    } else {
        /*nothing*/
    }


}

void CCP2_ISR(void) {
#if (CCP2_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)   
    CCP2_INTERRUPT_CLEAR_FLAG();
#endif

    if (CCP2_INTERRUPT_HANDLER) {

        CCP2_INTERRUPT_HANDLER();
    } else {
        /*nothing*/
    }


}