#ifndef EXAMPLES_HPP
#define EXAMPLES_HPP

#include <string>
#include <vector>
#include "Attributes.hpp"

/* A class made for individual examples. These examples will
contain example name and attributes (input), goal name and 
value (output). This is primarily used for training sets.*/
class Example
{
public:
    // CONSTRUCTOR:
    Example();
    Example(std::string t_exampleName, std::string t_goalName, int t_goal);

    // MUTATORS:
    void setExampleName(std::string t_exampleName);
    void setGoalName(std::string t_goalName);
    void setGoal(int t_goal);

    //ACCESSORS:
    std::string const getExampleName();
    Attributes const getInputAttributes();
    std::string const getGoalName();
    bool const getGoal();

private:
    std::string m_exampleName; // Input name. such as x1, x2
    Attributes m_inputAttributes; // "Hungry? -> Yes"
    std::string m_goalName; // The output of the example.
    int m_goal; // The output of the example (preferable binary)
};

#endif