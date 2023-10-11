/*
 * Timer_prog.c
 *
 *  Created on: Aug 5, 2023
 *      Author: hp
 */

#include "Std_types.h"
#include "Macros.h"

#include "DIO_int.h"

#include "Timer1_int.h"
#include "Timer1_priv.h"
#include "Timer1_confg.h"

void Timer1_voidInitialization(void)
{
#ifdef PWM
	// Set Mode (PWM, phase and frequency correct ICR1)
	SET_BIT(TCCR1B,TCCR1B_WGM13);
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);

	// Set NonInverted on OC1A
	SET_BIT(TCCR1A,TCCR1A_COM1A1);
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);

	// Setting Prescaler
	CLR_BIT(TCCR1B,TCCR1B_CS10);
	SET_BIT(TCCR1B,TCCR1B_CS11);
	CLR_BIT(TCCR1B,TCCR1B_CS12);

	TCNT1=0;

//	ICR1=10000;
//
//	OCR1A=500;


	#endif

#ifdef ICU
	// Set Normal Mode
	CLR_BIT(TCCR1B,TCCR1B_WGM13);
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);

	// Setting Prescaler
	SET_BIT(TCCR1B,TCCR1B_CS10);
	CLR_BIT(TCCR1B,TCCR1B_CS11);
	CLR_BIT(TCCR1B,TCCR1B_CS12);

	//SET_BIT(TIMSK,TOIE1);

	TCNT1 = 0;
	ICR1=0;
#endif
}


void Timer1_voidSetFrequency(u8 Freq)
{
	ICR1=1000000/(2*Freq);

	//ICR1=1000000/2*(float)((float)20/1000);
}
void Timer1_voidSetDutyCycle(u8 Duty)
{
	OCR1A=ICR1*(float)((float)Duty/1000);

	//OCR1A=ICR1*(float)((float)Duty/100);
}


void Timer1_voidCaptureEdgeSelect(u8 Edge_Select)
{
	switch(Edge_Select)
	{
	case 0: CLR_BIT(TCCR1B,TCCR1B_ICES1);break;
	case 1: SET_BIT(TCCR1B,TCCR1B_ICES1);break;
	}
}
void Timer1_voidSetTimervalue(u16 Value)
{
	ICR1=0;
}
u16 Timer1_voidGetTimervalue(void)
{
	return ICR1;
}
void Timer1_voidICRInterruptEnable(void)
{
	SET_BIT(TIMSK,TICIE1);
}
void Timer1_voidICRInterruptDisable(void)
{
	CLR_BIT(TIMSK,TICIE1);
}

void Timer1_voidOVFInterruptEnable(void)
{
	SET_BIT(TIMSK,TOIE1);
}
void Timer1_voidOVFInterruptDisable(void)
{
	CLR_BIT(TIMSK,TOIE1);
}

void (*Timer1ICR_ISR)(void)=NULL;
void __vector_6(void)
{
	Timer1ICR_ISR();
}
void Timer1ICR_CallBack(void (*PF_Timer1ICR)(void))
{
	Timer1ICR_ISR=PF_Timer1ICR;
}

void (*Timer1OVF_ISR)(void)=NULL;
void __vector_9(void)
{
	Timer1OVF_ISR();
}
void Timer1OVF_CallBack(void (*PF_Timer1OVF)(void))
{
	Timer1OVF_ISR=PF_Timer1OVF;
}


