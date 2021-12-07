#ifndef ANN_H_
#define ANN_H_

#include <cmath>
#include <memory>
#include <random>
#include <string>
#include <vector>

using rng_engine = std::default_random_engine;
using rng_distribution = std::uniform_real_distribution<double>;
using std::vector;

class Weight; // declare weight ahead of time for use in Neuron. Neuron needs to
              // know Weight and Weight needs to know Neuron.

/* A neuron is meant to be in the layers between the NetworkInput nodes and
 * NetworkOutput nodes. */
class Neuron
{
    vector<Weight> inputWeights;
    double bias;
    double output;
public:

    Neuron();
    /**
     * Create the Neuron with given input+output weights.
     * TODO: Make sure that the constructor is only called once during making
    Neural NEt. */
    Neuron(const vector<Weight>& t_inputWeights, const vector<Weight>& t_outputWeights);

    /* Sigmoid activation function: 1 / (1 + e^-x) */
    double sigmoidFunction();
    /* ReLU (rectifier) activation function: max(0,x) */
    double reluFunction();
    /* Calculate x for different activation functions, such as sigmoid and ReLu. */
    double activationInput();

    double getBias();

    /* Get the output saved in neuron, will not update neuron. */
    double getOutput();

};

class Weight
{
    Neuron& source;
    Neuron& destination;
    double weightValue;

public:
    Weight();
    Weight(Neuron& t_source, Neuron& t_destination);
    /**
     * Create weight with source and destination. startRange and endRange
     * represent the range of random values to assign initial weights */
    Weight(Neuron& t_source, Neuron& t_destination, double startRange,
           double endRange);

    Neuron getSource();
    Neuron getDestination();
    double getValue();

    void setSource(Neuron& t_source);
    void setDestination(Neuron& t_destination);
};

/**
 * Simple abstraction for a layer of neurons */
class Layer
{
    vector<Neuron> layer;
public:
    Layer();
    void insert(Neuron& neuron);
    Neuron getNeuron(int index);
    vector<Neuron> getLayer();
};

class NeuralNetwork
{

    Layer inputLayer;
    vector<Layer> hiddenLayers;
    vector<Weight> weights;
    Layer outputLayer;

public:

    /**
     * A constructor to create a barebone perceptron with 3 inputs.*/
    NeuralNetwork();

    /**
     * Given input size, create a perceptron with given input size. */
    NeuralNetwork(int t_inputSize);

    // TODO: Constructor to construct neural network from text file.

    Layer getInputLayer();
    vector<Layer> getHiddenLayers();
    vector<Weight> getWeights();
    Layer getOutputLayer();
};

#endif // ANN_H_
