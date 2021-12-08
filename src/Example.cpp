#include "Example.hpp"

/*Standard constructor for example class. Must provide attributes and target
attribute.*/
Example::Example(std::map<std::string, Attribute>& t_attributes,
                 Attribute& t_mainAttribute)
    : m_attributes{t_attributes}, m_mainAttribute{t_mainAttribute} {};

/*Get the value of the attribute as a string.*/
std::string Example::getAttributeValueString(std::string t_attributeName)
{
    return m_attributes.at(t_attributeName).getValue();
}

/*Get attribute value as a double. Some conversion is required.*/
double Example::getAttributeValue(std::string t_attributeName)
{
    auto targetAttribute = m_attributes.at(t_attributeName);
    return std::stod(targetAttribute.getValue());
}

Attribute Example::getMainAttribute() { return m_mainAttribute; }
