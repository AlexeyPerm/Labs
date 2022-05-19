cmake_minimum_required(VERSION 3.22)
project(BST_OOP)

set(CMAKE_CXX_STANDARD 20)
add_executable(BST_OOP main.cpp Node.cpp Node.h Menu.h func.h func.cpp draw.h)
target_link_libraries(BST_OOP -lOpenGL32 -lfreeGLUT -lGLU32)