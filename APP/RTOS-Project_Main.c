#include "STD_Types.h"
#include "Macros.h"

#include "DIO_int.h"
#include "DIO_reg.h"
#include "LCD_KIT_int.h"
#include "KEYBAD_int.h"
#include "KEYPAD_priv.h"
#include "GIE_int.h"
#include "ADC_int.h"
#include "ADC_priv.h"


#include "FreeRTOS.h"
#include "semphr.h"
#include "queue.h"
#include "event_groups.h"

#include "task.h"

#include <util/delay.h>



#define Flag_Pass	(1<<5)

QueueHandle_t xQueue_Password, xQueue_Equation;
EventGroupHandle_t xEventGroup;

SemaphoreHandle_t Mutex_LCD;

EventBits_t uxBits;

u8 Password[5] = "55555";

u8 ROW,COL,Flag,Queue_Index=0;


TaskHandle_t * Task1_Handler = NULL;
TaskHandle_t * Task2_Handler = NULL;
TaskHandle_t * Task3_Handler = NULL;
TaskHandle_t * Task4_Handler = NULL;

void TasK1(  void * PTR1 )
{
	LCD_KIT_voidSetCurser(Line1,Col0);
	LCD_KIT_voidDisplayString("Enter the Password");
	LCD_KIT_voidSetCurser(Line2,Col0);

	while(1)
	{
		//LCD_KIT_voidDisplayCharacter('L');

		uxBits = xEventGroupWaitBits( xEventGroup, Flag_Pass, pdTRUE, pdFALSE, ( TickType_t ) 10 );
		if( uxBits & Flag_Pass )
		{
			//LCD_KIT_voidDisplayCharacter('K');

			LCD_KIT_voidSetCurser(Line1,Col0);
			LCD_KIT_voidDisplayString("Correct Password");
			LCD_KIT_voidSetCurser(Line2,Col0);
			_delay_ms(500);

			vTaskResume(Task3_Handler);
			vTaskSuspend(Task1_Handler);
		}

		KEYBAD_voidGetPressedKey(&ROW,&COL,&Flag);

		if(Flag==1)
		{
			Flag=0;

			if( xSemaphoreTake(Mutex_LCD , ( TickType_t ) 10 ) == pdTRUE )
			{
				LCD_KIT_voidDisplayCharacter(Keypad[ROW][COL]);
				xSemaphoreGive( Mutex_LCD );
			}

			if(Queue_Index<5)
			{
				xQueueSendToBack( xQueue_Password, &Keypad[ROW][COL], ( TickType_t ) 10 );

//				u8 Recieve_Value;
//				xQueueReceive( xQueue_Password, &Recieve_Value, ( TickType_t ) 10 );
//				LCD_KIT_voidDisplayBigNumber(Recieve_Value);

				Queue_Index++;
			}

			_delay_ms(100);

			if(Queue_Index==5)
			{
				vTaskResume(Task2_Handler);
				vTaskSuspend(Task1_Handler);
			}

		}

		vTaskDelay(1000);
	}
}

void TasK2(  void * PTR2 )
{
	u8 Recieve_Value;
	u8 Error_Flag;
	while(1)
	{
		Error_Flag=0;

		for(u8 i=0;i<5;i++)
		{
			xQueueReceive( xQueue_Password, &Recieve_Value, ( TickType_t ) 10 );
			if(Recieve_Value != Password[i])
			{
				Error_Flag = 1;
				//LCD_KIT_voidDisplayCharacter(Recieve_Value);
			}
		}

		//_delay_ms(1000);

		LCD_KIT_voidRunCommand(0x01);
		Queue_Index=0;

		if(!Error_Flag)
		{
			uxBits = xEventGroupSetBits( xEventGroup, Flag_Pass );
		}
		else
		{
			LCD_KIT_voidSetCurser(Line1,Col0);
			LCD_KIT_voidDisplayString("Wrong Password");
			_delay_ms(500);
			LCD_KIT_voidRunCommand(0x01);
			LCD_KIT_voidDisplayString("Enter Password");
			LCD_KIT_voidSetCurser(Line2,Col0);
		}

		vTaskResume(Task1_Handler);
		vTaskSuspend(Task2_Handler);

		vTaskDelay(1000);
	}
}

void TasK3(  void * PTR3 )
{
	LCD_KIT_voidRunCommand(0x01);

	LCD_KIT_voidSetCurser(Line1,Col0);
	LCD_KIT_voidDisplayString("Enter Equation");
	LCD_KIT_voidSetCurser(Line2,Col0);

	while(1)
	{
		//LCD_KIT_voidDisplayCharacter('P');

		KEYBAD_voidGetPressedKey(&ROW,&COL,&Flag);

		if(Flag==1)
		{
			if( xSemaphoreTake(Mutex_LCD , ( TickType_t ) 10 ) == pdTRUE )
			{
				LCD_KIT_voidDisplayCharacter(Keypad[ROW][COL]);
				xSemaphoreGive( Mutex_LCD );
			}

			xQueueSendToBack( xQueue_Equation, &Keypad[ROW][COL], ( TickType_t ) 10 );

			Flag=0;

			if(Keypad[ROW][COL]=='=')
			{
				vTaskResume(Task4_Handler);
				vTaskSuspend(Task3_Handler);
			}

			_delay_ms(100);
		}

		vTaskDelay(1000);
	}
}

void TasK4(  void * PTR4 )
{
	u8 Recieve_Value;
	while(1)
	{
		static u16 res=0;
		static u8 opr=0;
		static u8 flag=0;
		static u8 Previous_operator='N';

		xQueueReceive( xQueue_Equation, &Recieve_Value, ( TickType_t ) 10 );
//		LCD_KIT_voidDisplayCharacter(Recieve_Value);


		if( (Recieve_Value != '*') && (Recieve_Value != '/')  && (Recieve_Value != '+') && (Recieve_Value != '-') && (Recieve_Value != '='))
		{
			//LCD_KIT_voidDisplayCharacter(Recieve_Value);
			opr *= 10;
			opr += Recieve_Value-48;
		}
		else if((Recieve_Value != '='))
		{
			switch(Previous_operator)
			{
			case '*': res*=opr;break;
			case '/': res/=opr;break;
			case '+': res+=opr;break;
			case '-': res-=opr;break;
			case 'N': res=opr;
			}
			Previous_operator = Recieve_Value;
			opr=0;
		}
		else if(Recieve_Value == '=')
		{
			switch(Previous_operator)
			{
			case '*': res*=opr;break;
			case '/': res/=opr;break;
			case '+': res+=opr;break;
			case '-': res-=opr;break;
			case 'N': break;
			}

			LCD_KIT_voidDisplayBigNumber(res);

			vTaskResume(Task1_Handler);
			vTaskSuspend(Task4_Handler);
			//_delay_ms(10000);
		}

//		else if(Recieve_Value == '*')
//		{
//			//LCD_KIT_voidDisplayCharacter(Recieve_Value);
//
//			switch(Previous_operator)
//			{
//			case '*': res*=opr;break;
//			case '/': res/=opr;break;
//			case '+': res+=opr;break;
//			case '-': res-=opr;break;
//			case '*': res*=opr;break;
//			}
//			res *= opr;
//			opr=0;
//		}
//		else if(Recieve_Value == '/')
//		{
//			//LCD_KIT_voidDisplayCharacter(Recieve_Value);
//			res /= opr;
//			opr=0;
//		}
//		else if(Recieve_Value == '+')
//		{
//			//LCD_KIT_voidDisplayCharacter(Recieve_Value);
//			res += opr;
//			opr=0;
//		}
//		else if(Recieve_Value == '-')
//		{
//			//LCD_KIT_voidDisplayCharacter('L');
//			res -= opr;
//			opr=0;
//		}
//		else if(Recieve_Value == '=')
//		{
//			//res *= opr;
//			//flag=1;
//
//			LCD_KIT_voidDisplayBigNumber(res);
//
//			//vTaskResume(Task1_Handler);
//			_delay_ms(1000);
//			vTaskSuspend(Task4_Handler);
//		}
//
//		if(flag==1)
//		{
//			LCD_KIT_voidDisplayBigNumber(res);
//			flag=0;
//
//			vTaskResume(Task1_Handler);
//			vTaskSuspend(Task4_Handler);
//		}

		vTaskDelay(1000);
	}
}

int main()
{
	LCD_KIT_voidInitialization();
	KEYBAD_voidInitialization();

	//LCD_KIT_voidDisplayCharacter('H');

	xQueue_Password = xQueueCreate( 5, sizeof( unsigned char ) );
	xQueue_Equation = xQueueCreate( 20, sizeof( u8 ) );

	xEventGroup = xEventGroupCreate();

	Mutex_LCD = xSemaphoreCreateMutex();



	u8 LED_ID_1 = 4;
	u8 LED_ID_2 = 5;
	u8 LED_ID_3 = 6;

	u8 Priority = 1;

	xTaskCreate(TasK1,"GET_PASSWORD",	150,&LED_ID_1,	3,	&Task1_Handler);
	xTaskCreate(TasK2,"CHECK_PASSWORD",	150,&LED_ID_2,	2,	&Task2_Handler);
	xTaskCreate(TasK3,"GET_EQUATION",	150,&LED_ID_3,	1,	&Task3_Handler);
	xTaskCreate(TasK4,"SOLVE_EQUATION",	150,&LED_ID_3,	1,	&Task4_Handler);

	vTaskSuspend(Task2_Handler);
	vTaskSuspend(Task3_Handler);
	vTaskSuspend(Task4_Handler);

	vTaskStartScheduler();

	while(1)
	{

	}

}
