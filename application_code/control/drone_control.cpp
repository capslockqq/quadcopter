#include "drone_control.hpp"

Drone_Control::Drone_Control(const char* name, const char* id) :
 Component(this, name, id)
,drone_yaw_controller(this, "Drone Yaw Controller", "01")
,drone_pitch_controller(this, "Drone Pitch Controller", "02")
,drone_roll_controller(this, "Drone Roll Controller", "03")
{
}