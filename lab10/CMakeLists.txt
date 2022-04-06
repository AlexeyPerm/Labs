cmake_minimum_required(VERSION 3.21)
project(lab10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS -static)
add_executable(lab10 main.cpp Money.cpp Money.h FileWork.h)
