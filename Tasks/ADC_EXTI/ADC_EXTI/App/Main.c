#include "../MCAL/Port/Includes/Port.h"
#include "../MCAL/ADC/Includes/ADC.h"
#include "../HAL/LCD/Includes/LCD.h"
#include "../MCAL/GIE/Includes/GIE.h"
#include "../MCAL/EXTI/Includes/EXTI.h"
#include "util/delay.h"

uint32 Value_mv=0;
uint8 Flag=0;
uint8 Flag1=0;
uint8 Flag2=0;

void ADC_CallFunc(uint16 Val)
{
	Value_mv=Val;

}
void EXTI_Func1(void);
void EXTI_Func2(void);

int main(void)
{
	float32 Value_v=0;
	PORT_Init();
	GIE_enuInit();
	EXTI_Init();
	Lcd_Init();
	ADC_ConfigType Config={AREF,ADC0,Prescaler_64};
	ADC_Init(&Config);
	ADC_CallBack(ADC_CallFunc);
	EXTI_CallBack(EXTI_Func1,EXTI_INT0_IRQ);
	LCD_DisplayStringXY(0,0,"Volume =");
	while(1)
	{
		ADC_enuReadChannel(ADC0);
		if(Flag==0)
		{
			if(Flag1==0){
			LCD_DisplayStringXY(0,9,"          ");
			Flag1=1;
			}
			Lcd_VidDisplayNumberXY(0,9,Value_mv);
			LCD_DisplayStringXY(0,13,"       ");
			LCD_DisplayStringXY(2,15,"mv");
		}
		else if(Flag==1)
		{
			if(Flag2==0){
		LCD_DisplayStringXY(0,9,"          ");
		Flag2=1;
			}
		Value_v=(float32) Value_mv / 1000;
		LCD_VidDisplayFloat(0,9,Value_v);
		LCD_DisplayStringXY(0,12,"        ");
		LCD_DisplayStringXY(2,15,"v ");
		}
	}
}


void EXTI_Func1(void)
{
	Flag=1;
	Flag2=0;
	EXTI_CallBack(EXTI_Func2,EXTI_INT0_IRQ);

}
void EXTI_Func2(void)
{
	Flag=0;
	Flag1=0;
	EXTI_CallBack(EXTI_Func1,EXTI_INT0_IRQ);

}
