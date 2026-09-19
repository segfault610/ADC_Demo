/*
 * adc.h
 *
 *  Created on: Sep 19, 2026
 *      Author: jonny
 */

#ifndef ADC_H_
#define ADC_H_

#include "stm32f4xx.h"

void adc1_init(void);
uint32_t adc1_read(void);

#endif /* ADC_H_ */
