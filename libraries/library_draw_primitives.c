/* < Include ::: Headers > */
#include "library_draw_primitives.h"

/* < Funciones de Control :: Primitivas : Dato en Buffer > */
void vDrawCircle(uint8_t X, uint8_t Y, uint8_t R, uint8_t Color) {
    /* < Variables ::: Locales > */
    int8_t F = (1 - R);
    int8_t DDx = 1;
    int8_t DDy = -2 * R;
    int8_t Tx = 0;
    int8_t Ty = R;

    vDrawPixel(X, Y + R, Color);
    vDrawPixel(X, Y - R, Color);
    vDrawPixel(X + R, Y, Color);
    vDrawPixel(X - R, Y, Color);

    while (Tx < Ty) {
        if (F >= 0) {
            Ty--;
            DDy += 2;
            F += DDy;
        }

        Tx++;
        DDx += 2;
        F += DDx;

        vDrawPixel(X + Tx, Y + Ty, Color);
        vDrawPixel(X - Tx, Y + Ty, Color);
        vDrawPixel(X + Tx, Y - Ty, Color);
        vDrawPixel(X - Tx, Y - Ty, Color);
        vDrawPixel(X + Ty, Y + Tx, Color);
        vDrawPixel(X - Ty, Y + Tx, Color);
        vDrawPixel(X + Ty, Y - Tx, Color);
        vDrawPixel(X - Ty, Y - Tx, Color);
    }
}

void vDrawCircleHelper(uint8_t X, uint8_t Y, uint8_t R, uint8_t C, uint8_t Color) {
    /* < Variables ::: Locales > */
    int8_t F = 1 - R;
    int8_t DDx = 1;
    int8_t DDy = -2 * R;
    int8_t Tx = 0;
    int8_t Ty = R;

    while (Tx < Ty) {
        if (F >= 0) {
            Ty--;
            DDy += 2;
            F += DDy;
        }

        Tx++;
        DDx += 2;
        F += DDx;

        if (C & 0x4) {
            vDrawPixel(X + Tx, Y + Ty, Color);
            vDrawPixel(X + Ty, Y + Tx, Color);
        }
        if (C & 0x2) {
            vDrawPixel(X + Tx, Y - Ty, Color);
            vDrawPixel(X + Ty, Y - Tx, Color);
        }
        if (C & 0x8) {
            vDrawPixel(X - Ty, Y + Tx, Color);
            vDrawPixel(X - Tx, Y + Ty, Color);
        }
        if (C & 0x1) {

            vDrawPixel(X - Ty, Y - Tx, Color);
            vDrawPixel(X - Tx, Y - Ty, Color);
        }
    }
}

void vDrawFillCircleHelper(uint8_t X, uint8_t Y, uint8_t R, uint8_t C, uint8_t D, uint8_t Color) {
    /* < Variables ::: Locales > */
    int8_t F = 1 - R;
    int8_t DDx = 1;
    int8_t DDy = -2 * R;
    int8_t Tx = 0;
    int8_t Ty = R;

    while (Tx < Ty) {
        if (F >= 0) {
            Ty--;
            DDy += 2;
            F += DDy;
        }

        Tx++;
        DDx += 2;
        F += DDx;

        if (C & 0x1) {
            vDrawVerticalLine(X + Tx, Y - Ty, 2 * Ty + 1 + D, Color);
            vDrawVerticalLine(X + Ty, Y - Tx, 2 * Tx + 1 + D, Color);
        }
        if (C & 0x2) {

            vDrawVerticalLine(X - Tx, Y - Ty, 2 * Ty + 1 + D, Color);
            vDrawVerticalLine(X - Ty, Y - Tx, 2 * Tx + 1 + D, Color);
        }
    }
}

void vDrawFillCircle(uint8_t X, uint8_t Y, uint8_t R, uint8_t Color) {
    /* < Dibuja un Circulo con Relleno > */
    vDrawVerticalLine(X, Y - R, 2 * R + 1, Color);
    vDrawFillCircleHelper(X, Y, R, 3, 0, Color);
}

void vDrawLine(uint8_t X1, uint8_t Y1, uint8_t X2, uint8_t Y2, uint8_t Color) {
    /* < Variables ::: Locales > */
    int8_t Steep = 0;
    int8_t Dx = 0;
    int8_t Dy = 0;
    int8_t Err = 0;
    int8_t Ystep = 0;

    Steep = abs(Y2 - Y1) > abs(X2 - X1);

    if (Steep) {
        SwapByte(X1, Y1);
        SwapByte(X2, Y2);
    }

    if (X1 > X2) {
        SwapByte(X1, X2);
        SwapByte(Y1, Y2);
    }

    Dx = X2 - X1;
    Dy = abs(Y2 - Y1);

    Err = Dx / 2;

    if (Y1 < Y2) Ystep = 1;
    else Ystep = -1;

    for (; X1 <= X2; X1++) {
        if (Steep) {
            vDrawPixel(Y1, X1, Color);
        } else {
            vDrawPixel(X1, Y1, Color);
        }
        Err -= Dy;
        if (Err < 0) {

            Y1 += Ystep;
            Err += Dx;
        }
    }
}

void vDrawRectangle(uint8_t X, uint8_t Y, uint8_t W, uint8_t H, uint8_t Color) {
    /* < Dibuja los Lados del Rectangulo > */
    vDrawHorizontalLine(X, Y, W, Color);
    vDrawHorizontalLine(X, (Y + H - 1), W, Color);
    vDrawVerticalLine(X, Y, H, Color);
    vDrawVerticalLine((X + W - 1), Y, H, Color);
}

void vDrawFillRectangle(uint8_t X, uint8_t Y, uint8_t W, uint8_t H, uint8_t Color) {
    /* < Variables ::: Locales > */
    uint8_t Count;

    /* < Dibujo Linea por Linea Vertical el Rectangulo > */
    for (Count = X; Count < X + W; Count++) {
        vDrawVerticalLine(Count, Y, H, Color);
    }
}

void vDrawRoundRectangle(uint8_t X, uint8_t Y, uint8_t W, uint8_t H, uint8_t R, uint8_t Color) {
    /* < Dibuja los Lados del Rectangulo > */
    vDrawHorizontalLine(X + R, Y, W - 2 * R, Color);
    vDrawHorizontalLine(X + R, Y + H - 1, W - 2 * R, Color);
    vDrawVerticalLine(X, Y + R, H - 2 * R, Color);
    vDrawVerticalLine(X + W - 1, Y + R, H - 2 * R, Color);

    /* < Dubuja las Esquinas Redondeadas > */
    vDrawCircleHelper(X + R, Y + R, R, 1, Color);
    vDrawCircleHelper(X + W - R - 1, Y + R, R, 2, Color);
    vDrawCircleHelper(X + W - R - 1, Y + H - R - 1, R, 4, Color);
    vDrawCircleHelper(X + R, Y + H - R - 1, R, 8, Color);
}

void vDrawFillRoundRectangle(uint8_t X, uint8_t Y, uint8_t W, uint8_t H, uint8_t R, uint8_t Color) {
    /* < Dibuja los lados del Rectangulo > */
    vDrawFillRectangle(X + R, Y, W - 2 * R, H, Color);

    /* < Dibuja las Esquinas Redondeadas > */
    vDrawFillCircleHelper(X + W - R - 1, Y + R, R, 1, H - 2 * R - 1, Color);
    vDrawFillCircleHelper(X + R, Y + R, R, 2, H - 2 * R - 1, Color);
}

void vDrawTriangle(uint8_t X1, uint8_t Y1, uint8_t X2, uint8_t Y2, uint8_t X3, uint8_t Y3, uint8_t Color) {
    /* < Dibuja los Lados del Triangulo > */
    vDrawLine(X1, Y1, X2, Y2, Color);
    vDrawLine(X2, Y2, X3, Y3, Color);
    vDrawLine(X3, Y3, X1, Y1, Color);
}

void vDrawFillTriangle(uint8_t X1, uint8_t Y1, uint8_t X2, uint8_t Y2, uint8_t X3, uint8_t Y3, uint8_t Color) {
    /* < Variables ::: Locales > */
    int8_t Ta = 0;
    int8_t Tb = 0;
    int8_t Ty = 0;
    int8_t Last = 0;

    int8_t Dx01 = 0;
    int8_t Dy01 = 0;
    int8_t Dx02 = 0;
    int8_t Dy02 = 0;
    int8_t Dx12 = 0;
    int8_t Dy12 = 0;

    int16_t Sa = 0;
    int16_t Sb = 0;

    // Sort coordinates by Y order (Y3 >= Y2 >= Y1)
    if (Y1 > Y2) {
        SwapByte(Y1, Y2);
        SwapByte(X1, X2);
    }

    if (Y2 > Y3) {
        SwapByte(Y3, Y2);
        SwapByte(X3, X2);
    }

    if (Y1 > Y2) {
        SwapByte(Y1, Y2);
        SwapByte(X1, X2);
    }

    if (Y1 == Y3) { // Handle awkward all-on-same-line case as its own thing
        Ta = Tb = X1;
        if (X2 < Ta) Ta = X2;
        else if (X2 > Tb) Tb = X2;
        if (X3 < Ta) Ta = X3;
        else if (X3 > Tb) Tb = X3;
        vDrawHorizontalLine(Ta, Y1, Tb - Ta + 1, Color);
        return;
    }

    Dx01 = X2 - X1;
    Dy01 = Y2 - Y1;
    Dx02 = X3 - X1;
    Dy02 = Y3 - Y1;
    Dx12 = X3 - X2;
    Dy12 = Y3 - Y2;

    // For upper part of triangle, find scanline crossings for segments
    // 0-1 and 0-2. If Y2=Y3 (flat-bottomed triangle), the scanline Y2
    // is included here (and second loop will be skipped, avoiding a /0
    // error there), otherwise scanline Y2 is skipped here and handled
    // in the second loop...which also avoids a /0 error here if Y1=Y2
    // (flat-topped triangle).

    if (Y2 == Y3) Last = Y2; // Include Y2 scanline
    else Last = Y2 - 1; // Skip it

    for (Ty = Y1; Ty <= Last; Ty++) {
        Ta = X1 + Sa / Dy01;
        Tb = X1 + Sb / Dy02;
        Sa += Dx01;
        Sb += Dx02;

        /* < longhand: > > */
        // Ta = X1 + (X2 - X1) * (Ty - Y1) / (Y2 - Y1);
        // Tb = X1 + (X3 - X1) * (Ty - Y1) / (Y3 - Y1);

        if (Ta > Tb) SwapByte(Ta, Tb);
        vDrawHorizontalLine(Ta, Ty, Tb - Ta + 1, Color);
    }

    // For lower part of triangle, find scanline crossings for segments
    // 0-2 and 1-2. This loop is skipped if Y2=Y3.

    Sa = Dx12 * (Ty - Y2);
    Sb = Dx02 * (Ty - Y1);

    for (; Ty <= Y3; Ty++) {
        Ta = X2 + Sa / Dy12;
        Tb = X1 + Sb / Dy02;
        Sa += Dx12;
        Sb += Dx02;

        /* < longhand > */
        // Ta = X2 + (X3 - X2) * (Ty - Y2) / (Y3 - Y2);
        // Tb = X1 + (X3 - X1) * (Ty - Y1) / (Y3 - Y1);

        if (Ta > Tb) SwapByte(Ta, Tb);
        vDrawHorizontalLine(Ta, Ty, Tb - Ta + 1, Color);
    }
}

/* < Prototipo ::: Funciones de Control :: Bitmaps : Datos en Buffer > > */
void vGLCDBufferDrawBitmap(uint8_t X, uint8_t Y, uint8_t Color, const uint8_t *pxBuffer) {
    /* < Variables ::: Locales > */
    uint8_t Coordinate_X = 0;
    uint8_t Coordinate_Y = 0;
    uint8_t CounterByte = 0;
    uint8_t *CounterBuffer = (uint8_t*) (pxBuffer + 4); // < Bitmap
    uint16_t *BitmapHeight = (uint16_t*) (pxBuffer + 2); // < Y
    uint16_t *BitmapWidth = (uint16_t*) (pxBuffer); // < X
    /* < Check ::: Buffer not Equal Null > */
    if (pxBuffer != NULL) {
        /* < Carga el Tamaño ::: Alto (H) > */
        for (Coordinate_Y = 0; Coordinate_Y < (*BitmapHeight / 8); Coordinate_Y++) {
            /* < Carga el Tamaño ::: Ancho (W) > */
            for (Coordinate_X = 0; Coordinate_X < *BitmapWidth; Coordinate_X++) {
                /* < Carga El Tamaño ::: Pixels por Byte (8) > */
                for (CounterByte = 0; CounterByte < 8; CounterByte++) {
                    /* < Draw ::: Pixels Bitmap > */
                    if (*CounterBuffer & (0x01 << CounterByte)) {
                        vDrawPixel((Coordinate_X + X), (CounterByte + Y + Coordinate_Y * 8), Color);
                    }
                }
                /* < Incrementa ::: Buffer > */
                CounterBuffer++;
            }
        }
    }
}
