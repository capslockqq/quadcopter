#include "interface.hpp"
#ifdef PC
#include <iostream>
#endif
class implementation : public interface<implementation> {
public:
    implementation();
    ~implementation();
    void some_function();
};

