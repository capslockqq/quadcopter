#include "tasks.hpp"
int counter = 0;
void *Test1(void *param) {
    while(1) {
      counter++;
      std::cout << "Test1" << std::endl;
      vTaskDelay(1000);
      if (counter >= 4) {
          vTaskEndScheduler();
          return NULL;
      }
   }
}
