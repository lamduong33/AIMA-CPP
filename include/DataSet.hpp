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
    const std::string m_fileName; // filename is fixed, cannot change
    std::vector<std::string> m_labels;
    std::vector<Example> m_examples;
    bool parsed;

public:

    /**
    * @brief An empty constructor that initializes the member variables. */
    DataSet();


    /**
    * @brief Constructor that takes in a file name, but without parsing.
    * @throw NotCSVException if file extension is not .csv */
    DataSet(std::string& t_fileName);

    /**
    * getData()
    * @brief modify the DataSet object by opening the testing and training file
    * put them in a 2 dimensional array (vector). */
    void getData();

    std::string getFileName();
    std::vector<Example> getExamples();
    std::vector<std::string> getLabels();

    /**
     * Append to the  */
    void addExamples(std::vector<Example> t_examples);

};

#endif
