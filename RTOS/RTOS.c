#include"RTOS.h"

Task  SystemTasks[4]  = {{0}} ;




void RTOS_StartOS ( void (*AP_CallBack) (void)  )
{
	Timers_VidTimer0SetCallBack (AP_CallBack ) ;
	Timers_VidTimer0Init();

}



void RTOS_CreateTask(  void (*AP_CallBack) (void)  , u16 A_Periodecity , u8 A_Priority  )
{
	SystemTasks[A_Priority].TaskPeriodecity = A_Periodecity ;
	SystemTasks[A_Priority].P_TaskAction = AP_CallBack ;
}



void Scheduler ( void )  // 1000
{
	static u16 Counter = 0 ;
	Counter++ ;
	for ( u8 i = 0 ; i < 4 ; i++ )
	{
		if ( Counter %  SystemTasks[i].TaskPeriodecity  == 0 )
		{
			SystemTasks[i].P_TaskAction() ;
		}
	}
	if ( Counter == 63000 )
		Counter = 0 ;
}
