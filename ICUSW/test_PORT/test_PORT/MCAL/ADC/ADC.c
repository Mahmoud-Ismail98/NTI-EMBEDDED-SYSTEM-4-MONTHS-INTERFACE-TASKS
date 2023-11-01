/*
 * ADC.c
 *
 * Created: 10/22/2023 11:55:32 AM
 *  Author: FADY
 */
 #include "../../SERVICES/Std_types.h"
#include "../../SERVICES/Bit_utils.h"
#include "Adc.h"
#include "Adc_prv.h"


void ADC_voidinit() {
	/* Select the Voltage reference AVCC */
	CLR_BIT(ADMUX,ADMUX_REFS1);
	SET_BIT(ADMUX,ADMUX_REFS0);

	/* Select the right Adjustment */
	CLR_BIT(ADMUX,ADMUX_ADLAR);
	/* Select The Prescaler value => 64 */
	SET_BIT(ADCSRA,ADCSRA_ADPS2);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	CLR_BIT(ADCSRA,ADCSRA_ADPS0);

	/* Enable ADC peripheral */
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}

ADC_ErrorStatus ADC_StartConverstion(u8 Copy_u8Channel, pu16 Ptr_addData) {
    ADC_ErrorStatus Loc_Status = A_OK;
    if ((Copy_u8Channel > 7) || (Copy_u8Channel < 0)) {
        Loc_Status = ADC_WrongChannel;
    } else if (Ptr_addData == NULL) {
        Loc_Status = ADC_NULLPTR;
    } else {
       	/* Clear The Channel Number bits */
		ADMUX &= 0b11100000;
		/* Select The Channel Number */
		ADMUX |= Copy_u8Channel;

		/* Start Conversion */
		SET_BIT(ADCSRA,ADCSRA_ADSC);

		/* Polling on the flag */
		while(GET_BIT(ADCSRA,ADCSRA_ADIF) == 0);

		/* Clear Flag */
		SET_BIT(ADCSRA,ADCSRA_ADIF);

        *Ptr_addData = ADC; 
        
    }
    return Loc_Status;
}

void ADC_Disable() {
    CLR_BIT(ADCSRA, ADCSRA_ADEN);
}
