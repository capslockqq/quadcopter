#include "quadcopter_simulation.hpp"

quadcopter_model::quadcopter_model(const char* name, const char* id) : 
Component(this, name, id)
,brushless_dc_motor_1(this, "Brushless DC 1", "01")
,brushless_dc_motor_2(this, "Brushless DC 2", "02")
,brushless_dc_motor_3(this, "Brushless DC 3", "03")
,brushless_dc_motor_4(this, "Brushless DC 4", "04")
{
    
}


void quadcopter_model::update() {
    
}
