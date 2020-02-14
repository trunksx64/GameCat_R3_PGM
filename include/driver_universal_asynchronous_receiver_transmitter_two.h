#ifndef DRIVER_UNIVERSAL_ASYNCHRONOUS_RECEIVER_TRANSMITTER_TWO_H
#define	DRIVER_UNIVERSAL_ASYNCHRONOUS_RECEIVER_TRANSMITTER_TWO_H

/* < Configuration Bits Settings > */
#include "xc.h"
/* < Configuration Main Settings > */
#include "main_typedefs.h"
#include "main_delays.h"

/* < Definicion ::: Pines de Control :: UART_TO_EXT > */
#define TRIS_UART2_TX           TRISBbits.TRISB3
#define TRIS_UART2_RX           TRISCbits.TRISC0

/* < Definicion ::: Configuracion INT :: UART_TO_EXT : Interruption > */
#define UART2_INT_TX_ENABLE     0x8000  // < enable / disable interrupts
#define UART2_INT_TX_DISABLE    0x0000

#define UART2_INT_RX_ENABLE     0x0080  // < enable / disable interrupts
#define UART2_INT_RX_DISABLE    0x0000

#define UART2_INT_TX_PRI_0      0x0000  // < Setting the priority of adc interrupt
#define UART2_INT_TX_PRI_1      0x0100
#define UART2_INT_TX_PRI_2      0x0200
#define UART2_INT_TX_PRI_3      0x0300
#define UART2_INT_TX_PRI_4      0x0400
#define UART2_INT_TX_PRI_5      0x0500
#define UART2_INT_TX_PRI_6      0x0600
#define UART2_INT_TX_PRI_7      0x0700

#define UART2_INT_RX_PRI_0      0x0000  // < Setting the priority of adc interrupt
#define UART2_INT_RX_PRI_1      0x0001
#define UART2_INT_RX_PRI_2      0x0002
#define UART2_INT_RX_PRI_3      0x0003
#define UART2_INT_RX_PRI_4      0x0004
#define UART2_INT_RX_PRI_5      0x0005
#define UART2_INT_RX_PRI_6      0x0006
#define UART2_INT_RX_PRI_7      0x0007

/* < Definicion ::: Configuracion 1 :: U1MODE: : UART_TO_EXT > */
#define UART2_RX_ENABLE         0x8000  /* Module enable */
#define UART2_RX_DIS            0x0000  /* Module disable */

#define UART2_IDLE_CON          0x0000  /* Work in IDLE mode */
#define UART2_IDLE_STOP         0x2000  /* Stop all functions in IDLE mode*/

#define UART2_IrDA_ENABLE       0x1000  /* IrDA encoder and decoder enabled*/
#define UART2_IrDA_DISABLE      0x0000  /* IrDA encoder and decoder disabled */

#define UART2_MODE_SIMPLEX      0x0800  /* UxRTS pin in Simplex mode */
#define UART2_MODE_FLOW         0x0000  /* UxRTS pin in Flow Control mode*/

#define UART2_UEN_TX_RX_CLK     0x0002  /* UxTX,UxRX and BCLK pins are enabled and used; UxCTS pin controlled by port latches */
#define UART2_UEN_TX_RX_CTS     0x0003  /* UxTX,UxRX, UxCTS and UxRTS pins are enabled and used */
#define UART2_UEN_TX_RX_RTS     0x0001  /* UxTX,UxRX and UxRTS pins are enabled and used; UxCTS pin controlled by port latches*/
#define UART2_UEN_TX_RX         0x0000  /* UxTX and UxRX pins are enabled and used; UxCTS and UxRTS/BCLK pins controlled by port latches*/

#define UART2_EN_WAKE           0x0080  /* Enable Wake-up on START bit Detect during SLEEP Mode bit */
#define UART2_DIS_WAKE          0x0000  /* Disable Wake-up on START bit Detect during SLEEP Mode bit */

#define UART2_EN_LOOPBACK       0x0040  /* Loop back enabled */
#define UART2_DIS_LOOPBACK      0x0000  /* Loop back disabled */

#define UART2_EN_ABAUD          0x0020  /* Enable baud rate measurement on the next character */
#define UART2_DIS_ABAUD         0x0000  /* Baud rate measurement disabled or completed */

#define UART2_UXRX_IDLE_ZERO    0x0010  /* UxRX Idle state is zero */
#define UART2_UXRX_IDLE_ONE     0x0000  /* UxRx Idle state is one */

#define UART2_BRGH_FOUR         0x0008  /* BRG generates 4 clocks per bit period */
#define UART2_BRGH_SIXTEEN      0x0000  /* BRG generates 16 clocks per bit period */

#define UART2_NO_PAR_9BIT       0x0006  /* No parity 9 bit*/
#define UART2_ODD_PAR_8BIT      0x0004  /* odd parity 8 bit*/
#define UART2_EVEN_PAR_8BIT     0x0002  /* even parity 8 bit*/
#define UART2_NO_PAR_8BIT       0x0000  /* no parity 8 bit*/

#define UART2_2STOPBITS         0x0001  /* 2 stop bits*/
#define UART2_1STOPBIT          0x0000  /* 1 stop bit*/

/* < Definicion ::: Configuracion 1 :: U1STA: : UART_TO_EXT > */
#define UART2_INT_TX_BUF_EMPTY  0x8000  /* Interrupt on TXBUF becoming empty */
#define UART2_INT_TX_LAST_CH    0x2000  /* Interrupt when last character shifted out*/
#define UART2_INT_TX_CHAR       0x0000  /* Interrupt on transfer of every character to TSR */

#define UART2_POL_INV_ONE       0x0000  /* IrDA encoded, UxTX Idle state is '1' */
#define UART2_POL_INV_ZERO      0x4000  /* IrDA encoded, UxTX Idel state is '0' */

#define UART2_SYNC_BREAK_ON     0x0800  /* Send sync break on next transmission */
#define UART2_SYNC_BREAK_OFF    0x0000  /* Sync break transmission disabled or completed */

#define UART2_TX_ENABLE         0x0400  /* Transmit enable */
#define UART2_TX_DISABLE        0x0000  /* Transmit disable */

#define UART2_INT_RX_BUF_FUL    0x00C0  /* Interrupt on RXBUF full */
#define UART2_INT_RX_3_4_FUL    0x0080  /* Interrupt on RXBUF 3/4 full */
#define UART2_INT_RX_CHAR       0x0000  /* Interrupt on every char received */

#define UART2_ADR_DETECT_EN     0x0020  /* address detect enable */
#define UART2_ADR_DETECT_DIS    0x0000  /* address detect disable */

#define UART2_RX_OVERRUN_CLEAR  0x0002  /* Rx buffer Over run status bit clear */

/* < Prototipo ::: Funciones de Control ::: UART_TO_EXT > */
void vConfigureUartTwo(uint16_t Config_INT, uint16_t Config_1, uint16_t Config_2, uint32_t Baud);
uint8_t xBusyUartTwo(void);
uint8_t xDataReadyUartTwo(void);
uint16_t xReadUartTwo(void);
void vWriteUartTwo(uint16_t Data);
void vPutsUartTwo(uint8_t Length, uint8_t *pxBuffer);
void vGetsUartTwo(uint8_t Length, uint8_t *pxBuffer);

#endif	/* < DRIVER_UNIVERSAL_ASYNCHRONOUS_RECEIVER_TRANSMITTER_TWO_H > */

