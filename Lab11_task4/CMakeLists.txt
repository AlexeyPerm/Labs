cmake_minimum_required(VERSION 3.21)
project(Lab11_task4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS -static)
add_executable(Lab11_task4 main.cpp Functions.h)
