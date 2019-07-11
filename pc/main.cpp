
#include <stdio.h>
#include <iostream>

#include "../application_code/components/Input.hpp"
#include "../application_code/components/Output.hpp"
#include "../application_code/components/Component.hpp"

#include "../application_code/components/Binds.hpp"
#include "../FreeRTOS_tasks/tasks.hpp"
#include "../application_code/communication/transport_layer/UART_fake.hpp"

template <class T>
void printIO(Input<T> i, Output<T> o);


int main(void)
{
   //Creating Tasks
   Component root;
   UART_fake lol(&root, "UART", "01");
   lol.Send_Data("Sending UART DATA \n\r");
   Output<const char *> output(&root, "Output", "01");
   output.SetValue("Hej");
   Bind_Input_2_Output(lol.ip_data, output);
   std::cout << lol.ip_data.GetValue() << std::endl;
   output.SetValue("DILLER SVANS");
   std::cout << lol.ip_data.GetValue() << std::endl;
   SetUp_Tasks();
   return 0;
}
template <class T>
void printIO(Input<T> i, Output<T> o)
{
   std::cout << "Output: " << o.GetValue() << std::endl;
   std::cout << "Input: " << i.GetValue() << std::endl;
}
