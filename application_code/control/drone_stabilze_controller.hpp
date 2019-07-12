#pragma once
#include "../components/Component.hpp"
#include "../components/Input.hpp"
#include "../components/Output.hpp"

class Drone_stabilize_Controller : public Component {
public:
    Drone_stabilize_Controller(Component *parent, const char* name, const char* id);
    virtual ~Drone_stabilize_Controller();
    void Update();
};