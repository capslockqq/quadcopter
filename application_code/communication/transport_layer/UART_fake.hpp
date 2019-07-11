#pragma once
#include "I_Serial_Communication.hpp"
#include "../../components/Component.hpp"
class UART_fake : public I_Serial_Communication<const char *> {
public:
    UART_fake(Component *parent, const char *name, const char *id);
    ~UART_fake();
    void Send_Data(const char *);
    void Receive_Data(const char *);
};
