/*
 * CFile1.c
 *
 * Created: 10/21/2023 1:14:38 AM
 *  Author: ahmed radwan
 */ 
// .h format
/*************************macros section***********************************/


/************************* macros section end ***********************************/


/*********************************** user defined data types section ***********************************/


/*********************************** user defined data types section end ***********************************/



/*****************function prototypes section*******************************************/


/*****************function prototypes section end*******************************************/




// this contain all tests copy  the required section and un define it define


/*********************************************port & dio drivers test ****************************************************/

// #define F_CPU 16000000UL
// #include <avr/io.h>
// #include <util/delay.h>
// #include "SERVICES/Standard_Data_Types.h"
// #include "SERVICES/Bit_Wise_Operations.h"
// #include "MCAL/PORT/PORT.h"
// #include "MCAL/DIO/DIO.h"
// 
// int main(void)
// {
// 	volatile u8 debug1=0;
// 	volatile u8 debug2=0;
// 	/* Replace with your application code */
// 	Port_vidInit();
// 	Dio_enuWriteChannel(10,DIO_PIN_HIGH);
// 	Dio_enuFlipChannel(10);
// 	Dio_enuWritePort(1,0xff);
// 	Dio_enuWritePort(1,0x00);
// 	_delay_ms(3000);
// 	while (1)
// 	{
// 		debug1++;
// 		for(u8 i=0;i<=31;i++)
// 		{
// 			Dio_enuWriteChannel(i,DIO_PIN_HIGH);
// 			_delay_ms(500);
// 		}
// 		debug1++;
// 		for(u8 i=0;i<31;i++)
// 		{
// 			Dio_enuFlipChannel(i);
// 		_delay_ms(500);		}
// 		debug1++;
// 		for(u8 i=0;i<=3;i++)
// 		{
// 			Dio_enuWritePort(i,0xff);
// 			_delay_ms(1000);
// 		}
// 		debug1++;
// 		for(u8 i=0;i<=3;i++)
// 		{
// 			Dio_enuWritePort(i,0x0f);
// 			_delay_ms(1000);
// 		}
// 		Dio_enuReadChannel(DIO_D7_ID_31,&debug1);
// 		Dio_enuReadPort(2,&debug2);
// 
// 		
// 	}
// }
// 
/*********************************************port & dio drivers test end ****************************************************/

/*********************************************push button drivers test ****************************************************/

/*
 * AVR_DRIVERS.c
 *
 * Created: 10/20/2023 8:33:11 PM
 * Author : ahmed radwan
 */ 
// #define F_CPU 16000000UL
// #include <avr/io.h>
// #include <util/delay.h>
// #include "SERVICES/Standard_Data_Types.h"
// #include "SERVICES/Bit_Wise_Operations.h"
// #include "MCAL/PORT/PORT.h"
// #include "MCAL/DIO/DIO.h"
// #include "HAL/BUTTON/BUTTON.h"
// #include "HAL/7_SEGMENT/7_SEGMENT.h"
// 
// 
// int main(void)
// {
// 	 volatile u8 debug1=0;
// 	 volatile u8 debug2=0;
// 	Button_tst button1={.button_pin_id=DIO_B2_ID_10,.conection=BUTTON_PULL_DOWN};
// 	Button_tst button2={.button_pin_id=DIO_C4_ID_20,.conection=BUTTON_PULL_UP};
//     /* Replace with your application code */
// 	Port_vidInit();
// 	Button_enuInit(&button1);
// 	Button_enuInit(&button2);
// 
//     while (1) 
//     {   
// 			Button_enuRead(&button1,&debug1);
// 			Button_enuRead(&button2,&debug2);
// 			_delay_ms(500);
//     }
// }

/*********************************************push button drivers test end ****************************************************/



/*********************************************seven segment drivers test ****************************************************/


/*
 * AVR_DRIVERS.c
 *
 * Created: 10/20/2023 8:33:11 PM
 * Author : ahmed radwan
 */ 
// #define F_CPU 16000000UL
// #include <avr/io.h>
// #include <util/delay.h>
// #include "SERVICES/Standard_Data_Types.h"
// #include "SERVICES/Bit_Wise_Operations.h"
// #include "MCAL/PORT/PORT.h"
// #include "MCAL/DIO/DIO.h"
// #include "HAL/BUTTON/BUTTON.h"
// #include "HAL/7_SEGMENT/7_SEGMENT.h"
// 
// Button_tst button1={.button_pin_id=DIO_B2_ID_10,.conection=BUTTON_PULL_DOWN};
// Button_tst button2={.button_pin_id=DIO_C4_ID_20,.conection=BUTTON_PULL_UP};
// SevenSegment_tst display1={.Segment_PIN1=DIO_D1_ID_25,
// 						   .Segment_PIN2=DIO_D2_ID_26,
// 						   .Segment_PIN3=DIO_D3_ID_27,
// 						   .Segment_PIN4=DIO_D4_ID_28};
// int main(void)
// {  
// 	u8 debug1=0;
// 
//     /* Replace with your application code */
// 	Port_vidInit();
// 	Button_enuInit(&button1);
// 	Button_enuInit(&button2);
// 	SevenSegment_INIT(&display1);
// 
//     while (1) 
//     {   
// 			SevenSegment_write(&display1,debug1++);
// 			_delay_ms(500);
//     }
// }



/*********************************************seven segment drivers test end ****************************************************/





/*********************************************seven segment  counter test ****************************************************/




/*
 * AVR_DRIVERS.c
 *
 * Created: 10/20/2023 8:33:11 PM
 * Author : ahmed radwan
//  */ 
// #define F_CPU 16000000UL
// #include <avr/io.h>
// #include <util/delay.h>
// #include "SERVICES/Standard_Data_Types.h"
// #include "SERVICES/Bit_Wise_Operations.h"
// #include "MCAL/PORT/PORT.h"
// #include "MCAL/DIO/DIO.h"
// #include "HAL/BUTTON/BUTTON.h"
// #include "HAL/7_SEGMENT/7_SEGMENT.h"
// u8 display_value1=0;
// u8 display_value2=0;
// u8 display_value3=0;
// u8 display_value4=0;
// Button_tst button1={.button_pin_id=DIO_B2_ID_10,.conection=BUTTON_PULL_DOWN};
// Button_tst button2={.button_pin_id=DIO_C4_ID_20,.conection=BUTTON_PULL_UP};
// SevenSegment_tst display1={.Segment_PIN1=DIO_C0_ID_16,
// 						   .Segment_PIN2=DIO_C1_ID_17,
// 						   .Segment_PIN3=DIO_C2_ID_18,
// 						   .Segment_PIN4=DIO_C3_ID_19};
// 
// 
// 
// SevenSegment4pins_tst active_pins={.Segment1_active=DIO_D0_ID_24,
// 								   .Segment2_active=DIO_D1_ID_25,
// 								   .Segment3_active=DIO_D2_ID_26,
// 								   .Segment4_active=DIO_D3_ID_27};
// int main(void)
// {  
// 	u8 debug1=0;
// 
//     /* Replace with your application code */
// 	Port_vidInit();
// 	//Button_enuInit(&button1);
// 	//Button_enuInit(&button2);
// 	SevenSegment_INIT(&display1);
// 
//     while (1) 
//     {   
// 		for(display_value4=0;display_value4<=9;display_value4++)
// 		{
// 			for(display_value3=0;display_value4<=9;display_value4++)
// 			{
// 				for(display_value1=0;display_value4<=9;display_value4++)
// 				{
// 					for(display_value1=0;display_value4<=9;display_value4++)
// 					{
// 						SevenSegment_Swaper();
// 						_delay_ms(500);
// 					}
// 				}
// 			}
// 		}
// 		display_value1=0;
// 		display_value2=0;
// 		display_value3=0;
// 		display_value4=0;
// 		
//     }
// }
// 
// void SevenSegment_Swaper(void){
// 	    SevenSegment_write(&display1,display_value1);
// 		Dio_enuWriteChannel(active_pins.Segment1_active,1);
// 		Dio_enuWriteChannel(active_pins.Segment2_active,0);
// 		Dio_enuWriteChannel(active_pins.Segment3_active,0);
// 		Dio_enuWriteChannel(active_pins.Segment4_active,0);
// 		_delay_ms(20);
// 		
// 		SevenSegment_write(&display1,display_value2);
// 		Dio_enuWriteChannel(active_pins.Segment1_active,0);
// 		Dio_enuWriteChannel(active_pins.Segment2_active,1);
// 		Dio_enuWriteChannel(active_pins.Segment3_active,0);
// 		Dio_enuWriteChannel(active_pins.Segment4_active,0);
// 		_delay_ms(20);
// 		
// 		SevenSegment_write(&display1,display_value3);
// 		Dio_enuWriteChannel(active_pins.Segment1_active,0);
// 		Dio_enuWriteChannel(active_pins.Segment2_active,0);
// 		Dio_enuWriteChannel(active_pins.Segment3_active,1);
// 		Dio_enuWriteChannel(active_pins.Segment4_active,0);
// 		_delay_ms(20);
// 		
// 		SevenSegment_write(&display1,display_value4);
// 		Dio_enuWriteChannel(active_pins.Segment1_active,0);
// 		Dio_enuWriteChannel(active_pins.Segment2_active,0);
// 		Dio_enuWriteChannel(active_pins.Segment3_active,0);
// 		Dio_enuWriteChannel(active_pins.Segment4_active,1);
// 		_delay_ms(20);
// 
// }
/*********************************************seven segment  counter test end ****************************************************/


/*********************************************seven segment  stop watch ****************************************************/
/*
 * AVR_DRIVERS.c
 *
 * Created: 10/20/2023 8:33:11 PM
 * Author : ahmed radwan
 */ 
// 
// #define F_CPU 16000000UL
// #include <avr/io.h>
// #include <util/delay.h>
// #include "SERVICES/Standard_Data_Types.h"
// #include "SERVICES/Bit_Wise_Operations.h"
// #include "MCAL/PORT/PORT.h"
// #include "MCAL/DIO/DIO.h"
// #include "HAL/BUTTON/BUTTON.h"
// #include "HAL/7_SEGMENT/7_SEGMENT.h"
// 
// 
// 
// void SevenSegment_Swaper(void);
// void SevenSegment_counter(void);
// 
// 
// 
// u8 display_value1=0;
// u8 display_value2=2;
// u8 display_value3=3;
// u8 display_value4=4;
// 
// Button_tst button_start={.button_pin_id=DIO_A0_ID_0,.conection=BUTTON_PULL_DOWN};
// Button_tst button_stop={.button_pin_id=DIO_A1_ID_1,.conection=BUTTON_PULL_DOWN};
// Button_tst button_clear={.button_pin_id=DIO_A2_ID_2,.conection=BUTTON_PULL_DOWN};
// 
// Button_tenuState button_start_status=BUTTON_NOT_PRESSED;
// Button_tenuState button_stop_status=BUTTON_NOT_PRESSED;
// Button_tenuState button_clear_status=BUTTON_NOT_PRESSED;
// 
// SevenSegment_tst display1={.Segment_PIN1=DIO_C0_ID_16,
// 						   .Segment_PIN2=DIO_C1_ID_17,
// 						   .Segment_PIN3=DIO_C2_ID_18,
// 						   .Segment_PIN4=DIO_C3_ID_19};
// 
// 
// 
// SevenSegment4pins_tst active_pins={.Segment1_active=DIO_D0_ID_24,
// 								   .Segment2_active=DIO_D1_ID_25,
// 								   .Segment3_active=DIO_D2_ID_26,
// 								   .Segment4_active=DIO_D3_ID_27};
// int main(void)
// {  
// 
//     /* Replace with your application code */
// 	Port_vidInit();
// 	Button_enuInit(&button_start);
// 	Button_enuInit(&button_stop);
// 	Button_enuInit(&button_clear);
// 	SevenSegment_INIT(&display1);
// 
//     while (1) 
//     {   
// 		Button_enuRead(&button_start,&button_start_status);
// 		Button_enuRead(&button_stop,&button_stop_status);
// 		Button_enuRead(&button_clear,&button_clear_status);
// 		if(button_start_status==BUTTON_NOT_PRESSED&&button_stop_status==BUTTON_NOT_PRESSED)
// 		{
// 				SevenSegment_counter();
// 		}
// 		if(button_clear_status==BUTTON_NOT_PRESSED&&button_stop_status==BUTTON_NOT_PRESSED)
// 		{
// 				SevenSegment_counter();
// 		}
//     }
// }
// 
// void SevenSegment_Swaper(void){
// 	    SevenSegment_write(&display1,display_value1);
// 		Dio_enuWriteChannel(active_pins.Segment1_active,1);
// 		Dio_enuWriteChannel(active_pins.Segment2_active,0);
// 		Dio_enuWriteChannel(active_pins.Segment3_active,0);
// 		Dio_enuWriteChannel(active_pins.Segment4_active,0);
// 		_delay_ms(20);
// 		
// 		SevenSegment_write(&display1,display_value2);
// 		Dio_enuWriteChannel(active_pins.Segment1_active,0);
// 		Dio_enuWriteChannel(active_pins.Segment2_active,1);
// 		Dio_enuWriteChannel(active_pins.Segment3_active,0);
// 		Dio_enuWriteChannel(active_pins.Segment4_active,0);
// 		_delay_ms(20);
// 		
// 		SevenSegment_write(&display1,display_value3);
// 		Dio_enuWriteChannel(active_pins.Segment1_active,0);
// 		Dio_enuWriteChannel(active_pins.Segment2_active,0);
// 		Dio_enuWriteChannel(active_pins.Segment3_active,1);
// 		Dio_enuWriteChannel(active_pins.Segment4_active,0);
// 		_delay_ms(20);
// 		
// 		SevenSegment_write(&display1,display_value4);
// 		Dio_enuWriteChannel(active_pins.Segment1_active,0);
// 		Dio_enuWriteChannel(active_pins.Segment2_active,0);
// 		Dio_enuWriteChannel(active_pins.Segment3_active,0);
// 		Dio_enuWriteChannel(active_pins.Segment4_active,1);
// 		_delay_ms(20);
// 
// }
// void SevenSegment_counter(void){
// 			for(display_value4=0;display_value4<=9;display_value4++)
// 			{
// 				for(display_value3=0;display_value3<=9;display_value3++)
// 				{
// 					for(display_value2=0;display_value2<=9;display_value2++)
// 					{
// 						for(display_value1=0;display_value1<=9;display_value1++)
// 						{
// 							SevenSegment_Swaper();
// 							_delay_ms(50);
// 							SevenSegment_Swaper();
// 							_delay_ms(50);
// 							SevenSegment_Swaper();
// 							_delay_ms(50);
// 							SevenSegment_Swaper();
// 							_delay_ms(50);
// 							SevenSegment_Swaper();
// 							_delay_ms(50);
// 							SevenSegment_Swaper();
// 							_delay_ms(50);
// 							SevenSegment_Swaper();
// 							_delay_ms(50);
// 							SevenSegment_Swaper();
// 							_delay_ms(50);
// 							SevenSegment_Swaper();
// 							_delay_ms(50);
// 							SevenSegment_Swaper();
// 							_delay_ms(50);
// 						}
// 					}
// 				}
// 			}
// 			display_value1=0;
// 			display_value2=0;
// 			display_value3=0;
// 			display_value4=0;
// 
// }
/*********************************************seven segment  stop watch end ****************************************************/


/****************************************** lcd 8 bit mode test *******************************************/
/*
 * AVR_DRIVERS.c
 *
 * Created: 10/20/2023 8:33:11 PM
 * Author : ahmed radwan
 */ 
// #define F_CPU 16000000UL
// #include <avr/io.h>
// #include <util/delay.h>
// #include "SERVICES/Standard_Data_Types.h"
// #include "SERVICES/Bit_Wise_Operations.h"
// #include "MCAL/PORT/PORT.h"
// #include "MCAL/DIO/DIO.h"
// #include "HAL/BUTTON/BUTTON.h"
// #include "HAL/7_SEGMENT/7_SEGMENT.h"
// #include "HAL/LCD/LCD.h"
// u8 hamada[] = {
// 	0b01110,
// 	0b01010,
// 	0b01110,
// 	0b00100,
// 	0b11111,
// 	0b10101,
// 	0b01010,
// 	0b11011
// };
// 
// LCD_8BIT_ST lcd={.lcd_pins[0]=PIN_B0_ID_8,
// 				 .lcd_pins[1]=PIN_B1_ID_9,
// 				 .lcd_pins[2]=PIN_B2_ID_10,
// 				 .lcd_pins[3]=PIN_B3_ID_11,
// 				 .lcd_pins[4]=PIN_B4_ID_12,
// 				 .lcd_pins[5]=PIN_B5_ID_13,
// 				 .lcd_pins[6]=PIN_B6_ID_14,
// 				 .lcd_pins[7]=PIN_B7_ID_15,
// 				 .lcd_pin_rs=PIN_A6_ID_6,
// 				 .lcd_pin_e=PIN_A7_ID_7};
// int main(void)
// {  
// 	Port_vidInit();
// 	LCD_vidInit_8bit(&lcd);
// 	
// 	LCD_vidDisplayChar_8bit(&lcd,'a');
// 	LCD_vidDisplayNumber_8bit(&lcd,1234);
// 	LCD_vidDisplayString_8bit(&lcd,"msamsa");
// 	LCD_vidGotoXY_8bit(&lcd,2,0);
// 	LCD_vidDisplayString_8bit(&lcd,"msamsa");
// 	LCD_vidDisplayString_8bit(&lcd,"msamsa");
// 	LCD_vidGotoXY_8bit(&lcd,3,0);
// 	LCD_vidDisplayString_8bit(&lcd,"msamsa");
// 	LCD_vidDisplayString_8bit(&lcd,"msamsa");
// 	LCD_vidGotoXY_8bit(&lcd,4,0);
// 	LCD_vidDisplayString_8bit(&lcd,"msamsa");
// 	LCD_vidDisplayString_8bit(&lcd,"msamsa");
// 	LCD_vidCraetCustomChar_8bit(&lcd,hamada,1);
// 	LCD_vidDisplayChar_8bit(&lcd,1);
// 	LCD_vidGotoXY_8bit(&lcd,2,0);
// 	LCD_vidDisplayChar_8bit(&lcd,'*');
// 
//     while (1) 
//     {   
// 
//     }
// }
// 

/****************************************** lcd 8 bit mode test end *******************************************/



/****************************************** lcd 4 bit mode test *******************************************/


/*
 * AVR_DRIVERS.c
 *
 * Created: 10/20/2023 8:33:11 PM
 * Author : ahmed radwan
 */ 
// #define F_CPU 16000000UL
// #include <avr/io.h>
// #include <util/delay.h>
// #include "SERVICES/Standard_Data_Types.h"
// #include "SERVICES/Bit_Wise_Operations.h"
// #include "MCAL/PORT/PORT.h"
// #include "MCAL/DIO/DIO.h"
// #include "HAL/BUTTON/BUTTON.h"
// #include "HAL/7_SEGMENT/7_SEGMENT.h"
// #include "HAL/LCD/LCD.h"
// u8 hamada[] = {
// 	0b01110,
// 	0b01010,
// 	0b01110,
// 	0b00100,
// 	0b11111,
// 	0b10101,
// 	0b01010,
// 	0b11011
// };
// 
// LCD_4BIT_ST lcd={.lcd_pins[0]=PIN_B0_ID_8,
// 				 .lcd_pins[1]=PIN_B1_ID_9,
// 				 .lcd_pins[2]=PIN_B2_ID_10,
// 				 .lcd_pins[3]=PIN_B4_ID_12,
// 				 .lcd_pin_rs=PIN_A3_ID_3,
// 				 .lcd_pin_e=PIN_A2_ID_2};
// int main(void)
// {  
// 	Port_vidInit();
// 	LCD_vidInit_4bit(&lcd);
// 	
// 	LCD_vidDisplayChar_4bit(&lcd,'a');
// 	LCD_vidDisplayNumber_4bit(&lcd,1234);
// 	LCD_vidDisplayString_4bit(&lcd,"msamsa");
// 	LCD_vidGotoXY_4bit(&lcd,2,0);
// 	LCD_vidDisplayString_4bit(&lcd,"msamsa");
// 	LCD_vidDisplayString_4bit(&lcd,"msamsa");
// 	LCD_vidGotoXY_4bit(&lcd,3,0);
// 	LCD_vidDisplayString_4bit(&lcd,"msamsa");
// 	LCD_vidDisplayString_4bit(&lcd,"msamsa");
// 	LCD_vidGotoXY_4bit(&lcd,4,0);
// 	LCD_vidDisplayString_4bit(&lcd,"msamsa");
// 	LCD_vidDisplayString_4bit(&lcd,"msamsa");
// 	LCD_vidCraetCustomChar_4bit(&lcd,hamada,1);
// 	LCD_vidDisplayChar_4bit(&lcd,1);
// 	LCD_vidGotoXY_4bit(&lcd,2,0);
// 	LCD_vidDisplayChar_4bit(&lcd,'*');
// 
//     while (1) 
//     {   
// 
//     }
// }
// 



/****************************************** lcd 4 bit mode test end *******************************************/


/***************************************** GIE TEST ******************************************/
/*
 * AVR_DRIVERS.c
 *
 * Created: 10/20/2023 8:33:11 PM
 * Author : ahmed radwan
 */ 
// #define F_CPU 16000000UL
// #include <avr/io.h>
// #include <util/delay.h>
// #include "SERVICES/Standard_Data_Types.h"
// #include "SERVICES/Bit_Wise_Operations.h"
// #include "MCAL/PORT/PORT.h"
// #include "MCAL/DIO/DIO.h"
// #include "HAL/BUTTON/BUTTON.h"
// #include "HAL/7_SEGMENT/7_SEGMENT.h"
// #include "HAL/LCD/LCD.h"
// #include "MCAL/GIE/GIE.h"
// u8 test_var=9;
// int main(void)
// {  
// 	Port_vidInit();
// 	LCD_vidInit_4bit(&lcd);
// 
// 	test_var=GIE_Get_Status();
// 	GIE_INIT();
// 	test_var=GIE_Get_Status();
// 	GIE_Disable();
// 	test_var=GIE_Get_Status();
// 	GIE_Enable();
// 	test_var=GIE_Get_Status(); 
// 	++test_var;
//     while (1) 
//     {   
// 		++test_var;
//     }
// }
// 
/***************************************** GIE TEST END ******************************************/



/**draft**/
// #define DELAY_VAL 10
// u8 display_value1=0;
// u8 display_value2=0;
// u8 display_value3=0;
// u8 display_value4=0;
// Button_tst start={.button_pin_id=DIO_D7_ID_31,.conection=BUTTON_PULL_UP};
// Button_tst stop={.button_pin_id=DIO_D6_ID_30,.conection=BUTTON_PULL_UP};
// Button_tst reset={.button_pin_id=DIO_D5_ID_29,.conection=BUTTON_PULL_UP};
// SevenSegment_tst display1={.Segment_PIN1=DIO_B0_ID_8,
// 	.Segment_PIN2=DIO_B1_ID_9,
// 	.Segment_PIN3=DIO_B2_ID_10,
// .Segment_PIN4=DIO_B4_ID_12};
// SevenSegment4pins_tst active_pins={.Segment1_active=DIO_A3_ID_3,
// 	.Segment2_active=DIO_A2_ID_2,
// 	.Segment3_active=DIO_B5_ID_13,
// .Segment4_active=DIO_B6_ID_14};
// int main(void)
// {
// 	u8 debug1=0;
// 
// 	/* Replace with your application code */
// 	Port_vidInit();
// 	//Button_enuInit(&button1);
// 	//Button_enuInit(&button2);
// 	SevenSegment_INIT(&display1);
// 	while (1)
// 	{
// 		
// 		Button_enuRead
// 		SevenSegment_Swaper();
// 
// 	}
// }
// 
// void SevenSegment_Swaper(void){
// 	
// 	Dio_enuWriteChannel(active_pins.Segment3_active,1);
// 	Dio_enuWriteChannel(active_pins.Segment4_active,1);
// 	Dio_enuWriteChannel(active_pins.Segment1_active,0);
// 	_delay_ms(DELAY_VAL);
// 	Dio_enuWriteChannel(active_pins.Segment1_active,1);
// 	Dio_enuWriteChannel(active_pins.Segment3_active,1);
// 	Dio_enuWriteChannel(active_pins.Segment4_active,1);
// 	_delay_ms(DELAY_VAL);
// 
// 	
// 	Dio_enuWriteChannel(active_pins.Segment1_active,1);
// 	Dio_enuWriteChannel(active_pins.Segment2_active,1);
// 	Dio_enuWriteChannel(active_pins.Segment3_active,0);
// 	_delay_ms(DELAY_VAL);
// 
// 	
// 	Dio_enuWriteChannel(active_pins.Segment1_active,1);
// 	Dio_enuWriteChannel(active_pins.Segment2_active,1);
// 	Dio_enuWriteChannel(active_pins.Segment3_active,1);
// 	Dio_enuWriteChannel(active_pins.Segment4_active,0);
// 	_delay_ms(DELAY_VAL);
// }
/***draft end**/

/**/

/*****/

/*****voltameter_task*******/
/*
 * AVR_DRIVERS.c
 *
 * Created: 10/20/2023 8:33:11 PM
 * Author : ahmed radwan
 */ 
// #define F_CPU 16000000UL
// #include <util/delay.h>
// #include "SERVICES/Standard_Data_Types.h"
// #include "SERVICES/Bit_Wise_Operations.h"
// #include "MCAL/PORT/PORT.h"
// #include "MCAL/DIO/DIO.h"
// #include "HAL/BUTTON/BUTTON.h"
// #include "HAL/7_SEGMENT/7_SEGMENT.h"
// #include "HAL/LCD/LCD.h"
// #include "MCAL/GIE/GIE.h"
// #include "MCAL/EXTI/EXTI.h"
// #include "MCAL/ADC/ADC.h"
// 
// u16 test_var=9;
// f32 volt_print=0;
// LCD_4BIT_ST lcd={.lcd_pins[0]=PIN_B0_ID_8,
// 	.lcd_pins[1]=PIN_B1_ID_9,
// 	.lcd_pins[2]=PIN_B2_ID_10,
// 	.lcd_pins[3]=PIN_B4_ID_12,
// 	.lcd_pin_rs=PIN_A3_ID_3,
// .lcd_pin_e=PIN_A2_ID_2};
// 
// int main(void)
// {  
// 	//Port_vidInit();
// 	LCD_vidInit_4bit(&lcd);
// 	GIE_INIT();
// 	EXI_INT(EXTI_INT0,EXTI_MODE_FALING_EDGE,isr);
// 	LCD_vidDisplayString_4bit(&lcd,"VOLT:");
// 	LCD_vidGotoXY_4bit(&lcd,1,6);
// 	
// 	ADC_INIT();
// 	
//     while (1) 
//     {
// 		ADC_GET_CONV_BOOLING(ADC1,&test_var);
// 		volt_print=(f32)test_var*5/1024;
// 		LCD_vidGotoXY_4bit(&lcd,1,5);
// 		if(flag==1)
// 		{
// 			LCD_vidDisplayFloatNumber_4bit(&lcd,volt_print);//v
// 			LCD_vidDisplayString_4bit(&lcd,"v   ");
// 		}
// 		else if(flag==0)
// 		{
// 			LCD_vidDisplayNumber_4bit(&lcd,volt_print*1000);//mv
// 			LCD_vidDisplayString_4bit(&lcd,"mv  ");
// 		}	
// 		else{}
// 				
//     }
// }
/*****/