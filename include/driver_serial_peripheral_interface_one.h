#ifndef DRIVER_SPI_MODULE_ONE_H
#define	DRIVER_SPI_MODULE_ONE_H

/* < Include ::: Processor Header >*/
#include "xc.h"
/* < Configuration Main Settings > */
#include "main_typedefs.h"
#include "main_delays.h"

/* < Definicion ::: Pines de Control :: SPI_MODULE_ONE > */
#define TRIS_SPI1_SDO                   TRISBbits.TRISB6
#define TRIS_SPI1_CLK                   TRISBbits.TRISB7

/* < Definicion ::: Configuracion INT :: SPI_MODULE_ONE : Interruption > */
#define SPI1_INT_ENABLE                 0x80  // < enable / disable interrupts
#define SPI1_INT_DISABLE                0x00

#define SPI1_INT_PRI_0                  0x00  // < Setting the priority interrupt
#define SPI1_INT_PRI_1                  0x01
#define SPI1_INT_PRI_2                  0x02
#define SPI1_INT_PRI_3                  0x03
#define SPI1_INT_PRI_4                  0x04
#define SPI1_INT_PRI_5                  0x05
#define SPI1_INT_PRI_6                  0x06
#define SPI1_INT_PRI_7                  0x07

/* < Definicion ::: Configuracion 1 :: SPI_MODULE_ONE : SPI1STAT > */
#define SPI1_ENABLE                     0x8000  /* Enable module */
#define SPI1_DISABLE                    0x0000  /* Disable module */

#define SPI1_IDLE_CON                   0x0000  /* Continue module operation in idle mode */
#define SPI1_IDLE_STOP                  0x2000  /* Discontinue module operation in idle mode */ 

/* < Definicion ::: Configuracion 1 :: SPI_MODULE_ONE : SPI1CON1 > */
#define SPI1_DISABLE_SCK_PIN            0x1000  /* SCK pin is not used by module */
#define SPI1_ENABLE_SCK_PIN             0x0000  /* SCK pin is  used by module */

#define SPI1_DISABLE_SDO_PIN            0x0800  /* SDO pin is not used by module */
#define SPI1_ENABLE_SDO_PIN             0x0000  /* SDO pin is  used by module */

#define SPI1_MODE_16BITS                0x0400  /* Communication is word wide */
#define SPI1_MODE_8BITS                 0x0000  /* Communication is byte wide */

#define SPI1_SMP_END                    0x0200  /* Input data sampled at end of data output time */
#define SPI1_SMP_MIDDLE                 0x0000  /* Input data sampled at middle of data output time */

#define SPI1_CKE_0_TO_1                 0x0000  /* Transmit happens from active clock state to idle clock state*/
#define SPI1_CKE_1_TO_0                 0x0100  /* Transmit happens on transition from idle clock state to active clock state */

#define SPI1_SLAVE_SS_ON                0x0080  /* Slave Select enable */
#define SPI1_SLAVE_SS_OFF               0x0000  /* Slave Select not used by module */

#define SPI1_CLK_POL_LOW                0x0040  /* Idle state for clock is high, active is low */
#define SPI1_CLK_POL_HIGH               0x0000  /* Idle state for clock is low, active is high */

#define SPI1_MASTER_ENABLE_ON           0x0020  /* Master Mode */
#define SPI1_MASTER_ENABLE_OFF          0x0000  /* Slave Mode */

#define SPI1_SEC_PRESCAL_1_1            0x001C  /* Secondary Prescale 1:1 */
#define SPI1_SEC_PRESCAL_1_2            0x0018  /* Secondary Prescale 2:1 */
#define SPI1_SEC_PRESCAL_1_3            0x0014  /* Secondary Prescale 2:1 */
#define SPI1_SEC_PRESCAL_1_4            0x0010  /* Secondary Prescale 4:1 */
#define SPI1_SEC_PRESCAL_1_5            0x000C  /* Secondary Prescale 5:1 */
#define SPI1_SEC_PRESCAL_1_6            0x0008  /* Secondary Prescale 6:1 */
#define SPI1_SEC_PRESCAL_1_7            0x0004  /* Secondary Prescale 7:1 */
#define SPI1_SEC_PRESCAL_1_8            0x0000  /* Secondary Prescale 8:1 */

#define SPI1_PRI_PRESCAL_1_1            0x0003  /* Primary Prescale 1:1 */
#define SPI1_PRI_PRESCAL_1_4            0x0002  /* Primary Prescale 4:1 */
#define SPI1_PRI_PRESCAL_1_16           0x0001  /* Primary Prescale 16:1 */
#define SPI1_PRI_PRESCAL_1_64           0x0000  /* Primary Prescale 64:1 */

/* < Definicion ::: Configuracion 1 :: SPI_MODULE_ONE : SPI1CON2 > */
#define SPI1_FRAME_ENABLE_ON            0x8000  /* Frame SPI support enable        */
#define SPI1_FRAME_ENABLE_OFF           0x0000  /* Frame SPI support Disable       */

#define SPI1_FRAME_SYNC_INPUT           0x4000  /* Frame sync pulse Input (slave)  */
#define SPI1_FRAME_SYNC_OUTPUT          0x0000  /* Frame sync pulse Output (master)*/

#define SPI1_FRAME_POL_ACTIVE_HIGH      0x2000  /* Frame sync pulse is active-high*/
#define SPI1_FRAME_POL_ACTIVE_LOW       0x0000  /* Frame sync pulse is active-low */

#define SPI1_FRAME_SYNC_EDGE_COINCIDE   0x0020  /* Frame sync pulse coincides with first bit clock */
#define SPI1_FRAME_SYNC_EDGE_PRECEDE    0x0000  /* Frame sync pulse precedes first bit clock */

/* < Prototipo ::: Funciones de Control ::: SPI_MODULE_ONE > */
void vConfigureSPIModuleOne(uint8_t Config_INT, uint16_t Config_1, uint16_t Config_2, uint16_t Config_3);
uint16_t xWriteReadSPIModuleOne(uint16_t Data);

#endif	/* < DRIVER_SPI_MODULE_ONE_H > */

