/*
 * Timer1_priv.h
 *
 *  Created on: Aug 5, 2023
 *      Author: hp
 */

#ifndef MCAL_TIMER1_TIMER1_PRIV_H_
#define MCAL_TIMER1_TIMER1_PRIV_H_

#define TCCR1A  *((volatile u8 * )(0X4F))

#define TCCR1A_COM1A1  Pin7
#define TCCR1A_COM1A0  Pin6
#define TCCR1A_COM1B1  Pin5
#define TCCR1A_COM1B0  Pin4
#define TCCR1A_FOC1A   Pin3
#define TCCR1A_FOC1B   Pin2
#define TCCR1A_WGM11   Pin1
#define TCCR1A_WGM10   Pin0

#define TCCR1B	*((volatile u8 * )(0X4E))

#define TCCR1B_ICNC1   Pin7
#define TCCR1B_ICES1   Pin6
#define TCCR1B_WGM13   Pin4
#define TCCR1B_WGM12   Pin3
#define TCCR1B_CS12    Pin2
#define TCCR1B_CS11    Pin1
#define TCCR1B_CS10    Pin0

#define TCNT1H  *((volatile u8 * )(0X4D))
#define TCNT1L  *((volatile u8 * )(0X4C))
#define TCNT1   *((volatile u16 * )(0X4C))
#define OCR1AH	*((volatile u8 * )(0X4B))
#define OCR1AL  *((volatile u8 * )(0X4A))
#define OCR1A   *((volatile u16 * )(0X4A))
#define OCR1BH	*((volatile u8 * )(0X49))
#define OCR1BL  *((volatile u8 * )(0X48))
#define OCR1B   *((volatile u16 * )(0X48))
#define ICR1H	*((volatile u8 * )(0X47))
#define ICR1L   *((volatile u8 * )(0X46))
#define ICR1    *((volatile u16 * )(0X46))

#define TIMSK   *((volatile u8 * )(0X59))

#define TICIE1  Pin5
#define OCIE1A  Pin4
#define OCIE1B	Pin3
#define TOIE1   Pin2

#define TIFR    *((volatile u8 * )(0X58))

#define ICF1	Pin5
#define OCF1A	Pin4
#define OCF1B	Pin3
#define TOV1	Pin2


void __vector_6(void) __attribute__((signal , used));
void Timer1ICR_CallBack(void (*PF_Timer1ICR)(void));

void __vector_9(void) __attribute__((signal , used));
void Timer1OVF_CallBack(void (*PF_Timer1OVF)(void));

#endif /* MCAL_TIMER1_TIMER1_PRIV_H_ */
