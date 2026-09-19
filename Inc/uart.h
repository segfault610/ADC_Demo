/*
 * uart.h
 *
 *  Created on: Sep 18, 2026
 *      Author: jonny
 */

#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include "stm32f4xx.h"
#define SYSFREQ			16000000
#define PERIPHCLK		SYSFREQ

void uart2_tx_init();

#endif /* UART_H_ */
