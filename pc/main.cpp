
#include <stdio.h>
#include <iostream>

#include "../application_code/components/Input.hpp"
#include "../application_code/components/Output.hpp"
#include "../application_code/components/Component.hpp"

#include "../application_code/components/Binds.hpp"
#include "../FreeRTOS_tasks/tasks.hpp"
#include "../application_code/components/Singleton.hpp"
#include "../application_code/components/OutputObserver.hpp"
#include "../application_code/interface.hpp"
#include "../application_code/implementation.hpp"
#include "../application_code/components/type_name.hpp"
template <class T>
void printIO(Input<T> i, Output<T> o);

SingletonLogging *SingletonLogging::instance = 0;
OutputObserver *OutputObserver::instance = 0;
int main(int argc, char * argv[])
{
   //Clearing ID file
   std::string command = "rm ";
   std::string path = "*.txt";
   if (system(command.append(path).c_str())) {
      std::cout << "txt files deleted" << std::endl;
   }
   SingletonLogging *S = SingletonLogging::GetInstance();
   vector<string> ids_to_log;
   std::cout << "argc: " << argc << std::endl;
   for (int i = 2; i < argc; i++) {
      ids_to_log.push_back(argv[i]);
   }
   S->SetData(ids_to_log);
   
   OutputObserver *L = OutputObserver::GetInstance();

   Tasks tasks;

   #ifdef PC
   if (argv[1] != NULL) {
      std::string simulation_time(argv[1]);
      tasks.m_simulation_time_seconds = std::stof(simulation_time);
   }
   else {
      tasks.m_simulation_time_seconds = 1.0f;
   }

   tasks.SetUp_Tasks(tasks);
   
   #endif
   
   return 0;
}
template <class T>
void printIO(Input<T> i, Output<T> o)
{
   std::cout << "Output: " << o.GetValue() << std::endl;
   std::cout << "Input: " << i.GetValue() << std::endl;
}
