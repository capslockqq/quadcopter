#pragma once
#include "../components/Component.hpp"
#include "../components/Input.hpp"
#include "../components/Output.hpp"

class Drone_Altitude_Controller : public Component {
public:
    Drone_Altitude_Controller(Component *parent, const char* name, const char* id);
    virtual ~Drone_Altitude_Controller();
    void Update();
};