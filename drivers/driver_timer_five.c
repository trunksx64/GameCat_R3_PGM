/* < Include ::: Headers > */
#include "driver_timer_five.h"

/* < Prototipo ::: Funciones de Control ::: Module Timer5 > */
void vConfigureTimer5Module(uint8_t Interrupt, uint16_t Config, uint16_t Timer) {
    /* < Habilita ::: Modulo TIMER5 > */
    PMD1bits.T5MD = pdClear;
    /* < Configuracion ::: Parameters :: TIMER5 > */
    TMR5 = 0x0000; /* Reset Timer3 to 0x0000 */
    PR5 = Timer; /* Assigning Period to Timer period register.*/
    T5CON = (Config & 0x7FFF); /* Configure timer control Reg */
    /* < Configuracion ::: Interruption :: TIMER5 > */
    IFS1bits.T5IF = pdClear; /* clear IF bit */
    IPC7bits.T5IP = (Interrupt & 0x07); /* assigning Interrupt Priority */
    IEC1bits.T5IE = (Interrupt & 0x08) >> 0x07; /* Interrupt Enable /Disable */
    /* < Enable Timer... > */
    T5CON |= (Config & 0x8000);
}

uint16_t xReadTimer5(void) {
    return (TMR5); /* Return the TIMER5 register */
}

void xWriteTimer5(uint16_t Timer) {
    TMR5 = Timer; /* assign timer value to TIMER5 Register */
}
