#ifndef LIBRARY_JOYSTICK_H
#define	LIBRARY_JOYSTICK_H

/* < Configuration Bits Settings > */
#include "xc.h"
/* < Configuration Main Settings > */
#include "main_typedefs.h"
#include "main_delays.h"

/* < Definicion ::: typeDefs :: JOYSTICK > */
typedef struct {

    union {
        uint16_t xRegisterJoystick;

        struct {
            unsigned xArrow_Up : 1;
            unsigned xArrow_Down : 1;
            unsigned xArrow_Left : 1;
            unsigned xArrow_Right : 1;
            unsigned xButton_A : 1;
            unsigned xButton_B : 1;
            unsigned xButton_X : 1;
            unsigned xButton_Y : 1;
            unsigned xButton_Z : 1;
            unsigned : 7;
        } Bits;
    } Buttons;

    struct {

        union {
            uint64_t xRegister;

            struct {
                uint16_t xValueAxisY;
                uint16_t xValueAxisX;
                uint16_t xValueLigth;
                uint16_t xValueTemp;
            } Words;
        } Union;
    } Analog;

} xBufferJoystick;

/* < Definicion ::: Pines de Control :: Boton Z del Joystick > */
#define TRIS_MUX_CHANNEL_A              TRISCbits.TRISC9
#define TRIS_MUX_CHANNEL_B              TRISCbits.TRISC8
#define TRIS_MUX_CHANNEL_C              TRISCbits.TRISC7

#define OUT_MUX_CHANNEL_A               LATCbits.LATC9
#define OUT_MUX_CHANNEL_B               LATCbits.LATC8
#define OUT_MUX_CHANNEL_C               LATCbits.LATC7

#define TRIS_INPUT_BUTTON_Z             TRISCbits.TRISC2
#define INPUT_BUTTON_Z                  PORTCbits.RC2

/* < Definicion ::: Direcciones :: Joystick "vProcessJoystickDigitalMode" > */
#define CHANNEL_BUTTON_A                0x01
#define CHANNEL_BUTTON_B                0x04
#define CHANNEL_BUTTON_X                0x02
#define CHANNEL_BUTTON_Y                0x06
#define CHANNEL_BUTTON_Z                0x08
#define CHANNEL_AXIS_X                  0x05
#define CHANNEL_AXIS_Y                  0x07
#define CHANNEL_READ_LIGHT              0x00
#define CHANNEL_READ_TEMP               0x03

/* < Definicion ::: Macros de Control > */
#define Dead_Zone_Joystick              320

/* < Defincicion ::: Macros de Control y Mascaras para Lectura de Entradas Digitales... > */
#define MASK_INPUT_JOYSTICK             0x000F
#define MASK_INPUT_JOYSTICK_HORIZONTAL  0x000C
#define MASK_INPUT_JOYSTICK_VERTICAL    0x0003
#define READ_INPUT_UP                   0x0001
#define READ_INPUT_DOWN                 0x0002
#define READ_INPUT_LEFT                 0x0004
#define READ_INPUT_RIGHT                0x0008

/* < Variables ::: Externa ::: Joystick... > */
extern xBufferJoystick xReadBufferJoystick;

/* < Prototipo ::: Funciones :: Configuracion : Joystick > */
void vJoystickConfiguration(void);
void vWriteAutoOuputMultiplexor(uint8_t *Channel);
void vWriteOuputMultiplexor(uint8_t Channel);
uint8_t xReadJoystickButtonZ(void);
void vProcessJoystickDigitalMode(uint8_t Channel, uint16_t Value);

#endif	/* < LIBRARY_JOYSTICK_H > */

