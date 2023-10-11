/*
 * ADC_prog.c
 *
 *  Created on: Jul 29, 2023
 *      Author: hp
 */

#include "STD_Types.h"
#include "Macros.h"

#include "DIO_int.h"

#include "ADC_int.h"
#include "ADC_priv.h"

void ADC_voidInitialization(void)
{
	// AVCC as a REF
	CLR_BIT(ADMUX,REFS1);
	SET_BIT(ADMUX,REFS0);

	// Right Adjusting
	DIO_voidSetPinValue(ADMUX,ADLAR,Low);

//	// Choosing Channel ADC0
//	CLR_BIT(ADMUX,MUX4);
//	CLR_BIT(ADMUX,MUX3);
//	CLR_BIT(ADMUX,MUX2);
//	CLR_BIT(ADMUX,MUX1);
//	CLR_BIT(ADMUX,MUX0);

	// Enabling ADC
	SET_BIT(ADCSRA,ADEN);

	// Auto Trigger Disable
	SET_BIT(ADCSRA,ADATE);

	// ADC Prescaler is 64
	SET_BIT(ADCSRA,ADPS2);
	SET_BIT(ADCSRA,ADPS1);
	CLR_BIT(ADCSRA,ADPS0);

	CLR_BIT(ADCSRA,ADIE);
	SET_BIT(ADCSRA,ADIF);
}

void ADC_voidInterruptEnable(void)
{
	SET_BIT(ADCSRA,ADIE);
}

void ADC_voidInterruptDisable(void)
{
	CLR_BIT(ADCSRA,ADIE);
}

void ADC_voidStartConversion(u8 Channel)
{
	CLR_BIT(ADMUX,MUX4);
	CLR_BIT(ADMUX,MUX3);

	switch(Channel)
	{
		case 0 : CLR_BIT(ADMUX,MUX2);CLR_BIT(ADMUX,MUX1);CLR_BIT(ADMUX,MUX0);break;
		case 1 : CLR_BIT(ADMUX,MUX2);CLR_BIT(ADMUX,MUX1);SET_BIT(ADMUX,MUX0);break;
		case 2 : CLR_BIT(ADMUX,MUX2);SET_BIT(ADMUX,MUX1);CLR_BIT(ADMUX,MUX0);break;
		case 3 : CLR_BIT(ADMUX,MUX2);SET_BIT(ADMUX,MUX1);SET_BIT(ADMUX,MUX0);break;
		case 4 : SET_BIT(ADMUX,MUX2);CLR_BIT(ADMUX,MUX1);CLR_BIT(ADMUX,MUX0);break;
		case 5 : SET_BIT(ADMUX,MUX2);CLR_BIT(ADMUX,MUX1);SET_BIT(ADMUX,MUX0);break;
		case 6 : SET_BIT(ADMUX,MUX2);SET_BIT(ADMUX,MUX1);CLR_BIT(ADMUX,MUX0);break;
		case 7 : SET_BIT(ADMUX,MUX2);SET_BIT(ADMUX,MUX1);SET_BIT(ADMUX,MUX0);break;
	}

	SET_BIT(ADCSRA,ADSC);
}

void ADC_voidReadConversionValue_Polling(void)
{
	while(!GET_BIT(ADCSRA,ADIF));
	LCD_KIT_voidRunCommand(0x01);
	LCD_KIT_voidDisplayBigNumber((u16)(ADCL|(ADCH<<8)));
}

void (*ADC_ISR)(void)=NULL;
void __vector_16(void)
{
	ADC_ISR();
}
void ADC_CallBack(void (*PF_ADC)(void))
{
	ADC_ISR=PF_ADC;
}



