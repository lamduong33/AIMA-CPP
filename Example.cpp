#include "Example.hpp"

/*Standard constructor for example class. Must provide attributes and target
attribute.*/
Example::Example(std::map<std::string, Attribute> t_attributes, Attribute t_mainAttribute) : m_attributes{ t_attributes }, m_mainAttribute{ t_mainAttribute } {};

/*Get the value of the attribute as a string.*/
std::string Example::getAttributeValueString(std::string t_attributeName)
{
	return m_attributes.at(t_attributeName).getValue;
}

/*Get attribute value as a double. Some conversion is required.*/
double Example::getAttributeValue(std::string t_attributeName)
{
	Attribute targetAttribute = m_attributes.at(t_attributeName);
	if (&targetAttribute == NULL)
	{
		throw ("Cannot convert a null attribute to double.\n");
	}
	return std::stod(targetAttribute.getValue());
}

Attribute Example::getMainAttribute()
{
	return m_mainAttribute;
}

