cmake_minimum_required(VERSION 3.22)
project(Graph)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS -static)
add_executable(Graph main.cpp Graph.cpp Graph.h)
