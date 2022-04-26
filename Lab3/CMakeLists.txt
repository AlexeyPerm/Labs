cmake_minimum_required(VERSION 3.22)
project(Lab3)

set(CMAKE_CXX_STANDARD 20)

include_directories(Lab3)

add_executable(Lab3
        Lab3/main.cpp
        Lab3/money.cpp
        Lab3/money.h)
