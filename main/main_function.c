/* < Include ::: Headers > */
#include "main_fuses.h"
#include "main_configuration.h"

/* < Main :::: Function > */
int16_t main(void) {
    /* < Break ::: DEBUG > */
    pdNop();
    /* < Configuracion ::: Puertos y Reloj... > */
    vHardwareConfiguration();
    /* < Select ::: Configure Mode - CAN ---------------------------------- > */
    xSetModeOperation(CAN_REQ_OPERMODE_CONFIG);
    /* < Configure ::: Drivers - DMA - CAN -------------------------------- > */
    vConfigureCANModule(CAN_INT_ENABLE | CAN_INT_RX_ENABLE | CAN_INT_PRI_7, CAN_CAPTURE_DIS | CAN_IDLE_STOP | CAN_CLOCK_SOURCE_FCY, CAN_SYNC_JUMP_WIDTH1 | CAN_BAUD_PRE_SCALE(FCY, 0x08, 100000UL), CAN_WAKEUP_BY_FILTER_EN | CAN_PHASE_SEG2_3_TQ | CAN_SEG2_FREE_PROG | CAN_SAMPLE3TIMES | CAN_PHASE_SEG1_3_TQ | CAN_PROPAGATIONTIME_SEG_1_TQ, CAN_DMA_BUFFER_SIZE_8);
    /* < - Driver - CAN - Set Value To Maks ------------------------------- > */
    vCANModuleSetMaskSID(CAN_MASK_NUMBER_01, 0x0000);
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
    vCANModuleSelectBufferToFilter(CAN_FILTER_NUMBER_01, CAN_BUFFER_CTRL_03); // < Set Filter1 to Buffer3
    vCANModuleSelectBufferToFilter(CAN_FILTER_NUMBER_02, CAN_BUFFER_CTRL_04); // < Set Filter2 to Buffer4
    vCANModuleSelectBufferToFilter(CAN_FILTER_NUMBER_03, CAN_BUFFER_CTRL_05); // < Set Filter3 to Buffer5
    vCANModuleSelectBufferToFilter(CAN_FILTER_NUMBER_04, CAN_BUFFER_CTRL_06); // < Set Filter3 to Buffer6
    vCANModuleSelectBufferToFilter(CAN_FILTER_NUMBER_05, CAN_BUFFER_CTRL_07); // < Set Filter3 to Buffer7
    /* < - Driver - CAN - Select Transmit Buffer -------------------------- > */
    vCANModuleConfigureBuffers(CAN_BUFFER_CTRL_00, CAN_BUFFER_PRIORITY_04, CAN_BUFFER_AS_TX); // < Buffer0 Like Transmission
    vCANModuleConfigureBuffers(CAN_BUFFER_CTRL_01, CAN_BUFFER_PRIORITY_04, CAN_BUFFER_AS_TX); // < Buffer1 Like Transmission
    vCANModuleConfigureBuffers(CAN_BUFFER_CTRL_02, CAN_BUFFER_PRIORITY_04, CAN_BUFFER_AS_TX); // < Buffer2 Like Transmission
    vCANModuleConfigureBuffers(CAN_BUFFER_CTRL_03, CAN_BUFFER_PRIORITY_04, CAN_BUFFER_AS_RX); // < Buffer3 Like Receiving
    vCANModuleConfigureBuffers(CAN_BUFFER_CTRL_04, CAN_BUFFER_PRIORITY_04, CAN_BUFFER_AS_RX); // < Buffer4 Like Receiving        
    vCANModuleConfigureBuffers(CAN_BUFFER_CTRL_05, CAN_BUFFER_PRIORITY_04, CAN_BUFFER_AS_RX); // < Buffer5 Like Receiving 
    vCANModuleConfigureBuffers(CAN_BUFFER_CTRL_06, CAN_BUFFER_PRIORITY_04, CAN_BUFFER_AS_RX); // < Buffer6 Like Receiving 
    vCANModuleConfigureBuffers(CAN_BUFFER_CTRL_07, CAN_BUFFER_PRIORITY_04, CAN_BUFFER_AS_RX); // < Buffer7 Like Receiving     
    /* < Select ::: Normal Mode - CAN ---------------------------------- > */
    xSetModeOperation(CAN_REQ_OPERMODE_NORMAL);
    /* < Configure ::: Drivers - DMA - FOR CAN ---------------------------- > */
    vConfigureDMAZeroModule(DMA_INT_ENABLE | DMA_INT_PRI_7, DMA_MODULE_ON | DMA_SIZE_WORD | DMA_TO_PERIPHERAL | DMA_INTERRUPT_BLOCK | DMA_NORMAL | DMA_PERIPHERAL_ADDRESSING | DMA_CONTINUOUS, 0x0046, __builtin_dmaoffset(&EcanBufferStorage), 0x0000, (volatile uint16_t) & C1TXD, 0x07);
    vConfigureDMAOneModule(DMA_INT_DISABLE | DMA_INT_PRI_7, DMA_MODULE_ON | DMA_SIZE_WORD | PERIPHERAL_TO_DMA | DMA_INTERRUPT_BLOCK | DMA_NORMAL | DMA_PERIPHERAL_ADDRESSING | DMA_CONTINUOUS, 0x0022, __builtin_dmaoffset(&EcanBufferStorage), 0x0000, (volatile uint16_t) & C1RXD, 0x07);


    /* < Exit ::: Main Function... > */
    return (EXIT_FAILURE);
}
