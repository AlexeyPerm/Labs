cmake_minimum_required(VERSION 3.21)
project(for_lab_14)

set(CMAKE_CXX_STANDARD 20)
add_executable(for_lab_14 main.cpp)
target_link_libraries(for_lab_14 -lOpenGL32 -lfreeglut -lglu32)