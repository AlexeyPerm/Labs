cmake_minimum_required(VERSION 3.21)
project(Lab9)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS -static)
add_executable(Lab9 List.cpp List.h main.cpp Error.h)
