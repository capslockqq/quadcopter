#include "tasks.hpp"
void *Test1(void *param) {
    while(1) {
        printf("Test1");
        vTaskDelay(1000);
    }
}