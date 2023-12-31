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
#define MCUCR *((volatile u8*)0x55)
#define ISC11 3
#define ISC10 2
#define ISC01 1
#define ISC00 0
#define MCUCSR *((volatile u8*)0x54)
#define ISC2 6
#define GICR *((volatile u8*)0x5B)
#define INT1 7
#define INT0 6
#define INT2 5
#define GIFR *((volatile u8*)0x5A)
#define INTF1 7
#define INTF0 6
#define INTF2 5
#endif