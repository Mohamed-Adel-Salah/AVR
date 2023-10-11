#include "STD_Types.h"
#include "Macros.h"

#include "DIO_int.h"
#include "DIO_reg.h"

#include "LCD_KIT_int.h"

#include "KEYBAD_int.h"
#include "KEYPAD_priv.h"

#include <util/delay.h>

u16 Power(u8 x , u8 y)
{
	u8 res=1;

	if(y==0)
	{
		return res;
	}

	while(y!=0)
	{
		res*=x;
		y--;
	}

	return res;
}

int main(void)
{
	LCD_KIT_voidInitialization();
	KEYBAD_voidInitialization();


	u8 Row=3,Col=3,Flag=0,Equal_flag=0;

	u8 Operator_Counter=1;

	u8 Operator_Position[20];
	Operator_Position[0]=0;
	u16 Operand_Value[19]={0};

	u8  Operation_arr[39];
	Operation_arr[0]='S';
	u8 Operation_arr_Counter=1;

	u16 res;

	while(1)
	{
		KEYBAD_voidGetPressedKey(&Row , &Col , &Flag);

		if(Flag==1)
		{
			LCD_KIT_voidDisplayCharacter(Keypad[Row][Col]);

			Operation_arr[Operation_arr_Counter]=Keypad[Row][Col];

			if((Keypad[Row][Col]=='+')||(Keypad[Row][Col]=='-')||(Keypad[Row][Col]=='*')||(Keypad[Row][Col]=='/')||(Keypad[Row][Col]=='='))
			{
				Operator_Position[Operator_Counter]=Operation_arr_Counter;
				Operator_Counter++;
			}

			Operation_arr_Counter++;

			_delay_ms(200);
			Flag=0;
			break;
		}
	}

	while(1)
	{
		KEYBAD_voidGetPressedKey(&Row , &Col , &Flag);

		if((Flag==1)&&(Equal_flag==0))
		{
			if(Keypad[Row][Col]=='#')
			{
				if((Operation_arr[Operation_arr_Counter-1]=='+')||(Operation_arr[Operation_arr_Counter-1]=='-')||(Operation_arr[Operation_arr_Counter-1]=='*')||(Operation_arr[Operation_arr_Counter-1]=='/'))
				{
					Operator_Counter--;
				}

				LCD_KIT_voidRunCommand(0x10);
				LCD_KIT_voidDisplayCharacter(' ');
				LCD_KIT_voidRunCommand(0x10);

				Operation_arr_Counter--;

				_delay_ms(200);
				Flag=0;

				continue;
			}

			LCD_KIT_voidDisplayCharacter(Keypad[Row][Col]);

			Operation_arr[Operation_arr_Counter]=Keypad[Row][Col];

			if((Keypad[Row][Col]=='+')||(Keypad[Row][Col]=='-')||(Keypad[Row][Col]=='*')||(Keypad[Row][Col]=='/')||(Keypad[Row][Col]=='='))
			{
				Operator_Position[Operator_Counter]=Operation_arr_Counter;
				Operator_Counter++;
			}

			Operation_arr_Counter++;

			_delay_ms(100);
			Flag=0;
		}
		else if((Flag==1)&&(Equal_flag==1))
		{
			LCD_KIT_voidRunCommand(Clear_LCD);

			Equal_flag=0;

			for(u8 i=0;i<19;i++)
			{
				Operand_Value[i]=0;
			}
			Operator_Counter=1;

			Operation_arr_Counter=1;

			if(Keypad[Row][Col]!='#')
			{
				LCD_KIT_voidDisplayCharacter(Keypad[Row][Col]);
				Operation_arr[Operation_arr_Counter]=Keypad[Row][Col];

				if((Keypad[Row][Col]=='+')||(Keypad[Row][Col]=='-')||(Keypad[Row][Col]=='*')||(Keypad[Row][Col]=='/')||(Keypad[Row][Col]=='='))
				{
					Operator_Position[Operator_Counter]=Operation_arr_Counter;
					Operator_Counter++;
				}

				Operation_arr_Counter++;
			}

			_delay_ms(100);
			Flag=0;


		}

		if((Keypad[Row][Col]=='=')&&(Equal_flag==0))
		{
			/***************Get Operand Values***********************/
			for(u8 i=0;i<Operator_Counter-1;i++)
			{
				for(u8 j=Operator_Position[i]+1;j<Operator_Position[i+1];j++)
				{
					Operand_Value[i]+=(Operation_arr[j]-48)*Power(10,Operator_Position[i+1]-j-1);
				}
			}

			for(u8 i=1;i<Operator_Counter-1;i++)
			{
				if(Operation_arr[Operator_Position[i]]=='*')
				{
					Operand_Value[i-1] *= Operand_Value[i];

					for(u8 j=i;j<Operator_Counter-2;j++)
					{
						Operand_Value[j]=Operand_Value[j+1];
						Operator_Position[j]=Operator_Position[j+1];
					}

					i--;

					Operator_Counter--;
				}
				else if(Operation_arr[Operator_Position[i]]=='/')
				{
					Operand_Value[i-1] /= Operand_Value[i];

					for(u8 j=i;j<Operator_Counter-2;j++)
					{
						Operand_Value[j]=Operand_Value[j+1];
						Operator_Position[j]=Operator_Position[j+1];
					}

					i--;

					Operator_Counter--;
				}
				else
				{

				}
			}

			for(u8 i=0;i<Operator_Counter-1;i++)
			{
				if(Operation_arr[Operator_Position[i]]=='S')
				{
					res=Operand_Value[i];
				}
				else if(Operation_arr[Operator_Position[i]]=='+')
				{
					res+=Operand_Value[i];
				}
				else if(Operation_arr[Operator_Position[i]]=='-')
				{
					res-=Operand_Value[i];
				}
			}

			LCD_KIT_voidDisplayBigNumber(res);

			Equal_flag=1;
		}
	}

	return 0;
}
