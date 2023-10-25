﻿#include "../../services/Bit_utils.h"
#include "../../services/Std_types.h"
#include "../../MCAL/PORT/include/port_private.h"
#include "../../MCAL/DIO/include/DIO.h"
#include "../../MCAL/PORT/include/port.h"
#include "../../HAL/7_segment/seven_segment.h"
#include <stdlib.h>
#include <stdio.h>
#include<util/delay.h>



	
int main(void)
{
	
init_four_sev_Seg();
Port_SetPinMode(PORTC_PIN0,PIN_IN_PULLUP);
while(1)
{	
	u8 read_value=1;
	
	while (read_value==1)
	{
	  DIO_READ_PIN(PORTC_PIN0,&read_value);
	}
	Sev_SegmentCounter_up(0);
}
}

