/* < Include ::: Headers > */
#include "driver_timer_two.h"

/* < Prototipo ::: Funciones de Control ::: Module Timer2 > */
void vConfigureTimer2Module(uint8_t Interrupt, uint16_t Config, uint16_t Timer) {
    /* < Habilita ::: Modulo TIMER2 > */
    PMD1bits.T2MD = pdClear;
    /* < Configuracion ::: Parameters :: TIMER2 > */
    TMR2 = 0x0000; /* Reset Timer3 to 0x0000 */
    PR2 = Timer; /* Assigning Period to Timer period register.*/
    T2CON = (Config & 0x7FFF); /* Configure timer control Reg */
    /* < Configuracion ::: Interruption :: TIMER2 > */
    IFS0bits.T2IF = pdClear; /* clear IF bit */
    IPC1bits.T2IP = (Interrupt & 0x07); /* assigning Interrupt Priority */
    IEC0bits.T2IE = (Interrupt & 0x08) >> 0x07; /* Interrupt Enable /Disable */
    /* < Enable Timer... > */
    T2CON |= (Config & 0x8000);
}

uint16_t xReadTimer2(void) {
    return (TMR2); /* Return the TIMER2 register */
}

void xWriteTimer2(uint16_t Timer) {
    TMR2 = Timer; /* assign timer value to Timer3 Register */
}
