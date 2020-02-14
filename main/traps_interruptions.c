/* < Include ::: Header >*/
#include "source_config_system.h"

/* < Function Trap ::: _OscillatorFail > */
void __attribute__((interrupt, no_auto_psv)) _OscillatorFail(void) {
    /* < Break ::: for DEBUG > */
    pdNop();
    /* < Enable ::: Interruption x 100 Cycles... >*/
    __builtin_disi(100);
    /* < Clock Switching to Incorporate OSC XT > */
    __builtin_write_OSCCONH(0x02); // < Initiate Clock Switch to Primary Oscillator (XT, HS, EC)(NOSC=0b010)
    __builtin_write_OSCCONL(0x01); // < Start clock switching
    /* < Wait for Clock Switch to occur >*/
    while (OSCCONbits.COSC != 0x02);
    /* < Enable ::: Interruption x 10 Cycles... >*/
    __builtin_disi(0);
    /* < Borra la Bandera del Trap > */
    INTCON1bits.OSCFAIL = pdClear;
}

/* < Function Trap ::: _AddressError > */
void __attribute__((interrupt, no_auto_psv)) _AddressError(void) {
    /* < Break ::: for DEBUG > */
    pdNop();
    /* < Borra la Bandera del Trap > */
    INTCON1bits.ADDRERR = pdClear;
}

/* < Function Trap ::: _StackError > */
void __attribute__((interrupt, no_auto_psv)) _StackError(void) {
    /* < Break ::: for DEBUG > */
    pdNop();
    /* < Borra la Bandera del Trap > */
    INTCON1bits.STKERR = pdClear;
}

/* < Function Trap ::: _MathError > */
void __attribute__((interrupt, no_auto_psv)) _MathError(void) {
    /* < Break ::: for DEBUG > */
    pdNop();
    /* < Borra la Bandera del Trap > */
    INTCON1bits.MATHERR = pdClear;
}

/* < Function Trap ::: _DMACError > */
void __attribute__((interrupt, no_auto_psv)) _DMACError(void) {
    /* < Break ::: for DEBUG > */
    pdNop();
    /* < Borra la Bandera del Trap > */
    INTCON1bits.DMACERR = pdClear;
}
