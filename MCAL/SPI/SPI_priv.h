/*
 * SPI_priv.h
 *
 *  Created on: Aug 12, 2023
 *      Author: hp
 */

#ifndef MCAL_SPI_SPI_PRIV_H_
#define MCAL_SPI_SPI_PRIV_H_

#define 	Master_Mode				1
#define 	Slave_Mode				0

#define 	HIGH_IDle_State			1
#define 	LOW_IDle_State			0

#define 	Sampling_At_Last		1
#define 	Sampling_At_First		0

#define 	SPI_SCK_FREQ_DIVI_4		0
#define 	SPI_SCK_FREQ_DIVI_8		1
#define 	SPI_SCK_FREQ_DIVI_16	2
#define 	SPI_SCK_FREQ_DIVI_64	3
#define 	SPI_SCK_FREQ_DIVI_128	4

#define 	Dummy_Data				0xFF

#define 	SPI_SPCR			*((volatile u8 * )(0x2D))

#define 	SPI_SPCR_SPIE   	Pin7
#define 	SPI_SPCR_SPE    	Pin6
#define 	SPI_SPCR_DORD   	Pin5
#define 	SPI_SPCR_MSTR   	Pin4
#define 	SPI_SPCR_CPOL    	Pin3
#define 	SPI_SPCR_CPHA    	Pin2
#define 	SPI_SPCR_SPR01   	Pin1
#define 	SPI_SPCR_SPR0    	Pin0

#define 	SPI_SPSR			*((volatile u8 * )(0x2E))

#define 	SPI_SPSR_SPIF   	Pin7
#define 	SPI_SPSR_WCOL    	Pin6
#define 	SPI_SPSR_SPI2X    	Pin0

#define 	SPI_SPDR			*((volatile u8 * )(0x2F))

#endif /* MCAL_SPI_SPI_PRIV_H_ */
