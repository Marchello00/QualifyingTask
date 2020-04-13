cmake_minimum_required(VERSION 3.13)
project(ClientLib)

add_library(ClientLib client.cpp)

set_target_properties(ClientLib PROPERTIES
                      INTERFACE_INCLUDE_DIRECTORIES "${ClientLib_SOURCE_DIR}/"
                      )