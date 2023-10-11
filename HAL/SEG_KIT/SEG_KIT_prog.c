/*
 * SEG_KIT_prog.c
 *
 *  Created on: Jul 22, 2023
 *      Author: hp
 */

#include "STD_Types.h"
#include "Macros.h"

#include "DIO_int.h"

#include "SEG_KIT_int.h"

#include <util/delay.h>

void SEG_KIT_voidInitialization(void)
{
	DIO_voidSetPinDirection(PortA,Pin3,Output);
	DIO_voidSetPinDirection(PortA,Pin2,Output);

	DIO_voidSetPinDirection(PortB,Pin5,Output);
	DIO_voidSetPinDirection(PortB,Pin6,Output);

	DIO_voidSetPinDirection(PortB,Pin0,Output);
	DIO_voidSetPinDirection(PortB,Pin1,Output);
	DIO_voidSetPinDirection(PortB,Pin2,Output);
	DIO_voidSetPinDirection(PortB,Pin4,Output);


	DIO_voidSetPinValue(PortA,Pin3,High);
	DIO_voidSetPinValue(PortA,Pin2,High);

	DIO_voidSetPinValue(PortB,Pin5,High);
	DIO_voidSetPinValue(PortB,Pin6,High);

	DIO_voidSetPinValue(PortB,Pin0,Low);
	DIO_voidSetPinValue(PortB,Pin1,Low);
	DIO_voidSetPinValue(PortB,Pin2,Low);
	DIO_voidSetPinValue(PortB,Pin4,Low);
}

void SEG_KIT_voidDisplayNumber(u8 Number,u8 SEGNumber)
{
	switch(Number)
	{
	case 0: DIO_voidSetPortValueMask(PortB,0,0xE8); break;
	case 1: DIO_voidSetPortValueMask(PortB,1,0xE8); break;
	case 2: DIO_voidSetPortValueMask(PortB,2,0xE8); break;
	case 3: DIO_voidSetPortValueMask(PortB,3,0xE8); break;
	case 4: DIO_voidSetPortValueMask(PortB,4,0xE8); break;
	case 5: DIO_voidSetPortValueMask(PortB,5,0xE8); break;
	case 6: DIO_voidSetPortValueMask(PortB,6,0xE8); break;
	case 7: DIO_voidSetPortValueMask(PortB,7,0xE8); break;
	case 8: DIO_voidSetPortValueMask(PortB,8+8,0xE8); break;
	case 9: DIO_voidSetPortValueMask(PortB,9+8,0xE8); break;
	}
	switch(SEGNumber)
	{
	case 1: DIO_voidSetPortValueMask(PortA,0x04,0xF3);DIO_voidSetPortValueMask(PortB,0x60,0x9F);break;
	case 2: DIO_voidSetPortValueMask(PortA,0x08,0xF3);DIO_voidSetPortValueMask(PortB,0x60,0x9F);break;
	case 3: DIO_voidSetPortValueMask(PortA,0x0C,0xF3);DIO_voidSetPortValueMask(PortB,0x40,0x9F);break;
	case 4: DIO_voidSetPortValueMask(PortA,0x0C,0xF3);DIO_voidSetPortValueMask(PortB,0x20,0x9F);break;
	}
}

void SEG_KIT_voidDisplayBigNumber(u16 Number)
{
	if(Number<=9)
	{
		SEG_KIT_voidDisplayNumber(Number,SEG1);
	}
	else if(Number<=99)
	{
		SEG_KIT_voidDisplayNumber(Number%10,SEG1);
		_delay_ms(2);
		SEG_KIT_voidDisplayNumber(Number/10,SEG2);
		_delay_ms(2);
	}
	else if(Number<=999)
		{
			SEG_KIT_voidDisplayNumber(Number%10,SEG1);
			_delay_ms(2);
			SEG_KIT_voidDisplayNumber((Number/10)%10,SEG2);
			_delay_ms(2);
			SEG_KIT_voidDisplayNumber(Number/100,SEG3);
			_delay_ms(2);
		}
	else
		{
			SEG_KIT_voidDisplayNumber(Number%10,SEG1);
			_delay_ms(2);
			SEG_KIT_voidDisplayNumber((Number/10)%10,SEG2);
			_delay_ms(2);
			SEG_KIT_voidDisplayNumber((Number/100)%10,SEG3);
			_delay_ms(2);
			SEG_KIT_voidDisplayNumber(Number/1000,SEG4);
			_delay_ms(2);
		}
}



