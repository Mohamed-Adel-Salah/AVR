/*
 * USART_priv.h
 *
 *  Created on: Jul 31, 2023
 *      Author: hp
 */

#ifndef MCAL_USART_USART_PRIV_H_
#define MCAL_USART_USART_PRIV_H_

#define UCSRA	*((volatile u8 * )(0X2B))

#define RXC     Pin7		// Receive Complete Flag			( automatically cleared )
#define TXC     Pin6		// Transmit Complete Flag			( automatically cleared OR Setting Bit by 1)
#define UDRE    Pin5		// UDR is empty and ready to receive again
#define FE      Pin4
#define DOR     Pin3
#define PE      Pin2
#define U2X     Pin1		// 1--> for double speed at Asynchronous mode
#define MPCM    Pin0

#define UCSRB	*((volatile u8 * )(0X2A))

#define RXCIE   Pin7		// Receive Complete interrupt Flag
#define TXCIE   Pin6        // Transmit Complete interrupt Flag
#define UDRIE   Pin5
#define RXEN    Pin4		// Receiver Enable
#define TXEN	Pin3		// Transmitter Enable
#define UCSZ2   Pin2		// 1--> for 9 Bit Data
#define RXB8    Pin1		// 9th Received bit
#define TXB8    Pin0		// 9th Transmitted bit

#define UCSRC	*((volatile u8 * )(0X40))

#define URSEL   Pin7		// Must be 1 when writing to UCSRC and 0 when writing to UBRRH
#define UMSEL   Pin6		// 0--> Asynchronous Mode
#define UPM1    Pin5		// 00--> Disabled		01-->Reserved
#define UPM0    Pin4		// 10--> Even Parity	11--> Odd Parity
#define USBS	Pin3		// 0--> 1 stop bit		1--> 2 stop bits
#define UCSZ1   Pin2		// 00--> 5 Bits			01--> 6 Bits
#define UCSZ0   Pin1		// 10--> 7 Bits			11--> (8,9) Bits
#define UCPOL   Pin0		// 0--> for Asynchronous mode

#define UBRRH   *((volatile u8 * )(0X40))
#define UBRRL   *((volatile u8 * )(0X29))
#define UDR		*((volatile u8 * )(0X2C))


void __vector_13(void);
void USART_RecieveCallBack(void (*PF_USART_Recieve)(void));

void __vector_14(void);
void USART_SendCallBack(void (*PF_USART_Send)(void));


#endif /* MCAL_USART_USART_PRIV_H_ */
