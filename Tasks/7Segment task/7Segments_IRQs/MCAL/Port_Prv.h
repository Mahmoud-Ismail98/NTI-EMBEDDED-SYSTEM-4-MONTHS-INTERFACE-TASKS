/*********************************************************************************************
 * Name                 : Port_Prv.h
 * Description          : Private configuration
 * Author               : Mohamed khaled
 * *******************************************************************************************/

//Guard start
#ifndef PORT_PRV_H
#define PORT_PRV_H

/*********************************************************************************************/
							//Registers Mapping//
/********************************************************************************************/
// direction registers for port A,B,C and D
#define DDRA    *((volatile uint8*)0x3A)
#define DDRB    *((volatile uint8*)0x37)
#define DDRC    *((volatile uint8*)0x34)
#define DDRD    *((volatile uint8*)0x31)

//Data registers for port A,B,C and D
#define PORTA    *((volatile uint8*)0x3B)
#define PORTB    *((volatile uint8*)0x38)
#define PORTC    *((volatile uint8*)0x35)
#define PORTD    *((volatile uint8*)0x32)

//read registers for port A,B,C and D
#define PINA     *((const volatile uint8*)0x39)
#define PINB     *((const volatile uint8*)0x36)
#define PINC     *((const volatile uint8*)0x33)
#define PIND     *((const volatile uint8*)0x30)

/*********************************************************************************************/
							//PORTS definition//
/********************************************************************************************/
//Port A,B,C and D
#define PORT_A            0
#define PORT_B            1
#define PORT_C            2
#define PORT_D            3

//guard end
#endif
