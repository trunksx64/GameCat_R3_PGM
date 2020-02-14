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
ifeq "$(wildcard nbproject/Makefile-local-GameCat_XC24H.mk)" "nbproject/Makefile-local-GameCat_XC24H.mk"
include nbproject/Makefile-local-GameCat_XC24H.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=GameCat_XC24H
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/GameCat_XC24H.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/GameCat_XC24H.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=controls/control_draw_menu.c controls/control_parameters_can.c controls/control_struct_menu_can.c controls/control_parameters_system.c drivers/driver_analog_digital_converter.c drivers/driver_controller_area_network.c drivers/driver_cyclic_redundancy_check.c drivers/driver_direct_memory_access_one.c drivers/driver_direct_memory_access_zero.c drivers/driver_output_compare_one.c drivers/driver_serial_peripheral_interface_one.c drivers/driver_timer_two.c drivers/driver_universal_asynchronous_receiver_transmitter_one.c drivers/driver_universal_asynchronous_receiver_transmitter_two.c drivers/driver_timer_five.c libraries/library_draw_font.c libraries/library_draw_primitives.c libraries/library_glcd_pcd8544.c libraries/library_joystick.c libraries/library_storage_bitmaps.c libraries/library_storage_fonts.c libraries/library_management_pulses.c main/dma_interruptions.c main/main_configuration.c main/main_function.c main/main_interruptions.c main/traps_interruptions.c sources/source_config_event_groups.c sources/source_config_mutex.c sources/source_config_queues.c sources/source_config_tasks.c sources/source_config_timers.c system/list.c system/queue.c system/tasks.c system/timers.c system/portable/MemMang/heap_4.c system/portable/PIC24_dsPIC/port.c system/portable/PIC24_dsPIC/portasm_PIC24.S system/event_groups.c threads/thread_screen_menu.c threads/threads_timer_system.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/controls/control_draw_menu.o ${OBJECTDIR}/controls/control_parameters_can.o ${OBJECTDIR}/controls/control_struct_menu_can.o ${OBJECTDIR}/controls/control_parameters_system.o ${OBJECTDIR}/drivers/driver_analog_digital_converter.o ${OBJECTDIR}/drivers/driver_controller_area_network.o ${OBJECTDIR}/drivers/driver_cyclic_redundancy_check.o ${OBJECTDIR}/drivers/driver_direct_memory_access_one.o ${OBJECTDIR}/drivers/driver_direct_memory_access_zero.o ${OBJECTDIR}/drivers/driver_output_compare_one.o ${OBJECTDIR}/drivers/driver_serial_peripheral_interface_one.o ${OBJECTDIR}/drivers/driver_timer_two.o ${OBJECTDIR}/drivers/driver_universal_asynchronous_receiver_transmitter_one.o ${OBJECTDIR}/drivers/driver_universal_asynchronous_receiver_transmitter_two.o ${OBJECTDIR}/drivers/driver_timer_five.o ${OBJECTDIR}/libraries/library_draw_font.o ${OBJECTDIR}/libraries/library_draw_primitives.o ${OBJECTDIR}/libraries/library_glcd_pcd8544.o ${OBJECTDIR}/libraries/library_joystick.o ${OBJECTDIR}/libraries/library_storage_bitmaps.o ${OBJECTDIR}/libraries/library_storage_fonts.o ${OBJECTDIR}/libraries/library_management_pulses.o ${OBJECTDIR}/main/dma_interruptions.o ${OBJECTDIR}/main/main_configuration.o ${OBJECTDIR}/main/main_function.o ${OBJECTDIR}/main/main_interruptions.o ${OBJECTDIR}/main/traps_interruptions.o ${OBJECTDIR}/sources/source_config_event_groups.o ${OBJECTDIR}/sources/source_config_mutex.o ${OBJECTDIR}/sources/source_config_queues.o ${OBJECTDIR}/sources/source_config_tasks.o ${OBJECTDIR}/sources/source_config_timers.o ${OBJECTDIR}/system/list.o ${OBJECTDIR}/system/queue.o ${OBJECTDIR}/system/tasks.o ${OBJECTDIR}/system/timers.o ${OBJECTDIR}/system/portable/MemMang/heap_4.o ${OBJECTDIR}/system/portable/PIC24_dsPIC/port.o ${OBJECTDIR}/system/portable/PIC24_dsPIC/portasm_PIC24.o ${OBJECTDIR}/system/event_groups.o ${OBJECTDIR}/threads/thread_screen_menu.o ${OBJECTDIR}/threads/threads_timer_system.o
POSSIBLE_DEPFILES=${OBJECTDIR}/controls/control_draw_menu.o.d ${OBJECTDIR}/controls/control_parameters_can.o.d ${OBJECTDIR}/controls/control_struct_menu_can.o.d ${OBJECTDIR}/controls/control_parameters_system.o.d ${OBJECTDIR}/drivers/driver_analog_digital_converter.o.d ${OBJECTDIR}/drivers/driver_controller_area_network.o.d ${OBJECTDIR}/drivers/driver_cyclic_redundancy_check.o.d ${OBJECTDIR}/drivers/driver_direct_memory_access_one.o.d ${OBJECTDIR}/drivers/driver_direct_memory_access_zero.o.d ${OBJECTDIR}/drivers/driver_output_compare_one.o.d ${OBJECTDIR}/drivers/driver_serial_peripheral_interface_one.o.d ${OBJECTDIR}/drivers/driver_timer_two.o.d ${OBJECTDIR}/drivers/driver_universal_asynchronous_receiver_transmitter_one.o.d ${OBJECTDIR}/drivers/driver_universal_asynchronous_receiver_transmitter_two.o.d ${OBJECTDIR}/drivers/driver_timer_five.o.d ${OBJECTDIR}/libraries/library_draw_font.o.d ${OBJECTDIR}/libraries/library_draw_primitives.o.d ${OBJECTDIR}/libraries/library_glcd_pcd8544.o.d ${OBJECTDIR}/libraries/library_joystick.o.d ${OBJECTDIR}/libraries/library_storage_bitmaps.o.d ${OBJECTDIR}/libraries/library_storage_fonts.o.d ${OBJECTDIR}/libraries/library_management_pulses.o.d ${OBJECTDIR}/main/dma_interruptions.o.d ${OBJECTDIR}/main/main_configuration.o.d ${OBJECTDIR}/main/main_function.o.d ${OBJECTDIR}/main/main_interruptions.o.d ${OBJECTDIR}/main/traps_interruptions.o.d ${OBJECTDIR}/sources/source_config_event_groups.o.d ${OBJECTDIR}/sources/source_config_mutex.o.d ${OBJECTDIR}/sources/source_config_queues.o.d ${OBJECTDIR}/sources/source_config_tasks.o.d ${OBJECTDIR}/sources/source_config_timers.o.d ${OBJECTDIR}/system/list.o.d ${OBJECTDIR}/system/queue.o.d ${OBJECTDIR}/system/tasks.o.d ${OBJECTDIR}/system/timers.o.d ${OBJECTDIR}/system/portable/MemMang/heap_4.o.d ${OBJECTDIR}/system/portable/PIC24_dsPIC/port.o.d ${OBJECTDIR}/system/portable/PIC24_dsPIC/portasm_PIC24.o.d ${OBJECTDIR}/system/event_groups.o.d ${OBJECTDIR}/threads/thread_screen_menu.o.d ${OBJECTDIR}/threads/threads_timer_system.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/controls/control_draw_menu.o ${OBJECTDIR}/controls/control_parameters_can.o ${OBJECTDIR}/controls/control_struct_menu_can.o ${OBJECTDIR}/controls/control_parameters_system.o ${OBJECTDIR}/drivers/driver_analog_digital_converter.o ${OBJECTDIR}/drivers/driver_controller_area_network.o ${OBJECTDIR}/drivers/driver_cyclic_redundancy_check.o ${OBJECTDIR}/drivers/driver_direct_memory_access_one.o ${OBJECTDIR}/drivers/driver_direct_memory_access_zero.o ${OBJECTDIR}/drivers/driver_output_compare_one.o ${OBJECTDIR}/drivers/driver_serial_peripheral_interface_one.o ${OBJECTDIR}/drivers/driver_timer_two.o ${OBJECTDIR}/drivers/driver_universal_asynchronous_receiver_transmitter_one.o ${OBJECTDIR}/drivers/driver_universal_asynchronous_receiver_transmitter_two.o ${OBJECTDIR}/drivers/driver_timer_five.o ${OBJECTDIR}/libraries/library_draw_font.o ${OBJECTDIR}/libraries/library_draw_primitives.o ${OBJECTDIR}/libraries/library_glcd_pcd8544.o ${OBJECTDIR}/libraries/library_joystick.o ${OBJECTDIR}/libraries/library_storage_bitmaps.o ${OBJECTDIR}/libraries/library_storage_fonts.o ${OBJECTDIR}/libraries/library_management_pulses.o ${OBJECTDIR}/main/dma_interruptions.o ${OBJECTDIR}/main/main_configuration.o ${OBJECTDIR}/main/main_function.o ${OBJECTDIR}/main/main_interruptions.o ${OBJECTDIR}/main/traps_interruptions.o ${OBJECTDIR}/sources/source_config_event_groups.o ${OBJECTDIR}/sources/source_config_mutex.o ${OBJECTDIR}/sources/source_config_queues.o ${OBJECTDIR}/sources/source_config_tasks.o ${OBJECTDIR}/sources/source_config_timers.o ${OBJECTDIR}/system/list.o ${OBJECTDIR}/system/queue.o ${OBJECTDIR}/system/tasks.o ${OBJECTDIR}/system/timers.o ${OBJECTDIR}/system/portable/MemMang/heap_4.o ${OBJECTDIR}/system/portable/PIC24_dsPIC/port.o ${OBJECTDIR}/system/portable/PIC24_dsPIC/portasm_PIC24.o ${OBJECTDIR}/system/event_groups.o ${OBJECTDIR}/threads/thread_screen_menu.o ${OBJECTDIR}/threads/threads_timer_system.o

# Source Files
SOURCEFILES=controls/control_draw_menu.c controls/control_parameters_can.c controls/control_struct_menu_can.c controls/control_parameters_system.c drivers/driver_analog_digital_converter.c drivers/driver_controller_area_network.c drivers/driver_cyclic_redundancy_check.c drivers/driver_direct_memory_access_one.c drivers/driver_direct_memory_access_zero.c drivers/driver_output_compare_one.c drivers/driver_serial_peripheral_interface_one.c drivers/driver_timer_two.c drivers/driver_universal_asynchronous_receiver_transmitter_one.c drivers/driver_universal_asynchronous_receiver_transmitter_two.c drivers/driver_timer_five.c libraries/library_draw_font.c libraries/library_draw_primitives.c libraries/library_glcd_pcd8544.c libraries/library_joystick.c libraries/library_storage_bitmaps.c libraries/library_storage_fonts.c libraries/library_management_pulses.c main/dma_interruptions.c main/main_configuration.c main/main_function.c main/main_interruptions.c main/traps_interruptions.c sources/source_config_event_groups.c sources/source_config_mutex.c sources/source_config_queues.c sources/source_config_tasks.c sources/source_config_timers.c system/list.c system/queue.c system/tasks.c system/timers.c system/portable/MemMang/heap_4.c system/portable/PIC24_dsPIC/port.c system/portable/PIC24_dsPIC/portasm_PIC24.S system/event_groups.c threads/thread_screen_menu.c threads/threads_timer_system.c



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
	${MAKE}  -f nbproject/Makefile-GameCat_XC24H.mk dist/${CND_CONF}/${IMAGE_TYPE}/GameCat_XC24H.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24HJ128GP504
MP_LINKER_FILE_OPTION=,--script=p24HJ128GP504.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/controls/control_draw_menu.o: controls/control_draw_menu.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/controls" 
	@${RM} ${OBJECTDIR}/controls/control_draw_menu.o.d 
	@${RM} ${OBJECTDIR}/controls/control_draw_menu.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  controls/control_draw_menu.c  -o ${OBJECTDIR}/controls/control_draw_menu.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/controls/control_draw_menu.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/controls/control_draw_menu.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/controls/control_parameters_can.o: controls/control_parameters_can.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/controls" 
	@${RM} ${OBJECTDIR}/controls/control_parameters_can.o.d 
	@${RM} ${OBJECTDIR}/controls/control_parameters_can.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  controls/control_parameters_can.c  -o ${OBJECTDIR}/controls/control_parameters_can.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/controls/control_parameters_can.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/controls/control_parameters_can.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/controls/control_struct_menu_can.o: controls/control_struct_menu_can.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/controls" 
	@${RM} ${OBJECTDIR}/controls/control_struct_menu_can.o.d 
	@${RM} ${OBJECTDIR}/controls/control_struct_menu_can.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  controls/control_struct_menu_can.c  -o ${OBJECTDIR}/controls/control_struct_menu_can.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/controls/control_struct_menu_can.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/controls/control_struct_menu_can.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/controls/control_parameters_system.o: controls/control_parameters_system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/controls" 
	@${RM} ${OBJECTDIR}/controls/control_parameters_system.o.d 
	@${RM} ${OBJECTDIR}/controls/control_parameters_system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  controls/control_parameters_system.c  -o ${OBJECTDIR}/controls/control_parameters_system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/controls/control_parameters_system.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/controls/control_parameters_system.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/drivers/driver_analog_digital_converter.o: drivers/driver_analog_digital_converter.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/driver_analog_digital_converter.o.d 
	@${RM} ${OBJECTDIR}/drivers/driver_analog_digital_converter.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  drivers/driver_analog_digital_converter.c  -o ${OBJECTDIR}/drivers/driver_analog_digital_converter.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/drivers/driver_analog_digital_converter.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/drivers/driver_analog_digital_converter.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/drivers/driver_controller_area_network.o: drivers/driver_controller_area_network.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/driver_controller_area_network.o.d 
	@${RM} ${OBJECTDIR}/drivers/driver_controller_area_network.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  drivers/driver_controller_area_network.c  -o ${OBJECTDIR}/drivers/driver_controller_area_network.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/drivers/driver_controller_area_network.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/drivers/driver_controller_area_network.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/drivers/driver_cyclic_redundancy_check.o: drivers/driver_cyclic_redundancy_check.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/driver_cyclic_redundancy_check.o.d 
	@${RM} ${OBJECTDIR}/drivers/driver_cyclic_redundancy_check.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  drivers/driver_cyclic_redundancy_check.c  -o ${OBJECTDIR}/drivers/driver_cyclic_redundancy_check.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/drivers/driver_cyclic_redundancy_check.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/drivers/driver_cyclic_redundancy_check.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/drivers/driver_direct_memory_access_one.o: drivers/driver_direct_memory_access_one.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/driver_direct_memory_access_one.o.d 
	@${RM} ${OBJECTDIR}/drivers/driver_direct_memory_access_one.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  drivers/driver_direct_memory_access_one.c  -o ${OBJECTDIR}/drivers/driver_direct_memory_access_one.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/drivers/driver_direct_memory_access_one.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/drivers/driver_direct_memory_access_one.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/drivers/driver_direct_memory_access_zero.o: drivers/driver_direct_memory_access_zero.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/driver_direct_memory_access_zero.o.d 
	@${RM} ${OBJECTDIR}/drivers/driver_direct_memory_access_zero.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  drivers/driver_direct_memory_access_zero.c  -o ${OBJECTDIR}/drivers/driver_direct_memory_access_zero.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/drivers/driver_direct_memory_access_zero.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/drivers/driver_direct_memory_access_zero.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/drivers/driver_output_compare_one.o: drivers/driver_output_compare_one.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/driver_output_compare_one.o.d 
	@${RM} ${OBJECTDIR}/drivers/driver_output_compare_one.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  drivers/driver_output_compare_one.c  -o ${OBJECTDIR}/drivers/driver_output_compare_one.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/drivers/driver_output_compare_one.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/drivers/driver_output_compare_one.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/drivers/driver_serial_peripheral_interface_one.o: drivers/driver_serial_peripheral_interface_one.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/driver_serial_peripheral_interface_one.o.d 
	@${RM} ${OBJECTDIR}/drivers/driver_serial_peripheral_interface_one.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  drivers/driver_serial_peripheral_interface_one.c  -o ${OBJECTDIR}/drivers/driver_serial_peripheral_interface_one.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/drivers/driver_serial_peripheral_interface_one.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/drivers/driver_serial_peripheral_interface_one.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/drivers/driver_timer_two.o: drivers/driver_timer_two.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/driver_timer_two.o.d 
	@${RM} ${OBJECTDIR}/drivers/driver_timer_two.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  drivers/driver_timer_two.c  -o ${OBJECTDIR}/drivers/driver_timer_two.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/drivers/driver_timer_two.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/drivers/driver_timer_two.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/drivers/driver_universal_asynchronous_receiver_transmitter_one.o: drivers/driver_universal_asynchronous_receiver_transmitter_one.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/driver_universal_asynchronous_receiver_transmitter_one.o.d 
	@${RM} ${OBJECTDIR}/drivers/driver_universal_asynchronous_receiver_transmitter_one.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  drivers/driver_universal_asynchronous_receiver_transmitter_one.c  -o ${OBJECTDIR}/drivers/driver_universal_asynchronous_receiver_transmitter_one.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/drivers/driver_universal_asynchronous_receiver_transmitter_one.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/drivers/driver_universal_asynchronous_receiver_transmitter_one.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/drivers/driver_universal_asynchronous_receiver_transmitter_two.o: drivers/driver_universal_asynchronous_receiver_transmitter_two.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/driver_universal_asynchronous_receiver_transmitter_two.o.d 
	@${RM} ${OBJECTDIR}/drivers/driver_universal_asynchronous_receiver_transmitter_two.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  drivers/driver_universal_asynchronous_receiver_transmitter_two.c  -o ${OBJECTDIR}/drivers/driver_universal_asynchronous_receiver_transmitter_two.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/drivers/driver_universal_asynchronous_receiver_transmitter_two.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/drivers/driver_universal_asynchronous_receiver_transmitter_two.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/drivers/driver_timer_five.o: drivers/driver_timer_five.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/driver_timer_five.o.d 
	@${RM} ${OBJECTDIR}/drivers/driver_timer_five.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  drivers/driver_timer_five.c  -o ${OBJECTDIR}/drivers/driver_timer_five.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/drivers/driver_timer_five.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/drivers/driver_timer_five.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/libraries/library_draw_font.o: libraries/library_draw_font.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/libraries" 
	@${RM} ${OBJECTDIR}/libraries/library_draw_font.o.d 
	@${RM} ${OBJECTDIR}/libraries/library_draw_font.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  libraries/library_draw_font.c  -o ${OBJECTDIR}/libraries/library_draw_font.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/libraries/library_draw_font.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/libraries/library_draw_font.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/libraries/library_draw_primitives.o: libraries/library_draw_primitives.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/libraries" 
	@${RM} ${OBJECTDIR}/libraries/library_draw_primitives.o.d 
	@${RM} ${OBJECTDIR}/libraries/library_draw_primitives.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  libraries/library_draw_primitives.c  -o ${OBJECTDIR}/libraries/library_draw_primitives.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/libraries/library_draw_primitives.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/libraries/library_draw_primitives.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/libraries/library_glcd_pcd8544.o: libraries/library_glcd_pcd8544.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/libraries" 
	@${RM} ${OBJECTDIR}/libraries/library_glcd_pcd8544.o.d 
	@${RM} ${OBJECTDIR}/libraries/library_glcd_pcd8544.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  libraries/library_glcd_pcd8544.c  -o ${OBJECTDIR}/libraries/library_glcd_pcd8544.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/libraries/library_glcd_pcd8544.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/libraries/library_glcd_pcd8544.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/libraries/library_joystick.o: libraries/library_joystick.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/libraries" 
	@${RM} ${OBJECTDIR}/libraries/library_joystick.o.d 
	@${RM} ${OBJECTDIR}/libraries/library_joystick.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  libraries/library_joystick.c  -o ${OBJECTDIR}/libraries/library_joystick.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/libraries/library_joystick.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/libraries/library_joystick.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/libraries/library_storage_bitmaps.o: libraries/library_storage_bitmaps.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/libraries" 
	@${RM} ${OBJECTDIR}/libraries/library_storage_bitmaps.o.d 
	@${RM} ${OBJECTDIR}/libraries/library_storage_bitmaps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  libraries/library_storage_bitmaps.c  -o ${OBJECTDIR}/libraries/library_storage_bitmaps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/libraries/library_storage_bitmaps.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/libraries/library_storage_bitmaps.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/libraries/library_storage_fonts.o: libraries/library_storage_fonts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/libraries" 
	@${RM} ${OBJECTDIR}/libraries/library_storage_fonts.o.d 
	@${RM} ${OBJECTDIR}/libraries/library_storage_fonts.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  libraries/library_storage_fonts.c  -o ${OBJECTDIR}/libraries/library_storage_fonts.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/libraries/library_storage_fonts.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/libraries/library_storage_fonts.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/libraries/library_management_pulses.o: libraries/library_management_pulses.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/libraries" 
	@${RM} ${OBJECTDIR}/libraries/library_management_pulses.o.d 
	@${RM} ${OBJECTDIR}/libraries/library_management_pulses.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  libraries/library_management_pulses.c  -o ${OBJECTDIR}/libraries/library_management_pulses.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/libraries/library_management_pulses.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/libraries/library_management_pulses.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/main/dma_interruptions.o: main/dma_interruptions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/main" 
	@${RM} ${OBJECTDIR}/main/dma_interruptions.o.d 
	@${RM} ${OBJECTDIR}/main/dma_interruptions.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main/dma_interruptions.c  -o ${OBJECTDIR}/main/dma_interruptions.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main/dma_interruptions.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/main/dma_interruptions.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/main/main_configuration.o: main/main_configuration.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/main" 
	@${RM} ${OBJECTDIR}/main/main_configuration.o.d 
	@${RM} ${OBJECTDIR}/main/main_configuration.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main/main_configuration.c  -o ${OBJECTDIR}/main/main_configuration.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main/main_configuration.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/main/main_configuration.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/main/main_function.o: main/main_function.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/main" 
	@${RM} ${OBJECTDIR}/main/main_function.o.d 
	@${RM} ${OBJECTDIR}/main/main_function.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main/main_function.c  -o ${OBJECTDIR}/main/main_function.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main/main_function.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/main/main_function.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/main/main_interruptions.o: main/main_interruptions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/main" 
	@${RM} ${OBJECTDIR}/main/main_interruptions.o.d 
	@${RM} ${OBJECTDIR}/main/main_interruptions.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main/main_interruptions.c  -o ${OBJECTDIR}/main/main_interruptions.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main/main_interruptions.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/main/main_interruptions.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/main/traps_interruptions.o: main/traps_interruptions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/main" 
	@${RM} ${OBJECTDIR}/main/traps_interruptions.o.d 
	@${RM} ${OBJECTDIR}/main/traps_interruptions.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main/traps_interruptions.c  -o ${OBJECTDIR}/main/traps_interruptions.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main/traps_interruptions.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/main/traps_interruptions.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/sources/source_config_event_groups.o: sources/source_config_event_groups.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/sources" 
	@${RM} ${OBJECTDIR}/sources/source_config_event_groups.o.d 
	@${RM} ${OBJECTDIR}/sources/source_config_event_groups.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/source_config_event_groups.c  -o ${OBJECTDIR}/sources/source_config_event_groups.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/sources/source_config_event_groups.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/sources/source_config_event_groups.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/sources/source_config_mutex.o: sources/source_config_mutex.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/sources" 
	@${RM} ${OBJECTDIR}/sources/source_config_mutex.o.d 
	@${RM} ${OBJECTDIR}/sources/source_config_mutex.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/source_config_mutex.c  -o ${OBJECTDIR}/sources/source_config_mutex.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/sources/source_config_mutex.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/sources/source_config_mutex.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/sources/source_config_queues.o: sources/source_config_queues.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/sources" 
	@${RM} ${OBJECTDIR}/sources/source_config_queues.o.d 
	@${RM} ${OBJECTDIR}/sources/source_config_queues.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/source_config_queues.c  -o ${OBJECTDIR}/sources/source_config_queues.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/sources/source_config_queues.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/sources/source_config_queues.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/sources/source_config_tasks.o: sources/source_config_tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/sources" 
	@${RM} ${OBJECTDIR}/sources/source_config_tasks.o.d 
	@${RM} ${OBJECTDIR}/sources/source_config_tasks.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/source_config_tasks.c  -o ${OBJECTDIR}/sources/source_config_tasks.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/sources/source_config_tasks.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/sources/source_config_tasks.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/sources/source_config_timers.o: sources/source_config_timers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/sources" 
	@${RM} ${OBJECTDIR}/sources/source_config_timers.o.d 
	@${RM} ${OBJECTDIR}/sources/source_config_timers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/source_config_timers.c  -o ${OBJECTDIR}/sources/source_config_timers.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/sources/source_config_timers.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/sources/source_config_timers.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/system/list.o: system/list.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/system" 
	@${RM} ${OBJECTDIR}/system/list.o.d 
	@${RM} ${OBJECTDIR}/system/list.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system/list.c  -o ${OBJECTDIR}/system/list.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/system/list.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/system/list.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/system/queue.o: system/queue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/system" 
	@${RM} ${OBJECTDIR}/system/queue.o.d 
	@${RM} ${OBJECTDIR}/system/queue.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system/queue.c  -o ${OBJECTDIR}/system/queue.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/system/queue.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/system/queue.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/system/tasks.o: system/tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/system" 
	@${RM} ${OBJECTDIR}/system/tasks.o.d 
	@${RM} ${OBJECTDIR}/system/tasks.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system/tasks.c  -o ${OBJECTDIR}/system/tasks.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/system/tasks.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/system/tasks.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/system/timers.o: system/timers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/system" 
	@${RM} ${OBJECTDIR}/system/timers.o.d 
	@${RM} ${OBJECTDIR}/system/timers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system/timers.c  -o ${OBJECTDIR}/system/timers.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/system/timers.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/system/timers.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/system/portable/MemMang/heap_4.o: system/portable/MemMang/heap_4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/system/portable/MemMang" 
	@${RM} ${OBJECTDIR}/system/portable/MemMang/heap_4.o.d 
	@${RM} ${OBJECTDIR}/system/portable/MemMang/heap_4.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system/portable/MemMang/heap_4.c  -o ${OBJECTDIR}/system/portable/MemMang/heap_4.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/system/portable/MemMang/heap_4.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/system/portable/MemMang/heap_4.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/system/portable/PIC24_dsPIC/port.o: system/portable/PIC24_dsPIC/port.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/system/portable/PIC24_dsPIC" 
	@${RM} ${OBJECTDIR}/system/portable/PIC24_dsPIC/port.o.d 
	@${RM} ${OBJECTDIR}/system/portable/PIC24_dsPIC/port.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system/portable/PIC24_dsPIC/port.c  -o ${OBJECTDIR}/system/portable/PIC24_dsPIC/port.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/system/portable/PIC24_dsPIC/port.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/system/portable/PIC24_dsPIC/port.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/system/event_groups.o: system/event_groups.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/system" 
	@${RM} ${OBJECTDIR}/system/event_groups.o.d 
	@${RM} ${OBJECTDIR}/system/event_groups.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system/event_groups.c  -o ${OBJECTDIR}/system/event_groups.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/system/event_groups.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/system/event_groups.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/threads/thread_screen_menu.o: threads/thread_screen_menu.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/threads" 
	@${RM} ${OBJECTDIR}/threads/thread_screen_menu.o.d 
	@${RM} ${OBJECTDIR}/threads/thread_screen_menu.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  threads/thread_screen_menu.c  -o ${OBJECTDIR}/threads/thread_screen_menu.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/threads/thread_screen_menu.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/threads/thread_screen_menu.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/threads/threads_timer_system.o: threads/threads_timer_system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/threads" 
	@${RM} ${OBJECTDIR}/threads/threads_timer_system.o.d 
	@${RM} ${OBJECTDIR}/threads/threads_timer_system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  threads/threads_timer_system.c  -o ${OBJECTDIR}/threads/threads_timer_system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/threads/threads_timer_system.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/threads/threads_timer_system.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/controls/control_draw_menu.o: controls/control_draw_menu.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/controls" 
	@${RM} ${OBJECTDIR}/controls/control_draw_menu.o.d 
	@${RM} ${OBJECTDIR}/controls/control_draw_menu.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  controls/control_draw_menu.c  -o ${OBJECTDIR}/controls/control_draw_menu.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/controls/control_draw_menu.o.d"        -g -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/controls/control_draw_menu.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/controls/control_parameters_can.o: controls/control_parameters_can.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/controls" 
	@${RM} ${OBJECTDIR}/controls/control_parameters_can.o.d 
	@${RM} ${OBJECTDIR}/controls/control_parameters_can.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  controls/control_parameters_can.c  -o ${OBJECTDIR}/controls/control_parameters_can.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/controls/control_parameters_can.o.d"        -g -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/controls/control_parameters_can.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/controls/control_struct_menu_can.o: controls/control_struct_menu_can.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/controls" 
	@${RM} ${OBJECTDIR}/controls/control_struct_menu_can.o.d 
	@${RM} ${OBJECTDIR}/controls/control_struct_menu_can.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  controls/control_struct_menu_can.c  -o ${OBJECTDIR}/controls/control_struct_menu_can.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/controls/control_struct_menu_can.o.d"        -g -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/controls/control_struct_menu_can.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/controls/control_parameters_system.o: controls/control_parameters_system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/controls" 
	@${RM} ${OBJECTDIR}/controls/control_parameters_system.o.d 
	@${RM} ${OBJECTDIR}/controls/control_parameters_system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  controls/control_parameters_system.c  -o ${OBJECTDIR}/controls/control_parameters_system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/controls/control_parameters_system.o.d"        -g -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/controls/control_parameters_system.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/drivers/driver_analog_digital_converter.o: drivers/driver_analog_digital_converter.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/driver_analog_digital_converter.o.d 
	@${RM} ${OBJECTDIR}/drivers/driver_analog_digital_converter.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  drivers/driver_analog_digital_converter.c  -o ${OBJECTDIR}/drivers/driver_analog_digital_converter.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/drivers/driver_analog_digital_converter.o.d"        -g -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/drivers/driver_analog_digital_converter.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/drivers/driver_controller_area_network.o: drivers/driver_controller_area_network.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/driver_controller_area_network.o.d 
	@${RM} ${OBJECTDIR}/drivers/driver_controller_area_network.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  drivers/driver_controller_area_network.c  -o ${OBJECTDIR}/drivers/driver_controller_area_network.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/drivers/driver_controller_area_network.o.d"        -g -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/drivers/driver_controller_area_network.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/drivers/driver_cyclic_redundancy_check.o: drivers/driver_cyclic_redundancy_check.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/driver_cyclic_redundancy_check.o.d 
	@${RM} ${OBJECTDIR}/drivers/driver_cyclic_redundancy_check.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  drivers/driver_cyclic_redundancy_check.c  -o ${OBJECTDIR}/drivers/driver_cyclic_redundancy_check.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/drivers/driver_cyclic_redundancy_check.o.d"        -g -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/drivers/driver_cyclic_redundancy_check.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/drivers/driver_direct_memory_access_one.o: drivers/driver_direct_memory_access_one.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/driver_direct_memory_access_one.o.d 
	@${RM} ${OBJECTDIR}/drivers/driver_direct_memory_access_one.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  drivers/driver_direct_memory_access_one.c  -o ${OBJECTDIR}/drivers/driver_direct_memory_access_one.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/drivers/driver_direct_memory_access_one.o.d"        -g -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/drivers/driver_direct_memory_access_one.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/drivers/driver_direct_memory_access_zero.o: drivers/driver_direct_memory_access_zero.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/driver_direct_memory_access_zero.o.d 
	@${RM} ${OBJECTDIR}/drivers/driver_direct_memory_access_zero.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  drivers/driver_direct_memory_access_zero.c  -o ${OBJECTDIR}/drivers/driver_direct_memory_access_zero.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/drivers/driver_direct_memory_access_zero.o.d"        -g -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/drivers/driver_direct_memory_access_zero.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/drivers/driver_output_compare_one.o: drivers/driver_output_compare_one.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/driver_output_compare_one.o.d 
	@${RM} ${OBJECTDIR}/drivers/driver_output_compare_one.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  drivers/driver_output_compare_one.c  -o ${OBJECTDIR}/drivers/driver_output_compare_one.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/drivers/driver_output_compare_one.o.d"        -g -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/drivers/driver_output_compare_one.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/drivers/driver_serial_peripheral_interface_one.o: drivers/driver_serial_peripheral_interface_one.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/driver_serial_peripheral_interface_one.o.d 
	@${RM} ${OBJECTDIR}/drivers/driver_serial_peripheral_interface_one.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  drivers/driver_serial_peripheral_interface_one.c  -o ${OBJECTDIR}/drivers/driver_serial_peripheral_interface_one.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/drivers/driver_serial_peripheral_interface_one.o.d"        -g -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/drivers/driver_serial_peripheral_interface_one.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/drivers/driver_timer_two.o: drivers/driver_timer_two.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/driver_timer_two.o.d 
	@${RM} ${OBJECTDIR}/drivers/driver_timer_two.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  drivers/driver_timer_two.c  -o ${OBJECTDIR}/drivers/driver_timer_two.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/drivers/driver_timer_two.o.d"        -g -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/drivers/driver_timer_two.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/drivers/driver_universal_asynchronous_receiver_transmitter_one.o: drivers/driver_universal_asynchronous_receiver_transmitter_one.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/driver_universal_asynchronous_receiver_transmitter_one.o.d 
	@${RM} ${OBJECTDIR}/drivers/driver_universal_asynchronous_receiver_transmitter_one.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  drivers/driver_universal_asynchronous_receiver_transmitter_one.c  -o ${OBJECTDIR}/drivers/driver_universal_asynchronous_receiver_transmitter_one.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/drivers/driver_universal_asynchronous_receiver_transmitter_one.o.d"        -g -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/drivers/driver_universal_asynchronous_receiver_transmitter_one.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/drivers/driver_universal_asynchronous_receiver_transmitter_two.o: drivers/driver_universal_asynchronous_receiver_transmitter_two.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/driver_universal_asynchronous_receiver_transmitter_two.o.d 
	@${RM} ${OBJECTDIR}/drivers/driver_universal_asynchronous_receiver_transmitter_two.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  drivers/driver_universal_asynchronous_receiver_transmitter_two.c  -o ${OBJECTDIR}/drivers/driver_universal_asynchronous_receiver_transmitter_two.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/drivers/driver_universal_asynchronous_receiver_transmitter_two.o.d"        -g -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/drivers/driver_universal_asynchronous_receiver_transmitter_two.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/drivers/driver_timer_five.o: drivers/driver_timer_five.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/driver_timer_five.o.d 
	@${RM} ${OBJECTDIR}/drivers/driver_timer_five.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  drivers/driver_timer_five.c  -o ${OBJECTDIR}/drivers/driver_timer_five.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/drivers/driver_timer_five.o.d"        -g -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/drivers/driver_timer_five.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/libraries/library_draw_font.o: libraries/library_draw_font.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/libraries" 
	@${RM} ${OBJECTDIR}/libraries/library_draw_font.o.d 
	@${RM} ${OBJECTDIR}/libraries/library_draw_font.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  libraries/library_draw_font.c  -o ${OBJECTDIR}/libraries/library_draw_font.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/libraries/library_draw_font.o.d"        -g -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/libraries/library_draw_font.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/libraries/library_draw_primitives.o: libraries/library_draw_primitives.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/libraries" 
	@${RM} ${OBJECTDIR}/libraries/library_draw_primitives.o.d 
	@${RM} ${OBJECTDIR}/libraries/library_draw_primitives.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  libraries/library_draw_primitives.c  -o ${OBJECTDIR}/libraries/library_draw_primitives.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/libraries/library_draw_primitives.o.d"        -g -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/libraries/library_draw_primitives.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/libraries/library_glcd_pcd8544.o: libraries/library_glcd_pcd8544.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/libraries" 
	@${RM} ${OBJECTDIR}/libraries/library_glcd_pcd8544.o.d 
	@${RM} ${OBJECTDIR}/libraries/library_glcd_pcd8544.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  libraries/library_glcd_pcd8544.c  -o ${OBJECTDIR}/libraries/library_glcd_pcd8544.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/libraries/library_glcd_pcd8544.o.d"        -g -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/libraries/library_glcd_pcd8544.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/libraries/library_joystick.o: libraries/library_joystick.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/libraries" 
	@${RM} ${OBJECTDIR}/libraries/library_joystick.o.d 
	@${RM} ${OBJECTDIR}/libraries/library_joystick.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  libraries/library_joystick.c  -o ${OBJECTDIR}/libraries/library_joystick.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/libraries/library_joystick.o.d"        -g -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/libraries/library_joystick.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/libraries/library_storage_bitmaps.o: libraries/library_storage_bitmaps.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/libraries" 
	@${RM} ${OBJECTDIR}/libraries/library_storage_bitmaps.o.d 
	@${RM} ${OBJECTDIR}/libraries/library_storage_bitmaps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  libraries/library_storage_bitmaps.c  -o ${OBJECTDIR}/libraries/library_storage_bitmaps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/libraries/library_storage_bitmaps.o.d"        -g -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/libraries/library_storage_bitmaps.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/libraries/library_storage_fonts.o: libraries/library_storage_fonts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/libraries" 
	@${RM} ${OBJECTDIR}/libraries/library_storage_fonts.o.d 
	@${RM} ${OBJECTDIR}/libraries/library_storage_fonts.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  libraries/library_storage_fonts.c  -o ${OBJECTDIR}/libraries/library_storage_fonts.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/libraries/library_storage_fonts.o.d"        -g -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/libraries/library_storage_fonts.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/libraries/library_management_pulses.o: libraries/library_management_pulses.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/libraries" 
	@${RM} ${OBJECTDIR}/libraries/library_management_pulses.o.d 
	@${RM} ${OBJECTDIR}/libraries/library_management_pulses.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  libraries/library_management_pulses.c  -o ${OBJECTDIR}/libraries/library_management_pulses.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/libraries/library_management_pulses.o.d"        -g -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/libraries/library_management_pulses.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/main/dma_interruptions.o: main/dma_interruptions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/main" 
	@${RM} ${OBJECTDIR}/main/dma_interruptions.o.d 
	@${RM} ${OBJECTDIR}/main/dma_interruptions.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main/dma_interruptions.c  -o ${OBJECTDIR}/main/dma_interruptions.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main/dma_interruptions.o.d"        -g -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/main/dma_interruptions.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/main/main_configuration.o: main/main_configuration.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/main" 
	@${RM} ${OBJECTDIR}/main/main_configuration.o.d 
	@${RM} ${OBJECTDIR}/main/main_configuration.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main/main_configuration.c  -o ${OBJECTDIR}/main/main_configuration.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main/main_configuration.o.d"        -g -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/main/main_configuration.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/main/main_function.o: main/main_function.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/main" 
	@${RM} ${OBJECTDIR}/main/main_function.o.d 
	@${RM} ${OBJECTDIR}/main/main_function.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main/main_function.c  -o ${OBJECTDIR}/main/main_function.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main/main_function.o.d"        -g -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/main/main_function.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/main/main_interruptions.o: main/main_interruptions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/main" 
	@${RM} ${OBJECTDIR}/main/main_interruptions.o.d 
	@${RM} ${OBJECTDIR}/main/main_interruptions.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main/main_interruptions.c  -o ${OBJECTDIR}/main/main_interruptions.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main/main_interruptions.o.d"        -g -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/main/main_interruptions.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/main/traps_interruptions.o: main/traps_interruptions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/main" 
	@${RM} ${OBJECTDIR}/main/traps_interruptions.o.d 
	@${RM} ${OBJECTDIR}/main/traps_interruptions.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main/traps_interruptions.c  -o ${OBJECTDIR}/main/traps_interruptions.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main/traps_interruptions.o.d"        -g -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/main/traps_interruptions.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/sources/source_config_event_groups.o: sources/source_config_event_groups.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/sources" 
	@${RM} ${OBJECTDIR}/sources/source_config_event_groups.o.d 
	@${RM} ${OBJECTDIR}/sources/source_config_event_groups.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/source_config_event_groups.c  -o ${OBJECTDIR}/sources/source_config_event_groups.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/sources/source_config_event_groups.o.d"        -g -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/sources/source_config_event_groups.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/sources/source_config_mutex.o: sources/source_config_mutex.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/sources" 
	@${RM} ${OBJECTDIR}/sources/source_config_mutex.o.d 
	@${RM} ${OBJECTDIR}/sources/source_config_mutex.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/source_config_mutex.c  -o ${OBJECTDIR}/sources/source_config_mutex.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/sources/source_config_mutex.o.d"        -g -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/sources/source_config_mutex.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/sources/source_config_queues.o: sources/source_config_queues.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/sources" 
	@${RM} ${OBJECTDIR}/sources/source_config_queues.o.d 
	@${RM} ${OBJECTDIR}/sources/source_config_queues.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/source_config_queues.c  -o ${OBJECTDIR}/sources/source_config_queues.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/sources/source_config_queues.o.d"        -g -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/sources/source_config_queues.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/sources/source_config_tasks.o: sources/source_config_tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/sources" 
	@${RM} ${OBJECTDIR}/sources/source_config_tasks.o.d 
	@${RM} ${OBJECTDIR}/sources/source_config_tasks.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/source_config_tasks.c  -o ${OBJECTDIR}/sources/source_config_tasks.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/sources/source_config_tasks.o.d"        -g -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/sources/source_config_tasks.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/sources/source_config_timers.o: sources/source_config_timers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/sources" 
	@${RM} ${OBJECTDIR}/sources/source_config_timers.o.d 
	@${RM} ${OBJECTDIR}/sources/source_config_timers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/source_config_timers.c  -o ${OBJECTDIR}/sources/source_config_timers.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/sources/source_config_timers.o.d"        -g -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/sources/source_config_timers.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/system/list.o: system/list.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/system" 
	@${RM} ${OBJECTDIR}/system/list.o.d 
	@${RM} ${OBJECTDIR}/system/list.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system/list.c  -o ${OBJECTDIR}/system/list.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/system/list.o.d"        -g -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/system/list.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/system/queue.o: system/queue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/system" 
	@${RM} ${OBJECTDIR}/system/queue.o.d 
	@${RM} ${OBJECTDIR}/system/queue.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system/queue.c  -o ${OBJECTDIR}/system/queue.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/system/queue.o.d"        -g -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/system/queue.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/system/tasks.o: system/tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/system" 
	@${RM} ${OBJECTDIR}/system/tasks.o.d 
	@${RM} ${OBJECTDIR}/system/tasks.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system/tasks.c  -o ${OBJECTDIR}/system/tasks.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/system/tasks.o.d"        -g -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/system/tasks.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/system/timers.o: system/timers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/system" 
	@${RM} ${OBJECTDIR}/system/timers.o.d 
	@${RM} ${OBJECTDIR}/system/timers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system/timers.c  -o ${OBJECTDIR}/system/timers.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/system/timers.o.d"        -g -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/system/timers.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/system/portable/MemMang/heap_4.o: system/portable/MemMang/heap_4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/system/portable/MemMang" 
	@${RM} ${OBJECTDIR}/system/portable/MemMang/heap_4.o.d 
	@${RM} ${OBJECTDIR}/system/portable/MemMang/heap_4.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system/portable/MemMang/heap_4.c  -o ${OBJECTDIR}/system/portable/MemMang/heap_4.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/system/portable/MemMang/heap_4.o.d"        -g -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/system/portable/MemMang/heap_4.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/system/portable/PIC24_dsPIC/port.o: system/portable/PIC24_dsPIC/port.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/system/portable/PIC24_dsPIC" 
	@${RM} ${OBJECTDIR}/system/portable/PIC24_dsPIC/port.o.d 
	@${RM} ${OBJECTDIR}/system/portable/PIC24_dsPIC/port.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system/portable/PIC24_dsPIC/port.c  -o ${OBJECTDIR}/system/portable/PIC24_dsPIC/port.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/system/portable/PIC24_dsPIC/port.o.d"        -g -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/system/portable/PIC24_dsPIC/port.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/system/event_groups.o: system/event_groups.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/system" 
	@${RM} ${OBJECTDIR}/system/event_groups.o.d 
	@${RM} ${OBJECTDIR}/system/event_groups.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system/event_groups.c  -o ${OBJECTDIR}/system/event_groups.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/system/event_groups.o.d"        -g -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/system/event_groups.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/threads/thread_screen_menu.o: threads/thread_screen_menu.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/threads" 
	@${RM} ${OBJECTDIR}/threads/thread_screen_menu.o.d 
	@${RM} ${OBJECTDIR}/threads/thread_screen_menu.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  threads/thread_screen_menu.c  -o ${OBJECTDIR}/threads/thread_screen_menu.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/threads/thread_screen_menu.o.d"        -g -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/threads/thread_screen_menu.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/threads/threads_timer_system.o: threads/threads_timer_system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/threads" 
	@${RM} ${OBJECTDIR}/threads/threads_timer_system.o.d 
	@${RM} ${OBJECTDIR}/threads/threads_timer_system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  threads/threads_timer_system.c  -o ${OBJECTDIR}/threads/threads_timer_system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/threads/threads_timer_system.o.d"        -g -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -falign-arrays -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/threads/threads_timer_system.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/system/portable/PIC24_dsPIC/portasm_PIC24.o: system/portable/PIC24_dsPIC/portasm_PIC24.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/system/portable/PIC24_dsPIC" 
	@${RM} ${OBJECTDIR}/system/portable/PIC24_dsPIC/portasm_PIC24.o.d 
	@${RM} ${OBJECTDIR}/system/portable/PIC24_dsPIC/portasm_PIC24.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  system/portable/PIC24_dsPIC/portasm_PIC24.S  -o ${OBJECTDIR}/system/portable/PIC24_dsPIC/portasm_PIC24.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/system/portable/PIC24_dsPIC/portasm_PIC24.o.d"  -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc   -std=gnu99 -Wa,-MD,"${OBJECTDIR}/system/portable/PIC24_dsPIC/portasm_PIC24.o.asm.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_ICD4=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/system/portable/PIC24_dsPIC/portasm_PIC24.o.d" "${OBJECTDIR}/system/portable/PIC24_dsPIC/portasm_PIC24.o.asm.d"  -t $(SILENT)  -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/system/portable/PIC24_dsPIC/portasm_PIC24.o: system/portable/PIC24_dsPIC/portasm_PIC24.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/system/portable/PIC24_dsPIC" 
	@${RM} ${OBJECTDIR}/system/portable/PIC24_dsPIC/portasm_PIC24.o.d 
	@${RM} ${OBJECTDIR}/system/portable/PIC24_dsPIC/portasm_PIC24.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  system/portable/PIC24_dsPIC/portasm_PIC24.S  -o ${OBJECTDIR}/system/portable/PIC24_dsPIC/portasm_PIC24.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/system/portable/PIC24_dsPIC/portasm_PIC24.o.d"  -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc   -std=gnu99 -Wa,-MD,"${OBJECTDIR}/system/portable/PIC24_dsPIC/portasm_PIC24.o.asm.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/system/portable/PIC24_dsPIC/portasm_PIC24.o.d" "${OBJECTDIR}/system/portable/PIC24_dsPIC/portasm_PIC24.o.asm.d"  -t $(SILENT)  -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/GameCat_XC24H.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/GameCat_XC24H.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99  -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x825 -mreserve=data@0x826:0x84F   -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_ICD4=1,$(MP_LINKER_FILE_OPTION),--heap=32,--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp=${DFP_DIR}/xc16 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/GameCat_XC24H.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/GameCat_XC24H.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_GameCat_XC24H=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -std=gnu99 -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--heap=32,--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp=${DFP_DIR}/xc16 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/GameCat_XC24H.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp=${DFP_DIR}/xc16 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/GameCat_XC24H
	${RM} -r dist/GameCat_XC24H

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
