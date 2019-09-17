#include "I2C_fake.hpp"
I2C_fake::I2C_fake(Component *parent, const char *name, const char *id) :
I_Serial_Communication(parent, name, id)
{

}

I2C_fake::~I2C_fake() {
    
}

void I2C_fake::Send_Data() {
    
}

void I2C_fake::Receive_Data() {
    
}

void I2C_fake::Update(int data) {
    op_data.SetValue(data);
}
