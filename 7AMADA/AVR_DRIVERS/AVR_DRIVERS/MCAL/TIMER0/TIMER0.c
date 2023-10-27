/*
 * TIMER0.c
 *
 * Created: 10/24/2023 11:18:43 AM
 *  Author: ahmed radwan
 */ 

#include "../../SERVICES/Standard_Data_Types.h"
#include "../../SERVICES/Bit_Wise_Operations.h"
#include "../PORT/PORT.h"
#include "../PORT/PORT_PRIV.h"
#include "TIMER0_PRIV.h"
#include "TIMER0.h"
#include "TIMER0_CFG.h"


static void (*TIMER0_OVERFLOW_CALLBACK)(void);
static void (*TIMER0_COMPARE_MATCH_CALLBACK)(void);

void TIMER0_INT(void)
{
	// SET MODE
	switch(TIMER0_MODE_CFG)
	{
		case NORMAL:
		TIMER0_MODE_SET_NORMAL();
		break;
		case PWM:
		TIMER0_MODE_SET_PWM();
		if(TIMER0_PWM_MODE==NIN_INVERTING)
		{
			PWM_MODE_SET_NININVERTING();
		}
		else if(TIMER0_PWM_MODE==INVERTING)
		{
			PWM_MODE_SET_INVERTING();	
		}
		break;
		case CTC:
		TIMER0_MODE_SET_CTC();
		SET_COMPARE_VALUE(TIMER0_COMPARE_VALUE_CFG);
		Port_enuSetpinDirection(PIN_B3_ID_11,PIN_MODE_OUTPUT);
		break;
		case FASTPWM:
		TIMER0_MODE_SET_PWM_PHASE_CORRECT(); 
		break;
	}
	
	//set prescaller
	SET_PRESCALER(TIMER0_PRESCALER_CFG);
	
	//SET preload
	SET_PRELOAD(TIMER0_PRELOAD_CFG);
	
	// INT OVERFLOW CONFIG
	if(TIMER0_OVERFLOW_INT_CFG==ENABLE)
	{
		TIMER0_CLEAR_OVERFLOW_INT_FLAG();
		TIMER0_OVERFLOW_INT_ENABLE();
	}
	
	//
	if(TIMER0_COMPARE_MODE_INT_CFG==ENABLE)
	{
		TIMER0_CLEAR_COMPARE_MATCH_INT_FLAG();
		TIMER0_COMPARE_MATCH_INT_ENABLE();
	}
	
	
}
void TIMER0_SET_OVRRFLOW_CALLBACK(void(*timer0_overflow_isr)(void))
{
	TIMER0_OVERFLOW_CALLBACK=timer0_overflow_isr;
}
void TIMER0_SET_COMPMATCH_CALLBACK(void(*timer0_compmatch_isr)(void))
{
	TIMER0_COMPARE_MATCH_CALLBACK=timer0_compmatch_isr;
}



void TIMER0_PWM_SET_DUTYCYCLE(u8 duty)
{
	SET_COMPARE_VALUE((duty*(256-TIMER0_PRELOAD_CFG)/100));
}

void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	TIMER0_OVERFLOW_CALLBACK();
}

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	TIMER0_COMPARE_MATCH_CALLBACK();
}