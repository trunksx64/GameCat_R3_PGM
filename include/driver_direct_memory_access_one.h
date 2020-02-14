#ifndef DRIVER_DIRECT_MEMORY_ACCESS_ONE_H
#define	DRIVER_DIRECT_MEMORY_ACCESS_ONE_H

/* < Include ::: Processor Header >*/
#include <xc.h>
/* < Configuration Main Settings > */
#include "main_typedefs.h"
#include "main_delays.h"

/* < Definicion ::: Interrupts :: DMA ONE > */
#define DMA1_INT_ENABLE                 0x80
#define DMA1_INT_DISABLE                0x00

/* < Definicion ::: Interrupts Priority :: DMA ONE > */
#define DMA1_INT_PRI_0                  0x00
#define DMA1_INT_PRI_1                  0x01
#define DMA1_INT_PRI_2                  0x02
#define DMA1_INT_PRI_3                  0x03
#define DMA1_INT_PRI_4                  0x04
#define DMA1_INT_PRI_5                  0x05
#define DMA1_INT_PRI_6                  0x06
#define DMA1_INT_PRI_7                  0x07

/* < Definicion ::: Configuracion :: DMA ONE : DMA1CON : Config > */
#define DMA1_MODULE_ON                  0x8000 /* DMA on */
#define DMA1_MODULE_OFF                 0x0000 /* DMA off */

#define DMA1_SIZE_BYTE                  0x4000 /* DMA1 data size is byte */
#define DMA1_SIZE_WORD                  0x0000 /* DMA1 data size is word */

#define DMA1_TO_PERIPHERAL              0x2000 /* Read from DMA RAM address, write to peripheral*/
#define PERIPHERAL_TO_DMA1              0x0000 /* Read from peripheral address, write to DMA RAM*/

#define DMA1_INTERRUPT_HALF             0x1000 /* Initiate block transfer complete interrupt when half of the data has been moved */
#define DMA1_INTERRUPT_BLOCK            0x0000 /* Initiate block transfer complete interrupt when all of the data has been moved */

#define DMA1_WRITE_0x00                 0x0080 /* 0x00 data write to peripheral in addition to DMA RAM write*/
#define DMA1_NORMAL                     0x0000 /* Normal operation*/

#define DMA1_PERIPHERAL_RESERVERD       0x0030 /* Reserved (acts as Peripheral Indirect Addressing mode) */
#define DMA1_PERIPHERAL_ADDRESSING      0x0020 /* Peripheral Indirect Addressing mode */
#define DMA1_REGISTER_WITHOUT_INCREMENT 0x0010 /* Register Indirect without Post-Increment mode */
#define DMA1_REGISTER_WITH_INCREMENT    0x0000 /* Register Indirect with Post-Increment mode */

#define DMA1_ONE_SHOT_PING_PONG         0x0003 /* One-Shot, Ping-Pong modes enabled*/
#define DMA1_CONTINUOUS_PING_PONG       0x0002 /* Continuous Ping-Pong modes enabled*/
#define DMA1_ONE_SHOT                   0x0001 /* One-shot Ping-Pong mode disabled*/
#define DMA1_CONTINUOUS                 0x0000 /* Continuous Ping-Pong modes disabled */

/* < Macros de Control ::: Interrupts Priority :: DMA ONE > */
#define ENABLE_INT_DMA_ONE()                   IEC0bits.DMA1IE = pdSet
#define DISABLE_INT_DMA_ONE()                  IEC0bits.DMA1IE = pdClear
#define SET_PRIORITY_INT_DMA_ONE(Priority)     IPC3bits.DMA1IP = (Priority)

/* < Prototipo ::: Funciones de Control ::: Module DMA Zero > */
void vConfigureDMAOneModule(uint8_t Interrupt, uint16_t Config, uint16_t IRQ, uint16_t STA_Address, uint16_t STB_Address, uint16_t PAD_Address, uint16_t Count);

#endif	/* < DRIVER_DIRECT_MEMORY_ACCESS_ONE_H > */

