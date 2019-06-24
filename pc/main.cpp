
#include <stdio.h>
#include <iostream>
#include "../application_code/components/Input.hpp"
#include "../application_code/components/Output.hpp"
#include "../application_code/communication/transportation/UART.hpp"
#include "../application_code/control/Binds.hpp"
template<class T>
void printIO(Input<T> i, Output<T> o);
int main(void)
{
   UART hej;
   Input<bool> input1;
   Output<bool> output2;
   printIO(input1, output2);
   Bind_Output_2_Input(input1, output2);
   printIO(input1, output2);
   output2.SetValue(true);
   printIO(input1, output2);
   

   printf("test");
   printf("PC\n\r");
}
template<class T>
void printIO(Input<T> i, Output<T> o) {
   std::cout << "Output: " << o.GetValue() << std::endl;
   std::cout << "Input: " << i.GetValue() << std::endl;
}


