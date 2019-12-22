
#include <stdio.h>
#include <iostream>
#include <string.h>

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
#include "../application_code/components/ParameterWrite.hpp"
SingletonLogging *SingletonLogging::instance = 0;
OutputObserver *OutputObserver::instance = 0;
ParameterWrite *ParameterWrite::instance = 0;
int main(int argc, char * argv[])
{
   Tasks tasks;
   
   //Clearing ID file
   std::string command = "rm ";
   std::string path = "*.txt";
   if (system(command.append(path).c_str())) {
      std::cout << "txt files deleted" << std::endl;
   }
   
   auto unique_ids = Component::get_all_unique_ids_as_map();

   SingletonLogging *S = SingletonLogging::GetInstance();
   ParameterWrite  *paramwrite = ParameterWrite::GetInstance();

   vector<string> ids_to_log;
   bool simulation_story_start = false;
   int param_write_offset = 0;
   
   for (int i = 2; i < argc; i++) {
      std::string argument = argv[i];
      if (argument == "simulation_story" && !simulation_story_start) simulation_story_start = true;
      else if (simulation_story_start) {
         if (param_write_offset % 3 == 0) {
            std::string param_id(argv[i]);
            if (!unique_ids.count(param_id)) {
              std::cout << "____ERROR_____: Could not find parameter ID: " << param_id << std::endl;
              return 1;
            }
            std::string time(argv[i+1]);
            std::string value(argv[i+2]);
            paramwrite->simlation_param_write[param_id] = make_tuple(std::stof(time), std::stof(value));
         }
         param_write_offset++;
      }
      else {
         ids_to_log.push_back(argv[i]);
      }
   }
   
   S->SetData(ids_to_log);
   
   OutputObserver *L = OutputObserver::GetInstance();
   
   
   if (argv[1] != NULL) {
      std::string simulation_time(argv[1]);
      tasks.m_simulation_time_seconds = std::stof(simulation_time);
   }
   else {
      tasks.m_simulation_time_seconds = 1.0f;
   }
   
   tasks.SetUp_Tasks(tasks);
 
   for (auto t : paramwrite->simlation_param_write) {
      std::cout << t.first << ": {time: " << std::get<0>(t.second) << " value: " << std::get<1>(t.second) << "}" << std::endl;
   }
   return 0;
}

