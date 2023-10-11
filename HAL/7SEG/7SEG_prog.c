/*
 * 7SEG_int.c
 *
 *  Created on: Jul 22, 2023
 *      Author: hp
 */
#include "STD_Types.h"
#include "Macros.h"

#include "DIO_int.h"

#include "7SEG_int.h"
#include "7SEG_priv.h"

void SEG_voidInitialization(void)
{
	DIO_voidSetPortDirection(SEG_PORT,Output);
}

void SEG_voidDisplayNumber(u8 Number)
{
	switch(Number)
	{
	case 0 : DIO_voidSetPortValue(SEG_PORT,SEG_Display0_Value); break;
	case 1 : DIO_voidSetPortValue(SEG_PORT,SEG_Display1_Value); break;
	case 2 : DIO_voidSetPortValue(SEG_PORT,SEG_Display2_Value); break;
	case 3 : DIO_voidSetPortValue(SEG_PORT,SEG_Display3_Value); break;
	case 4 : DIO_voidSetPortValue(SEG_PORT,SEG_Display4_Value); break;
	case 5 : DIO_voidSetPortValue(SEG_PORT,SEG_Display5_Value); break;
	case 6 : DIO_voidSetPortValue(SEG_PORT,SEG_Display6_Value); break;
	case 7 : DIO_voidSetPortValue(SEG_PORT,SEG_Display7_Value); break;
	case 8 : DIO_voidSetPortValue(SEG_PORT,SEG_Display8_Value); break;
	case 9 : DIO_voidSetPortValue(SEG_PORT,SEG_Display9_Value); break;
	}
	return;
}
