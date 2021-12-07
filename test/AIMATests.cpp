#define CATCH_CONFIG_RUNNER
#include <catch2/catch.hpp> // NOTE: assuming intalled via package manager.
#include <iostream>
//#include "catch2.hpp" // NOTE: assuming catch.hpp is in local dir
#include "../include/ANN.hpp"

TEST_CASE("ANN Test 1")
{
    Neuron neuron1{};
    Neuron neuron2{};
    Neuron neuron3{};
    Neuron neuron4{};
    Neuron neuron5{};
}

int main(int argc, char *argv[])
{
    int result = Catch::Session().run(argc, argv);
    return result;
}
