cmake_minimum_required(VERSION 3.22)
project(lab_3_tmp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS -static)
add_executable(lab_3_tmp main.cpp Money.cpp Money.h)
