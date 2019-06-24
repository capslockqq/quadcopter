add_executable(unittest main.cpp)
target_link_libraries(unittest
                                pc-application_code 
                                application_code_control
                                pc-application_code_communication 
                                pc-application_code_protocols
)