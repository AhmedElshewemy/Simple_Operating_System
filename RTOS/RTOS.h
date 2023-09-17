/*
 * RTOS.h
 *
 *  Created on: Sep 2, 2023
 *      Author: btc
 */

#ifndef RTOS_H_
#define RTOS_H_

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"Timers.h"

typedef struct
{
	u16 TaskPeriodecity ;
	void (*P_TaskAction) (void) ;
}Task;

void RTOS_StartOS ( void (*AP_CallBack) (void)  );
void RTOS_CreateTask(  void (*AP_CallBack) (void)  , u16 A_Periodecity , u8 A_Priority  );
void Scheduler ( void ) ; // 1000



#endif /* RTOS_H_ */
