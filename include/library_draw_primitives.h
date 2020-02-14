#ifndef LIBRARY_DRAW_PRIMITIVES_H
#define	LIBRARY_DRAW_PRIMITIVES_H

/* < Configuration Bits Settings > */
#include "xc.h"
/* < Configuration Main Settings > */
#include "main_typedefs.h"
#include "main_delays.h"
/* < Configuration Libraries Settings > */
#include "library_glcd_pcd8544.h"

/* < Definicion ::: Macros de Control :: Draw Primitives > */
#define vDrawPixel(Z,Y,C)                   vGLCDDrawPixel(Z,Y,C)     // < Fuction Draw Pixels

/* < Definicion ::: Macros Draw Lines :: Draw Primitives > */
#define vDrawVerticalLine(X, Y, H, Color)   vDrawLine(X, Y, X, (Y+H-1), Color)
#define vDrawHorizontalLine(X, Y, W, Color) vDrawLine(X, Y, (X+W-1), Y, Color)

/* < Prototipo ::: Funciones de Control :: Draw Primitives : Dato en Buffer > */
void vDrawCircle(uint8_t X, uint8_t Y, uint8_t R, uint8_t Color);
void vDrawCircleHelper(uint8_t X, uint8_t Y, uint8_t R, uint8_t C, uint8_t Color);
void vDrawFillCircleHelper(uint8_t X, uint8_t Y, uint8_t R, uint8_t C, uint8_t D, uint8_t Color);
void vDrawFillCircle(uint8_t X, uint8_t Y, uint8_t R, uint8_t Color);
void vDrawLine(uint8_t X1, uint8_t Y1, uint8_t X2, uint8_t Y2, uint8_t Color);
void vDrawRectangle(uint8_t X, uint8_t Y, uint8_t W, uint8_t H, uint8_t Color);
void vDrawFillRectangle(uint8_t X, uint8_t Y, uint8_t W, uint8_t H, uint8_t Color);
void vDrawRoundRectangle(uint8_t X, uint8_t Y, uint8_t W, uint8_t H, uint8_t R, uint8_t Color);
void vDrawFillRoundRectangle(uint8_t X, uint8_t Y, uint8_t W, uint8_t H, uint8_t R, uint8_t Color);
void vDrawTriangle(uint8_t X1, uint8_t Y1, uint8_t X2, uint8_t Y2, uint8_t X3, uint8_t Y3, uint8_t Color);
void vDrawFillTriangle(uint8_t X1, uint8_t Y1, uint8_t X2, uint8_t Y2, uint8_t X3, uint8_t Y3, uint8_t Color);

/* < Prototipo ::: Funciones de Control :: Draw Bitmaps : Datos en Buffer > */
void vGLCDBufferDrawBitmap(uint8_t X, uint8_t Y, uint8_t Color, const uint8_t *pxBuffer);

#endif	/* < LIBRARY_DRAW_PRIMITIVES_H > */

