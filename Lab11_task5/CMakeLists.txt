cmake_minimum_required(VERSION 3.22)
project(Lab11_task5)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS -static)
add_executable(Lab11_task5 main.cpp List.h)
