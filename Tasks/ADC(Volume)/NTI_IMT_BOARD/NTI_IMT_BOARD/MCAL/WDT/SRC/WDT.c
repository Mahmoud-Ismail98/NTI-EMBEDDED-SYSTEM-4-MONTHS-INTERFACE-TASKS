/*
 * WDT.c
 *
 * Created: 10/27/2023 1:27:06 PM
 *  Author: Mahmoud Tariq
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "CLCK.h"

#include "PORT.h"
#include "DIO.h"

#include "WDT.h"
#include "WDT_CFG.h"
#include "WDT_PRIVATE.h"


void WDT_vidInit(void){
	
	SET_BIT(WDTCR,WDTCR_WDE);   //SETTING WATCH DOG ENABLE BIT
	CLR_BIT(WDTCR,WDTCR_WDTOE); //CLEARING WATCH DOG TURN OFF ENABLE BIT
	
#if (1 == WDT_16K_CYCLES)
	CLR_BIT(WDTCR,WDTCR_WDP2);
	CLR_BIT(WDTCR,WDTCR_WDP1);
	CLR_BIT(WDTCR,WDTCR_WDP0);
	
#elif (1 == WDT_32K_CYCLES)
	CLR_BIT(WDTCR,WDTCR_WDP2);
	CLR_BIT(WDTCR,WDTCR_WDP1);
	SET_BIT(WDTCR,WDTCR_WDP0);
	
#elif (1 == WDT_64K_CYCLES)
	CLR_BIT(WDTCR,WDTCR_WDP2);
	SET_BIT(WDTCR,WDTCR_WDP1);
	CLR_BIT(WDTCR,WDTCR_WDP0);
	
#elif (1 == WDT_128K_CYCLES)
	CLR_BIT(WDTCR,WDTCR_WDP2);
	SET_BIT(WDTCR,WDTCR_WDP1);
	SET_BIT(WDTCR,WDTCR_WDP0);
	
#elif (1 == WDT_256K_CYCLES)
	SET_BIT(WDTCR,WDTCR_WDP2);
	CLR_BIT(WDTCR,WDTCR_WDP1);
	CLR_BIT(WDTCR,WDTCR_WDP0);
	
#elif (1 == WDT_512K_CYCLES)
	SET_BIT(WDTCR,WDTCR_WDP2);
	CLR_BIT(WDTCR,WDTCR_WDP1);
	SET_BIT(WDTCR,WDTCR_WDP0);
	
#elif (1 == WDT_1024K_CYCLES)
	SET_BIT(WDTCR,WDTCR_WDP2);
	SET_BIT(WDTCR,WDTCR_WDP1);
	CLR_BIT(WDTCR,WDTCR_WDP0);
	
#elif (1 == WDT_2048K_CYCLES)
	SET_BIT(WDTCR,WDTCR_WDP2);
	SET_BIT(WDTCR,WDTCR_WDP1);
	SET_BIT(WDTCR,WDTCR_WDP0);
	
#endif

	
	
}


void WDT_vidDeInit(void){
	CLR_BIT(WDTCR,WDTCR_WDE);   //CLEARING WATCH DOG ENABLE BIT
	SET_BIT(WDTCR,WDTCR_WDTOE); //SETTING WATCH DOG TURN OFF ENABLE BIT
	
}