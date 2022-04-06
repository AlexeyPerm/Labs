cmake_minimum_required(VERSION 3.21)
project(Lab1)

set(CMAKE_CXX_STANDARD 14)

include_directories(Lab1)

add_executable(Lab1
        "Lab1/calculation .cpp"
        Lab1/calculation.h
        Lab1/main.cpp)
