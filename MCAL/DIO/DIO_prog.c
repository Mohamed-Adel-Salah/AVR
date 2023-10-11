/*
 * DIO_prog.c
 *
 *  Created on: Jul 22, 2023
 *      Author: hp
 */

#include "STD_Types.h"
#include "Macros.h"

#include "DIO_int.h"
#include "DIO_priv.h"
#include "DIO_reg.h"

void DIO_voidInitialization (void)
{
//Depends on Application

/***** Game *****/
//	DIO_voidSetPinDirection(PortD,Pin5,Input);
//	DIO_voidSetPinDirection(PortD,Pin3,Input);
//	DIO_voidSetPinDirection(PortD,Pin7,Input);
//	DIO_voidSetPinDirection(PortD,Pin6,Input);
//
//	DIO_voidSetPinValue(PortD,Pin5,High);
//	DIO_voidSetPinValue(PortD,Pin3,High);
//	DIO_voidSetPinValue(PortD,Pin7,High);
//	DIO_voidSetPinValue(PortD,Pin6,High);

/***** EXT_INT*****/
//	DIO_voidSetPinDirection(PortB,Pin7,Output);
//	DIO_voidSetPinDirection(PortD,Pin3,Input);
//
//	DIO_voidSetPinValue(PortB,Pin7,Low);
//	DIO_voidSetPinValue(PortD,Pin3,High);

/***** Timer as a counter ****/
//	DIO_voidSetPinDirection(PortB,Pin0,Input);
//	DIO_voidSetPinValue(PortB,Pin0,High);
//
//	DIO_voidSetPinDirection(PortB,Pin5,Output);
//	DIO_voidSetPinValue(PortB,Pin5,High);

/***** Timer1 OC1 Pin*****/
//	DIO_voidSetPinDirection(PortD,Pin5,Output);
//
//	DIO_voidSetPinDirection(PortB,Pin3,Output);
//	DIO_voidSetPinDirection(PortD,Pin6,Input);

}

void 	DIO_voidSetPinDirection (u8 PortId,u8 PinId,u8 Direction)
{
	if(Direction==Output)
	{
		switch(PortId)
		{
			case 0: SET_BIT(DDRA,PinId); break;
			case 1: SET_BIT(DDRB,PinId); break;
			case 2: SET_BIT(DDRC,PinId); break;
			case 3: SET_BIT(DDRD,PinId); break;
		}
	}
	else
	{
		switch(PortId)
		{
			case 0: CLR_BIT(DDRA,PinId); break;
			case 1: CLR_BIT(DDRB,PinId); break;
			case 2: CLR_BIT(DDRC,PinId); break;
			case 3: CLR_BIT(DDRD,PinId); break;
		}
	}
}

void DIO_voidSetPinValue(u8 PortId,u8 PinId,u8 Value)
{
	if(Value==High)
	{
		switch(PortId)
		{
			case 0: SET_BIT(PORTA,PinId); break;
			case 1: SET_BIT(PORTB,PinId); break;
			case 2: SET_BIT(PORTC,PinId); break;
			case 3: SET_BIT(PORTD,PinId); break;
		}
	}
	else
	{
		switch(PortId)
		{
			case 0: CLR_BIT(PORTA,PinId); break;
			case 1: CLR_BIT(PORTB,PinId); break;
			case 2: CLR_BIT(PORTC,PinId); break;
			case 3: CLR_BIT(PORTD,PinId); break;
		}
	}
}

void DIO_voidTogglePin (u8 PortId,u8 PinId)
{
	switch(PortId)
	{
		case 0: TOG_BIT(PORTA,PinId); break;
		case 1: TOG_BIT(PORTB,PinId); break;
		case 2: TOG_BIT(PORTC,PinId); break;
		case 3: TOG_BIT(PORTD,PinId); break;
	}
}

void DIO_voidSetPortDirection (u8 PortId,u8 Direction)
{
	if(Direction==Output)
	{
		switch(PortId)
		{
			case 0: SET_BYTE(DDRA,0xFF); break;
			case 1: SET_BYTE(DDRB,0xFF); break;
			case 2: SET_BYTE(DDRC,0xFF); break;
			case 3: SET_BYTE(DDRD,0xFF); break;
		}
	}
	else
	{
		switch(PortId)
		{
			case 0: SET_BYTE(DDRA,0x00); break;
			case 1: SET_BYTE(DDRB,0x00); break;
			case 2: SET_BYTE(DDRC,0x00); break;
			case 3: SET_BYTE(DDRD,0x00); break;
		}
	}
}

void DIO_voidSetPortValue (u8 PortId,u8 Value)
{
	switch(PortId)
	{
		case 0: SET_BYTE(PORTA,Value); break;
		case 1: SET_BYTE(PORTB,Value); break;
		case 2: SET_BYTE(PORTC,Value); break;
		case 3: SET_BYTE(PORTD,Value); break;
	}
}

void	DIO_voidSetPortValueMask		(u8 PortId,u8 Value,u8 Mask)
{
	switch(PortId)
	{
		case 0: PORTA=((Value)|(PORTA & Mask)); break;
		case 1: PORTB=((Value)|(PORTB & Mask)); break;
		case 2: PORTC=((Value)|(PORTC & Mask)); break;
		case 3: PORTD=((Value)|(PORTD & Mask)); break;
	}
}

void	DIO_voidSetPortDirectionMask	(u8 PortId,u8 Direction,u8 Mask)
{
	switch(PortId)
	{
		case 0: PORTA=((Direction)|(DDRA & Mask)); break;
		case 1: PORTB=((Direction)|(DDRB & Mask)); break;
		case 2: PORTC=((Direction)|(DDRC & Mask)); break;
		case 3: PORTD=((Direction)|(DDRD & Mask)); break;
	}
}

u8 DIO_u8GetPinValue (u8 PortId,u8 PinId)
{
	u8 DIO_u8ReturnPinValue;
	switch(PortId)
	{
	case 0: DIO_u8ReturnPinValue = GET_BIT(PINA,PinId); break;
	case 1: DIO_u8ReturnPinValue = GET_BIT(PINB,PinId); break;
	case 2: DIO_u8ReturnPinValue = GET_BIT(PINC,PinId); break;
	case 3: DIO_u8ReturnPinValue = GET_BIT(PIND,PinId); break;
	default : DIO_u8ReturnPinValue = GET_BIT(PortId,PinId); break;
	}
	return DIO_u8ReturnPinValue;
}

void DIO_voidGetPinValue (u8 PortId,u8 PinId, u8 * ptr)
{
	switch(PortId)
	{
	case 0: *ptr = GET_BIT(DDRA,PinId); break;
	case 1: *ptr = GET_BIT(DDRB,PinId); break;
	case 2: *ptr = GET_BIT(DDRC,PinId); break;
	case 3: *ptr = GET_BIT(DDRD,PinId); break;
	}
	return;
}
