cmake_minimum_required(VERSION 4.1)
project(GameStop)

set(CMAKE_CXX_STANDARD 20)

add_executable(GameStop main.cpp
        product.h
        videogame.h
        console.h
        bundle.h
        merch.h
        customer.h
        product.cpp
        videogame.cpp
        console.cpp
        bundle.cpp
        merch.cpp
        customer.cpp
)
