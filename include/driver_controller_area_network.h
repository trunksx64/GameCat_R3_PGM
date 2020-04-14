#ifndef DRIVER_CONTROLLER_AREA_NETWORK_H
#define	DRIVER_CONTROLLER_AREA_NETWORK_H

/* < Configuration Main Settings > */
#include "main_typedefs.h"
#include "main_delays.h"

/* < Definicion ::: Typedef > */
typedef struct {
    uint32_t ID; /* 29 bit ID max of 0x1FFF FFFF / 11 bit ID max of 0x7FF */
    uint8_t DataLength;
    uint8_t Data[8];
    uint8_t MessageType; /* RTR message or Data Message */
    uint8_t FrameType; /* Frame Type Extended or Standard */
    uint8_t Buffer; /* Buffer being used to Send and Receive Messages */
} xMessegeECAN;

/* < Definicion ::: ECAN message buffer length > */
#define CAN_BUFFER_LENGTH               8

/* < Definicion ::: Pines de Control :: CAN_MODULE_ONE > */
#define TRIS_CAN_TX                     TRISBbits.TRISB5
#define TRIS_CAN_RX                     TRISCbits.TRISC5

/* < Definicion ::: Configuracion INT :: CAN_MODULE : Interruption > */
#define CAN_INT_ENABLE                  0x80     // < enable / disable interrupts
#define CAN_INT_DISABLE                 0x00
#define CAN_INT_TX_ENABLE               0x40
#define CAN_INT_TX_DISABLE              0x00
#define CAN_INT_RX_ENABLE               0x20
#define CAN_INT_RX_DISABLE              0x00

#define CAN_INT_PRI_0                   0x00  // < Setting the priority of adc interrupt
#define CAN_INT_PRI_1                   0x01
#define CAN_INT_PRI_2                   0x02
#define CAN_INT_PRI_3                   0x03
#define CAN_INT_PRI_4                   0x04
#define CAN_INT_PRI_5                   0x05
#define CAN_INT_PRI_6                   0x06
#define CAN_INT_PRI_7                   0x07

/* < Macros ::: Control de Interrupciones ::: CAN_MODULE > */
#define EnableIntCAN()                  IEC2bits.C1IE = pdSet
#define DisableIntCAN()                 IEC2bits.C1IE = pdClear
#define SetPriorityIntCAN(Priority)     IPC8bits.C1IP = (Priority)

/* < Definicion ::: Configuracion 1 :: CAN_MODULE : C1CTRL1 : Config > */
#define CAN_CAPTURE_EN                  0x0008  /* Enable input capture based on CAN message receive */
#define CAN_CAPTURE_DIS                 0x0000  /* Disable CAN capture */

#define CAN_IDLE_STOP                   0x2000  /* Discontinue module operation when device enters Idle mode */
#define CAN_IDLE_CON                    0x0000  /* Continue module operation in Idle mode */

#define CAN_CLOCK_SOURCE_FOS            0x0000  /* FCAN is selected to be FOS */
#define CAN_CLOCK_SOURCE_FCY            0x0800  /* FCAN is selected to be FCY */

/* < Definicion ::: Configuracion 1 :: CAN_MODULE : C1CTRL1 : REQOP Settings > */
#define CAN_REQ_OPERMODE_NORMAL         0x00  /* Module is in Normal Operation mode */
#define CAN_REQ_OPERMODE_DISABLE        0x01  /* Module is in Disable mode */
#define CAN_REQ_OPERMODE_LOOPBK         0x02  /* Module is in Loopback mode */
#define CAN_REQ_OPERMODE_LISTENONLY     0x03  /* Module is in Listen Only mode */
#define CAN_REQ_OPERMODE_CONFIG         0x04  /* Module is in Configuration mode */
#define CAN_REQ_OPERMODE_LISTENALL      0x07  /* Module is in Listen All Messages mode */

/* < Definicion ::: Configuracion 2 :: CAN_MODULE : C1CFG1 : SyncBRP > */
#define CAN_SYNC_JUMP_WIDTH1            0x0000  /* Synchronization Jump Width bits */
#define CAN_SYNC_JUMP_WIDTH2            0x0040
#define CAN_SYNC_JUMP_WIDTH3            0x0080
#define CAN_SYNC_JUMP_WIDTH4            0x00C0

#define CAN_BAUD_PRE_SCALE(F,N,B)       (((F/(0x02*N*B))-0x01)&0x3F) // < ((FCAN/(2*Ntq*Birate))-1) 

/* < Definicion ::: Configuracion 3 :: CAN_MODULE : C1CFG2 : WakePhaseSamProp > */
#define CAN_WAKEUP_BY_FILTER_EN         0x4000  /* Use CAN bus line filter for wake-up */
#define CAN_WAKEUP_BY_FILTER_DIS        0x0000  /* CAN bus line filter is not used for wake-up */

#define CAN_PHASE_SEG2_8_TQ             0x0700  /* Phase Segment 2 - Length is 8 x TQ */
#define CAN_PHASE_SEG2_7_TQ             0x0600  /* Phase Segment 2 - Length is 7 x TQ */
#define CAN_PHASE_SEG2_6_TQ             0x0500  /* Phase Segment 2 - Length is 6 x TQ */
#define CAN_PHASE_SEG2_5_TQ             0x0400  /* Phase Segment 2 - Length is 5 x TQ */
#define CAN_PHASE_SEG2_4_TQ             0x0300  /* Phase Segment 2 - Length is 4 x TQ */
#define CAN_PHASE_SEG2_3_TQ             0x0200  /* Phase Segment 2 - Length is 3 x TQ */
#define CAN_PHASE_SEG2_2_TQ             0x0100  /* Phase Segment 2 - Length is 2 x TQ */
#define CAN_PHASE_SEG2_1_TQ             0x0000  /* Phase Segment 2 - Length is 1 x TQ */

#define CAN_SEG2_FREE_PROG              0x0080  /* Freely programmable */
#define CAN_SEG2_TIME_LIMIT_SET         0x0000  /* Maximum of SEG1PH bits or Information Processing Time (IPT), whichever is greater */

#define CAN_SAMPLE3TIMES                0x0040  /* Bus line is sampled three times at the sample point */
#define CAN_SAMPLE1TIME                 0x0000  /* Bus line is sampled once at the sample point */

#define CAN_PHASE_SEG1_8_TQ             0x0038  /* Phase Segment 1 - Length is 8 x TQ */
#define CAN_PHASE_SEG1_7_TQ             0x0030  /* Phase Segment 1 - Length is 7 x TQ */
#define CAN_PHASE_SEG1_6_TQ             0x0028  /* Phase Segment 1 - Length is 6 x TQ */
#define CAN_PHASE_SEG1_5_TQ             0x0020  /* Phase Segment 1 - Length is 5 x TQ */
#define CAN_PHASE_SEG1_4_TQ             0x0018  /* Phase Segment 1 - Length is 4 x TQ */
#define CAN_PHASE_SEG1_3_TQ             0x0010  /* Phase Segment 1 - Length is 3 x TQ */
#define CAN_PHASE_SEG1_2_TQ             0x0008  /* Phase Segment 1 - Length is 2 x TQ */
#define CAN_PHASE_SEG1_1_TQ             0x0000  /* Phase Segment 1 - Length is 1 x TQ */

#define CAN_PROPAGATIONTIME_SEG_8_TQ    0x0007  /* Propagation Time Segment - Length is 8 x TQ */
#define CAN_PROPAGATIONTIME_SEG_7_TQ    0x0006  /* Propagation Time Segment - Length is 7 x TQ */
#define CAN_PROPAGATIONTIME_SEG_6_TQ    0x0005  /* Propagation Time Segment - Length is 6 x TQ */
#define CAN_PROPAGATIONTIME_SEG_5_TQ    0x0004  /* Propagation Time Segment - Length is 5 x TQ */
#define CAN_PROPAGATIONTIME_SEG_4_TQ    0x0003  /* Propagation Time Segment - Length is 4 x TQ */
#define CAN_PROPAGATIONTIME_SEG_3_TQ    0x0002  /* Propagation Time Segment - Length is 3 x TQ */
#define CAN_PROPAGATIONTIME_SEG_2_TQ    0x0001  /* Propagation Time Segment - Length is 2 x TQ */
#define CAN_PROPAGATIONTIME_SEG_1_TQ    0x0000  /* Propagation Time Segment - Length is 1 x TQ */

/* < Definicion ::: Tamaño Buffer DMA :: DMA_Buffer > */
#define CAN_DMA_BUFFER_SIZE_4           0x00
#define CAN_DMA_BUFFER_SIZE_6           0x01
#define CAN_DMA_BUFFER_SIZE_8           0x02
#define CAN_DMA_BUFFER_SIZE_12          0x03
#define CAN_DMA_BUFFER_SIZE_16          0x04
#define CAN_DMA_BUFFER_SIZE_24          0x05
#define CAN_DMA_BUFFER_SIZE_32          0x06

/* < Macros ::: Control de Identificacion ::: CAN_MODULE > */
#define CAN_FRAME_STD                   0x01
#define CAN_FRAME_EXT                   0x02
#define CAN_MSG_DATA                    0x03
#define CAN_MSG_RTR                     0x04

/* < Macros ::: Numeracion de Buffers ::: CAN_MODULE > */
#define CAN_BUFFER_CTRL_00              0x00
#define CAN_BUFFER_CTRL_01              0x01
#define CAN_BUFFER_CTRL_02              0x02
#define CAN_BUFFER_CTRL_03              0x03
#define CAN_BUFFER_CTRL_04              0x04
#define CAN_BUFFER_CTRL_05              0x05
#define CAN_BUFFER_CTRL_06              0x06
#define CAN_BUFFER_CTRL_07              0x07

#define CAN_BUFFER_AS_RX                0x00
#define CAN_BUFFER_AS_TX                0x01

#define CAN_BUFFER_PRIORITY_04          0x03
#define CAN_BUFFER_PRIORITY_03          0x02
#define CAN_BUFFER_PRIORITY_02          0x01
#define CAN_BUFFER_PRIORITY_01          0x00

/* < Macros ::: Numeracion de Maks ::: CAN_MODULE > */
#define CAN_MASK_NUMBER_00              0x00
#define CAN_MASK_NUMBER_01              0x01
#define CAN_MASK_NUMBER_02              0x02

/* < Macros ::: Numeracion de Filters ::: CAN_MODULE > */
#define CAN_FILTER_NUMBER_00            0x00
#define CAN_FILTER_NUMBER_01            0x01
#define CAN_FILTER_NUMBER_02            0x02
#define CAN_FILTER_NUMBER_03            0x03   
#define CAN_FILTER_NUMBER_04            0x04
#define CAN_FILTER_NUMBER_05            0x05
#define CAN_FILTER_NUMBER_06            0x06
#define CAN_FILTER_NUMBER_07            0x07
#define CAN_FILTER_NUMBER_08            0x08
#define CAN_FILTER_NUMBER_09            0x09
#define CAN_FILTER_NUMBER_10            0x0A
#define CAN_FILTER_NUMBER_11            0x0B
#define CAN_FILTER_NUMBER_12            0x0C
#define CAN_FILTER_NUMBER_13            0x0D
#define CAN_FILTER_NUMBER_14            0x0E
#define CAN_FILTER_NUMBER_15            0x0F

/* < Macros ::: Control de Mensajes ::: CAN_MODULE > */
#define CAN_FILTERMASK2REG_SID(x)       ((x & 0x07FF)<<0x05)                // Use for Standard Messages Only in CiRXMnSID
#define CAN_SETMIDE(SID)                (SID | 0x0008)                      // The Macro will set the MIDE bit in CiRXMxSID
#define CAN_FILTERSTD(SID)              (SID & 0xFFF7)                      // The macro will clear the EXIDE bit in CiRXFxSID to only accept standard messages
#define CAN_FILTERXTD(SID)              (SID | 0x0008)                      // The Macro will set the EXIDE bit in CiRXFxSID to only accept extended messages
#define CAN_FILTERMASK2REG_EID0(X)      (X & 0xFFFF)                        // Macro used to write filter/mask ID to Register CiRXMxSID, CiRXMxEID, CiRXFxSID and CiRXFxEID
#define CAN_FILTERMASK2REG_EID1(X)      (((X & 0x1FFC)<<0x03)|(X & 0x03))   // Macro used to write filter/mask ID to Register CiRXMxSID, CiRXMxEID, CiRXFxSID and CiRXFxEID

/* < Extern ::: Globales ::: Memoria DMA... > */
extern uint16_t EcanBufferStorage[CAN_BUFFER_LENGTH][8] __attribute__((space(dma), aligned(CAN_BUFFER_LENGTH * 16)));

/* < Prototipo ::: Funciones de Control ::: CAN_MODULE > */
void vConfigureCANModule(uint8_t Interrupt, uint16_t Config, uint16_t SyncBRP, uint16_t BaudRate_2, uint8_t SizeBufferDMA);
void vCANModuleConfigureBuffers(uint8_t SetBuffers, uint8_t Priority, uint8_t Selection);
void vCANModuleSelectMaskToFilter(uint8_t Filter, uint8_t Mask);
void vCANModuleSetMaskSID(uint8_t Mask, uint16_t SID);
void vCANModuleSetFiltersSID(uint8_t Filter, uint16_t SID);
void vCANModuleSetMaskXTD(uint8_t Mask, uint32_t XTD);
void vCANModuleSetFiltersXTD(uint8_t Filter, uint32_t XTD);
void vCANModuleSelectBufferToFilter(uint8_t Filter, uint8_t Buffer);
void vCANModuleSetSendTransmission(uint8_t BufferNumber);
uint1_t xSetModeOperation(uint8_t Mode);
uint8_t xCANModuleClearReceiveFlags(void);
void vCANModuleSendMessege(xMessegeECAN *Message);
void vCANModuleReceiveMessege(xMessegeECAN *Message);

#endif	/* < DRIVER_CONTROLLER_AREA_NETWORK_H > */

