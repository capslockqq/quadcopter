#####################################################################
# simple AVR library
#####################################################################
file(GLOB communication_src
    "*.hpp"
    "*.h"
    "*.cc"
    "*.cpp"
    "I2C_fake.cpp"
    )
if(BUILD_TYPE STREQUAL "PC" OR BUILD_TYPE STREQUAL "UNITTEST")
    add_library (
        pc-application_code_transport_layer
        ${communication_src}
    )
endif()