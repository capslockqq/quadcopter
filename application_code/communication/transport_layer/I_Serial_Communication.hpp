#pragma once
#ifdef TARGET
#include "../../../avr_code/operators.h"
#endif
#include "../../../application_code/components/Input.hpp"
#include "../../../application_code/components/Output.hpp"
template<class T>
class I_Serial_Communication {
public:
    virtual void Send_Data(T data)      = 0;
    virtual void Receive_Data(T data)   = 0;

    Input<T> ip_data;
    Output<T> op_data;
};