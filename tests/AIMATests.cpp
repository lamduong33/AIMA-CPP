#define CATCH_CONFIG_RUNNER
#include <catch2/catch.hpp> // NOTE: assuming intalled via package manager.
#include <iostream>
//#include "catch2.hpp" // NOTE: assuming catch.hpp is in local dir
#include "../include/ANN.hpp"

/* Sanity check to ensure that objects are instantiation correctly. */
TEST_CASE("NeuralNetwork Constructor Test 1")
{
    auto numberOfInputs = 5;
    NeuralNetwork net(numberOfInputs);

    std::vector<Neuron> listOfNeurons;
    for (int i = 0; i < numberOfInputs; i++)
    {
        if (i != numberOfInputs-1)
        {
            auto neuron = net.getInputLayer().getNeuron(i);
            for (int j = i; j < numberOfInputs; j++)
            {
                auto neuron2 = net.getInputLayer().getNeuron(j);
                REQUIRE(&neuron != &neuron2);
            }
        }
    }

    // Hidden layers test
    REQUIRE(net.getHiddenLayers().empty());

    // Output test
    REQUIRE(!net.getOutputLayer().getLayer().empty());
    REQUIRE(net.getOutputLayer().getLayer()[0].getBias() == 0.0);
    REQUIRE(net.getOutputLayer().getLayer()[0].getOutput() == 0.0);

    // Test weights
    REQUIRE(!net.getWeights().empty());
    for (auto& weight : net.getWeights())
    {
        REQUIRE(weight.getValue() < 1.0);
        REQUIRE(weight.getValue() > -1.0);
    }
}

int main(int argc, char *argv[])
{
    int result = Catch::Session().run(argc, argv);
    return result;
}
