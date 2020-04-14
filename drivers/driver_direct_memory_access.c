/* < Include ::: Headers > */
#include "driver_direct_memory_access.h"

/* < Funciones de Control ::: Module DMA Zero > */
void vConfigureDMAZeroModule(uint8_t Interrupt, uint16_t Config, uint16_t IRQ, uint16_t STA_Address, uint16_t STB_Address, uint16_t PAD_Address, uint16_t Count) {
    /* < configures the DMA0 CONTROL register >  */
    DMA0CON = (Config & 0x7FFF);
    /* < Set the peripheral IRQ number > */
    DMA0REQ = (IRQ & 0x7FFF);
    /* < set the start address for buffer A >  */
    DMA0STA = STA_Address;
    /* < set the start address for buffer B >  */
    DMA0STB = STB_Address;
    /* < set the peripheral address > */
    DMA0PAD = PAD_Address;
    /* < set the number of bytes/words to be tranfered > */
    DMA0CNT = Count;
    /* < Configure ::: Interrupt DMA0 > */
    IFS0bits.DMA0IF = pdClear;
    IPC1bits.DMA0IP = (Interrupt & 0x07);
    IEC0bits.DMA0IE = !!(Interrupt & 0x80);
    /* < Enable the DMA0 >  */
    DMA0CON |= (Config & 0x8000);
}

/* < Funciones de Control ::: Module DMA ONE > */
void vConfigureDMAOneModule(uint8_t Interrupt, uint16_t Config, uint16_t IRQ, uint16_t STA_Address, uint16_t STB_Address, uint16_t PAD_Address, uint16_t Count) {
    /* < configures the DMA0 CONTROL register >  */
    DMA1CON = (Config & 0x7FFF);
    /* < Set the peripheral IRQ number > */
    DMA1REQ = (IRQ & 0x7FFF);
    /* < set the start address for buffer A >  */
    DMA1STA = STA_Address;
    /* < set the start address for buffer B >  */
    DMA1STB = STB_Address;
    /* < set the peripheral address > */
    DMA1PAD = PAD_Address;
    /* < set the number of bytes/words to be tranfered > */
    DMA1CNT = Count;
    /* < Configure ::: Interrupt DMA0 > */
    IFS0bits.DMA1IF = pdClear;
    IPC3bits.DMA1IP = (Interrupt & 0x07);
    IEC0bits.DMA1IE = !!(Interrupt & 0x80);
    /* < Enable the DMA0 >  */
    DMA1CON |= (Config & 0x8000);
}
