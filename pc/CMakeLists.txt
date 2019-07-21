
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
add_executable(pc_program main.cpp)


target_link_libraries(  pc_program 
                        Threads::Threads
                        pc-application_code 
                        pc-application_code_communication 
                        pc-application_code_protocols
                        pc-Free_RTOS_Tasks
                        pc-application_code_transport_layer
                        application_code_control
                        Free_RTOS_Linux
                        
)
