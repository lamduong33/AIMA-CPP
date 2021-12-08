#define CATCH_CONFIG_RUNNER
#include <catch2/catch.hpp> // NOTE: assuming intalled via package manager.
#include <iostream>
//#include "catch2.hpp" // NOTE: assuming catch.hpp is in local dir
#include "../include/ANN.hpp"

/* Sanity check to ensure that objects are instantiation correctly. */
TEST_CASE("NeuralNetwork Test 1")
{
    NeuralNetwork net(5);

    // Input layer test
    REQUIRE(net.getInputLayer().getLayer().size() == 5);
    auto n1 = net.getInputLayer().getNeuron(0);
    auto n2 = net.getInputLayer().getNeuron(1);
    auto n3 = net.getInputLayer().getNeuron(2);
    auto n4 = net.getInputLayer().getNeuron(3);
    auto n5 = net.getInputLayer().getNeuron(4);
    REQUIRE((&n1 != &n2) && (&n1 != &n3) && (&n1 != &n4) && (&n1 != &n5));

    // Hidden layers test
    REQUIRE(net.getHiddenLayers().empty());

    // Output test
    REQUIRE(!net.getOutputLayer().getLayer().empty());
    REQUIRE(net.getOutputLayer().getLayer()[0].getBias() == 0.0);
    REQUIRE(net.getOutputLayer().getLayer()[0].getOutput() == 0.0);

    // Test weights
    for (auto& weight : net.getWeights())
    {

    }
}

int main(int argc, char *argv[])
{
    int result = Catch::Session().run(argc, argv);
    return result;
}
