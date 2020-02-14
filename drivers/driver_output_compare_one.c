/* < Include ::: Headers > */
#include "driver_output_compare_one.h"

/* < Funciones de Control ::: OUTPUT_COMPARR_MODULE_ONE > */
void vConfigureOutputCompareModuleOne(uint8_t Config_INT, uint16_t Config_1) {
    /* < Habilita ::: Modulo OUTPUT_COMPARR > */
    PMD2bits.OC1MD = pdClear;
    /* < Configuracion ::: Puertos y Registros I/O > */
    TRIS_OUTPUT_COMPARE_ONE = pdClear;
    /* < .:: Configuracion del OUTPUT_COMPARR_MODULE_ONE ::: Multiplexor de Salida (PIC24H) ::. > */
    __builtin_write_OSCCONL(OSCCON &~(0x40));
    RPOR11bits.RP22R = 0b00001; // < RP22 tied to PWM1(OC1)
    __builtin_write_OSCCONL(OSCCON | 0x40);
    /* < Configuracion ::: Operation Settings :: OUTPUT_COMPARR_MODULE_ONE > */
    OC1R = 0x00; // Initialize Compare Register1
    OC1RS = 0x00; // Initialize Secondary Compare Register1 
    OC1CON = Config_1;
    /* < Configuracion ::: Interruption :: SPI_MODULE_ONE > */
    IFS0bits.OC1IF = pdClear;
    IPC0bits.OC1IP = (Config_INT & 0x07);
    IEC0bits.OC1IE = (Config_INT & 0x80) >> 0x07;
}

uint16_t xReadPWMDutyOutputCompareModuleOne(void) {
    if ((OC1CONbits.OCM & 0x06) == 0x06) {
        return (OC1RS); // < Output Compare Secondary Register
    } else {
        return (0x00);
    }
}

uint16_t xReadRegisterOutputCompareModuleOne(uint8_t Register) {
    if ((OC1CONbits.OCM & 0x06) != 0x06) {
        if (Register) {
            return (OC1R); // < Output Compare main Register 
        } else {
            return (OC1RS); // < Output Compare Secondary Register
        }
    } else {
        return (0x00);
    }
}

void vSetPWMDutyOutputCompareModuleOne(uint16_t DutyCycle) {
    /* < check if OC is in PWM Mode > */
    if ((OC1CONbits.OCM & 0x06) == 0x06) {
        OC1RS = DutyCycle; // < Assign to OCRS
    }
}

void vSetPulseCompareModuleOne(uint16_t PulseStart, uint16_t PulseStop) {
    /* < check if OC is in PWM Mode > */
    if ((OC1CONbits.OCM & 0x06) != 0x06) {
        OC1R = PulseStart; // < assign pulse_start to Main Register
        OC1RS = PulseStop; // Z assign pulse_stop to Secondary Register
    }
}
