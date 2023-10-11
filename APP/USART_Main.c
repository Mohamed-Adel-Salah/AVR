

#include "STD_Types.h"
#include "Macros.h"

#include "DIO_int.h"
#include "DIO_reg.h"

#include "LCD_KIT_int.h"

#include "GIE_int.h"

#include "USART_int.h"
#include "USART_priv.h"

#include <util/delay.h>


u8 UDR_Global;

u8 temp;

void USART_voidSendData_Intrrupt(u8 Character)
{
	UDR=Character;

	CLR_BIT(UCSRA,UDRE);

	return;
}

void USART_voidRecieveData_Interrupt(void)
{
	LCD_KIT_voidDisplayCharacter('A');

	UDR_Global=UDR;
	//temp=UDR;

	LCD_KIT_voidDisplayCharacter(UDR_Global);
	//LCD_KIT_voidDisplayCharacter(temp);
	//SET_BIT(UCSRA,RXC);

//	GIE_Disable();
//	GIE_Enable();

//	CLR_BIT(UCSRB,RXEN);
//	SET_BIT(UCSRB,RXEN);


}

int main(void)
{
	USART_RecieveCallBack(USART_voidRecieveData_Interrupt);
		//USART_SendCallBack(USART_voidSendData_Intrrupt);

	DIO_voidInitialization();

	LCD_KIT_voidInitialization();

	USART_voidInitialization();

	GIE_Enable();

//	_delay_ms(200);
//	USART_voidSendData_Polling(65);
//	_delay_ms(200);
//	USART_voidSendData_Polling('h');
//	_delay_ms(200);
//	USART_voidSendData_Polling('m');
//	_delay_ms(200);
//	USART_voidSendData_Polling('e');
//	_delay_ms(200);
//	USART_voidSendData_Polling('d');
//	_delay_ms(200);

//	USART_voidRecieveData_Polling();
//	LCD_KIT_voidDisplayCharacter(UDR_Global);
//
//	USART_voidRecieveData_Polling();
//	LCD_KIT_voidDisplayCharacter(UDR_Global);
//
//	USART_voidRecieveData_Polling();
//	LCD_KIT_voidDisplayCharacter(UDR_Global);

	while(1)
	{
//		LCD_KIT_voidDisplayCharacter('g');
//		_delay_ms(50);

		//		USART_voidRecieveData_Polling();
//		LCD_KIT_voidDisplayCharacter(UDR_Global);
//		_delay_ms(1000);

	}


	return 0;
}
