
#pragma once
#include <sys/stat.h>
#include "../../application_code/components/Component.hpp"

class Simulation : public Component {
public:
    Simulation(const char*, const char*);
    virtual ~Simulation(){};
    void update();
};