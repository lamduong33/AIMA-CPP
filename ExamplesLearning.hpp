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

template <typename T> // 
class Attribute
{
public:
    Attribute();
    Attribute(std::string t_attributeName, T t_attributeValue)
    T getAttributeValue();
    std::string getAttributeName();
    void setAttributeValue;
    void setAttributeName;
private:
    std::string attributeName;
    T attributeValue;
};

class Example
{
public:
    Example();
    Example(std::string t_exampleName, std::string t_exampleType, std::string t_goalName, bool t_goal);
    void addAttribute(std::string t_attributeName, int t_value);
    void removeAttribute(std::string t_attributeName);
    void removeAttribute(std::string t_attributeName, int t_value);
    void clearAttributes();
    std::string getExampleName();
    std::string getExampleType();
    std::vector<Attribute> getInputAttributes();
    std::string getGoalName();
    bool getGoal();
private:
    std::string exampleName;
    std::string exampleType;
    std::vector<Attribute> inputAttributes;
    std::string goalName;
    bool goal;
};
class DecisionTree
{
    DecisionTree();
    DecisionTree(Example::Attribute attribute);
};

DecisionTree decisionTreeLearning(std::vector<Example> t_examples,
    std::vector<Example::Attribute> t_attributes, std::vector<Example> t_parentExamples);
DecisionTree pluralityValue(std::vector<Example> t_examples);
int importance(Example::Attribute attribute, std::vector<Example> examples);
bool sameClassification(std::vector<Example> examples);

#endif /*EXAMPLESLEARNING_H_*/