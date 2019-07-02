#include "tasks.hpp"
int counter = 0;
void *Test1(void *param) {
    while(1) {
      
      #ifdef PC
      counter++;
      std::cout << "Test1" << std::endl;
      if (counter >= 4) {
          vTaskEndScheduler();
          return NULL;
      }
      #endif
    vTaskDelay(1000);

   }
}
