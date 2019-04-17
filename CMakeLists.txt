cmake_minimum_required(VERSION 3.13)
project(fotbal)

set(CMAKE_CXX_STANDARD 14)

add_executable(fotbal main.cpp Player.cpp Player.h Repository.cpp Repository.h Controller.cpp Controller.h UI.cpp UI.h)