#include <avr/io.h>
#include"Timers.h"
#include"DIO.h"
#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include "RTOS.h"



void LED1 (void)
{
	DIO_VidTogglePinValue(DIO_PORTA,DIO_PIN0);
}

void LED2 (void)
{
	DIO_VidTogglePinValue(DIO_PORTC,DIO_PIN0);
}

void LED3 (void)
{
	DIO_VidTogglePinValue(DIO_PORTD,DIO_PIN0);
}


int main (void)
{
	DIO_VidSetPinDirection(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);
	DIO_VidSetPinValue(DIO_PORTA,DIO_PIN0,DIO_HIGH);//LED 1

	DIO_VidSetPinDirection(DIO_PORTC,DIO_PIN0,DIO_OUTPUT);
	DIO_VidSetPinValue(DIO_PORTC,DIO_PIN0,DIO_HIGH);//LED 2

	DIO_VidSetPinDirection(DIO_PORTD,DIO_PIN0,DIO_OUTPUT);
	DIO_VidSetPinValue(DIO_PORTD,DIO_PIN0,DIO_HIGH);//LED 3

	RTOS_CreateTask( LED1 , 1000 , 0  ) ;
	RTOS_CreateTask( LED2 , 2000 , 1  ) ;
	RTOS_CreateTask( LED3 , 2400 , 2  ) ;

	RTOS_StartOS ( Scheduler ) ;
	while (1)
	{

	}
}


///* ISR */
//void __vector_10 (void)  __attribute__((signal)) ;
//void __vector_10 (void)
//{
//	GP_CallBack() ;  // scheduler
//}
