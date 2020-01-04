#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <string>

class Attribute
{
public:
	Attribute();
	Attribute(std::string value, std::string name);
	std::string getValue();
	std::string getName();
	void setName(std::string t_name);
	void setValue(std::string t_value);
private:
	std::string attributeValue;
	std::string attributeName;
};


#endif