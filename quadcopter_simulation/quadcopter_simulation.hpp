
#pragma once
#include "../application_code/components/Component.hpp"
#include "../application_code/components/Output.hpp"
#include "../application_code/components/Input.hpp"
class Quadcopter : public Component {
public:
    Quadcopter(const char*, const char*);
    virtual ~Quadcopter(){};
    void update();


};