#ifdef PC
#include "../FreeRTOS_Linux/include/FreeRTOS.h"
#include "../FreeRTOS_Linux/include/task.h"
#endif
#ifdef TARGET
#include "../FreeRTOS_avr/include/FreeRTOS.h"
#include "../FreeRTOS_avr/include/task.h"
#endif

#include <stdio.h>


void *Test1(void *param);
void *Test2(void *param);
void *Test3(void *param);
void *Test4(void *param);