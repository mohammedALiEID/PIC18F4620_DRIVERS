/* 
 * File:   MCAL_EEPROM.h
 * Author: sayr3
 *
 * Created on January 3, 2024, 2:19 PM
 */

#ifndef MCAL_EEPROM_H
#define	MCAL_EEPROM_H

/*section:*********includes*******************************/
#include"MCAL_EEPROM_confg.h"
#include "../interrupt/mcal_interrupt_confg.h"

/*section:*********data types ***************************/


/*section:*********macro declaration*********************/
/**EEPGD: Flash Program or Data EEPROM Memory Select bit*/
#define Access_Flash_program_memory                  0x1
#define Access_data_EEPROM_memory                    0x0
/**CFGS: Flash Program/Data EEPROM or Configuration Select bit*/

#define Access_Configuration_registers               0x1
#define Access_Flash_program_or_data_EEPROMm_emory   0x0

/**WREN: Flash Program/Data EEPROM Write Enable bit*/
#define Allows_write_cycles_to_Flash_program_data_EEPROM  0x1
#define inhibit_write_cycles_to_Flash_program_data_EEPROM 0x0

/**WR: Write Control bit*/
#define Initiates_data_EEPROM_erase_write_cycle  0x1
#define Write_cycle_to_the_EEPROM_is_complete    0x0

/**RD: READ Control bit*/
#define Initiates_data_EEPROM_READ_cycle        0x1
#define READ_cycle_to_the_EEPROM_is_complete    0x0





/*section:*********macro functions declaration **********/


/*section:*********functions declaration*****************/
Std_ReturnType DATA_EEPROM_READ_BYTE(uint_16 address ,uint_8 * READ_VALUE ) ;
Std_ReturnType DATA_EEPROM_WRITE_BYTE(uint_16 address ,uint_8 VALUE ) ;






#endif	/* MCAL_EEPROM_H */

