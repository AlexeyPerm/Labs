cmake_minimum_required(VERSION 3.22)
project(Lab13_task3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS -static)
add_executable(Lab13_task3 main.cpp Money.cpp Money.h Functions.h)
