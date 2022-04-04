cmake_minimum_required(VERSION 3.21)
project(untitled_lab10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS -static)
add_executable(untitled_lab10  FileWork.h Person.cpp Person.h main.cpp)
