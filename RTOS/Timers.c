#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"Timers.h"
#include"avr/io.h"
#include"avr/interrupt.h"


void (*Timer0_PFun)(void);


void Timers_VidTimer0SetCallBack( void (*Timer0_Ptr)(void) )
{
	Timer0_PFun = Timer0_Ptr ;
}

void Timers_VidTimer0Init(void)
{
	/*Select the MODE*/
	/*Normal Mode*/
	//CLR_BIT( TCCR0 , WGM00 );
	//CLR_BIT( TCCR0 , WGM01 );
	/*CTC Mode*/
	CLR_BIT( TCCR0 , WGM00 );
	SET_BIT( TCCR0 , WGM01 );

	/*Enable the Interrupt*/
	/*GIE*/
	SET_BIT( SREG , 7 );
	/*PIE -- > OVF */
	//SET_BIT( TIMSK , TOIE0 );
	/*PIE -- > CTC */
	SET_BIT( TIMSK , OCIE0 );

	/* setup the preload value*/
	//TCNT0 = 192 ;

	/*Setup the OCR Value*/
	OCR0 = 125 ;

	/*Select Prescaler factor*/
	/*/8 */
//	CLR_BIT( TCCR0 , CS00 );
//	SET_BIT( TCCR0 , CS01 );
//	CLR_BIT( TCCR0 , CS02 );



	/*Select Prescaler factor*/
		/*/64 */
	SET_BIT(TCCR0, CS00);
	SET_BIT(TCCR0, CS01);
	CLR_BIT(TCCR0, CS02);
}





//ISR(TIMER0_OVF_vect)
//{
//	static u16 Local_U16CounterOVF = 0 ;
//	Local_U16CounterOVF++ ;
//	if( Local_U16CounterOVF == 3907 )
//	{
//		Local_U16CounterOVF = 0 ;
//		TCNT0 = 192 ;
//
//		Timer0_PFun();
//	}
//
//}



ISR(TIMER0_COMP_vect)
{
	Timer0_PFun();

}


