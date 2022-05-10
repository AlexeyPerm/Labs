cmake_minimum_required(VERSION 3.21)
project(untitled3)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)


set(CMAKE_CXX_STANDARD 20)
add_executable(untitled3 main.cpp)
target_link_libraries(untitled3 ${OPENGL_LIBRARIES})
target_link_libraries(untitled3 ${GLUT_LIBRARIES})
target_link_libraries(untitled3 -lopengl32 -g -lfreeglut)