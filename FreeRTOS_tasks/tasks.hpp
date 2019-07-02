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



void *Test1(void *param);
void *Test2(void *param);
void *Test3(void *param);
void *Test4(void *param);
