
#include "STD_Types.h"
#include "Macros.h"

#include "DIO_int.h"
#include "DIO_reg.h"

#include "LCD_KIT_int.h"

#include "GIE_int.h"

#include "ADC_int.h"
#include "ADC_priv.h"


#include <util/delay.h>




void ADC_voidReadConversionValue(void)
{
//	u16 Value=ADCL;
//
//	if(GET_BIT(ADCH,Pin0))
//	{
//		Value+=256;
//	}
//	if(GET_BIT(ADCH,Pin1))
//	{
//		Value+=512;
//	}

	LCD_KIT_voidRunCommand(0x01);
	LCD_KIT_voidDisplayBigNumber((u16)(ADCL|(ADCH<<8)));

	SET_BIT(ADCSRA,ADIF);

	return ;
}

int main(void)
{
	DIO_voidInitialization();

	ADC_voidInitialization();
	LCD_KIT_voidInitialization();

	ADC_CallBack(ADC_voidReadConversionValue);

	GIE_Enable();
	//ADC_voidInterruptEnable();



	while(1)
	{
		ADC_voidStartConversion(0);

		ADC_voidReadConversionValue_Polling();
		LCD_KIT_voidDisplayString("Finally");
		//_delay_ms(500);
	}

	return 0;
}

