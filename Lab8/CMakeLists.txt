cmake_minimum_required(VERSION 3.22)
project(Lab8)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS -static)
add_executable(Lab8 Object.h Person.cpp Person.h main.cpp Student.cpp Student.h Tree.cpp Tree.h Event.h Dialog.cpp Dialog.h)
