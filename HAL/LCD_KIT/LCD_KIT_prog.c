/*
 * LCD_KIT_prog.c
 *
 *  Created on: Jul 23, 2023
 *      Author: hp
 */

#include <LCD_KIT_confg.h>
#include "STD_Types.h"
#include "Macros.h"

#include "DIO_int.h"
#include "DIO_priv.h"

#include "LCD_KIT_int.h"

#include <util/delay.h>


void LCD_KIT_voidInitialization(void)
{
	DIO_voidSetPinDirection(LCD_ADDRESS_PORT,LCD_ADDRESS_E,Output);
	DIO_voidSetPinDirection(LCD_ADDRESS_PORT,LCD_ADDRESS_RS,Output);

	DIO_voidSetPinDirection(LCD_DATA_PORT,LCD_DATA_PinD4,Output);
	DIO_voidSetPinDirection(LCD_DATA_PORT,LCD_DATA_PinD5,Output);
	DIO_voidSetPinDirection(LCD_DATA_PORT,LCD_DATA_PinD6,Output);
	DIO_voidSetPinDirection(LCD_DATA_PORT,LCD_DATA_PinD7,Output);

	_delay_ms(40);
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PinD4,Low);
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PinD5,High);
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PinD6,Low);
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PinD7,Low);

	DIO_voidSetPinValue(LCD_ADDRESS_PORT,LCD_ADDRESS_E,High);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_ADDRESS_PORT,LCD_ADDRESS_E,Low);
	_delay_ms(2);

	LCD_KIT_voidRunCommand(0x28);
	_delay_ms(1);

	LCD_KIT_voidRunCommand(0x0C);
	_delay_ms(1);

	LCD_KIT_voidRunCommand(0x01);
	_delay_ms(2);

	LCD_KIT_voidRunCommand(0x06);

	LCD_KIT_voidRunCommand(0x80);

	return;
}

void LCD_KIT_voidDisplayCharacter(u8 character)
{
	DIO_voidSetPinValue(LCD_ADDRESS_PORT,LCD_ADDRESS_RS,High);

	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PinD7,GET_BIT(character,Pin7));
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PinD6,GET_BIT(character,Pin6));
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PinD5,GET_BIT(character,Pin5));
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PinD4,GET_BIT(character,Pin4));

	DIO_voidSetPinValue(LCD_ADDRESS_PORT,LCD_ADDRESS_E,High);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_ADDRESS_PORT,LCD_ADDRESS_E,Low);
	_delay_ms(2);

	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PinD7,GET_BIT(character,Pin3));
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PinD6,GET_BIT(character,Pin2));
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PinD5,GET_BIT(character,Pin1));
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PinD4,GET_BIT(character,Pin0));

	DIO_voidSetPinValue(LCD_ADDRESS_PORT,LCD_ADDRESS_E,High);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_ADDRESS_PORT,LCD_ADDRESS_E,Low);
	_delay_ms(2);

	return;
}

void LCD_KIT_voidRunCommand(u8 command)
{
	DIO_voidSetPinValue(LCD_ADDRESS_PORT,LCD_ADDRESS_RS,Low);

	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PinD7,GET_BIT(command,Pin7));
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PinD6,GET_BIT(command,Pin6));
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PinD5,GET_BIT(command,Pin5));
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PinD4,GET_BIT(command,Pin4));

	DIO_voidSetPinValue(LCD_ADDRESS_PORT,LCD_ADDRESS_E,High);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_ADDRESS_PORT,LCD_ADDRESS_E,Low);
	_delay_ms(2);

	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PinD7,GET_BIT(command,Pin3));
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PinD6,GET_BIT(command,Pin2));
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PinD5,GET_BIT(command,Pin1));
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PinD4,GET_BIT(command,Pin0));
	//DIO_voidSetPinValue(PortB,Pin7,GET_BIT(command,Pin0));

	DIO_voidSetPinValue(LCD_ADDRESS_PORT,LCD_ADDRESS_E,High);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_ADDRESS_PORT,LCD_ADDRESS_E,Low);
	_delay_ms(2);

	return;
}

void LCD_KIT_voidSetCurser(u8 Line , u8 Col)
{
	LCD_KIT_voidRunCommand(Line+Col);

	return;
}

void LCD_KIT_voidDisplayString(u8 *Str)
{
	for(u8 j=0;Str[j]!='\0';j++)
	{
		LCD_KIT_voidDisplayCharacter(Str[j]);
	}
}

/*
void LCD_KIT_voidDisplayCustomCharacter(u8 *Str)
{
	for(u8 j=0;j<8;j++)
	{
		LCD_KIT_voidDisplayCharacter(Str[j]);
	}
}
*/

void LCD_KIT_voidDisplayBigNumber(u32 Number)
{
	if(Number<=9)
	{
		LCD_KIT_voidDisplayCharacter(Number+48);
	}
	else if(Number<=99)
	{
		LCD_KIT_voidDisplayCharacter(Number/10+48);
		LCD_KIT_voidDisplayCharacter(Number%10+48);
	}
	else if(Number<=999)
	{
		LCD_KIT_voidDisplayCharacter(Number/100+48);
		LCD_KIT_voidDisplayCharacter((Number/10)%10+48);
		LCD_KIT_voidDisplayCharacter(Number%10+48);
	}
	else if(Number<=9999)
	{
		LCD_KIT_voidDisplayCharacter(Number/1000+48);
		LCD_KIT_voidDisplayCharacter((Number/100)%10+48);
		LCD_KIT_voidDisplayCharacter((Number/10)%10+48);
		LCD_KIT_voidDisplayCharacter(Number%10+48);
	}
	else if(Number<=99999)
	{
		LCD_KIT_voidDisplayCharacter(Number/10000+48);
		LCD_KIT_voidDisplayCharacter((Number/1000)%10+48);
		LCD_KIT_voidDisplayCharacter((Number/100)%10+48);
		LCD_KIT_voidDisplayCharacter((Number/10)%10+48);
		LCD_KIT_voidDisplayCharacter(Number%10+48);
	}
	else if(Number<=999999)
		{
			LCD_KIT_voidDisplayCharacter(Number/100000+48);
			LCD_KIT_voidDisplayCharacter((Number/10000)%10+48);
			LCD_KIT_voidDisplayCharacter((Number/1000)%10+48);
			LCD_KIT_voidDisplayCharacter((Number/100)%10+48);
			LCD_KIT_voidDisplayCharacter((Number/10)%10+48);
			LCD_KIT_voidDisplayCharacter(Number%10+48);
		}
	else if(Number<=9999999)
			{
				LCD_KIT_voidDisplayCharacter(Number/1000000+48);
				LCD_KIT_voidDisplayCharacter((Number/100000)%10+48);
				LCD_KIT_voidDisplayCharacter((Number/10000)%10+48);
				LCD_KIT_voidDisplayCharacter((Number/1000)%10+48);
				LCD_KIT_voidDisplayCharacter((Number/100)%10+48);
				LCD_KIT_voidDisplayCharacter((Number/10)%10+48);
				LCD_KIT_voidDisplayCharacter(Number%10+48);
			}

	return;
}

void LCD_KIT_voidStoreCustomCharacter(u8 *Character, u8 Address)
{
	LCD_KIT_voidRunCommand(Address);

	for(u8 j=0;j<8;j++)
	{
		LCD_KIT_voidDisplayCharacter(Character[j]);
	}

	return;
}

