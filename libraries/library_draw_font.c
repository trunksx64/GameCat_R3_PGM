/* < Include ::: Headers > */
#include "library_draw_font.h"

/* < Variables ::: Globales de Control > */
SelectFont SelectedFont;

/* < Prototipo ::: Funciones de Control :: Draw Font Arial >*/
void vSelectSetFont(const uint8_t *pxFont, uint8_t Width, uint8_t Height) {
    /* < Seleccion de Fuente>*/
    SelectedFont.Font = pxFont;
    SelectedFont.Width = (Width + 0x01);
    SelectedFont.Height = (Height + 0x01);
    SelectedFont.SetX = 0x00;
    SelectedFont.SetY = 0x00;
    SelectedFont.SetZ = 0x00;
}

uint8_t xPutCharGlcd(uint8_t X, uint8_t Y, uint8_t Color, char Character) {
    /* < Variables ::: Locales > */
    uint8_t Count1;
    uint8_t Count2;
    /* < Determina ::: Caracter de Control > */
    if (iscntrl(Character)) {
        /* < Ejecuta ::: Caracter de Control > */
        switch (Character) {
            case '\a':
                /* < Set Position (0,0) >*/
                SelectedFont.SetX = 0x00;
                SelectedFont.SetY = 0x00;
                break;
            case '\f':
                /* < Clear Screen >*/
                ClearScreen();
                /* < Set Position (0,0) >*/
                SelectedFont.SetX = 0x00;
                SelectedFont.SetY = 0x00;
                break;
            case '\n':
                /* < Jump Line > */
                SelectedFont.SetX = 0x00;
                SelectedFont.SetY += SelectedFont.Height;
                SelectedFont.SetZ = 0x00;
                break;
            case '\b':
                /* < Back Character > */
                SelectedFont.SetX -= (SelectedFont.SetZ + 1);
                SelectedFont.SetZ = 0x00;
                break;
            case '\r':
                SelectedFont.SetX = X;
                SelectedFont.SetY = Y;
                break;
        }
    }/* < Determina ::: Caracter a Imprimir > */
    else if (isprint(Character)) {
        /* < Lectura ::: Parametros >*/
        SelectedFont.SetZ = SelectedFont.Font[((Character - 0x20) * SelectedFont.Width)];
        /* < Dibuja el Caracter... (Width) >*/
        for (Count1 = 0x00; Count1 < SelectedFont.SetZ; Count1++) {
            /* < Dibuja el Caracter... (Height) >*/
            for (Count2 = 0x00; Count2 < SelectedFont.Height; Count2++) {
                /* < Evalua el Pixel del Caracter... >*/
                if ((SelectedFont.Font[((Character - 0x20) * SelectedFont.Width)+(Count1 + 1)])&(1 << Count2)) {
                    /* < Draw Pixel >*/
                    DrawingPixelFont((X + Count1), (Y + Count2), Color);
                }
            }
        }
    }

    /* < Return ::: Width if Character >*/
    return (SelectedFont.SetZ);
}

void vPutsCharGlcd(uint8_t X, uint8_t Y, uint8_t Color, const char *pxChars) {
    /* < Variables ::: Locales >*/
    uint8_t Width = 0x00;

    /* < Alignment > */
    switch (X) {
        case ALIGMENT_FONT_LEFT:
            /* < Copy ::: Cordenadas >*/
            SelectedFont.SetX = 0x00;
            SelectedFont.SetY = Y;
            break;
        case ALIGMENT_FONT_RIGHT:
            /* < Copy ::: Cordenadas >*/
            SelectedFont.SetX = (GLCD_WIDTH - xCountPixelsText(pxChars));
            SelectedFont.SetY = Y;
            break;
        case ALIGMENT_FONT_CENTER:
            /* < Copy ::: Cordenadas >*/
            SelectedFont.SetX = (((GLCD_WIDTH + 3) - xCountPixelsText(pxChars)) / 0x02);
            SelectedFont.SetY = Y;
            break;
        default:
            /* < Copy ::: Cordenadas >*/
            SelectedFont.SetX = X;
            SelectedFont.SetY = Y;
            break;
    }

    /* < Dibuja la Cadena de Caracteres... >*/
    while (*pxChars != '\0') {
        /* < Variables ::: Locales >*/
        Width = xPutCharGlcd(SelectedFont.SetX, SelectedFont.SetY, Color, *pxChars++);
        /* < Ajust Next Character >*/
        SelectedFont.SetX += (Width + 0x01);
    }
}

uint8_t xCountPixelsText(const char *pxChars) {
    /* < Variables ::: Locales > */
    uint8_t Pixels = 0x00;

    /* < Cuenta los Pixeles del Texto > */
    while (*pxChars != '\0')
        Pixels += (SelectedFont.Font[(((*pxChars++) - 0x20) * SelectedFont.Width)] + 0x01);
    /* < Return ::: # Pixels >*/
    return (Pixels);
}
