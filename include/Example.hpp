#ifndef EXAMPLE_HPP
#define EXAMPLE_HPP

#include <vector>
#include <string>

/**
 * This class holds the names for attributes of a dataset*/
struct Labels
{
    std::vector<std::string> m_attributeNames;
};

/** A class made for individual examples for learning. An example is simply a
 * row of data in a table. An example is made of discrete variables for input
 * attributes.
 *
 * NOTE: This class is used for categorical data.
 *
 * */
class Example
{
protected:
    std::string m_exampleName;
    std::vector<std::string> m_inputAttributes;
    std::string m_output;

public:
    Example();
    Example(std::string& t_exampleName,
            std::vector<std::string>& t_inputAttributes, std::string& t_output);

    std::string getExampleName();
    std::vector<std::string> getAttributes();
    std::string getOutput();

    void setExampleName(std::string& t_exampleName);
    void setAttributes(std::vector<std::string>& t_attributes);
    void setOutputs(std::string& t_output);
};

#endif
