cmake_minimum_required(VERSION 3.15)
project(calculator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(BUILD_SHARED_LIBS OFF) # Stick with statically linked libraries

include(sanitizers.cmake)
include(doctest.cmake)

add_executable(calculator_test calculator_test.cpp)
target_link_libraries(calculator_test PRIVATE doctest::doctest_with_main)

enable_testing()
add_test(NAME calculator_test COMMAND calculator_test)
