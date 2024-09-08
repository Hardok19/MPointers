cmake_minimum_required(VERSION 3.28)
project(Mpointers)

set(CMAKE_CXX_STANDARD 17)

add_executable(Mpointers main.cpp
        include/MPointers.h
        include/MPointerGC.cpp
        include/MPointerGC.h
        include/lLista.h
        include/lLista.h
        include/lLista.cpp
        ListaDoble.h
)
