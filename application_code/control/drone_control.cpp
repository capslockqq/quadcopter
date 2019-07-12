#include "drone_control.hpp"

Drone_Control::Drone_Control(const char* name, const char* id) :
 Component(this, name, id)
,drone_stabilizer(this, "Drone Stabilize Controller", "01")
,drone_altitude_controller(this, "Drone Altitude Controller", "02")
{
}