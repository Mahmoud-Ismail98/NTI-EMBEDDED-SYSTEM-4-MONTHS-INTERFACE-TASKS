#ifndef KEYPAD_Cfg_H
#define KEYPAD_Cfg_H


#define KEYPAD_4x3       0
#define KEYPAD_4x4       1

#define KEYPAD_TYPE       KEYPAD_4x4


#if(KEYPAD_TYPE==KEYPAD_4x3)
#define KEYPAD_NUMBER_OF_ROWS    4
#define KEYPAD_NUMBER_OF_COL     3

#define KEYPAD_ROW1    PIN7
#define KEYPAD_ROW2    PIN7
#define KEYPAD_ROW3    PIN7
#define KEYPAD_ROW4    PIN7

#define KEYPAD_COL1    PIN7
#define KEYPAD_COL2    PIN7
#define KEYPAD_COL3    PIN7

#elif(KEYPAD_TYPE==KEYPAD_4x4)
#define KEYPAD_NUMBER_OF_ROWS    4
#define KEYPAD_NUMBER_OF_COL     4

#define KEYPAD_ROW1    PIN8
#define KEYPAD_ROW2    PIN9
#define KEYPAD_ROW3    PIN10
#define KEYPAD_ROW4    PIN11

#define KEYPAD_COL1    PIN12
#define KEYPAD_COL2    PIN13
#define KEYPAD_COL3    PIN14
#define KEYPAD_COL4    PIN15

#endif

#define ROW0_COL0     '7'
#define ROW0_COL1     '8'
#define ROW0_COL2     '9'
#define ROW0_COL3     '/'

#define ROW1_COL0     '4'
#define ROW1_COL1     '5'
#define ROW1_COL2     '6'
#define ROW1_COL3     '*'

#define ROW2_COL0     '1'
#define ROW2_COL1     '2'
#define ROW2_COL2     '3'
#define ROW2_COL3     '-'

#define ROW3_COL0     '#'
#define ROW3_COL1     '0'
#define ROW3_COL2     '='
#define ROW3_COL3     '+'
#endif
