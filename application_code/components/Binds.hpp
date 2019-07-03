#ifndef BINDS_H
#define BINDS_H
#include "Input.hpp"
#include "Output.hpp"
template<class type>
void Bind_Output_2_Input(Output<type> &output, Input<type> &input);
template<class type>
void Bind_Input_2_Output(Input<type> &input, Output<type> &output);




template<class type>
void Bind_Output_2_Input(Output<type> &output, Input<type> &input) {
    output = input;
}

template<class type>
void Bind_Input_2_Output(Input<type> &input, Output<type> &output) {
    input = output;
}
#endif