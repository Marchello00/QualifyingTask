cmake_minimum_required(VERSION 3.13)

add_subdirectory(client_lib)

add_executable(Client run_client.cpp)

target_link_libraries(Client ClientLib Networking)
link_directories(Client ClientLib Networking)