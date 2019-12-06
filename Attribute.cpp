/*
 * @Author: Lam Duong
 * @Description: For decision-tree learning. Implements Attribute classes
 *               from Attribute.hpp file.
 *               This includes AttributeType, AttributeTypesList, Attribute.
 */

#include <iostream>
#include <map>
#include "Attribute.hpp"

Attributes::Attributes(){}

/* Add an attribute to the list of attributes. */
void Attributes::addAttribute(std::string t_attributeName, double t_attributeValue)
{
    m_mapOfAttributes.insert(std::pair<std::string, double> (t_attributeName, t_attributeValue));
}

/* Remove the attribute given the name */
void Attributes::removeAttribute(std::string t_attributeName)
{
    this->m_mapOfAttributes.erase(t_attributeName);
}



/* Check to see if the map has the attribute */
bool Attributes::hasAttribute(std::string t_attributeName)
{
    bool isInMap = false;
    for (auto const& key : m_mapOfAttributes)
    {
        if (key.first == t_attributeName)
        {
            isInMap = true;
            break;
        }
    }
    return isInMap;
}

/* Return the value of an attribute */
double Attributes::getAttributeValue(const std::string t_attributeName)
{
    bool found = false;
    double value = 0;
    for (auto const& key : m_mapOfAttributes)
    {
        if (key.first == t_attributeName)
        {
            found = true;
            value = key.second;
        }
    }
    if (found == false)
    {
        std::string errorMessage = t_attributeName;
        errorMessage = errorMessage + " was not found in the list of attributes!\n";
        throw std::invalid_argument(errorMessage);
    }
    return value;
}


/* Return the map that holds all the attributes*/
std::map<std::string, double> Attributes::getMap()
{
    return m_mapOfAttributes;
}