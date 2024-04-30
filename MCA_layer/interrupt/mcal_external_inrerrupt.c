/* 
 * File:    mcal_external_inrerrupt.c
 * Author: sayr3
 *
 * Created on December 29, 2023, 11:42 AM
 */
/*section:***********includes*******************************/

#include"mcal_external_inrerrupt.h"
/*section:*********static helper functions declaration*****************/

static Std_ReturnType Interrupt_INTX_ENABLE(const Interrupt_INTX_t*int_obj) ;
static Std_ReturnType Interrupt_INTX_DISBLE(const Interrupt_INTX_t*int_obj) ;
static Std_ReturnType Interrupt_INTX_EDGE_INIT(const Interrupt_INTX_t*int_obj) ;
static Std_ReturnType Interrupt_INTX_PRIORITY_INIT(const Interrupt_INTX_t*int_obj) ;
static Std_ReturnType Interrupt_INTX_PIN_INIT(const Interrupt_INTX_t*int_obj) ;
static Std_ReturnType Interrupt_INTX_CLEAR_FLAG(const Interrupt_INTX_t*int_obj) ;
static Std_ReturnType Interrupt_INTX_SET_INTERRUPT_HANDLER(const Interrupt_INTX_t*int_obj) ;

static Std_ReturnType Interrupt_RBX_ENABLE(const Interrupt_RBX_t*int_obj) ;
static Std_ReturnType Interrupt_RBX_DISBLE(const Interrupt_RBX_t*int_obj) ;
static Std_ReturnType Interrupt_RBX_CLEAR_FLAG(const Interrupt_RBX_t*int_obj) ;
static Std_ReturnType Interrupt_RBX_PRIORITY_INIT(const Interrupt_RBX_t*int_obj) ;
static Std_ReturnType Interrupt_RBX_PIN_INIT(const Interrupt_RBX_t*int_obj) ;
static Std_ReturnType Interrupt_RBX_SET_INTERRUPT_HANDLER(const Interrupt_RBX_t*int_obj) ;

/*section:*********static function pointer_INTX*****************/
static void (*INT0_INTERRUPT_HANDLER)(void)=NULL ;
static void (*INT1_INTERRUPT_HANDLER)(void)=NULL ;
static void (*INT2_INTERRUPT_HANDLER)(void)=NULL ;

/*section:*********INTX_ISR_definition*****************/
void INT0_ISR(void){
   EXT_INT0_INTERRUPT_CLEAR_FLAG()  ;
   if(INT0_INTERRUPT_HANDLER){
     INT0_INTERRUPT_HANDLER() ;
   }
     else{/*nothing*/}

}
void INT1_ISR(void){
   EXT_INT1_INTERRUPT_CLEAR_FLAG()  ;
   if(INT1_INTERRUPT_HANDLER){
     INT1_INTERRUPT_HANDLER() ;
   }
     else{/*nothing*/}

}
void INT2_ISR(void){
   EXT_INT2_INTERRUPT_CLEAR_FLAG()  ;
   if(INT2_INTERRUPT_HANDLER){
     INT2_INTERRUPT_HANDLER() ;
   }
     else{/*nothing*/}

}

/*section:*********static function pointer_RBX*****************/

static void (*RB4_INTERRUPT_HANDLER_HIGH)(void)=NULL ; /*** OR static interrup_handler RB4_INTERRUPT_HANDLER_HIGH =NULL ;
                                                              *  another syntax using typedef in "mcal_std_types" "interrup_handler"*/
static void (*RB4_INTERRUPT_HANDLER_LOW)(void)=NULL ;
static void (*RB5_INTERRUPT_HANDLER_HIGH)(void)=NULL ;
static void (*RB5_INTERRUPT_HANDLER_LOW)(void)=NULL ;
static void (*RB6_INTERRUPT_HANDLER_HIGH)(void)=NULL ;
static void (*RB6_INTERRUPT_HANDLER_LOW)(void)=NULL ;
static void (*RB7_INTERRUPT_HANDLER_HIGH)(void)=NULL ;
static void (*RB7_INTERRUPT_HANDLER_LOW)(void)=NULL ;
/*section:*********RBX_ISR_definition*****************/
void RB4_ISR_HIGH(void){
  EXT_RBX_INTERRUPT_CLEAR_FLAG() ;
   if(RB4_INTERRUPT_HANDLER_HIGH){
     RB4_INTERRUPT_HANDLER_HIGH() ;
   }
     else{/*nothing*/}

}
void RB4_ISR_LOW(void){
  EXT_RBX_INTERRUPT_CLEAR_FLAG() ;
   if(RB4_INTERRUPT_HANDLER_LOW){
     RB4_INTERRUPT_HANDLER_LOW() ;
   }
     else{/*nothing*/}

}
void RB5_ISR_HIGH(void){
  EXT_RBX_INTERRUPT_CLEAR_FLAG() ;
   if(RB5_INTERRUPT_HANDLER_HIGH){
     RB5_INTERRUPT_HANDLER_HIGH() ;
   }
     else{/*nothing*/}

}
void RB5_ISR_LOW(void){
  EXT_RBX_INTERRUPT_CLEAR_FLAG() ;
   if(RB5_INTERRUPT_HANDLER_LOW){
     RB5_INTERRUPT_HANDLER_LOW() ;
   }
     else{/*nothing*/}

}
void RB6_ISR_HIGH(void){
  EXT_RBX_INTERRUPT_CLEAR_FLAG() ;
   if(RB6_INTERRUPT_HANDLER_HIGH){
     RB6_INTERRUPT_HANDLER_HIGH() ;
   }
     else{/*nothing*/}

}
void RB6_ISR_LOW(void){
  EXT_RBX_INTERRUPT_CLEAR_FLAG() ;
   if(RB6_INTERRUPT_HANDLER_LOW){
     RB6_INTERRUPT_HANDLER_LOW() ;
   }
     else{/*nothing*/}

}
void RB7_ISR_HIGH(void){
  EXT_RBX_INTERRUPT_CLEAR_FLAG() ;
   if(RB7_INTERRUPT_HANDLER_HIGH){
     RB7_INTERRUPT_HANDLER_HIGH() ;
   }
     else{/*nothing*/}

}
void RB7_ISR_LOW(void){
  EXT_RBX_INTERRUPT_CLEAR_FLAG() ;
   if(RB7_INTERRUPT_HANDLER_LOW){
     RB7_INTERRUPT_HANDLER_LOW() ;
   }
     else{/*nothing*/}

}

/*section:*********functions definition*****************/

/**
 * 
 * @param int_obj
 * @return 
 */
Std_ReturnType Interrupt_INTX_Initialize(const Interrupt_INTX_t*int_obj) {
    
    Std_ReturnType ret =E_OK ;
    if (NULL==int_obj){
        
        ret=E_NOT_OK ;
        
    }
    else {
        ret = Interrupt_INTX_DISBLE(int_obj) ;
        
        ret = Interrupt_INTX_CLEAR_FLAG(int_obj) ;
        ret = Interrupt_INTX_EDGE_INIT(int_obj) ;
        #if (INRERRUPT_PRIORITY_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)
        ret = Interrupt_INTX_PRIORITY_INIT(int_obj) ;
        #endif
        ret = Interrupt_INTX_PIN_INIT(int_obj) ;
        ret = Interrupt_INTX_SET_INTERRUPT_HANDLER(int_obj);
     
        ret = Interrupt_INTX_ENABLE(int_obj) ;
        
    }
    
    return ret ;
}
/**
 * 
 * @param int_obj
 * @return 
 */
Std_ReturnType Interrupt_INTX_DEInitialize(const Interrupt_INTX_t*int_obj) {
    Std_ReturnType ret =E_OK ;
    if (NULL==int_obj){
        
        ret=E_NOT_OK ;
        
    }
    else {
        ret=Interrupt_INTX_DISBLE(int_obj) ;
        
        
    }
    
    return ret ;
    
}
/**
 * 
 * @param int_obj
 * @return 
 */
Std_ReturnType Interrupt_RBX_Initialize(const Interrupt_RBX_t*int_obj) {
    Std_ReturnType ret =E_OK ;
    if (NULL==int_obj){
        
        ret=E_NOT_OK ;
        
    }
    else {
          ret &= Interrupt_RBX_DISBLE(int_obj) ; /*we use ret&= or ret|= to return OK or NOT_Ok in general to  ensure all functions return ok  */
          
          ret &= Interrupt_RBX_CLEAR_FLAG(int_obj) ;
          #if (INRERRUPT_PRIORITY_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)
          ret&=Interrupt_RBX_PRIORITY_INIT(int_obj) ;
          #endif
          ret&= Interrupt_RBX_PIN_INIT(int_obj) ;
          ret&=Interrupt_RBX_SET_INTERRUPT_HANDLER(int_obj) ;
          
          ret &=Interrupt_RBX_ENABLE(int_obj) ;
        
    }
    
    return ret ;
    
}
/**
 * 
 * @param int_obj
 * @return 
 */
Std_ReturnType Interrupt_RBX_DEInitialize(const Interrupt_RBX_t*int_obj) {
    
    Std_ReturnType ret =E_OK ;
    if (NULL==int_obj){
        
        ret=E_NOT_OK ;
        
    }
    else {
        ret=Interrupt_RBX_DISBLE (int_obj) ;
        
    }
    
    return ret ;
}

/**
 * 
 * @param int_obj
 * @return 
 */
static Std_ReturnType Interrupt_INTX_ENABLE(const Interrupt_INTX_t*int_obj) {
    
    Std_ReturnType ret =E_OK ;
    if (NULL==int_obj){
        
        ret=E_NOT_OK ;
        
    }
    else {
       switch (int_obj->source) {
          case interrupt_INT0 : 
          EXT_INT0_INTERRUPT_ENABLE() ;
 #if (INRERRUPT_PRIORITY_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)
          INTERRUPT_PRIORITY_LEVELS_ENABLE()  ;
         INTERRUPT_GLOBAL_INTERRUPT_ENABLE_HIGH() ;
           
#else
          
          INTERRUPT_GLOBAL_INTERRUPT_ENABLE() ;
          INTERRUPT_PERIPHERAL_INTERRUPT_ENABLE()   ;
#endif
          break ;
          case interrupt_INT1 : 
          EXT_INT1_INTERRUPT_ENABLE() ;
 #if (INRERRUPT_PRIORITY_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)
          INTERRUPT_PRIORITY_LEVELS_ENABLE()     ;
           if (interrupt_low_prioity==int_obj->priorty)
           {INTERRUPT_GLOBAL_INTERRUPT_ENABLE_LOW() ;} 
           else if (interrupt_HIGH_prioity==int_obj->priorty)
           {INTERRUPT_GLOBAL_INTERRUPT_ENABLE_HIGH() ;}
           else {ret=E_NOT_OK ;}
          
#else
          
          INTERRUPT_GLOBAL_INTERRUPT_ENABLE() ;
          INTERRUPT_PERIPHERAL_INTERRUPT_ENABLE()   ;
#endif
          break ;
          case interrupt_INT2 : 
          EXT_INT2_INTERRUPT_ENABLE() ;
 #if (INRERRUPT_PRIORITY_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)
          INTERRUPT_PRIORITY_LEVELS_ENABLE()     ;
           if (interrupt_low_prioity==int_obj->priorty)
           {INTERRUPT_GLOBAL_INTERRUPT_ENABLE_LOW() ;} 
           else if (interrupt_HIGH_prioity==int_obj->priorty)
           {INTERRUPT_GLOBAL_INTERRUPT_ENABLE_HIGH() ;}
           else {ret=E_NOT_OK ;}
          
#else
          
          INTERRUPT_GLOBAL_INTERRUPT_ENABLE() ;
          INTERRUPT_PERIPHERAL_INTERRUPT_ENABLE()   ;
#endif
          break ;
          default : 
          ret = E_NOT_OK ;
          break ;
       }
        
        
        
    }
    
    return ret ;
}
/**
 * 
 * @param int_obj
 * @return 
 */
static Std_ReturnType Interrupt_INTX_DISBLE(const Interrupt_INTX_t*int_obj) {
    Std_ReturnType ret =E_OK ;
    if (NULL==int_obj){
        
        ret=E_NOT_OK ;
        
    }
    else {
         switch (int_obj->source) {
          case interrupt_INT0 : 
          EXT_INT0_INTERRUPT_disable() ;
          break ;
          case interrupt_INT1 : 
          EXT_INT1_INTERRUPT_disable() ;
          break ;
          case interrupt_INT2 : 
          EXT_INT2_INTERRUPT_disable() ;
          break ;
          default : 
          ret = E_NOT_OK ;
          break ;
       }
        
    }
    
    return ret ;
    
}
/**
 * 
 * @param int_obj
 * @return 
 */
static Std_ReturnType Interrupt_INTX_EDGE_INIT(const Interrupt_INTX_t*int_obj) {
    Std_ReturnType ret =E_OK ;
    if (NULL==int_obj){
        
        ret=E_NOT_OK ;
        
    }
    else {
        
         switch (int_obj->source) {
          case interrupt_INT0 : 
            if (interrupt_INTX_falling_edge==int_obj->edge){ EXT_INT0_SET_FALLING_EDGE() ;} 
            else if (interrupt_INTX_rising_edge==int_obj->edge){EXT_INT0_SET_RISING_EDGE();}
            else {ret=E_NOT_OK ;}
          break ;
          
          case interrupt_INT1 : 
            if (interrupt_INTX_falling_edge==int_obj->edge){ EXT_INT1_SET_FALLING_EDGE() ;} 
            else if (interrupt_INTX_rising_edge==int_obj->edge){EXT_INT1_SET_RISING_EDGE();}
            else {ret=E_NOT_OK ;}
          break ;
          case interrupt_INT2 : 
            if (interrupt_INTX_falling_edge==int_obj->edge){ EXT_INT2_SET_FALLING_EDGE() ;} 
            else if (interrupt_INTX_rising_edge==int_obj->edge){EXT_INT2_SET_RISING_EDGE();}
            else {ret=E_NOT_OK ;}
          break ;
          default : 
          ret = E_NOT_OK ;
          break ;
       }
        
        
        
        
        
        
    }
    
    return ret ;
    
}
/**
 * 
 * @param int_obj
 * @return 
 */
#if (INRERRUPT_PRIORITY_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)
static Std_ReturnType Interrupt_INTX_PRIORITY_INIT(const Interrupt_INTX_t*int_obj) {
    Std_ReturnType ret =E_OK ;
    if (NULL==int_obj){
        
        ret=E_NOT_OK ;
        
    }
    else {
        switch (int_obj->source) {
  
          case interrupt_INT1 : 
            if (interrupt_low_prioity==int_obj->priorty){EXT_INT1_SET_low_PRIORITY() ;} 
            else if (interrupt_HIGH_prioity==int_obj->priorty){EXT_INT1_SET_HIGH_PRIORITY();}
            else {ret=E_NOT_OK ;}
          break ;
          case interrupt_INT2 : 
            if (interrupt_low_prioity==int_obj->priorty){EXT_INT2_SET_low_PRIORITY() ;} 
            else if (interrupt_HIGH_prioity==int_obj->priorty){EXT_INT2_SET_HIGH_PRIORITY();}
            else {ret=E_NOT_OK ;}
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
 * 
 * @param int_obj
 * @return 
 */
static Std_ReturnType Interrupt_INTX_PIN_INIT(const Interrupt_INTX_t*int_obj) {
    Std_ReturnType ret =E_OK ;
    if (NULL==int_obj){
        
        ret=E_NOT_OK ;
        
    }
    else {
        
        ret= gpio_pin_direction_initalize(&(int_obj->mcu_pin)) ;
        
        
        
    }
    
    return ret ;
    
}
/**
 * 
 * @param int_obj
 * @return 
 */
static Std_ReturnType Interrupt_INTX_CLEAR_FLAG(const Interrupt_INTX_t*int_obj) {
    Std_ReturnType ret =E_OK ;
    if (NULL==int_obj){
        
        ret=E_NOT_OK ;
        
    }
    else {
        
    switch (int_obj->source) {
          case interrupt_INT0 : 
          EXT_INT0_INTERRUPT_CLEAR_FLAG() ;
          break ;
          case interrupt_INT1 : 
          EXT_INT1_INTERRUPT_CLEAR_FLAG() ;
          break ;
          case interrupt_INT2 : 
          EXT_INT2_INTERRUPT_CLEAR_FLAG() ;
          break ;
          default : 
          ret = E_NOT_OK ;
          break ;
       }
        
    }
    
    return ret ;
    
    
}
/**
 * 
 * @param int_obj
 * @return 
 */
static Std_ReturnType Interrupt_INTX_SET_INTERRUPT_HANDLER(const Interrupt_INTX_t*int_obj) {
    Std_ReturnType ret =E_OK ;
    if ((NULL==int_obj)||(NULL==(int_obj->EXT_INTERRUPT_HANDLER))){
        
        ret=E_NOT_OK ;
        
    }
    else {
        
    switch (int_obj->source) {
          case interrupt_INT0 : 
          INT0_INTERRUPT_HANDLER =(int_obj->EXT_INTERRUPT_HANDLER);
          break ;
          case interrupt_INT1 : 
          INT1_INTERRUPT_HANDLER =(int_obj->EXT_INTERRUPT_HANDLER);
          break ;
          case interrupt_INT2 : 
          INT2_INTERRUPT_HANDLER =(int_obj->EXT_INTERRUPT_HANDLER);
          break ;
          default : 
          ret = E_NOT_OK ;
          break ;
       }
        
    }
    
    return ret ;
    
    
}
/**
 * 
 * @param int_obj
 * @return 
 */
static Std_ReturnType Interrupt_RBX_ENABLE(const Interrupt_RBX_t*int_obj) {
    
     
    Std_ReturnType ret =E_OK ;
    if (NULL==int_obj){
        
        ret=E_NOT_OK ;
        
    }
    else {
        
        EXT_RBX_INTERRUPT_ENABLE()   ;
        #if (INRERRUPT_PRIORITY_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)
          INTERRUPT_PRIORITY_LEVELS_ENABLE()     ;
           if (interrupt_low_prioity==int_obj->priorty)
           {INTERRUPT_GLOBAL_INTERRUPT_ENABLE_LOW() ;} 
           else if (interrupt_HIGH_prioity==int_obj->priorty)
           {INTERRUPT_GLOBAL_INTERRUPT_ENABLE_HIGH() ;}
           else {ret=E_NOT_OK ;}
        #else
          
          INTERRUPT_GLOBAL_INTERRUPT_ENABLE() ;
          INTERRUPT_PERIPHERAL_INTERRUPT_ENABLE()   ;
        #endif
        
    }
    
    return ret ;
    
}
/**
 * 
 * @param int_obj
 * @return 
 */
static Std_ReturnType Interrupt_RBX_DISBLE(const Interrupt_RBX_t*int_obj) {
    Std_ReturnType ret =E_OK ;
    if (NULL==int_obj){
        
        ret=E_NOT_OK ;
        
    }
    else {
        EXT_RBX_INTERRUPT_DISABLE()  ;
        
        
    }
    
    return ret ;
    
}
/**
 * 
 * @param int_obj
 * @return 
 */
static Std_ReturnType Interrupt_RBX_CLEAR_FLAG(const Interrupt_RBX_t*int_obj) {
    Std_ReturnType ret =E_OK ;
    if (NULL==int_obj){
        
        ret=E_NOT_OK ;
        
    }
    else {
        EXT_RBX_INTERRUPT_CLEAR_FLAG()    ;
        
        
    }
    
    return ret ;
    
}
/**
 * 
 * @param int_obj
 * @return 
 */
#if (INRERRUPT_PRIORITY_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)
static Std_ReturnType Interrupt_RBX_PRIORITY_INIT(const Interrupt_RBX_t*int_obj) {
    Std_ReturnType ret =E_OK ;
    if (NULL==int_obj){
        
        ret=E_NOT_OK ;
        
    }
    else {
        if (interrupt_low_prioity==int_obj->priorty){
            
             EXT_RBX_INTERRUPT_SET_LOW_PRIORITY()    ;
        }
        else if (interrupt_HIGH_prioity==int_obj->priorty){
            EXT_RBX_INTERRUPT_SET_HIGH_PRIORITY()     ;
        }
        else {  ret=E_NOT_OK ; }
                      
        
    }
    
    return ret ;
    
}
#endif 
/**
 * 
 * @param int_obj
 * @return 
 */
static Std_ReturnType Interrupt_RBX_PIN_INIT(const Interrupt_RBX_t*int_obj) {
    Std_ReturnType ret =E_OK ;
    if (NULL==int_obj){
        
        ret=E_NOT_OK ;
        
    }
    else {
       
        ret= gpio_pin_direction_initalize(&(int_obj->mcu_pin)) ;
        
        
    }
    
    return ret ;
    
}
static Std_ReturnType Interrupt_RBX_SET_INTERRUPT_HANDLER(const Interrupt_RBX_t*int_obj) {
    Std_ReturnType ret =E_OK ;
    if (NULL==int_obj){
        
        ret=E_NOT_OK ;
        
    }
    else {
       switch (int_obj->mcu_pin.pin) {
          case PIN4 : 
          RB4_INTERRUPT_HANDLER_HIGH =(int_obj->EXT_INTERRUPT_HANDLER_HIGH) ;
          RB4_INTERRUPT_HANDLER_LOW =(int_obj->EXT_INTERRUPT_HANDLER_LOW) ;
          break ;
          case PIN5 : 
          RB5_INTERRUPT_HANDLER_HIGH =(int_obj->EXT_INTERRUPT_HANDLER_HIGH) ;
          RB5_INTERRUPT_HANDLER_LOW =(int_obj->EXT_INTERRUPT_HANDLER_LOW) ;
          break ;
          case PIN6 : 
          RB6_INTERRUPT_HANDLER_HIGH =(int_obj->EXT_INTERRUPT_HANDLER_HIGH) ;
          RB6_INTERRUPT_HANDLER_LOW =(int_obj->EXT_INTERRUPT_HANDLER_LOW) ;
          break ;
          case PIN7 : 
          RB7_INTERRUPT_HANDLER_HIGH =(int_obj->EXT_INTERRUPT_HANDLER_HIGH) ;
          RB7_INTERRUPT_HANDLER_LOW =(int_obj->EXT_INTERRUPT_HANDLER_LOW) ;
          break ;
          default : 
          ret = E_NOT_OK ;
          break ;
       }
        
        
        
        
    }
    
    return ret ;
    
    
}