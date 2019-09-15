#pragma once

#define SAMPLE_RATE_HZ 10
#define SLEEP_TIME_MS (1000 / SAMPLE_RATE_HZ)
#include "Factory.hpp"
#include "../application_code/communication/transport_layer/I_Serial_Communication.hpp"
#include "../application_code/control/drone_control.hpp"

#ifdef TARGET
#include "../avr_code/operators.h"
#include <avr/io.h>
#include "../avr_code/communication/transport_layer/UART.hpp"
#include "../FreeRTOS_avr/include/FreeRTOS.h"
#include "../FreeRTOS_avr/include/task.h"
#define COM_TO_PC UART
#define COM_TO_IMU UART

#endif
#ifdef PC

#include <chrono>
#include <ctime>
#include <math.h>
#include "../application_code/communication/transport_layer/UART_fake.hpp"
#include "../application_code/communication/transport_layer/I2C_fake.hpp"
#include "../FreeRTOS_Linux/include/FreeRTOS.h"
#include "../FreeRTOS_Linux/include/task.h"
#include "../FreeRTOS_Linux/include/queue.h"

#include "../FreeRTOS_Linux/include/semphr.h"

#include "Factory.hpp"
#include <stdio.h>
#include <iostream>

#define COM_TO_IMU I2C_fake
#define COM_TO_PC  UART_fake
#define SIMULATION_TIME_MS 2000
#endif

// Component *Application = new Component(0, "Application", "01");
class Tasks : public Component {
public:
Tasks();
    ~Tasks();
    void SetUp_Tasks(Tasks &task);
    I_Serial_Communication<const char *, COM_TO_PC> com_to_computer;
    I_Serial_Communication<int, COM_TO_IMU> com_to_imu;
    Drone_Control drone_controller;

private:
    void ControlSenderTask(void *param);
    static void ControlTask(void *param);
    static void IMUReceiverTask(void *param);

};

