#ifndef TASKS_HPP
#define TASKS_HPP

#define SAMPLE_RATE_HZ 100
#define SLEEP_TIME_MS (1000 / SAMPLE_RATE_HZ)
#include "../application_code/communication/transport_layer/I_Serial_Communication.hpp"


#ifdef TARGET
#include "../avr_code/operators.h"
#include <avr/io.h>
#include "../avr_code/communication/transport_layer/UART.hpp"
#include "../FreeRTOS_avr/include/FreeRTOS.h"
#include "../FreeRTOS_avr/include/task.h"

#endif
#ifdef PC
#include <chrono>
#include <ctime>
#include "../application_code/communication/transport_layer/UART_fake.hpp"
#include "../application_code/communication/transport_layer/I2C_fake.hpp"
#include "../FreeRTOS_Linux/include/FreeRTOS.h"
#include "../FreeRTOS_Linux/include/task.h"
#include <stdio.h>
#include <iostream>
#define SIMULATION_TIME_MS 1000

void SimulationTask(void *param);

#endif

void CheckToStopSimulation(const int ticks);

void ControlSenderTask(void *param);
void ControlTask(void *param);
void BroadcasterTask(void *param);

void SetUp_Tasks();

#endif