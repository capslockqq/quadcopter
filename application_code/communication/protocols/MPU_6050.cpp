#include "MPU_6050.hpp"

MPU_6050::MPU_6050(I_Serial_Communication<const char*, MPU_6050> *SerialCommunication)
{
    _serialCommunication = (SerialCommunication) ? _serialCommunication : nullptr;
}

MPU_6050::~MPU_6050()
{   
}

void MPU_6050::Send_Data(const char *data)
{
}

void MPU_6050::Receive_Data(const char *data)
{
}