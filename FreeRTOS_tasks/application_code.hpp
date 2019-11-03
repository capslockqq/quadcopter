#pragma once
#include "../application_code/components/Component.hpp"
#include "../application_code/communication/transport_layer/I_Serial_Communication.hpp"
#include "../application_code/control/drone_control.hpp"
#include "../application_code/components/Parameter.hpp"
#ifdef TARGET
#include "../avr_code/operators.h"
#include <avr/io.h>
#include "../avr_code/communication/transport_layer/UART.hpp"

#define COM_TO_PC UART
#define COM_TO_IMU UART

#endif

#ifdef PC

#include <chrono>
#include <ctime>
#include <math.h>
#include "../application_code/communication/transport_layer/UART_fake.hpp"
#include "../application_code/communication/transport_layer/I2C_fake.hpp"


#include <stdio.h>
#include <iostream>

#define COM_TO_IMU I2C_fake
#define COM_TO_PC  UART_fake

#endif

class Application_code : public Component {
public:
    Application_code(const char* name, const char * id);
    virtual ~Application_code(){};
    void Update();
    I_Serial_Communication<const char *, COM_TO_PC> com_to_computer;
    Drone_Control drone_controller;

    Parameter<int> _param;
    Parameter<float> _param2;
    Parameter<double> _param3;
    Parameter<int> _param4;
private:
    
};