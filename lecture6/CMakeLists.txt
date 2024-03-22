cmake_minimum_required(VERSION 3.27)
project(lecture6)

set(CMAKE_CXX_STANDARD 14)
include(doctest.cmake)

add_executable(lecture6 main.cpp
        Visitor.cpp
        Visitor.h
        calculator.h
)
target_link_libraries(lecture6 PRIVATE doctest::doctest_with_main)