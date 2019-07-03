#####################################################################
# simple AVR library
#####################################################################
add_subdirectory(protocols)
add_subdirectory(transport_layer)
file(GLOB communication_src
    "*.hh"
    "*.h"
    "*.cc"
    "*.cpp"
    )
if(BUILD_TYPE STREQUAL "TARGET")
    add_avr_library(
    application_code_communication
    ${communication_src}
    )
else()
    add_library (
        pc-application_code_communication
        ${communication_src}
    )
endif()
