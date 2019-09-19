#include "tasks.hpp"
Tasks::Tasks() :
Component(this, "Tasks", "Tsk")
// ,com_to_computer(this, "Com to PC", "ComPC")
// ,com_to_imu(this, "Com to IMU", "02")
// ,drone_controller("Drone controller", "DRONE")
,application("Application", "App")
{
} 

Tasks::~Tasks() {
    
}

void Tasks::ControlSenderTask(void *param) {
    
}

#ifdef PC
float Tasks::m_simulation_time_seconds;
std::string Tasks::m_path_to_test_folder;
#endif
void Tasks::ControlTask(void *param) {

  Tasks* task = (Tasks*)param;
  
  double i = 1;
  double result = 0;
  while (1)
  {
    vTaskDelay(SLEEP_TIME_MS);
    task->application.Update();
    
    #ifdef PC
    UpdateOutputs();
    #endif
    #ifdef PC 
    static int ticks = 0;
    ticks++;
     if (ticks >= SAMPLE_FREQUENCY*m_simulation_time_seconds) {
       std::cout << "-----------------------Ending simulation-----------------------" << std::endl;
       std::cout << "Ticks: " << ticks << std::endl;
       std::cout << "Simulation time: " << ticks/SAMPLE_FREQUENCY << std::endl;
       std::cout << "---------------------------------------------------------------" << std::endl;
       std::cout << "Simulation folder: " << m_path_to_test_folder << std::endl;
    
       vTaskEndScheduler();
       return;
     }
    #endif

  }
}

void Tasks::IMUReceiverTask(void *param) {
    
}
#ifdef PC
void Tasks::UpdateOutputs() {
  OutputObserver *L = OutputObserver::GetInstance();
  auto list = L->GetUpdate();
  for (auto i : list) {
    if (std::get<1>(i) == "bool") {
      Output<bool>*tmp = (Output<bool>*)std::get<0>(i); 
      tmp->Update_Log();;
    }
      
    else if (std::get<1>(i) == "float") {
      Output<float>*tmp = (Output<float>*)std::get<0>(i); 
      tmp->Update_Log();;
    }
    else if (std::get<1>(i) == "double") {
      Output<double>*tmp = (Output<double>*)std::get<0>(i); 
      tmp->Update_Log();;
    }
    else if (std::get<1>(i) == "int") {
      Output<int>*tmp = (Output<int>*)std::get<0>(i); 
      tmp->Update_Log();;
    }
    else std:cout << "hel" << std::endl;
    
  }
}
#endif

void Tasks::SetUp_Tasks(Tasks &task) {
  xTaskCreate(this->ControlTask, "Controller",    configMINIMAL_STACK_SIZE, this, 7, NULL);
  // START SCHELUDER
  vTaskStartScheduler();
  vTaskEndScheduler();  
}

