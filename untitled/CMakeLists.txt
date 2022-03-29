cmake_minimum_required(VERSION 3.21)
project(untitled)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS -static)
add_executable(untitled Object.cpp Object.h Car.cpp Car.h main.cpp Lorry.cpp Lorry.h Vector.cpp Vector.h)
