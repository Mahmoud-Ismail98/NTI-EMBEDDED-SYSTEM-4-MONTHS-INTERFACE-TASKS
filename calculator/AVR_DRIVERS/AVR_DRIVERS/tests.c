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
// #include <util/delay.h>
// #include "SERVICES/Standard_Data_Types.h"
// #include "SERVICES/Bit_Wise_Operations.h"
// #include "MCAL/PORT/PORT.h"
// #include "MCAL/DIO/DIO.h"
// #include "HAL/BUTTON/BUTTON.h"
// #include "HAL/7_SEGMENT/7_SEGMENT.h"
// #include "HAL/LCD/LCD.h"
// #include "MCAL/GIE/GIE.h"
// 
// #define DELAY_POV_VAL 15
// void SevenSegment_Swaper(void);
// 
// u8 display_value1=0;
// u8 display_value2=0;
// u8 display_value3=0;
// u8 display_value4=0;
// Button_tst count_plus={.button_pin_id=DIO_D7_ID_31,.conection=BUTTON_PULL_UP};
// Button_tst count_minus={.button_pin_id=DIO_D6_ID_30,.conection=BUTTON_PULL_UP};
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
// 	Port_vidInit();
// 	Button_enuInit(&count_plus);
// 	Button_enuInit(&count_minus);
// 	Button_enuInit(&reset);
// 	SevenSegment_INIT(&display1);
// 	while (1)
// 	{
// 
// 		Button_enuRead(&count_plus,&count_plus_state);
// 		Button_enuRead(&count_minus,&count_minus_state);
// 		Button_enuRead(&reset,&reset_state);
// 		if(reset_state==BUTTON_PRESSED||counter>=9999)
// 		{
// 			counter=0;
// 			
// 			display_value1=counter%10;
// 			display_value2=(counter/10)%10;
// 			display_value3=(counter/100)%10;
// 			display_value4=(counter/1000)%10;
// 		}
// 		else if(count_minus_state==BUTTON_PRESSED&&counter!=0)
// 		{
// 			counter--;
// 			display_value1=counter%10;
// 			display_value2=(counter/10)%10;
// 			display_value3=(counter/100)%10;
// 			display_value4=(counter/1000)%10;
// 			SevenSegment_Swaper();
// 			_delay_ms(50);
// 		}
// 		else if(count_plus_state==BUTTON_PRESSED)
// 		{
// 			counter++;
// 			display_value1=counter%10;
// 			display_value2=(counter/10)%10;
// 			display_value3=(counter/100)%10;
// 			display_value4=(counter/1000)%10;
// 			SevenSegment_Swaper();
// 			_delay_ms(50);
// 			
// 		}
// 		
// 	}
// }
// 
// void SevenSegment_Swaper(void){
// 	Dio_enuWriteChannel(active_pins.Segment2_active,1);
// 	Dio_enuWriteChannel(active_pins.Segment3_active,1);
// 	Dio_enuWriteChannel(active_pins.Segment4_active,1);
// 	Dio_enuWriteChannel(active_pins.Segment1_active,0);
// 	_delay_ms(DELAY_POV_VAL);
// 	Dio_enuWriteChannel(active_pins.Segment1_active,1);
// 	Dio_enuWriteChannel(active_pins.Segment3_active,1);
// 	Dio_enuWriteChannel(active_pins.Segment4_active,1);
// 	_delay_ms(DELAY_POV_VAL);
// 
// 	Dio_enuWriteChannel(active_pins.Segment1_active,1);
// 	Dio_enuWriteChannel(active_pins.Segment2_active,1);
// 	Dio_enuWriteChannel(active_pins.Segment3_active,0);
// 	_delay_ms(DELAY_POV_VAL);
// 	Dio_enuWriteChannel(active_pins.Segment1_active,1);
// 	Dio_enuWriteChannel(active_pins.Segment2_active,1);
// 	Dio_enuWriteChannel(active_pins.Segment3_active,1);
// 	Dio_enuWriteChannel(active_pins.Segment4_active,0);
// 	_delay_ms(DELAY_POV_VAL);
// }
/*********************************************seven segment  counter test end ****************************************************/


/*********************************************seven segment  stop watch ****************************************************/
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
// 
// #define DELAY_POV_VAL 15
// 
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
// 	Port_vidInit();
// 	Button_enuInit(&start);
// 	Button_enuInit(&stop);
// 	Button_enuInit(&reset);
// 	SevenSegment_INIT(&display1);
// 	while (1)
// 	{
// 
// 		Button_enuRead(&start,&start_state);
// 		Button_enuRead(&stop,&stop_state);
// 		Button_enuRead(&reset,&reset_state);
// 		if(reset_state==BUTTON_PRESSED||counter==9999)
// 		{
// 			counter=0;
// 			stp_watch_flag=0;
// 			display_value1=counter%10;
// 			display_value2=(counter/10)%10;
// 			display_value3=(counter/100)%10;
// 			display_value4=(counter/1000)%10;
// 		}
// 		else if(stop_state==BUTTON_PRESSED)
// 		{
// 			stp_watch_flag=0;
// 			
// 		}
// 		else if(start_state==BUTTON_PRESSED)
// 		{
// 			stp_watch_flag=1;
// 			
// 		}
// 		if(stp_watch_flag)
// 		{
// 			display_value1=counter%10;
// 			display_value2=(counter/10)%10;
// 			display_value3=(counter/100)%10;
// 			display_value4=(counter/1000)%10;
// 			counter++;
// 		}
// 		
// 
// 	}
// }
// 
// void SevenSegment_Swaper(void){
// 	Dio_enuWriteChannel(active_pins.Segment2_active,1);
// 	Dio_enuWriteChannel(active_pins.Segment3_active,1);
// 	Dio_enuWriteChannel(active_pins.Segment4_active,1);
// 	Dio_enuWriteChannel(active_pins.Segment1_active,0);
// 	_delay_ms(DELAY_POV_VAL);
// 	Dio_enuWriteChannel(active_pins.Segment1_active,1);
// 	Dio_enuWriteChannel(active_pins.Segment3_active,1);
// 	Dio_enuWriteChannel(active_pins.Segment4_active,1);
// 	_delay_ms(DELAY_POV_VAL);
// 
// 	Dio_enuWriteChannel(active_pins.Segment1_active,1);
// 	Dio_enuWriteChannel(active_pins.Segment2_active,1);
// 	Dio_enuWriteChannel(active_pins.Segment3_active,0);
// 	_delay_ms(DELAY_POV_VAL);
// 	Dio_enuWriteChannel(active_pins.Segment1_active,1);
// 	Dio_enuWriteChannel(active_pins.Segment2_active,1);
// 	Dio_enuWriteChannel(active_pins.Segment3_active,1);
// 	Dio_enuWriteChannel(active_pins.Segment4_active,0);
// 	_delay_ms(DELAY_POV_VAL);
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




/**************************************** ADC voltameter with EXINT *************************************************/

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
// #include "HAL/LCD/LCD.h"
// #include "MCAL/GIE/GIE.h"
// #include "MCAL/EXTI/EXTI.h"
// #include "MCAL/ADC/ADC.h"
// volatile u8 flag=0;
// void isr(void)
// {
// 	if(flag==0)
// 	{
// 		flag=1;
// 	}
// 	else if(flag==1)
// 	{
// 		flag=0;
// 	}
// }
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
// 	Port_vidInit();
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
///**************************************** ADC voltameter with EXINT end *************************************************/




/**************************************** ADC volume task *************************************************/
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
// u16 ADC_val=9;
// f32 volt_print=0;
// LCD_4BIT_ST lcd={.lcd_pins[0]=PIN_B0_ID_8,
// 	.lcd_pins[1]=PIN_B1_ID_9,
// 	.lcd_pins[2]=PIN_B2_ID_10,
// 	.lcd_pins[3]=PIN_B4_ID_12,
// 	.lcd_pin_rs=PIN_A3_ID_3,
// .lcd_pin_e=PIN_A2_ID_2};
// 
// u8 volume1[] = {
// 	0b00000,
// 	0b00000,
// 	0b00000,
// 	0b00000,
// 	0b00000,
// 	0b11111,
// 	0b11111,
// 	0b11111
// };
// u8 volume2[] = {
// 	0b00000,
// 	0b00000,
// 	0b00000,
// 	0b11111,
// 	0b11111,
// 	0b11111,
// 	0b11111,
// 	0b11111
// };
// u8 volume3[] = {
// 	0b11111,
// 	0b11111,
// 	0b11111,
// 	0b11111,
// 	0b11111,
// 	0b11111,
// 	0b11111,
// 	0b11111
// };
// 
// int main(void)
// {  
// 	LCD_vidInit_4bit(&lcd);
// 	LCD_vidCraetCustomChar_4bit(&lcd,volume1,1);
// 	LCD_vidCraetCustomChar_4bit(&lcd,volume2,2);
// 	LCD_vidCraetCustomChar_4bit(&lcd,volume3,3);
// 	
// 
// 	LCD_vidDisplayString_4bit(&lcd,"VOLUME:");
// 	LCD_vidGotoXY_4bit(&lcd,1,8);
// 	
// 	ADC_INIT();
// 	
//     while (1) 
//     {
// 		ADC_GET_CONV_BOOLING(ADC1,&ADC_val);
// 		 if(ADC_val<100)
// 		{
// 			LCD_vidGotoXY_4bit(&lcd,1,8);
// 			LCD_vidDisplayChar_4bit(&lcd,'X');
// 			LCD_vidDisplayChar_4bit(&lcd,' ');
// 			LCD_vidDisplayChar_4bit(&lcd,' ');
// 
// 		}
// 		else if(ADC_val>100&&ADC_val<400)
// 		{
// 			LCD_vidGotoXY_4bit(&lcd,1,8);
// 			LCD_vidDisplayChar_4bit(&lcd,1);
// 			LCD_vidDisplayChar_4bit(&lcd,' ');
// 			LCD_vidDisplayChar_4bit(&lcd,' ');
// 
// 		}
// 		else if(ADC_val>400&&ADC_val<700)
// 		{
// 			LCD_vidGotoXY_4bit(&lcd,1,8);
// 			LCD_vidDisplayChar_4bit(&lcd,1);
// 			LCD_vidDisplayChar_4bit(&lcd,2);
// 			LCD_vidDisplayChar_4bit(&lcd,' ');
// 		}	
// 		else if(ADC_val>700)
// 		{
// 			LCD_vidGotoXY_4bit(&lcd,1,8);
// 			LCD_vidDisplayChar_4bit(&lcd,1);
// 			LCD_vidDisplayChar_4bit(&lcd,2);
// 			LCD_vidDisplayChar_4bit(&lcd,3);
// 		}
// 		else{}
// 				
//     }
// }
// 
/**************************************** ADC volume task end *************************************************/



/*************************************************** counter lcd EXTI ****************************************/
//#define F_CPU 16000000UL
// #include <util/delay.h>
// #include "SERVICES/Standard_Data_Types.h"
// #include "SERVICES/Bit_Wise_Operations.h"
// #include "MCAL/PORT/PORT.h"
// #include "MCAL/DIO/DIO.h"
// #include "HAL/BUTTON/BUTTON.h"
// #include "HAL/7_SEGMENT/7_SEGMENT.h"
// #include "HAL/LCD/LCD_COMANDS.h"
// #include "HAL/LCD/LCD.h"
// #include "MCAL/GIE/GIE.h"
// #include "MCAL/EXTI/EXTI.h"

// volatile u32 counter=0;
// volatile u8 flag=0;
// void isr1(void)
// {
// 	EXTI_INT0_Interrupt_Disable();
// 	if(counter!=0)
// 	{
// 		counter--;
// 	}
// 	_delay_ms(1000);
// 	flag=1;
// 	EXTI_INT0_Interrupt_Flag_clear();
// 	EXTI_INT0_Interrupt_Enable();


// }

// void isr2(void)
// {
// 	EXTI_INT1_Interrupt_Disable();
// 	counter++;
// 	_delay_ms(1000);
// 	flag=1;
// 	EXTI_INT1_Interrupt_Flag_clear();
// 	EXTI_INT1_Interrupt_Enable();
// }


// LCD_4BIT_ST lcd={.lcd_pins[0]=PIN_B0_ID_8,
// 				 .lcd_pins[1]=PIN_B1_ID_9,
// 				 .lcd_pins[2]=PIN_B2_ID_10,
// 				 .lcd_pins[3]=PIN_B4_ID_12,
// 				 .lcd_pin_rs=PIN_A3_ID_3,
// 				 .lcd_pin_e=PIN_A2_ID_2};

// int main(void)
// {
// 	Port_vidInit();
// 	GIE_INIT();
// 	LCD_vidInit_4bit(&lcd);
// 	//LCD_vidSendcommand_4bit(&lcd,LCD_CLEAR_DISPLAY);
// 	LCD_vidDisplayString_4bit(&lcd,"counter:");
// 	EXI_INT(EXTI_INT0,EXTI_MODE_FALING_EDGE,isr1);
// 	EXI_INT(EXTI_INT1,EXTI_MODE_FALING_EDGE,isr2);
// 	while (1)
// 	{
//  		if(counter>=9999)
// 		{
// 			counter=0;
// 		}
// 		if(flag==1)
// 		{
// 			LCD_vidGotoXY_4bit(&lcd,1,9);
// 			LCD_vidDisplayString_4bit(&lcd,"    ");
//  			LCD_vidGotoXY_4bit(&lcd,1,9);
// 			LCD_vidDisplayNumber_4bit(&lcd,counter);
// 			_delay_ms(500);
// 			flag=0;
// 		}

// 	}

// }

/*****************************************************counter lcd EXTI end **********************************/


/*****************************************************************/
/*
//  * AVR_DRIVERS.c
//  *
//  * Created: 10/20/2023 8:33:11 PM
//  * Author : ahmed radwan
//  */
// #define F_CPU 16000000UL
// #include <util/delay.h>

// #include "HAL/7_SEGMENT/7_SEGMENT.h"
// #include "HAL/BUTTON/BUTTON.h"
// #include "HAL/KEY_PAD/KEY_PAD.h"
// #include "HAL/LCD/LCD.h"
// #include "HAL/LCD/LCD_COMANDS.h"
// #include "MCAL/DIO/DIO.h"
// #include "MCAL/EXTI/EXTI.h"
// #include "MCAL/GIE/GIE.h"
// #include "MCAL/PORT/PORT.h"
// #include "MCAL/TIMER0/TIMER0.h"
// #include "SERVICES/Bit_Wise_Operations.h"
// #include "SERVICES/Standard_Data_Types.h"


// void over_Flow_ISR(void);
// volatile u8 SECONDS = 0;

// LCD_4BIT_ST lcd = {.lcd_pins[0] = PIN_B0_ID_8,
//                    .lcd_pins[1] = PIN_B1_ID_9,
//                    .lcd_pins[2] = PIN_B2_ID_10,
//                    .lcd_pins[3] = PIN_B4_ID_12,
//                    .lcd_pin_rs = PIN_A3_ID_3,
//                    .lcd_pin_e = PIN_A2_ID_2};

// KEY_PAD_ST keypad = {
//     .key_pad_rows_pins[0] = DIO_C5_ID_21,
//     .key_pad_rows_pins[1] = DIO_C4_ID_20,
//     .key_pad_rows_pins[2] = DIO_C3_ID_19,
//     .key_pad_rows_pins[3] = DIO_C2_ID_18,
//     .key_pad_col_pins[0] = DIO_D7_ID_31,
//     .key_pad_col_pins[1] = DIO_D6_ID_30,
//     .key_pad_col_pins[2] = DIO_D5_ID_29,
//     .key_pad_col_pins[3] = DIO_D3_ID_27,
// };
// u8 keypad_value = '@';
// u8 key_status = KEY_NOT_PRESSED;
// int main(void) {
//   Port_vidInit();
//   GIE_INIT();
//   LCD_vidInit_4bit(&lcd);
//   // LCD_vidSendcommand_4bit(&lcd,LCD_CLEAR_DISPLAY);

//   key_pad_Init(&keypad);
//   TIMER0_INT();
//   TIMER0_SET_OVRRFLOW_CALLBACK(over_Flow_ISR);
//   while (1) {
//   }
// }
// void over_Flow_ISR(void) {
//   SECONDS++;
//   if (SECONDS == 15) {
//     SECONDS = 0;
//     key_status = key_pad_Get_value(&keypad, &keypad_value);
//     if (KEY_PRESSED == key_status) {
//       LCD_vidDisplayChar_4bit(&lcd, keypad_value);
//     }
//   }
// }
/*****************************************************************/
/**********************************7amada task  *******************************/


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
// #include "HAL/LCD/LCD_COMANDS.h"
// #include "HAL/LCD/LCD.h"
// #include "MCAL/GIE/GIE.h"
// #include "MCAL/EXTI/EXTI.h"
// #include "MCAL/TIMER0/TIMER0.h"
// #include "HAL/KEY_PAD/KEY_PAD.h"

// u8 *line="____________________";
// u8 hamada[] = {
// 	0B01110,
// 	0B01110,
// 	0B11111,
// 	0B10101,
// 	0B00100,
// 	0B01110,
// 	0B11011,
// 	0B00000
// };

// LCD_4BIT_ST lcd={.lcd_pins[0]=PIN_B0_ID_8,
// 	.lcd_pins[1]=PIN_B1_ID_9,
// 	.lcd_pins[2]=PIN_B2_ID_10,
// 	.lcd_pins[3]=PIN_B4_ID_12,
// 	.lcd_pin_rs=PIN_A3_ID_3,
// .lcd_pin_e=PIN_A2_ID_2};

// int main(void)
// {

// 	Port_vidInit();
// 	GIE_INIT();
// 	LCD_vidInit_4bit(&lcd);
// 	LCD_vidCraetCustomChar_4bit(&lcd,hamada,1);
// 	LCD_vidSendcommand_4bit(&lcd,LCD_CLEAR_DISPLAY);
// 	LCD_vidDisplayString_4bit(&lcd,line);
// 	LCD_vidGotoXY_4bit(&lcd,2,0);
// 	LCD_vidDisplayString_4bit(&lcd,line);
// 	LCD_vidGotoXY_4bit(&lcd,3,0);
// 	LCD_vidDisplayString_4bit(&lcd,line);
// 	LCD_vidGotoXY_4bit(&lcd,4,0);
// 	LCD_vidDisplayString_4bit(&lcd,line);
// 	LCD_vidGotoXY_4bit(&lcd,1,0);
// 	LCD_vidDisplayChar_4bit(&lcd,1);
// 	while (1)
// 	{

// 		//LCD_vidDisplayChar_4bit(&lcd,keypad_value);
// 		//1s
// 		for(u8 row=1;row<=4;row++)
// 		{

// 			for(u8 col=0;col<=18;col++)
// 			{
// 				LCD_vidGotoXY_4bit(&lcd,row,col);
// 				LCD_vidDisplayChar_4bit(&lcd,'_');
// 				LCD_vidDisplayChar_4bit(&lcd,1);
// 				_delay_ms(100);
// 			}
// 			LCD_vidGotoXY_4bit(&lcd,row,19);
// 			LCD_vidDisplayChar_4bit(&lcd,'_');
// 		}//1e
// 		//2s
// 		LCD_vidGotoXY_4bit(&lcd,1,10);
// 		LCD_vidDisplayChar_4bit(&lcd,' ');
// 		for(u8 row=1;row<=4;row++)
// 		{

// 			for(u8 col=0;col<=18;col++)
// 			{
// 				if(row==1&&col==10)
// 				{
// 					LCD_vidGotoXY_4bit(&lcd,row,col);
// 					LCD_vidDisplayChar_4bit(&lcd,' ');
// 					row=2;
// 				}
// 				else
// 				{
// 					LCD_vidGotoXY_4bit(&lcd,row,col);
// 					LCD_vidDisplayChar_4bit(&lcd,'_');
// 					LCD_vidDisplayChar_4bit(&lcd,1);
// 					_delay_ms(100);
// 				}
// 			}
// 			LCD_vidGotoXY_4bit(&lcd,row,19);
// 			LCD_vidDisplayChar_4bit(&lcd,'_');
// 		}//2e
// 		//3
// 		LCD_vidGotoXY_4bit(&lcd,1,10);
// 		LCD_vidDisplayChar_4bit(&lcd,'_');
// 		LCD_vidGotoXY_4bit(&lcd,3,10);
// 		LCD_vidDisplayChar_4bit(&lcd,' ');
// 		LCD_vidGotoXY_4bit(&lcd,4,10);
// 		LCD_vidDisplayChar_4bit(&lcd,'/');
// 		LCD_vidGotoXY_4bit(&lcd,4,1);
// 		u8 row=4;
// 		for(u8 col=0;col<=18;col++)
// 		{

// 			if(col==10)
// 			{
// 				LCD_vidGotoXY_4bit(&lcd,4,10);
// 				LCD_vidDisplayChar_4bit(&lcd,'_');
// 				LCD_vidGotoXY_4bit(&lcd,3,10);
// 				LCD_vidDisplayChar_4bit(&lcd,1);
// 				row=3;
// 				LCD_vidGotoXY_4bit(&lcd,3,10);
// 				LCD_vidDisplayChar_4bit(&lcd,' ');

// 			}
// 			else
// 			{
// 				LCD_vidGotoXY_4bit(&lcd,row,col);
// 				LCD_vidDisplayChar_4bit(&lcd,'_');
// 				LCD_vidDisplayChar_4bit(&lcd,1);
// 				_delay_ms(100);
// 			}
// 		}
// 		LCD_vidGotoXY_4bit(&lcd,3,19);
// 		LCD_vidDisplayChar_4bit(&lcd,'_');
// 		LCD_vidGotoXY_4bit(&lcd,3,10);
// 		LCD_vidDisplayChar_4bit(&lcd,'|');
// 		for(u8 finalcol=0;finalcol<10;finalcol++)
// 		{
// 			LCD_vidGotoXY_4bit(&lcd,3,finalcol);
// 			LCD_vidDisplayChar_4bit(&lcd,'_');
// 			LCD_vidDisplayChar_4bit(&lcd,1);
// 			_delay_ms(100);
// 		}
// 		break;

// 	}
// 	LCD_vidSendcommand_4bit(&lcd,LCD_CLEAR_DISPLAY);
// 	LCD_vidGotoXY_4bit(&lcd,2,6);
// 	LCD_vidDisplayString_4bit(&lcd,"GAME OVER");

// }
/**********************************7amada task end *******************************/