add_executable(
  AIMA-CPP
  AIMA.cpp
  AIMAGUI.cpp
)

target_link_libraries(AIMA-CPP PRIVATE Qt6::Widgets)

set_target_properties(
  AIMA-CPP PROPERTIES
  WIN32_EXECUTABLE ON
  MACOSX_BUNDLE ON
)
