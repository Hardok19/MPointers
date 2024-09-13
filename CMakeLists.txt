cmake_minimum_required(VERSION 3.28)
project(Mpointers)

set(CMAKE_CXX_STANDARD 17)



# Añadir el ejecutable principal
add_executable(Mpointers
        biblioteca/MPointers.h
        biblioteca/lLista.h
        ListaDoble.cpp
        ListaDoble.h


)
# Encuentra Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Añade tus archivos de prueba
add_executable(MyTests test_main.cpp
        biblioteca/MPointers.h
        biblioteca/lLista.h
        ListaDoble.cpp
        ListaDoble.h


)

# Enlaza Google Test con tu ejecutable
target_link_libraries(MyTests gtest gtest_main)


# Incluir directorios de cabecera
target_include_directories(Mpointers PRIVATE include)








