cmake_minimum_required(VERSION 3.21)
project(untitled1_lab9)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS -static)
add_executable(untitled1_lab9 main.cpp Vector.cpp Vector.h)
