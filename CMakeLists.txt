cmake_minimum_required(VERSION 3.26)
project(Estructuras1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Estructuras1 Juego/main.cpp
        Estructura/tarjeta.cpp
        Estructura/territorio.cpp
        Estructura/continente.h
        Estructura/continente.cpp
        Estructura/jugador.h
        Estructura/jugador.cpp)
