cmake_minimum_required(VERSION 3.16)

project(AIMA-CPP VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# No need to find Core because Widgets depends on it.
find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

add_subdirectory(src/gui)
add_subdirectory(src/aima)
