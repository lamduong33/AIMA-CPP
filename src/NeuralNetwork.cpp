#include "../include/NeuralNetwork.hpp"

NetworkInput::NetworkInput(double t_inputValue) : inputValue(t_inputValue) {}

double Neuron::activationFunction()
{
    double result = 0.0;
    for (auto& input : this->inputs)
    {
        result += input.first * input.second;
    }
    result += this->bias;
    return result;
}

double Neuron::sigmoidFunction()
{
    return (1 / (1+(exp(-activationFunction()))));
}

double Neuron::reluFunction()
{
    return std::fmax(0.0, activationFunction());
}
