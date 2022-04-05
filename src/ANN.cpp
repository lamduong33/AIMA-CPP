#include "../include/ANN.hpp"

/** NOTE: Documentations are available in ANN.hpp*/

Neuron::Neuron() : bias{0.0}, output{0.0} {}

Neuron::Neuron(double t_output) : bias{0.0}, output{t_output} {}

void Neuron::sigmoidFunction(double t_activationInput)
{
    this->output = (1 / (1 + (exp(-t_activationInput))));
}

void Neuron::reluFunction(double t_activationInput)
{
    this->output = std::fmax(0.0, t_activationInput);
}

double Neuron::activationInput(std::vector<double>& inputs,
                               std::vector<double>& weights)
{
    if (weights.size() != inputs.size())
        throw new UnevenWeightsInputs;
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

Weight::Weight(Neuron& t_source, Neuron& t_destination)
    : Weight(t_source, t_destination, -1.0, 1.0)
{}

Weight::Weight(Neuron& t_source, Neuron& t_destination, double startRange,
               double endRange)
    : source{t_source}, destination{t_destination}
{
    static std::default_random_engine rng;
    std::uniform_real_distribution<double> dist(startRange, endRange);
    weightValue = dist(rng);
}

Neuron& Weight::getSource() { return this->source; }
Neuron& Weight::getDestination() { return this->destination; }
Neuron* Weight::getSourceAddress() { return &this->source; }
Neuron* Weight::getDestinationAddress() { return &this->destination; }
double Weight::getValue() { return this->weightValue; }

void Weight::setSource(Neuron& t_source) { this->source = t_source; }
void Weight::setDestination(Neuron& t_destination)
{
    this->destination = t_destination;
}

/** ========================= NEURAL NETWORK ======================== */

NeuralNetwork::NeuralNetwork(int t_inputSize, int t_outputSize,
                             LearningMethod t_method)
    : m_inputLayer{vector<Neuron>{}}, m_hiddenLayers{vector<vector<Neuron>>{}},
      m_outputLayer{vector<Neuron>{}},
      m_method(t_method), m_inputSize{t_inputSize}, m_outputSize{t_outputSize},
      m_hiddenNeuronsSize{0}
{
    // Input layer
    for (int i = 0; i < t_inputSize; i++)
    {
        Neuron inputNeuron;
        m_inputLayer.push_back(inputNeuron);
    }
    this->createOutputLayer(t_outputSize);
    this->assignWeights();
    this->update();
}

NeuralNetwork::NeuralNetwork(std::vector<double> t_inputs, int t_outputSize,
                             LearningMethod t_method)
    : m_inputLayer{vector<Neuron>{}}, m_hiddenLayers{vector<vector<Neuron>>{}},
      m_outputLayer(vector<Neuron>{}),
      m_method(t_method), m_inputSize{(int)t_inputs.size()},
      m_outputSize{t_outputSize}, m_hiddenNeuronsSize{0}
{
    for (int i = 0; i < t_inputs.size(); i++)
    {
        Neuron inputNeuron;
        inputNeuron.setOutput(t_inputs[i]);
        m_inputLayer.push_back(inputNeuron);
    }
    this->createOutputLayer(t_outputSize);
    this->assignWeights();
    this->update();
}

void NeuralNetwork::update()
{
    std::unordered_map<Neuron*, double> map;

    // O(w) for w weights.
    for (int i = 0; i < this->m_weights.size(); i++)
    {
        auto neuron = m_weights[i].getDestinationAddress();
        if (!map.count(neuron))
        {
            map[neuron] = 0.0;
        }
        map[neuron] +=
            m_weights[i].getSource().getOutput() + m_weights[i].getValue();
    }

    // O(n) for n neurons.
    for (auto pair = map.begin(); pair != map.end(); pair++)
    {
        auto neuron = pair->first;
        if (this->getLearningMethod() == LearningMethod::relu)
        {
            neuron->reluFunction(pair->second);
        }
        else if (this->getLearningMethod() == LearningMethod::sigmoid)
        {
            neuron->sigmoidFunction(pair->second);
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
        this->m_outputLayer.push_back(Neuron{});
    }
}

void NeuralNetwork::assignWeights()
{
    for (int i = 0; i < m_inputLayer.size(); i++)
    {
        for (int j = 0; j < m_outputLayer.size(); j++)
        {
            m_weights.push_back(
                Weight(m_inputLayer[i], m_outputLayer[j], -1.0, 1.0));
        }
    }
}

void NeuralNetwork::addHiddenLayer(int t_numberOfNodes)
{
    // Create the hidden layer and add it to the network.
    vector<Neuron> hiddenLayer;
    for (int i = 0; i < t_numberOfNodes; i++)
    {
        auto newNeuron = Neuron{};
        std::vector<Neuron> previous;
        if (m_hiddenLayers.empty())
            previous = m_inputLayer;
        else
            previous = m_hiddenLayers.back();
        for (auto& p_neuron : previous)
        {
            m_weights.push_back(Weight(p_neuron, newNeuron));
        }
        for (auto& output : m_outputLayer)
        {
            m_weights.push_back(Weight(newNeuron, output));
        }
    }
    this->m_hiddenLayers.push_back(hiddenLayer);

    // If everything went correctly, adjust weights/outputs
    this->update(); // NOTE: Can be expensive here
    this->m_hiddenNeuronsSize += t_numberOfNodes;
}

void NeuralNetwork::addNeuron(int t_layerIndex)
{
    if (t_layerIndex >= (int) this->m_hiddenLayers.size())
    {
        throw std::out_of_range("The hidden layer does not have this index");
    }
}

void NeuralNetwork::addNeuron()
{
    this->addNeuron(m_hiddenLayers.size()-1);
}

void NeuralNetwork::removeHiddenLayer(int t_layerIndex)
{
}

void NeuralNetwork::removeNeuron(int t_layerIndex, int t_neuronIndex)
{
}

void NeuralNetwork::setLearningMethod(LearningMethod t_learningMethod)
{
    this->m_method = t_learningMethod;
}

void NeuralNetwork::addOutputNode(int t_hiddenLayerIndex)
{
    this->m_outputLayer.push_back(Neuron{});
}

vector<Neuron> NeuralNetwork::getInputLayer() { return this->m_inputLayer; }
vector<vector<Neuron>> NeuralNetwork::getHiddenLayers()
{
    return this->m_hiddenLayers;
}

vector<Weight> NeuralNetwork::getWeights() { return this->m_weights; }
vector<Neuron> NeuralNetwork::getOutputLayer() { return this->m_outputLayer; }
LearningMethod NeuralNetwork::getLearningMethod() { return this->m_method; }
int NeuralNetwork::getInputSize() { return this->m_inputSize; }
int NeuralNetwork::getOutputSize() { return this->m_outputSize; }
int NeuralNetwork::getHiddenNeuronsSize() { return this->m_hiddenNeuronsSize; }
