#include "../../../application_code/components/Input.hpp"
#include "../../../application_code/components/Input.hpp"
template<class T>
class I_Serial_Communication {
public:
    virtual void Send_Data(T)      = 0;
    virtual void Receive_Data(T)   = 0;
};