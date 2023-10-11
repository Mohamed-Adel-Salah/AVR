
#include "STD_Types.h"
#include "Macros.h"


#include "DIO_int.h"
#include "DIO_reg.h"

#include "LCD_KIT_int.h"

#include "GIE_int.h"

#include "Timer0_int.h"
#include "Timer0_priv.h"
#include "Timer0_confg.h"
#include "Timer1_int.h"
#include "Timer1_priv.h"
#include "Timer1_confg.h"

#include <util/delay.h>


volatile u8 flag=0;
volatile u32 T_0=0;
volatile u32 T_1;
volatile u32 T_2;
volatile u32 T_3;
void Timer1_ICR_interrupt(void)
{
	if(flag==0)
	{
		T_0=ICR1+OVF_Counter*65536;
//		TCNT1=0;
//		OVF_Counter=0;
		//Timer1_voidCaptureEdgeSelect(Falling_Edge);
		SET_BIT(TCCR1B,TCCR1B_ICES1);
		flag++;
	}
	else if(flag==1)
	{
		T_1=ICR1+OVF_Counter*65536;
//		TCNT1=0;
//		OVF_Counter=0;
		//Timer1_voidCaptureEdgeSelect(Rising_Edge);
		CLR_BIT(TCCR1B,TCCR1B_ICES1);
		flag++;
	}
	else if(flag==2)
	{
		T_2=ICR1+OVF_Counter*65536;
//		TCNT1=0;
//		OVF_Counter=0;
		//Timer1_voidCaptureEdgeSelect(Falling_Edge);
		SET_BIT(TCCR1B,TCCR1B_ICES1);
		flag++;
	}
	else if(flag==3)
		{
			T_3=ICR1+OVF_Counter*65536;
			flag++;

			Timer1_voidICRInterruptDisable();
			Timer1_voidOVFInterruptDisable();
		}
}

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

	Timer1ICR_CallBack(Timer1_ICR_interrupt);
	Timer1OVF_CallBack(Timer1_OVF_interrupt);

	DIO_voidInitialization();
	Timer0_voidInitialization();
	Timer1_voidInitialization();

	LCD_KIT_voidInitialization();

	//_delay_ms(501);
	//_delay_ms(534);

	//Timer1_voidCaptureEdgeSelect(Rising_Edge);
	CLR_BIT(TCCR1B,TCCR1B_ICES1);

	GIE_Enable();
	Timer1_voidOVFInterruptEnable();
	Timer1_voidICRInterruptEnable();


	while(1)
	{
//		LCD_KIT_voidSetCurser(Line1,Col0);
//		LCD_KIT_voidDisplayBigNumber(T_0);
//		LCD_KIT_voidSetCurser(Line2,Col0);
//		LCD_KIT_voidDisplayBigNumber(T_1-T_0);
//		LCD_KIT_voidSetCurser(Line3,Col0);
//		LCD_KIT_voidDisplayBigNumber(T_2-T_0);
//		LCD_KIT_voidSetCurser(Line4,Col0);
//		LCD_KIT_voidDisplayBigNumber(T_3-T_0);

		if(flag==3)
		{
			LCD_KIT_voidSetCurser(Line1,Col0);
			LCD_KIT_voidDisplayString("Period is ");
			LCD_KIT_voidDisplayBigNumber((T_2-T_0)/8);
			LCD_KIT_voidDisplayString(" Ms");

			LCD_KIT_voidSetCurser(Line2,Col0);
			LCD_KIT_voidDisplayString("Duty Cycle is ");
			LCD_KIT_voidDisplayBigNumber((((float)(T_2-T_1))/(T_2-T_0))*100);
			LCD_KIT_voidDisplayCharacter('%');
		}

	}
	return 0;
}
