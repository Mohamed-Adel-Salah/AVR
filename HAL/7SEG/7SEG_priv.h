/*
 * 7SEG_priv.h
 *
 *  Created on: Jul 22, 2023
 *      Author: hp
 */

#ifndef COTS_HAL_7SEG_7SEG_PRIV_H_
#define COTS_HAL_7SEG_7SEG_PRIV_H_

#ifdef COMMON_CATHODE
	#define SEG_Display0_Value	0b00111111
	#define SEG_Display1_Value	0b00000110
	#define SEG_Display2_Value	0b01011011
	#define SEG_Display3_Value	0b01001111
	#define SEG_Display4_Value	0b01100110
	#define SEG_Display5_Value	0b01101101
	#define SEG_Display6_Value	0b01111101
	#define SEG_Display7_Value	0b01000111
	#define SEG_Display8_Value	0b01111111
	#define SEG_Display9_Value	0b01101111
#else
	#define SEG_Display0_Value	0b11000000
	#define SEG_Display1_Value	0b11111001
	#define SEG_Display2_Value	0b10100100
	#define SEG_Display3_Value	0b10110000
	#define SEG_Display4_Value	0b10011001
	#define SEG_Display5_Value	0b10010010
	#define SEG_Display6_Value	0b10000010
	#define SEG_Display7_Value	0b10111000
	#define SEG_Display8_Value	0b10000000
	#define SEG_Display9_Value	0b10010000
#endif

#endif /* COTS_HAL_7SEG_7SEG_PRIV_H_ */
