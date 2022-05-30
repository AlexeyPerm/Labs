cmake_minimum_required(VERSION 3.22)
project(Graph)

set(CMAKE_CXX_STANDARD 20)

add_executable(Graph main.cpp Graph.cpp Graph.h draw.cpp draw.h)
target_link_libraries(${PROJECT_NAME} -lOpenGL32 -lfreeglut -lglu32)