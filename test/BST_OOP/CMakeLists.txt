cmake_minimum_required(VERSION 3.22)
set(PROJECT_NAME BST_OOP)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)
add_executable(${PROJECT_NAME} main.cpp Tree.cpp Tree.h Menu.h draw.h)
target_link_libraries(${PROJECT_NAME} -lOpenGL32 -lfreeglut -lglu32)
