#include "drone_stabilze_controller.hpp"

const char* INPUT_MEASUREMENT[] = {"Roll measurement", "Pitch measurement", "Yaw measurement"} ;
const char* INPUT_SETPOINT[] = {"Roll Setpoint", "Pitch Setpoint", "Yaw Setpoint"} ;

Drone_stabilize_Controller::Drone_stabilize_Controller(Component *parent, const char* name, const char* id, INPUT_NAME_INDEX index, float max, float min) :
Component(parent, name, id)
,PID_controller(this, "PID Controller", "PID", max, min)
,ip_measurement(this, INPUT_MEASUREMENT[index], "ME")
,ip_setpoint(this, INPUT_SETPOINT[index], "SP")
{
    PID_controller.Set_P_Gain(1.0);
}

Drone_stabilize_Controller::~Drone_stabilize_Controller() {
    
}

void Drone_stabilize_Controller::Update() {
    PID_controller.Calculate_Output(ip_setpoint.GetValue() - ip_measurement.GetValue());
}
