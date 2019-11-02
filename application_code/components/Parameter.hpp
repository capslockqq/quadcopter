#pragma once
#include "Component.hpp"
#include "ParameterWrite.hpp"
template <class T>
class Parameter : public Component {
public:
    Parameter(Component *parent, const char *name, const char *id, T value);
    virtual ~Parameter(){}
    ComponentType type(){ return ComponentType::parameter; }
    void SetValue(T val);
    T GetValue();
private:
    T _value;
};

template <class T>
Parameter<T>::Parameter(Component *parent, const char *name, const char *id, T value) :
Component(parent, name, id)
{
    _value = value;
    ParameterWrite *parawrite = ParameterWrite::GetInstance();
    parawrite->count();
    
    
}

template <class T>
void Parameter<T>::SetValue(T value) {
    _value = value;
}
template <class T>
T Parameter<T>::GetValue() {
    return _value;
}
