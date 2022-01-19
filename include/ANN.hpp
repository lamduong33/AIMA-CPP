#ifndef ANN_HPP_
#define ANN_HPP_

#include <cmath>
#include <memory>
#include <random>
#include <string>
#include <vector>

using std::vector;

/* A neuron is meant to be in the layers between the NetworkInput nodes and
 * NetworkOutput nodes. */
class Neuron
{
    double bias;
    double output;
public:

    Neuron();

    /* Sigmoid activation function: 1 / (1 + e^-x) */
    double sigmoidFunction(std::vector<double>& inputs,
        std::vector<double>& weights);
    /* ReLU (rectifier) activation function: max(0,x) */
    double reluFunction(std::vector<double>& inputs,
        std::vector<double>& weights);
    /* Calculate x for different activation functions, such as sigmoid and ReLu. */
    double activationInput(std::vector<double>& inputs,
        std::vector<double>& weights);

    double getBias();

    /* Get the output saved in neuron, will not update neuron. */
    double getOutput();

    /** @brief set the output of the neuron. Use this for input neurons.*/
    void setOutput(double t_output);
};
/**
 * Exception for when a training/testing file is not a csv file. */
class UnevenWeightsInputs : public std::exception
{
    virtual const char* what() const throw()
    {
        return "The incoming weights and inputs size do not match!\n";
    }
};

class Weight
{
    Neuron source;
    Neuron destination;
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

/**
 * A feed-forward network. */
class NeuralNetwork
{
    Layer inputLayer;
    vector<Layer> hiddenLayers;
    vector<Weight> weights;
    Layer outputLayer; // multiple nodes indicate classification

public:

    /**
     * @brief A constructor to create a barebone perceptron with 3 inputs and no
     * hidden layers.*/
    NeuralNetwork();

    /**
     * @brief Given input size, create a network with given input size. This is
     * similar to a linear regression model. This will start with an input layer
     * the given amount and no hidden layers.
     *
     * @param t_inputSize the number of input neurons from the input layer.
     * @param t_outputSize the number of neurons in the output layer. */
    NeuralNetwork(int t_inputSize, int t_outputSize);

    /**
     * @brief Given a list of inputs, create a neural network. This has no hidden
     * layers, and one output node.
     *
     * @param t_inputSize the number of input nodes from the input layer.
     * @param t_outputSize the number of nodes in the output layer. */
    NeuralNetwork(std::vector<double> t_inputs, int t_outputSize);

    // TODO: Constructor to construct neural network from text file.

    /**
     * @brief add a hidden layer to the neural network right before the output.
     * @param t_numberOfNodes the number of nodes to be added. */
    void addHiddenLayer(int t_numberOfNodes);

    /**
     * @brief create an output layer from given output size and assign it to the
     * neural network. This is meant to be used in the constructor only.
     * @param t_outputSize the number of output neurons. */
    void createOutputLayer(int t_outputSize);

    void assignWeights();

    /**
     * @brief add an output node to the neural network at a certain layer. */
    void addOutputNode(int t_hiddenLayerIndex);

    Layer getInputLayer();
    vector<Layer> getHiddenLayers();
    vector<Weight> getWeights();
    Layer getOutputLayer();
};

#endif // ANN_HPP_
