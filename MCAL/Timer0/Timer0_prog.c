/*
 * Timers_prog.c
 *
 *  Created on: Aug 4, 2023
 *      Author: hp
 */


#include "Std_types.h"
#include "Macros.h"

#include "DIO_int.h"

#include "Timer0_confg.h"
#include "Timer0_int.h"
#include "Timer0_priv.h"




void Timer0_voidInitialization(void)
{
#ifdef Timer0
	#ifdef Normal_Mode
		CLR_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);

		// Setting Prescaler
		CLR_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);

		// Interrupts
		CLR_BIT(TIMSK,OCIE0);
		SET_BIT(TIMSK,TOIE0);

		TCNT0 = 6;
	#endif

	#ifdef CTC_Mode
		CLR_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);

		// Setting Prescaler
		CLR_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);

		// Interrupts
		SET_BIT(TIMSK,OCIE0);
		CLR_BIT(TIMSK,TOIE0);

		OCR0=249;
	#endif

	#ifdef PWM_PhasaCorrect
		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);

		// NonInverted PWM
		SET_BIT(TCCR0,COM01);
		CLR_BIT(TCCR0,COM00);

		// Setting Prescaler
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);

		OCR0=63;

	#endif

#endif

}

void (*Timer0OVF_ISR)(void)=NULL;
void __vector_11(void)
{
	Timer0OVF_ISR();
}

void Timer0OVF_CallBack(void (*PF_Timer0OVF)(void))
{
	Timer0OVF_ISR=PF_Timer0OVF;
}


void (*Timer0CTC_ISR)(void)=NULL;
void __vector_10(void)
{
	Timer0CTC_ISR();
}

void Timer0CTC_CallBack(void (*PF_Timer0CTC)(void))
{
	Timer0CTC_ISR=PF_Timer0CTC;
}
