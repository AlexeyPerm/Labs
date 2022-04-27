cmake_minimum_required(VERSION 3.22)
project(Lab6)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS -static)

add_executable(Lab6
        List.cpp
        List.h
        main.cpp Iterator.cpp Iterator.h)
