cmake_minimum_required(VERSION 3.13)
project(Movie_Final)

set(CMAKE_CXX_STANDARD 14)

add_executable(Movie_Final main.cpp Movie.cpp Movie.h Repository.cpp Repository.h Controller.cpp Controller.h UI.cpp UI.h)