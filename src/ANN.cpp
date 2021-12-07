#include "../include/ANN.hpp"

/* ============================== NEURON ===================================== */

Neuron::Neuron() : bias{0.0} {}

double Neuron::sigmoidFunction(std::vector<double>& inputs,
                               std::vector<double>& weights)
{
    return (1 / (1 + (exp(-activationInput(inputs, weights)))));
}

/* ReLu function makes the net non-linear. */
double Neuron::reluFunction(std::vector<double>& inputs,
                            std::vector<double>& weights)
{
    return std::fmax(0.0, activationInput(inputs, weights));
}

double Neuron::activationInput(std::vector<double>& inputs,
                               std::vector<double>& weights)
{
    double result = 0.0;
    if (inputs.size() != weights.size())
        throw new std::exception;
    for (int i = 0; i < (int)inputs.size(); i++)
    {
        result += inputs[i] * weights[i];
    }
    return result += this->bias;
}

double Neuron::getBias() { return this->bias; }

/* ============================== WEIGHT ===================================== */

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

/* ============================== LAYER ===================================== */
