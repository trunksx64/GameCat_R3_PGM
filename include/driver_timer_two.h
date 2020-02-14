#ifndef DRIVER_TIMER_TWO_H
#define	DRIVER_TIMER_TWO_H

/* < Configuration Bits Settings > */
#include "xc.h"
/* < Configuration Main Settings > */
#include "main_typedefs.h"
#include "main_delays.h"

/* < Definicion ::: Configuracion :: TIMER2 : INTERRUPTIONS > */
#define T2_INT_ON                       0x80      /* Interrupt Enable */  
#define T2_INT_OFF                      0x00      /* Interrupt Disable */

#define T2_INT_PRIOR_7                  0x07      /* 111 = Interrupt is priority 7 */ 
#define T2_INT_PRIOR_6                  0x06      /* 110 = Interrupt is priority 6 */
#define T2_INT_PRIOR_5                  0x05      /* 101 = Interrupt is priority 5 */
#define T2_INT_PRIOR_4                  0x04      /* 100 = Interrupt is priority 4 */
#define T2_INT_PRIOR_3                  0x03      /* 011 = Interrupt is priority 3 */
#define T2_INT_PRIOR_2                  0x02      /* 010 = Interrupt is priority 2 */
#define T2_INT_PRIOR_1                  0x01      /* 001 = Interrupt is priority 1 */
#define T2_INT_PRIOR_0                  0x00      /* 000 = Interrupt is priority 0 */

/* < Definicion ::: Configuracion :: TIMER2 : T2CON > */
#define T2_ON                           0x8000      /* Timer2 ON */
#define T2_OFF                          0x0000      /* Timer2 OFF */

#define T2_IDLE_CON                     0x0000      /* operate during sleep */
#define T2_IDLE_STOP                    0x2000      /* stop operation during sleep */

#define T2_GATE_ON                      0x0040      /* Timer2 Gate  time accumulation enabled  */
#define T2_GATE_OFF                     0x0000      /* Timer2 Gate time accumulation disabled */

#define T2_PS_1_1                       0x0000      /* Prescaler 1:1   */
#define T2_PS_1_8                       0x0010      /* Prescaler 1:8   */
#define T2_PS_1_64                      0x0020      /* Prescaler 1:64  */
#define T2_PS_1_256                     0x0030      /* Prescaler 1:256 */

#define T2_32BIT_MODE_ON                0x0008      /* Timer 2 and Timer 3 form a 32 bit Timer */
#define T2_32BIT_MODE_OFF               0x0000     

#define T2_SOURCE_EXT                   0x0002      /* External clock source */
#define T2_SOURCE_INT                   0x0000      /* Internal clock source */

/* < Macros de Control ::: Interrupts Priority :: TIMER2 > */
#define EnableIntT2()                   IEC0bits.T2IE = pdSet
#define DisableIntT2()                  IEC0bits.T2IE = pdClear
#define SetPriorityIntT2(Priority)      IPC1bits.T2IP = Priority

/* < Prototipo ::: Funciones de Control ::: Module Timer3 > */
void vConfigureTimer2Module(uint8_t Interrupt, uint16_t Config, uint16_t Timer);
uint16_t xReadTimer2(void);
void xWriteTimer2(uint16_t Timer);

#endif	/* < DRIVER_TIMER_TWO_H > */

