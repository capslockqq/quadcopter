
#pragma once
#include "../application_code/components/Component.hpp"
#include "../application_code/components/Output.hpp"
#include "../application_code/components/Input.hpp"
class quadcopter_model : public Component {
public:
    quadcopter_model(const char*, const char*);
    virtual ~quadcopter_model(){};
    void update();

    Component brushless_dc_motor_1;
    Component brushless_dc_motor_2;
    Component brushless_dc_motor_3;
    Component brushless_dc_motor_4;
};