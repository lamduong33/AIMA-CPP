#ifndef ANN_HPP_
#define ANN_HPP_

#include <cmath>
#include <memory>
#include <random>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::vector;

/* A neuron is meant to be nodes in a NeuralNetwork.*/
class Neuron
{
    double bias;
    double output;

public:
    /**
     * @brief Default constructor with 0 bias and 0 output. */
    Neuron();

    /**
     * @brief Create a neuron with a given output. */
    Neuron(double t_output);

    /**
     * @brief Sigmoid activation function: 1 / (1 + e^-x)
     * @param t_activationInput is the sum of the input's weights and outputs.
     */
    void sigmoidFunction(double t_activationInput);

    /**
     * @brief ReLU (rectifier) activation function: max(0,x)
     * @param t_activationInput is the sum of the input's weights and outputs.
     */
    void reluFunction(double t_activationInput);

    /**
     * @brief intermediate function used by activation functions, such as
     * sigmoidFunction and reluFunction. NOTE: This is for debugging.
     * @throws UnevenWeightInputs when list of inputs and weights are not equal.
     * @param inputs a list of incoming input values from the previous neurons
     * @param weights the weights associated with those inputs */
    double activationInput(std::vector<double>& inputs,
                           std::vector<double>& weights);

    /**
     * @brief return the bias member variable. */
    double getBias();

    /**
     * @brief Get the output saved in neuron, will not update neuron. */
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

class NoSuchLearningMethod : public std::exception
{
    virtual const char* what() const throw()
    {
        return "The learning method does not exist!\n";
    }
};

class Weight
{
    Neuron& source;
    Neuron& destination;
    double weightValue;

public:
    Weight();

    /**
     * @brief Create the weight object with source and destination */
    Weight(Neuron& t_source, Neuron& t_destination);

    /**
     * @brief Create weight with source and destination. startRange and endRange
     * represent the range of random values to assign initial weights */
    Weight(Neuron& t_source, Neuron& t_destination, double startRange,
           double endRange);

    Neuron& getSource();
    Neuron& getDestination();
    Neuron* getSourceAddress();
    Neuron* getDestinationAddress();
    double getValue();

    void setSource(Neuron& t_source);
    void setDestination(Neuron& t_destination);
};
/**
 * Learning method choices:
 * - sigmoid
 * - relu */
enum class LearningMethod
{
    sigmoid,
    relu
};

/**
 * A feed-forward network. */
class NeuralNetwork
{
    vector<Neuron> m_inputLayer;
    vector<vector<Neuron>> m_hiddenLayers;
    vector<Weight> m_weights;
    vector<Neuron> m_outputLayer; // multiple nodes indicate classification
    LearningMethod m_method = LearningMethod::sigmoid; // sigmoid by default

    int m_inputSize;         // the number of input neurons
    int m_outputSize;        // the number of output neurons
    int m_hiddenNeuronsSize; // the number of neurons in hidden layeres

    /**
     * @brief add a hidden layer to the neural network right before the output.
     * @param t_numberOfNodes the number of nodes to be added. */
    void addHiddenLayer(int t_numberOfNodes);

    /**
     * @brief create an output layer from given output size and assign it to the
     * neural network. This is meant to be used in the constructor only.
     * @param t_outputSize the number of output neurons. */
    void createOutputLayer(int t_outputSize);

public:
    /**
     * @brief Given input size, create a network with given input size. This is
     * similar to a linear regression model.
     * NOTE: This will create an input layer with outputs of 0.0
     *
     * @param t_inputSize the number of input neurons from the input layer.
     * @param t_outputSize the number of neurons in the output layer. */
    NeuralNetwork(int t_inputSize, int t_outputSize);

    /**
     * @brief Given a list of inputs, create a neural network. This will
     * additionally run the learning algorithm with sigmoid function.
     *
     * @param t_inputSize the number of input nodes from the input layer.
     * @param t_outputSize the number of nodes in the output layer. */
    NeuralNetwork(std::vector<double> t_inputs, int t_outputSize);

    /**
     * @brief Given a list of inputs, create a neural network. This will
     * additionally run the learning algorithm based on the chosen method.
     *
     * @param t_inputSize the number of input nodes from the input layer.
     * @param t_outputSize the number of nodes in the output layer. */
    NeuralNetwork(std::vector<double> t_inputs, int t_outputSize,
                  LearningMethod method);

    // TODO: Constructor to construct neural network from text file.

    /**
     * @brief Perform one pass and update values accordingly. This will update
     * every neuron using the list of weights in the object.*/
    void update();

    /**
     * @brief assign weights so that each input neuron maps to an output. */
    void assignWeights();

    /**
     * @brief add an output node to the neural network at a certain layer. */
    void addOutputNode(int t_hiddenLayerIndex);

    void setLearningMethod(LearningMethod t_learningMethod);

    vector<Neuron> getInputLayer();
    vector<vector<Neuron>> getHiddenLayers();
    vector<Weight> getWeights();
    vector<Neuron> getOutputLayer();
    LearningMethod getLearningMethod();
    int getInputSize();
    int getOutputSize();
    int getHiddenNeuronsSize();
};

#endif // ANN_HPP_
