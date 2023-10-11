#include "STD_Types.h"
#include "Macros.h"


#include "DIO_int.h"
#include "DIO_reg.h"

#include "Timer1_int.h"
#include "Timer1_priv.h"
#include "Timer1_confg.h"

#include <util/delay.h>

u16 OVF_Counter=0;
void Timer1_OVF_interrupt(void)
{
	OVF_Counter++;
//	LCD_KIT_voidDisplayCharacter('*');
//	LCD_KIT_voidDisplayCharacter(OVF_Counter+48);

	SET_BIT(TIFR,TOV1);
}

int main(void)
{
	DIO_voidInitialization();
	Timer1_voidInitialization();

	Timer1_voidSetFrequency(50);


	while(1)
	{
		Timer1_voidSetDutyCycle(50);
		_delay_ms(500);

		Timer1_voidSetDutyCycle(60);
		_delay_ms(500);

		Timer1_voidSetDutyCycle(70);
		_delay_ms(500);

		Timer1_voidSetDutyCycle(75);
		_delay_ms(500);

		Timer1_voidSetDutyCycle(80);
		_delay_ms(500);

		Timer1_voidSetDutyCycle(90);
		_delay_ms(500);

		Timer1_voidSetDutyCycle(100);
		_delay_ms(500);
	}
		return 0;
}
