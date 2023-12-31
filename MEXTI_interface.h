/************************************/
/* Author		: Ali Azzouz		*/
/* SWC			: MEXTI				*/
/* Layer		: MCAL			    */
/* Version		: 1.0				*/
/* Date			: December 22,2023	*/
/* Last Edit	: N/A			 	*/
/************************************/
#ifndef _MEXTI_INTERFACE_H_
#define_MEXTI_INTERFACE_H_
#define MEXTI_INT0 6
#define MEXTI_INT1 7
#define MEXTI_INT2 5

#define MEXTI_MODE_LOW      0
#define MEXTI_MODE_IOC      1
#define MEXTI_MODE_FALLING  2
#define MEXTI_MODE_RISING	3

#define MEXTI_MODE_
void MEXTI_voidInit(u8 ARG_u8InterruptNo,u8 ARG_u8InterruptMode);
void MEXTI_voidEnableInterrupt(u8 ARG_u8InterruptNo);
void MEXTI_voidDisableInterrupt(u8 ARG_u8InterruptNo);
void MEXTI_voidSetCallback(void(*ARG_pvoidfUserFunction)(void),u8 ARG_u8InterruptNo);
#endif