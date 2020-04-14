/* < Include ::: Headers > */
#include "driver_controller_area_network.h"

/* < Variables ::: Globales ::: Memoria DMA... > */
uint16_t EcanBufferStorage[CAN_BUFFER_LENGTH][8] __attribute__((space(dma), aligned(CAN_BUFFER_LENGTH * 16)));

/* < Prototipo ::: Funciones de Control ::: CAN_MODULE > */
void vConfigureCANModule(uint8_t Interrupt, uint16_t Config, uint16_t SyncBRP, uint16_t WakePhaseSamProp, uint8_t SizeBufferDMA) {
    /* < Configuracion ::: Puertos y Registros I/O > */
    TRIS_CAN_TX = pdClear;
    TRIS_CAN_RX = pdSet;
    /* < Configuracion ::: Operation Settings :: CAN_MODULE > */
    if (C1CTRL1bits.OPMODE == CAN_REQ_OPERMODE_CONFIG) {
        /* < Mode ::. Control y Baudrate... > */
        C1CTRL1 |= (Config & 0x2808);
        C1CFG1 = (SyncBRP & 0x00FF);
        C1CFG2 = (WakePhaseSamProp & 0x47FF);
        /* < CAN Messages to be buffered in DMA RAM > */
        C1FCTRLbits.DMABS = (SizeBufferDMA & 0x0F);
    }
    /* < Clear ::: Buffers > */
    C1TR01CON = 0x0000;
    C1TR23CON = 0x0000;
    C1TR45CON = 0x0000;
    C1TR67CON = 0x0000;
    C1RXFUL1 = 0x0000;
    C1RXFUL2 = 0x0000;
    C1RXOVF1 = 0x0000;
    C1RXOVF2 = 0x0000;
    C1FEN1 = 0x0000;
    /* < Configuracion ::: Interruption :: CAN_MODULE > */
    IFS2bits.C1IF = pdClear;
    IPC8bits.C1IP = (Interrupt & 0x07);
    IEC2bits.C1IE = !!(Interrupt & 0x80);
    C1INTEbits.TBIE = !!(Interrupt & 0x40);
    C1INTEbits.RBIE = !!(Interrupt & 0x20);
}

void vCANModuleConfigureBuffers(uint8_t SetBuffers, uint8_t Priority, uint8_t Selection) {
    /* < Set ::: Value Buffer & Selection  > */
    SetBuffers &= 0x0F;
    Priority &= 0x03;
    Selection &= 0x01;
    /* < Select ::: Buffer... > */
    switch (SetBuffers) {
        case 0x00:
            C1TR01CONbits.TXEN0 = Selection;
            C1TR01CONbits.TX0PRI = Priority;
            break;
        case 0x01:
            C1TR01CONbits.TXEN1 = Selection;
            C1TR01CONbits.TX1PRI = Priority;
            break;
        case 0x02:
            C1TR23CONbits.TXEN2 = Selection;
            C1TR23CONbits.TX2PRI = Priority;
            break;
        case 0x03:
            C1TR23CONbits.TXEN3 = Selection;
            C1TR23CONbits.TX3PRI = Priority;
            break;
        case 0x04:
            C1TR45CONbits.TXEN4 = Selection;
            C1TR45CONbits.TX4PRI = Priority;
            break;
        case 0x05:
            C1TR45CONbits.TXEN5 = Selection;
            C1TR45CONbits.TX5PRI = Priority;
            break;
        case 0x06:
            C1TR67CONbits.TXEN6 = Selection;
            C1TR67CONbits.TX6PRI = Priority;
            break;
        case 0x07:
            C1TR67CONbits.TXEN7 = Selection;
            C1TR67CONbits.TX7PRI = Priority;
            break;
    }
}

void vCANModuleSelectMaskToFilter(uint8_t Filter, uint8_t Mask) { // < Asocia a cada Filtro la Mascara de 3 posibles...
    /* < Set ::: Value Mask & Filter > */
    Mask &= 0x03;
    Filter &= 0x0F;
    /* < Seleciona el Modo de Configuracion del Modulo ECAN > */
    if (C1CTRL1bits.OPMODE == CAN_REQ_OPERMODE_CONFIG) {
        /* < Enable ::: Window Control :: Filter */
        C1CTRL1bits.WIN = pdSet;
        /* < Select ::: Filter... > */
        switch (Filter) {
            case 0x00: C1FMSKSEL1bits.F0MSK = Mask;
                break;
            case 0x01: C1FMSKSEL1bits.F1MSK = Mask;
                break;
            case 0x02: C1FMSKSEL1bits.F2MSK = Mask;
                break;
            case 0x03: C1FMSKSEL1bits.F3MSK = Mask;
                break;
            case 0x04: C1FMSKSEL1bits.F4MSK = Mask;
                break;
            case 0x05: C1FMSKSEL1bits.F5MSK = Mask;
                break;
            case 0x06: C1FMSKSEL1bits.F6MSK = Mask;
                break;
            case 0x07: C1FMSKSEL1bits.F7MSK = Mask;
                break;
            case 0x08: C1FMSKSEL2bits.F8MSK = Mask;
                break;
            case 0x09: C1FMSKSEL2bits.F9MSK = Mask;
                break;
            case 0x0A: C1FMSKSEL2bits.F10MSK = Mask;
                break;
            case 0x0B: C1FMSKSEL2bits.F11MSK = Mask;
                break;
            case 0x0C: C1FMSKSEL2bits.F12MSK = Mask;
                break;
            case 0x0D: C1FMSKSEL2bits.F13MSK = Mask;
                break;
            case 0x0E: C1FMSKSEL2bits.F14MSK = Mask;
                break;
            case 0x0F: C1FMSKSEL2bits.F15MSK = Mask;
                break;
        }
        /* < Disable ::: Window Control :: Filter */
        C1CTRL1bits.WIN = pdClear;
    }
}

void vCANModuleSetMaskSID(uint8_t Mask, uint16_t SID) {
    /* < Set ::: Value Mask > */
    Mask &= 0x03;
    /* < Seleciona el Modo de Configuracion del Modulo ECAN > */
    if (C1CTRL1bits.OPMODE == CAN_REQ_OPERMODE_CONFIG) {
        /* < Enable ::: Window Control :: Filter */
        C1CTRL1bits.WIN = pdSet;
        /* < Select ::: Mask... > */
        switch (Mask) {
            case 0x00:
                C1RXM0SID = CAN_FILTERMASK2REG_SID(SID); // < Set Acceptance Mask0
                C1RXM0SID = CAN_SETMIDE(C1RXM0SID); // < Set standard ID
                break;
            case 0x01:
                C1RXM1SID = CAN_FILTERMASK2REG_SID(SID); // < Set Acceptance Mask1
                C1RXM1SID = CAN_SETMIDE(C1RXM1SID); // < Set standard ID
                break;
            case 0x02:
                C1RXM2SID = CAN_FILTERMASK2REG_SID(SID); // < Set Acceptance Mask2
                C1RXM2SID = CAN_SETMIDE(C1RXM1SID); // < Set standard ID
                break;
        }
        /* < Disable ::: Window Control :: Filter */
        C1CTRL1bits.WIN = pdClear;
    }
}

void vCANModuleSetFiltersSID(uint8_t Filter, uint16_t SID) {
    /* < Set ::: Value Mask & Filter > */
    Filter &= 0x0F;
    /* < Seleciona el Modo de Configuracion del Modulo ECAN > */
    if (C1CTRL1bits.OPMODE == CAN_REQ_OPERMODE_CONFIG) {
        /* < Enable ::: Window Control :: Filter */
        C1CTRL1bits.WIN = pdSet;
        /* < Select ::: Filter... > */
        switch (Filter) {
            case 0x00:
                C1RXF0SID = CAN_FILTERMASK2REG_SID(SID); // < Set SID tu Filter0
                C1RXF0SID = CAN_FILTERSTD(C1RXF0SID); // < Set standard ID
                C1FEN1bits.FLTEN0 = pdSet; // < Enable Filter0
                break;
            case 0x01:
                C1RXF1SID = CAN_FILTERMASK2REG_SID(SID); // < Set SID tu Filter1
                C1RXF1SID = CAN_FILTERSTD(C1RXF1SID); // < Set standard ID
                C1FEN1bits.FLTEN1 = pdSet; // < Enable Filter1
                break;
            case 0x02:
                C1RXF2SID = CAN_FILTERMASK2REG_SID(SID); // < Set SID tu Filter2
                C1RXF2SID = CAN_FILTERSTD(C1RXF2SID); // < Set standard ID
                C1FEN1bits.FLTEN2 = pdSet; // < Enable Filter2
                break;
            case 0x03:
                C1RXF3SID = CAN_FILTERMASK2REG_SID(SID); // < Set SID tu Filter3
                C1RXF3SID = CAN_FILTERSTD(C1RXF3SID); // < Set standard ID
                C1FEN1bits.FLTEN3 = pdSet; // < Enable Filter3
                break;
            case 0x04:
                C1RXF4SID = CAN_FILTERMASK2REG_SID(SID); // < Set SID tu Filter4
                C1RXF4SID = CAN_FILTERSTD(C1RXF4SID); // < Set standard ID
                C1FEN1bits.FLTEN4 = pdSet; // < Enable Filter4
                break;
            case 0x05:
                C1RXF5SID = CAN_FILTERMASK2REG_SID(SID); // < Set SID tu Filter5
                C1RXF5SID = CAN_FILTERSTD(C1RXF5SID); // < Set standard ID
                C1FEN1bits.FLTEN5 = pdSet; // < Enable Filter5
                break;
            case 0x06:
                C1RXF6SID = CAN_FILTERMASK2REG_SID(SID); // < Set SID tu Filter6
                C1RXF6SID = CAN_FILTERSTD(C1RXF7SID); // < Set standard ID
                C1FEN1bits.FLTEN6 = pdSet; // < Enable Filter6
                break;
            case 0x07:
                C1RXF7SID = CAN_FILTERMASK2REG_SID(SID); // < Set SID tu Filter7
                C1RXF7SID = CAN_FILTERSTD(C1RXF7SID); // < Set standard ID
                C1FEN1bits.FLTEN7 = pdSet; // < Enable Filter7
                break;
            case 0x08:
                C1RXF8SID = CAN_FILTERMASK2REG_SID(SID); // < Set SID tu Filter8
                C1RXF8SID = CAN_FILTERSTD(C1RXF8SID); // < Set standard ID
                C1FEN1bits.FLTEN8 = pdSet; // < Enable Filter8
                break;
            case 0x09:
                C1RXF9SID = CAN_FILTERMASK2REG_SID(SID); // < Set SID tu Filter9
                C1RXF9SID = CAN_FILTERSTD(C1RXF9SID); // < Set standard ID
                C1FEN1bits.FLTEN9 = pdSet; // < Enable Filter9
                break;
            case 0x0A:
                C1RXF10SID = CAN_FILTERMASK2REG_SID(SID); // < Set SID tu Filter10
                C1RXF10SID = CAN_FILTERSTD(C1RXF10SID); // < Set standard ID
                C1FEN1bits.FLTEN10 = pdSet; // < Enable Filter10
                break;
            case 0x0B:
                C1RXF11SID = CAN_FILTERMASK2REG_SID(SID); // < Set SID tu Filter11
                C1RXF11SID = CAN_FILTERSTD(C1RXF11SID); // < Set standard ID
                C1FEN1bits.FLTEN11 = pdSet; // < Enable Filter11
                break;
            case 0x0C:
                C1RXF12SID = CAN_FILTERMASK2REG_SID(SID); // < Set SID tu Filter12
                C1RXF12SID = CAN_FILTERSTD(C1RXF12SID); // < Set standard ID
                C1FEN1bits.FLTEN12 = pdSet; // < Enable Filter12
                break;
            case 0x0D:
                C1RXF13SID = CAN_FILTERMASK2REG_SID(SID); // < Set SID tu Filter13
                C1RXF13SID = CAN_FILTERSTD(C1RXF13SID); // < Set standard ID
                C1FEN1bits.FLTEN13 = pdSet; // < Enable Filter13
                break;
            case 0x0E:
                C1RXF14SID = CAN_FILTERMASK2REG_SID(SID); // < Set SID tu Filter14
                C1RXF14SID = CAN_FILTERSTD(C1RXF14SID); // < Set standard ID
                C1FEN1bits.FLTEN14 = pdSet; // < Enable Filter14
                break;
            case 0x0F:
                C1RXF15SID = CAN_FILTERMASK2REG_SID(SID); // < Set SID tu Filter15
                C1RXF15SID = CAN_FILTERSTD(C1RXF15SID); // < Set standard ID
                C1FEN1bits.FLTEN15 = pdSet; // < Enable Filter15
                break;
        }
        /* < Disable ::: Window Control :: Filter */
        C1CTRL1bits.WIN = pdClear;
    }
}

void vCANModuleSetMaskXTD(uint8_t Mask, uint32_t XTD) {
    /* < Set ::: Value Mask > */
    Mask &= 0x03;
    /* < Seleciona el Modo de Configuracion del Modulo ECAN > */
    if (C1CTRL1bits.OPMODE == CAN_REQ_OPERMODE_CONFIG) {
        /* < Enable ::: Window Control :: Filter */
        C1CTRL1bits.WIN = pdSet;
        /* < Select ::: Mask... > */
        switch (Mask) {
            case 0x00:
                C1RXM0EID = CAN_FILTERMASK2REG_EID0(*((uint16_t *) (&XTD + 1))); // < Set Acceptance Extended Mask0
                C1RXM0SID = CAN_FILTERMASK2REG_EID1(*((uint16_t *) (&XTD)));
                C1RXM0SID = CAN_SETMIDE(C1RXM0SID); // < Set Message Extended
                break;
            case 0x01:
                C1RXM1EID = CAN_FILTERMASK2REG_EID0(*((uint16_t *) (&XTD + 1))); // < Set Acceptance Extended Mask1
                C1RXM1SID = CAN_FILTERMASK2REG_EID1(*((uint16_t *) (&XTD)));
                C1RXM1SID = CAN_SETMIDE(C1RXM1SID); // < Set Message Extended
                break;
            case 0x02:
                C1RXM2EID = CAN_FILTERMASK2REG_EID0(*((uint16_t *) (&XTD + 1))); // < Set Acceptance Extended Mask2
                C1RXM2SID = CAN_FILTERMASK2REG_EID1(*((uint16_t *) (&XTD)));
                C1RXM2SID = CAN_SETMIDE(C1RXM2SID); // < Set Message Extended
                break;
        }
        /* < Disable ::: Window Control :: Filter */
        C1CTRL1bits.WIN = pdClear;
    }
}

void vCANModuleSetFiltersXTD(uint8_t Filter, uint32_t XTD) {
    /* < Set ::: Value Mask & Filter > */
    Filter &= 0x0F;
    /* < Seleciona el Modo de Configuracion del Modulo ECAN > */
    if (C1CTRL1bits.OPMODE == CAN_REQ_OPERMODE_CONFIG) {
        /* < Enable ::: Window Control :: Filter */
        C1CTRL1bits.WIN = pdSet;
        /* < Select ::: Filter... > */
        switch (Filter) {
            case 0x00:
                C1RXF0EID = CAN_FILTERMASK2REG_EID0(*((uint16_t *) (&XTD + 1))); // < Set XTD tu Filter0
                C1RXF0SID = CAN_FILTERMASK2REG_EID1(*((uint16_t *) (&XTD)));
                C1RXF0SID = CAN_FILTERXTD(C1RXF0SID); // < Set Message Extended
                C1FEN1bits.FLTEN0 = pdSet; // < Enable Filter0
                break;
            case 0x01:
                C1RXF1EID = CAN_FILTERMASK2REG_EID0(*((uint16_t *) (&XTD + 1))); // < Set XTD tu Filter1
                C1RXF1SID = CAN_FILTERMASK2REG_EID1(*((uint16_t *) (&XTD)));
                C1RXF1SID = CAN_FILTERXTD(C1RXF1SID); // < Set Message Extended
                C1FEN1bits.FLTEN1 = pdSet; // < Enable Filter1
                break;
            case 0x02:
                C1RXF2EID = CAN_FILTERMASK2REG_EID0(*((uint16_t *) (&XTD + 1))); // < Set XTD tu Filter2
                C1RXF2SID = CAN_FILTERMASK2REG_EID1(*((uint16_t *) (&XTD)));
                C1RXF2SID = CAN_FILTERXTD(C1RXF2SID); // < Set Message Extended
                C1FEN1bits.FLTEN2 = pdSet; // < Enable Filter2
                break;
            case 0x03:
                C1RXF3EID = CAN_FILTERMASK2REG_EID0(*((uint16_t *) (&XTD + 1))); // < Set XTD tu Filter3
                C1RXF3SID = CAN_FILTERMASK2REG_EID1(*((uint16_t *) (&XTD)));
                C1RXF3SID = CAN_FILTERXTD(C1RXF3SID); // < Set Message Extended
                C1FEN1bits.FLTEN3 = pdSet; // < Enable Filter3
                break;
            case 0x04:
                C1RXF4EID = CAN_FILTERMASK2REG_EID0(*((uint16_t *) (&XTD + 1))); // < Set XTD tu Filter4
                C1RXF4SID = CAN_FILTERMASK2REG_EID1(*((uint16_t *) (&XTD)));
                C1RXF4SID = CAN_FILTERXTD(C1RXF4SID); // < Set Message Extended
                C1FEN1bits.FLTEN4 = pdSet; // < Enable Filter4
                break;
            case 0x05:
                C1RXF5EID = CAN_FILTERMASK2REG_EID0(*((uint16_t *) (&XTD + 1))); // < Set XTD tu Filter5
                C1RXF5SID = CAN_FILTERMASK2REG_EID1(*((uint16_t *) (&XTD)));
                C1RXF5SID = CAN_FILTERXTD(C1RXF5SID); // < Set Message Extended
                C1FEN1bits.FLTEN5 = pdSet; // < Enable Filter5
                break;
            case 0x06:
                C1RXF6EID = CAN_FILTERMASK2REG_EID0(*((uint16_t *) (&XTD + 1))); // < Set XTD tu Filter6
                C1RXF6SID = CAN_FILTERMASK2REG_EID1(*((uint16_t *) (&XTD)));
                C1RXF6SID = CAN_FILTERXTD(C1RXF6SID); // < Set Message Extended
                C1FEN1bits.FLTEN6 = pdSet; // < Enable Filter6
                break;
            case 0x07:
                C1RXF7EID = CAN_FILTERMASK2REG_EID0(*((uint16_t *) (&XTD + 1))); // < Set XTD tu Filter7
                C1RXF7SID = CAN_FILTERMASK2REG_EID1(*((uint16_t *) (&XTD)));
                C1RXF7SID = CAN_FILTERXTD(C1RXF7SID); // < Set Message Extended
                C1FEN1bits.FLTEN7 = pdSet; // < Enable Filter7
                break;
            case 0x08:
                C1RXF8EID = CAN_FILTERMASK2REG_EID0(*((uint16_t *) (&XTD + 1))); // < Set XTD tu Filter8
                C1RXF8SID = CAN_FILTERMASK2REG_EID1(*((uint16_t *) (&XTD)));
                C1RXF8SID = CAN_FILTERXTD(C1RXF8SID); // < Set Message Extended
                C1FEN1bits.FLTEN8 = pdSet; // < Enable Filter8
                break;
            case 0x09:
                C1RXF9EID = CAN_FILTERMASK2REG_EID0(*((uint16_t *) (&XTD + 1))); // < Set XTD tu Filter9
                C1RXF9SID = CAN_FILTERMASK2REG_EID1(*((uint16_t *) (&XTD)));
                C1RXF9SID = CAN_FILTERXTD(C1RXF9SID); // < Set Message Extended
                C1FEN1bits.FLTEN9 = pdSet; // < Enable Filter9
                break;
            case 0x0A:
                C1RXF10EID = CAN_FILTERMASK2REG_EID0(*((uint16_t *) (&XTD + 1))); // < Set XTD tu Filter10
                C1RXF10SID = CAN_FILTERMASK2REG_EID1(*((uint16_t *) (&XTD)));
                C1RXF10SID = CAN_FILTERXTD(C1RXF10SID); // < Set Message Extended
                C1FEN1bits.FLTEN10 = pdSet; // < Enable Filter10
                break;
            case 0x0B:
                C1RXF11EID = CAN_FILTERMASK2REG_EID0(*((uint16_t *) (&XTD + 1))); // < Set XTD tu Filter11
                C1RXF11SID = CAN_FILTERMASK2REG_EID1(*((uint16_t *) (&XTD)));
                C1RXF11SID = CAN_FILTERXTD(C1RXF11SID); // < Set Message Extended
                C1FEN1bits.FLTEN11 = pdSet; // < Enable Filter11
                break;
            case 0x0C:
                C1RXF12EID = CAN_FILTERMASK2REG_EID0(*((uint16_t *) (&XTD + 1))); // < Set XTD tu Filter12
                C1RXF12SID = CAN_FILTERMASK2REG_EID1(*((uint16_t *) (&XTD)));
                C1RXF12SID = CAN_FILTERXTD(C1RXF12SID); // < Set Message Extended
                C1FEN1bits.FLTEN12 = pdSet; // < Enable Filter12
                break;
            case 0x0D:
                C1RXF13EID = CAN_FILTERMASK2REG_EID0(*((uint16_t *) (&XTD + 1))); // < Set XTD tu Filter13
                C1RXF13SID = CAN_FILTERMASK2REG_EID1(*((uint16_t *) (&XTD)));
                C1RXF13SID = CAN_FILTERXTD(C1RXF13SID); // < Set Message Extended
                C1FEN1bits.FLTEN13 = pdSet; // < Enable Filter13
                break;
            case 0x0E:
                C1RXF14EID = CAN_FILTERMASK2REG_EID0(*((uint16_t *) (&XTD + 1))); // < Set XTD tu Filter14
                C1RXF14SID = CAN_FILTERMASK2REG_EID1(*((uint16_t *) (&XTD)));
                C1RXF14SID = CAN_FILTERXTD(C1RXF14SID); // < Set Message Extended
                C1FEN1bits.FLTEN14 = pdSet; // < Enable Filter14
                break;
            case 0x0F:
                C1RXF15EID = CAN_FILTERMASK2REG_EID0(*((uint16_t *) (&XTD + 1))); // < Set XTD tu Filter15
                C1RXF15SID = CAN_FILTERMASK2REG_EID1(*((uint16_t *) (&XTD)));
                C1RXF15SID = CAN_FILTERXTD(C1RXF15SID); // < Set Message Extended
                C1FEN1bits.FLTEN15 = pdSet; // < Enable Filter15
                break;
        }
        /* < Disable ::: Window Control :: Filter */
        C1CTRL1bits.WIN = pdClear;
    }
}

void vCANModuleSelectBufferToFilter(uint8_t Filter, uint8_t Buffer) {
    /* < Set ::: Value Mask & Filter > */
    Buffer &= 0x0F;
    Filter &= 0x0F;
    /* < Seleciona el Modo de Configuracion del Modulo ECAN > */
    if (C1CTRL1bits.OPMODE == CAN_REQ_OPERMODE_CONFIG) {
        /* < Enable ::: Window Control :: Filter */
        C1CTRL1bits.WIN = pdSet;
        /* < Select ::: Fitter... > */
        switch (Filter) {
            case 0x00: C1BUFPNT1bits.F0BP = Buffer;
                break;
            case 0x01: C1BUFPNT1bits.F1BP = Buffer;
                break;
            case 0x02: C1BUFPNT1bits.F2BP = Buffer;
                break;
            case 0x03: C1BUFPNT1bits.F3BP = Buffer;
                break;
            case 0x04: C1BUFPNT2bits.F4BP = Buffer;
                break;
            case 0x05: C1BUFPNT2bits.F5BP = Buffer;
                break;
            case 0x06: C1BUFPNT2bits.F6BP = Buffer;
                break;
            case 0x07: C1BUFPNT2bits.F7BP = Buffer;
                break;
            case 0x08: C1BUFPNT3bits.F8BP = Buffer;
                break;
            case 0x09: C1BUFPNT3bits.F9BP = Buffer;
                break;
            case 0x0A: C1BUFPNT3bits.F10BP = Buffer;
                break;
            case 0x0B: C1BUFPNT3bits.F11BP = Buffer;
                break;
            case 0x0C: C1BUFPNT4bits.F12BP = Buffer;
                break;
            case 0x0D: C1BUFPNT4bits.F13BP = Buffer;
                break;
            case 0x0E: C1BUFPNT4bits.F14BP = Buffer;
                break;
            case 0x0F: C1BUFPNT4bits.F15BP = Buffer;
                break;
        }
        /* < Disable ::: Window Control :: Filter */
        C1CTRL1bits.WIN = pdClear;
    }
}

void vCANModuleSetSendTransmission(uint8_t BufferNumber) {
    /* < Check ::: Buffer to Transmission Data... > */
    if (BufferNumber == CAN_BUFFER_CTRL_00)
        /* < Set ::: Transmission > */
        C1TR01CONbits.TXREQ0 = pdSet;
    else if (BufferNumber == CAN_BUFFER_CTRL_01)
        /* < Set ::: Transmission > */
        C1TR01CONbits.TXREQ1 = pdSet;
    else if (BufferNumber == CAN_BUFFER_CTRL_02)
        /* < Set ::: Transmission > */
        C1TR23CONbits.TXREQ2 = pdSet;
    else if (BufferNumber == CAN_BUFFER_CTRL_03)
        /* < Set ::: Transmission > */
        C1TR23CONbits.TXREQ3 = pdSet;
    else if (BufferNumber == CAN_BUFFER_CTRL_04)
        /* < Set ::: Transmission > */
        C1TR45CONbits.TXREQ4 = pdSet;
    else if (BufferNumber == CAN_BUFFER_CTRL_05)
        /* < Set ::: Transmission > */
        C1TR45CONbits.TXREQ5 = pdSet;
    else if (BufferNumber == CAN_BUFFER_CTRL_06)
        /* < Set ::: Transmission > */
        C1TR67CONbits.TXREQ6 = pdSet;
    else if (BufferNumber == CAN_BUFFER_CTRL_07)
        /* < Set ::: Transmission > */
        C1TR67CONbits.TXREQ7 = pdSet;
}

uint1_t xSetModeOperation(uint8_t Mode) {
    /* < Variables ::: Locales >*/
    uint16_t Counter = 0U;
    /* < Masking & Mode > */
    Mode &= 0x0F;
    /* < Seleciona el Modo de Configuracion del Modulo ECAN > */
    do {
        C1CTRL1bits.REQOP = Mode; // < Mode Configuracion...
        __delay_us(1); // < Delay Change Status Mode...        
    } while ((C1CTRL1bits.OPMODE != Mode) && (Counter++ < 1000UL));
    /* < Return... > */
    return (Counter > 1000U ? pdSet : pdClear);
}

uint8_t xCANModuleClearReceiveFlags(void) {
    /* < Variables ::: Locales > */
    uint8_t Return = 0x00;
    /* < Check ::: Buffer to Clear > */
    if (C1RXFUL1bits.RXFUL0) {
        /* < Clear ::: Flag > */
        C1RXFUL1bits.RXFUL0 = pdClear;
        /* < Copy ::: Number Buffer... > */
        Return = CAN_BUFFER_CTRL_00;
    } else if (C1RXFUL1bits.RXFUL1) {
        /* < Clear ::: Flag > */
        C1RXFUL1bits.RXFUL1 = pdClear;
        /* < Copy ::: Number Buffer... > */
        Return = CAN_BUFFER_CTRL_01;
    } else if (C1RXFUL1bits.RXFUL2) {
        /* < Clear ::: Flag > */
        C1RXFUL1bits.RXFUL2 = pdClear;
        /* < Copy ::: Number Buffer... > */
        Return = CAN_BUFFER_CTRL_02;
    } else if (C1RXFUL1bits.RXFUL3) {
        /* < Clear ::: Flag > */
        C1RXFUL1bits.RXFUL3 = pdClear;
        /* < Copy ::: Number Buffer... > */
        Return = CAN_BUFFER_CTRL_03;
    } else if (C1RXFUL1bits.RXFUL4) {
        /* < Clear ::: Flag > */
        C1RXFUL1bits.RXFUL4 = pdClear;
        /* < Copy ::: Number Buffer... > */
        Return = CAN_BUFFER_CTRL_04;
    } else if (C1RXFUL1bits.RXFUL5) {
        /* < Clear ::: Flag > */
        C1RXFUL1bits.RXFUL5 = pdClear;
        /* < Copy ::: Number Buffer... > */
        Return = CAN_BUFFER_CTRL_05;
    } else if (C1RXFUL1bits.RXFUL6) {
        /* < Clear ::: Flag > */
        C1RXFUL1bits.RXFUL6 = pdClear;
        /* < Copy ::: Number Buffer... > */
        Return = CAN_BUFFER_CTRL_06;
    } else if (C1RXFUL1bits.RXFUL7) {
        /* < Clear ::: Flag > */
        C1RXFUL1bits.RXFUL7 = pdClear;
        /* < Copy ::: Number Buffer... > */
        Return = CAN_BUFFER_CTRL_07;
    }
    /* < Return ::: Value > */
    return (Return);
}

void vCANModuleSendMessege(xMessegeECAN * Message) {
    /* < Variables ::: Locales > */
    uint32_t Word0 = 0x00000000;
    uint32_t Word1 = 0x00000000;
    uint32_t Word2 = 0x00000000;

    /* < Check to see if the Message has an extended ID > */
    if (Message->FrameType == CAN_FRAME_EXT) {
        /* < Get the extended Message id EID28..18 > */
        Word0 = (Message->ID & 0x1FFC0000) >> 0x10;
        /* < Set the SRR and IDE bit > */
        Word0 = (Word0 + 0x0003);
        /* < The the value of EID17..6 > */
        Word1 = ((Message->ID & 0x0003FFC0) >> 0x06);
        /* < Get the value of EID5..0 for word 2 > */
        Word2 = ((Message->ID & 0x0000003F) << 0x0A);
    } else if (Message->FrameType == CAN_FRAME_STD) {
        /* < Get the SID > */
        Word0 = ((Message->ID & 0x000007FF) << 0x02);
    }
    /* < Check to see if the Message is an RTR Message > */
    if (Message->MessageType == CAN_MSG_RTR) {
        if (Message->FrameType == CAN_FRAME_EXT) Word2 = (Word2 | 0x0200);
        else Word0 = (Word0 | 0x0002);
        /* < Copy the data > */
        EcanBufferStorage[Message->Buffer][0x00] = Word0;
        EcanBufferStorage[Message->Buffer][0x01] = Word1;
        EcanBufferStorage[Message->Buffer][0x02] = Word2;
    } else {

        Word2 = (Word2 + (Message->DataLength & 0x0F));
        /* < Copy the data > */
        EcanBufferStorage[Message->Buffer][0x00] = Word0;
        EcanBufferStorage[Message->Buffer][0x01] = Word1;
        EcanBufferStorage[Message->Buffer][0x02] = Word2;
        /* < Fill the data > */
        *((uint8_t *) (&EcanBufferStorage[Message->Buffer][0x03])) = Message->Data[0x00];
        *((uint8_t *) (&EcanBufferStorage[Message->Buffer][0x03]) + 0x01) = Message->Data[0x01];
        *((uint8_t *) (&EcanBufferStorage[Message->Buffer][0x04])) = Message->Data[0x02];
        *((uint8_t *) (&EcanBufferStorage[Message->Buffer][0x04]) + 0x01) = Message->Data[0x03];
        *((uint8_t *) (&EcanBufferStorage[Message->Buffer][0x05])) = Message->Data[0x04];
        *((uint8_t *) (&EcanBufferStorage[Message->Buffer][0x05]) + 0x01) = Message->Data[0x05];
        *((uint8_t *) (&EcanBufferStorage[Message->Buffer][0x06])) = Message->Data[0x06];
        *((uint8_t *) (&EcanBufferStorage[Message->Buffer][0x06]) + 0x01) = Message->Data[0x07];
    }
    /* < Set the Message for Transmission > */
    vCANModuleSetSendTransmission(Message->Buffer);
}

void vCANModuleReceiveMessege(xMessegeECAN * Message) {
    /* < Variables ::: Locales > */
    uint32_t ID = 0x00000000;
    /* < Clear ::: Buffer Receive > */
    Message->Buffer = xCANModuleClearReceiveFlags();
    /* < Check to see what type of Message  > */
    if (EcanBufferStorage[Message->Buffer][0x00] & 0x0001) { // < Mesage is Extended Identifier
        ID = (EcanBufferStorage[Message->Buffer][0x00] & 0x1FFC);
        Message->ID = (ID << 0x10);
        ID = (EcanBufferStorage[Message->Buffer][0x01] & 0x0FFF);
        Message->ID = (Message->ID + (ID << 0x06));
        ID = ((EcanBufferStorage[Message->Buffer][0x02] & 0xFC00) >> 0x0A);
        Message->ID = (Message->ID + ID);
        Message->FrameType = CAN_FRAME_EXT;
    } else { // < Message is standard identifier
        Message->ID = ((EcanBufferStorage[Message->Buffer][0x00] & 0x1FFC) >> 0x02);
        Message->FrameType = CAN_FRAME_STD;
    }
    /* < Check to see what type of Message it is > */
    if (EcanBufferStorage[Message->Buffer][0x00] & 0x0002) { // < RTR Message
        Message->MessageType = CAN_MSG_RTR;
    } else { // < Normal Message
        Message->MessageType = CAN_MSG_DATA;
        Message->DataLength = *((uint8_t *) (&EcanBufferStorage[Message->Buffer][0x02]));
        Message->Data[0x00] = *((uint8_t *) (&EcanBufferStorage[Message->Buffer][0x03]));
        Message->Data[0x01] = *((uint8_t *) (&EcanBufferStorage[Message->Buffer][0x03]) + 0x01);
        Message->Data[0x02] = *((uint8_t *) (&EcanBufferStorage[Message->Buffer][0x04]));
        Message->Data[0x03] = *((uint8_t *) (&EcanBufferStorage[Message->Buffer][0x04]) + 0x01);
        Message->Data[0x04] = *((uint8_t *) (&EcanBufferStorage[Message->Buffer][0x05]));
        Message->Data[0x05] = *((uint8_t *) (&EcanBufferStorage[Message->Buffer][0x05]) + 0x01);
        Message->Data[0x06] = *((uint8_t *) (&EcanBufferStorage[Message->Buffer][0x06]));
        Message->Data[0x07] = *((uint8_t *) (&EcanBufferStorage[Message->Buffer][0x06]) + 0x01);
    }
}
