/* < Configuracon ::: Header > */
#include "source_config_system.h"

/* < Variables ::: Globales de Control :: Timers : Joystick > */
static uint16_t BufferConvertADC = 0;
static uint8_t CounterMux = 0;

/* < Funcion :: Threads for Timer System... > */
void vThreadTimerSystem(TimerHandle_t pxTimer) {
    /* < Declaracion ::: Variables Locales > */
    uint8_t IndiceTemporizadores = (size_t) pvTimerGetTimerID(pxTimer);

    /* < Determina ::: Timer Overflow > */
    switch (IndiceTemporizadores) {
            /* < - Refresh - Screen --------------------------------------- > */
        case 1:
            /* < Break ::: for DEBUG > */
            pdNop();
            /* < Drawing Buffer.... > */
            vGLCDDrawBuffer();
            break;
        case 2:
            /* < Break ::: for DEBUG > */
            pdNop();            
            /* < Start ::: Sampling> */
            AD1CON1bits.SAMP = pdSet;
            /* < While ::: Conversion Done... > */
            while (!AD1CON1bits.DONE);
            /* < Copy ::: Buffer ADC to Buffer Joystick > */
            BufferConvertADC = ADC1BUF0;
            /* < Process ::: Buffer into Control Joystick... > */
            vProcessJoystickDigitalMode(CounterMux, BufferConvertADC);
            /* < Seleccion :: Canal Conversor Analogo.. > */
            vWriteAutoOuputMultiplexor(&CounterMux);
            break;
    }
}
