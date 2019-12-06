#include "Example.hpp"
#include <string>

/* A constructor member function that will create an example
 * with no input attributes initially. Refer to addAttribute()
 * for population of attributes. */
Example::Example(std::string t_exampleName, std::string t_goalName, bool t_goal) :
    m_exampleName(t_exampleName), m_goalName(t_goalName), m_goal(t_goal){}


/* Add an attribute by name and value */
void Example::addAttribute(std::string t_attributeName, double t_value)
{
    Attribute attribute(t_value, t_attributeName);
    m_inputAttributes.push_back(attribute);
}

/* Remove every attribute with this name.*/
void Example::removeAttribute(std::string t_attributeName)
{
    for (int index = 0; index < m_inputAttributes.size; index++)
    {
        if (m_inputAttributes[index].getAttributeName() == t_attributeName)
        {
            m_inputAttributes.erase(m_inputAttributes.begin()+index);
        }
    }
}

/* Overloading: Remove every attribute with this name and value*/
void Example::removeAttribute(std::string t_attributeName, double t_value)
{
    bool attributeFound = false;
    for (int index = 0; index < m_inputAttributes.size; index++)
    {
        if ((m_inputAttributes[index].getAttributeName() == t_attributeName)
        && (m_inputAttributes[index].getAttributeValue() == t_value))
        {
            attributeFound = true;
            m_inputAttributes.erase(m_inputAttributes.begin()+index);
        }
    }
}

/* Clear all attributes in the example */
void Example::clearAttributes()
{
    this->m_inputAttributes.clear();
}

/* Get the name of the example */
std::string const Example::getExampleName()
{
    return m_exampleName;
}

/* Get the attributes in a form a vector */
std::vector<Attribute> const Example::getInputAttributes()
{
    return m_inputAttributes;
}

/* Get the name of the goal as a string */
std::string const Example::getGoalName()
{
    return m_goalName;
}

/* Get the goal of example as a boolean value */
bool const Example::getGoal()
{
    return m_goal;
}