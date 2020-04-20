cmake_minimum_required(VERSION 3.10.0)
project(WORDS)
set(CMAKE_CXX_STANDARD 17)
add_executable(proj_test test.cpp game.cpp)
add_executable(proj main.cpp )

catch_discover_tests(proj_test)




