#include "../include/ANN.hpp"

/**
 * @brief Default constructor with 0 bias and 0 output. */
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
 * sigmoidFunction and reluFunction.
 * @throws UnevenWeightInputs when list of inputs and weights are not equal.
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

/**
 * @brief return the bias member variable. */
double Neuron::getBias() { return this->bias; }

/**
 * @brief return the output member variable. */
double Neuron::getOutput() { return this->output; }

void Neuron::setOutput(double t_output) { this->output = t_output; }

/**
 * @brief Create the weight object with source and destination
 * @details Using RNG, create  */
Weight::Weight(Neuron& t_source, Neuron& t_destination)
    : source{t_source}, destination{t_destination}
{
    static std::default_random_engine rng;
    std::uniform_real_distribution<double> dist(-1.0, 1.0);
    weightValue = dist(rng);
}

Weight::Weight(Neuron& t_source, Neuron& t_destination, double startRange,
               double endRange)
    : source{t_source}, destination{t_destination}
{
    static std::default_random_engine rng;
    std::uniform_real_distribution<double> dist(startRange, endRange);
    weightValue = dist(rng);
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
    NeuralNetwork(3, 1);
}

NeuralNetwork::NeuralNetwork(int t_inputSize, int t_outputSize)
    : inputLayer{Layer()}, hiddenLayers{vector<Layer>()}, outputLayer(Layer())
{
    // Input layer
    for (int i = 0; i < t_inputSize; i++)
    {
        Neuron inputNeuron;
        inputLayer.insert(inputNeuron);
    }
    this->createOutputLayer(t_outputSize);
    this->assignWeights();
}

NeuralNetwork::NeuralNetwork(std::vector<double> t_inputs, int t_outputSize)
    : inputLayer{Layer()}, hiddenLayers{vector<Layer>()}, outputLayer(Layer())
{
    for (int i = 0; i < t_inputs.size(); i++)
    {
        Neuron inputNeuron;
        inputNeuron.setOutput(t_inputs[i]);
        inputLayer.insert(inputNeuron);
    }
    this->createOutputLayer(t_outputSize);
    this->assignWeights();
}

void NeuralNetwork::createOutputLayer(int t_outputSize)
{
    for (int i = 0; i < t_outputSize; i++)
    {
        Neuron outputNeuron;
        this->outputLayer.insert(outputNeuron);
    }
}

void NeuralNetwork::assignWeights()
{
    for (auto& inputNeuron : this->inputLayer.getLayer())
    {
        for (auto& outputNeuron: this->outputLayer.getLayer())
        {
            Weight newWeight(inputNeuron, outputNeuron);
            this->weights.push_back(newWeight);
        }
    }
}

void NeuralNetwork::addHiddenLayer(int t_numberOfNodes)
{
    // Create the hidden layer
    Layer hiddenLayer;
    for (int i = 0; i < t_numberOfNodes; i++)
    {
        Neuron n;
    }
    // Add it to the net
    // Adjust weights accordingly
}

void NeuralNetwork::addOutputNode(int t_hiddenLayerIndex)
{

}

Layer NeuralNetwork::getInputLayer() { return this->inputLayer; }
vector<Layer> NeuralNetwork::getHiddenLayers() { return this->hiddenLayers; }
vector<Weight> NeuralNetwork::getWeights() { return this->weights; }
Layer NeuralNetwork::getOutputLayer() { return this->outputLayer; }
