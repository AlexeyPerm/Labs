cmake_minimum_required(VERSION 3.21)
project(Lab13_taks1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS -static)
add_executable(Lab13_taks1 main.cpp Money.h Money.cpp Functions.h)
