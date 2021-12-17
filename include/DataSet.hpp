#ifndef DATASET_HPP
#define DATASET_HPP

#include "Example.hpp"
#include <fstream> // for parsing files
#include <sstream> // for help in parsing files
#include <stdexcept> // for throwing quick and dirty errors

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
    * @brief open the recorded data file, parse values, then assign values. */
    void getData(); // TODO: finish making test cases for getData()

    std::string getFileName();
    std::vector<Example> getExamples();
    std::vector<std::string> getLabels();

    /**
     * Append to the  */
    void addExamples(std::vector<Example> t_examples);

};

/**
 * Exception for when a training/testing file is not a csv file. */
class NotCSVException : public std::exception
{
    virtual const char* what() const throw()
    {
        return "The file is not in a csv format";
    }
};

#endif
