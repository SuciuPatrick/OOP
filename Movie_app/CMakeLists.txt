cmake_minimum_required(VERSION 3.13)
project(Movie_Final)

set(CMAKE_CXX_STANDARD 14)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Charts REQUIRED)

add_executable(Movie_Final main.cpp Movie.cpp Movie.h Repository.cpp Repository.h Controller.cpp Controller.h UI.cpp UI.h UndoAction.cpp UndoAction.h Errors.cpp Errors.h Validate.cpp Validate.h RepositoryCSV.cpp RepositoryCSV.h RepositoryHTML.cpp RepositoryHTML.h GUI.cpp GUI.h)
target_link_libraries(Movie_Final Qt5::Widgets Qt5::Charts)