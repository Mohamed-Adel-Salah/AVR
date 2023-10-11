/*
 * EXT_INT_int.h
 *
 *  Created on: Jul 28, 2023
 *      Author: hp
 */

#ifndef MCAL_EXT_INT_EXT_INT_INT_H_
#define MCAL_EXT_INT_EXT_INT_INT_H_

//#define EXTI0
//#define EXTI0_Low_Level
//#define EXTI0_Any_Edge
//#define EXTI0_Falling_Edge
//#define EXTI0_Rising_Edge

#define EXTI1
//#define EXTI1_Low_Level
//#define EXTI1_Any_Edge
#define EXTI1_Falling_Edge
//#define EXTI1_Rising_Edge

//#define EXTI2
//#define EXTI2_Falling_Edge
//#define EXTI2_Rising_Edge

#define MCUCR 	*((volatile u8 *)(0x55))

#define MCUCR_ISC00	Pin0
#define MCUCR_ISC01	Pin1
#define MCUCR_ISC10 Pin2
#define MCUCR_ISC11	Pin3

#define MCUCSR 	*((volatile u8 *)(0x54))

#define MCUCSR_ISC2	Pin6

#define GICR	*((volatile u8 *)(0x5B))

#define INTE1 Pin7
#define INTE0 Pin6
#define INTE2 Pin5

#define GIFR	*((volatile u8 *)(0x5A))

#define INTF1 Pin7
#define INTF0 Pin6
#define INTF2 Pin5


void EXT_INT_voidInitialization(void);
void EXTI0_Enable(void);
void EXTI1_Enable(void);
void EXTI2_Enable(void);
void EXTI0_Disable(void);
void EXTI1_Disable(void);
void EXTI2_Disable(void);

#endif /* MCAL_EXT_INT_EXT_INT_INT_H_ */
