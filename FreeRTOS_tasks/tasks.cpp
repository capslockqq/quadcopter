#include "tasks.hpp"
Tasks::Tasks() :
Component(this, "Tasks", "01")
,com_to_computer(this, "Com to PC", "01")
,com_to_imu(this, "Com to IMU", "02")
,drone_controller("Drone controller", "03")
{
} 

Tasks::~Tasks() {
    
}

void Tasks::ControlSenderTask(void *param) {
    
}

void Tasks::ControlTask(void *param) {

  Tasks* task = (Tasks*)param;
  int ticks = 0;
  double i = 1;
  double result = 0;
  while (1)
  {
    vTaskDelay(SLEEP_TIME_MS);
    task->drone_controller.Update();
    task->drone_controller.drone_pitch_controller.ip_setpoint.SetValue(result);
    result = i*i;
    i++;
    // com_to_imu->Update(3);
    #ifdef PC 
    ticks++;
    if (ticks >= SIMULATION_TIME_MS/SLEEP_TIME_MS) {
        std::cout << ticks << std::endl;

      vTaskEndScheduler();
      return;
    }
    #endif
    task->com_to_computer.Update("12");
    task->com_to_imu.Update(12);
  }
}

void Tasks::IMUReceiverTask(void *param) {
    
}

void Tasks::SetUp_Tasks(Tasks &task) {
  xTaskCreate(this->ControlTask, "Controller", configMINIMAL_STACK_SIZE, this, 7, NULL);
  // START SCHELUDER
  vTaskStartScheduler();
  vTaskEndScheduler();  
}
