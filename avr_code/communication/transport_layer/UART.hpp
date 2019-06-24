#include "I_Serial_Communication.hpp" 
#include "../../../application_code/components/Input.hpp"
#include <stdio.h>
class UART : public I_Serial_Communication<const char *> {
public:
    UART();
    ~UART(){};
    void Send_Data(const char *);
    void Receive_Data(const char *);
};