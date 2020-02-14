#ifndef LIBRARY_DRAW_FONT_H
#define	LIBRARY_DRAW_FONT_H

/* < Configuration Bits Settings > */
#include "xc.h"
/* < Configuration Main Settings > */
#include "main_typedefs.h"
#include "main_delays.h"
/* < Configuration Libraries Settings > */
#include "library_glcd_pcd8544.h"

/* < Definicion ::: TypeDefs > */
typedef struct {
    const uint8_t *Font;
    uint8_t Width;
    uint8_t Height;
    uint8_t SetX;
    uint8_t SetY;
    uint8_t SetZ;
} SelectFont;

/* < Definicion ::: Configuracion :: Alineamiento >*/
#define ALIGMENT_FONT_LEFT      ((uint8_t ) 253)
#define ALIGMENT_FONT_RIGHT     ((uint8_t ) 254)
#define ALIGMENT_FONT_CENTER    ((uint8_t ) 255)

/* < Definicion ::: Macros de Control :: Draw Font >*/
#define DrawingPixelFont(x,y,c) vGLCDDrawPixel(x,y,c)          // <- Fuction Draw Pixels
#define ClearScreen()           vGLCDClearBuffer()        // <- Limpia la Pantalla

/* < Variables ::: Globales :: Control Execute Menu : Extern >*/
extern SelectFont SelectedFont;

/* < Prototipo ::: Funciones de Control :: Draw Font Arial >*/
void vSelectSetFont(const uint8_t *pxFont, uint8_t Width, uint8_t Height);
uint8_t xPutCharGlcd(uint8_t X, uint8_t Y, uint8_t Color, char Character);
void vPutsCharGlcd(uint8_t X, uint8_t Y, uint8_t Color, const char *pxChars);
uint8_t xCountPixelsText(const char *pxChars);

#endif	/* < LIBRARY_DRAW_FONT_H > */

