
#include <stdio.h>
#include <iostream>

#include "../application_code/components/Input.hpp"
#include "../application_code/components/Output.hpp"
#include "../application_code/components/Component.hpp"

#include "../application_code/components/Binds.hpp"
#include "../FreeRTOS_tasks/tasks.hpp"


template <class T>
void printIO(Input<T> i, Output<T> o);


int main(void)
{
   SetUp_Tasks();
   return 0;
}
template <class T>
void printIO(Input<T> i, Output<T> o)
{
   std::cout << "Output: " << o.GetValue() << std::endl;
   std::cout << "Input: " << i.GetValue() << std::endl;
}
