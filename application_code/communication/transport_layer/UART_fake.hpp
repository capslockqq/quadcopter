#pragma once
#include "I_Serial_Communication.hpp"
#include "../../components/Component.hpp"
class UART_fake : public I_Serial_Communication<const char *, UART_fake> {
public:
    UART_fake(Component *parent, const char *name, const char *id);
    ~UART_fake();
    void Send_Data();
    void Receive_Data();
    void Update(const char *);
};
