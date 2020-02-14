#ifndef LIBRARY_GLCD_PCD8544_H
#define	LIBRARY_GLCD_PCD8544_H

/* < Configuration Bits Settings > */
#include "xc.h"
/* < Configuration Main Settings > */
#include "main_typedefs.h"
#include "main_delays.h"
/* < Configuration Drivers Settings > */
#include "driver_serial_peripheral_interface_one.h"

/* < Definicion ::: Pines de Control :: GLCD_PCD8544 > */
#define TRIS_GLCD_RES                   TRISAbits.TRISA7
#define TRIS_GLCD_DC                    TRISBbits.TRISB5
#define TRIS_GLCD_DIN                   TRISBbits.TRISB6
#define TRIS_GLCD_CLK                   TRISBbits.TRISB7

#define PORT_GLCD_RES                   LATAbits.LATA7
#define PORT_GLCD_DC                    LATBbits.LATB5
#define PORT_GLCD_DIN                   LATBbits.LATB6
#define PORT_GLCD_CLK                   LATBbits.LATB7

/* < Definicion ::: Opciones de Configuracion :: GLCD_PCD8544 > */
#define GLCD_WIDTH                      84  // < Ancho <(X)> ::: 84 Pixeles
#define GLCD_HEIGHT                     48  // < Alto  <(Y)> ::: 48 Pixeles
#define GLCD_RESOLUTION                 504 // < Resolution ((GLCD_WIDTH * GLCD_HEIGHT) / 8)

/* < Definicion ::: Opciones de Pantalla :: GLCD_PCD8544 > */
#define GLCD_NORMAL_VIEW                0x00
#define GLCD_INVERT_VIEW                0x01
#define GLCD_PIXEL_BLACK                0x01
#define GLCD_PIXEL_WHITE                0x00

/* < Definicion ::: Comandos :: GLCD_PCD8544 > */
#define GLCD_POWER_DOWN                 0x04
#define GLCD_ENTRY_MODE                 0x02
#define GLCD_EXTENDED_INSTRUCTION       0x01
#define GLCD_DISPLAY_BLANK              0x00
#define GLCD_DISPLAY_NORMAL             0x04
#define GLCD_DISPLAY_ALL_ON             0x01
#define GLCD_DISPLAY_INVERTED           0x05

/* < Definicion ::: Instruction Set :: GLCD_PCD8544 > */
#define GLCD_FUNCTION_SET               0x20
#define GLCD_DISPLAY_CONTROL            0x08
#define GLCD_SET_ADDR_Y                 0x40
#define GLCD_SET_ADDR_X                 0x80

/* < Definicion ::: Instruction Set Extend :: GLCD_PCD8544 > */
#define GLCD_SET_TEMP                   0x04
#define GLCD_SET_BIAS                   0x10
#define GLCD_SET_VOP                    0x80

/* < Definicion ::: Coeficiente de Temperatura :: GLCD_PCD8544 > */
#define GLCD_TEMP_C_0                   0x00
#define GLCD_TEMP_C_1                   0x01
#define GLCD_TEMP_C_2                   0x02
#define GLCD_TEMP_C_3                   0x03

/* < Definicion ::: Value Bias :: GLCD_PCD8544 > */
#define GLCD_BIAS_1_100                 0x00
#define GLCD_BIAS_1_80                  0x01
#define GLCD_BIAS_1_65                  0x02
#define GLCD_BIAS_1_48                  0x03
#define GLCD_BIAS_1_40                  0x04
#define GLCD_BIAS_1_24                  0x05
#define GLCD_BIAS_1_18                  0x06
#define GLCD_BIAS_1_10                  0x07

/* < Definicion ::: Macros de Control :: GLCD_PCD8544... > */
#define GLCD_PULSE_RESET()              PORT_GLCD_RES = pdClear;    \
                                        __delay_ms(30);             \
                                        PORT_GLCD_RES = pdSet

#define GLCD_CONTROL_COMMAND()          PORT_GLCD_DC = pdClear
#define GLCD_CONTROL_DATA()             PORT_GLCD_DC = pdSet

/* < Definicion ::: Macros de Control :: GLCD_PCD8544... > */
#define WriteDataGLCD(Data)             xWriteReadSPIModuleOne(Data)

/* < Prototipo ::: Funciones de Control ::: GLCD_PCD8544 > */
void vConfigureGLCD(uint8_t Constrast, uint8_t Temp, uint8_t Bias);

void vGLCDCommand(uint8_t Command);
void vGLCDData(uint8_t Data);
void vGLCDGotoxy(uint8_t X, uint8_t Y);

void vGLCDFill(uint8_t Data);
void vGLCDPowerDown(void);
void vGLCDPowerUp(void);

void vGLCDContrast(uint8_t Contrastc);
void vGLCDInvert(uint8_t Mode);
void vGLCDDrawPixel(uint8_t X, uint8_t Y, uint8_t Color);
void vGLCDClearBuffer(void);
void vGLCDDrawBuffer(void);

#endif	/* < LIBRARY_GLCD_PCD8544_H > */

