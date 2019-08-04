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

Example::Example(std::string exampleName, std::string exampleType, std::string goalName, bool goal)
{
    this->exampleName = exampleName; // Input name
    this->exampleType = exampleType;
    this->goalName = goalName;
    this->goal = goal; // Output, true or false
}
void Example::addAttribute(std::string attributeName, int value)
{
    Example::Attribute attribute = {attributeName, value};
    Example::inputAttributes.push_back(attribute);
}

/*
 * Author: Lam Duong
 * Function: decisionTreeLearning(examples, attributes, parentExamples)
 * Parameters: vector<Example>, vector<Attribute>, vector<Example>
 * Return: DecisionTreee
 * Description: A Decision Tree learning algorithm that will return a tree given
 *              a set of examples. This set of examples will have a corresponding
 *              attributes that match up with the examples' attributes.
 *              Inspiration from the alogirthm by Russell and Norvyg, 3rd Ed.
 */
DecisionTree decisionTreeLearning(std::vector<Example> examples,
    std::vector<Example::Attribute> attributes, std::vector<Example> parentExamples)
{
    DecisionTree resultTree;
    if (examples.empty())
    {
        resultTree = pluralityValue(parentExamples);
    }
    // TODO: Else if all examples have the same classification then return the classification
    else if (attributes.empty())
    {
        resultTree = pluralityValue(examples);
    }
    else
    {
        // A <-argmax Importance(a, examples)
        // tree <- a new decision tree with root test A
        // for each value vk of A do

    }
    return resultTree;
}

DecisionTree pluralityValue(std::vector<Example> examples);

/*
 * Author: Lam Duong
 * Function: importance(attribute, examples)
 * Parameters: Attribute, vector<Example>
 * Return: int
 * Description: This finds the information gain, which is the attribute test
 *              on an attribute, A, and the expected reduction in entropy.
 *              This returns the amount of bits (from 0 to 1), so it should not
 *              return anything that's not in between that range. 
 */
int importance(Example::Attribute attribute, std::vector<Example> examples)
{
    // Find entropy, H(attribute)
    // Find Remainder(attribute)
    // Find Gain(attribute)
}

int main()
{
    return 0;
}