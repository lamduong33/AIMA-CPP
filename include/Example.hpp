#ifndef EXAMPLE_HPP
#define EXAMPLE_HPP

#include "Attribute.hpp"
#include <iostream>
#include <map>
#include <vector>

/* A class made for individual examples for learning.*/
class Example
{
public:
    Example(std::map<std::string, Attribute>& t_attributes,
            Attribute& t_mainAttribute);
    std::string getAttributeValueString(std::string t_attributeName);
    double getAttributeValue(std::string t_attributeName);
    Attribute getMainAttribute();

private:
    // Attribute attribute;
    std::map<std::string, Attribute> m_attributes;
    Attribute m_mainAttribute;
};

#endif
