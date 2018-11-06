/*
 * led_driver.h
 *
 *  Created on: Oct 26, 2018
 *      Author: RamboLaptop
 */

#ifndef LED_DRIVER_H_
#define LED_DRIVER_H_

#include "peripherals.h"

extern uint32_t led_bit_count_g;

//MACROS
#define NUM_BITS_PER_LED 24
#define NUM_LEDS_ON_STRIP 1
#define NUM_BITS_PER_STRIP (NUM_BITS_PER_LED * NUM_LEDS_ON_STRIP)

//prototype declarations
void update_leds(void);
void init_led_data(void);

//Structs

#endif /* LED_DRIVER_H_ */
