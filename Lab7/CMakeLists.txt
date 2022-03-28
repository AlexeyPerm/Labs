cmake_minimum_required(VERSION 3.21)
project(Lab7)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS -static)
add_executable(Lab7 main.cpp List.inl List.h)
