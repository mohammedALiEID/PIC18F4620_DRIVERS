#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/my_project.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/my_project.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=ECUA_layer/button/ecual_button.c ECUA_layer/character_lcd/cha_lcd.c ECUA_layer/DC_motor_driver/ecual_dc_motor_driver.c ECUA_layer/keypad/ecual_keypad.c ECUA_layer/LED/ECUAL_led.c ECUA_layer/relay/ecual_relay.c ECUA_layer/seven_segment/ecual_seven_segment.c ECUA_layer/ecual_layer_initalization.c MCA_layer/ADC/MCAL_ADC.c MCA_layer/CCP1/Mcal_CCP1.c MCA_layer/device_configuration/device_configure.c MCA_layer/EEPROM/MCAL_EEPROM.c MCA_layer/GPIO/mcal_GPIO.c MCA_layer/interrupt/mcal_internal_interrupt.c MCA_layer/interrupt/mcal_external_inrerrupt.c MCA_layer/interrupt/mcal_inrerrupt_manger.c MCA_layer/TIMER0/MCAL_TIMER0.c MCA_layer/TIMER1/MCAL_TIMER1.c MCA_layer/TIMER2/MCAL_TIMER2.c MCA_layer/TIMER3/MCAL_TIMER3.c MCA_layer/USART/MCAL_USART.c application_main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ECUA_layer/button/ecual_button.p1 ${OBJECTDIR}/ECUA_layer/character_lcd/cha_lcd.p1 ${OBJECTDIR}/ECUA_layer/DC_motor_driver/ecual_dc_motor_driver.p1 ${OBJECTDIR}/ECUA_layer/keypad/ecual_keypad.p1 ${OBJECTDIR}/ECUA_layer/LED/ECUAL_led.p1 ${OBJECTDIR}/ECUA_layer/relay/ecual_relay.p1 ${OBJECTDIR}/ECUA_layer/seven_segment/ecual_seven_segment.p1 ${OBJECTDIR}/ECUA_layer/ecual_layer_initalization.p1 ${OBJECTDIR}/MCA_layer/ADC/MCAL_ADC.p1 ${OBJECTDIR}/MCA_layer/CCP1/Mcal_CCP1.p1 ${OBJECTDIR}/MCA_layer/device_configuration/device_configure.p1 ${OBJECTDIR}/MCA_layer/EEPROM/MCAL_EEPROM.p1 ${OBJECTDIR}/MCA_layer/GPIO/mcal_GPIO.p1 ${OBJECTDIR}/MCA_layer/interrupt/mcal_internal_interrupt.p1 ${OBJECTDIR}/MCA_layer/interrupt/mcal_external_inrerrupt.p1 ${OBJECTDIR}/MCA_layer/interrupt/mcal_inrerrupt_manger.p1 ${OBJECTDIR}/MCA_layer/TIMER0/MCAL_TIMER0.p1 ${OBJECTDIR}/MCA_layer/TIMER1/MCAL_TIMER1.p1 ${OBJECTDIR}/MCA_layer/TIMER2/MCAL_TIMER2.p1 ${OBJECTDIR}/MCA_layer/TIMER3/MCAL_TIMER3.p1 ${OBJECTDIR}/MCA_layer/USART/MCAL_USART.p1 ${OBJECTDIR}/application_main.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/ECUA_layer/button/ecual_button.p1.d ${OBJECTDIR}/ECUA_layer/character_lcd/cha_lcd.p1.d ${OBJECTDIR}/ECUA_layer/DC_motor_driver/ecual_dc_motor_driver.p1.d ${OBJECTDIR}/ECUA_layer/keypad/ecual_keypad.p1.d ${OBJECTDIR}/ECUA_layer/LED/ECUAL_led.p1.d ${OBJECTDIR}/ECUA_layer/relay/ecual_relay.p1.d ${OBJECTDIR}/ECUA_layer/seven_segment/ecual_seven_segment.p1.d ${OBJECTDIR}/ECUA_layer/ecual_layer_initalization.p1.d ${OBJECTDIR}/MCA_layer/ADC/MCAL_ADC.p1.d ${OBJECTDIR}/MCA_layer/CCP1/Mcal_CCP1.p1.d ${OBJECTDIR}/MCA_layer/device_configuration/device_configure.p1.d ${OBJECTDIR}/MCA_layer/EEPROM/MCAL_EEPROM.p1.d ${OBJECTDIR}/MCA_layer/GPIO/mcal_GPIO.p1.d ${OBJECTDIR}/MCA_layer/interrupt/mcal_internal_interrupt.p1.d ${OBJECTDIR}/MCA_layer/interrupt/mcal_external_inrerrupt.p1.d ${OBJECTDIR}/MCA_layer/interrupt/mcal_inrerrupt_manger.p1.d ${OBJECTDIR}/MCA_layer/TIMER0/MCAL_TIMER0.p1.d ${OBJECTDIR}/MCA_layer/TIMER1/MCAL_TIMER1.p1.d ${OBJECTDIR}/MCA_layer/TIMER2/MCAL_TIMER2.p1.d ${OBJECTDIR}/MCA_layer/TIMER3/MCAL_TIMER3.p1.d ${OBJECTDIR}/MCA_layer/USART/MCAL_USART.p1.d ${OBJECTDIR}/application_main.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ECUA_layer/button/ecual_button.p1 ${OBJECTDIR}/ECUA_layer/character_lcd/cha_lcd.p1 ${OBJECTDIR}/ECUA_layer/DC_motor_driver/ecual_dc_motor_driver.p1 ${OBJECTDIR}/ECUA_layer/keypad/ecual_keypad.p1 ${OBJECTDIR}/ECUA_layer/LED/ECUAL_led.p1 ${OBJECTDIR}/ECUA_layer/relay/ecual_relay.p1 ${OBJECTDIR}/ECUA_layer/seven_segment/ecual_seven_segment.p1 ${OBJECTDIR}/ECUA_layer/ecual_layer_initalization.p1 ${OBJECTDIR}/MCA_layer/ADC/MCAL_ADC.p1 ${OBJECTDIR}/MCA_layer/CCP1/Mcal_CCP1.p1 ${OBJECTDIR}/MCA_layer/device_configuration/device_configure.p1 ${OBJECTDIR}/MCA_layer/EEPROM/MCAL_EEPROM.p1 ${OBJECTDIR}/MCA_layer/GPIO/mcal_GPIO.p1 ${OBJECTDIR}/MCA_layer/interrupt/mcal_internal_interrupt.p1 ${OBJECTDIR}/MCA_layer/interrupt/mcal_external_inrerrupt.p1 ${OBJECTDIR}/MCA_layer/interrupt/mcal_inrerrupt_manger.p1 ${OBJECTDIR}/MCA_layer/TIMER0/MCAL_TIMER0.p1 ${OBJECTDIR}/MCA_layer/TIMER1/MCAL_TIMER1.p1 ${OBJECTDIR}/MCA_layer/TIMER2/MCAL_TIMER2.p1 ${OBJECTDIR}/MCA_layer/TIMER3/MCAL_TIMER3.p1 ${OBJECTDIR}/MCA_layer/USART/MCAL_USART.p1 ${OBJECTDIR}/application_main.p1

# Source Files
SOURCEFILES=ECUA_layer/button/ecual_button.c ECUA_layer/character_lcd/cha_lcd.c ECUA_layer/DC_motor_driver/ecual_dc_motor_driver.c ECUA_layer/keypad/ecual_keypad.c ECUA_layer/LED/ECUAL_led.c ECUA_layer/relay/ecual_relay.c ECUA_layer/seven_segment/ecual_seven_segment.c ECUA_layer/ecual_layer_initalization.c MCA_layer/ADC/MCAL_ADC.c MCA_layer/CCP1/Mcal_CCP1.c MCA_layer/device_configuration/device_configure.c MCA_layer/EEPROM/MCAL_EEPROM.c MCA_layer/GPIO/mcal_GPIO.c MCA_layer/interrupt/mcal_internal_interrupt.c MCA_layer/interrupt/mcal_external_inrerrupt.c MCA_layer/interrupt/mcal_inrerrupt_manger.c MCA_layer/TIMER0/MCAL_TIMER0.c MCA_layer/TIMER1/MCAL_TIMER1.c MCA_layer/TIMER2/MCAL_TIMER2.c MCA_layer/TIMER3/MCAL_TIMER3.c MCA_layer/USART/MCAL_USART.c application_main.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/my_project.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4620
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/ECUA_layer/button/ecual_button.p1: ECUA_layer/button/ecual_button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUA_layer/button" 
	@${RM} ${OBJECTDIR}/ECUA_layer/button/ecual_button.p1.d 
	@${RM} ${OBJECTDIR}/ECUA_layer/button/ecual_button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUA_layer/button/ecual_button.p1 ECUA_layer/button/ecual_button.c 
	@-${MV} ${OBJECTDIR}/ECUA_layer/button/ecual_button.d ${OBJECTDIR}/ECUA_layer/button/ecual_button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUA_layer/button/ecual_button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUA_layer/character_lcd/cha_lcd.p1: ECUA_layer/character_lcd/cha_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUA_layer/character_lcd" 
	@${RM} ${OBJECTDIR}/ECUA_layer/character_lcd/cha_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECUA_layer/character_lcd/cha_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUA_layer/character_lcd/cha_lcd.p1 ECUA_layer/character_lcd/cha_lcd.c 
	@-${MV} ${OBJECTDIR}/ECUA_layer/character_lcd/cha_lcd.d ${OBJECTDIR}/ECUA_layer/character_lcd/cha_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUA_layer/character_lcd/cha_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUA_layer/DC_motor_driver/ecual_dc_motor_driver.p1: ECUA_layer/DC_motor_driver/ecual_dc_motor_driver.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUA_layer/DC_motor_driver" 
	@${RM} ${OBJECTDIR}/ECUA_layer/DC_motor_driver/ecual_dc_motor_driver.p1.d 
	@${RM} ${OBJECTDIR}/ECUA_layer/DC_motor_driver/ecual_dc_motor_driver.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUA_layer/DC_motor_driver/ecual_dc_motor_driver.p1 ECUA_layer/DC_motor_driver/ecual_dc_motor_driver.c 
	@-${MV} ${OBJECTDIR}/ECUA_layer/DC_motor_driver/ecual_dc_motor_driver.d ${OBJECTDIR}/ECUA_layer/DC_motor_driver/ecual_dc_motor_driver.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUA_layer/DC_motor_driver/ecual_dc_motor_driver.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUA_layer/keypad/ecual_keypad.p1: ECUA_layer/keypad/ecual_keypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUA_layer/keypad" 
	@${RM} ${OBJECTDIR}/ECUA_layer/keypad/ecual_keypad.p1.d 
	@${RM} ${OBJECTDIR}/ECUA_layer/keypad/ecual_keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUA_layer/keypad/ecual_keypad.p1 ECUA_layer/keypad/ecual_keypad.c 
	@-${MV} ${OBJECTDIR}/ECUA_layer/keypad/ecual_keypad.d ${OBJECTDIR}/ECUA_layer/keypad/ecual_keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUA_layer/keypad/ecual_keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUA_layer/LED/ECUAL_led.p1: ECUA_layer/LED/ECUAL_led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUA_layer/LED" 
	@${RM} ${OBJECTDIR}/ECUA_layer/LED/ECUAL_led.p1.d 
	@${RM} ${OBJECTDIR}/ECUA_layer/LED/ECUAL_led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUA_layer/LED/ECUAL_led.p1 ECUA_layer/LED/ECUAL_led.c 
	@-${MV} ${OBJECTDIR}/ECUA_layer/LED/ECUAL_led.d ${OBJECTDIR}/ECUA_layer/LED/ECUAL_led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUA_layer/LED/ECUAL_led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUA_layer/relay/ecual_relay.p1: ECUA_layer/relay/ecual_relay.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUA_layer/relay" 
	@${RM} ${OBJECTDIR}/ECUA_layer/relay/ecual_relay.p1.d 
	@${RM} ${OBJECTDIR}/ECUA_layer/relay/ecual_relay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUA_layer/relay/ecual_relay.p1 ECUA_layer/relay/ecual_relay.c 
	@-${MV} ${OBJECTDIR}/ECUA_layer/relay/ecual_relay.d ${OBJECTDIR}/ECUA_layer/relay/ecual_relay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUA_layer/relay/ecual_relay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUA_layer/seven_segment/ecual_seven_segment.p1: ECUA_layer/seven_segment/ecual_seven_segment.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUA_layer/seven_segment" 
	@${RM} ${OBJECTDIR}/ECUA_layer/seven_segment/ecual_seven_segment.p1.d 
	@${RM} ${OBJECTDIR}/ECUA_layer/seven_segment/ecual_seven_segment.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUA_layer/seven_segment/ecual_seven_segment.p1 ECUA_layer/seven_segment/ecual_seven_segment.c 
	@-${MV} ${OBJECTDIR}/ECUA_layer/seven_segment/ecual_seven_segment.d ${OBJECTDIR}/ECUA_layer/seven_segment/ecual_seven_segment.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUA_layer/seven_segment/ecual_seven_segment.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUA_layer/ecual_layer_initalization.p1: ECUA_layer/ecual_layer_initalization.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUA_layer" 
	@${RM} ${OBJECTDIR}/ECUA_layer/ecual_layer_initalization.p1.d 
	@${RM} ${OBJECTDIR}/ECUA_layer/ecual_layer_initalization.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUA_layer/ecual_layer_initalization.p1 ECUA_layer/ecual_layer_initalization.c 
	@-${MV} ${OBJECTDIR}/ECUA_layer/ecual_layer_initalization.d ${OBJECTDIR}/ECUA_layer/ecual_layer_initalization.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUA_layer/ecual_layer_initalization.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_layer/ADC/MCAL_ADC.p1: MCA_layer/ADC/MCAL_ADC.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_layer/ADC" 
	@${RM} ${OBJECTDIR}/MCA_layer/ADC/MCAL_ADC.p1.d 
	@${RM} ${OBJECTDIR}/MCA_layer/ADC/MCAL_ADC.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_layer/ADC/MCAL_ADC.p1 MCA_layer/ADC/MCAL_ADC.c 
	@-${MV} ${OBJECTDIR}/MCA_layer/ADC/MCAL_ADC.d ${OBJECTDIR}/MCA_layer/ADC/MCAL_ADC.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_layer/ADC/MCAL_ADC.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_layer/CCP1/Mcal_CCP1.p1: MCA_layer/CCP1/Mcal_CCP1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_layer/CCP1" 
	@${RM} ${OBJECTDIR}/MCA_layer/CCP1/Mcal_CCP1.p1.d 
	@${RM} ${OBJECTDIR}/MCA_layer/CCP1/Mcal_CCP1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_layer/CCP1/Mcal_CCP1.p1 MCA_layer/CCP1/Mcal_CCP1.c 
	@-${MV} ${OBJECTDIR}/MCA_layer/CCP1/Mcal_CCP1.d ${OBJECTDIR}/MCA_layer/CCP1/Mcal_CCP1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_layer/CCP1/Mcal_CCP1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_layer/device_configuration/device_configure.p1: MCA_layer/device_configuration/device_configure.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_layer/device_configuration" 
	@${RM} ${OBJECTDIR}/MCA_layer/device_configuration/device_configure.p1.d 
	@${RM} ${OBJECTDIR}/MCA_layer/device_configuration/device_configure.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_layer/device_configuration/device_configure.p1 MCA_layer/device_configuration/device_configure.c 
	@-${MV} ${OBJECTDIR}/MCA_layer/device_configuration/device_configure.d ${OBJECTDIR}/MCA_layer/device_configuration/device_configure.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_layer/device_configuration/device_configure.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_layer/EEPROM/MCAL_EEPROM.p1: MCA_layer/EEPROM/MCAL_EEPROM.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_layer/EEPROM" 
	@${RM} ${OBJECTDIR}/MCA_layer/EEPROM/MCAL_EEPROM.p1.d 
	@${RM} ${OBJECTDIR}/MCA_layer/EEPROM/MCAL_EEPROM.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_layer/EEPROM/MCAL_EEPROM.p1 MCA_layer/EEPROM/MCAL_EEPROM.c 
	@-${MV} ${OBJECTDIR}/MCA_layer/EEPROM/MCAL_EEPROM.d ${OBJECTDIR}/MCA_layer/EEPROM/MCAL_EEPROM.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_layer/EEPROM/MCAL_EEPROM.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_layer/GPIO/mcal_GPIO.p1: MCA_layer/GPIO/mcal_GPIO.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_layer/GPIO" 
	@${RM} ${OBJECTDIR}/MCA_layer/GPIO/mcal_GPIO.p1.d 
	@${RM} ${OBJECTDIR}/MCA_layer/GPIO/mcal_GPIO.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_layer/GPIO/mcal_GPIO.p1 MCA_layer/GPIO/mcal_GPIO.c 
	@-${MV} ${OBJECTDIR}/MCA_layer/GPIO/mcal_GPIO.d ${OBJECTDIR}/MCA_layer/GPIO/mcal_GPIO.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_layer/GPIO/mcal_GPIO.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_layer/interrupt/mcal_internal_interrupt.p1: MCA_layer/interrupt/mcal_internal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_layer/interrupt" 
	@${RM} ${OBJECTDIR}/MCA_layer/interrupt/mcal_internal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCA_layer/interrupt/mcal_internal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_layer/interrupt/mcal_internal_interrupt.p1 MCA_layer/interrupt/mcal_internal_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCA_layer/interrupt/mcal_internal_interrupt.d ${OBJECTDIR}/MCA_layer/interrupt/mcal_internal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_layer/interrupt/mcal_internal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_layer/interrupt/mcal_external_inrerrupt.p1: MCA_layer/interrupt/mcal_external_inrerrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_layer/interrupt" 
	@${RM} ${OBJECTDIR}/MCA_layer/interrupt/mcal_external_inrerrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCA_layer/interrupt/mcal_external_inrerrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_layer/interrupt/mcal_external_inrerrupt.p1 MCA_layer/interrupt/mcal_external_inrerrupt.c 
	@-${MV} ${OBJECTDIR}/MCA_layer/interrupt/mcal_external_inrerrupt.d ${OBJECTDIR}/MCA_layer/interrupt/mcal_external_inrerrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_layer/interrupt/mcal_external_inrerrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_layer/interrupt/mcal_inrerrupt_manger.p1: MCA_layer/interrupt/mcal_inrerrupt_manger.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_layer/interrupt" 
	@${RM} ${OBJECTDIR}/MCA_layer/interrupt/mcal_inrerrupt_manger.p1.d 
	@${RM} ${OBJECTDIR}/MCA_layer/interrupt/mcal_inrerrupt_manger.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_layer/interrupt/mcal_inrerrupt_manger.p1 MCA_layer/interrupt/mcal_inrerrupt_manger.c 
	@-${MV} ${OBJECTDIR}/MCA_layer/interrupt/mcal_inrerrupt_manger.d ${OBJECTDIR}/MCA_layer/interrupt/mcal_inrerrupt_manger.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_layer/interrupt/mcal_inrerrupt_manger.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_layer/TIMER0/MCAL_TIMER0.p1: MCA_layer/TIMER0/MCAL_TIMER0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_layer/TIMER0" 
	@${RM} ${OBJECTDIR}/MCA_layer/TIMER0/MCAL_TIMER0.p1.d 
	@${RM} ${OBJECTDIR}/MCA_layer/TIMER0/MCAL_TIMER0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_layer/TIMER0/MCAL_TIMER0.p1 MCA_layer/TIMER0/MCAL_TIMER0.c 
	@-${MV} ${OBJECTDIR}/MCA_layer/TIMER0/MCAL_TIMER0.d ${OBJECTDIR}/MCA_layer/TIMER0/MCAL_TIMER0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_layer/TIMER0/MCAL_TIMER0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_layer/TIMER1/MCAL_TIMER1.p1: MCA_layer/TIMER1/MCAL_TIMER1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_layer/TIMER1" 
	@${RM} ${OBJECTDIR}/MCA_layer/TIMER1/MCAL_TIMER1.p1.d 
	@${RM} ${OBJECTDIR}/MCA_layer/TIMER1/MCAL_TIMER1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_layer/TIMER1/MCAL_TIMER1.p1 MCA_layer/TIMER1/MCAL_TIMER1.c 
	@-${MV} ${OBJECTDIR}/MCA_layer/TIMER1/MCAL_TIMER1.d ${OBJECTDIR}/MCA_layer/TIMER1/MCAL_TIMER1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_layer/TIMER1/MCAL_TIMER1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_layer/TIMER2/MCAL_TIMER2.p1: MCA_layer/TIMER2/MCAL_TIMER2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_layer/TIMER2" 
	@${RM} ${OBJECTDIR}/MCA_layer/TIMER2/MCAL_TIMER2.p1.d 
	@${RM} ${OBJECTDIR}/MCA_layer/TIMER2/MCAL_TIMER2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_layer/TIMER2/MCAL_TIMER2.p1 MCA_layer/TIMER2/MCAL_TIMER2.c 
	@-${MV} ${OBJECTDIR}/MCA_layer/TIMER2/MCAL_TIMER2.d ${OBJECTDIR}/MCA_layer/TIMER2/MCAL_TIMER2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_layer/TIMER2/MCAL_TIMER2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_layer/TIMER3/MCAL_TIMER3.p1: MCA_layer/TIMER3/MCAL_TIMER3.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_layer/TIMER3" 
	@${RM} ${OBJECTDIR}/MCA_layer/TIMER3/MCAL_TIMER3.p1.d 
	@${RM} ${OBJECTDIR}/MCA_layer/TIMER3/MCAL_TIMER3.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_layer/TIMER3/MCAL_TIMER3.p1 MCA_layer/TIMER3/MCAL_TIMER3.c 
	@-${MV} ${OBJECTDIR}/MCA_layer/TIMER3/MCAL_TIMER3.d ${OBJECTDIR}/MCA_layer/TIMER3/MCAL_TIMER3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_layer/TIMER3/MCAL_TIMER3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_layer/USART/MCAL_USART.p1: MCA_layer/USART/MCAL_USART.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_layer/USART" 
	@${RM} ${OBJECTDIR}/MCA_layer/USART/MCAL_USART.p1.d 
	@${RM} ${OBJECTDIR}/MCA_layer/USART/MCAL_USART.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_layer/USART/MCAL_USART.p1 MCA_layer/USART/MCAL_USART.c 
	@-${MV} ${OBJECTDIR}/MCA_layer/USART/MCAL_USART.d ${OBJECTDIR}/MCA_layer/USART/MCAL_USART.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_layer/USART/MCAL_USART.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/application_main.p1: application_main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application_main.p1.d 
	@${RM} ${OBJECTDIR}/application_main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/application_main.p1 application_main.c 
	@-${MV} ${OBJECTDIR}/application_main.d ${OBJECTDIR}/application_main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/application_main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/ECUA_layer/button/ecual_button.p1: ECUA_layer/button/ecual_button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUA_layer/button" 
	@${RM} ${OBJECTDIR}/ECUA_layer/button/ecual_button.p1.d 
	@${RM} ${OBJECTDIR}/ECUA_layer/button/ecual_button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUA_layer/button/ecual_button.p1 ECUA_layer/button/ecual_button.c 
	@-${MV} ${OBJECTDIR}/ECUA_layer/button/ecual_button.d ${OBJECTDIR}/ECUA_layer/button/ecual_button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUA_layer/button/ecual_button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUA_layer/character_lcd/cha_lcd.p1: ECUA_layer/character_lcd/cha_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUA_layer/character_lcd" 
	@${RM} ${OBJECTDIR}/ECUA_layer/character_lcd/cha_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECUA_layer/character_lcd/cha_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUA_layer/character_lcd/cha_lcd.p1 ECUA_layer/character_lcd/cha_lcd.c 
	@-${MV} ${OBJECTDIR}/ECUA_layer/character_lcd/cha_lcd.d ${OBJECTDIR}/ECUA_layer/character_lcd/cha_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUA_layer/character_lcd/cha_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUA_layer/DC_motor_driver/ecual_dc_motor_driver.p1: ECUA_layer/DC_motor_driver/ecual_dc_motor_driver.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUA_layer/DC_motor_driver" 
	@${RM} ${OBJECTDIR}/ECUA_layer/DC_motor_driver/ecual_dc_motor_driver.p1.d 
	@${RM} ${OBJECTDIR}/ECUA_layer/DC_motor_driver/ecual_dc_motor_driver.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUA_layer/DC_motor_driver/ecual_dc_motor_driver.p1 ECUA_layer/DC_motor_driver/ecual_dc_motor_driver.c 
	@-${MV} ${OBJECTDIR}/ECUA_layer/DC_motor_driver/ecual_dc_motor_driver.d ${OBJECTDIR}/ECUA_layer/DC_motor_driver/ecual_dc_motor_driver.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUA_layer/DC_motor_driver/ecual_dc_motor_driver.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUA_layer/keypad/ecual_keypad.p1: ECUA_layer/keypad/ecual_keypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUA_layer/keypad" 
	@${RM} ${OBJECTDIR}/ECUA_layer/keypad/ecual_keypad.p1.d 
	@${RM} ${OBJECTDIR}/ECUA_layer/keypad/ecual_keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUA_layer/keypad/ecual_keypad.p1 ECUA_layer/keypad/ecual_keypad.c 
	@-${MV} ${OBJECTDIR}/ECUA_layer/keypad/ecual_keypad.d ${OBJECTDIR}/ECUA_layer/keypad/ecual_keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUA_layer/keypad/ecual_keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUA_layer/LED/ECUAL_led.p1: ECUA_layer/LED/ECUAL_led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUA_layer/LED" 
	@${RM} ${OBJECTDIR}/ECUA_layer/LED/ECUAL_led.p1.d 
	@${RM} ${OBJECTDIR}/ECUA_layer/LED/ECUAL_led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUA_layer/LED/ECUAL_led.p1 ECUA_layer/LED/ECUAL_led.c 
	@-${MV} ${OBJECTDIR}/ECUA_layer/LED/ECUAL_led.d ${OBJECTDIR}/ECUA_layer/LED/ECUAL_led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUA_layer/LED/ECUAL_led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUA_layer/relay/ecual_relay.p1: ECUA_layer/relay/ecual_relay.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUA_layer/relay" 
	@${RM} ${OBJECTDIR}/ECUA_layer/relay/ecual_relay.p1.d 
	@${RM} ${OBJECTDIR}/ECUA_layer/relay/ecual_relay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUA_layer/relay/ecual_relay.p1 ECUA_layer/relay/ecual_relay.c 
	@-${MV} ${OBJECTDIR}/ECUA_layer/relay/ecual_relay.d ${OBJECTDIR}/ECUA_layer/relay/ecual_relay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUA_layer/relay/ecual_relay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUA_layer/seven_segment/ecual_seven_segment.p1: ECUA_layer/seven_segment/ecual_seven_segment.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUA_layer/seven_segment" 
	@${RM} ${OBJECTDIR}/ECUA_layer/seven_segment/ecual_seven_segment.p1.d 
	@${RM} ${OBJECTDIR}/ECUA_layer/seven_segment/ecual_seven_segment.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUA_layer/seven_segment/ecual_seven_segment.p1 ECUA_layer/seven_segment/ecual_seven_segment.c 
	@-${MV} ${OBJECTDIR}/ECUA_layer/seven_segment/ecual_seven_segment.d ${OBJECTDIR}/ECUA_layer/seven_segment/ecual_seven_segment.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUA_layer/seven_segment/ecual_seven_segment.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUA_layer/ecual_layer_initalization.p1: ECUA_layer/ecual_layer_initalization.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUA_layer" 
	@${RM} ${OBJECTDIR}/ECUA_layer/ecual_layer_initalization.p1.d 
	@${RM} ${OBJECTDIR}/ECUA_layer/ecual_layer_initalization.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUA_layer/ecual_layer_initalization.p1 ECUA_layer/ecual_layer_initalization.c 
	@-${MV} ${OBJECTDIR}/ECUA_layer/ecual_layer_initalization.d ${OBJECTDIR}/ECUA_layer/ecual_layer_initalization.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUA_layer/ecual_layer_initalization.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_layer/ADC/MCAL_ADC.p1: MCA_layer/ADC/MCAL_ADC.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_layer/ADC" 
	@${RM} ${OBJECTDIR}/MCA_layer/ADC/MCAL_ADC.p1.d 
	@${RM} ${OBJECTDIR}/MCA_layer/ADC/MCAL_ADC.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_layer/ADC/MCAL_ADC.p1 MCA_layer/ADC/MCAL_ADC.c 
	@-${MV} ${OBJECTDIR}/MCA_layer/ADC/MCAL_ADC.d ${OBJECTDIR}/MCA_layer/ADC/MCAL_ADC.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_layer/ADC/MCAL_ADC.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_layer/CCP1/Mcal_CCP1.p1: MCA_layer/CCP1/Mcal_CCP1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_layer/CCP1" 
	@${RM} ${OBJECTDIR}/MCA_layer/CCP1/Mcal_CCP1.p1.d 
	@${RM} ${OBJECTDIR}/MCA_layer/CCP1/Mcal_CCP1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_layer/CCP1/Mcal_CCP1.p1 MCA_layer/CCP1/Mcal_CCP1.c 
	@-${MV} ${OBJECTDIR}/MCA_layer/CCP1/Mcal_CCP1.d ${OBJECTDIR}/MCA_layer/CCP1/Mcal_CCP1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_layer/CCP1/Mcal_CCP1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_layer/device_configuration/device_configure.p1: MCA_layer/device_configuration/device_configure.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_layer/device_configuration" 
	@${RM} ${OBJECTDIR}/MCA_layer/device_configuration/device_configure.p1.d 
	@${RM} ${OBJECTDIR}/MCA_layer/device_configuration/device_configure.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_layer/device_configuration/device_configure.p1 MCA_layer/device_configuration/device_configure.c 
	@-${MV} ${OBJECTDIR}/MCA_layer/device_configuration/device_configure.d ${OBJECTDIR}/MCA_layer/device_configuration/device_configure.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_layer/device_configuration/device_configure.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_layer/EEPROM/MCAL_EEPROM.p1: MCA_layer/EEPROM/MCAL_EEPROM.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_layer/EEPROM" 
	@${RM} ${OBJECTDIR}/MCA_layer/EEPROM/MCAL_EEPROM.p1.d 
	@${RM} ${OBJECTDIR}/MCA_layer/EEPROM/MCAL_EEPROM.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_layer/EEPROM/MCAL_EEPROM.p1 MCA_layer/EEPROM/MCAL_EEPROM.c 
	@-${MV} ${OBJECTDIR}/MCA_layer/EEPROM/MCAL_EEPROM.d ${OBJECTDIR}/MCA_layer/EEPROM/MCAL_EEPROM.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_layer/EEPROM/MCAL_EEPROM.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_layer/GPIO/mcal_GPIO.p1: MCA_layer/GPIO/mcal_GPIO.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_layer/GPIO" 
	@${RM} ${OBJECTDIR}/MCA_layer/GPIO/mcal_GPIO.p1.d 
	@${RM} ${OBJECTDIR}/MCA_layer/GPIO/mcal_GPIO.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_layer/GPIO/mcal_GPIO.p1 MCA_layer/GPIO/mcal_GPIO.c 
	@-${MV} ${OBJECTDIR}/MCA_layer/GPIO/mcal_GPIO.d ${OBJECTDIR}/MCA_layer/GPIO/mcal_GPIO.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_layer/GPIO/mcal_GPIO.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_layer/interrupt/mcal_internal_interrupt.p1: MCA_layer/interrupt/mcal_internal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_layer/interrupt" 
	@${RM} ${OBJECTDIR}/MCA_layer/interrupt/mcal_internal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCA_layer/interrupt/mcal_internal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_layer/interrupt/mcal_internal_interrupt.p1 MCA_layer/interrupt/mcal_internal_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCA_layer/interrupt/mcal_internal_interrupt.d ${OBJECTDIR}/MCA_layer/interrupt/mcal_internal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_layer/interrupt/mcal_internal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_layer/interrupt/mcal_external_inrerrupt.p1: MCA_layer/interrupt/mcal_external_inrerrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_layer/interrupt" 
	@${RM} ${OBJECTDIR}/MCA_layer/interrupt/mcal_external_inrerrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCA_layer/interrupt/mcal_external_inrerrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_layer/interrupt/mcal_external_inrerrupt.p1 MCA_layer/interrupt/mcal_external_inrerrupt.c 
	@-${MV} ${OBJECTDIR}/MCA_layer/interrupt/mcal_external_inrerrupt.d ${OBJECTDIR}/MCA_layer/interrupt/mcal_external_inrerrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_layer/interrupt/mcal_external_inrerrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_layer/interrupt/mcal_inrerrupt_manger.p1: MCA_layer/interrupt/mcal_inrerrupt_manger.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_layer/interrupt" 
	@${RM} ${OBJECTDIR}/MCA_layer/interrupt/mcal_inrerrupt_manger.p1.d 
	@${RM} ${OBJECTDIR}/MCA_layer/interrupt/mcal_inrerrupt_manger.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_layer/interrupt/mcal_inrerrupt_manger.p1 MCA_layer/interrupt/mcal_inrerrupt_manger.c 
	@-${MV} ${OBJECTDIR}/MCA_layer/interrupt/mcal_inrerrupt_manger.d ${OBJECTDIR}/MCA_layer/interrupt/mcal_inrerrupt_manger.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_layer/interrupt/mcal_inrerrupt_manger.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_layer/TIMER0/MCAL_TIMER0.p1: MCA_layer/TIMER0/MCAL_TIMER0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_layer/TIMER0" 
	@${RM} ${OBJECTDIR}/MCA_layer/TIMER0/MCAL_TIMER0.p1.d 
	@${RM} ${OBJECTDIR}/MCA_layer/TIMER0/MCAL_TIMER0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_layer/TIMER0/MCAL_TIMER0.p1 MCA_layer/TIMER0/MCAL_TIMER0.c 
	@-${MV} ${OBJECTDIR}/MCA_layer/TIMER0/MCAL_TIMER0.d ${OBJECTDIR}/MCA_layer/TIMER0/MCAL_TIMER0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_layer/TIMER0/MCAL_TIMER0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_layer/TIMER1/MCAL_TIMER1.p1: MCA_layer/TIMER1/MCAL_TIMER1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_layer/TIMER1" 
	@${RM} ${OBJECTDIR}/MCA_layer/TIMER1/MCAL_TIMER1.p1.d 
	@${RM} ${OBJECTDIR}/MCA_layer/TIMER1/MCAL_TIMER1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_layer/TIMER1/MCAL_TIMER1.p1 MCA_layer/TIMER1/MCAL_TIMER1.c 
	@-${MV} ${OBJECTDIR}/MCA_layer/TIMER1/MCAL_TIMER1.d ${OBJECTDIR}/MCA_layer/TIMER1/MCAL_TIMER1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_layer/TIMER1/MCAL_TIMER1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_layer/TIMER2/MCAL_TIMER2.p1: MCA_layer/TIMER2/MCAL_TIMER2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_layer/TIMER2" 
	@${RM} ${OBJECTDIR}/MCA_layer/TIMER2/MCAL_TIMER2.p1.d 
	@${RM} ${OBJECTDIR}/MCA_layer/TIMER2/MCAL_TIMER2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_layer/TIMER2/MCAL_TIMER2.p1 MCA_layer/TIMER2/MCAL_TIMER2.c 
	@-${MV} ${OBJECTDIR}/MCA_layer/TIMER2/MCAL_TIMER2.d ${OBJECTDIR}/MCA_layer/TIMER2/MCAL_TIMER2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_layer/TIMER2/MCAL_TIMER2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_layer/TIMER3/MCAL_TIMER3.p1: MCA_layer/TIMER3/MCAL_TIMER3.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_layer/TIMER3" 
	@${RM} ${OBJECTDIR}/MCA_layer/TIMER3/MCAL_TIMER3.p1.d 
	@${RM} ${OBJECTDIR}/MCA_layer/TIMER3/MCAL_TIMER3.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_layer/TIMER3/MCAL_TIMER3.p1 MCA_layer/TIMER3/MCAL_TIMER3.c 
	@-${MV} ${OBJECTDIR}/MCA_layer/TIMER3/MCAL_TIMER3.d ${OBJECTDIR}/MCA_layer/TIMER3/MCAL_TIMER3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_layer/TIMER3/MCAL_TIMER3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_layer/USART/MCAL_USART.p1: MCA_layer/USART/MCAL_USART.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_layer/USART" 
	@${RM} ${OBJECTDIR}/MCA_layer/USART/MCAL_USART.p1.d 
	@${RM} ${OBJECTDIR}/MCA_layer/USART/MCAL_USART.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_layer/USART/MCAL_USART.p1 MCA_layer/USART/MCAL_USART.c 
	@-${MV} ${OBJECTDIR}/MCA_layer/USART/MCAL_USART.d ${OBJECTDIR}/MCA_layer/USART/MCAL_USART.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_layer/USART/MCAL_USART.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/application_main.p1: application_main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application_main.p1.d 
	@${RM} ${OBJECTDIR}/application_main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/application_main.p1 application_main.c 
	@-${MV} ${OBJECTDIR}/application_main.d ${OBJECTDIR}/application_main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/application_main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/my_project.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/my_project.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/my_project.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/my_project.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/my_project.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/my_project.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/my_project.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
