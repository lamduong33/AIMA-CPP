#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <string>

/* An attribute class is used to map an attribute to a value. Most of the time,
this is not neccessary. Only use for multi-label categorical classification.*/
class Attribute
{
public:
    /* Empty constructor with empty initial values*/
    Attribute();

    /* Default constructor that takes in a string value and a string name */
    Attribute(std::string value, std::string name);

    std::string getValue();
    std::string getName();
    void setName(const std::string t_name);
    void setValue(const std::string t_value);

private:
    std::string attributeValue;
    std::string attributeName;
};

#endif
