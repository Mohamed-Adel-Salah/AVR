/*
 * SPI_int.h
 *
 *  Created on: Aug 12, 2023
 *      Author: hp
 */

#ifndef MCAL_SPI_SPI_INT_H_
#define MCAL_SPI_SPI_INT_H_

void SPI_voidInitialization(void);

void SPI_voidInterruptEnable(void);
void SPI_voidInterruptDisable(void);

void SPI_MasterTransmit(u8 Data);
u8	 SPI_MasterRecieve(void);
u8	 SPI_MasterTransive(u8 Data);

void SPI_SlaveTransmit(u8 Data);
u8	 SPI_SlaveRecieve(void);
u8	 SPI_SlaveTransive(u8 Data);

void SPI_CallBack(void (* SPI_CallBack_PTR)(void));
void __vector_12(void);



#endif /* MCAL_SPI_SPI_INT_H_ */
