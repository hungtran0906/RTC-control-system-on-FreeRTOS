/*
 * task_handler.c
 *
 *  Created on: Sep 18, 2024
 *      Author: User
 */
#include "main.h"
#include "task_handler.h"
void menu_task(void *parameter) {
	uint32_t cmd_addr;

	command_t *cmd;

	int option;

	const char *msg_menu = "\n========================\n"
							"|         Menu         |\n"
							"========================\n"
							"LED effect    ----> 0\n"
							"Date and time ----> 1\n"
							"Exit          ----> 2\n"
							"Enter your choice here : ";
	while(1){
		xQueueCRSend(q_print, &msg_menu, portMAX_DELAY);

		xTaskNotifyWait(0, 0, &cmd_addr, portMAX_DELAY);

	}
}
void cmd_handler_task(void *parameter) {

}
void print_task(void *paramter) {

}
void led_task(void *parameter) {

}
void rtc_task(void *parameter) {

}

