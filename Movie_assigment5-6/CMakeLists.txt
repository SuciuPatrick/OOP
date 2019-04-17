cmake_minimum_required(VERSION 3.13)
project(Bacteria_test)

set(CMAKE_CXX_STANDARD 14)

add_executable(Bacteria_test main.cpp Bacteria.cpp Bacteria.h Repository.cpp Repository.h Controller.cpp Controller.h UI.cpp UI.h)