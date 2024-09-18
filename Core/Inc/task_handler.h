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
	sRtcDataConfig,
	sRtcReport,
}state_t;

void menu_task(void *parameter);
void cmd_handler_task(void *parameter);
void print_task(void *paramter);
void led_task(void *parameter);
void rtc_task(void *parameter);


#endif /* INC_TASK_HANDLER_H_ */
