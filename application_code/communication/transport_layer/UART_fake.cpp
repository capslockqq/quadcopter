#include "UART_fake.hpp"
#include <iostream>
UART_fake::UART_fake(Component *parent, const char *name, const char *id) :
I_Serial_Communication(this , name, id)
{

}

UART_fake::~UART_fake() {
    
}

void UART_fake::Update(const char *data) {
    op_data.SetValue(data);
    // this->Send_Data();
}

void UART_fake::Send_Data() {
    std::cout << (op_data.GetValue()) << std::endl;
}

void UART_fake::Receive_Data() {
    
}

