#pragma once
#include "../components/Component.hpp"
#include "../components/Input.hpp"
#include "../components/Output.hpp"
#include "drone_stabilze_controller.hpp"
#include "drone_altitude_controller.hpp"
class Drone_Control : public Component {
public:
    Drone_Control(const char * name, const char *id);
    virtual ~Drone_Control();
    void Update();

    Drone_stabilize_Controller drone_stabilizer;
    Drone_Altitude_Controller drone_altitude_controller;

};