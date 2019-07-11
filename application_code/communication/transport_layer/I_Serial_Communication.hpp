#pragma once
#ifdef TARGET
#include "../../../avr_code/operators.h"
#endif
#include "../../../application_code/components/Input.hpp"
#include "../../../application_code/components/Output.hpp"
#include "../../../application_code/components/Component.hpp"
template<class T>
class I_Serial_Communication : public Component{
public:
    I_Serial_Communication(Component *parent, const char *name, const char *id);
    virtual void Send_Data(T data)      = 0;
    virtual void Receive_Data(T data)   = 0;

    Input<T> ip_data;
    Output<T> op_data;
};
template<class T>
I_Serial_Communication<T>::I_Serial_Communication(Component *parent, const char *name, const char *id) :
 Component(parent, name, id)
,ip_data(this, (const char *)"Serial input", (const char *)"01")
,op_data(this, (const char *)"Serial output",(const char *)"02")
{
    
}