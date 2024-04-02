cmake_minimum_required(VERSION 3.27)
project(Practica2Oficial)

set(CMAKE_CXX_STANDARD 17)

add_executable(Practica2Oficial main.cpp
        clases/Grupos.cpp
        estructuras/Nodo.cpp
        estructuras/Nodo.h
        estructuras/ListaDoblemente.cpp
        estructuras/ListaDoblemente.h
        clases/Grupos.h
        estructuras/NodoArbol.cpp
        estructuras/NodoArbol.h
        estructuras/ArbolAVL.cpp
        estructuras/ArbolAVL.h
        estructuras/TablaHash.h
        clases/Contactos.cpp
        clases/Contactos.h
)
