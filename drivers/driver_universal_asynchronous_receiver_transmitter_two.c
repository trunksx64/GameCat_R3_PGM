/* < Include ::: Headers > */
#include "driver_universal_asynchronous_receiver_transmitter_two.h"

/* < Prototipo ::: Funciones de Control ::: UART_TO_EXT > */
void vConfigureUartTwo(uint16_t Config_INT, uint16_t Config_1, uint16_t Config_2, uint32_t Baud) {
    /* < Habilita ::: Modulo UART_TO_EXT > */
    PMD1bits.U2MD = pdClear;
    /* < Configuracion ::: Puertos y Registros I/O > */
    TRIS_UART2_TX = pdClear;
    TRIS_UART2_RX = pdSet;
    /* < .:: Configuracion del Modulo UART_TO_EXT ::: Multiplexor de Salida (PIC24H) ::. > */
    __builtin_write_OSCCONL(OSCCON &~(0x40));
    RPOR9bits.RP19R = 0b00101; // < RP3 tied to UART2 Transmit   
    RPINR19bits.U2RXR = 0b10000; // < Input tied to RP16 UART2 Receive
    __builtin_write_OSCCONL(OSCCON | 0x40);
    /* < Configuracion ::: Operation Settings :: UART_TO_EXT > */
    U2MODE = (Config_1 & 0x7FFF);
    U2STA = (Config_2 & 0xFBFF);
    /* < Configuracion ::: Baud Rate UART_TO_EXT > */
    if (Config_1 & UART2_BRGH_FOUR) U2BRG = (((FCY / Baud) / 4) - 1);
    else U2BRG = (((FCY / Baud) / 16) - 1);
    /* < Configuracion ::: Interruption :: UART_TO_EXT : TX > */
    IFS1bits.U2TXIF = 0x00;
    IEC1bits.U2TXIE = (0x8000 & Config_INT) >> 0x0F;
    IPC7bits.U2TXIP = (0x0700 & Config_INT) >> 0x08;
    /* < Configuracion ::: Interruption :: UART_TO_EXT : RX > */
    IFS1bits.U2RXIF = 0x00; // < Clear flags        
    IEC1bits.U2RXIE = (0x0080 & Config_INT) >> 0x07;
    IPC7bits.U2RXIP = (0x0007 & Config_INT); // < Set priority    
    /*PC2 < Enable UART_TO_EXT... > */
    U2MODE |= (Config_1 & 0x8000); // < Enable RX
    U2STA |= (Config_2 & 0x0400); // < Enalbe TX
}

uint8_t xBusyUartTwo(void) {
    return (!U2STAbits.TRMT);
}

uint8_t xDataReadyUartTwo(void) {
    return (U2STAbits.URXDA);
}

uint16_t xReadUartTwo(void) {
    /* < Check ::: Data Ready > */
    if (U2STAbits.URXDA) {
        /* < Check ::: 9-bit data > */
        if (U2MODEbits.PDSEL == 0b11) return (U2RXREG & 0x01FF);
        else return (U2RXREG & 0x00FF);
    }
    /* < Return ::: Void > */
    return (pdClear);
}

void vWriteUartTwo(uint16_t Data) {
    /* < Wait ::: Buffer is Clear > */
    while (U2STAbits.UTXBF);
    /* < Check ::: 9-bit data > */
    if (U2MODEbits.PDSEL == 0b11) U2TXREG = (Data & 0x01FF);
    else U2TXREG = (Data & 0x00FF);
    /* < Wait ::: Buffer is Send > */
    while (!U2STAbits.TRMT);
}

void vPutsUartTwo(uint8_t Length, uint8_t *pxBuffer) {
    /* < Variables ::: Locales > */
    uint16_t *Ptr = (uint16_t *) pxBuffer;
    /* < Check ::: 9-bit data > */
    if (U2MODEbits.PDSEL == 0b11) {
        /* < While ::: Send Length Buffer > */
        while (Length--) {
            /* < Decrement ::: Length > */
            Length--;
            /* < Wait ::: Buffer is Clear > */
            while (U2STAbits.UTXBF);
            /* < Write ::: to Buffer > */
            U2TXREG = (*Ptr++ & 0x01FF);
            /* < Wait ::: Buffer is Send > */
            while (!U2STAbits.TRMT);
        }
    } else {
        /* < While ::: Send Length Buffer > */
        while (Length--) {
            /* < Wait ::: Buffer is Clear > */
            while (U2STAbits.UTXBF);
            /* < Write ::: to Buffer > */
            U2TXREG = (*pxBuffer++ & 0x00FF);
            /* < Wait ::: Buffer is Send > */
            while (!U2STAbits.TRMT);
        }
    }
}

void vGetsUartTwo(uint8_t Length, uint8_t *pxBuffer) {
    /* < Variables ::: Locales > */
    uint16_t *Ptr = (uint16_t *) pxBuffer;
    /* < Check ::: 9-bit data > */
    if (U2MODEbits.PDSEL == 0b11) {
        /* < While ::: Receive Length Buffer > */
        while (Length--) {
            /* < Decrement ::: Length > */
            Length--;
            /* < Wait ::: Buffer is Full > */
            while (!U2STAbits.URXDA);
            /* < Read ::: Buffer > */
            *Ptr = (U2RXREG & 0x01FF);
        }
    } else {
        /* < While ::: Receive Length Buffer > */
        while (Length--) {
            /* < Wait ::: Buffer is Full > */
            while (!U2STAbits.URXDA);
            /* < Read ::: Buffer > */
            *pxBuffer = (U2RXREG & 0x00FF);
        }
    }
}
