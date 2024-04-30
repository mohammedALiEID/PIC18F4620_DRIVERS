/* 
 * File:   mcal_GPIO.c
 * Author: mohammed_ali
 *
 * Created on December 2, 2023, 6:01 PM
 */
/*section:***********includes*******************************/
#include "mcal_GPIO.h"  

/*section:*********functions definition*****************/
volatile uint_8*tris_regisrers[PORT__MAX_NUMBER]= {&TRISA ,&TRISB ,&TRISC ,&TRISD ,&TRISE  };
volatile uint_8*port_regisrers[PORT__MAX_NUMBER]= {&PORTA ,&PORTB ,&PORTC ,&PORTD ,&PORTE  };
volatile uint_8*lat_regisrers[PORT__MAX_NUMBER]= {&LATA ,&LATB ,&LATC ,&LATD ,&LATE  };
/**
 * @breif initialize the pin direction
 * @param pin_confg PIN_Configuration @ref pin_confg_t
 * @return status of the function 
            (E_OK) the function done successfully 
            (E_NOT_OK) the function has issue to do the action 
 */
#if (GPIO_PIN_CONFIGURATION==STD_config_enable)
Std_ReturnType gpio_pin_direction_initalize(const pin_confg_t *pin_confg ) {
    Std_ReturnType ret = E_OK  ;
    
    if ((NULL==pin_confg )||(pin_confg->port > PORT__MAX_NUMBER -1) || (pin_confg->pin >PIN_MAX_NUMBER -1))
        ret = E_NOT_OK ;
    else {
        switch (pin_confg->direction){
            case  OUTPUT :
                
                clear_bit(*tris_regisrers[pin_confg->port],pin_confg->pin) ;
                
                break ;
                
            case   INPUT :
                
                set_bit(*tris_regisrers[pin_confg->port],pin_confg->pin) ;
                
                break ;
            
            default :
ret = E_NOT_OK ;
                
                break ;
            
            
            
        }
                
        
        
        
    }
    return ret ;
}

#endif 
/**
 * @breif get the direction status of the pin 
 * @param pin_confg PIN_Configuration @ref pin_confg_t
 * @param direction_status
 * @return status of the function 
            (E_OK) the function done successfully 
            (E_NOT_OK) the function has issue to do the action 
 */
#if (GPIO_PIN_CONFIGURATION==STD_config_enable)
Std_ReturnType gpio_pin_get_direction_status(const pin_confg_t *pin_confg ,direction_t *direction_status) {
       Std_ReturnType ret = E_OK  ;
    
    if ((NULL==pin_confg )||(pin_confg->port > PORT__MAX_NUMBER -1) || (pin_confg->pin >PIN_MAX_NUMBER -1)||(NULL==direction_status))
        ret = E_NOT_OK ;
    else {
        
        *direction_status = read_bit(*tris_regisrers[pin_confg->port],pin_confg->pin) ;
        
        
        
        
        
        
    }
       
    return ret ;
    
    
}
#endif 
/**
 * @breif write logic on the pin 
 * @param  pin_confg PIN_Configuration @ref pin_confg_t
 * @param logic
 * @return status of the function 
            (E_OK) the function done successfully 
            (E_NOT_OK) the function has issue to do the action 
 */
#if (GPIO_PIN_CONFIGURATION==STD_config_enable)
Std_ReturnType gpio_pin_write_logic(const pin_confg_t *pin_confg ,logic_t logic) {
    
      Std_ReturnType ret = E_OK  ;
    
    if ((NULL==pin_confg )||(pin_confg->port > PORT__MAX_NUMBER -1) || (pin_confg->pin >PIN_MAX_NUMBER -1))
        ret = E_NOT_OK ;
    else {
        
        switch (logic){
            case  LOW :
                
                clear_bit (*lat_regisrers[pin_confg->port],pin_confg->pin) ;
                
                break ;
                
            case   HIGH : 
                
                set_bit(*lat_regisrers[pin_confg->port],pin_confg->pin);
                break ;
            default :
                
           ret = E_NOT_OK ;
                break ;
            
            
        }
        
        
    }
      
    return ret ;
    
}
#endif 
/**
 * @breif read logic on the pin
 * @param  pin_confg PIN_Configuration @ref pin_confg_t
 * @param logic
 * @return status of the function 
            (E_OK) the function done successfully 
            (E_NOT_OK) the function has issue to do the action 
 */
#if (GPIO_PIN_CONFIGURATION==STD_config_enable)
Std_ReturnType gpio_pin_read_logic(const pin_confg_t *pin_confg ,logic_t* logic)  {
      Std_ReturnType ret = E_OK  ;
    
    if ((NULL==pin_confg )||(pin_confg->port > PORT__MAX_NUMBER -1) || (pin_confg->pin >PIN_MAX_NUMBER -1)||(NULL==logic))
        ret = E_NOT_OK ;
    else {
        
         *logic = read_bit(*port_regisrers[pin_confg->port],pin_confg->pin) ;
        
        
    }
    return ret ;
    
    
}
#endif 
/**
 * @breif toggle the logic  on the pin 
 * @param  pin_confg PIN_Configuration @ref pin_confg_t
 * @return status of the function 
            (E_OK) the function done successfully 
            (E_NOT_OK) the function has issue to do the action 
 */
#if (GPIO_PIN_CONFIGURATION==STD_config_enable)
Std_ReturnType gpio_pin_toggle_logic(const pin_confg_t *pin_confg )  {
     Std_ReturnType ret = E_OK  ;
    
    if ((NULL==pin_confg )||(pin_confg->port > PORT__MAX_NUMBER -1) || (pin_confg->pin >PIN_MAX_NUMBER -1))
        ret = E_NOT_OK ;
    else {
        
        toggle_bit(*lat_regisrers[pin_confg->port],pin_confg->pin) ;
        
        
    }
    return ret ;
    
    
}
#endif 
/**
 * @breif initialize the direction of the pin and write logic low on the pin to avoid the unknown value of the lat_register 
 * @param  pin_confg PIN_Configuration @ref pin_confg_t
 * @return status of the function 
            (E_OK) the function done successfully 
            (E_NOT_OK) the function has issue to do the action 
 */
#if (GPIO_PIN_CONFIGURATION==STD_config_enable)
Std_ReturnType gpio_pin__ALL_initaliztion(const pin_confg_t *pin_confg ) {
      Std_ReturnType ret = E_OK  ;
    
    if ((NULL==pin_confg )||(pin_confg->port > PORT__MAX_NUMBER -1) || (pin_confg->pin >PIN_MAX_NUMBER -1))
        ret = E_NOT_OK ;
    else {
       ret= gpio_pin_direction_initalize(pin_confg) ;
      ret = gpio_pin_write_logic(pin_confg,pin_confg->logic) ;
       
        
        
    }
    return ret ;
    
    
}
#endif 
/**
 * @breif initialize the port direction 
 * @param port port index @ref port_index_t
 * @param direction the direction of port
 * @return status of the function 
            (E_OK) the function done successfully 
            (E_NOT_OK) the function has issue to do the action 
 */
#if (GPIO_port_CONFIGURATION==STD_config_enable)
Std_ReturnType gpio_port_direction_initalize(port_index_t port ,uint_8 direction ) {
     Std_ReturnType ret = E_OK  ;
    if (port > (PORT__MAX_NUMBER -1)){
        
        ret =E_NOT_OK ;
        
    }
    else {
        
        *tris_regisrers[port]=direction ;
        
    }
    return ret ;
    
}
#endif 
/**
 * @breif  get the port direction 
 * @param port port index @ref port_index_t
 * @param direction_status return the direction status of the port 
 * @return status of the function 
            (E_OK) the function done successfully 
            (E_NOT_OK) the function has issue to do the action 
 */
#if (GPIO_port_CONFIGURATION==STD_config_enable)
Std_ReturnType gpio_port_get_direction_status(port_index_t port  ,uint_8 *direction_status)  {
      Std_ReturnType ret = E_OK  ;
    if ((port > (PORT__MAX_NUMBER -1)||(NULL==direction_status))){
        
        ret =E_NOT_OK ;
        
    }
    else {
        *direction_status = *tris_regisrers[port] ;
        
        
    }
    return ret ;
    
    
}
#endif
/**
 * @breif  write logic on the port 
 * @paramport port index @ref port_index_t
 * @param logic the logic of the port
 *@return status of the function 
            (E_OK) the function done successfully 
            (E_NOT_OK) the function has issue to do the action 
 */
#if (GPIO_port_CONFIGURATION==STD_config_enable)
Std_ReturnType gpio_port_write_logic( port_index_t port ,uint_8 logic)  {
    
      Std_ReturnType ret = E_OK  ;
    if (port > (PORT__MAX_NUMBER -1)){
        
        ret =E_NOT_OK ;
        
    }
    else {
        
        *lat_regisrers[port]=logic ;
        
    }
    return ret ;
    
    
}
#endif
/**
 * @breif  read logic on the port
 * @param port port index @ref port_index_t
 * @param logic return logic on the port 
 * @return status of the function 
            (E_OK) the function done successfully 
            (E_NOT_OK) the function has issue to do the action 
 */ 
#if (GPIO_port_CONFIGURATION==STD_config_enable)
Std_ReturnType gpio_port_read_logic(port_index_t port  ,uint_8* logic)  {
      Std_ReturnType ret = E_OK  ;
    if ((port > (PORT__MAX_NUMBER -1)||(NULL==logic))){
        
        ret =E_NOT_OK ;
        
    }
    else {
        
        * logic =*port_regisrers[port] ;
        
    }
    return ret ;
    
    
    
    
}
#endif
/**
 * @breif toggle the port logic 
 * @param port port index @ref port_index_t
 * @return status of the function 
            (E_OK) the function done successfully 
            (E_NOT_OK) the function has issue to do the action 
 */
#if (GPIO_port_CONFIGURATION==STD_config_enable)
Std_ReturnType gpio_port_toggle_logic(port_index_t port )  {
     Std_ReturnType ret = E_OK  ;
    if (port > (PORT__MAX_NUMBER -1)){
        
        ret =E_NOT_OK ;
        
    }
    else {
        
        (*lat_regisrers[port])^= PORTC_MASK ;
        
    }
    return ret ;
    
    
}

#endif