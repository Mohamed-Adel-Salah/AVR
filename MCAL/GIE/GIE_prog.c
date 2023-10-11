/*
 * GIE_prog.c
 *
 *  Created on: Jul 28, 2023
 *      Author: hp
 */

#include "STD_Types.h"
#include "Macros.h"

#include "DIO_int.h"

#include "GIE_int.h"
#include "GIE_priv.h"

void GIE_Enable (void)
{
	SET_BIT(SREG,GIE);
}

void GIE_Disable(void)
{
	CLR_BIT(SREG,GIE);
}
