/*
 * Macros.h
 *
 *  Created on: Jul 22, 2023
 *      Author: hp
 */

#ifndef COTS_LIB_MACROS_H_
#define COTS_LIB_MACROS_H_

#define SET_BIT(Reg,Bit) (Reg |= (1<<Bit))
#define CLR_BIT(Reg,Bit) (Reg &= ~(1<<Bit))
#define TOG_BIT(Reg,Bit) (Reg ^= (1<<Bit))
#define GET_BIT(Reg,Bit) ((Reg & (1<<Bit))>>Bit)

#define SET_BYTE(Reg,Value) (Reg = Value)


#endif /* COTS_LIB_MACROS_H_ */
