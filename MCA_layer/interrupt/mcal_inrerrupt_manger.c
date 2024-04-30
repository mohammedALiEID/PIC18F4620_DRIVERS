
/* 
 * File:   mcal_inrerrupt_manger.c
 * Author: sayr3
 *
 * Created on December 29, 2023, 11:42 AM
 */
/*section:***********includes*******************************/
#include "mcal_inrerrupt_manger.h"
/*section:***********global_variable*******************************/
  static volatile uint_8 RB4_flag =1 , RB5_flag = 1 , RB6_flag = 1 ,RB7_flag = 1 ;


/*section:*********functions definition*****************/

#if (INRERRUPT_PRIORITY_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE)
void __interrupt()INTERRUPT_MANGER_HIGH(void){
    if((INTERRUPT_ENABLE== (INTCON3bits.INT2IE))&&(INTERRUPT_CHECKED==(INTCON3bits.INT2IF))){
        
        INT2_ISR() ;
    }
    else{/*nothing*/}
    if((INTERRUPT_ENABLE== (INTCONbits.INT0IE))&&(INTERRUPT_CHECKED==(INTCONbits.INT0IF))){
        
        INT0_ISR() ;
    }
    else{/*nothing*/}
      if((INTERRUPT_ENABLE== (INTCONbits.RBIE))&&(INTERRUPT_CHECKED==(INTCONbits.RBIF))&&(PORTBbits.RB4==HIGH)&&(RB4_flag==1)){
        RB4_flag = 0 ;
        RB4_ISR_HIGH();
      
    }
    else{/*nothing*/}
   if((INTERRUPT_ENABLE== (INTCONbits.RBIE))&&(INTERRUPT_CHECKED==(INTCONbits.RBIF))&&(PORTBbits.RB4==LOW)&&(RB4_flag==0)){
        RB4_flag = 1 ;
        RB4_ISR_LOW() ;
      
    }
    else{/*nothing*/}
    
    if((INTERRUPT_ENABLE== (INTCONbits.RBIE))&&(INTERRUPT_CHECKED==(INTCONbits.RBIF))&&(PORTBbits.RB5==HIGH)&&(RB5_flag==1)){
        RB5_flag = 0 ;
       RB5_ISR_HIGH();
      
    }
    else{/*nothing*/}
   if((INTERRUPT_ENABLE== (INTCONbits.RBIE))&&(INTERRUPT_CHECKED==(INTCONbits.RBIF))&&(PORTBbits.RB5==LOW)&&(RB5_flag==0)){
        RB5_flag = 1 ;
        RB5_ISR_LOW() ;
      
    }
    else{/*nothing*/}
     if((INTERRUPT_ENABLE== (PIE1bits.CCP1IE))&&(INTERRUPT_CHECKED==(PIR1bits.CCP1IF))){
        
       CCP1_ISR() ;
    }
    else{/*nothing*/}
    
}
void __interrupt(low_priority)INTERRUPT_MANGER_LOW(void){
   if((INTERRUPT_ENABLE== (INTCON3bits.INT1IE))&&(INTERRUPT_CHECKED==(INTCON3bits.INT1IF))){
        
        INT1_ISR() ;
    }
    else{/*nothing*/}
    if((INTERRUPT_ENABLE== (INTCONbits.RBIE))&&(INTERRUPT_CHECKED==(INTCONbits.RBIF))&&(PORTBbits.RB6==HIGH)&&(RB6_flag==1)){
        RB6_flag = 0 ;
        RB6_ISR_HIGH();
      
    }
    else{/*nothing*/}
   if((INTERRUPT_ENABLE== (INTCONbits.RBIE))&&(INTERRUPT_CHECKED==(INTCONbits.RBIF))&&(PORTBbits.RB6==LOW)&&(RB6_flag==0)){
        RB6_flag = 1 ;
        RB6_ISR_LOW() ;
      
    }
    else{/*nothing*/}
    
    if((INTERRUPT_ENABLE== (INTCONbits.RBIE))&&(INTERRUPT_CHECKED==(INTCONbits.RBIF))&&(PORTBbits.RB7==HIGH)&&(RB7_flag==1)){
        RB7_flag = 0 ;
        RB7_ISR_HIGH();
      
    }
    else{/*nothing*/}
   if((INTERRUPT_ENABLE== (INTCONbits.RBIE))&&(INTERRUPT_CHECKED==(INTCONbits.RBIF))&&(PORTBbits.RB7==LOW)&&(RB7_flag==0)){
        RB7_flag = 1 ;
        RB7_ISR_LOW() ;
      
    }
    else{/*nothing*/}
    if((INTERRUPT_ENABLE== (PIE2bits.TMR3IE))&&(INTERRUPT_CHECKED==(PIR2bits.TMR3IF))){
        
       TIMER3_ISR() ;
    }
    
   
   
   
   
}
#else 
void __interrupt()INTERRUPT_MANGER(void){
    
    
    if((INTERRUPT_ENABLE== (INTCONbits.INT0IE))&&(INTERRUPT_CHECKED==(INTCONbits.INT0IF))){
        
        INT0_ISR() ;
    }
    else{/*nothing*/}
    if((INTERRUPT_ENABLE== (INTCON3bits.INT1IE))&&(INTERRUPT_CHECKED==(INTCON3bits.INT1IF))){
        
        INT1_ISR() ;
    }
    else{/*nothing*/}
    if((INTERRUPT_ENABLE== (INTCON3bits.INT2IE))&&(INTERRUPT_CHECKED==(INTCON3bits.INT2IF))){
        
        INT2_ISR() ;
    }
    else{/*nothing*/}
    if((INTERRUPT_ENABLE== (INTCONbits.RBIE))&&(INTERRUPT_CHECKED==(INTCONbits.RBIF))&&(PORTBbits.RB4==HIGH)&&(RB4_flag==1)){
        RB4_flag = 0 ;
        RB4_ISR_HIGH();
      
    }
    else{/*nothing*/}
   if((INTERRUPT_ENABLE== (INTCONbits.RBIE))&&(INTERRUPT_CHECKED==(INTCONbits.RBIF))&&(PORTBbits.RB4==LOW)&&(RB4_flag==0)){
        RB4_flag = 1 ;
        RB4_ISR_LOW() ;
      
    }
    else{/*nothing*/}
    
    if((INTERRUPT_ENABLE== (INTCONbits.RBIE))&&(INTERRUPT_CHECKED==(INTCONbits.RBIF))&&(PORTBbits.RB5==HIGH)&&(RB5_flag==1)){
        RB5_flag = 0 ;
        RB5_ISR_HIGH();
      
    }
    else{/*nothing*/}
   if((INTERRUPT_ENABLE== (INTCONbits.RBIE))&&(INTERRUPT_CHECKED==(INTCONbits.RBIF))&&(PORTBbits.RB5==LOW)&&(RB5_flag==0)){
        RB5_flag = 1 ;
        RB5_ISR_LOW() ;
      
    }
    else{/*nothing*/}
    
    if((INTERRUPT_ENABLE== (INTCONbits.RBIE))&&(INTERRUPT_CHECKED==(INTCONbits.RBIF))&&(PORTBbits.RB6==HIGH)&&(RB6_flag==1)){
        RB6_flag = 0 ;
        RB6_ISR_HIGH();
      
    }
    else{/*nothing*/}
   if((INTERRUPT_ENABLE== (INTCONbits.RBIE))&&(INTERRUPT_CHECKED==(INTCONbits.RBIF))&&(PORTBbits.RB6==LOW)&&(RB6_flag==0)){
        RB6_flag = 1 ;
        RB6_ISR_LOW() ;
      
    }
    else{/*nothing*/}
    
    if((INTERRUPT_ENABLE== (INTCONbits.RBIE))&&(INTERRUPT_CHECKED==(INTCONbits.RBIF))&&(PORTBbits.RB7==HIGH)&&(RB7_flag==1)){
        RB7_flag = 0 ;
        RB7_ISR_HIGH();
      
    }
    else{/*nothing*/}
   if((INTERRUPT_ENABLE== (INTCONbits.RBIE))&&(INTERRUPT_CHECKED==(INTCONbits.RBIF))&&(PORTBbits.RB7==LOW)&&(RB7_flag==0)){
        RB7_flag = 1 ;
        RB7_ISR_LOW() ;
      
    }
    else{/*nothing*/}
    if((INTERRUPT_ENABLE== (PIE1bits.ADIE))&&(INTERRUPT_CHECKED==(PIR1bits.ADIF))){
        
        ADC_ISR() ;
    }
    else{/*nothing*/}
    if((INTERRUPT_ENABLE== (INTCONbits.TMR0IE))&&(INTERRUPT_CHECKED==(INTCONbits.TMR0IF))){
        
       TIMER0_ISR() ;
    }
    else{/*nothing*/}
    if((INTERRUPT_ENABLE== (PIE1bits.TMR1IE))&&(INTERRUPT_CHECKED==(PIR1bits.TMR1IF))){
        
       TIMER1_ISR() ;
    }
    else{/*nothing*/}
    if((INTERRUPT_ENABLE== (PIE1bits.TMR2IE))&&(INTERRUPT_CHECKED==(PIE1bits.TMR2IE))){
        
       TIMER2_ISR() ;
    }
    else{/*nothing*/}
     if((INTERRUPT_ENABLE== (PIE2bits.TMR3IE))&&(INTERRUPT_CHECKED==(PIR2bits.TMR3IF))){
        
       TIMER3_ISR() ;
    }
    else{/*nothing*/}
     if((INTERRUPT_ENABLE== (PIE1bits.CCP1IE))&&(INTERRUPT_CHECKED==(PIR1bits.CCP1IF))){
        
       CCP1_ISR() ;
    }
    else{/*nothing*/}
    if((INTERRUPT_ENABLE== (PIE2bits.CCP2IE))&&(INTERRUPT_CHECKED==(PIR2bits.CCP2IF))){
        
       CCP2_ISR() ;
    }
    else{/*nothing*/}
    
    if((INTERRUPT_ENABLE== (PIE1bits.TXIE))&&(INTERRUPT_CHECKED==(PIR1bits.TXIF))){
        
       USART_ASYN_TX_ISR() ;
    }
    else{/*nothing*/}
     if((INTERRUPT_ENABLE== (PIE1bits.RCIE))&&(INTERRUPT_CHECKED==(PIR1bits.RCIF))){
        
       USART_ASYN_RX_ISR() ;
    }
    else{/*nothing*/}
}

#endif