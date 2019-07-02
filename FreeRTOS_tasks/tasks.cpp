#include "tasks.hpp"
int ticks = 0;

void ControlTask(void *param) {

    while(1) {
      
      #ifdef PC
      ticks++;
      std::cout << SLEEP_TIME_MS << std::endl;
      if (ticks >= SIMULATION_TIME_MS/SLEEP_TIME_MS) {
          vTaskEndScheduler();
          return NULL;
      }
      #endif
    vTaskDelay(SLEEP_TIME_MS);

   }
}

void SetUp_Tasks() {
	xTaskCreate(ControlTask, "Print", configMINIMAL_STACK_SIZE, NULL, 7, NULL );

	// START SCHELUDER
	vTaskStartScheduler();
  vTaskEndScheduler();
}