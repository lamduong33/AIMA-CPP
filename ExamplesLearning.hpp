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
#include "Attribute.hpp"

/* A class made for individual examples. These examples will
contain example name and attributes (input), goal name and 
value (output). This is primarily used for training sets.*/
class Example
{
public:

    // CONSTRUCTOR

    Example();
    Example(std::string t_exampleName, std::string t_goalName, bool t_goal);

    // MUTATORS:

    void addAttribute(std::string t_attributeName, double t_value);
    void removeAttribute(std::string t_attributeName);
    void removeAttribute(std::string t_attributeName, double t_value);
    void clearAttributes();

    //ACCESSORS:

    std::string const getExampleName();
    std::vector<Attribute> const getInputAttributes();
    std::string const getGoalName();
    bool const getGoal();

private:

    std::string m_exampleName;
    std::vector<Attribute> m_inputAttributes;
    std::string m_goalName;
    bool m_goal;

};
/*A Decision tree class. This class will have nodes and leaves. It
will recursively add nodes and leaves. Leaves have their own special
class, DecisionTreeLeaf.*/
class DecisionTree
{
public:
    DecisionTree();
    DecisionTree(Attribute t_attribute);    
    void addLeaf();
    void addNode();
private:
    Attribute m_attribute;
    std::map<Attribute,DecisionTree> m_nodes;
};

/*A decision tree leaf node that inherits from Decision tree. It will
not create any further */
class DecisionTreeLeaf : public DecisionTree
{
public:
    DecisionTreeLeaf(double t_attributeValue);
    double const getAttributeValue();
    void setAttributeValue();
private:
    double m_attributeValue;
};


DecisionTree decisionTreeLearning(std::vector<Example> t_examples,
    std::vector<Attribute> t_attributes, std::vector<Example> t_parentExamples);
DecisionTree pluralityValue(std::vector<Example> t_examples);
int importance(Attribute attribute, std::vector<Example> examples);
bool sameClassification(std::vector<Example> examples);

#endif /*EXAMPLESLEARNING_H_*/