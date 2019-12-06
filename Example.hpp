#ifndef EXAMPLE_HPP
#define EXAMPLE_HPP

#include <string>
#include <vector>
#include "Attribute.hpp"

/* A class made for individual examples. These examples will
contain example name and attributes (input), goal name and 
value (output). This is primarily used for training sets.*/
class Example
{
public:
    // CONSTRUCTOR:
    Example();
    Example(std::string t_exampleName, std::string t_goalName, bool t_goal);

    // MUTATORS:
    void addAttribute(std::string t_attributeName, double t_value);
    void removeAttribute(std::string t_attributeName);
    void removeAttribute(std::string t_attributeName, double t_value);
    void clearAttributes();

    //ACCESSORS:
    std::string const getExampleName();
    std::vector<Attribute> const getInputAttributes();
    std::string const getGoalName();
    bool const getGoal();

private:
    std::string m_exampleName; // Input name. such as x1, x2
    std::vector<Attribute> m_inputAttributes; // "Hungry? -> Yes"
    std::string m_goalName; // The output of the example.
    bool m_goal; // The binary output of the example
};

#endif