#ifndef DRIVER_CYCLIC_REDUNDANCY_CHECK_H
#define	DRIVER_CYCLIC_REDUNDANCY_CHECK_H

/* < Include ::: Processor Header >*/
#include <xc.h>
/* < Configuration Main Settings > */
#include "main_typedefs.h"
#include "main_delays.h"

/* < Definicion ::: Configuracion INT :: CRC_MODULE : Interruption > */
#define CRC_INT_ENABLE                  0x80     // < enable / disable interrupts
#define CRC_INT_DISABLE                 0x00

#define CRC_INT_PRI_0                   0x00  // < Setting the priority of adc interrupt
#define CRC_INT_PRI_1                   0x01
#define CRC_INT_PRI_2                   0x02
#define CRC_INT_PRI_3                   0x03
#define CRC_INT_PRI_4                   0x04
#define CRC_INT_PRI_5                   0x05
#define CRC_INT_PRI_6                   0x06
#define CRC_INT_PRI_7                   0x07

/* < Definicion ::: Configuracion 1 :: CRC_MODULE : CRCCON : Config > */
#define CRC_IDLE_STOP                   0x2000  /*stop CRC module in Idle mode */
#define CRC_IDLE_CON                    0x0000  /*continue CRC module in Idle mode */

#define CRC_POLYNOMIAL_LEN1             0x0000
#define CRC_POLYNOMIAL_LEN2             0x0001 
#define CRC_POLYNOMIAL_LEN3             0x0002 
#define CRC_POLYNOMIAL_LEN4             0x0003 
#define CRC_POLYNOMIAL_LEN5             0x0004 
#define CRC_POLYNOMIAL_LEN6             0x0005 
#define CRC_POLYNOMIAL_LEN7             0x0006 
#define CRC_POLYNOMIAL_LEN8             0x0007 
#define CRC_POLYNOMIAL_LEN9             0x0008 
#define CRC_POLYNOMIAL_LEN10            0x0009 
#define CRC_POLYNOMIAL_LEN11            0x000A
#define CRC_POLYNOMIAL_LEN12            0x000B
#define CRC_POLYNOMIAL_LEN13            0x000C
#define CRC_POLYNOMIAL_LEN14            0x000D
#define CRC_POLYNOMIAL_LEN15            0x000E
#define CRC_POLYNOMIAL_LEN16            0x000F

/* < Prototipo ::: Funciones de Control :: CRC_MODULE > */
void vConfigureCRCModule(uint8_t Interrupt, uint16_t Configure, uint16_t Polynomi);
void vCRCModuleSetPolynomi(uint16_t Lenght, uint16_t Polynomi);
uint16_t CRC_Calc_ChecksumWord(uint16_t* Data, uint16_t NumberWords, uint16_t PreviusCRC);
uint16_t CRC_Calc_ChecksumByte(uint8_t* Data, uint16_t NumberBytes, uint16_t PreviusCRC);

#endif	/* < DRIVER_CYCLIC_REDUNDANCY_CHECK_H > */

