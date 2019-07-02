#include "UART_fake.hpp"
#include <iostream>
UART_fake::UART_fake() {

}

UART_fake::~UART_fake() {
    
}

void UART_fake::Send_Data(const char * data) {
    std::cout << (data) << std::endl;
}

void UART_fake::Receive_Data(const char * data) {
    
}