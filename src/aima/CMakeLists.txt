add_library(
  aima STATIC
  ANN.cpp
  DataSet.cpp
  DecisionTree.cpp
  Example.cpp
  ExamplesLearning.cpp
)
target_link_libraries(aima PRIVATE Qt6::Core)
target_include_directories(aima INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
