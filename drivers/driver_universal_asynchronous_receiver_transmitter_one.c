/* < Include ::: Headers > */
#include "driver_universal_asynchronous_receiver_transmitter_one.h"

/* < Prototipo ::: Funciones de Control ::: UART_TO_USB > */
void vConfigureUartOne(uint16_t Config_INT, uint16_t Config_1, uint16_t Config_2, uint32_t Baud) {
    /* < Habilita ::: Modulo UART_TO_USB > */
    PMD1bits.U1MD = pdClear;
    /* < Configuracion ::: Puertos y Registros I/O > */
    TRIS_UART1_TX = pdClear;
    TRIS_UART1_RX = pdSet;
    /* < .:: Configuracion del Modulo UART_TO_USB ::: Multiplexor de Salida (PIC24H) ::. > */
    __builtin_write_OSCCONL(OSCCON &~(0x40));
    RPOR9bits.RP19R = 0b00011; // < RP19 tied to UART1 Transmit   
    RPINR18bits.U1RXR = 0b10100; // < Input tied to RP20 UART1 Receive
    __builtin_write_OSCCONL(OSCCON | 0x40);
    /* < Configuracion ::: Operation Settings :: UART_TO_USB > */
    U1MODE = (Config_1 & 0x7FFF);
    U1STA = (Config_2 & 0xFBFF);
    /* < Configuracion ::: Baud Rate UART_TO_USB > */
    if (Config_1 & UART1_BRGH_FOUR) U1BRG = (((FCY / Baud) / 4) - 1);
    else U1BRG = (((FCY / Baud) / 16) - 1);
    /* < Configuracion ::: Interruption :: UART_TO_USB : TX > */
    IFS0bits.U1TXIF = 0x00;
    IEC0bits.U1TXIE = (0x8000 & Config_INT) >> 0x0F;
    IPC3bits.U1TXIP = (0x0700 & Config_INT) >> 0x08;
    /* < Configuracion ::: Interruption :: UART_TO_USB : RX > */
    IFS0bits.U1RXIF = 0x00; // < Clear flags        
    IEC0bits.U1RXIE = (0x0080 & Config_INT) >> 0x07;
    IPC2bits.U1RXIP = (0x0007 & Config_INT); // < Set priority    
    /*PC2 < Enable UART_TO_USB... > */
    U1MODE |= (Config_1 & 0x8000); // < Enable RX
    U1STA |= (Config_2 & 0x0400); // < Enalbe TX
}

uint8_t xBusyUartOne(void) {
    return (!U1STAbits.TRMT);
}

uint8_t xDataReadyUartOne(void) {
    return (U1STAbits.URXDA);
}

uint16_t xReadUartOne(void) {
    /* < Check ::: Data Ready > */
    if (U1STAbits.URXDA) {
        /* < Check ::: 9-bit data > */
        if (U1MODEbits.PDSEL == 0b11) return (U1RXREG & 0x01FF);
        else return (U1RXREG & 0x00FF);
    }
    /* < Return ::: Void > */
    return (pdClear);
}

void vWriteUartOne(uint16_t Data) {
    /* < Wait ::: Buffer is Clear > */
    while (U2STAbits.UTXBF);
    /* < Check ::: 9-bit data > */
    if (U1MODEbits.PDSEL == 0b11) U1TXREG = (Data & 0x01FF);
    else U1TXREG = (Data & 0x00FF);
    /* < Wait ::: Buffer is Send > */
    while (!U1STAbits.TRMT);
}

void vPutsUartOne(uint8_t Length, uint8_t *pxBuffer) {
    /* < Variables ::: Locales > */
    uint16_t *Ptr = (uint16_t *) pxBuffer;
    /* < Check ::: 9-bit data > */
    if (U1MODEbits.PDSEL == 0b11) {
        /* < While ::: Send Length Buffer > */
        while (Length--) {
            /* < Decrement ::: Length > */
            Length--;
            /* < Wait ::: Buffer is Clear > */
            while (U1STAbits.UTXBF);
            /* < Write ::: to Buffer > */
            U1TXREG = (*Ptr++ & 0x01FF);
            /* < Wait ::: Buffer is Send > */
            while (!U1STAbits.TRMT);
        }
    } else {
        /* < While ::: Send Length Buffer > */
        while (Length--) {
            /* < Wait ::: Buffer is Clear > */
            while (U1STAbits.UTXBF);
            /* < Write ::: to Buffer > */
            U1TXREG = (*pxBuffer++ & 0x00FF);
            /* < Wait ::: Buffer is Send > */
            while (!U1STAbits.TRMT);
        }
    }
}

void vGetsUartOne(uint8_t Length, uint8_t *pxBuffer) {
    /* < Variables ::: Locales > */
    uint16_t *Ptr = (uint16_t *) pxBuffer;
    /* < Check ::: 9-bit data > */
    if (U1MODEbits.PDSEL == 0b11) {
        /* < While ::: Receive Length Buffer > */
        while (Length--) {
            /* < Decrement ::: Length > */
            Length--;
            /* < Wait ::: Buffer is Full > */
            while (!U1STAbits.URXDA);
            /* < Read ::: Buffer > */
            *Ptr = (U1RXREG & 0x01FF);
        }
    } else {
        /* < While ::: Receive Length Buffer > */
        while (Length--) {
            /* < Wait ::: Buffer is Full > */
            while (!U1STAbits.URXDA);
            /* < Read ::: Buffer > */
            *pxBuffer = (U1RXREG & 0x00FF);
        }
    }
}
