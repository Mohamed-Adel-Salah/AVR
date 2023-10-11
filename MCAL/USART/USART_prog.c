/*
 * USART_prog.c
 *
 *  Created on: Jul 31, 2023
 *      Author: hp
 */

#include "Std_types.h"
#include "Macros.h"

#include "DIO_int.h"

#include "USART_int.h"
#include "USART_priv.h"

#include <util/delay.h>


void USART_voidInitialization(void)
{
	u8 UCSRC_Value = 0x80;

	// No double speed
	CLR_BIT(UCSRA,U2X);

	// Disable Multi-processor Communication Mode
	CLR_BIT(UCSRA,MPCM);

//	// writing in UCSRC
//	SET_BIT(UCSRC,URSEL);

	// Asynchronous Mode
	CLR_BIT(UCSRC_Value,UMSEL);

	// Disable Parity check
	CLR_BIT(UCSRC_Value,UPM1);
	CLR_BIT(UCSRC_Value,UPM0);

	// 1 Stop Bit
	CLR_BIT(UCSRC_Value,USBS);

	// 8 Bit Data
	CLR_BIT(UCSRB,UCSZ2);
	SET_BIT(UCSRC_Value,UCSZ1);
	SET_BIT(UCSRC_Value,UCSZ0);

	// 0--> for Asynchronous mode
	CLR_BIT(UCSRC_Value,UCPOL);

	UCSRC = UCSRC_Value;

	// Baud Rate = 9600
	UBRRL=103;

	// Enabling Receiver & Transmitter
	SET_BIT(UCSRB,RXEN);
	SET_BIT(UCSRB,TXEN);

	return;
}

void USART_voidSendData_Polling(u8 Character)
{
	while(!GET_BIT(UCSRA,UDRE));

	UDR=Character;

	//while(GET_BIT(UCSRA,UDRE));

	return;
}

void USART_voidSendString_Polling(u8* STR_Ptr)
{
	for(u8 i=0;STR_Ptr[i];i++)
	{
		USART_voidSendData_Polling(STR_Ptr[i]);
		//_delay_ms(500);
	}

	return;
}

u8 USART_u8RecieveData_Polling(void)
{
	while(!GET_BIT(UCSRA,RXC));

	return UDR;
}

void USART_voidEnableReceiverInterrupt(void)
{
	SET_BIT(UCSRB,RXCIE);
}
void USART_voidDisableReceiverInterrupt(void)
{
	CLR_BIT(UCSRB,RXCIE);
}
void USART_voidEnableTransmitterInterrupt(void)
{
	SET_BIT(UCSRB,TXCIE);
}
void USART_voidDisableTransmitterInterrupt(void)
{
	CLR_BIT(UCSRB,TXCIE);
}



void (*USART_Recieve_ISR)(void)=NULL;
void __vector_13(void)
{
	USART_Recieve_ISR();
}
void USART_RecieveCallBack(void (*PF_USART_Recieve)(void))
{
	USART_Recieve_ISR=PF_USART_Recieve;
}

void (*USART_Send_ISR)(void)=NULL;
void __vector_15(void)
{
	USART_Send_ISR();
}
void USART_SendCallBack(void (*PF_USART_Send)(void))
{
	USART_Send_ISR=PF_USART_Send;
}




