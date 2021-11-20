#ifndef NEURALNETWORK_H_
#define NEURALNETWORK_H_

#include <vector>
#include <memory> // smart pointers
#include <random> // RNG
#include <cmath>
#include <string>

using rng_engine = std::default_random_engine;
using rng_distribution = std::uniform_real_distribution<float>;

/* A neural node represents a list of connections of inputs being fed to it and
 * outputs that it will send forward.*/
struct NeuralNode
{
    // Inputs are a pair of <output, weight>
    std::vector<std::pair<double, std::unique_ptr<NeuralNode>>> inputs;
    // Outputs are a pair of <output, weight>
    std::vector<std::pair<double, std::unique_ptr<NeuralNode>>> outputs;
};

/* A network input node will not have inputs. */
class NetworkInput : NeuralNode
{
protected:
    double inputValue; // input value is also the output value
public:
    // An input node MUST not have inputs, only outputs.
    NetworkInput(double t_inputValue);
    bool noInputs();
};

class NetworkOutput : NeuralNode
{
    std::string label;
public:
};

/* A neuron is meant to be in the layers between the NetworkInput nodes and
 * NetworkOutput nodes.*/
class Neuron : NeuralNode
{
    double bias;
public:
    Neuron();
    double activationFunction();
    double sigmoidFunction();
    double reluFunction();
    double getBias();
    std::vector<std::pair<double, double>> getOutputs();
    std::vector<std::pair<double, double>> getInputs();
};

template<class NeuralNode>
struct Layer
{
    std::vector<NeuralNode> nodes;
};

class NeuralNetWork
{
    std::vector<NetworkInput> inputLayer;
    std::vector<NetworkOutput> outputLayer;
};


#endif // NEURALNETWORK_H_
