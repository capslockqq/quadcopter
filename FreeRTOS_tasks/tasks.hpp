#pragma once
#include "../application_code/components/Component.hpp"
#include "application_code.hpp"
#define SAMPLE_FREQUENCY 100 // Hz

#ifdef PC
#define SLEEP_TIME_MS 0.0001f
#include "../FreeRTOS_Linux/include/FreeRTOS.h"
#include "../FreeRTOS_Linux/include/task.h"
#include "../FreeRTOS_Linux/include/queue.h"
#include "../FreeRTOS_Linux/include/semphr.h"
#include "../application_code/components/Singleton.hpp"
#include "../application_code/components/OutputObserver.hpp"
#include "../application_code/components/type_name.hpp"


#endif

#ifdef TARGET
#define SLEEP_TIME_MS (1000 / SAMPLE_FREQUENCY)
#include "../FreeRTOS_avr/include/FreeRTOS.h"
#include "../FreeRTOS_avr/include/task.h"

#endif

// Component *Application = new Component(0, "Application", "01");
class Tasks : public Component {
public:
Tasks();
    ~Tasks();
    void SetUp_Tasks(Tasks &task);
    #ifdef PC
    static float m_simulation_time_seconds;
    static std::string m_path_to_test_folder;
    #endif
private:
    void ControlSenderTask(void *param);
    static void ControlTask(void *param);
    static void IMUReceiverTask(void *param);
    #ifdef PC
    static void UpdateOutputs();
    #endif
    Application_code application;
};

