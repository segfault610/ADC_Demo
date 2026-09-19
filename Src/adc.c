#include "adc.h"

void adc1_init(void)
{
	// enable clock access to GPIOA
	RCC->AHB1ENR |= (1U<<0);
	// set PA1 to analog mode
	GPIOA->MODER |= (3U<<2); // to write 11 to bits 3 and 2
	// enable clock access to ADC1
	RCC->APB2ENR |= (1U<<8);
	// set conversion sequence i.e. channel number
	ADC1->SQR3 |= (1U<<0); // since we are sampling channel 1
	// set conversion sequence length i.e. no. of conversions
	ADC1->SQR1 = 0x00;
	adc1_start_conversion();
}

void adc1_start_conversion(void)
{
	// enable continuous conversion
	ADC1->CR2 |= (1U<<1);
	// turn on the ADC
	ADC1->CR2 |= (1U<<0);
	// start the conversion
	ADC1->CR2 |= (1U<<30);
}

uint32_t adc1_read(void)
{
	// wait for current conversion to finish
	while (!(ADC1->SR & (1U<<1)));
	// rteurn the data from the register
	return ADC1->DR;
}
