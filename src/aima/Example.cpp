#include "../include/Example.hpp"

Example::Example()
    : m_exampleName{std::string{}},
      m_inputAttributes{std::vector<std::string>{}}, m_output{std::string{}}
{}

Example::Example(std::string& t_exampleName,
                 std::vector<std::string>& t_inputAttributes,
                 std::string& t_output)
    : m_exampleName{t_exampleName},
      m_inputAttributes{t_inputAttributes}, m_output{t_output}
{}

std::string Example::getExampleName() { return this->m_exampleName; }
std::vector<std::string> Example::getAttributes()
{
    return this->m_inputAttributes;
}
std::string Example::getOutput() { return this->m_output; }

void Example::setExampleName(std::string& t_exampleName)
{
    this->m_exampleName = t_exampleName;
}
void Example::setAttributes(std::vector<std::string>& t_attributes)
{
    this->m_inputAttributes = t_attributes;
}
void Example::setOutputs(std::string& t_output) { this->m_output = t_output; }
