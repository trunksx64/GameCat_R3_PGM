/* < Include ::: Header >*/
#include "library_joystick.h"

/* < Variables ::: Externa ::: Joystick... > */
xBufferJoystick xReadBufferJoystick;

/* < Prototipo ::: Funciones :: Configuracion : Joystick > */
void vJoystickConfiguration(void) {
    /* < Configuracion ::: Puertos y Registros I/O > */
    TRIS_INPUT_BUTTON_Z = pdSet;
    TRIS_MUX_CHANNEL_A = pdClear;
    TRIS_MUX_CHANNEL_B = pdClear;
    TRIS_MUX_CHANNEL_C = pdClear;
    /* < Configuracion ::: Puertos y Registros I/O > */
    OUT_MUX_CHANNEL_A = pdClear;
    OUT_MUX_CHANNEL_B = pdClear;
    OUT_MUX_CHANNEL_C = pdClear;
    /* < Clear ::: xReadBufferJoystick > */
    memset(&xReadBufferJoystick, 0, sizeof (xReadBufferJoystick));
}

void vWriteAutoOuputMultiplexor(uint8_t *Channel) {
    /* < Control de Conteo de Canal... > */
    if (*Channel < 0x08) {
        /* < Incrementa el Contador del Mux... > */
        *Channel += 0x01;
        /* < Chequea ::: Que el Valor este Dentro del Conteo de Direccionamiento... >*/
        if (*Channel <= 0x07) {
            /* < Seleccion ::: Channel Multiplexor > */
            OUT_MUX_CHANNEL_A = !!(*Channel & 0x01);
            OUT_MUX_CHANNEL_B = !!(*Channel & 0x02);
            OUT_MUX_CHANNEL_C = !!(*Channel & 0x04);
        }
    } else {
        *Channel = 0x00;
    }
}

void vWriteOuputMultiplexor(uint8_t Channel) {
    /* < Chequea ::: Que el Valor este Dentro del Conteo de Direccionamiento... >*/
    if (Channel <= 0x07) {
        /* < Seleccion ::: Channel Multiplexor > */
        OUT_MUX_CHANNEL_A = !!(Channel & 0x01);
        OUT_MUX_CHANNEL_B = !!(Channel & 0x02);
        OUT_MUX_CHANNEL_C = !!(Channel & 0x04);
    }
}

uint8_t xReadJoystickButtonZ(void) {
    /* < Read ::: Button Z... > */
    return ((INPUT_BUTTON_Z == pdFalse) ? pdSet : pdClear);
}

void vProcessJoystickDigitalMode(uint8_t Channel, uint16_t Value) {
    /* < Seleccion ::: Entrada a registrar > */
    switch (Channel) {
        case CHANNEL_BUTTON_A:
            /* < Saved value Into the Buffer Joystick... >*/
            xReadBufferJoystick.Buttons.Bits.xButton_A = (Value > (512 + Dead_Zone_Joystick) ? pdClear : pdSet);
            break;
        case CHANNEL_BUTTON_B:
            /* < Saved value Into the Buffer Joystick... >*/
            xReadBufferJoystick.Buttons.Bits.xButton_B = (Value > (512 + Dead_Zone_Joystick) ? pdClear : pdSet);
            break;
        case CHANNEL_BUTTON_X:
            /* < Saved value Into the Buffer Joystick... >*/
            xReadBufferJoystick.Buttons.Bits.xButton_X = (Value > (512 + Dead_Zone_Joystick) ? pdClear : pdSet);
            break;
        case CHANNEL_BUTTON_Y:
            /* < Saved value Into the Buffer Joystick... >*/
            xReadBufferJoystick.Buttons.Bits.xButton_Y = (Value > (512 + Dead_Zone_Joystick) ? pdClear : pdSet);
            break;
        case CHANNEL_BUTTON_Z:
            /* < Saved value Into the Buffer Joystick... >*/
            xReadBufferJoystick.Buttons.Bits.xButton_Z = ((INPUT_BUTTON_Z == pdFalse) ? pdSet : pdClear);
            break;
        case CHANNEL_AXIS_X:
            /* < Read :: Value... > */
            xReadBufferJoystick.Analog.Union.Words.xValueAxisX = Value;
            /* < Selectec Digital Arrow... > */
            xReadBufferJoystick.Buttons.Bits.xArrow_Left = ((Value > (512 + Dead_Zone_Joystick)) ? pdSet : pdClear);
            xReadBufferJoystick.Buttons.Bits.xArrow_Right = ((Value < (512 - Dead_Zone_Joystick)) ? pdSet : pdClear);
            break;
        case CHANNEL_AXIS_Y:
            /* < Read :: Value... > */
            xReadBufferJoystick.Analog.Union.Words.xValueAxisY = Value;
            /* < Selectec Digital Arrow... > */
            xReadBufferJoystick.Buttons.Bits.xArrow_Up = ((Value < (512 - Dead_Zone_Joystick)) ? pdSet : pdClear);
            xReadBufferJoystick.Buttons.Bits.xArrow_Down = ((Value > (512 + Dead_Zone_Joystick)) ? pdSet : pdClear);
            break;
        case CHANNEL_READ_LIGHT:
            /* < Read :: Value... > */
            xReadBufferJoystick.Analog.Union.Words.xValueLigth = Value;
            break;
        case CHANNEL_READ_TEMP:
            /* < Read :: Value... > */
            xReadBufferJoystick.Analog.Union.Words.xValueTemp = Value;
            break;
    }
}
