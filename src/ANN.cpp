#include "../include/ANN.hpp"

/** NOTE: Documentations are available in ANN.hpp*/

Neuron::Neuron() : bias{0.0}, output{0.0} {}

double Neuron::sigmoidFunction(double t_activationInput)
{
    return (1 / (1 + (exp(-t_activationInput))));
}

double Neuron::reluFunction(double t_activationInput)
{
    return std::fmax(0.0, t_activationInput);
}

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

void Neuron::setOutput(double t_output) { this->output = t_output; }

Weight::Weight(Neuron* t_source, Neuron* t_destination)
    : Weight(t_source, t_destination, -1.0, 1.0)
{}

Weight::Weight(Neuron* t_source, Neuron* t_destination, double startRange,
               double endRange)
    : source{std::make_shared<Neuron>(t_source)},
      destination{std::make_shared<Neuron>(t_destination)}
{
    static std::default_random_engine rng;
    std::uniform_real_distribution<double> dist(-1.0, 1.0);
    weightValue = dist(rng);
}

std::shared_ptr<Neuron> Weight::getSource() { return this->source; }
std::shared_ptr<Neuron> Weight::getDestination() { return this->destination; }
double Weight::getValue() { return this->weightValue; }

void Weight::setSource(Neuron* t_source)
{
    this->source = std::make_shared<Neuron>(t_source);
}
void Weight::setDestination(Neuron* t_destination)
{
    this->destination = std::make_shared<Neuron>(t_destination);
}

Layer::Layer() : layer{vector<Neuron>()} {}
void Layer::insert(Neuron& neuron) { this->layer.push_back(neuron); }
Neuron Layer::getNeuron(int index) { return this->layer[index]; }
vector<Neuron> Layer::getLayer() { return this->layer; }

NeuralNetwork::NeuralNetwork(int t_inputSize, int t_outputSize)
    : m_inputLayer{Layer()}, m_hiddenLayers{vector<Layer>()},
      m_outputLayer(Layer()), m_inputSize{t_inputSize},
      m_outputSize{t_outputSize}, m_hiddenNeuronsSize{0}
{
    // Input layer
    for (int i = 0; i < t_inputSize; i++)
    {
        Neuron inputNeuron;
        m_inputLayer.insert(inputNeuron);
    }
    this->createOutputLayer(t_outputSize);
    this->assignWeights();
}

NeuralNetwork::NeuralNetwork(std::vector<double> t_inputs, int t_outputSize)
    : m_inputLayer{Layer()}, m_hiddenLayers{vector<Layer>()},
      m_outputLayer(Layer()), m_inputSize{(int)t_inputs.size()},
      m_outputSize{t_outputSize}, m_hiddenNeuronsSize{0}
{
    for (int i = 0; i < t_inputs.size(); i++)
    {
        Neuron inputNeuron;
        inputNeuron.setOutput(t_inputs[i]);
        m_inputLayer.insert(inputNeuron);
    }
    this->m_inputSize = t_inputs.size();
    this->createOutputLayer(t_outputSize);
    this->assignWeights();
    this->update();
}

NeuralNetwork::NeuralNetwork(std::vector<double> t_inputs, int t_outputSize,
                             LearningMethod t_method)
    : NeuralNetwork(t_inputs, t_outputSize)
{
    this->m_method = t_method;
}

void NeuralNetwork::update()
{
    std::unordered_map<std::shared_ptr<Neuron>, double> map;

    // O(w) for w weights.
    for (auto& weight : this->m_weights)
    {
        auto neuron = weight.getDestination();
        if (!map.count(neuron))
        {
            map[neuron] = 0.0;
        }
        map[neuron] += weight.getSource()->getOutput() + weight.getValue();
    }

    // O(n) for n neurons.
    for (auto& pair : map)
    {
        auto neuron = *pair.first;
        if (this->getLearningMethod() == LearningMethod::relu)
        {
            neuron.reluFunction(pair.second);
        }
        else if (this->getLearningMethod() == LearningMethod::sigmoid)
        {
            neuron.sigmoidFunction(pair.second);
        }
        else
        {
            throw new NoSuchLearningMethod;
        }
    }
}

void NeuralNetwork::createOutputLayer(int t_outputSize)
{
    for (int i = 0; i < t_outputSize; i++)
    {
        Neuron outputNeuron;
        this->m_outputLayer.insert(outputNeuron);
    }
}

void NeuralNetwork::assignWeights()
{
    for (auto& inputNeuron : this->m_inputLayer.getLayer())
    {
        for (auto& outputNeuron : this->m_outputLayer.getLayer())
        {
            Weight newWeight(&inputNeuron, &outputNeuron);
            this->m_weights.push_back(newWeight);
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
    // If everything went correctly, adjust the hidden neurons amount
    this->m_hiddenNeuronsSize += t_numberOfNodes;
}

void NeuralNetwork::setLearningMethod(LearningMethod t_learningMethod)
{
    this->m_method = t_learningMethod;
}
/** TODO*/
void NeuralNetwork::addOutputNode(int t_hiddenLayerIndex) {}

Layer NeuralNetwork::getInputLayer() { return this->m_inputLayer; }
vector<Layer> NeuralNetwork::getHiddenLayers() { return this->m_hiddenLayers; }
vector<Weight> NeuralNetwork::getWeights() { return this->m_weights; }
Layer NeuralNetwork::getOutputLayer() { return this->m_outputLayer; }
LearningMethod NeuralNetwork::getLearningMethod() { return this->m_method; }
int NeuralNetwork::getInputSize() { return this->m_inputSize; }
int NeuralNetwork::getOutputSize() { return this->m_outputSize; }
int NeuralNetwork::getHiddenNeuronsSize() { return this->m_hiddenNeuronsSize; }
