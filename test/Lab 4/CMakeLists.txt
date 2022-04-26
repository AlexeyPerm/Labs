cmake_minimum_required(VERSION 3.22)
project(Lab_4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS -static)
add_executable(Lab_4 main.cpp Triad.cpp Triad.h)
