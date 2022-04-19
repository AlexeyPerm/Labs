cmake_minimum_required(VERSION 3.22)
project(Lab14)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS -static)
add_executable(Lab14 main.cpp Functions.h)
