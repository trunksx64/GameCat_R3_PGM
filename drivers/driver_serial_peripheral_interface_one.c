/* < Include ::: Headers > */
#include "driver_serial_peripheral_interface_one.h"

/* < Funciones de Control ::: SPI_MODULE_TWO > */
void vConfigureSPIModuleOne(uint8_t Config_INT, uint16_t Config_1, uint16_t Config_2, uint16_t Config_3) {
    /* < Habilita ::: Modulo SPI > */
    PMD1bits.SPI1MD = pdClear;
    /* < Configuracion ::: Puertos y Registros I/O > */
    TRIS_SPI1_SDO = pdClear;
    TRIS_SPI1_CLK = pdClear;
    /* < .:: Configuracion del SPI_MODULE_TWO ::: Multiplexor de Salida (PIC24H) ::. > */
    __builtin_write_OSCCONL(OSCCON &~(0x40));
    RPOR3bits.RP6R = 0b00111; // < RP6 tied to SDO1 Transmit                  
    RPOR3bits.RP7R = 0b01000; // < RP7 tied to SCLK1 Transmit  
    __builtin_write_OSCCONL(OSCCON | 0x40);
    /* < Configuracion ::: Operation Settings :: SPI_MODULE_TWO > */
    SPI1STAT = (Config_1 & 0x7FFF);
    SPI1CON1 = Config_2;
    SPI1CON2 = Config_3;
    /* < Configuracion ::: Interruption :: SPI_MODULE_TWO > */
    IFS0bits.SPI1IF = pdClear;
    IPC2bits.SPI1IP = (Config_INT & 0x07);
    IEC0bits.SPI1IE = (Config_INT & 0x80) >> 0x07;
    /* < Enable SPI_TWO... > */
    SPI1STAT |= (Config_1 & 0x8000);
    /* < Send ::: Garbage... > */
    xWriteReadSPIModuleOne(0x00);
}

uint16_t xWriteReadSPIModuleOne(uint16_t Data) {
    /* < Variables ::: Locales > */
    uint16_t ReadBuffer = 0x00;
    /* < Errata ::: Work Around > */
    Nop();
    /* < Write ::: Buffer SPI1 > */
    if (SPI1CON1bits.MODE16) SPI1BUF = Data; // Word Write
    else SPI1BUF = (Data & 0xFF); // Byte Write    
    /* < Wait Until Bit is Set Interruption... > */
    while (!IFS0bits.SPI1IF);
    /* < Clear ::: Flag Interrupt... > */
    IFS0bits.SPI1IF = pdClear;
    /* < Check for Receive buffer full status bit of status register > */
    if (SPI1STATbits.SPIRBF) {
        /* < Clear ::: Buffer Overflow... > */
        SPI1STATbits.SPIROV = pdClear;
        /* < Return Byte Read > */
        if (SPI1CON1bits.MODE16) ReadBuffer = SPI1BUF;
        else ReadBuffer = (SPI1BUF & 0xFF);
    }
    /* < RBF bit is not set return error > */
    return (ReadBuffer);
}
