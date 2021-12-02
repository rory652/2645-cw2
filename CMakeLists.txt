cmake_minimum_required(VERSION 3.10)
project(2645-cw2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(cw2
        gui.h gui.cpp
        main.cpp
        Group.h
        Term.h Term.cpp
        Function.h Function.cpp
        Equation.h Equation.cpp
        tests.h tests.cpp)
