#####################################################################
# simple AVR executable
#####################################################################
add_avr_executable(
   Quadcopter
   main.cpp
   )

add_avr_library(
   operators
   "operators.cpp"
)
#####################################################################
# libraries to link to
#####################################################################
target_link_libraries(
   Quadcopter-${AVR_MCU}.elf
   operators-${AVR_MCU}
   application_code-${AVR_MCU}
   application_code_communication-${AVR_MCU}
   application_code_protocols-${AVR_MCU}
   application_code_transportation-${AVR_MCU}
   )
