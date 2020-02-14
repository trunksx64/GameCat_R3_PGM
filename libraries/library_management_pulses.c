/* < Configuracion ::: Header > */
#include "library_management_pulses.h"

/* < Funciones de Control :: Library-Management-Inputs > */
uint8_t xReadSinglePulse(uint8_t Input, uint8_t Logic) {
    /* < Read ::: Input > */
    if ((!Input && (Logic == pdFalse)) || (Input && (Logic == pdTrue))) {
        return (pdSet);
    } else {
        return (pdClear);
    }
}

int8_t xReadRepeatPulse(xCheckInputPulse *Index, uint8_t Input, uint8_t Logic, uint8_t Control) {
    /* < Variables ::: Locales > */
    uint8_t xReturn = pdClear;

    /* < Tipo de Ejecucion... >*/
    if (Control == REPEAT_OFF) { // < Salida No Constante... 
        /* < Update ::: Registers... > */
        Index->uxPastInput = Index->uxCurrentInput;
        Index->uxCurrentInput = Input;
        /* < Read ::: Input and Control... > */
        if (xReadSinglePulse(Input, Logic)) {
            /* < Si la Salida es Mayor :: Habilita.. > */
            if (Index->uxCurrentInput > Index->uxPastInput) {
                /* < Set ::: Output > */
                xReturn = pdSet;
            } else {
                /* < Clear ::: Output > */
                xReturn = pdClear;
            }
        }
    } else if (Control == REPEAT_ON) { // < Salida Incremental...
        /* < Read ::: Input and Control... > */
        if (xReadSinglePulse(Input, Logic)) {
            /* < Chequea si hay Control de Tiempo Set... > */
            if (Index->uxTimeControl == pdFalse) {
                /* < Enable ::: Counter Control... > */
                Index->uxTimeControl = pdSet;
                /* < Set ::: Output > */
                xReturn = pdSet;
            }
        }
        /* < Control de Repeticion... > */
        if (Index->uxTimeControl > 0x00) ++(Index->uxTimeControl);
        /* < Auto Repeticion... > */
        if (Control == REPEAT_ON) {
            /* < Chequea los valores del Contador > */
            if (Index->uxTimeControl >= (10) && Index->uxTimeControl % (1))xReturn = pdSet;
            else if (Index->uxTimeControl >= (100) && Index->uxTimeControl % (10))xReturn = pdSet;
            else if (Index->uxTimeControl >= (1000) && Index->uxTimeControl % (100))xReturn = pdSet;
        }
    } else if (Control == RELEALSE_BUTTON) { // < la Salida se Activa al Liberar el Boton
        /* < Read ::: Input and Control... > */
        if (xReadSinglePulse(Input, Logic)) {
            /* < Update ::: Registers... > */
            Index->uxPastInput = Input;
        } else if (Index->uxPastInput > Input) { // < Si la Salida es Mayor :: Habilita.. 
            /* < Update ::: Registers... > */
            Index->uxPastInput = pdClear;
            /* < Set ::: Output > */
            xReturn = pdSet;
        }
    } else if (Control == RELEALSE_TIME) {
        /* < Read ::: Input and Control... > */
        if (xReadSinglePulse(Input, Logic)) {
            /* < Update ::: Registers... > */
            Index->uxPastInput = Input;
            /* <  Incremento del Tiempo >*/
            Index->uxTimeControl++;
        } else if (Index->uxPastInput > Input) {
            /* < Check ::: Time for Value Return > */
            if (Index->uxTimeControl > 10) {
                /* < Program ::: Output > */
                xReturn = pdProgram;
            } else {
                /* < Set ::: Output > */
                xReturn = pdSet;
            }
            /* < Update ::: Registers... > */
            Index->uxPastInput = pdClear;
            Index->uxTimeControl = pdClear;
        }
    } else { // < Salida Permanente
        /* < Read ::: Input and Control... > */
        if (xReadSinglePulse(Input, Logic)) {
            /* < Set ::: Output > */
            xReturn = pdSet;
        }
    }
    /* < Resultado de la Pulsacion... > */
    return (xReturn);
}
