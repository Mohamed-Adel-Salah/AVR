/*
 * 7SEG_int.h
 *
 *  Created on: Jul 22, 2023
 *      Author: hp
 */

#ifndef COTS_HAL_7SEG_7SEG_INT_H_
#define COTS_HAL_7SEG_7SEG_INT_H_

#define SEG_PORT 	PortA

#define COMMON_CATHODE

void SEG_voidInitialization(void);
void SEG_voidDisplayNumber(u8 Number);

#endif /* COTS_HAL_7SEG_7SEG_INT_H_ */
