#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <string>

/**
 * An attribute class is used to map an attribute to a value. Most of the time,
 * this is not neccessary. Should be used for multi-label categorical
 * classification. Attributes are meant to be used as inputs for machine
 * learning models.*/
template <class T>
class Attribute
{
    T m_attributeValue;
    std::string m_attributeName;
public:
    /* Empty constructor with empty initial values*/
    Attribute();

    /* Default constructor that takes in a string value and a string name */
    Attribute(T& t_value, std::string& name);

    T getValue();
    std::string getName();
    void setName(std::string t_name);
    void setValue(T& t_value);
};

#endif
