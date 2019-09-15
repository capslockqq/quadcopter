#pragma once
#ifdef TARGET
#include "../../../avr_code/operators.h"
#endif
#include "../../../application_code/components/Input.hpp"
#include "../../../application_code/components/Output.hpp"
#include "../../../application_code/components/Component.hpp"
template<class T, class implementation>
class I_Serial_Communication : public Component{
public:
    I_Serial_Communication(Component *parent, const char *name, const char *id);
    void Update(const char * data){
        static_cast<implementation*>(this)->Update(data);
    };
    void Update(int data){
        static_cast<implementation*>(this)->Update(data);
    };
    Input<T> ip_data;
    Output<T> op_data;

private:
    void Send_Data(){
        static_cast<implementation*>(this)->Send_Data();
    }
    void Receive_Data() {
        static_cast<implementation*>(this)->Send_Data();

    }
};
template<class T, class implementation>
I_Serial_Communication<T, implementation>::I_Serial_Communication(Component *parent, const char *name, const char *id) :
 Component(parent, name, id)
,ip_data(this, (const char *)"Serial input", (const char *)"01")
,op_data(this, (const char *)"Serial output",(const char *)"02")
{
    
}

template<class T>
class I_Serial_Communication2 : public Component{
public:
    I_Serial_Communication2(Component *parent, const char *name, const char *id);
    virtual void Update(const char * data){};
    virtual void Update(int data){};
    Input<T> ip_data;
    Output<T> op_data;

private:
    virtual void Send_Data() = 0;

    virtual void Receive_Data() = 0;
};
template<class T>
I_Serial_Communication2<T>::I_Serial_Communication2(Component *parent, const char *name, const char *id) :
 Component(parent, name, id)
,ip_data(this, (const char *)"Serial input", (const char *)"01")
,op_data(this, (const char *)"Serial output",(const char *)"02")
{
    
}