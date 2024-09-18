
#include "led_effect.h"

extern TimerHandle_t handle_led_timer[4];
int led_effect_stop(int *n) {
	return xTimerStop(handle_led_timer[*n], 0);
}
int led_effect(int *n) {
	led_effect_stop(n);
	return xTimerStart(handle_led_timer[*n], 0);

}

void led_effect1(void) {
	for (int i = 12; i < 16; i++) {
		if (i % 2 == 0)
			HAL_GPIO_TogglePin(GPIOD, 1 << i);
	}
}
void led_effect2(void) {
	for (int i = 12; i < 16; i++) {
		if (i % 2 == 1)
			HAL_GPIO_TogglePin(GPIOD, 1 << i);
	}
}
void led_effect3(void) {
	for (int i = 12; i < 16; i++) {
		HAL_GPIO_TogglePin(GPIOD, 1 << i);
		HAL_Delay(50);
		HAL_GPIO_TogglePin(GPIOD, 1 << i);

	}
}
void led_effect4(void) {
	for (int i = 15; i > 11; i--) {
		HAL_GPIO_TogglePin(GPIOD, 1 << i);
		HAL_Delay(50);
		HAL_GPIO_TogglePin(GPIOD, 1 << i);

	}
}
