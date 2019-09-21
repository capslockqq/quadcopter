#include <type_traits>
#include <typeinfo>
#ifndef _MSC_VER
#include <cxxabi.h>
#endif
#include <memory>
#include <string>
#include <cstdlib>

#include "Output.hpp"
#include "../control/OutputObserver.hpp"
class test {
public:
    test(Output<float>*tester) {
        _test = tester;
    }
private:
    Output<float> *_test;
};