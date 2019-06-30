
#include <stdio.h>
#include <iostream>
#include "../application_code/components/Input.hpp"
#include "../application_code/components/Output.hpp"
#include "../application_code/components/Binds.hpp"
#include "../FreeRTOS_Linux/include/FreeRTOS.h"
#include "../FreeRTOS_Linux/include/task.h"


template<class T>
void printIO(Input<T> i, Output<T> o);

void blinkLED(void* parameter)
{
	for (;;)
	{
		std::cout << "BlinkTask" << std::endl;
      vTaskDelay(1000);
   }
}

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
   printf("PC\n\r");
   	// CREATE BLINKER TASK
	xTaskCreate(blinkLED, "Print", configMINIMAL_STACK_SIZE, NULL, 7, NULL );

	// START SCHELUDER
	vTaskStartScheduler();


}
template<class T>
void printIO(Input<T> i, Output<T> o) {
   std::cout << "Output: " << o.GetValue() << std::endl;
   std::cout << "Input: " << i.GetValue() << std::endl;
}


