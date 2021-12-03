#ifndef ANN_H_
#define ANN_H_

#include <cmath>
#include <memory> // smart pointers
#include <random> // RNG
#include <string>
#include <vector>

using rng_engine = std::default_random_engine;
using rng_distribution = std::uniform_real_distribution<double>;

/* A neuron is meant to be in the layers between the NetworkInput nodes and
 * NetworkOutput nodes.*/
class Neuron
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

class Weight
{
    Neuron source;
    Neuron destination;
    double weightValue;
public:
    Weight();
    Weight(Neuron &t_source, Neuron &t_destination);
    Weight(Neuron &t_source, Neuron &t_destination, double startRange,
    double endRange);
};

template <class Neuron> struct Layer
{
    std::vector<Neuron> nodes;
};

class NeuralNetWork
{
    std::vector<Neuron> inputLayer;
    std::vector<Neuron> outputLayer;
};

#endif // ANN_H_
