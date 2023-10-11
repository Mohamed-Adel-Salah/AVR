/*
 * SEG_KIT_int.h
 *
 *  Created on: Jul 22, 2023
 *      Author: hp
 */

#ifndef COTS_HAL_SEG_KIT_SEG_KIT_INT_H_
#define COTS_HAL_SEG_KIT_SEG_KIT_INT_H_

#define SEG_KIT_PORT PortB

#define SEG1 1
#define SEG2 2
#define SEG3 3
#define SEG4 4

void SEG_KIT_voidInitialization(void);
void SEG_KIT_voidDisplayNumber(u8 Number,u8 SEGNumber);

void SEG_KIT_StoreCustomCharacter(u8 *Character);


#endif /* COTS_HAL_SEG_KIT_SEG_KIT_INT_H_ */
