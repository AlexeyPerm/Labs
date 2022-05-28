cmake_minimum_required(VERSION 3.22.4)
set(PROJECT_NAME test_openGL_BST)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
add_executable(${PROJECT_NAME} main.cpp bst.h draw.h)
target_link_libraries(${PROJECT_NAME} -lOpenGL32 -lfreeglut -lglu32)
