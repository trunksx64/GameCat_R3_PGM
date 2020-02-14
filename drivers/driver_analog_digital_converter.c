/* < Include ::: Headers > */
#include "driver_analog_digital_converter.h"

void vConfigureADCConverter(uint8_t Config_INT, uint16_t Config_1, uint16_t Config_2, uint16_t Config_3, uint16_t Config_4, uint16_t Config_5, uint16_t Config_6, uint16_t Config_7, uint16_t Config_8) {
    /* < Habilita ::: Modulo ADC > */
    PMD1bits.AD1MD = pdClear;
    /* < Configuracion ::: Puertos y Registros I/O > */
    TrisInputAN0 = pdSet;
    /* < Configuracion ::: Operation Settings :: ADC_Convert > */    
    AD1PCFGL = Config_8;
    AD1CON1 = (Config_1 & 0x7FFF);    
    AD1CON2 = Config_2;
    AD1CON3 = Config_3;
    AD1CON4 = Config_4;
    AD1CHS123 = Config_5;
    AD1CHS0 = Config_6;
    AD1CSSL = Config_7;    
    /* < Configuracion ::: Interruption :: ADC_Convert > */
    IFS0bits.AD1IF = pdClear;
    IPC3bits.AD1IP = (Config_INT & 0x07);
    IEC0bits.AD1IE = (Config_INT & 0x80) >> 0x07;
    /* < Enable ADC1... > */
    AD1CON1 |= (Config_1 & 0x8000);
}

void vConvertADCConverter(void) {
    AD1CON1bits.SAMP = 0; /* Clear SAMP to start conversion */
}

void vSetChanADCConverter(uint16_t Channel123, uint16_t Channel0) {
    AD1CHS123 = Channel123;
    AD1CHS0 = Channel0;
}

uint16_t xReadADCConverter(void) {
    /* < Return of Value Sampling> */
    return ((uint16_t) ADC1BUF0);
}

uint8_t xBusyADCConverter(void) {
    return !(AD1CON1bits.DONE);
}
