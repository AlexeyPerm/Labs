cmake_minimum_required(VERSION 3.21)
project(Lab13_task2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS -static)
add_executable(Lab13_task2 main.cpp Functions.h Money.cpp Money.h)
