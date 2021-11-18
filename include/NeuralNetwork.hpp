#ifndef NEURALNETWORK_H_
#define NEURALNETWORK_H_

#include <iostream>
#include <vector>

/* A simple neuron that takes in double float input and output. */
class Neuron
{
protected:
    double weight;
    double output;

public:
    // Default constructor to initialize a Neuron
    Neuron() : weight{0.0}, output{0.0} {}
    /* Simply return the output double float value. */
    double getOutput();
    double getWeight();
    /* Do some math magic to get the output. */
    double giveOutput(std::vector<double>& inputs);
    // TODO: A function to take in inputs with variadic arguments.
};

class Layer
{
    std::vector<Neuron> layer;
};

class NeuralNetWork
{
    std::vector<Layer> hiddenLayers;
    Layer outputLayer;
};

#endif // NEURALNETWORK_H_
