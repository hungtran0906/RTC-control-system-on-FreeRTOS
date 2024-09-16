/*
 * led_effectt.c
 *
 *  Created on: Sep 15, 2024
 *      Author: Acer
 */


#include "main.h"
#ifndef timer_h
#define timer_h
#include "FreeRTOS.h"
#include "timers.h"
extern TimerHandle_t handle_led_timer[4];
#endif

static void led_effect_stop(void) {
	for (int i = 12; i < 16; i++)
		xTimerStop(handle_led_timer[i], portMAX_DELAY);
}
static int led_effect(int n) {
	led_effect_stop();
	xTimerStart(handle_led_timer[n], portMAX_DELAY);
}
static void turn_off_all_led(void) {
	for (int i = 12; i < 16; i++)
		HAL_GPIO_WritePin(GPIOD, 1 << i, 0);
}
static void turn_on_all_led(void) {
	for (int i = 12; i < 16; i++)
		HAL_GPIO_WritePin(GPIOD, 1 << i, 1);
}
static void turn_on_even_led(void) {
	for (int i = 12; i < 16; i++) {
		if (i % 2 == 0)
			HAL_GPIO_WritePin(GPIOD, 1 << i, 1);
		else
			HAL_GPIO_WritePin(GPIOD, 1 << i, 0);
		;
	}
}
static void turn_on_odd_led(void) {
	for (int i = 12; i < 16; i++) {
		if (i % 2 == 1)
			HAL_GPIO_WritePin(GPIOD, 1 << i, 1);
		else
			HAL_GPIO_WritePin(GPIOD, 1 << i, 0);
		;
	}
}

static void led_effect1(void) {
	static int flag = 1;
	(flag ^= 1) ? turn_off_all_led() : turn_on_all_led();
}
static void led_effect2(void) {
	static int flag = 1;
	(flag ^= 1) ? turn_on_odd_led() : turn_on_even_led();
}
static void led_effect3(void) {
	for (int i = 12; i < 16; i++) {
		HAL_GPIO_TogglePin(GPIOD, 1 << i);
		HAL_Delay(50);
		HAL_GPIO_TogglePin(GPIOD, 1 << i);

	}
}
static void led_effect4(void) {
	for (int i = 15; i > 11; i--) {
		HAL_GPIO_TogglePin(GPIOD, 1 << i);
		HAL_Delay(50);
		HAL_GPIO_TogglePin(GPIOD, 1 << i);

	}
}
