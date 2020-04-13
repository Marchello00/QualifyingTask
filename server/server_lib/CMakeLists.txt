cmake_minimum_required(VERSION 3.13)
project(ServerLib)

add_library(ServerLib server.cpp dictionary.cpp dictionary.h client.cpp client.h)

set_target_properties(ServerLib PROPERTIES
                      INTERFACE_INCLUDE_DIRECTORIES "${ServerLib_SOURCE_DIR}/"
                      )

target_link_libraries(ServerLib Networking)