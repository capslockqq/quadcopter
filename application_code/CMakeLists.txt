#####################################################################
# simple AVR library
#####################################################################
file(GLOB helloworld_SRC
    "*.hh"
    "*.h"
    "*.cc"
    "*.cpp")
if(BUILD_TYPE STREQUAL "TARGET")
    add_avr_library(
    application_code
    ${helloworld_SRC}
    )
else()
    add_library (
        pc-application_code
        ${helloworld_SRC}
    )
endif()
