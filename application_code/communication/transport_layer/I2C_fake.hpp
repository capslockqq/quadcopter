#pragma once
#include "I_Serial_Communication.hpp"
#include "../../components/Component.hpp"
class I2C_fake : public I_Serial_Communication<int, I2C_fake> {
public:
    I2C_fake(Component *parent, const char *name, const char *id);
    virtual ~I2C_fake();
    void Send_Data();
    void Receive_Data();
    void Update(int);
};