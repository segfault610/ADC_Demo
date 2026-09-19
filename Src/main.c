#include <stdio.h>
#include "signals.h"
#include "uart.h"
#include "adc.h"

extern float _5hz_signal[HZ_5_SIG_LEN];
float g_in_sig_sample;
uint32_t adc_val;

static void plot_input_signal(void);
static void pseudo_dly(int dly);

int main()
{

	/*Enable Floating Point Unit :  Enable CP10 and CP11 full access*/
	SCB->CPACR |= (1U<<20);
	SCB->CPACR |= (1U<<21);
	SCB->CPACR |= (1U<<22);
	SCB->CPACR |= (1U<<23);

	/*Initialize the uart*/
	uart2_tx_init();
	adc1_init();
	while(1)
	{
		//plot_input_signal();
		adc_val = adc1_read();
		printf("%d\r\n", adc_val);
		pseudo_dly(3000);
	}
}

static void plot_input_signal(void)
{
	int i;
	for( i = 0; i < HZ_5_SIG_LEN; i++)
	{
		g_in_sig_sample = _5hz_signal[i];
		printf("%f\n\r", g_in_sig_sample);
		pseudo_dly(90000);
	}
}

static void pseudo_dly(int dly) {
	for (int i = 0; i < dly; i++);
}
