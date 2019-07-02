#include "tasks.hpp"

#ifdef TARGET
I_Serial_Communication<const char *> *uart = new UART();
#endif
#ifdef PC
I_Serial_Communication<const char *> *uart = new UART_fake();
#endif
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

    
    vTaskDelay(1000);
    uart->Send_Data("LOOOOL\0");

   }
}

void SetUp_Tasks() {

	xTaskCreate(ControlTask, "Print", configMINIMAL_STACK_SIZE, NULL, 7, NULL );

	// START SCHELUDER
	vTaskStartScheduler();
  vTaskEndScheduler();
}