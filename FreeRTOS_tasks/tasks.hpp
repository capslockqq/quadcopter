#ifdef PC
#include "../FreeRTOS_Linux/include/FreeRTOS.h"
#include "../FreeRTOS_Linux/include/task.h"
#include <stdio.h>
#include <iostream>
#define DEBUG (std::cout << "HEEEEEEJ" << std::endl;)

#endif
#ifdef TARGET
#include "../FreeRTOS_avr/include/FreeRTOS.h"
#include "../FreeRTOS_avr/include/task.h"
#endif

#define SAMPLE_RATE_HZ 5
#define SLEEP_TIME_MS (1000/SAMPLE_RATE_HZ)


void *Test1(void *param);
void *Test2(void *param);
void *Test3(void *param);
void *Test4(void *param);
