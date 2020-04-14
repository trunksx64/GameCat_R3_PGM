#ifndef DRIVER_DIRECT_MEMORY_ACCESS_ONE_H
#define	DRIVER_DIRECT_MEMORY_ACCESS_ONE_H

/* < Configuration Main Settings > */
#include "main_typedefs.h"
#include "main_delays.h"

/* < Definicion ::: Interrupts :: DMA > */
#define DMA_INT_ENABLE                  0x80
#define DMA_INT_DISABLE                 0x00

/* < Definicion ::: Interrupts Priority :: DMA > */
#define DMA_INT_PRI_0                   0x00
#define DMA_INT_PRI_1                   0x01
#define DMA_INT_PRI_2                   0x02
#define DMA_INT_PRI_3                   0x03
#define DMA_INT_PRI_4                   0x04
#define DMA_INT_PRI_5                   0x05
#define DMA_INT_PRI_6                   0x06
#define DMA_INT_PRI_7                   0x07

/* < Definicion ::: Configuracion :: DMA : DMAxCON : Config > */
#define DMA_MODULE_ON                   0x8000 /* DMA on */
#define DMA_MODULE_OFF                  0x0000 /* DMA off */

#define DMA_SIZE_BYTE                   0x4000 /* DMA1 data size is byte */
#define DMA_SIZE_WORD                   0x0000 /* DMA1 data size is word */

#define DMA_TO_PERIPHERAL               0x2000 /* Read from DMA RAM address, write to peripheral*/
#define PERIPHERAL_TO_DMA               0x0000 /* Read from peripheral address, write to DMA RAM*/

#define DMA_INTERRUPT_HALF              0x1000 /* Initiate block transfer complete interrupt when half of the data has been moved */
#define DMA_INTERRUPT_BLOCK             0x0000 /* Initiate block transfer complete interrupt when all of the data has been moved */

#define DMA_WRITE_0x00                  0x0080 /* 0x00 data write to peripheral in addition to DMA RAM write*/
#define DMA_NORMAL                      0x0000 /* Normal operation*/

#define DMA_PERIPHERAL_RESERVERD        0x0030 /* Reserved (acts as Peripheral Indirect Addressing mode) */
#define DMA_PERIPHERAL_ADDRESSING       0x0020 /* Peripheral Indirect Addressing mode */
#define DMA_REGISTER_WITHOUT_INCREMENT  0x0010 /* Register Indirect without Post-Increment mode */
#define DMA_REGISTER_WITH_INCREMENT     0x0000 /* Register Indirect with Post-Increment mode */

#define DMA_ONE_SHOT_PING_PONG          0x0003 /* One-Shot, Ping-Pong modes enabled*/
#define DMA_CONTINUOUS_PING_PONG        0x0002 /* Continuous Ping-Pong modes enabled*/
#define DMA_ONE_SHOT                    0x0001 /* One-shot Ping-Pong mode disabled*/
#define DMA_CONTINUOUS                  0x0000 /* Continuous Ping-Pong modes disabled */

/* < Macros de Control ::: Interrupts Priority > */
#define ENABLE_INT_DMA_ZERO()           IEC0bits.DMA0IE = pdSet
#define DISABLE_INT_DMA_ZERO()          IEC0bits.DMA0IE = pdClear
#define SET_PRIORITY_INT_DMA_ZERO(X)    IPC3bits.DMA0IP = (X)

#define ENABLE_INT_DMA_ONE()            IEC0bits.DMA1IE = pdSet
#define DISABLE_INT_DMA_ONE()           IEC0bits.DMA1IE = pdClear
#define SET_PRIORITY_INT_DMA_ONE(X)     IPC3bits.DMA1IP = (X)

/* < Prototipo ::: Funciones de Control ::: Module DMA Zero > */
void vConfigureDMAZeroModule(uint8_t Interrupt, uint16_t Config, uint16_t IRQ, uint16_t STA_Address, uint16_t STB_Address, uint16_t PAD_Address, uint16_t Count);
void vConfigureDMAOneModule(uint8_t Interrupt, uint16_t Config, uint16_t IRQ, uint16_t STA_Address, uint16_t STB_Address, uint16_t PAD_Address, uint16_t Count);

#endif	/* < DRIVER_DIRECT_MEMORY_ACCESS_ONE_H > */

