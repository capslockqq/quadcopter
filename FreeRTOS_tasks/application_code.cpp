#include "application_code.hpp"

Application_code::Application_code(const char *name, const char *id) :
Component(this, name, id)
,drone_controller("Drone controller", "DRONE")
,_param(this, "Param", "05", 10)
,_param2(this, "Param2", "06", 10.0f)
,_param3(this, "Param2", "06", 10.5)
,_param4(this, "Param2", "06", false)
{
}


void Application_code::Update() {
    static int result = 0;
    static int i = 0;
    drone_controller.Update();
    drone_controller.drone_pitch_controller.ip_setpoint.SetValue(result);
    drone_controller.drone_yaw_controller.ip_setpoint.SetValue(32);
    drone_controller.drone_yaw_controller.PID_controller.op_control_signal.SetValue(_param2.GetValue());
    result = i*i;
    i++;
}
 