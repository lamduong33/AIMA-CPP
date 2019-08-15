#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <iostream>
#include <vector>
#include <map>



/* AttributeType class is a map that allows the translation
 * of numeric value to a string value and vice versa. 
 * This allows for a more fluid Attribute. Assign numeric 
 * value to denote something which is translated to string. */
class AttributeType
{
public:
    //CONSTRUCTOR:

    AttributeType();
    AttributeType(std::string t_attributeName);

    // MUTATORS:

    void addValue(double t_value, std::string t_valueName);
    void deleteValue(double t_value);
    void deleteValue(std::string t_valueName);

    // ACCESSORS

    std::string getAttributeName();
    std::string getValueName(double t_value);
    double getValue(std::string t_valueName);
    std::map<double, std::string> getMapOfValues();
    bool mapContainsKey(double t_value);
    bool mapContainsValue(std::string t_valueName);
private:
    std::string attributeName;
    std::map<double, std::string> mapOfValues;
};

class AttributeTypesList
{
public:
    AttributeTypesList();
    void addAttributeType(AttributeType t_attributeType);
    void removeAttributeType(std::string t_attributeName);
    bool containsAttribute(std::string t_attributeName);
    std::string valueToName(double t_attributeValue, std::string t_attributeName);
    double nameToValue(double t_attributeValue, std::string t_attributeName);
private:
    std::vector<AttributeType> listOfAttributeTypes;

};

class Attribute
{
public:
    Attribute(double t_attributeValue, std::string t_attributeName);
    void setAttributeValue(double t_attributeValue);
    void setAttributeName(std::string t_attributeName);
    double getAttributeValue();
    std::string getAttributeName();
    std::string getAttributeValueName();
private:
    std::string attributeName;
    double attributeValue;
};

#endif