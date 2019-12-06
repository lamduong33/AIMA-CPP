#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <iostream>
#include <vector>
#include <map>

/* Attributes class is a class that holds numeric value and a name
 * for a certain Attributes via a hash map. The hashmap holds information
 * regarding each attribute.
 */
class Attributes
{
public:
    Attributes();
    void addAttribute(std::string t_attributeName, double t_attributeValue);
    void removeAttribute(std::string t_attributeName);
    void changeValue(std::string t_attributeName, double t_attributeValue);
    bool hasAttribute(std::string t_attributeName);
    double getAttributeValue(const std::string t_attributeName);
    bool isEmpty();

    std::string toString();

    std::map<std::string, double> getMap();
private:
    std::map<std::string, double> m_mapOfAttributes;
};

#endif