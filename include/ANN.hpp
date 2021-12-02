#ifndef ANN_H_
#define ANN_H_

#include <vector>
#include <memory> // smart pointers
#include <random> // RNG
#include <cmath> // math functions
#include <string>

using rng_engine = std::default_random_engine;
using rng_distribution = std::uniform_real_distribution<float>;

class NeuralNetwork
{
    // Represent the neural network as a weighted adjacency list
    std::vector<std::pair<double, double>> adjacencyList;
};

#endif // ANN_H_
