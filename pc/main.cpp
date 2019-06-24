
#include <stdio.h>
#include <iostream>
#include "../application_code/components/Input.hpp"
#include "../application_code/components/Output.hpp"
#include "../application_code/components/Binds.hpp"
template<class T>
void printIO(Input<T> i, Output<T> o);
int main(void)
{
   Input<int> input1;
   Output<int> output2;
   Bind_Output_2_Input(input1, output2);
   printIO(input1, output2);
   output2.SetValue(3);
   printIO(input1, output2);

   #ifdef BUILD
	printf("heeej");
	#endif
   printf("test");
   printf("PC\n\r");
}
template<class T>
void printIO(Input<T> i, Output<T> o) {
   std::cout << "Output: " << o.GetValue() << std::endl;
   std::cout << "Input: " << i.GetValue() << std::endl;
}


