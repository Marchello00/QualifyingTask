cmake_minimum_required(VERSION 3.13)
project(Argparse)

add_library(Argparse argparse.cpp)

set_target_properties(Argparse PROPERTIES
                      INTERFACE_INCLUDE_DIRECTORIES "${Argparse_SOURCE_DIR}/"
                      )