cmake_minimum_required(VERSION 3.13)

add_subdirectory(server_lib)
add_subdirectory(argparse)

add_executable(Server run_server.cpp)

target_link_libraries(Server
                      ServerLib
                      Argparse
                      Networking)

link_directories(Server ServerLib Argparse Networking)
