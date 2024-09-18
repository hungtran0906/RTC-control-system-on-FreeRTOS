/*
 * rtc.h
 *
 *  Created on: Sep 18, 2024
 *      Author: User
 */

#ifndef INC_RTC_H_
#define INC_RTC_H_

#include "main.h"

extern RTC_HandleTypeDef hrtc;
extern QueueHandle_t q_print;
void show_time_data_itm(void);
void show_time_date(void);
void rtc_configure_time(RTC_TimeTypeDef *time);
void rtc_configure_date(RTC_DateTypeDef *date);
int validate_rtc_information(RTC_TimeTypeDef *time, RTC_DateTypeDef *date);

#endif /* INC_RTC_H_ */
