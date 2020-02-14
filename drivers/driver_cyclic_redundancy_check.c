/* < Include : break;: break;: break; Header > */
#include "driver_cyclic_redundancy_check.h"

/* < Funciones de Control :: CRC_MODULE > */
void vConfigureCRCModule(uint8_t Interrupt, uint16_t Configure, uint16_t Polynomi) {
    /* < Habilita ::: CRC_MODULE > */
    PMD3bits.CRCMD = pdClear;
    /* < Configuracion ::: Operation Settings :: CRC_MODULE > */
    CRCCON = Configure;
    CRCXOR = Polynomi;
    /* < Configuracion ::: Interruption :: CRC_MODULE > */
    IFS4bits.CRCIF = pdClear;
    IPC16bits.CRCIP = (Interrupt & 0x07);
    IEC4bits.CRCIE = (Interrupt & 0x80) >> 0x07;
}

void vCRCModuleSetPolynomi(uint16_t Lenght, uint16_t Polynomi) {
    /* < Configuracion ::: Operation Settings :: CRC_MODULE > */
    CRCCON = (Lenght & 0x000F);
    CRCXOR = Polynomi;
}

uint16_t CRC_Calc_ChecksumWord(uint16_t* Data, uint16_t NumberWords, uint16_t PreviusCRC) {
    /* < Copy ::: Previus CRC... > */
    CRCWDAT = PreviusCRC;
    /* < Enable ::: CRC_Module > */
    CRCCONbits.CRCGO = pdSet;
    /* < Execute ::: CRC_Module > */
    do {
        /* < Check & While ::: Buffer FIFO is Empty... > */
        while (0x01 != CRCCONbits.CRCMPT);
        /* < Check & While ::: Buffer FIFO is Full... > */
        while ((0x00 == CRCCONbits.CRCFUL && (0x00 < NumberWords))) {
            CRCDAT = *Data;
            Data++;
            NumberWords--;
        }
    } while (0x00 < NumberWords);
    /* < Check & While ::: Buffer FIFO is Full... > */
    while (CRCCONbits.CRCFUL == 0x01);
    /* < Do this to shift the last word out of the CRC shift register > */
    CRCDAT = 0x0000;
    /* < Check & While ::: Buffer FIFO is Empty... > */
    while (0x01 != CRCCONbits.CRCMPT);
    /* < Disable ::: CRC_Module > */
    CRCCONbits.CRCGO = pdClear;
    /* < Delay ::: Instruction... > */
    Nop();
    /* < Return ::: Value CRC> */
    return (CRCWDAT);
}

uint16_t CRC_Calc_ChecksumByte(uint8_t* Data, uint16_t NumberBytes, uint16_t PreviusCRC) {
    /* < Copy ::: Previus CRC... > */
    CRCWDAT = PreviusCRC;
    /* < Enable ::: CRC_Module > */
    CRCCONbits.CRCGO = pdSet;
    do {
        /* < Check & While ::: Buffer FIFO is Empty... > */
        while (0x01 != CRCCONbits.CRCMPT);
        /* < Check & While ::: Buffer FIFO is Full... > */
        while ((0x00 == CRCCONbits.CRCFUL && (0x00 < NumberBytes))) {
            *(uint8_t*)&CRCDAT = *Data;
            Data++;
            NumberBytes--;
        }
    } while (0x00 < NumberBytes);
    /* < Check & While ::: Buffer FIFO is Full... > */
    while (CRCCONbits.CRCFUL == 0x01);
    /* < Do this to shift the last word out of the > */
    CRCDAT = 0x0000;
    /* < Check & While ::: Buffer FIFO is Empty... > */
    while (0x01 != CRCCONbits.CRCMPT);
    /* < Disable ::: CRC_Module > */
    CRCCONbits.CRCGO = pdClear;
    /* < Delay ::: Instruction... > */
    Nop();
    /* < Return ::: Value CRC> */
    return (CRCWDAT);
}
