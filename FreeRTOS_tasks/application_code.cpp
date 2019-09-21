#include "application_code.hpp"

Application_code::Application_code(const char *name, const char *id) :
Component(this, name, id)
,com_to_computer(this, "Com to PC", "ComPC")
,drone_controller("Drone controller", "DRONE")
{

}


void Application_code::Update() {
    static int result = 0;
    static int i = 0;
    drone_controller.Update();
    drone_controller.drone_pitch_controller.ip_setpoint.SetValue(result);
    drone_controller.drone_yaw_controller.ip_setpoint.SetValue(32);
    drone_controller.drone_yaw_controller.PID_controller.op_control_signal.SetValue(33);
    result = i*i;
    i++;
}
 