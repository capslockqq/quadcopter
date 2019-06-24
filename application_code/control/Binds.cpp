#include "Binds.hpp"

template<class type>
void Bind_Output_2_Input(Input<type> &input, Output<type> &output) {
    input = output;
}