/*
 * EXT_INT_priv.h
 *
 *  Created on: Jul 28, 2023
 *      Author: hp
 */

#ifndef MCAL_EXT_INT_EXT_INT_PRIV_H_
#define MCAL_EXT_INT_EXT_INT_PRIV_H_

void __vector_2(void) __attribute__((signal , used));

void EXTI1_CallBack(void (*PF_EXTI1)(void));

//void EXTI1_CallBack(void (*PF_EXTI1)(u8,u8));

#endif /* MCAL_EXT_INT_EXT_INT_PRIV_H_ */
