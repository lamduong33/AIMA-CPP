#include "../include/ANN.hpp"

double Neuron::sigmoidFunction()
{
    return (1 / (1 + (exp(-activationInput()))));
}

double Neuron::reluFunction() { return std::fmax(0.0, activationInput()); }

double Neuron::activationInput()
{
    double result = 0.0;
    for (int i = 0; i < (int)this->inputWeights.size(); i++)
    {
        // input is output of the incoming input neuron
        auto input = inputWeights[i].getDestination().getOutput();
        auto weight = inputWeights[i].getValue();
        result += (input * weight);
    }
    return result += this->bias;
}

double Neuron::getBias() { return this->bias; }

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
        Neuron newNeuron{};
        inputLayer.insert(newNeuron);
    }
    // No hidden layers, but one output layer with one neuron
    Neuron outputNeuron{};
    outputLayer.insert(outputNeuron);
    // Assign weights
    for (auto& inputNeuron : inputLayer.getLayer())
    {
        Weight newWeight(inputNeuron, outputNeuron);
        outputLayer.insert(outputNeuron);
    }
}

Layer NeuralNetwork::getInputLayer() { return this->inputLayer; }
vector<Layer> NeuralNetwork::getHiddenLayers() { return this->hiddenLayers; }
vector<Weight> NeuralNetwork::getWeights() { return this->weights;}
Layer NeuralNetwork::getOutputLayer() { return this->outputLayer;}
