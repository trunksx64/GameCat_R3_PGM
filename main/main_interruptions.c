/* < Include ::: Header >*/
#include "source_config_system.h"

/* < Vector ::: Interrupt :: CAN1... > */
void __attribute__((interrupt, auto_psv))_C1Interrupt(void) {
    /* < Variables ::: Locales > */
    BaseType_t xTaskWokenC1Interrupt = 0;
    xMessegeECAN_t ReceiveInterruptBufferCAN;
    /* < Check ::: Receive CAN Messege Interruption... > */
    if (C1INTFbits.RBIF) {
        /* < Break ::: for DEBUG > */
        pdNop();
        /* < Check ::: Buffer... > */
        if (C1RXFUL1bits.RXFUL3) {
            /* < Receive ::: Messege From Bus CAN... > */
            vCANModuleReceiveMessege(&ReceiveInterruptBufferCAN);
            /* < Send ::: Queue xQueueReceiveDataCAN > */
            xQueueSendFromISR(xQueueReceiveDataCAN, (void*) &ReceiveInterruptBufferCAN, &xTaskWokenC1Interrupt);            
        }
        if (C1RXFUL1bits.RXFUL4) {
            /* < Receive ::: Messege From Bus CAN... > */
            vCANModuleReceiveMessege(&ReceiveInterruptBufferCAN);
            /* < Send ::: Queue xQueueReceiveDataCAN > */
            xQueueSendFromISR(xQueueReceiveDataCAN, (void*) &ReceiveInterruptBufferCAN, &xTaskWokenC1Interrupt);            
        }
        if (C1RXFUL1bits.RXFUL5) {
            /* < Receive ::: Messege From Bus CAN... > */
            vCANModuleReceiveMessege(&ReceiveInterruptBufferCAN);
            /* < Send ::: Queue xQueueReceiveDataCAN > */
            xQueueSendFromISR(xQueueReceiveDataCAN, (void*) &ReceiveInterruptBufferCAN, &xTaskWokenC1Interrupt);            
        }
        if (C1RXFUL1bits.RXFUL6) {
            /* < Receive ::: Messege From Bus CAN... > */
            vCANModuleReceiveMessege(&ReceiveInterruptBufferCAN);
            /* < Send ::: Queue xQueueReceiveDataCAN > */
            xQueueSendFromISR(xQueueReceiveDataCAN, (void*) &ReceiveInterruptBufferCAN, &xTaskWokenC1Interrupt);            
        }
        if (C1RXFUL1bits.RXFUL7) {
            /* < Receive ::: Messege From Bus CAN... > */
            vCANModuleReceiveMessege(&ReceiveInterruptBufferCAN);
            /* < Send ::: Queue xQueueReceiveDataCAN > */
            xQueueSendFromISR(xQueueReceiveDataCAN, (void*) &ReceiveInterruptBufferCAN, &xTaskWokenC1Interrupt);            
        }
        /* < Clear ::: Flag Interrupt... > */
        C1INTFbits.RBIF = pdClear;
    } else if (C1INTFbits.TBIF) {
        /* < Break ::: for DEBUG > */
        pdNop();
        /* < Clear ::: Flag Interrupt... > */
        C1INTFbits.TBIF = pdClear;
    }
    /* < Control de Contexto Rtos > */
    if (xTaskWokenC1Interrupt) taskYIELD();
    /* < Clear ::: Flag Interrupt... > */
    IFS2bits.C1IF = pdClear;
}

void __attribute__((interrupt, auto_psv)) _U1RXInterrupt(void) {
    /* < Break ::: for DEBUG > */
    pdNop();
    /* < Borra la Bandera de la Interrupción > */
    IFS0bits.U1RXIF = pdClear;
}

/* < Vector ::: Interrupt :: U1RX... > */
void __attribute__((interrupt, auto_psv)) _U1TXInterrupt(void) {
    /* < Break ::: for DEBUG > */
    pdNop();
    /* < Borra la Bandera de la Interrupción > */
    IFS0bits.U1TXIF = pdClear;
}