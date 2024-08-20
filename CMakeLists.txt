cmake_minimum_required(VERSION 3.28)
project(Mpointers)

set(CMAKE_CXX_STANDARD 17)

add_executable(Mpointers main.cpp
        src/MPointers.cpp
        include/MPointers.h)
