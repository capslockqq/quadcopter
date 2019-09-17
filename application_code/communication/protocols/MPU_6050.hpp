#pragma once
#include "I_Datalink_Layer.hpp"
#include "../transport_layer/I_Serial_Communication.hpp"

class MPU_6050 : public I_Datalink_Layer
{
public:
    MPU_6050(I_Serial_Communication<const char *, MPU_6050> *serialCommunication);
    ~MPU_6050();

    void Send_Data(const char *data);
    void Receive_Data(const char *data);

private:
    I_Serial_Communication<const char *, MPU_6050> *_serialCommunication;
};