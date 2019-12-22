#pragma once
#include "Component.hpp"
#include "ParameterWrite.hpp"
template <class T>
class Parameter : public Component {
public:
    Parameter(Component *parent, const char *name, const char *id, int value);
    Parameter(Component *parent, const char *name, const char *id, float value);
    Parameter(Component *parent, const char *name, const char *id, double value);
    Parameter(Component *parent, const char *name, const char *id, bool value);
    virtual ~Parameter(){}
    ComponentType type(){ return ComponentType::parameter; }
    void SetValue(T val);
    T GetValue();
private:
    T _value;
};

template <class T>
Parameter<T>::Parameter(Component *parent, const char *name, const char *id, int value) :
Component(parent, name, id, ComponentType::parameter)
{
    ParameterWrite *s = ParameterWrite::GetInstance();
    int* ptr_to_obj = (int*)this;
    s->AddParamToArray(ptr_to_obj, param_type::INT);
    _value = value; 
}
template <class T>
Parameter<T>::Parameter(Component *parent, const char *name, const char *id, float value) :
Component(parent, name, id, ComponentType::parameter)
{
    ParameterWrite *s = ParameterWrite::GetInstance();
    int* ptr_to_obj = (int*)this;
    s->AddParamToArray(ptr_to_obj, param_type::FLOAT);
    _value = value; 
}
template <class T>
Parameter<T>::Parameter(Component *parent, const char *name, const char *id, double value) :
Component(parent, name, id, ComponentType::parameter)
{
    ParameterWrite *s = ParameterWrite::GetInstance();
    int* ptr_to_obj = (int*)this;
    s->AddParamToArray(ptr_to_obj, param_type::DOUBLE);
    _value = value; 
}
template <class T>
Parameter<T>::Parameter(Component *parent, const char *name, const char *id, bool value) :
Component(parent, name, id, ComponentType::parameter)
{
    ParameterWrite *s = ParameterWrite::GetInstance();
    int* ptr_to_obj = (int*)this;
    s->AddParamToArray(ptr_to_obj, param_type::BOOL);
    _value = value; 
}
template <class T>
void Parameter<T>::SetValue(T value) {
    _value = value;
}
template <class T>
T Parameter<T>::GetValue() {
    return _value;
}
