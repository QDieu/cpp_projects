cmake_minimum_required(VERSION 3.6)
project(lab9_1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp cmake-build-debug/funcs.cpp cmake-build-debug/funcs.h)
add_executable(lab9_1 ${SOURCE_FILES})