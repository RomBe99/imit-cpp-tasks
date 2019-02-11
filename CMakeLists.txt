cmake_minimum_required(VERSION 3.13)
project(cpp-tasks)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp-tasks src/main.cpp src/BoxStruct.cpp headers/BoxStruct.h src/BoxStructProcessor.cpp headers/BoxStructProcessor.h)