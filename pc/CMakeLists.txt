add_executable(pc_program main.cpp)
target_link_libraries(  pc_program 
                        pc-application_code 
                        application_code_control
                        pc-application_code_communication 
                        pc-application_code_transportation 
                        pc-application_code_protocols
)
