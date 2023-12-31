/************************************/
/* Author		: Ali Azzouz		*/
/* SWC			: MEXTI				*/
/* Layer		: MCAL			    */
/* Version		: 1.0				*/
/* Date			: December 22,2023	*/
/* Last Edit	: N/A			 	*/
/************************************/
#include "LBIT_math.h"
#include "LSTD_types.h"

#include "MEXTI_private.h"
#include "MEXTI_interface.h"
static void (* MEXTI_pvoidfUserFunctionINT0)(VOID)=NULL_POINTER;
static void (* MEXTI_pvoidfUserFunctionINT1)(VOID)=NULL_POINTER;
static void (* MEXTI_pvoidfUserFunctionINT2)(VOID)=NULL_POINTER;

void MEXTI_voidInit(u8 ARG_u8InterruptNo,u8 ARG_u8InterruptMode)
{
	switch(ARG_u8InterruptNo)
	{
		case MEXTI_INT0:
		{
			switch(ARG_u8InterruptMode)
			{case EXTI_MODE_LOW:
				{
					CLEAR_BIT(MCUCR,ISC01);
					CLEAR_BIT(MCUCR,ISC00);
					break;
				}
				case EXTI_MODE_IOC:
				{
					CLEAR_BIT(MCUCR,ISC01);
					SET_BIT(MCUCR,ISC00);
					break;
				}
				case EXTI_MODE_FALLIING:
				{
					SET_BIT(MCUCR,ISC01);
					CLEAR_BIT(MCUCR,ISC00);
					break;
				}
				case EXTI_MODE_LOW:
				{
					SET_BIT(MCUCR,ISC01);
					SET_BIT(MCUCR,ISC00);
					break;
				}
				default: reak;  //report an error
			}
			break;
			
	}
	case MEXTI_INT1:
		switch(ARG_u8InterruptNo)
		{
			switch(ARG_u8InterruptMode)
			{
			    case EXTI_MODE_LOW:
				{
					CLEAR_BIT(MCUCR,ISC11);
					CLEAR_BIT(MCUCR,ISC10);
					break;
				}
				case EXTI_MODE_IOC:
				{
					CLEAR_BIT(MCUCR,ISC11);
					SET_BIT(MCUCR,ISC10);
					break;
				}
				case EXTI_MODE_FALLIING:
				{
					SET_BIT(MCUCR,ISC11);
					CLEAR_BIT(MCUCR,ISC10);
					break;
				}
				case EXTI_MODE_LOW:
				{
					SET_BIT(MCUCR,ISC11);
					SET_BIT(MCUCR,ISC10);
					break;
				}
				default: reak;  //report an error
			}
			break;
			
	}
	case MEXTI_INT2:
	switch(ARG_u8InterruptMode)
	case EXTI_MODE_FALLIING:
				{
					CLEAR_BIT(MCUCSR,ISC2);
					break;
				}
				case EXTI_MODE_LOW:
				{
					SET_BIT(MCUCSR,ISC2);
					break;
				}
				default: reak;  //report an error
			}
			break;
	
	
}
void MEXTI_voidEnableInterrupt(u8 ARG_u8InterruptNo)
{
	if(ARG_u8InterruptNo>=5 && ARG_u8InterruptNo<=7)
	{
		SET_BIT(GICR,ARG_u8InterruptNo);
	}
	else
	{
		//report an error
	}
}
void MEXTI_voidDisableInterrupt(u8 ARG_u8InterruptNo)
{
	if(ARG_u8InterruptNo>=5 && ARG_u8InterruptNo<=7)
	{
		CLEAR_BIT(GICR,ARG_u8InterruptNo);
	}
	else
	{
		//report an error
	}
}
void MEXTI_voidSetCallback(void(*ARG_pvoidfUserFunction)(void),u8 ARG_u8InterruptNo)
{
	if(ARG_pvoidfUserFunction!=NULL_POINTER)
	{
		switch(ARG_u8InterruptNo)
		{
		case MEXTI_INT0 MEXTI_INT0: MEXTI_pvoidfUserFunctionINT0=ARG_pvoidfUserFunction;break;
		case MEXTI_INT1 MEXTI_INT1: MEXTI_pvoidfUserFunctionINT1=ARG_pvoidfUserFunction;break;
		case MEXTI_INT2 MEXTI_INT2: MEXTI_pvoidfUserFunctionINT2=ARG_pvoidfUserFunction;break;
		default: break; //report an error
		}
	}
	else
	{
		//report an error
	}
}
void __vector_1(void)__attribute((signal));
void __vector_1(void)
{
	if(MEXTI_pvoidfUserFunctionINT0!=NULL_POINTER)
	{
		(*MEXTI_pvoidfUserFunctionINT0)();
	}
	else
	{
		//do nothing
	}
}
void __vector_2(void)__attribute((signal));
void __vector_2(void)
{
	if(MEXTI_pvoidfUserFunctionINT1!=NULL_POINTER)
	{
		(*MEXTI_pvoidfUserFunctionINT1)();
	}
	else
	{
		//do nothing
	}
}

void __vector_3(void)__attribute((signal));
void __vector_3(void)
{
	if(MEXTI_pvoidfUserFunctionINT2!=NULL_POINTER)
	{
		(*MEXTI_pvoidfUserFunctionINT2)();
	}
	else
	{
		//do nothing
	}
}