/*
 * @Author: Lam Duong
 * @Description: For decision-tree learning. Implements Attribute classes
 *               from Attribute.hpp file.
 *               This includes AttributeType, AttributeTypesList, Attribute.
 */

#include <iostream>
#include <string>
#include <map>
#include "Attributes.hpp"

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

<<<<<<< HEAD:Attributes.cpp
=======
void Attributes::changeValue(std::string t_attributeName, double t_attributeValue)
{
    bool found;
    for (auto const& key: m_mapOfAttributes)
    {
        if (key.first == t_attributeName)
        {
            found = true;
            m_mapOfAttributes[key.first] = t_attributeValue;
        }
    }
}

>>>>>>> f67ee40beecd8e189c93695c1ceca434f6841584:Attribute.cpp
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

/* Return the value of an attribute, given its name*/
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

bool Attributes::isEmpty()
{
    bool empty = false;
    if (m_mapOfAttributes.empty == true)
    {
        empty = true;
    }
    return empty;
}


/* Return the map that holds all the attributes*/
std::map<std::string, double> Attributes::getMap()
{
    return m_mapOfAttributes;
}

std::string Attributes::toString()
{
    std::string result = "";
    for (auto const& key : m_mapOfAttributes)
    {
        result = result + "Attribute: " + key.first;
        result = result + " | Value: " + std::to_string(key.second) + "\n";
    }
}