#pragma once
#include "../components/Component.hpp"
class Drone_Communication : public Component {
public:
    Drone_Communication(const char * name, const char * id);
    virtual ~Drone_Communication(){};
    void Update();
};