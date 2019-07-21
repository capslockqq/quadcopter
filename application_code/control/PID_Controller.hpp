#pragma once
#include "../components/Component.hpp"
#include "../components/Input.hpp"
#include "../components/Output.hpp"

template <class T>
class PID_Controller : public Component {
public:
    PID_Controller(Component *, const char*, const char*, float max_limit, float min_limit);
    void Set_P_Gain(T p_gain);
    void Set_I_Gain(T i_gain);
    T    Get_P_Gain();
    T    Get_I_Gain();
    T    Get_Output(T error);


    Input<T>  error;
    Output<T> control_signal;

private:
    T _P_gain;
    T _I_gain;
    float _max_limit;
    float _min_limit;
};
template <class T>
PID_Controller<T>::PID_Controller(Component *parent, const char* name, const char* id, float max_limit, float min_limit) :
Component(this, name, id)
,error(this, "Control error", "01")
,control_signal(this, "Control signal", "02")
,_max_limit(max_limit)
,_min_limit(min_limit)
{

}
template <class T>
void PID_Controller<T>::Set_P_Gain(T p_gain) {
}
template <class T>
void PID_Controller<T>::Set_I_Gain(T i_gain) {

}
template <class T>
T PID_Controller<T>::Get_P_Gain() {
    return _P_gain;
}
template <class T>
T PID_Controller<T>::Get_I_Gain() {
    return _I_gain;
}

template <class T>
T PID_Controller<T>::Get_Output(T error) {

}