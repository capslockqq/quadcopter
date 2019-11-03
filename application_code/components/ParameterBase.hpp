#pragma once
#include "Component.hpp"
class ParameterBase {
public:
    ParameterBase(Component *parent, const char *name, const char *id, float value);
    ParameterBase(Component *parent, const char *name, const char *id, double value);
    ParameterBase(Component *parent, const char *name, const char *id, int value);
    ParameterBase(Component *parent, const char *name, const char *id, bool value);


    virtual ~ParameterBase(){}
    ComponentType type(){ return ComponentType::parameter; }
    void SetValue(T val);
    T GetValue();
private:
    T _value;
};

ParameterBase::ParameterBase(Component *parent, const char *name, const char *id, float value) :
{
}

void ParameterBase::SetValue(T value) {
    _value = value;
}
T ParameterBase::GetValue() {
    return _value;
}
