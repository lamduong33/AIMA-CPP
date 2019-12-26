#include "Example.hpp"

Example::Example(){}

Example::Example(std::string t_exampleName, std::string t_goalName, int t_goal)
{
    m_exampleName = t_exampleName;
    m_goalName = t_goalName;
    m_goal = t_goal;
}

void Example::setExampleName(std::string t_exampleName)
{
    m_exampleName = t_exampleName;
}

void Example::setGoalName(std::string t_goalName)
{
    m_goalName = t_goalName;
}

void Example::setGoal(int t_goal)
{
    m_goal = t_goal;
}

std::string const Example::getExampleName()
{
    return m_goalName;
}

Attributes const Example::getInputAttributes()
{
    return m_inputAttributes;
}

std::string const Example::getGoalName()
{
    return m_goalName;
}

bool const Example::getGoal()
{
    return m_goal;
}

