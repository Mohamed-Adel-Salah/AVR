/*
 * UUSART_int.h
 *
 *  Created on: Jul 31, 2023
 *      Author: hp
 */

#ifndef MCAL_USART_USART_INT_H_
#define MCAL_USART_USART_INT_H_

void USART_voidInitialization(void);
void USART_voidSendData_Polling(u8 Character);
void USART_voidSendString_Polling(u8* STR_Ptr);
u8   USART_u8RecieveData_Polling(void);

void USART_voidEnableReceiverInterrupt(void);
void USART_voidDisableReceiverInterrupt(void);
void USART_voidEnableTransmitterInterrupt(void);
void USART_voidDisableTransmitterInterrupt(void);


#endif /* MCAL_USART_USART_INT_H_ */
