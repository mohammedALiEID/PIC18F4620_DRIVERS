/* 
 * File:   MCAL_EEPROM.c
 * Author: sayr3
 *
 * Created on January 3, 2024, 2:19 PM
 */
/*section:***********includes*******************************/
#include "MCAL_EEPROM.h" 
/*section:*********functions definition*****************/
/**
 * 
 * @param address
 * @param READ_VALUE
 * @return 
 */
Std_ReturnType DATA_EEPROM_READ_BYTE(uint_16 address ,uint_8 * READ_VALUE ) {
    Std_ReturnType ret = E_OK ;
    
    if (NULL==READ_VALUE) {
        ret = E_NOT_OK ;
        
    }
    else {
        
                // Upper bits of Data Memory Address to write
                 EEADRH=(uint_8)((address>>8)&(0x3)) ;
    
                //Lower bits of Data Memory Address to write
                 EEADR =(uint_8)((address)&(0xFF)) ;
    
               // Point to DATA memory EPGD =0 
                 EECON1bits.EEPGD=Access_data_EEPROM_memory ;
    
                //Access EEPROM CFGS = 0 
                 EECON1bits.CFGS =Access_Flash_program_or_data_EEPROMm_emory ;
              //Set RD bit to begin READ
                EECON1bits.RD =Initiates_data_EEPROM_READ_cycle ;
                /*recommended in high frequency >40 MHZ  to use NOP instruction it no operation 
                instruction just for delay to ensure reading process is completed */
                
                NOP() ;
                NOP() ;

                // read data from  EEDATA
               * READ_VALUE = EEDATA ;
                
               
    }
    
    
    
    return ret ;
    
    
    
}
/**
 * 
 * @param address
 * @param VALUE
 * @return 
 */
Std_ReturnType DATA_EEPROM_WRITE_BYTE(uint_16 address ,uint_8 VALUE ){
    Std_ReturnType ret = E_OK ;
    uint_8 GLOPAL_interrupt_status = INTCONbits.GIE ;
    
    
                // Upper bits of Data Memory Address to write
                 EEADRH=(uint_8)((address>>8)&(0x3)) ;
    
                //Lower bits of Data Memory Address to write
                 EEADR =(uint_8)((address)&(0xFF)) ;
    
                //Data Memory Value to write
                 EEDATA =VALUE ;
    
                // Point to DATA memory EPGD =0 
                 EECON1bits.EEPGD=Access_data_EEPROM_memory ;
    
                //Access EEPROM CFGS = 0 
                 EECON1bits.CFGS =Access_Flash_program_or_data_EEPROMm_emory ;
     
                //Enable writes WREN =1 
                 EECON1bits.WREN = Allows_write_cycles_to_Flash_program_data_EEPROM ;
    
                //Disable Interrupts GIE =0 
               INTCONbits.GIE=(INTERRUPT_DISABLE) ;
     
                //Write 55h to EECON2 
                EECON2 = 0X55 ;
    
                //Write 0AAh to EECON2 
                EECON2 = 0X0AA;
    
                //Set WR bit to begin write 
                EECON1bits.WR =Initiates_data_EEPROM_erase_write_cycle ;
    
               //Enable Interrupts
               INTCONbits.GIE =GLOPAL_interrupt_status ;
    
               //Disable writes on write complete WREN = 0 
            
               while ( EECON1bits.WR){
             
             
               }
              EECON1bits.WREN = inhibit_write_cycles_to_Flash_program_data_EEPROM ;
            
            
     return ret ; 
    
}
