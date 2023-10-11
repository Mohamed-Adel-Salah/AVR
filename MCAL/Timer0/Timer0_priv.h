/*
 * Timers_priv.h
 *
 *  Created on: Aug 4, 2023
 *      Author: hp
 */

//#include "Timers_confg.h"

#ifndef MCAL_TIMER0_TIMER0_PRIV_H_
#define MCAL_TIMER0_TIMER0_PRIV_H_

#define TCCR0   *((volatile u8 * )(0X53))

#define FOC0    Pin7
#define WGM00   Pin6
#define COM01   Pin5
#define COM00   Pin4
#define WGM01	Pin3
#define CS02    Pin2
#define CS01    Pin1
#define CS00    Pin0

#define TCNT0   *((volatile u8 * )(0X52))
#define OCR0	*((volatile u8 * )(0X5C))
#define TIMSK   *((volatile u8 * )(0X59))

#define OCIE0   Pin1
#define TOIE0   Pin0

#define TIFR    *((volatile u8 * )(0X58))

#define OCF0    Pin1
#define TOV0    Pin0

void __vector_11(void) __attribute__((signal , used));
void Timer0OVF_CallBack(void (*PF_Timer0OVF)(void));

void __vector_10(void) __attribute__((signal , used));
void Timer0CTC_CallBack(void (*PF_Timer0CTC)(void));

#endif /* MCAL_TIMER0_TIMER0_PRIV_H_ */
