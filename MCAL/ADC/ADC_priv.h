/*
 * ADC_priv.h
 *
 *  Created on: Jul 29, 2023
 *      Author: hp
 */

#ifndef MCAL_ADC_ADC_PRIV_H_
#define MCAL_ADC_ADC_PRIV_H_

void __vector_16(void) __attribute__((signal , used));

void ADC_CallBack(void (*PF_ADC)(void));

#endif /* MCAL_ADC_ADC_PRIV_H_ */
