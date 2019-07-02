#####################################################################
# simple AVR library
#####################################################################
file(GLOB communication_src
    "*.hh"
    "*.h"
    "*.cc"
    "*.cpp"
    )
if(BUILD_TYPE STREQUAL "PC")
    add_library (
        pc-application_code_transport_layer
        ${communication_src}
    )
endif()