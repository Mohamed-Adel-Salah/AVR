/*
 * EXT_INT_prog.c
 *
 *  Created on: Jul 28, 2023
 *      Author: hp
 */


#include "STD_Types.h"
#include "Macros.h"

#include "DIO_int.h"

#include "EXT_INT_int.h"
#include "EXT_INT_priv.h"


void EXT_INT_voidInitialization(void)
{

#ifdef EXTI0
	#ifdef EXTI0_Low_Level
		CLR_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);

		CLR_BIT(GICR,INTE0);
		SET_BIT(GIFR,INTF0);
	#endif

	#ifdef EXTI0_Any_Edge
		SET_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);

		CLR_BIT(GICR,INTE0);
		SET_BIT(GIFR,INTF0);
	#endif

	#ifdef EXTI0_Falling_Edge
		CLR_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);

		CLR_BIT(GICR,INTE0);
		SET_BIT(GIFR,INTF0);
	#endif

	#ifdef EXTI0_Rising_Edge
		SET_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);

		CLR_BIT(GICR,INTE0);
		SET_BIT(GIFR,INTF0);
	#endif
#endif

#ifdef EXTI1
	#ifdef EXTI1_Low_Level
		CLR_BIT(MCUCR,MCUCR_ISC10);
		CLR_BIT(MCUCR,MCUCR_ISC11);

		CLR_BIT(GICR,INTE1);
		SET_BIT(GIFR,INTF1);
	#endif

	#ifdef EXTI1_Any_Edge
		SET_BIT(MCUCR,MCUCR_ISC10);
		CLR_BIT(MCUCR,MCUCR_ISC11);

		CLR_BIT(GICR,INTE1);
		SET_BIT(GIFR,INTF1);
	#endif

	#ifdef EXTI1_Falling_Edge
		CLR_BIT(MCUCR,MCUCR_ISC10);
		SET_BIT(MCUCR,MCUCR_ISC11);

		CLR_BIT(GICR,INTE1);
		SET_BIT(GIFR,INTF1);
	#endif

	#ifdef EXTI1_Rising_Edge
		SET_BIT(MCUCR,MCUCR_ISC10);
		SET_BIT(MCUCR,MCUCR_ISC11);

		CLR_BIT(GICR,INTE1);
		SET_BIT(GIFR,INTF1);
	#endif
#endif

#ifdef EXTI2
	#ifdef EXTI2_Falling_Edge
		CLR_BIT(MCUCSR,MCUCSR_ISC2);

		CLR_BIT(GICR,INTE2);
		SET_BIT(GIFR,INTF2);
	#endif

	#ifdef EXTI2_Rising_Edge
		SET_BIT(MCUCSR,MCUCSR_ISC2);

		CLR_BIT(GICR,INTE2);
		SET_BIT(GIFR,INTF2);
	#endif
#endif

}

#ifdef EXTI0
void EXTI0_Enable(void)
{
	SET_BIT(GICR,INTE1);
}

void EXTI0_Disable(void)
{
	CLR_BIT(GICR,INTE1);
}
#endif

#ifdef EXTI1
void EXTI1_Enable(void)
{
	SET_BIT(GICR,INTE1);
}

void EXTI1_Disable(void)
{
	CLR_BIT(GICR,INTE1);
}
#endif

#ifdef EXTI2
void EXTI2_Enable(void)
{
	SET_BIT(GICR,INTE1);
}

void EXTI2_Disable(void)
{
	CLR_BIT(GICR,INTE1);
}
#endif


void (*EXTI1_ISR)(void)=NULL;
void __vector_2(void)
{
	EXTI1_ISR();
}
void EXTI1_CallBack(void (*PF_EXTI1)(void))
{
	EXTI1_ISR=PF_EXTI1;
}

//void EXTI1_CallBack(void (*PF_EXTI1)(u8,u8))
//{
//	EXTI1_ISR=PF_EXTI1;
//}
