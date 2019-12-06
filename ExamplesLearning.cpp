/*
 * @Author: Lam Duong
 * @Description: For learning from examples. 
 */
#include <iostream>
#include "ExamplesLearning.hpp"
#include "Attribute.hpp"
#include "Example.hpp"
#include "DecisionTree.hpp"


int main()
{

    return 0;
}
/* A Decision Tree learning algorithm that will return a tree given
 * a set of examples. This set of examples will have a corresponding
 * attributes that match up with the examples' attributes.
 * Inspiration from the alogirthm by Russell and Norvyg, 3rd Ed. */
DecisionTree decisionTreeLearning(std::vector<Example> t_examples,
    Attributes t_attributes, std::vector<Example> t_parentExamples)
{
    DecisionTree resultTree;

    // if examples is empty then return Plurality-Value(parentExamples)
    // No examples mean that for this tree, there are no examples from
    // the training set have been observed for these attribute values.
    if (t_examples.empty())
    {
        resultTree = pluralityValue(t_parentExamples);
    }

    // Else if all examples have the same classification then return --the classification
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
    else if (t_attributes.getMap().empty)
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

/* Selects the most common output values among a set of examples, 
 * breaking ties randomly.*/
DecisionTree pluralityValue(std::vector<Example> t_examples)
{
    DecisionTree decisionTree;

    // Iterate through the examples
    for (auto const& example: t_examples)
    {
        // Find the most common output
    }

    return decisionTree;
}

/* This finds the information gain, which is the attribute test
 * on an attribute, A, and the expected reduction in entropy.
 * This returns the amount of bits (from 0 to 1), so it should not
 * return anything that's not in between that range. */
int importance(std::string attribute, std::vector<Example> examples)
{
    // Find entropy, H(attribute)
    // Find Remainder(attribute)
    // Find Gain(attribute)
}

/* Simple method that determines whether all examples have the same classiication.*/
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