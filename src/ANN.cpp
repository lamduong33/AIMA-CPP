#include "../include/ANN.hpp"

/* ============================== NEURON ===================================== */
Neuron::Neuron() : bias{0.0} {}

double Neuron::sigmoidFunction()
{
    return (1 / (1 + (exp(-activationFunction()))));
}

double Neuron::reluFunction() { return std::fmax(0.0, activationFunction()); }

double Neuron::activationFunction()
{
    double result = 0.0;
    result += this->bias;
    return result;
}

/* ============================== WEIGHT ===================================== */

Weight::Weight(Neuron &t_source, Neuron &t_destination)
    : source{t_source}, destination{t_destination}
{
    rng_engine r{};
    rng_distribution defaultRange{-5.5, 5.5};
    weightValue = defaultRange(r);
}

Weight::Weight(Neuron &t_source, Neuron &t_destination,
               double startRange, double endRange)
    : source{t_source}, destination{t_destination}
{
    rng_engine r{};
    rng_distribution range{startRange, endRange};
    weightValue = range(r);
}
