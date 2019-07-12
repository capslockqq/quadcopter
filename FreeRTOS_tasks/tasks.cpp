#include "tasks.hpp"
Component root;
#ifdef TARGET
I_Serial_Communication<const char *> *uart = new UART(&root, "UART", "01");
#endif
#ifdef PC
#include <chrono>
#include <ctime>
#include "../application_code/components/Component.hpp"
I_Serial_Communication<const char *> *uart = new UART_fake(&root, "Fake UART", "01");

void SimulationTask(void *param)
{
  while(1) {
    static int ticks = 0;
    ticks++;
    auto start = std::chrono::system_clock::now();
    vTaskDelay(SLEEP_TIME_MS);
    auto end = std::chrono::system_clock::now();
    static std::chrono::duration<double> elapsed_seconds = end-start;
    elapsed_seconds += end-start;
    if (ticks >= SIMULATION_TIME_MS/SLEEP_TIME_MS) {
      std::cout << elapsed_seconds.count()/ticks << std::endl;
      std::cout << SIMULATION_TIME_MS/SLEEP_TIME_MS << std::endl;

      vTaskEndScheduler();
      return;
    }
  }
}
#endif

void ControlSenderTask(void *param)
{

}

void ControlTask(void *param)
{
  while (1)
  {
    vTaskDelay(SLEEP_TIME_MS);
    uart->Update("Hello");
  }
}

void SetUp_Tasks()
{

  xTaskCreate(ControlTask, "Print", configMINIMAL_STACK_SIZE, NULL, 7, NULL);
  #ifdef PC 
  xTaskCreate(SimulationTask, "Simu", configMINIMAL_STACK_SIZE, NULL, 9, NULL);
  #endif
  // START SCHELUDER
  vTaskStartScheduler();
  vTaskEndScheduler();
}