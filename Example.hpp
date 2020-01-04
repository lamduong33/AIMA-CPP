#ifndef EXAMPLE_HPP
#define EXAMPLE_HPP

#include <string>
#include <vector>
#include "Attribute.hpp"

/* A class made for individual examples for learning.*/
class Example
{
public:
	Example();
	~Example();
private:
	//Attribute attribute;
	std::map<std::string, Attribute> attributes;
};

#endif 