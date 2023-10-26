
#include "std_types.h"
#include "Bit_utils.h"

#include "ADC_Priv.h"
#include "ADC_Config.h"
#include "ADC_Int.h"

static volatile void (* ADCINT_ptr) (void); 
void ADC_voidInitialize(void) 

{
//select voltage reference
#if (VOLTAGE_REFERENCE_SELECTION == AREF)
CLR_BIT(ADMUX,REFS0);
CLR_BIT(ADMUX,REFS1);
#elif (VOLTAGE_REFERENCE_SELECTION == AVCC_CAPACITOR_AT_AREF)
SET_BIT(ADMUX,REFS0);
CLR_BIT(ADMUX,REFS1);
#elif ((VOLTAGE_REFERENCE_SELECTION == INTERNAL_2_56_VOLTAGE_REFERENCE))
SET_BIT(ADMUX,REFS0);
SET_BIT(ADMUX,REFS1);

#else
#error "Wrong reference selection mode chosen"
#endif

#if (ADC_CONVERSION_FORM == LEFT_ADJUSTED)
SET_BIT(ADMUX,ADLAR);
#elif (ADC_CONVERSION_FORM == RIGHT_ADJUSTED)
CLR_BIT(ADMUX,ADLAR);
#else
#error "Wrong left or right adjust mode chosen"
#endif


#if (ANALOG_CHANNEL_AND_GAIN_SELECTION_REFERENCE == SEI_ADC0)
CLR_BIT(ADMUX,MUX4);
CLR_BIT(ADMUX,MUX3);
CLR_BIT(ADMUX,MUX2);
CLR_BIT(ADMUX,MUX1);
CLR_BIT(ADMUX,MUX0);

#elif (ANALOG_CHANNEL_AND_GAIN_SELECTION_REFERENCE == SEI_ADC1)
CLR_BIT(ADMUX,MUX4);
CLR_BIT(ADMUX,MUX3);
CLR_BIT(ADMUX,MUX2);
CLR_BIT(ADMUX,MUX1);
SET_BIT(ADMUX,MUX0);

#elif (ANALOG_CHANNEL_AND_GAIN_SELECTION_REFERENCE ==   SEI_ADC2
)
CLR_BIT(ADMUX,MUX4);
CLR_BIT(ADMUX,MUX3);
CLR_BIT(ADMUX,MUX2);
SET_BIT(ADMUX,MUX1);
CLR_BIT(ADMUX,MUX0);

#elif (ANALOG_CHANNEL_AND_GAIN_SELECTION_REFERENCE == SEI_ADC3
)
CLR_BIT(ADMUX,MUX4);
CLR_BIT(ADMUX,MUX3);
CLR_BIT(ADMUX,MUX2);
SET_BIT(ADMUX,MUX1);
SET_BIT(ADMUX,MUX0);

#elif (ANALOG_CHANNEL_AND_GAIN_SELECTION_REFERENCE == SEI_ADC4)
CLR_BIT(ADMUX,MUX4);
CLR_BIT(ADMUX,MUX3);
SET_BIT(ADMUX,MUX2);
CLR_BIT(ADMUX,MUX1);
CLR_BIT(ADMUX,MUX0);

#elif (ANALOG_CHANNEL_AND_GAIN_SELECTION_REFERENCE ==   SEI_ADC5
)
CLR_BIT(ADMUX,MUX4);
CLR_BIT(ADMUX,MUX3);
SET_BIT(ADMUX,MUX2);
CLR_BIT(ADMUX,MUX1);
SET_BIT(ADMUX,MUX0);

#elif (ANALOG_CHANNEL_AND_GAIN_SELECTION_REFERENCE == SEI_ADC6 )
CLR_BIT(ADMUX,MUX4);
CLR_BIT(ADMUX,MUX3);
SET_BIT(ADMUX,MUX2);
SET_BIT(ADMUX,MUX1);
CLR_BIT(ADMUX,MUX0);

#elif (ANALOG_CHANNEL_AND_GAIN_SELECTION_REFERENCE == SEI_ADC7)
CLR_BIT(ADMUX,MUX4);
CLR_BIT(ADMUX,MUX3);
SET_BIT(ADMUX,MUX2);
SET_BIT(ADMUX,MUX1);
SET_BIT(ADMUX,MUX0);

#elif (ANALOG_CHANNEL_AND_GAIN_SELECTION_REFERENCE ==   DI_PADC0_NADC0_G10
)
CLR_BIT(ADMUX,MUX4);
SET_BIT(ADMUX,MUX3);
CLR_BIT(ADMUX,MUX2);
CLR_BIT(ADMUX,MUX1);
CLR_BIT(ADMUX,MUX0);

#elif (ANALOG_CHANNEL_AND_GAIN_SELECTION_REFERENCE == DI_PADC1_NADC0_G10
 )
CLR_BIT(ADMUX,MUX4);
SET_BIT(ADMUX,MUX3);
CLR_BIT(ADMUX,MUX2);
CLR_BIT(ADMUX,MUX1);
SET_BIT(ADMUX,MUX0);

#elif (ANALOG_CHANNEL_AND_GAIN_SELECTION_REFERENCE ==  DI_PADC0_NADC0_G200
)
CLR_BIT(ADMUX,MUX4);
SET_BIT(ADMUX,MUX3);
CLR_BIT(ADMUX,MUX2);
SET_BIT(ADMUX,MUX1);
CLR_BIT(ADMUX,MUX0);

#elif (ANALOG_CHANNEL_AND_GAIN_SELECTION_REFERENCE ==  DI_PADC1_NADC0_G200
)
CLR_BIT(ADMUX,MUX4);
SET_BIT(ADMUX,MUX3);
CLR_BIT(ADMUX,MUX2);
SET_BIT(ADMUX,MUX1);
SET_BIT(ADMUX,MUX0);


#elif (ANALOG_CHANNEL_AND_GAIN_SELECTION_REFERENCE == DI_PADC2_NADC2_G10
 )
CLR_BIT(ADMUX,MUX4);
SET_BIT(ADMUX,MUX3);
SET_BIT(ADMUX,MUX2);
CLR_BIT(ADMUX,MUX1);
CLR_BIT(ADMUX,MUX0);

#elif (ANALOG_CHANNEL_AND_GAIN_SELECTION_REFERENCE ==   DI_PADC3_NADC2_G10
 )
CLR_BIT(ADMUX,MUX4);
SET_BIT(ADMUX,MUX3);
SET_BIT(ADMUX,MUX2);
CLR_BIT(ADMUX,MUX1);
SET_BIT(ADMUX,MUX0);

#elif (ANALOG_CHANNEL_AND_GAIN_SELECTION_REFERENCE == DI_PADC2_NADC2_G200)
CLR_BIT(ADMUX,MUX4);
SET_BIT(ADMUX,MUX3);
SET_BIT(ADMUX,MUX2);
SET_BIT(ADMUX,MUX1);
CLR_BIT(ADMUX,MUX0);

#elif (ANALOG_CHANNEL_AND_GAIN_SELECTION_REFERENCE ==   DI_PADC3_NADC2_G200
)
CLR_BIT(ADMUX,MUX4);
SET_BIT(ADMUX,MUX3);
SET_BIT(ADMUX,MUX2);
SET_BIT(ADMUX,MUX1);
SET_BIT(ADMUX,MUX0);

#elif (ANALOG_CHANNEL_AND_GAIN_SELECTION_REFERENCE == DI_PADC0_NADC1_G1
)
SET_BIT(ADMUX,MUX4);
CLR_BIT(ADMUX,MUX3);
CLR_BIT(ADMUX,MUX2);
CLR_BIT(ADMUX,MUX1);
CLR_BIT(ADMUX,MUX0);

#elif (ANALOG_CHANNEL_AND_GAIN_SELECTION_REFERENCE == DI_PADC1_NADC1_G1)
SET_BIT(ADMUX,MUX4);
CLR_BIT(ADMUX,MUX3);
CLR_BIT(ADMUX,MUX2);
CLR_BIT(ADMUX,MUX1);
SET_BIT(ADMUX,MUX0);

#elif (ANALOG_CHANNEL_AND_GAIN_SELECTION_REFERENCE == DI_PADC2_NADC1_G1 )
SET_BIT(ADMUX,MUX4);
CLR_BIT(ADMUX,MUX3);
CLR_BIT(ADMUX,MUX2);
SET_BIT(ADMUX,MUX1);
CLR_BIT(ADMUX,MUX0);



#elif (ANALOG_CHANNEL_AND_GAIN_SELECTION_REFERENCE == DI_PADC3_NADC1_G1)
SET_BIT(ADMUX,MUX4);
CLR_BIT(ADMUX,MUX3);
CLR_BIT(ADMUX,MUX2);
SET_BIT(ADMUX,MUX1);
SET_BIT(ADMUX,MUX0);

#elif (ANALOG_CHANNEL_AND_GAIN_SELECTION_REFERENCE == DI_PADC4_NADC1_G1)
SET_BIT(ADMUX,MUX4);
CLR_BIT(ADMUX,MUX3);
SET_BIT(ADMUX,MUX2);
CLR_BIT(ADMUX,MUX1);
CLR_BIT(ADMUX,MUX0);

#elif (ANALOG_CHANNEL_AND_GAIN_SELECTION_REFERENCE ==   DI_PADC5_NADC1_G1
)
SET_BIT(ADMUX,MUX4);
CLR_BIT(ADMUX,MUX3);
SET_BIT(ADMUX,MUX2);
CLR_BIT(ADMUX,MUX1);
SET_BIT(ADMUX,MUX0);




#elif (ANALOG_CHANNEL_AND_GAIN_SELECTION_REFERENCE == DI_PADC6_NADC1_G1 )
SET_BIT(ADMUX,MUX4);
CLR_BIT(ADMUX,MUX3);
SET_BIT(ADMUX,MUX2);
SET_BIT(ADMUX,MUX1);
CLR_BIT(ADMUX,MUX0);

#elif (ANALOG_CHANNEL_AND_GAIN_SELECTION_REFERENCE == DI_PADC7_NADC1_G1)
SET_BIT(ADMUX,MUX4);
CLR_BIT(ADMUX,MUX3);
SET_BIT(ADMUX,MUX2);
SET_BIT(ADMUX,MUX1);
SET_BIT(ADMUX,MUX0);

#elif (ANALOG_CHANNEL_AND_GAIN_SELECTION_REFERENCE == DI_PADC0_NADC2_G1)
SET_BIT(ADMUX,MUX4);
SET_BIT(ADMUX,MUX3);
CLR_BIT(ADMUX,MUX2);
CLR_BIT(ADMUX,MUX1);
CLR_BIT(ADMUX,MUX0);

#elif (ANALOG_CHANNEL_AND_GAIN_SELECTION_REFERENCE == DI_PADC1_NADC2_G1)
SET_BIT(ADMUX,MUX4);
SET_BIT(ADMUX,MUX3);
CLR_BIT(ADMUX,MUX2);
CLR_BIT(ADMUX,MUX1);
SET_BIT(ADMUX,MUX0);

#elif (ANALOG_CHANNEL_AND_GAIN_SELECTION_REFERENCE == DI_PADC2_NADC2_G1)
SET_BIT(ADMUX,MUX4);
SET_BIT(ADMUX,MUX3);
CLR_BIT(ADMUX,MUX2);
SET_BIT(ADMUX,MUX1);
CLR_BIT(ADMUX,MUX0);

#elif (ANALOG_CHANNEL_AND_GAIN_SELECTION_REFERENCE == DI_PADC3_NADC2_G1)
SET_BIT(ADMUX,MUX4);
SET_BIT(ADMUX,MUX3);
CLR_BIT(ADMUX,MUX2);
SET_BIT(ADMUX,MUX1);
SET_BIT(ADMUX,MUX0);

#elif (ANALOG_CHANNEL_AND_GAIN_SELECTION_REFERENCE == DI_PADC4_NADC2_G1)
SET_BIT(ADMUX,MUX4);
SET_BIT(ADMUX,MUX3);
SET_BIT(ADMUX,MUX2);
CLR_BIT(ADMUX,MUX1);
CLR_BIT(ADMUX,MUX0);

#elif (ANALOG_CHANNEL_AND_GAIN_SELECTION_REFERENCE == DI_PADC5_NADC2_G1)
SET_BIT(ADMUX,MUX4);
SET_BIT(ADMUX,MUX3);
SET_BIT(ADMUX,MUX2);
CLR_BIT(ADMUX,MUX1);
SET_BIT(ADMUX,MUX0);

#elif (ANALOG_CHANNEL_AND_GAIN_SELECTION_REFERENCE == SEI_1_22V)
SET_BIT(ADMUX,MUX4);
SET_BIT(ADMUX,MUX3);
SET_BIT(ADMUX,MUX2);
SET_BIT(ADMUX,MUX1);
CLR_BIT(ADMUX,MUX0);

#elif (ANALOG_CHANNEL_AND_GAIN_SELECTION_REFERENCE == SEI_0V)
SET_BIT(ADMUX,MUX4);
SET_BIT(ADMUX,MUX3);
SET_BIT(ADMUX,MUX2);
SET_BIT(ADMUX,MUX1);
SET_BIT(ADMUX,MUX0);

#else
#error "Wrong gain channel mode selected"
#endif

//enable or disable auto trigger conversions
#if (ADC_AUTO_TRIGGER_ENABLE ==ENABLED)
SET_BIT(ADCSRA,ADATE);
#elif(ADC_AUTO_TRIGGER_ENABLE ==DISABLED)
CLR_BIT(ADCSRA,ADATE);
#else
#error "Wrong auto trigger mode selected, please select enabled or disabled"
#endif

//enable or disable interrupts that occurs after conversion, still needs to be updated by updating the interrupt functions
#if(ADC_INTERRUPT_ENABLE == ENABLED)
SET_BIT(ADCSRA,ADIE);



#elif (ADC_INTERRUPT_ENABLE == DISABLED)
CLR_BIT(ADCSRA,ADIE);
#else
#error "Wrong interrupt mode selected, please select enabled or disabled "
#endif



#if (ADC_PRESCALER_SET_BITS == DIVISION_FACTOR_2 )
CLR_BIT(ADCSRA,ADPS2);
CLR_BIT(ADCSRA,ADPS1);
CLR_BIT(ADCSRA,ADPS0);

#elif (ADC_PRESCALER_SET_BITS ==  DIVISION_FACTOR_2)
CLR_BIT(ADCSRA,ADPS2);
CLR_BIT(ADCSRA,ADPS1);
SET_BIT(ADCSRA,ADPS0);

#elif (ADC_PRESCALER_SET_BITS == DIVISION_FACTOR_4)
CLR_BIT(ADCSRA,ADPS2);
SET_BIT(ADCSRA,ADPS1);
CLR_BIT(ADCSRA,ADPS0);

#elif (ADC_PRESCALER_SET_BITS ==DIVISION_FACTOR_8  )
CLR_BIT(ADCSRA,ADPS2);
SET_BIT(ADCSRA,ADPS1);
SET_BIT(ADCSRA,ADPS0);

#elif (ADC_PRESCALER_SET_BITS ==  DIVISION_FACTOR_16)
SET_BIT(ADCSRA,ADPS2);
CLR_BIT(ADCSRA,ADPS1);
CLR_BIT(ADCSRA,ADPS0);

#elif (ADC_PRESCALER_SET_BITS == DIVISION_FACTOR_32)
SET_BIT(ADCSRA,ADPS2);
CLR_BIT(ADCSRA,ADPS1);
SET_BIT(ADCSRA,ADPS0);

#elif (ADC_PRESCALER_SET_BITS ==  DIVISION_FACTOR_64)
SET_BIT(ADCSRA,ADPS2);
SET_BIT(ADCSRA,ADPS1);
CLR_BIT(ADCSRA,ADPS0);

#elif (ADC_PRESCALER_SET_BITS ==  DIVISION_FACTOR_64)
SET_BIT(ADCSRA,ADPS2);
SET_BIT(ADCSRA,ADPS1);
SET_BIT(ADCSRA,ADPS0);

#else
#error "Wrong prescaler value selected"
#endif




//set the bits to enable the autotrigger source
#if (AUTO_TRIGGER_SOURCE == FREE_RUNNING_MODE)
CLR_BIT(SFIOR,ADTS2);
CLR_BIT(SFIOR,ADTS1);
CLR_BIT(SFIOR,ADTS0);

#elif (AUTO_TRIGGER_SOURCE == ANALOG_COMAPARTOR)
CLR_BIT(SFIOR,ADTS2);
CLR_BIT(SFIOR,ADTS1);
SET_BIT(SFIOR,ADTS0);

#elif (AUTO_TRIGGER_SOURCE == EXTERNAL_INTERRUPT_REQUEST_0)
CLR_BIT(SFIOR,ADTS2);
SET_BIT(SFIOR,ADTS1);
CLR_BIT(SFIOR,ADTS0);

#elif (AUTO_TRIGGER_SOURCE == TIMER_OR_COUNTER0_COMPARE_MATCH)
CLR_BIT(SFIOR,ADTS2);
SET_BIT(SFIOR,ADTS1);
SET_BIT(SFIOR,ADTS0);

#elif (AUTO_TRIGGER_SOURCE == TIMER_OR_COUNTER0_OVERFLOW)
SET_BIT(SFIOR,ADTS2);
CLR_BIT(SFIOR,ADTS1);
CLR_BIT(SFIOR,ADTS0);

#elif (AUTO_TRIGGER_SOURCE == TIMER_OR_COUNTER1_COMPARE_MATCH_B)
SET_BIT(SFIOR,ADTS2);
CLR_BIT(SFIOR,ADTS1);
SET_BIT(SFIOR,ADTS0);

#elif (AUTO_TRIGGER_SOURCE == TIMER_OR_COUNTER1_OVERFLOW)
SET_BIT(SFIOR,ADTS2);
SET_BIT(SFIOR,ADTS1);
CLR_BIT(SFIOR,ADTS0);

#elif (AUTO_TRIGGER_SOURCE == TIMER_OR_COUNTER1_CAPTURE_EVENT)
SET_BIT(SFIOR,ADTS2);
SET_BIT(SFIOR,ADTS1);
SET_BIT(SFIOR,ADTS0);

#else
#error "Auto trigger wrong source selected, please choose from options in configuration"
#endif

//enable ADC to start converting, this should be after all configurations are set
#if (ADC_ENABLE == ENABLED)
SET_BIT(ADCSRA,ADEN);
#elif (ADC_ENABLE == DISABLED)
CLR_BIT(ADCSRA,ADEN);
#else
#error "wrong mode for activating ADC selected please either enable or disable"

#endif

}

//this function starts the first but for conversion, supposed to initiate conversion in freerunning mode
static void ADC_voidStartConversion(void)
{
	SET_BIT(ADCSRA,ADSC);
}
//this function changes the reference pin of conversion. you ca refere to different modes based on ADC_Config file
void ADC_voidChangeReference(u8 reference)
{
if (reference == SEI_ADC0)
{
CLR_BIT(ADMUX,MUX4);
CLR_BIT(ADMUX,MUX3);
CLR_BIT(ADMUX,MUX2);
CLR_BIT(ADMUX,MUX1);
CLR_BIT(ADMUX,MUX0);
}
else if (reference == SEI_ADC1)
{
CLR_BIT(ADMUX,MUX4);
CLR_BIT(ADMUX,MUX3);
CLR_BIT(ADMUX,MUX2);
CLR_BIT(ADMUX,MUX1);
SET_BIT(ADMUX,MUX0);
}
else if (reference ==  SEI_ADC2)
{
CLR_BIT(ADMUX,MUX4);
CLR_BIT(ADMUX,MUX3);
CLR_BIT(ADMUX,MUX2);
SET_BIT(ADMUX,MUX1);
CLR_BIT(ADMUX,MUX0);
}
else if (reference == SEI_ADC3)
{
CLR_BIT(ADMUX,MUX4);
CLR_BIT(ADMUX,MUX3);
CLR_BIT(ADMUX,MUX2);
SET_BIT(ADMUX,MUX1);
SET_BIT(ADMUX,MUX0);
}
else if (reference == SEI_ADC4)
{
CLR_BIT(ADMUX,MUX4);
CLR_BIT(ADMUX,MUX3);
SET_BIT(ADMUX,MUX2);
CLR_BIT(ADMUX,MUX1);
CLR_BIT(ADMUX,MUX0);
}
else if (reference ==   SEI_ADC5)
{
CLR_BIT(ADMUX,MUX4);
CLR_BIT(ADMUX,MUX3);
SET_BIT(ADMUX,MUX2);
CLR_BIT(ADMUX,MUX1);
SET_BIT(ADMUX,MUX0);
}
else if (reference == SEI_ADC6 )
{
	CLR_BIT(ADMUX,MUX4);
CLR_BIT(ADMUX,MUX3);
SET_BIT(ADMUX,MUX2);
SET_BIT(ADMUX,MUX1);
CLR_BIT(ADMUX,MUX0);
}
else if (reference == SEI_ADC7)
{
	CLR_BIT(ADMUX,MUX4);
CLR_BIT(ADMUX,MUX3);
SET_BIT(ADMUX,MUX2);
SET_BIT(ADMUX,MUX1);
SET_BIT(ADMUX,MUX0);
}
else if (reference ==   DI_PADC0_NADC0_G10)
{
CLR_BIT(ADMUX,MUX4);
SET_BIT(ADMUX,MUX3);
CLR_BIT(ADMUX,MUX2);
CLR_BIT(ADMUX,MUX1);
CLR_BIT(ADMUX,MUX0);
}
else if (reference == DI_PADC1_NADC0_G10)
{
CLR_BIT(ADMUX,MUX4);
SET_BIT(ADMUX,MUX3);
CLR_BIT(ADMUX,MUX2);
CLR_BIT(ADMUX,MUX1);
SET_BIT(ADMUX,MUX0);
}
else if (reference ==  DI_PADC0_NADC0_G200)
{
CLR_BIT(ADMUX,MUX4);
SET_BIT(ADMUX,MUX3);
CLR_BIT(ADMUX,MUX2);
SET_BIT(ADMUX,MUX1);
CLR_BIT(ADMUX,MUX0);
}
else if (reference ==  DI_PADC1_NADC0_G200)
{
CLR_BIT(ADMUX,MUX4);
SET_BIT(ADMUX,MUX3);
CLR_BIT(ADMUX,MUX2);
SET_BIT(ADMUX,MUX1);
SET_BIT(ADMUX,MUX0);
}

else if (reference == DI_PADC2_NADC2_G10)
{
CLR_BIT(ADMUX,MUX4);
SET_BIT(ADMUX,MUX3);
SET_BIT(ADMUX,MUX2);
CLR_BIT(ADMUX,MUX1);
CLR_BIT(ADMUX,MUX0);
}

else if (reference ==   DI_PADC3_NADC2_G10)
{
CLR_BIT(ADMUX,MUX4);
SET_BIT(ADMUX,MUX3);
SET_BIT(ADMUX,MUX2);
CLR_BIT(ADMUX,MUX1);
SET_BIT(ADMUX,MUX0);
}

else if (reference == DI_PADC2_NADC2_G200)
{
CLR_BIT(ADMUX,MUX4);
SET_BIT(ADMUX,MUX3);
SET_BIT(ADMUX,MUX2);
SET_BIT(ADMUX,MUX1);
CLR_BIT(ADMUX,MUX0);
}

else if (reference ==   DI_PADC3_NADC2_G200)
{
CLR_BIT(ADMUX,MUX4);
SET_BIT(ADMUX,MUX3);
SET_BIT(ADMUX,MUX2);
SET_BIT(ADMUX,MUX1);
SET_BIT(ADMUX,MUX0);
}
else if (reference == DI_PADC0_NADC1_G1)
{
SET_BIT(ADMUX,MUX4);
CLR_BIT(ADMUX,MUX3);
CLR_BIT(ADMUX,MUX2);
CLR_BIT(ADMUX,MUX1);
CLR_BIT(ADMUX,MUX0);
}
else if (reference == DI_PADC1_NADC1_G1)
{
SET_BIT(ADMUX,MUX4);
CLR_BIT(ADMUX,MUX3);
CLR_BIT(ADMUX,MUX2);
CLR_BIT(ADMUX,MUX1);
SET_BIT(ADMUX,MUX0);
}

else if (reference == DI_PADC2_NADC1_G1 )
{
SET_BIT(ADMUX,MUX4);
CLR_BIT(ADMUX,MUX3);
CLR_BIT(ADMUX,MUX2);
SET_BIT(ADMUX,MUX1);
CLR_BIT(ADMUX,MUX0);
}


else if (reference == DI_PADC3_NADC1_G1)
{
SET_BIT(ADMUX,MUX4);
CLR_BIT(ADMUX,MUX3);
CLR_BIT(ADMUX,MUX2);
SET_BIT(ADMUX,MUX1);
SET_BIT(ADMUX,MUX0);
}

else if (reference == DI_PADC4_NADC1_G1)
{
SET_BIT(ADMUX,MUX4);
CLR_BIT(ADMUX,MUX3);
SET_BIT(ADMUX,MUX2);
CLR_BIT(ADMUX,MUX1);
CLR_BIT(ADMUX,MUX0);
}

else if (reference ==   DI_PADC5_NADC1_G1)
{
SET_BIT(ADMUX,MUX4);
CLR_BIT(ADMUX,MUX3);
SET_BIT(ADMUX,MUX2);
CLR_BIT(ADMUX,MUX1);
SET_BIT(ADMUX,MUX0);
}

else if (reference == DI_PADC6_NADC1_G1 )
{
SET_BIT(ADMUX,MUX4);
CLR_BIT(ADMUX,MUX3);
SET_BIT(ADMUX,MUX2);
SET_BIT(ADMUX,MUX1);
CLR_BIT(ADMUX,MUX0);
}

else if (reference == DI_PADC7_NADC1_G1)
{
SET_BIT(ADMUX,MUX4);
CLR_BIT(ADMUX,MUX3);
SET_BIT(ADMUX,MUX2);
SET_BIT(ADMUX,MUX1);
SET_BIT(ADMUX,MUX0);
}

else if (reference == DI_PADC0_NADC2_G1)
{
SET_BIT(ADMUX,MUX4);
SET_BIT(ADMUX,MUX3);
CLR_BIT(ADMUX,MUX2);
CLR_BIT(ADMUX,MUX1);
CLR_BIT(ADMUX,MUX0);
}
else if (reference == DI_PADC1_NADC2_G1)
{
SET_BIT(ADMUX,MUX4);
SET_BIT(ADMUX,MUX3);
CLR_BIT(ADMUX,MUX2);
CLR_BIT(ADMUX,MUX1);
SET_BIT(ADMUX,MUX0);
}
else if (reference== DI_PADC2_NADC2_G1)
{
SET_BIT(ADMUX,MUX4);
SET_BIT(ADMUX,MUX3);
CLR_BIT(ADMUX,MUX2);
SET_BIT(ADMUX,MUX1);
CLR_BIT(ADMUX,MUX0);
}

else if (reference == DI_PADC3_NADC2_G1)
{
SET_BIT(ADMUX,MUX4);
SET_BIT(ADMUX,MUX3);
CLR_BIT(ADMUX,MUX2);
SET_BIT(ADMUX,MUX1);
SET_BIT(ADMUX,MUX0);
}

else if (reference == DI_PADC4_NADC2_G1)
{
SET_BIT(ADMUX,MUX4);
SET_BIT(ADMUX,MUX3);
SET_BIT(ADMUX,MUX2);
CLR_BIT(ADMUX,MUX1);
CLR_BIT(ADMUX,MUX0);
}

else if (reference == DI_PADC5_NADC2_G1)
{
SET_BIT(ADMUX,MUX4);
SET_BIT(ADMUX,MUX3);
SET_BIT(ADMUX,MUX2);
CLR_BIT(ADMUX,MUX1);
SET_BIT(ADMUX,MUX0);
}

else if (reference == SEI_1_22V)
{
SET_BIT(ADMUX,MUX4);
SET_BIT(ADMUX,MUX3);
SET_BIT(ADMUX,MUX2);
SET_BIT(ADMUX,MUX1);
CLR_BIT(ADMUX,MUX0);
}

else if (reference == SEI_0V)
{
SET_BIT(ADMUX,MUX4);
SET_BIT(ADMUX,MUX3);
SET_BIT(ADMUX,MUX2);
SET_BIT(ADMUX,MUX1);
SET_BIT(ADMUX,MUX0);
}

else
{

}

}
//this function is used to clear the interrupt flag by software
void ADC_voidClearInterruptFlag(void)
{
	SET_BIT(ADCSRA,ADIF);
}

#if (ADC_CONVERSION_FORM == LEFT_ADJUSTED) //disable 8bit mode if the configuration is left adjusted
//this function converts to digital in 8bits mode and ignores last two bits
u8 ADC_u8Convert8bits(void)
{
	SET_BIT(ADCSRA,ADSC);
	while (GET_BIT (ADCSRA,ADSC) == 1);
	return ADCH;
}
#endif
u16 ADC_u16Convert10bits(void) //this function converts in ADC and returns the result in 10 bits mode
{
#if (ADC_AUTO_TRIGGER_ENABLE == DISABLED)
SET_BIT(ADCSRA,ADSC);
#endif
while (GET_BIT(ADCSRA,ADSC) == 1);

#if (ADC_CONVERSION_FORM == RIGHT_ADJUSTED)

u16 result = 0x00 | ADCL;
return (result | ADCH<<8);

//left adjusted ADLAR=1
#elif(ADC_CONVERSION_FORM == LEFT_ADJUSTED)
u16 result = 0x00|ADCL;
result = result>>6;
return (result | ADCH<<2);
#endif

return 0;
}

#if (ADC_INTERRUPT_ENABLE == ENABLED)
void ADC_SetCallBack(void (* ADC_Complete_Interrupt_ptr)(void)){
	ADCINT_ptr = ADC_Complete_Interrupt_ptr;
}
void __vector_16(void)__attribute((signal,used));
void __vector_16(void) {
	ADCINT_ptr();
}
#elif (ADC_INTERRUPT_ENABLE == DISABLED)


#else
#error "Wrong ADC_INTERRUPT_ENABLE mode selected, please select ENABLED or DISABLED"
#endif