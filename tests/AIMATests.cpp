#define CATCH_CONFIG_RUNNER
#include <catch2/catch.hpp> // NOTE: assuming intalled via package manager.
#include <iostream>
//#include "catch2.hpp" // NOTE: assuming catch.hpp is in local dir
#include "../include/ANN.hpp"
#include "../include/DataSet.hpp"

TEST_CASE("DataSet - file extensions")
{
    std::string fileName1 = "fakename.csv";
    std::string fileName2 = "fakenamecsv";
    std::string fileName3 = "fakename";
    std::string fileName4 = "fakename.csv2";
    REQUIRE_NOTHROW(DataSet{fileName1});
    REQUIRE_THROWS(DataSet{fileName2});
    REQUIRE_THROWS(DataSet{fileName3});
    REQUIRE_THROWS(DataSet{fileName4});
}

TEST_CASE("DataSet - get data - correct data")
{
    std::vector<std::string> row1{"Yes", "No", "No",  "Yes",    "Some",
                                  "$$$", "No", "Yes", "French", "0-10"};
    std::vector<std::string> row2{"Yes", "No", "No", "Yes",  "Full",
                                  "$",   "No", "No", "Thai", "30-60"};
    std::vector<std::string> row3{"No", "Yes", "No", "No",     "Some",
                                  "$",  "No",  "No", "Burger", "0-10"};
    std::vector<std::string> row4{"Yes", "No",  "Yes", "Yes",  "Full",
                                  "$",   "Yes", "No",  "Thai", "10-30"};
    std::vector<std::string> row5{"Yes", "No", "Yes", "No",     "Full",
                                  "$$$", "No", "Yes", "French", ">60"};
    std::vector<std::string> row6{"No", "Yes", "No",  "Yes",     "Some",
                                  "$$", "Yes", "Yes", "Italian", "0-10"};
    std::vector<std::string> row7{"No", "Yes", "No", "No",     "None",
                                  "$",  "Yes", "No", "Burger", "0-10"};
    std::vector<std::string> row8{"No", "No",  "No",  "Yes",  "Some",
                                  "$$", "Yes", "Yes", "Thai", "0-10"};
    std::vector<std::string> row9{"No", "Yes", "Yes", "No",     "Full",
                                  "$",  "Yes", "No",  "Burger", ">60"};
    std::vector<std::string> row10{"Yes", "Yes", "Yes", "Yes",     "Full",
                                   "$$$", "No",  "Yes", "Italian", "10-30"};
    std::vector<std::string> row11{"No", "No", "No", "No",   "None",
                                   "$",  "No", "No", "Thai", "0-10"};
    std::vector<std::string> row12{"Yes", "Yes", "Yes", "Yes",    "Full",
                                   "$",   "No",  "No",  "Burger", "30-60"};
    std::vector<std::vector<std::string>> rows{row1, row2,  row3,  row4,
                                               row5, row6,  row7,  row8,
                                               row9, row10, row11, row12};
    std::vector<std::string> outputs{"Yes", "No",  "Yes", "Yes", "No", "Yes",
                                     "No",  "Yes", "No",  "No",  "No", "Yes"};
    std::vector<std::string> labels{"Alt",  "Bar",   "Fri",     "Hun",
                                    "Pat",  "Price", "Rain",    "Res",
                                    "Type", "Est",   "WillWait"};

    // Ensure a bad path throws an error
    std::string badPath = "..datasets/restaurant.csv";
    REQUIRE_THROWS(DataSet{badPath}.getData());

    std::string path = "datasets/restaurant.csv";
    DataSet ds{path};
    REQUIRE_NOTHROW(ds.getData());
    auto examples = ds.getExamples();
    REQUIRE(!examples.empty());

    for (int i = 1; i < (int)examples.size(); i++)
    {
        auto example = examples[i - 1];
        // Ensure that examples are the correct name, from 1 to n
        REQUIRE(example.getExampleName() == ("x" + std::to_string(i)));
        REQUIRE(example.getAttributes() == rows[i - 1]);
    }
}

TEST_CASE("Neuron Uneven Test")
{
    std::vector<double> weights{-0.02,-0.04};
    std::vector<double> inputs{2.0};
    Neuron neuron{};
    REQUIRE_THROWS(neuron.activationInput(inputs, weights));
}

/* Check for basic math functions.*/
TEST_CASE("Neuron Test")
{
    std::vector<double> weights{-0.02,-0.04};
    std::vector<double> inputs{2.0, 10.0};
    Neuron neuron{};
    auto activationInput = neuron.activationInput(inputs, weights);
    REQUIRE(activationInput == -0.44);
}

TEST_CASE("Weight Randomization Tests")
{
    auto numberOfWeights = 5;
    std::vector<Weight> listOfWeights{};
    Neuron neuron{};
    for (int i = 0; i < numberOfWeights; i++)
    {
        listOfWeights.push_back(Weight{neuron, neuron});
        for (int j = i; j >= 0; j--)
        {
            if (j != i)
            {
                REQUIRE(&listOfWeights[j] != &listOfWeights[i]);
                REQUIRE(listOfWeights[j].getValue() != listOfWeights[i].getValue());
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

    // Ensure that inputs aren't identical
    for (int i = 0; i < numberOfInputs; i++)
    {
        if (i != numberOfInputs - 1)
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
    for (int i = 0; i < numberOfOutputs; i++)
    {
        REQUIRE(!net.getOutputLayer().getLayer().empty());
        REQUIRE(net.getOutputLayer().getLayer()[i].getBias() == 0.0);
        REQUIRE(net.getOutputLayer().getLayer()[i].getOutput() == 0.0);
        if (i != numberOfOutputs -1)
        {
            auto outputNeuron = net.getOutputLayer().getNeuron(i);
            for (int j = i; j < numberOfOutputs; j++)
            {
                auto outputNeuron2 = net.getOutputLayer().getNeuron(j);
                REQUIRE(&outputNeuron != &outputNeuron2);
            }
        }
    }

    // Test weights
    REQUIRE(!net.getWeights().empty());
    for (auto& weight : net.getWeights())
    {
        REQUIRE(weight.getValue() < 1.0);
        REQUIRE(weight.getValue() > -1.0);
    }
}

TEST_CASE("Neural Network Test 2")
{
    NeuralNetwork net1(2, 2);
}

TEST_CASE("Neural Network Hidden Layer Test")
{

}

int main(int argc, char* argv[])
{
    int result = Catch::Session().run(argc, argv);
    return result;
}
