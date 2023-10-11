/*
 * DIO_int.h
 *
 *  Created on: Jul 22, 2023
 *      Author: hp
 */

#ifndef COTS_MCAL_DIO_DIO_INT_H_
#define COTS_MCAL_DIO_DIO_INT_H_

#define Input 	0
#define Output 	1

#define High 	1
#define Low 	0

#define PortA 0
#define PortB 1
#define PortC 2
#define PortD 3

#define Pin0 0
#define Pin1 1
#define Pin2 2
#define Pin3 3
#define Pin4 4
#define Pin5 5
#define Pin6 6
#define Pin7 7

void DIO_voidInitialization (void);

void 	DIO_voidSetPinDirection 		(u8 PortId,u8 PinId,u8 Direction);
void	DIO_voidSetPinValue				(u8 PortId,u8 PinId,u8 Value);
void	DIO_voidTogglePin				(u8 PortId,u8 PinId);
void	DIO_voidSetPortDirection		(u8 PortId,u8 Direction);
void	DIO_voidSetPortValue			(u8 PortId,u8 Value);
void	DIO_voidSetPortValueMask		(u8 PortId,u8 Value,u8 Mask);
void	DIO_voidSetPortDirectionMask	(u8 PortId,u8 Direction,u8 Mask);

u8		DIO_u8GetPinValue			(u8 PortId,u8 PinId);
void	DIO_voidGetPinValue			(u8 PortId,u8 PinId, u8 * ptr);

#endif /* COTS_MCAL_DIO_DIO_INT_H_ */
