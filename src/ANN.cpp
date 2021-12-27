#include "../include/ANN.hpp"

Neuron::Neuron() : bias{0.0}, output{0.0} {}

double Neuron::sigmoidFunction(std::vector<double>& inputs,
                               std::vector<double>& weights)
{
    return (1 / (1 + (exp(-activationInput(inputs, weights)))));
}

double Neuron::reluFunction(std::vector<double>& inputs,
                            std::vector<double>& weights)
{
    return std::fmax(0.0, activationInput(inputs, weights));
}

/**
 * @brief intermediate function used for activation functions, such as
 * sigmoidFunction and reluFunction. The list of inputs and weights should be equal
 * @param inputs a list of incoming input values from the previous neurons
 * @param weights the weights associated with those inputs */
double Neuron::activationInput(std::vector<double>& inputs,
                               std::vector<double>& weights)
{
    if (weights.size() != inputs.size()) throw new UnevenWeightsInputs;
    double result = 0.0;
    for (int i = 0; i < (int)inputs.size(); i++)
    {
        // input is output of the incoming input neuron
        result += (inputs[i] * weights[i]);
    }
    return result += this->bias;
}

double Neuron::getBias() { return this->bias; }
double Neuron::getOutput() { return this->output; }

Weight::Weight(Neuron& t_source, Neuron& t_destination)
    : source{t_source}, destination{t_destination}
{
    rng_engine r{};
    rng_distribution defaultRange{-1.0, 1.0};
    weightValue = defaultRange(r);
}

Weight::Weight(Neuron& t_source, Neuron& t_destination, double startRange,
               double endRange)
    : source{t_source}, destination{t_destination}
{
    rng_engine r{};
    rng_distribution range{startRange, endRange};
    weightValue = range(r);
}

Neuron Weight::getSource() { return this->source; }
Neuron Weight::getDestination() { return this->destination; }
double Weight::getValue() { return this->weightValue; }

void Weight::setSource(Neuron& t_source) { this->source = t_source; }
void Weight::setDestination(Neuron& t_destination)
{
    this->destination = t_destination;
}

Layer::Layer() : layer{vector<Neuron>()} {}
void Layer::insert(Neuron& neuron) { this->layer.push_back(neuron); }
Neuron Layer::getNeuron(int index) { return this->layer[index]; }
vector<Neuron> Layer::getLayer() { return this->layer; }

NeuralNetwork::NeuralNetwork()
    : inputLayer{Layer()}, hiddenLayers{vector<Layer>()}, outputLayer(Layer())
{
    NeuralNetwork(3);
}

NeuralNetwork::NeuralNetwork(int t_inputSize)
    : inputLayer{Layer()}, hiddenLayers{vector<Layer>()}, outputLayer(Layer())
{
    // Input layer
    for (int i = 0; i < t_inputSize; i++)
    {
        Neuron newNeuron;
        inputLayer.insert(newNeuron);
    }
    // No hidden layers, but one output layer with one neuron
    Neuron outputNeuron{};
    outputLayer.insert(outputNeuron);
    // Assign weights
    for (auto& inputNeuron : inputLayer.getLayer())
    {
        Weight newWeight(inputNeuron, outputNeuron);
        this->weights.push_back(newWeight);
    }
}

Layer NeuralNetwork::getInputLayer() { return this->inputLayer; }
vector<Layer> NeuralNetwork::getHiddenLayers() { return this->hiddenLayers; }
vector<Weight> NeuralNetwork::getWeights() { return this->weights; }
Layer NeuralNetwork::getOutputLayer() { return this->outputLayer; }
