cmake_minimum_required(VERSION 3.22)
project(Lab12_task2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS -static)

add_executable(Lab12_task2
        main.cpp
        Money.cpp
        Money.h Functions.h)
