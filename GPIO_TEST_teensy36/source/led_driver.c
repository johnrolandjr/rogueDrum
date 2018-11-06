/*
 * led_driver.c
 *
 *  Created on: Oct 26, 2018
 *      Author: RamboLaptop
 */
#include "led_driver.h"

uint8_t screen_para_out[NUM_BITS_PER_STRIP];

void init_led_data(void)
{
	for(int a=0; a<NUM_BITS_PER_STRIP; a++)
	{
		screen_para_out[a] = 0xae;
	}
}

void update_leds(void)
{
	//begin led data transfer by setting the outputs high, and begin the tpm
	led_bit_count_g = 0;
	TPM_StartTimer(DUAL_PWM_PERIPHERAL, kTPM_SystemClock);
	GPIOD->PSOR = 0xFF;
}
