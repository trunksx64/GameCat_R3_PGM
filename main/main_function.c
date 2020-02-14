/* < Include ::: Headers > */
#include "main_fuses.h"
#include "source_config_system.h"

/* < Main :::: Function > */
int16_t main(void) {
    
    
    
    /* < Break ::: DEBUG > */
    pdNop();
    /* < Configuracion ::: Puertos y Reloj... > */
    vHardwareConfiguration();
    /* < - Configuracion - Drivers ---------------------------------------- > */
    /* < - Driver - ADC --------------------------------------------------- > */
    vConfigureADCConverter(ADC_INT_DISABLE | ADC_INT_PRI_7, ADC_MODULE_ON | ADC_IDLE_CONTINUE | ADC_ADDMABM_SCATTR | ADC_AD12B_10BIT | ADC_FORMAT_INTG | ADC_CLK_AUTO | ADC_MULTIPLE | ADC_AUTO_SAMPLING_OFF | ADC_SAMP_OFF, ADC_VREF_AVDD_AVSS | ADC_SCAN_OFF | ADC_SELECT_CHAN_0 | ADC_BUF_FILL_0x0_0x7 | ADC_SAMPLES_PER_INT_1 | ADC_ALT_BUF_OFF | ADC_ALT_INPUT_OFF, ADC_CONV_CLK_SYSTEM | ADC_SAMPLE_TIME_0 | ADC_CONV_CLK_3Tcy, ADC_DMA_BUF_LOC_1, ADC_CH123_NEG_SAMPLEB_NVREF | ADC_CH123_POS_SAMPLEB_0_1_2 | ADC_CH123_NEG_SAMPLEA_NVREF | ADC_CH123_POS_SAMPLEA_0_1_2, ADC_CH0_NEG_SAMPLEB_NVREF | ADC_CH0_POS_SAMPLEB_AN0 | ADC_CH0_NEG_SAMPLEA_NVREF | ADC_CH0_POS_SAMPLEA_AN0, SCAN_ALL & SELECT_SCAN_AN0, MASK_INPUTS_ALL_DIGITAL & ANALOG_AN00_ANA);
    /* < - Driver - CAN --------------------------------------------------- > */
    vConfigureCANModule(CAN_INT_ENABLE | CAN_INT_RX_ENABLE | CAN_INT_PRI_7, CAN_CAPTURE_DIS | CAN_IDLE_STOP | CAN_CLOCK_SOURCE_FCY, CAN_SYNC_JUMP_WIDTH1 | CAN_BAUD_PRE_SCALE(FCY, 0x08, 100000UL), CAN_WAKEUP_BY_FILTER_EN | CAN_PHASE_SEG2_3_TQ | CAN_SEG2_FREE_PROG | CAN_SAMPLE3TIMES | CAN_PHASE_SEG1_3_TQ | CAN_PROPAGATIONTIME_SEG_1_TQ, CAN_DMA_BUFFER_SIZE_8);
    /* < - Driver - CAN - Set Value To Maks ------------------------------- > */
    vCANModuleSetMaskSID(CAN_MASK_NUMBER_01, 0x0000); // < Write Value To Mask1           
    /* < - Driver - CAN - Set Value To Filters ---------------------------- > */
    vCANModuleSetFiltersSID(CAN_FILTER_NUMBER_01, 0x7FF); // < Write Value to Filter1    
    vCANModuleSetFiltersSID(CAN_FILTER_NUMBER_02, 0x7FF); // < Write Value to Filter2    
    vCANModuleSetFiltersSID(CAN_FILTER_NUMBER_03, 0x7FF); // < Write Value to Filter3    
    vCANModuleSetFiltersSID(CAN_FILTER_NUMBER_04, 0x7FF); // < Write Value to Filter4    
    vCANModuleSetFiltersSID(CAN_FILTER_NUMBER_05, 0x7FF); // < Write Value to Filter5    
    /* < - Driver - CAN - Selectec Mask to Filter Receive ----------------- > */
    vCANModuleSelectMaskToFilter(CAN_FILTER_NUMBER_01, CAN_MASK_NUMBER_01); // < Select Mask1 to Filter1   
    vCANModuleSelectMaskToFilter(CAN_FILTER_NUMBER_02, CAN_MASK_NUMBER_01); // < Select Mask1 to Filter2  
    vCANModuleSelectMaskToFilter(CAN_FILTER_NUMBER_03, CAN_MASK_NUMBER_01); // < Select Mask1 to Filter3  
    vCANModuleSelectMaskToFilter(CAN_FILTER_NUMBER_04, CAN_MASK_NUMBER_01); // < Select Mask1 to Filter4  
    vCANModuleSelectMaskToFilter(CAN_FILTER_NUMBER_05, CAN_MASK_NUMBER_01); // < Select Mask1 to Filter5  
    /* < - Driver - CAN - Set Filter to Bufers ---------------------------- > */
    vCANModuleSelectBufferToFilter(CAN_FILTER_NUMBER_01, CAN_BUFFER_CTRL_THREE); // < Set Filter1 to Buffer3
    vCANModuleSelectBufferToFilter(CAN_FILTER_NUMBER_02, CAN_BUFFER_CTRL_FOUR); // < Set Filter2 to Buffer4
    vCANModuleSelectBufferToFilter(CAN_FILTER_NUMBER_03, CAN_BUFFER_CTRL_FIVE); // < Set Filter3 to Buffer5
    vCANModuleSelectBufferToFilter(CAN_FILTER_NUMBER_04, CAN_BUFFER_CTRL_SIX); // < Set Filter3 to Buffer6
    vCANModuleSelectBufferToFilter(CAN_FILTER_NUMBER_05, CAN_BUFFER_CTRL_SEVEN); // < Set Filter3 to Buffer7
    /* < - Driver - CAN - Selectec Transmit Buffer ------------------------ > */
    vCANModuleConfigureBuffers(CAN_BUFFER_CTRL_ZERO, CAN_BUFFER_PRIORITY_HIGH, CAN_BUFFER_AS_TX); // < Buffer0 Like Transmission
    vCANModuleConfigureBuffers(CAN_BUFFER_CTRL_ONE, CAN_BUFFER_PRIORITY_HIGH, CAN_BUFFER_AS_TX); // < Buffer1 Like Transmission
    vCANModuleConfigureBuffers(CAN_BUFFER_CTRL_TWO, CAN_BUFFER_PRIORITY_HIGH, CAN_BUFFER_AS_TX); // < Buffer2 Like Transmission
    vCANModuleConfigureBuffers(CAN_BUFFER_CTRL_THREE, CAN_BUFFER_PRIORITY_HIGH, CAN_BUFFER_AS_RX); // < Buffer3 Like Receiving
    vCANModuleConfigureBuffers(CAN_BUFFER_CTRL_FOUR, CAN_BUFFER_PRIORITY_HIGH, CAN_BUFFER_AS_RX); // < Buffer4 Like Receiving        
    vCANModuleConfigureBuffers(CAN_BUFFER_CTRL_FIVE, CAN_BUFFER_PRIORITY_HIGH, CAN_BUFFER_AS_RX); // < Buffer5 Like Receiving 
    vCANModuleConfigureBuffers(CAN_BUFFER_CTRL_SIX, CAN_BUFFER_PRIORITY_HIGH, CAN_BUFFER_AS_RX); // < Buffer6 Like Receiving 
    vCANModuleConfigureBuffers(CAN_BUFFER_CTRL_SEVEN, CAN_BUFFER_PRIORITY_HIGH, CAN_BUFFER_AS_RX); // < Buffer7 Like Receiving     
    /* < - Driver - DMA0 - Set Send CAN ----------------------------------- > */
    vConfigureDMAZeroModule(DMA0_INT_DISABLE | DMA0_INT_PRI_7, DMA0_MODULE_ON | DMA0_SIZE_WORD | DMA0_TO_PERIPHERAL | DMA0_INTERRUPT_BLOCK | DMA0_NORMAL | DMA0_PERIPHERAL_ADDRESSING | DMA0_CONTINUOUS, 0x0046, __builtin_dmaoffset(&EcanBufferStorage), 0x0000, (volatile uint16_t) & C1TXD, 0x07);
    /* < - Driver - DMA1 - Set Receive CAN -------------------------------- > */
    vConfigureDMAOneModule(DMA1_INT_DISABLE | DMA1_INT_PRI_7, DMA1_MODULE_ON | DMA1_SIZE_WORD | PERIPHERAL_TO_DMA1 | DMA1_INTERRUPT_BLOCK | DMA1_NORMAL | DMA1_PERIPHERAL_ADDRESSING | DMA1_CONTINUOUS, 0x0022, __builtin_dmaoffset(&EcanBufferStorage), 0x0000, (volatile uint16_t) & C1RXD, 0x07);
    /* < - Driver - CRC Module -------------------------------------------- > */
    vConfigureCRCModule(CRC_INT_DISABLE | CRC_INT_PRI_0, CRC_IDLE_CON | CRC_POLYNOMIAL_LEN16, 0x1020); // < (Polynomy) x16 + x12 + x5 + 1    
    /* < - Driver - OC1 Module - PWM for LED GLCD - Timer2 ---------------- > */
    vConfigureOutputCompareModuleOne(OC1_INT_OFF | OC1_INT_PRIOR_0, OC1_IDLE_STOP | OC1_TIMER2_SRC | OC1_PWM_FAULT_PIN_DISABLE); /* < - Driver - CRC Module -------------------------------------------- > */    
    /* < - Driver - SPI1 - GLCD 3.3Mhz (4x3) -------------------------------- > */
    vConfigureSPIModuleOne(SPI1_INT_DISABLE | SPI1_INT_PRI_7, SPI1_ENABLE | SPI1_IDLE_STOP, SPI1_ENABLE_SCK_PIN | SPI1_ENABLE_SDO_PIN | SPI1_MODE_8BITS | SPI1_SMP_END | SPI1_CKE_1_TO_0 | SPI1_CLK_POL_HIGH | SPI1_MASTER_ENABLE_ON | SPI1_PRI_PRESCAL_1_4 | SPI1_SEC_PRESCAL_1_3, SPI1_FRAME_ENABLE_OFF);    
    /* < - Driver - TIMER2 - PWM For LED GLCD ----------------------------- > */
    vConfigureTimer2Module(T2_INT_OFF | T2_INT_PRIOR_7, T2_ON | T2_IDLE_STOP | T2_GATE_OFF | T2_PS_1_1 | T2_SOURCE_INT, 10000);        
    /* < - Driver - UART1 - USB FTRL32 ------------------------------------ > */
    vConfigureUartOne(UART1_INT_TX_DISABLE | UART1_INT_TX_PRI_7 | UART1_INT_RX_DISABLE | UART1_INT_RX_PRI_7, UART1_RX_ENABLE | UART1_IDLE_STOP | UART1_MODE_SIMPLEX | UART1_UEN_TX_RX | UART1_BRGH_FOUR | UART1_NO_PAR_8BIT, UART1_INT_TX_CHAR | UART1_TX_ENABLE | UART1_INT_RX_CHAR | UART1_RX_OVERRUN_CLEAR, 9600);
    /* < - Driver - UART2 - External -------------------------------------- > */
    vConfigureUartTwo(UART2_INT_TX_DISABLE | UART2_INT_TX_PRI_7 | UART2_INT_RX_DISABLE | UART2_INT_RX_PRI_7, UART2_RX_ENABLE | UART2_IDLE_STOP | UART2_MODE_SIMPLEX | UART2_UEN_TX_RX | UART2_BRGH_FOUR | UART2_NO_PAR_8BIT, UART2_INT_TX_CHAR | UART2_TX_ENABLE | UART2_INT_RX_CHAR | UART2_RX_OVERRUN_CLEAR, 9600);
    /* < - Configuracion - Libraries -------------------------------------- > */
    /* < - Library - GLCD - PCD8544 --------------------------------------- > */
    vConfigureGLCD(64, GLCD_TEMP_C_2, GLCD_BIAS_1_48);
    /* < - Library - Joystick --------------------------------------------- > */
    vJoystickConfiguration();
    /* < - Library - Font - Config ---------------------------------------- > */
    vSelectSetFont(Arial5x7, 5, 7);
    /* < - Rtos ----------------------------------------------------------- > */
    vPortInitialiseBlocks(); // < Initialise ::: Block Memory
    vConfigurationEventGroups(); // < Configure ::: Flags 
    vConfigurationMutexes(); // < Configure ::: Mutexes
    vConfigurationQueues(); // < Configure ::: Queues
    vConfigurationTimers(); // < Configure ::: Timers
    vConfigurationTasks(); // < Configure ::: Tasks
    vTaskStartScheduler(); // < Start the scheduler
    /* < Exit ::: Main Function... > */
    return (EXIT_FAILURE);
}