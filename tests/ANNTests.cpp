#include <catch2/catch.hpp> // NOTE: assuming intalled via package manager.
#include <iostream>
//#include "catch2.hpp" // NOTE: assuming catch.hpp is in local dir
#include "../include/ANN.hpp"

/* Check for basic math functions.*/
TEST_CASE("Neuron Test")
{
    std::vector<double> weights{-0.02, -0.04};
    std::vector<double> inputs{2.0, 10.0};
    Neuron neuron{};
    auto activationInput = neuron.activationInput(inputs, weights);
    REQUIRE(activationInput == -0.44);
}

TEST_CASE("Weight Randomization Tests")
{
    auto numberOfWeights = 5;
    std::vector<Weight> listOfWeights{};
    Neuron newNeuron{};
    for (int i = 0; i < numberOfWeights; i++)
    {
        listOfWeights.push_back(Weight(newNeuron, newNeuron, -1.0, 1.0));
        for (int j = i; j >= 0; j--)
        {
            if (j != i)
            {
                // Weights are unique
                REQUIRE(&listOfWeights[j] != &listOfWeights[i]);
                // Weights have unique values
                REQUIRE(listOfWeights[j].getValue() !=
                        listOfWeights[i].getValue());
            }
        }
    }
}

/**
 * @brief Ensure that the input neurons are unique in address. */
void ANNInputTest(std::vector<Neuron> t_inputs)
{
    std::unordered_set<Neuron*> neurons;
    for (auto& neuron : t_inputs)
    {
        REQUIRE(neurons.count(&neuron) == 0);
        neurons.insert(&neuron);
    }
}

/**
 * @brief Test to see if weights are intialized correctly. This test to see if
 * the weights in the neural net will produce non-zero unique weights. This uses
 * an unordered_map so this can be somewhat memory expensive.*/
void weightTest(std::vector<Weight> t_weights)
{
    auto weightSet = std::unordered_set<double>{};
    for (auto& weight : t_weights)
    {
        // Ensuring that the weights are within the right range
        REQUIRE(weight.getValue() < 1.0);
        REQUIRE(weight.getValue() != 0.0);
        REQUIRE(weight.getValue() > -1.0);
        // Ensuring that weights are not repeat of each other.
        REQUIRE(weightSet.count(weight.getValue()) == false);
        weightSet.insert(weight.getValue());
    }
}

/**
 * @brief Test to see if the output looking the way it should. NOTE: This should
 * only used for a new neural net (such as constructors or if testing to see
 * things are unchanged).
 * This function will check if the output layer:
 * 1) has 0 bias in each node
 * 2) produces non-zero and unique output nodes
 * */
void ANNOutputTest(std::vector<Neuron> t_outputLayer)
{
    for (int i = 0; i < t_outputLayer.size(); i++)
    {
        REQUIRE(!t_outputLayer.empty());
        REQUIRE(t_outputLayer[i].getBias() == 0.0);
        REQUIRE(t_outputLayer[i].getOutput() != 0.0);
        if (i != t_outputLayer.size() - 1)
        {
            auto outputNeuron = t_outputLayer[i];
            for (int j = i; j < t_outputLayer.size(); j++)
            {
                auto outputNeuron2 = t_outputLayer[j];
                // different addresses for output neurons
                REQUIRE(&outputNeuron != &outputNeuron2);
            }
        }
    }
}

/* Sanity check to ensure that objects are instantiation correctly. This checks
 * for correct number of hidden layers(none), output, bias, and weights. */
TEST_CASE("NeuralNetwork Constructor Test 1")
{
    auto numberOfInputs = 5;
    auto numberOfOutputs = 2;
    NeuralNetwork net(numberOfInputs, numberOfOutputs);
    REQUIRE(net.getLearningMethod() == LearningMethod::sigmoid);

    // Ensure that inputs aren't identical
    ANNInputTest(net.getInputLayer());

    // Hidden layers test
    REQUIRE(net.getHiddenLayers().empty());

    // Output test
    ANNOutputTest(net.getOutputLayer());

    // Test weights
    weightTest(net.getWeights());
}

/* Test for the constructor that takes in a vector of doubles as inputs.*/
TEST_CASE("NeuralNetwork Constructor Test 2")
{
    std::vector<double> inputs{2.0, 10.0, -5.0, 4.0, 1.0, -3.0};
    auto numberOfOutputs = 5;
    NeuralNetwork net(inputs, numberOfOutputs);

    ANNInputTest(net.getInputLayer());

    // Hidden layers test
    REQUIRE(net.getHiddenLayers().empty());

    // Output test
    ANNOutputTest(net.getOutputLayer());

    // Test weights
    REQUIRE(!net.getWeights().empty());
    weightTest(net.getWeights());
}

TEST_CASE("Neural Network Constructor Test 3")
{
    std::vector<double> inputs{2.0, 10.0};
    NeuralNetwork net(inputs, 2, LearningMethod::relu); // 2x2 network
    REQUIRE(net.getLearningMethod() == LearningMethod::relu);
    REQUIRE(net.getInputSize() == 2);
    REQUIRE(net.getOutputSize() == 2);
    REQUIRE(net.getHiddenNeuronsSize() == 0);

    // Ensuring update() has worked correctly. This does not check for the
    // correct output. It simply checks if there is an output.
    auto previous = 0.0;
    for (auto& output : net.getOutputLayer())
    {
        REQUIRE(output.getOutput() != previous);
        previous = output.getOutput();
    }
}

TEST_CASE("Add Hidden Layer Test")
{
    NeuralNetwork net{std::vector<double>{2.0, 10.0}, 2, LearningMethod::relu};
    REQUIRE(net.getHiddenLayers().size() == 0);
    net.addHiddenLayer(3);
    REQUIRE(net.getHiddenLayers().size() == 1);
    net.addHiddenLayer(2);
    REQUIRE(net.getHiddenLayers().size() == 2);

    // Check weights are correct
    weightTest(net.getWeights());

    // Check outputs are correct
    ANNOutputTest(net.getOutputLayer());
}

TEST_CASE("Add Neuron Test")
{
    NeuralNetwork net{std::vector<double>{2.0, 10.0}, 2, LearningMethod::relu};
    net.addHiddenLayer(2); // 2 neurons
    REQUIRE_THROWS(net.addNeuron(1), std::out_of_range(""));
    REQUIRE_NOTHROW(net.addNeuron(0)); // 1 neuron
    net.addHiddenLayer(3); // 3 neurons
    REQUIRE_NOTHROW(net.addNeuron(0)); // 1 neuron
    REQUIRE_NOTHROW(net.addNeuron(1)); // 1 neuron
    REQUIRE_THROWS(net.addNeuron(2), std::out_of_range(""));
    REQUIRE_NOTHROW(net.addNeuron()); // 1 neuron
    REQUIRE_NOTHROW(net.addNeuron()); // 1 neuron
    REQUIRE(net.getHiddenNeuronsSize() == 10); // 10 total
    REQUIRE(net.getHiddenLayers()[0].size() == 4); // 4 in first
    REQUIRE(net.getHiddenLayers()[1].size() == 6); // 6 in second
}
