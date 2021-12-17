#ifndef DATASET_HPP
#define DATASET_HPP

#include "Example.hpp"
#include <fstream>
#include <memory>
#include <string>

class NotCSVException : public std::exception
{
    virtual const char* what() const throw()
    {
        return "The file is not in a csv format";
    }
};

/**
 * A dataset object is simply a 2 dimensional matrix that takes has labels
 * associated with the data. Each row of a DataSet is an "Example".*/
class DataSet
{
    std::string m_fileName;
    std::vector<std::string> m_labels;
    std::vector<Example> m_examples;
    bool parsed;

public:
    DataSet();
    DataSet(std::string& t_fileName);
    void getData();

    std::string getFileName();
    std::vector<Example> getExamples();
    std::vector<std::string> getLabels();
};

#endif
