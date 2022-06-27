cmake_minimum_required(VERSION 3.16)

project(AIMA-CPP VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# No need to find Core because Widgets depends on it.
find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

add_executable(
  AIMA-CPP
  gui/AIMA.cpp
)

add_library(
  AIMAGUI STATIC
  gui/AIMAGUI.cpp
)

target_link_libraries(AIMA-CPP PRIVATE Qt6::Widgets)
target_link_libraries(AIMAGUI PRIVATE Qt6::Core)
target_include_directories(AIMAGUI INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/gui)

set_target_properties(
  AIMA-CPP PROPERTIES
  WIN32_EXECUTABLE ON
  MACOSX_BUNDLE ON
)
