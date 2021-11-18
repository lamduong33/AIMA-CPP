#define CATCH_CONFIG_RUNNER
#include <catch2/catch.hpp> // NOTE: assuming intalled via package manager.
#include <iostream>
//#include "catch2.hpp" // NOTE: assuming catch.hpp is in local dir
#include "../include/NeuralNetwork.hpp"

TEST_CASE("BinaryTree Order Test 1")
{
    std::vector<double> inputs;
    inputs.push_back(20.3);
}

int main(int argc, char *argv[])
{
    int result = Catch::Session().run(argc, argv);
    return result;
}
