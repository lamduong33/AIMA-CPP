/*
 * Matrix.h
 *
 *  Created on: Aug 3, 2019
 *      Author: Lam Duong
 */

#ifndef EXAMPLESLEARNING_H_
#define EXAMPLESLEARNING_H_

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "math.h"

class Example
{
public:
    Example(std::string exampleName, std::string exampleType, std::string goalName, bool goal);
    void addAttribute(std::string attributeName, int value);
    struct Attribute
    {
        std::string attributeName;
        int value;
    };
private:
    std::string exampleName;
    std::string exampleType;
    std::vector<Attribute> inputAttributes;
    std::string goalName;
    bool goal;
};

class DecisionTree
{

};

DecisionTree decisionTreeLearning(std::vector<Example> examples,
    std::vector<Example::Attribute> attributes, std::vector<Example> parentExamples);

DecisionTree pluralityValue(std::vector<Example> examples);

int importance(Example::Attribute attribute, std::vector<Example> examples);
#endif /*EXAMPLESLEARNING_H_*/