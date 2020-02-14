#ifndef DRIVER_OUTPUT_COMPARE_ONE_H
#define	DRIVER_OUTPUT_COMPARE_ONE_H

/* < Configuration Bits Settings > */
#include "xc.h"
/* < Configuration Main Settings > */
#include "main_typedefs.h"
#include "main_delays.h"

/* < Definicion ::: Pines de Control :: OUTPUT_COMPARR_MODULE_ONE > */
#define TRIS_OUTPUT_COMPARE_ONE         TRISCbits.TRISC6

/* < Definicion ::: Configuracion INT :: SPI_MODULE_ONE : Interruption > */
#define OC1_INT_ON                      0x80  /* OutputCompare Enable  */
#define OC1_INT_OFF                     0x00  /* OutputCompare Disable */

#define OC1_INT_PRIOR_0                 0x00  /* OutputCompare PriorityLevel 0 */
#define OC1_INT_PRIOR_1                 0x01  /* OutputCompare PriorityLevel 1 */
#define OC1_INT_PRIOR_2                 0x02  /* OutputCompare PriorityLevel 2 */
#define OC1_INT_PRIOR_3                 0x03  /* OutputCompare PriorityLevel 3 */
#define OC1_INT_PRIOR_4                 0x04  /* OutputCompare PriorityLevel 4 */
#define OC1_INT_PRIOR_5                 0x05  /* OutputCompare PriorityLevel 5 */
#define OC1_INT_PRIOR_6                 0x06  /* OutputCompare PriorityLevel 6 */
#define OC1_INT_PRIOR_7                 0x07  /* OutputCompare PriorityLevel 7 */

/* < Definicion ::: Configuracion 1 :: OUTPUT_COMPARR_MODULE_ONE : OC1CON > */
#define OC1_IDLE_STOP                   0x2000   /* stop in idle mode */
#define OC1_IDLE_CON                    0x0000   /* continue operation in idle mode */

#define OC1_TIMER2_SRC                  0x0000  /* Timer2 is the clock source for OutputCompare1 */
#define OC1_TIMER3_SRC                  0x0008  /* Timer3 is the clock source for OutputCompare1 */

#define OC1_PWM_FAULT_PIN_ENABLE        0x0007  /* Center Aligned PWM Mode on OCx pin */
#define OC1_PWM_FAULT_PIN_DISABLE       0x0006  /* Edge Aligned PWM Mode on OCx pin */
#define OC1_CONTINUE_PULSE              0x0005  /* Generates Continuous Output pulse on OCx Pin */
#define OC1_SINGLE_PULSE                0x0004  /* Generates Single Output pulse on OCx Pin */
#define OC1_TOGGLE_PULSE                0x0003  /* Compare1 toggles OC1 pin */
#define OC1_HIGH_LOW                    0x0002  /* Compare1 forces OC1 pin Low */
#define OC1_LOW_HIGH                    0x0001  /* Compare1 forces OC1 pin High */
#define OC1_OFF                         0x0000  /* OutputCompare x Off */

/* < Prototipo ::: Funciones de Control ::: OUTPUT_COMPARR_MODULE_ONE > */
void vConfigureOutputCompareModuleOne(uint8_t Config_INT, uint16_t Config_1);
uint16_t xReadPWMDutyOutputCompareModuleOne(void);
uint16_t xReadRegisterOutputCompareModuleOne(uint8_t Register);
void vSetPWMDutyOutputCompareModuleOne(uint16_t DutyCycle);
void vSetPulseCompareModuleOne(uint16_t PulseStart, uint16_t PulseStop);

#endif	/* < DRIVER_OUTPUT_COMPARE_ONE_H > */

