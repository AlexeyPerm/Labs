cmake_minimum_required(VERSION 3.22)
project(Lab4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS -static)

add_executable(Lab4
        cpp.hint
        main.cpp
        Time.cpp
        Time.h
        Triad.cpp
        Triad.h)
