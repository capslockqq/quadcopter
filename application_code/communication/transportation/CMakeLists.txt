#####################################################################
# simple AVR library
#####################################################################
file(GLOB transportation_src
    "*.hh"
    "*.h"
    "*.cc"
    "*.cpp")
if(BUILD_TYPE STREQUAL "TARGET")
    add_avr_library(
    application_code_transportation
    ${transportation_src}
    )
else()
    add_library (
        pc-application_code_transportation
        ${transportation_src}
    )
endif()
