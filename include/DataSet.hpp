#ifndef DATASET_HPP
#define DATASET_HPP

#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class DataSet
{
    std::string m_trainingFileName;
    std::string m_testingFileName;
    std::vector<double> labels;
public:
    // constructor
    DataSet(std::string t_trainingFileName, std::string t_testingFileName);
    void getData();
};

#endif
