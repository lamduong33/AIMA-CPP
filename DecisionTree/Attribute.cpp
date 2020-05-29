#include "Attribute.hpp"

/* Empty constructor */
Attribute::Attribute()
{
	this->attributeName = "";
	this->attributeValue = "";
}

/* Default constructor */
Attribute::Attribute(std::string t_value, std::string t_name)
{
	this->attributeName = t_name;
	this->attributeValue = t_value;
}

std::string Attribute::getValue()
{
	return this->attributeValue;
}

std::string Attribute::getName()
{
	return this->attributeName;
}

void Attribute::setName(const std::string t_name)
{
	this->attributeName = t_name;
}

void Attribute::setValue(const std::string t_value)
{
	this->attributeValue = t_value;
}
