/* < Include ::: Headers > */
#include "library_glcd_pcd8544.h"

/* < Declaracion ::: Variables ::: Buffer GLCD_PCD8544 > */
uint8_t FrameBuffer[GLCD_RESOLUTION];

/* < Prototipo ::: Funciones de Control ::: GLCD_PCD8544 > */
void vConfigureGLCD(uint8_t Constrast, uint8_t Temp, uint8_t Bias) {
    /* < Configuracion ::: Puertos y Registros I/O > */
    TRIS_GLCD_RES = pdClear;
    TRIS_GLCD_DC = pdClear;
    TRIS_GLCD_DIN = pdClear;
    TRIS_GLCD_CLK = pdClear;
    /* < Secuencia ::: Start Glcd > */
    GLCD_PULSE_RESET(); // < Secuencia de Start
    vGLCDCommand(GLCD_FUNCTION_SET | GLCD_EXTENDED_INSTRUCTION); // < LCD Extended Commands
    vGLCDCommand(GLCD_SET_VOP | Constrast); // < Set LCD Vop (Contrast)
    vGLCDCommand(GLCD_SET_TEMP | Temp); // < Set Temp Coefficent
    vGLCDCommand(GLCD_SET_BIAS | Bias); // < LCD Bias mode 1:48
    vGLCDCommand(GLCD_FUNCTION_SET); // < LCD back to standard instructions    
    vGLCDCommand(GLCD_DISPLAY_CONTROL | GLCD_DISPLAY_NORMAL); // < LCD in normal mode       
}

void vGLCDCommand(uint8_t Command) {
    GLCD_CONTROL_COMMAND(); // < Select Command
    WriteDataGLCD(Command); // < Send Command 
}

void vGLCDData(uint8_t Data) {
    GLCD_CONTROL_DATA(); // < Select Data
    WriteDataGLCD(Data); // < Send Data   
}

void vGLCDGotoxy(uint8_t X, uint8_t Y) {
    vGLCDCommand(GLCD_SET_ADDR_Y | (Y > 5 ? 5 : Y)); // < LCD Set Y address of RAM    
    vGLCDCommand(GLCD_SET_ADDR_X | (X & 127)); // < LCD Set X address of RAM
}

void vGLCDFill(uint8_t Data) {
    /* < Variables ::: Locales > */
    uint16_t Length = GLCD_RESOLUTION;
    /* < Set Address (0,0) > */
    vGLCDGotoxy(0, 0);
    GLCD_CONTROL_DATA(); // < Select Data
    while (Length--) WriteDataGLCD(Data); // Send Data           
}

void vGLCDPowerDown(void) {
    /* < Fill RAM with zeroes to ensure minimum specified current consumption > */
    vGLCDFill(0);
    /* < Power Down > */
    vGLCDCommand(GLCD_FUNCTION_SET | GLCD_POWER_DOWN);
}

void vGLCDPowerUp(void) {
    /* < Power Up > */
    vGLCDCommand(GLCD_FUNCTION_SET);
}

void vGLCDContrast(uint8_t Contrastc) {
    /* < LCD Extended Commands > */
    vGLCDCommand(GLCD_FUNCTION_SET | GLCD_EXTENDED_INSTRUCTION);
    /* < Set LCD Vop (Contrast) > */
    vGLCDCommand(GLCD_SET_VOP | (Contrastc & 0x7F));
    /* < LCD back to standard instructions > */
    vGLCDCommand(GLCD_FUNCTION_SET);
    /* < LCD in normal mode > */
    vGLCDCommand(GLCD_DISPLAY_CONTROL | GLCD_DISPLAY_NORMAL);
}

void vGLCDInvert(uint8_t Mode) {
    if (Mode == GLCD_NORMAL_VIEW) vGLCDCommand(GLCD_DISPLAY_CONTROL | GLCD_DISPLAY_NORMAL);
    else vGLCDCommand(GLCD_DISPLAY_CONTROL | GLCD_DISPLAY_INVERTED);
}

void vGLCDDrawPixel(uint8_t X, uint8_t Y, uint8_t Color) {
    /* < Comprueba ::: Limites del GLCD > */
    if ((X < GLCD_WIDTH) && (Y < GLCD_HEIGHT)) {
        if (Color) FrameBuffer[X + (Y / 8) * GLCD_WIDTH] |= (0x01 << (Y % 8));
        else FrameBuffer[X + (Y / 8) * GLCD_WIDTH] &= ~(0x01 << (Y % 8));
    }
}

void vGLCDClearBuffer(void) {
    /* < Clear ::: Frame Buffer > */
    memset(FrameBuffer, 0x00, GLCD_RESOLUTION);
}

void vGLCDDrawBuffer(void) {
    /* < Variables ::: Locales > */
    uint16_t Length = GLCD_RESOLUTION;
    uint8_t *Wrptr = FrameBuffer;
    /* < Set Address (0,0) > */
    vGLCDGotoxy(0, 0);
    GLCD_CONTROL_DATA(); // < Select Data
    /* < Send Data ::: Frame Buffer > */
    while (Length--) WriteDataGLCD(*Wrptr++);
}
