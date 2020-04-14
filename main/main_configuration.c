/* < Include ::: Header >*/
#include "main_configuration.h"

/* < Control :: Functions > */
void vHardwareConfiguration(void) {
    /* < Break ::: DEBUG > */
    pdNop();
    /* < Configure Oscillator to operate the device at 40Mips ::: Fosc= Fin*M/(N1*N2), Fcy=Fosc/2 ::: Fosc= 4M*80/(2*2)=80Mhz for 4Mhz input clock > */
    PLLFBD = 78; // < M = 80
    CLKDIVbits.PLLPOST = pdClear; // < N1 = 2
    CLKDIVbits.PLLPRE = pdClear; // < N2 = 2
    OSCTUN = 0x0000; // < Center frequency (7.37 MHz nominal)
    /* < Disable WatchDog Timer > */
    RCONbits.SWDTEN = pdClear;
    /* < Clock switching to incorporate PLL > */
    __builtin_write_OSCCONH(0x03); // < Initiate Clock Switch to Primary Oscillator with PLL (NOSC=0b011)
    __builtin_write_OSCCONL(0x01); // < Start clock switching
    /* < Wait for Clock switch to occur >*/
    while (OSCCONbits.COSC != 0b011);
    /* < Wait for PLL to lock >*/
    while (OSCCONbits.LOCK != pdSet);
    /* < Configuracion ::: Puertos de Entrada > */
    TRISA = 0xFFFF; // < All Inputs in Ports     
    TRISB = 0xFFFF; // < All Inputs in Ports
    TRISC = 0xFFFF; // < All Inputs in Ports
    /* < Configuracion ::: Conversor A/D (All Input Digital) > */
    AD1PCFGL = 0xFFFF;
    /* < Configuracion ::: Activavion/Desactivacion Modulos por Hardware > */
    PMD1 = 0xFFF9; // < Peripheral modules is disabled
    PMD2 = 0xFFFF; // < Peripheral modules is disabled
    PMD3 = 0xFFFF; // < Peripheral modules is disabled  
    /* < Configuracion ::: Mutiplexor de I/O :: for Peripherals (PIC24H)... > */
    __builtin_write_OSCCONL(OSCCON & ~(0x40));
    /**************************************************************************/
    RPOR2bits.RP5R = 0b10000; // < RP5 tied to ECAN Transmit    
    RPINR26bits.C1RXR = 0b10101; // < Input tied to RP21 ECAN Receive  
    /**************************************************************************/


    __builtin_write_OSCCONL(OSCCON | 0x40);
}
