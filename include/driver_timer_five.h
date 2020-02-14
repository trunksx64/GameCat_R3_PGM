#ifndef DRIVER_TIMER_FIVE_H
#define	DRIVER_TIMER_FIVE_H

/* < Configuration Bits Settings > */
#include "xc.h"
/* < Configuration Main Settings > */
#include "main_typedefs.h"
#include "main_delays.h"

/* < Definicion ::: Configuracion :: TIMER2 : INTERRUPTIONS > */
#define T5_INT_PRIOR_7                  0x07      /* 111 = Interrupt is priority 7 */ 
#define T5_INT_PRIOR_6                  0x06      /* 110 = Interrupt is priority 6 */
#define T5_INT_PRIOR_5                  0x05      /* 101 = Interrupt is priority 5 */
#define T5_INT_PRIOR_4                  0x04      /* 100 = Interrupt is priority 4 */
#define T5_INT_PRIOR_3                  0x03      /* 011 = Interrupt is priority 3 */
#define T5_INT_PRIOR_2                  0x02      /* 010 = Interrupt is priority 2 */
#define T5_INT_PRIOR_1                  0x01      /* 001 = Interrupt is priority 1 */
#define T5_INT_PRIOR_0                  0x00      /* 000 = Interrupt is priority 0 */

#define T5_INT_ON                       0x80      /* Interrupt Enable */  
#define T5_INT_OFF                      0x00      /* Interrupt Disable */

/* < Definicion ::: Configuracion :: TIMER5 : T5CON > */
#define T5_ON                           0x8000      /* Timer5 ON */
#define T5_OFF                          0x0000      /* Timer5 OFF */

#define T5_IDLE_CON                     0x0000      /* operate during sleep */
#define T5_IDLE_STOP                    0x2000      /* stop operation during sleep */

#define T5_GATE_ON                      0x0040      /* Timer5 Gate  time accumulation enabled  */
#define T5_GATE_OFF                     0x0000      /* Timer5 Gate time accumulation disabled */

#define T5_PS_1_1                       0x0000      /* Prescaler 1:1   */
#define T5_PS_1_8                       0x0010      /* Prescaler 1:8   */
#define T5_PS_1_64                      0x0020      /* Prescaler 1:64  */
#define T5_PS_1_256                     0x0030      /* Prescaler 1:256 */

#define T5_SOURCE_EXT                   0x0002      /* External clock source */
#define T5_SOURCE_INT                   0x0001      /* Internal clock source */

/* < Macros de Control ::: Interrupts Priority :: TIMER5 > */
#define EnableIntT5()                   IEC1bits.T5IE = pdSet
#define DisableIntT5()                  IEC1bits.T5IE = pdClear
#define SetPriorityIntT5(Priority)      IPC7bits.T5IP = Priority

/* < Prototipo ::: Funciones de Control ::: Module Timer5 > */
void vConfigureTimer5Module(uint8_t Interrupt, uint16_t Config, uint16_t Timer);
uint16_t xReadTimer5(void);
void xWriteTimer5(uint16_t Timer);

#endif	/* < DRIVER_TIMER_FIVE_H > */

