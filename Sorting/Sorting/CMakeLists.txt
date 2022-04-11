cmake_minimum_required(VERSION 3.15)
project(Sorting)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Sorting
        main.cpp
        sorting.h)
