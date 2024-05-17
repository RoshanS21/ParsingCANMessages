cmake_minimum_required(VERSION 3.10)
project(can_project)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(can_project src/main.cpp src/can_utils.cpp)
