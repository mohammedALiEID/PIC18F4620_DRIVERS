/* 
 * File:   my_register_definition.h
 * Author: mohammed_ali
 *
 * Created on December 3, 2023, 4:59 PM
 */

#ifndef MY_REGISTE_DEFINITION_H
#define	MY_REGISTE_DEFINITION_H



#define LATC_ADD (0XF8B)
#define PORTC_ADD (0XF82)
#define TRISC_ADD (0XF94)
#define SSPCON1_ADD  (0xFC6)  

#define PLATFORM_TYPE 8


#if (PLATFORM_TYPE == 8)
#define GPIO_REG(_x) (*((volatile uint8 *)(_x))) 

#elif (PLATFORM_TYPE == 16)

#define GPIO_REG(_x) (*((volatile uint16*)(_x)))

#elif   (PLATFORM_TYPE == 32)

#define GPIO_REG(_x) (*((volatile uint32*)(_x)))
#else 
#error 

#endif


#define MO_TRISC  (GPIO_REG(TRISC_ADD))
#define MO_LATC  (GPIO_REG(LATC_ADD))
#define MO_PORTC  (GPIO_REG(PORTC_ADD))

  
#define mo_set_bit(reg ,bit_pos)  (reg|=(1<<bit_pos))
#define mo_clear_bit(reg ,bit_pos)  (reg&=~(1<<bit_pos))
#define mo_toggl_bit(reg ,bit_pos)  (reg^=(1<<bit_pos))
 
 
typedef union {
   struct {
       unsigned trisc0 :1 ;
       unsigned trisc1 :1 ;  
       unsigned trisc2 :1 ;
       unsigned trisc3 :1 ;
       unsigned trisc4 :1 ;
       unsigned trisc5 :1 ;
       unsigned trisc6 :1 ;
       unsigned trisc7 :1 ;
       
       
   }; 
   uint_8 trisc_reg ;   
    
    
}mo_trisc_t;

typedef union{
   struct {
       unsigned latc0 :1 ;
       unsigned latc1 :1 ;  
       unsigned latc2 :1 ;
       unsigned latc3 :1 ;
       unsigned latc4 :1 ;
       unsigned latc5 :1 ;
       unsigned latc6 :1 ;
       unsigned latc7 :1 ;
       
   }; 
   uint_8 latc_reg ;   
    
    
}mo_latc_t;

typedef union {
   struct {
       unsigned portc0 :1 ;
       unsigned portc1 :1 ;  
       unsigned portc2 :1 ;
       unsigned portc3 :1 ;
       unsigned portc4 :1 ;
       unsigned portc5 :1 ;
       unsigned portc6 :1 ;
       unsigned portc7 :1 ;
       
   }; 
   uint_8 portc_reg ;   
    
    
}mo_portc_t;

typedef union{
   struct {
      uint_8 SSPMX :4 ;
      uint_8 CKP   :1 ;  
      uint_8 SSPEN  :1 ;
      uint_8 SSPOV :1 ;
      uint_8 WCOL  :1 ;
      
   }; 
   uint_8 SSPCON1_reg ;   
    
    
}SSPCON1_t;

typedef enum {
  SPI_Master_mode_clock_FOSC_4  ,
  SPI_Master_mode_clock_FOSC_16 ,
  SPI_Mr_mode_clock_TMR2_output_2 ,
  SPI_MastePI_Master_mode_clock_FOSC_64 ,
  SPI_Mr_mode_clock_SCK_pin_SS_pin_control_enabled ,
  SPI_Master_mode_clock_SCK_pin_SS_pin_control_diabled,
}SSPMX_t;
  SSPMX_t  SSPMX_value ; 
   

#define m_trisc   (( volatile mo_trisc_t*)(TRISC_ADD))
#define m_latc   (( volatile mo_latc_t*)(LATC_ADD) )
#define m_portc   (( volatile mo_portc_t*)(PORTC_ADD)) 
#define m_SSPCON1 (*(( volatile SSPCON1_t*)(SSPCON1_ADD)))




#endif	/* MY_REGISTE_DEFINITION_H */


        