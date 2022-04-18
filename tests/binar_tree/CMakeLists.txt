cmake_minimum_required(VERSION 3.22)
project(binar_tree)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS -static)
add_executable(binar_tree main.cpp Tree.h)
