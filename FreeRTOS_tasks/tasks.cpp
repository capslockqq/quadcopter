#include "tasks.hpp"
#include "Factory.hpp"
Component root;
#ifdef TARGET
//I_Serial_Communication<const char *> *uart = new UART(&root, "UART", "01");
#endif
#ifdef PC
//I_Serial_Communication<const char *> *uart = new UART_fake(&root, "Fake UART", "01");

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
  Factory<const char*, int> factory(&root, "Factory", "01");
  I_Serial_Communication<const char*> *com_to_computer = factory.get_data_com_to_computer();
  I_Serial_Communication<int> *com_to_imu              = factory.get_data_com_to_IMU();
  Drone_Control drone_controller("Drone Controller", "01");
  while (1)
  {
    vTaskDelay(SLEEP_TIME_MS);
    drone_controller.Update();
    com_to_computer->Update("Hej");
    
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