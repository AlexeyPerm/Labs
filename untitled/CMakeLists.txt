cmake_minimum_required(VERSION 3.22)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp draw.h bst.h)
target_link_libraries(untitled -lOpenGL32 -lfreeGLUT -lGLU32)