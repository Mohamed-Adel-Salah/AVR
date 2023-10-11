/*
 * Timer1_int.h
 *
 *  Created on: Aug 5, 2023
 *      Author: hp
 */

#ifndef MCAL_TIMER1_TIMER1_INT_H_
#define MCAL_TIMER1_TIMER1_INT_H_

void Timer1_voidInitialization(void);

void Timer1_voidSetFrequency(u8 Freq);
void Timer1_voidSetDutyCycle(u8 Duty);

void Timer1_voidCaptureEdgeSelect(u8 Edge_Select);
void Timer1_voidSetTimervalue(u16 Value);
u16 Timer1_voidGetTimervalue(void);
void Timer1_voidICRInterruptEnable(void);
void Timer1_voidICRInterruptDisable(void);
void Timer1_voidOVFInterruptEnable(void);
void Timer1_voidOVFInterruptDisable(void);


#endif /* MCAL_TIMER1_TIMER1_INT_H_ */
