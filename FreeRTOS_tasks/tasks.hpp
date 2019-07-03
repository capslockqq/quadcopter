#ifndef TASKS_HPP
#define TASKS_HPP





#ifdef TARGET
#include "../avr_code/operators.h"
#include <avr/io.h>
#include "../avr_code/communication/transport_layer/UART.hpp"
#include "../FreeRTOS_avr/include/FreeRTOS.h"
#include "../FreeRTOS_avr/include/task.h"


#endif

#include "../application_code/communication/transport_layer/I_Serial_Communication.hpp"

#ifdef PC
#include "../application_code/communication/transport_layer/UART_fake.hpp"
#include "../FreeRTOS_Linux/include/FreeRTOS.h"
#include "../FreeRTOS_Linux/include/task.h"
#include <stdio.h>
#include <iostream>
#define SIMULATION_TIME_MS 1000



#endif


#define SAMPLE_RATE_HZ 5
#define SLEEP_TIME_MS (1000/SAMPLE_RATE_HZ)



void ControlTask(void *param);
void SetUp_Tasks();

#endif