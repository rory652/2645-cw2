cmake_minimum_required(VERSION 3.20)
project(2645-cw2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(cw2
        gui.cpp gui.h
        main.cpp Group.h Term.cpp Term.h)
