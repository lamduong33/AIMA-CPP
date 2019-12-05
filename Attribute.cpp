/*
 * @Author: Lam Duong
 * @Description: For decision-tree learning. Implements Attribute classes
 *               from Attribute.hpp file.
 *               This includes AttributeType, AttributeTypesList, Attribute.
 */

#include <iostream>
#include <map>
#include "Attribute.hpp"

/*---------------------------- ATTRIBUTETYPE---------------------------------*/

/* Description: AttributeType constructor with attributeName.*/
AttributeType::AttributeType(std::string t_attributeName):
    m_attributeName(t_attributeName){}

/* Add a value and its name to the map of values.
 * The numeric value will be the key and value name as mapped item.*/
void AttributeType::addValue(double t_value, std::string t_valueName)
{
    // If the key and value aren't already in the map of values
    if (mapContainsKey(t_value) || mapContainsValue(t_valueName))
    {
        m_mapOfValues.insert(std::pair<double, std::string>(t_value, t_valueName));
    }
    else
    {
        std::string errorMessage = "Cannot add value because the value or its value name";
        errorMessage += "is already in the map of values";
        throw std::invalid_argument(errorMessage);
    }
}

/* Delete value by a numeric value.*/
void AttributeType::deleteValue(double t_value)
{
    m_mapOfValues.erase(t_value);
}

/* Delete value by the name of the value*/
void AttributeType::deleteValue(std::string t_valueName)
{
    for (auto const& key : m_mapOfValues)
    {
        if (key.second == t_valueName)
        {
            m_mapOfValues.erase(key.first);  
        }
    }
}

/* Return the name of the AttributeType. */
std::string const AttributeType::getAttributeName()
{
    return m_attributeName;
}

/*Get the value name of a value given its numeric value*/
std::string const AttributeType::getValueName(double t_value)
{
    return m_mapOfValues.at(t_value);
}

/* Get the numeric value of a value given a value name*/
double AttributeType::getValue(std::string t_valueName)
{
    bool found = false;
    double value = 0;
    for (auto const& key : m_mapOfValues)
    {
        if (key.second == t_valueName)
        {
            found = true;
            value = key.first;
        }
    }
    if (found == false)
    {
        throw std::invalid_argument("No value by that name found in map of Attributes.");
    }
    return value;
}

/*Return the map of values of the AttributeType*/
std::map<double, std::string> const AttributeType::getMapOfValues()
{
    return m_mapOfValues;
}

/* Check whether the map contains a key with a specific numeric value. */
bool AttributeType::mapContainsKey(double t_value)
{
    bool isInMap = false;
    for (auto const& key : m_mapOfValues)
    {
        if (key.first == t_value)
        {
            isInMap = true;
            break;
        }
    }
    return isInMap;
}

/* Check whether the map contains a value with the given name.*/
bool AttributeType::mapContainsValue(std::string t_valueName)
{
    bool isInMap = false;
    for (auto const& key : m_mapOfValues)
    {
        if (key.second == t_valueName)
        {
            isInMap = true;
            break;
        }
    }
    return isInMap;
}





/*--------------------------ATTRIBUTETYPESLIST-------------------------------*/

/*Empty constructor to get the list of AttributeType started.*/
AttributeTypesList::AttributeTypesList(){}

/*Add an AttributeType to the list*/
void AttributeTypesList::addAttributeType(AttributeType t_attributeType)
{
    m_listOfAttributeTypes.push_back(t_attributeType);
}

/* Remove an attribute from listOfAttributeTypes given its name.*/
void AttributeTypesList::removeAttributeType(std::string t_attributeName)
{
    for (int i = 0; i < m_listOfAttributeTypes.size; i++)
    {
        if (m_listOfAttributeTypes.at(i).getAttributeName() == t_attributeName)
        {
            m_listOfAttributeTypes.erase(m_listOfAttributeTypes.begin()+i);
        }
    }
}

/* Returns true if the Attribute of that name is in the list.*/
bool AttributeTypesList::containsAttribute(std::string attributeName)
{
    bool found = false;
    for (int i = 0; i < m_listOfAttributeTypes.size; i++)
    {
        if (m_listOfAttributeTypes[i].getAttributeName() == attributeName)
        {
            found = true;
            break;
        }
    }
    return found;
}

/* Return a string, the name of the value, given
 * its numeric value.
 * Example: given value of 3 with attribute name of "Hungry?"
 * The function will return "very hungry", which is mapped to 3. */
std::string AttributeTypesList::valueToName(double t_attributeValue, std::string t_attributeName)
{
    std::string nameOfValue;
    bool found = false;
    for (int index = 0; index < m_listOfAttributeTypes.size; index++)
    {
        if (m_listOfAttributeTypes[index].getAttributeName() == t_attributeName)
        {
            for (auto const& key : m_listOfAttributeTypes[index].getMapOfValues())
            {
                if (key.first == t_attributeValue)
                {
                    found = true;
                    nameOfValue = key.second;
                }
            }
        }
    }
    if (found == false)
    {
        throw std::invalid_argument("No attribute value of that name and numeric value was found.");
    }
    return nameOfValue;
}

/* IMPLEMENT ONLY IF NEEDED
double AttributeTypesList::nameToValue(double t_attributeValue, std::string t_attributeName){}*/



/*-----------------------------ATTTRIBUTE-------------------------------------*/

/* Simple constructor that instantiate initial values.*/
Attribute::Attribute(double t_attributeValue, std::string t_attributeName):
    m_attributeValue(t_attributeValue), m_attributeName(t_attributeName){}

/* Set the value of the Attribute to the given value.*/
void Attribute::setAttributeValue(double t_attributeValue)
{
   m_attributeValue = t_attributeValue;
}

/* Set the name of the attribute to the given name.*/
void Attribute::setAttributeName(std::string t_attributeName)
{
    m_attributeName = t_attributeName;
}

/* Get the value of the attribute.*/
double const Attribute::getAttributeValue()
{
    return m_attributeValue;
}

/* Get the name of the attribute.*/
std::string const Attribute::getAttributeName()
{
    return m_attributeName;
}