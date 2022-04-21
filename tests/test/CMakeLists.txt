cmake_minimum_required(VERSION 3.22)
project(test)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS -static)
add_executable(test main.cpp)
