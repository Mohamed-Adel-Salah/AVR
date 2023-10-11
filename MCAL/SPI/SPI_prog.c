/*
 * SPI_prog.c
 *
 *  Created on: Aug 12, 2023
 *      Author: hp
 */


#include "Std_types.h"
#include "Macros.h"

#include "DIO_int.h"

#include "SPI_int.h"
#include "SPI_priv.h"
#include "SPI_confg.h"

void SPI_voidInitialization(void)
{
#if		(Mode==Master_Mode)

	DIO_voidSetPinDirection(SPI_PORT,SPI_MOSI,Output);
	DIO_voidSetPinDirection(SPI_PORT,SPI_MISO,Input);
	DIO_voidSetPinDirection(SPI_PORT,SPI_CS,Output);
	DIO_voidSetPinDirection(SPI_PORT,SPI_SCK,Output);

	//DIO_voidSetPinValue(SPI_PORT,SPI_MOSI,High);
	//DIO_voidSetPinValue(SPI_PORT,SPI_MISO,High);
	DIO_voidSetPinValue(SPI_PORT,SPI_CS,High);
	//DIO_voidSetPinValue(SPI_PORT,SPI_SCK,High);

	SET_BIT(SPI_SPCR,SPI_SPCR_MSTR);

	#if 	(IDLE_State==HIGH_IDle_State)

		SET_BIT(SPI_SPCR,SPI_SPCR_CPOL);

	#elif 	(IDLE_State==LOW_IDle_State)

		CLR_BIT(SPI_SPCR,SPI_SPCR_CPOL);

	#endif

	#if 	(Sampling_mode==Sampling_At_First)

		CLR_BIT(SPI_SPCR,SPI_SPCR_CPHA);

	#elif 	(Sampling_mode==Sampling_At_Last)

		SET_BIT(SPI_SPCR,SPI_SPCR_CPHA);

	#endif

	#if		(SPI_SCK_FREQ==SPI_SCK_FREQ_DIVI_4)

		CLR_BIT(SPI_SPCR,SPI_SPCR_SPR0);
		CLR_BIT(SPI_SPCR,SPI_SPCR_SPR01);
		CLR_BIT(SPI_SPSR,SPI_SPSR_SPI2X);

	#elif		(SPI_SCK_FREQ==SPI_SCK_FREQ_DIVI_8)

		CLR_BIT(SPI_SPCR,SPI_SPCR_SPR0);
		CLR_BIT(SPI_SPCR,SPI_SPCR_SPR01);
		SET_BIT(SPI_SPSR,SPI_SPSR_SPI2X);

	#elif		(SPI_SCK_FREQ==SPI_SCK_FREQ_DIVI_16)

		SET_BIT(SPI_SPCR,SPI_SPCR_SPR0);
		CLR_BIT(SPI_SPCR,SPI_SPCR_SPR01);
		CLR_BIT(SPI_SPSR,SPI_SPSR_SPI2X);

	#elif		(SPI_SCK_FREQ==SPI_SCK_FREQ_DIVI_64)

		CLR_BIT(SPI_SPCR,SPI_SPCR_SPR0);
		SET_BIT(SPI_SPCR,SPI_SPCR_SPR01);
		CLR_BIT(SPI_SPSR,SPI_SPSR_SPI2X);

	#elif		(SPI_SCK_FREQ==SPI_SCK_FREQ_DIVI_128)

		SET_BIT(SPI_SPCR,SPI_SPCR_SPR0);
		SET_BIT(SPI_SPCR,SPI_SPCR_SPR01);
		CLR_BIT(SPI_SPSR,SPI_SPSR_SPI2X);


	#endif

#elif		(Mode==Slave_Mode)

		DIO_voidSetPinDirection(SPI_PORT,SPI_MOSI,Input);
		DIO_voidSetPinDirection(SPI_PORT,SPI_MISO,Output);
		DIO_voidSetPinDirection(SPI_PORT,SPI_CS,Input);
		DIO_voidSetPinDirection(SPI_PORT,SPI_SCK,Input);

		DIO_voidSetPinValue(SPI_PORT,SPI_MISO,High);

		CLR_BIT(SPI_SPCR,SPI_SPCR_MSTR);

#endif

	SET_BIT(SPI_SPCR,SPI_SPCR_SPE);
	CLR_BIT(SPI_SPCR,SPI_SPCR_DORD);
}

void SPI_MasterTransmit(u8 Data)
{
	DIO_voidSetPinValue(SPI_PORT,SPI_CS,Low);

	//LCD_KIT_voidDisplayCharacter(SPI_SPDR);
	SPI_SPDR = Data;
	//LCD_KIT_voidDisplayCharacter(SPI_SPDR);
	while(!GET_BIT(SPI_SPSR,SPI_SPSR_SPIF));
	//LCD_KIT_voidDisplayCharacter(SPI_SPDR);
	//Data = SPI_SPSR;
	//Data = SPI_SPDR;

	DIO_voidSetPinValue(SPI_PORT,SPI_CS,Low);
}

u8	 SPI_MasterRecieve(void)
{
	//SPI_SPDR = Dummy_Data;

	while(!GET_BIT(SPI_SPSR,SPI_SPSR_SPIF));

	//Data = SPI_SPSR;
	return SPI_SPDR;
}

u8	 SPI_MasterTransive(u8 Data)
{
	SPI_SPDR = Data;

	while(!GET_BIT(SPI_SPSR,SPI_SPSR_SPIF));

	Data = SPI_SPSR;
	return SPI_SPDR;
}



void SPI_SlaveTransmit(u8 Data)
{
	SPI_SPDR = Data;

	while(!GET_BIT(SPI_SPSR,SPI_SPSR_SPIF));

	Data = SPI_SPSR;
	Data = SPI_SPDR;
}

u8	 SPI_SlaveRecieve(void)
{
	while(!GET_BIT(SPI_SPSR,SPI_SPSR_SPIF));

	//Data = SPI_SPSR;
	return SPI_SPDR;
}

u8	 SPI_SlaveTransive(u8 Data)
{
	SPI_SPDR = Data;

	while(!GET_BIT(SPI_SPSR,SPI_SPSR_SPIF));

	Data = SPI_SPSR;
	return SPI_SPDR;
}

void SPI_voidInterruptEnable(void)
{
	SET_BIT(SPI_SPCR,SPI_SPCR_SPIE);
}
void SPI_voidInterruptDisable(void)
{
	CLR_BIT(SPI_SPCR,SPI_SPCR_SPIE);
}

void (* SPI_PTR)(void)=NULL;
void SPI_CallBack(void (* SPI_CallBack_PTR)(void))
{
	SPI_PTR = SPI_CallBack_PTR;
}

void __vector_12(void)
{
	SPI_PTR();
}





