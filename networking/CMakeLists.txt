cmake_minimum_required(VERSION 3.13)
project(Networking)

add_library(Networking acceptor.cpp socket.cpp socket.h networking.cpp networking.h resolver.cpp resolver.h)

set_target_properties(Networking PROPERTIES
                      INTERFACE_INCLUDE_DIRECTORIES "${Networking_SOURCE_DIR}/"
                      )

INCLUDE_DIRECTORIES(/usr/local/opt/asio/include)
LINK_DIRECTORIES(/usr/local/opt/asio/include)