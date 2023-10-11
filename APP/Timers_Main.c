
#include "STD_Types.h"
#include "Macros.h"

#include "LCD_KIT_int.h"

#include "GIE_int.h"

#include "Timer0_int.h"
#include "Timer0_priv.h"
#include "Timer0_confg.h"

#include <util/delay.h>





volatile u16 Counter=0;
void Timer0_OVF_Interrupt(void)
{
	Counter++;
	//TCNT0=6;

	if(Counter==4000)
	{
		DIO_voidTogglePin(PortB,Pin5);
		Counter=0;
	}
}

volatile u8 Counter_Seconds=0;
volatile u8 Counter_Minuts=0;
volatile u8 Counter_Hours=0;
void Timer0_CTC_Interrupt(void)
{
	Counter++;

	if(Counter==4000)
	{
		DIO_voidTogglePin(PortB,Pin5);
		Counter_Seconds++;
		Counter=0;
	}
}



int main(void)
{
	Timer0_voidInitialization();
	LCD_KIT_voidInitialization();
	DIO_voidInitialization();

	//Timer0OVF_CallBack(Timer0_OVF_Interrupt);
	Timer0CTC_CallBack(Timer0_CTC_Interrupt);

	LCD_KIT_voidDisplayString("00:00:00");

	//GIE_Enable();

	while(1)
	{
		Counter_Seconds++;
//			LCD_KIT_voidRunCommand(Clear_LCD);
//			LCD_KIT_voidSetCurser(Line1,Col0);
//			//LCD_KIT_voidDisplayBigNumber(Counter_Seconds);
//			LCD_KIT_voidDisplayCharacter(Counter_Seconds+48);
//			_delay_ms(100);

		if(Counter_Seconds<9)
		{
			LCD_KIT_voidSetCurser(Line1,Col7);
			LCD_KIT_voidDisplayCharacter(Counter_Seconds+48);
			//_delay_ms(1000);
		}
		else if(Counter_Seconds<60)
		{
			LCD_KIT_voidSetCurser(Line1,Col6);
			LCD_KIT_voidDisplayBigNumber(Counter_Seconds);
			//_delay_ms(1000);

		}
		else if(Counter_Seconds==60)
		{
			LCD_KIT_voidSetCurser(Line1,Col6);
			LCD_KIT_voidDisplayCharacter('0');
			LCD_KIT_voidDisplayCharacter('0');
			Counter_Minuts++;
		}

		//LCD_KIT_voidDisplayCharacter(Counter_Seconds+48);

	}

		return 0;
}
