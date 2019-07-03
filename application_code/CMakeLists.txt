#####################################################################
# simple AVR library
#####################################################################
add_subdirectory(communication)
add_subdirectory(control)
file(GLOB application
    "*.hh"
    "*.h"
    "*.cc"
    "*.cpp")
if(BUILD_TYPE STREQUAL "TARGET")
    add_avr_library(
    application_code
    ${application}
    )
else()
    add_library (
        pc-application_code
        ${application}
    )
endif()
