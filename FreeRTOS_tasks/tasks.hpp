#ifdef PC
#include "../FreeRTOS_Linux/include/FreeRTOS.h"
#include "../FreeRTOS_Linux/include/task.h"
#include <stdio.h>
#include <iostream>
#define SIMULATION_TIME_MS 1000
#endif
#ifdef TARGET
#include <avr/io.h>
#include "../FreeRTOS_avr/include/FreeRTOS.h"
#include "../FreeRTOS_avr/include/task.h"
#endif

#define SAMPLE_RATE_HZ 5
#define SLEEP_TIME_MS (1000/SAMPLE_RATE_HZ)


void ControlTask(void *param);
void SetUp_Tasks();
