cmake_minimum_required(VERSION 3.20)
project(asymptotic_test)

set(CMAKE_CXX_STANDARD 20)

set(target "sumtwo-sorted")

add_executable(asymptotic_test ${target}/${target}.cpp tools.cpp tools.h)
