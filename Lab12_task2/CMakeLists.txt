cmake_minimum_required(VERSION 3.21)
project(Lab12_task2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS -static)
add_executable(Lab12_task2 main.cpp Money.h Money.cpp)
