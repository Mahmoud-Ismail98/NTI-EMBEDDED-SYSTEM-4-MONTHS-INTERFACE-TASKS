//#include "../../services/Bit_utils.h"
#include "../../../services/Std_types.h"
#include "../../../services/Bit_utils.h"
#include "../../../MCAL/PORT/include/port.h"
#include "../../../MCAL/DIO/include/DIO.h"
#include "../../../MCAL/DIO/include/DIO_private.h"
#include "../../../HAL/KEYPAD/include/KEYPAD_cfg.h"
#include "../../../HAL/KEYPAD/include/KEYPAD.h"


#define	 KEY_RAW0		PORTC_PIN0
#define	 KEY_RAW1		PORTC_PIN1
#define	 KEY_RAW2		PORTC_PIN2
#define	 KEY_RAW3		PORTC_PIN3
#define	 KEY_COL0		PORTC_PIN4
#define	 KEY_COL1		PORTC_PIN5
#define	 KEY_COL2		PORTC_PIN6
#define	 KEY_COL3		PORTC_PIN7




void KEYPAD_WritrPins(u8 value)
{
	DIO_WritrPin(KEY_RAW0,GET_BIT(value,0));
	DIO_WritrPin(KEY_RAW1,GET_BIT(value,1));
	DIO_WritrPin(KEY_RAW2,GET_BIT(value,2));
	DIO_WritrPin(KEY_RAW3,GET_BIT(value,3));
}

void KEYPAD_ReadPins(u8 *value)
{
	u8 loc_read=0;
	DIO_READ_PIN(KEY_COL0,&loc_read);
	*value=loc_read;
	DIO_READ_PIN(KEY_COL1,&loc_read);
	*value|=(loc_read<<1);
	DIO_READ_PIN(KEY_COL2,&loc_read);
	*value|=(loc_read<<2);
	DIO_READ_PIN(KEY_COL3,&loc_read);
	*value|=(loc_read<<3);
}	
ERROR_KEYPAD_STATUS KEYPAD_FindKey(u8 *Loc_keyPress)
{
  ERROR_KEYPAD_STATUS ERROR_KEYPAD_RET=ERROR_FREE;
  u8 temp=0b00;
  u8 reg;
  for(u8 i=0;i<RAW_NUM;i++)
  {	  
	reg=0x0F;
	//pin=i;
//	 reg^=(1<<i);	  
  KEYPAD_WritrPins(TGLWITHOUTASSIGN_BIT(reg,i));
  //KEYPAD_WritrPins((reg^=(1<<i)));
 // KEYPAD_WritrPins(0x0F & (0x0F<<i));
 // KEYPAD_WritrPins(0xFE);
  KEYPAD_ReadPins(&temp);
  switch(temp)
  {
	case 0b1110:	
	*Loc_keyPress=KEYPAD_SYMBOL[(4*i)+0]; 
	break;
	case 0b1101:	
	*Loc_keyPress=KEYPAD_SYMBOL[(4*i)+1];
	break;
	case 0b1011:	
	*Loc_keyPress=KEYPAD_SYMBOL[(4*i)+2];
	break;
	case 0b0111:	
	*Loc_keyPress=KEYPAD_SYMBOL[(4*i)+3];
	break;
	default:
	ERROR_KEYPAD_RET=NO_KEY_PRESSED;
	
   }
  }   	
	return ERROR_KEYPAD_RET;

}
