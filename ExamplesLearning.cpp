/*
 * Author: Lam Duong
 * Description: For learning from examples. Includes functions
 * that compute learning.
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "math.h"
#include "ExamplesLearning.hpp"

// TODO: Empty constructor for Attribute class
Attribute::Attribute(std::string t_attributeName, T t_attributeValue)
{

}

// TODO: Empty constructor for example
Example::Example()
{

} 
/* Author: Lam Duong
 * Function: Example(exampleName, exampleType, goalName, goal)
 * Parameters: string, string, string, bool
 * Description: A constructor member function that will create an example
 *              with no input attributes initially. Refer to addAttribute()
 *              for population of attributes. */
 Example::Example(std::string t_exampleName, std::string t_exampleType, std::string t_goalName, bool t_goal)
    :exampleName(t_exampleName), exampleType(t_exampleType), goalName(t_goalName), goal(t_goal){}

// Example Mutator Member Functions:

void Example::addAttribute(std::string t_attributeName, int t_value)
{
    Attribute attribute = {t_attributeName, t_value};
    Example::inputAttributes.push_back(attribute);
}
// Remove every attribute with this name
void Example::removeAttribute(std::string t_attributeName)
{
    for (int index = 0; index < this->inputAttributes.size; index++)
    {
        if (inputAttributes[index].attributeName == t_attributeName)
        {
            this->inputAttributes.erase(inputAttributes.begin()+index);
        }
    }
}
// Remove every attribute with this name and value
void Example::removeAttribute(std::string t_attributeName, int t_value)
{
    bool attributeFound = false;
    for (int index = 0; index < this->inputAttributes.size; index++)
    {
        if ((inputAttributes[index].attributeName == t_attributeName)
        && (inputAttributes[index].value == t_value))
        {
            attributeFound = true;
            this->inputAttributes.erase(inputAttributes.begin()+index);
        }
    }
    if (attributeFound == false)
    {
        throw std::invalid_argument("Could not find the attribute with given name and value. Nothing was removed.");
    }
}
void Example::clearAttributes()
{
    this->inputAttributes.clear();
}

// Example Accessor Member Functions:

std::string Example::getExampleName()
{
    return this->exampleName;
}
std::string Example::getExampleType()
{
    return this->exampleType;
}
std::vector<Attribute> Example::getInputAttributes()
{
    return this->inputAttributes;
}
std::string Example::getGoalName()
{
    return this->goalName;
}
bool Example::getGoal()
{
    return this->goal;
}

/* Author: Lam Duong
 * Function: decisionTreeLearning(examples, attributes, parentExamples)
 * Parameters: vector<Example>, vector<Attribute>, vector<Example>
 * Return: DecisionTree
 * Description: A Decision Tree learning algorithm that will return a tree given
 *              a set of examples. This set of examples will have a corresponding
 *              attributes that match up with the examples' attributes.
 *              Inspiration from the alogirthm by Russell and Norvyg, 3rd Ed. */
DecisionTree decisionTreeLearning(std::vector<Example> t_examples,
    std::vector<Attribute> t_attributes, std::vector<Example> t_parentExamples)
{
    DecisionTree resultTree;

    // if examples is empty then return Plurality-Value(parentExamples)
    // No examples mean that for this tree, there are no examples from
    // the training set have been observed for these attribute values.
    if (t_examples.empty())
    {
        resultTree = pluralityValue(t_parentExamples);
    }

    // Else if all examples have the same classification then return the classification
    else if (sameClassification(t_examples))
    {
        // TODO: Return the classification as a decision tree here
        // Classification here being the attribute that they all have in common
        // Example: If restaurant is FULL (attribute), and all of them return negative
        //          Then the function should return a decision tree with FULL attributes
        //          leading to that negative return.
    }

    // else if attributes is empty, then return Plurality-Value(examples)
    // 
    else if (t_attributes.empty())
    {
        resultTree = pluralityValue(t_examples);
    }
    else
    {
        // A <-argmax Importance(a, examples)
        // tree <- a new decision tree with root test A
        // for each value vk of A do
    }
    return resultTree;
}

/* Author: Lam Duong
 * Function: pluralityValue(t_examples)
 * Parameters: vector<Example>
 * Return: DecisionTree
 * Description: Selects the most common output values among a set of examples, 
 *              breaking ties randomly.*/
DecisionTree pluralityValue(std::vector<Example> t_examples)
{

    DecisionTree decisionTree(modalValue);
    return decisionTree;
}

/* Author: Lam Duong
 * Function: importance(attribute, examples)
 * Parameters: Attribute, vector<Example>
 * Return: int
 * Description: This finds the information gain, which is the attribute test
 *              on an attribute, A, and the expected reduction in entropy.
 *              This returns the amount of bits (from 0 to 1), so it should not
 *              return anything that's not in between that range. */
int importance(Example::Attribute attribute, std::vector<Example> examples)
{
    // Find entropy, H(attribute)
    // Find Remainder(attribute)
    // Find Gain(attribute)
}

/* Author: Lam Duong
 * Function: sameClassification(examples)
 * Parameters: vector
 * Return: bool
 * Description: Simple method that determines whether all examples have the same classiication.*/
bool sameClassification(std::vector<Example> examples)
{
    bool sameClassification = true;
    bool goal;
    for (int index = 0; index < examples.size; index++)
    {
        if (index == 0)
        {
            // Set the goal to be matched intially
            goal = examples[index].getGoal();
            continue;
        }
        else
        {
            // Continue, if goal is not the same, then false.
            if (goal != examples[index].getGoal())
            {
                sameClassification = false;
                break;
            }
        }
    }
    return sameClassification;
}

ExamplesLearning::DecisionTree

int main()
{
    return 0;
}