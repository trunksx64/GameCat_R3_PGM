#ifndef MAIN_TYPEDEFS_H
#define	MAIN_TYPEDEFS_H

/* < Functions Type Definitions
 *
 * Unsigned (u)
 * Void (v)
 * Base_Type (t)
 * Char (c)
 * Short (s)
 * Long (l)
 * Float/Double (d)
 * Emun (e)
 * Pointer (p)
 * Struct / Others (x) > */

/* < Generic Type Definitions > */
#include <stdint.h> 

/* < MPLAB - Software Library > */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h> 

/* < Define ::: Typedefs > */
#define uint1_t bool

/* < Define ::: Configuration Bits Control > */
#define BitGet(Register,Bit)                ((Register) & (0x01 << Bit))
#define BitSet(Register,Bit)                ((Register) |= (0x01 << Bit))
#define BitClear(Register,Bit)              ((Register) &= ~(0x01 << Bit))
#define BitToggle(Register,Bit)             ((Register) ^= (0x01 << Bit))
#define BitWrite(Value,Register,Bit)        (Value? BitSet(Register,Bit) : BitClear(Register,Bit))

/* <Define ::: Control ::: Bytes > */
#define SwapNibble(Byte)                    (Byte = (Byte >> 0x04) | (Byte << 0x04))
#define SwapByte(A,B)                       ((A)^=(B),(B)^=(A),(A)^=(B))

/* < Define ::: Nop() For Debug >*/
#if __DEBUG
#define pdNop() Nop()
#else
#define pdNop()
#endif

/* < Define ::: Configuration Bit Ports & Variables > */
#define pdClear     false
#define pdSet       true

#define pdFalse     false
#define pdTrue      true

/* < Define ::: Control Result for Functions > */
#define pdNULL      0x00
#define pdPass      0x01
#define pdDisable   0x02
#define pdEnable    0x03
#define pdProgram   0x04
#define pdOverload  0x05
#define pdReview    0x06
#define pdReset     0x07
#define pdEmphy     0x08
#define pdError     0x09
#define pdFail      0x0A

/* < Define ::: Control Loops > */
#define RunLoop     0x01
#define RunMain     0x01
#define RunTask     0x01
#define RunFunction 0x01
#define RunRutine   0x01
#define RunCoRutine 0x01
#define RunThread   0x01
#define ReturnNULL  0x00

#endif	/* < MAIN_TYPEDEFS_H > */

