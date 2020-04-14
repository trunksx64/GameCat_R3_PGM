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
ifeq "$(wildcard nbproject/Makefile-local-GameCat_R3_PGM.mk)" "nbproject/Makefile-local-GameCat_R3_PGM.mk"
include nbproject/Makefile-local-GameCat_R3_PGM.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=GameCat_R3_PGM
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/GameCat_R3_PGM.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/GameCat_R3_PGM.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=drivers/driver_controller_area_network.c drivers/driver_direct_memory_access.c main/main_function.c main/main_configuration.c system/list.c system/queue.c system/tasks.c system/portable/MemMang/heap_1.c system/portable/PIC24_dsPIC/port.c system/portable/PIC24_dsPIC/portasm_PIC24.S

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/drivers/driver_controller_area_network.o ${OBJECTDIR}/drivers/driver_direct_memory_access.o ${OBJECTDIR}/main/main_function.o ${OBJECTDIR}/main/main_configuration.o ${OBJECTDIR}/system/list.o ${OBJECTDIR}/system/queue.o ${OBJECTDIR}/system/tasks.o ${OBJECTDIR}/system/portable/MemMang/heap_1.o ${OBJECTDIR}/system/portable/PIC24_dsPIC/port.o ${OBJECTDIR}/system/portable/PIC24_dsPIC/portasm_PIC24.o
POSSIBLE_DEPFILES=${OBJECTDIR}/drivers/driver_controller_area_network.o.d ${OBJECTDIR}/drivers/driver_direct_memory_access.o.d ${OBJECTDIR}/main/main_function.o.d ${OBJECTDIR}/main/main_configuration.o.d ${OBJECTDIR}/system/list.o.d ${OBJECTDIR}/system/queue.o.d ${OBJECTDIR}/system/tasks.o.d ${OBJECTDIR}/system/portable/MemMang/heap_1.o.d ${OBJECTDIR}/system/portable/PIC24_dsPIC/port.o.d ${OBJECTDIR}/system/portable/PIC24_dsPIC/portasm_PIC24.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/drivers/driver_controller_area_network.o ${OBJECTDIR}/drivers/driver_direct_memory_access.o ${OBJECTDIR}/main/main_function.o ${OBJECTDIR}/main/main_configuration.o ${OBJECTDIR}/system/list.o ${OBJECTDIR}/system/queue.o ${OBJECTDIR}/system/tasks.o ${OBJECTDIR}/system/portable/MemMang/heap_1.o ${OBJECTDIR}/system/portable/PIC24_dsPIC/port.o ${OBJECTDIR}/system/portable/PIC24_dsPIC/portasm_PIC24.o

# Source Files
SOURCEFILES=drivers/driver_controller_area_network.c drivers/driver_direct_memory_access.c main/main_function.c main/main_configuration.c system/list.c system/queue.c system/tasks.c system/portable/MemMang/heap_1.c system/portable/PIC24_dsPIC/port.c system/portable/PIC24_dsPIC/portasm_PIC24.S



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
	${MAKE}  -f nbproject/Makefile-GameCat_R3_PGM.mk dist/${CND_CONF}/${IMAGE_TYPE}/GameCat_R3_PGM.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24HJ128GP504
MP_LINKER_FILE_OPTION=,--script=p24HJ128GP504.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/drivers/driver_controller_area_network.o: drivers/driver_controller_area_network.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/driver_controller_area_network.o.d 
	@${RM} ${OBJECTDIR}/drivers/driver_controller_area_network.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  drivers/driver_controller_area_network.c  -o ${OBJECTDIR}/drivers/driver_controller_area_network.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/drivers/driver_controller_area_network.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_R3_PGM=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/drivers/driver_controller_area_network.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/drivers/driver_direct_memory_access.o: drivers/driver_direct_memory_access.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/driver_direct_memory_access.o.d 
	@${RM} ${OBJECTDIR}/drivers/driver_direct_memory_access.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  drivers/driver_direct_memory_access.c  -o ${OBJECTDIR}/drivers/driver_direct_memory_access.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/drivers/driver_direct_memory_access.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_R3_PGM=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/drivers/driver_direct_memory_access.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/main/main_function.o: main/main_function.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/main" 
	@${RM} ${OBJECTDIR}/main/main_function.o.d 
	@${RM} ${OBJECTDIR}/main/main_function.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main/main_function.c  -o ${OBJECTDIR}/main/main_function.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main/main_function.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_R3_PGM=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/main/main_function.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/main/main_configuration.o: main/main_configuration.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/main" 
	@${RM} ${OBJECTDIR}/main/main_configuration.o.d 
	@${RM} ${OBJECTDIR}/main/main_configuration.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main/main_configuration.c  -o ${OBJECTDIR}/main/main_configuration.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main/main_configuration.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_R3_PGM=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/main/main_configuration.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/system/list.o: system/list.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/system" 
	@${RM} ${OBJECTDIR}/system/list.o.d 
	@${RM} ${OBJECTDIR}/system/list.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system/list.c  -o ${OBJECTDIR}/system/list.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/system/list.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_R3_PGM=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/system/list.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/system/queue.o: system/queue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/system" 
	@${RM} ${OBJECTDIR}/system/queue.o.d 
	@${RM} ${OBJECTDIR}/system/queue.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system/queue.c  -o ${OBJECTDIR}/system/queue.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/system/queue.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_R3_PGM=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/system/queue.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/system/tasks.o: system/tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/system" 
	@${RM} ${OBJECTDIR}/system/tasks.o.d 
	@${RM} ${OBJECTDIR}/system/tasks.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system/tasks.c  -o ${OBJECTDIR}/system/tasks.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/system/tasks.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_R3_PGM=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/system/tasks.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/system/portable/MemMang/heap_1.o: system/portable/MemMang/heap_1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/system/portable/MemMang" 
	@${RM} ${OBJECTDIR}/system/portable/MemMang/heap_1.o.d 
	@${RM} ${OBJECTDIR}/system/portable/MemMang/heap_1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system/portable/MemMang/heap_1.c  -o ${OBJECTDIR}/system/portable/MemMang/heap_1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/system/portable/MemMang/heap_1.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_R3_PGM=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/system/portable/MemMang/heap_1.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/system/portable/PIC24_dsPIC/port.o: system/portable/PIC24_dsPIC/port.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/system/portable/PIC24_dsPIC" 
	@${RM} ${OBJECTDIR}/system/portable/PIC24_dsPIC/port.o.d 
	@${RM} ${OBJECTDIR}/system/portable/PIC24_dsPIC/port.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system/portable/PIC24_dsPIC/port.c  -o ${OBJECTDIR}/system/portable/PIC24_dsPIC/port.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/system/portable/PIC24_dsPIC/port.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_GameCat_R3_PGM=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/system/portable/PIC24_dsPIC/port.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/drivers/driver_controller_area_network.o: drivers/driver_controller_area_network.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/driver_controller_area_network.o.d 
	@${RM} ${OBJECTDIR}/drivers/driver_controller_area_network.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  drivers/driver_controller_area_network.c  -o ${OBJECTDIR}/drivers/driver_controller_area_network.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/drivers/driver_controller_area_network.o.d"        -omf=elf -DXPRJ_GameCat_R3_PGM=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/drivers/driver_controller_area_network.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/drivers/driver_direct_memory_access.o: drivers/driver_direct_memory_access.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/driver_direct_memory_access.o.d 
	@${RM} ${OBJECTDIR}/drivers/driver_direct_memory_access.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  drivers/driver_direct_memory_access.c  -o ${OBJECTDIR}/drivers/driver_direct_memory_access.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/drivers/driver_direct_memory_access.o.d"        -omf=elf -DXPRJ_GameCat_R3_PGM=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/drivers/driver_direct_memory_access.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/main/main_function.o: main/main_function.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/main" 
	@${RM} ${OBJECTDIR}/main/main_function.o.d 
	@${RM} ${OBJECTDIR}/main/main_function.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main/main_function.c  -o ${OBJECTDIR}/main/main_function.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main/main_function.o.d"        -omf=elf -DXPRJ_GameCat_R3_PGM=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/main/main_function.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/main/main_configuration.o: main/main_configuration.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/main" 
	@${RM} ${OBJECTDIR}/main/main_configuration.o.d 
	@${RM} ${OBJECTDIR}/main/main_configuration.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main/main_configuration.c  -o ${OBJECTDIR}/main/main_configuration.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main/main_configuration.o.d"        -omf=elf -DXPRJ_GameCat_R3_PGM=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/main/main_configuration.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/system/list.o: system/list.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/system" 
	@${RM} ${OBJECTDIR}/system/list.o.d 
	@${RM} ${OBJECTDIR}/system/list.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system/list.c  -o ${OBJECTDIR}/system/list.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/system/list.o.d"        -omf=elf -DXPRJ_GameCat_R3_PGM=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/system/list.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/system/queue.o: system/queue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/system" 
	@${RM} ${OBJECTDIR}/system/queue.o.d 
	@${RM} ${OBJECTDIR}/system/queue.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system/queue.c  -o ${OBJECTDIR}/system/queue.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/system/queue.o.d"        -omf=elf -DXPRJ_GameCat_R3_PGM=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/system/queue.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/system/tasks.o: system/tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/system" 
	@${RM} ${OBJECTDIR}/system/tasks.o.d 
	@${RM} ${OBJECTDIR}/system/tasks.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system/tasks.c  -o ${OBJECTDIR}/system/tasks.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/system/tasks.o.d"        -omf=elf -DXPRJ_GameCat_R3_PGM=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/system/tasks.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/system/portable/MemMang/heap_1.o: system/portable/MemMang/heap_1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/system/portable/MemMang" 
	@${RM} ${OBJECTDIR}/system/portable/MemMang/heap_1.o.d 
	@${RM} ${OBJECTDIR}/system/portable/MemMang/heap_1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system/portable/MemMang/heap_1.c  -o ${OBJECTDIR}/system/portable/MemMang/heap_1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/system/portable/MemMang/heap_1.o.d"        -omf=elf -DXPRJ_GameCat_R3_PGM=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/system/portable/MemMang/heap_1.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/system/portable/PIC24_dsPIC/port.o: system/portable/PIC24_dsPIC/port.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/system/portable/PIC24_dsPIC" 
	@${RM} ${OBJECTDIR}/system/portable/PIC24_dsPIC/port.o.d 
	@${RM} ${OBJECTDIR}/system/portable/PIC24_dsPIC/port.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system/portable/PIC24_dsPIC/port.c  -o ${OBJECTDIR}/system/portable/PIC24_dsPIC/port.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/system/portable/PIC24_dsPIC/port.o.d"        -omf=elf -DXPRJ_GameCat_R3_PGM=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/system/portable/PIC24_dsPIC/port.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
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
	${MP_CC} $(MP_EXTRA_AS_PRE)  system/portable/PIC24_dsPIC/portasm_PIC24.S  -o ${OBJECTDIR}/system/portable/PIC24_dsPIC/portasm_PIC24.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/system/portable/PIC24_dsPIC/portasm_PIC24.o.d"  -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -omf=elf -DXPRJ_GameCat_R3_PGM=$(CND_CONF)  -legacy-libc  -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -Wa,-MD,"${OBJECTDIR}/system/portable/PIC24_dsPIC/portasm_PIC24.o.asm.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_ICD4=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/system/portable/PIC24_dsPIC/portasm_PIC24.o.d" "${OBJECTDIR}/system/portable/PIC24_dsPIC/portasm_PIC24.o.asm.d"  -t $(SILENT)  -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/system/portable/PIC24_dsPIC/portasm_PIC24.o: system/portable/PIC24_dsPIC/portasm_PIC24.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/system/portable/PIC24_dsPIC" 
	@${RM} ${OBJECTDIR}/system/portable/PIC24_dsPIC/portasm_PIC24.o.d 
	@${RM} ${OBJECTDIR}/system/portable/PIC24_dsPIC/portasm_PIC24.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  system/portable/PIC24_dsPIC/portasm_PIC24.S  -o ${OBJECTDIR}/system/portable/PIC24_dsPIC/portasm_PIC24.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/system/portable/PIC24_dsPIC/portasm_PIC24.o.d"  -omf=elf -DXPRJ_GameCat_R3_PGM=$(CND_CONF)  -legacy-libc  -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -Wa,-MD,"${OBJECTDIR}/system/portable/PIC24_dsPIC/portasm_PIC24.o.asm.d",--defsym=__MPLAB_BUILD=1,--no-relax$(MP_EXTRA_AS_POST)  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/system/portable/PIC24_dsPIC/portasm_PIC24.o.d" "${OBJECTDIR}/system/portable/PIC24_dsPIC/portasm_PIC24.o.asm.d"  -t $(SILENT)  -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/GameCat_R3_PGM.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/GameCat_R3_PGM.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -omf=elf -DXPRJ_GameCat_R3_PGM=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC"  -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x825 -mreserve=data@0x826:0x84F   -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_ICD4=1,$(MP_LINKER_FILE_OPTION),--heap=16,--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp=${DFP_DIR}/xc16 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/GameCat_R3_PGM.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/GameCat_R3_PGM.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_GameCat_R3_PGM=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"include" -I"drivers" -I"libraries" -I"controls" -I"main" -I"sources" -I"threads" -I"system" -I"system/include" -I"system/portable/MemMang" -I"system/portable/PIC24_dsPIC" -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--heap=16,--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp=${DFP_DIR}/xc16 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/GameCat_R3_PGM.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp=${DFP_DIR}/xc16 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/GameCat_R3_PGM
	${RM} -r dist/GameCat_R3_PGM

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
