#ifndef LIBRARY_MANAGEMENT_PULSES_H
#define	LIBRARY_MANAGEMENT_PULSES_H

/* < Configuration Bits Settings > */
#include <xc.h>
/* < Configuration Main Settings > */
#include "main_typedefs.h"
#include "main_delays.h"

/* < Definicion ::: Variables :: Typedef's > */
typedef struct {
    uint1_t uxCurrentInput;
    uint1_t uxPastInput;
    uint16_t uxTimeControl;
} xCheckInputPulse;

/* < Define ::: Controles :: Library-Management-Inputs > */
#define DIRECT_LOGIC     0x01 // Al pulsar 1 se recibe un 1
#define REVERSE_LOGIC    0x00 // Al pulsar 0 se recibe un 1

#define REPEAT_OFF       0x00 // La tecla al Ser pulsada, la Salida No se Repite
#define REPEAT_ON        0x01 // La tecla se mantiene pulsada, la Salida es Incremental
#define REPEAT_HOLD      0x02 // La tecla se mantiene pulsada, la Salida Permanece Constante
#define RELEALSE_BUTTON  0x03 // La tecla al Ser pulsada, la Salida se Activa al Liberar el Boton
#define RELEALSE_TIME    0x04 // La tecle al ser pulsada, Activa la Salida, Si se Sostiene Activa el Tiempo

/* < Prototipo ::: Funciones de Control :: Library-Management-Inputs > */
uint8_t xReadSinglePulse(uint8_t Input, uint8_t Logic);
int8_t xReadRepeatPulse(xCheckInputPulse *Index, uint8_t Input, uint8_t Logic, uint8_t Control);

#endif	/* < LIBRARY_MANAGEMENT_PULSES_H > */

