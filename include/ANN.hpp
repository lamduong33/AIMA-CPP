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

    /**
     * Computes the series of inputs and weights given to a Neuron. This
     * is actually not an activation function itself. It is meant to be used as an
     * input for activation functions. */
    double activationInput(std::vector<double>& inputs,
                           std::vector<double>& weights);

    /**
     * Sigmoid function: 1 / (1 + e^-x) */
    double sigmoidFunction(std::vector<double>& inputs,
                           std::vector<double>& weights);

    /**
     * ReLU (rectifier) function: max(0,x) */
    double reluFunction(std::vector<double>& inputs,
                        std::vector<double>& weights);

    double getBias();

};

class Weight
{
    Neuron& source;
    Neuron& destination;
    double weightValue;

public:
    Weight();
    Weight(Neuron& t_source, Neuron& t_destination);
    Weight(Neuron& t_source, Neuron& t_destination, double startRange,
           double endRange);

    Neuron getSource();
    Neuron getDestination();

    void setSource(Neuron& t_source);
    void setDestination(Neuron& t_destination);
};

/**
 * Simple abstraction for a layer of neurons */
struct Layer
{
    std::vector<Neuron> layer;
};

class NeuralNetwork
{

    Layer inputLayer;
    std::vector<Layer> layers;
    Layer outputLayer;

public:

    /**
     * A constructor to create a barebone perceptron. */
    NeuralNetwork();

    /**
     * Given input size */
    NeuralNetwork(int t_inputSize);


    // TODO: Constructor to construct neural network from text file.
};

#endif // ANN_H_
