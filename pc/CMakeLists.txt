add_executable(pc_program main.cpp)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

target_link_libraries(  pc_program 
                        Threads::Threads
                        pc-application_code 
                        application_code_control
                        pc-application_code_communication 
                        pc-application_code_protocols
                        pc-application_code_transport_layer
                        pc-Free_RTOS_Tasks
                        Free_RTOS_Linux
)
