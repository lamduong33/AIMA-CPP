#define CATCH_CONFIG_RUNNER
#include <iostream>
//#include "catch2.hpp" // NOTE: assuming catch.hpp is in local dir
#include "../include/DataSet.hpp"
#include "./ANNTests.cpp"
#include "./DataSetTests.cpp"

int main(int argc, char* argv[])
{
    int result = Catch::Session().run(argc, argv);
    return result;
}
