#include "I_Serial_Communication.hpp"
#include <stdio.h>
class UART : public I_Serial_Communication {
public:
    UART();
    ~UART(){};
    void Send_Data(const char *);
    void Receive_Data(const char *);
    bool dummy();
};