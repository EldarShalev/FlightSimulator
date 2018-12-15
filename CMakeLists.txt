cmake_minimum_required(VERSION 3.5)
project(simulator)

set(CMAKE_CXX_STANDARD 14)

add_executable(simulator main.cpp Command.h AllCommands/OpenServerCommand.cpp AllCommands/OpenServerCommand.h Utils.cpp Utils.h GlobalMap.cpp GlobalMap.h)