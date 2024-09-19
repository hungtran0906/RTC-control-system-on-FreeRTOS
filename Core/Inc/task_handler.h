/*
 * task_handler.h
 *
 *  Created on: Sep 18, 2024
 *      Author: User
 */

#ifndef INC_TASK_HANDLER_H_
#define INC_TASK_HANDLER_H_
#include "main.h"
typedef struct{
	uint8_t payload[10];
	uint32_t len;
}command_t;

typedef enum{
	sMainMenu = 0,
	sLedEffect ,
	sRtcMenu,
	sRtcTimeConfig,
	sRtcDateConfig,
	sRtcReport,
}state_t;
extern xTaskHandle handle_cmd_task;
extern xTaskHandle handle_menu_task;
extern xTaskHandle handle_led_task;
extern xTaskHandle handle_print_task;
extern xTaskHandle handle_rtc_task;
extern QueueHandle_t q_data;
extern QueueHandle_t q_print;
extern TimerHandle_t rtc_timer;
extern UART_HandleTypeDef huart2;

void menu_task(void *parameter);
void cmd_handler_task(void *parameter);
void print_task(void *paramter);
void led_task(void *parameter);
void rtc_task(void *parameter);
uint8_t getNumber(uint8_t *p, int len);
void process_command(command_t *cmd);
int extract_command(command_t *cmd);


#endif /* INC_TASK_HANDLER_H_ */
