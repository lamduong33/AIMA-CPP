/*
 * @Author: Lam Duong
 * @Description: For learning from examples. 
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include "math.h"
#include "ExamplesLearning.hpp"

/* Description: AttributeType constructor with attributeName.*/
AttributeType::AttributeType(std::string t_attributeName):
    m_attributeName(t_attributeName){}

/* Function: addValue(t_value, t_valueName)
 * Parameters: double, string
 * Description: Add a value and its name to the map of values.
 *              The numeric value will be the key and value name as mapped item.*/
void AttributeType::addValue(double t_value, std::string t_valueName)
{
    // If the key and value aren't already in the map of values
    if (mapContainsKey(t_value) || mapContainsValue(t_valueName))
    {
        m_mapOfValues.insert(std::pair<double, std::string>(t_value, t_valueName));
    }
    else
    {
        std::string errorMessage = "Cannot add value because the value or its value name";
        errorMessage += "is already in the map of values";
        throw std::invalid_argument(errorMessage);
    }
}

/* Delete value by a numeric value.*/
void AttributeType::deleteValue(double t_value)
{
    m_mapOfValues.erase(t_value);
}

/* Delete value by the name of the value*/
void AttributeType::deleteValue(std::string t_valueName)
{
    for (auto const& key : m_mapOfValues)
    {
        if (key.second == t_valueName)
        {
           m_mapOfValues.erase(key.first);
        }
    }
}


/* Return the name of the AttributeType. */
std::string const AttributeType::getAttributeName()
{
    return m_attributeName;
}

/*Get the value name of a value given its numeric value*/
std::string const AttributeType::getValueName(double t_value)
{
    return m_mapOfValues.at(t_value);
}

/* Function: getValue(t_value)
 * Parameters: string
 * Return: double
 * Description: get the numeric value of a value given a value name*/
double AttributeType::getValue(std::string t_valueName)
{
    bool found = false;
    double value = 0;
    for (auto const& key : m_mapOfValues)
    {
        if (key.second == t_valueName)
        {
            found = true;
            value = key.first;
        }
    }
    if (found == false)
    {
        throw std::invalid_argument("No value by that name found in map of Attributes.");
    }
    return value;
}

/*Return the map of values of the AttributeType*/
std::map<double, std::string> const AttributeType::getMapOfValues()
{
    return m_mapOfValues;
}

/* Function: mapContainsKey(t_value)
 * Parameters: double
 * Return: bool
 * Description: Check whether the map contains a key with a specific
 *              numeric value. */
bool AttributeType::mapContainsKey(double t_value)
{
    bool isInMap = false;
    for (auto const& key : m_mapOfValues)
    {
        if (key.first == t_value)
        {
            isInMap = true;
            break;
        }
    }
    return isInMap;
}

/* Function: mapContainsValue(t_valueName)
 * Parameters: string
 * Return: bool
 * Description: Check whether the map contains a value with the given name.*/
bool AttributeType::mapContainsValue(std::string t_valueName)
{
    bool isInMap = false;
    for (auto const& key : m_mapOfValues)
    {
        if (key.second == t_valueName)
        {
            isInMap = true;
            break;
        }
    }
    return isInMap;
}

/*Empty constructor to get the list of AttributeType started.*/
AttributeTypesList::AttributeTypesList(){}

/*Add an AttributeType to the list*/
void AttributeTypesList::addAttributeType(AttributeType t_attributeType)
{
    m_listOfAttributeTypes.push_back(t_attributeType);
}

/* Function: removeAttributeType(attributeName)
 * Parameters: string
 * Description: Remove an attribute from listOfAttributeTypes given its name.*/
void AttributeTypesList::removeAttributeType(std::string attributeName)
{
    for (int i = 0; i < m_listOfAttributeTypes.size; i++)
    {
        if (m_listOfAttributeTypes.at(i).getAttributeName() == attributeName)
        {
            m_listOfAttributeTypes.erase(m_listOfAttributeTypes.begin()+i);
        }
    }
}

/* Function: containsAttribute(attributeName)
 * Parameters: string
 * Return: bool
 * Description: Returns true if the Attribute of that name is in the list.*/
bool AttributeTypesList::containsAttribute(std::string attributeName)
{
    bool found = false;
    for (int i = 0; i < m_listOfAttributeTypes.size; i++)
    {
        if (m_listOfAttributeTypes[i].getAttributeName() == attributeName)
        {
            found = true;
            break;
        }
    }
    return found;
}

/* Function: valueToName(t_attributeValue, t_attributeName)
 * Parameters: double, string
 * Return: string
 * Description: Return a string, the name of the value, given
 *              its numeric value.
 *              Example: given value of 3 with attribute name of "Hungry?"
 *              The function will return "very hungry", which is mapped to 3. */
std::string AttributeTypesList::valueToName(double t_attributeValue, std::string t_attributeName)
{
    std::string nameOfValue;
    bool found = false;
    for (int index = 0; index < m_listOfAttributeTypes.size; index++)
    {
        if (m_listOfAttributeTypes[index].getAttributeName() == t_attributeName)
        {
            for (auto const& key : m_listOfAttributeTypes[index].getMapOfValues())
            {
                if (key.first == t_attributeValue)
                {
                    found = true;
                    nameOfValue = key.second;
                }
            }
        }
    }
    if (found == false)
    {
        throw std::invalid_argument("No attribute value of that name and numeric value was found.");
    }
    return nameOfValue;
}

/* IMPLEMENT ONLY IF NEEDED
double AttributeTypesList::nameToValue(double t_attributeValue, std::string t_attributeName){}*/

/* Function: Attribute(t_attributeName, t_attributeValue)
 * Parameters: string, double
 * Description: Simple constructor that instantiate initial values.*/
Attribute::Attribute(double t_attributeValue, std::string t_attributeName):
    m_attributeValue(t_attributeValue), m_attributeName(t_attributeName){}

/* Set the value of the Attribute to the given value.*/
void Attribute::setAttributeValue(double t_attributeValue)
{
   m_attributeValue = t_attributeValue;
}

/* Set the name of the attribute to the given name.*/
void Attribute::setAttributeName(std::string t_attributeName)
{
    m_attributeName = t_attributeName;
}

/* Get the value of the attribute.*/
double const Attribute::getAttributeValue()
{
    return m_attributeValue;
}

/* Get the name of the attribute.*/
std::string const Attribute::getAttributeName()
{
    return m_attributeName;
}

/* Function: Example(exampleName, exampleType, goalName, goal)
 * Parameters: string, string, string, bool
 * Description: A constructor member function that will create an example
 *              with no input attributes initially. Refer to addAttribute()
 *              for population of attributes. */
 Example::Example(std::string t_exampleName, std::string t_goalName, bool t_goal) :
    m_exampleName(t_exampleName), m_goalName(t_goalName), m_goal(t_goal){}


/* Added */
void Example::addAttribute(std::string t_attributeName, double t_value)
{
    Attribute attribute(t_value, t_attributeName);
    m_inputAttributes.push_back(attribute);
}

/* Function: removeAttribute(t_attributeName)
 * Parameters: string
 * Return: void
 * Description: Remove every attribute with this name.*/
void Example::removeAttribute(std::string t_attributeName)
{
    for (int index = 0; index < m_inputAttributes.size; index++)
    {
        if (m_inputAttributes[index].getAttributeName() == t_attributeName)
        {
            m_inputAttributes.erase(m_inputAttributes.begin()+index);
        }
    }
}

/* Function: removeAttribute(t_attributeName, t_value)
 * Parameters: string
 * Return: void
 * Description: Overloading: Remove every attribute with this name and value*/
void Example::removeAttribute(std::string t_attributeName, double t_value)
{
    bool attributeFound = false;
    for (int index = 0; index < m_inputAttributes.size; index++)
    {
        if ((m_inputAttributes[index].getAttributeName() == t_attributeName)
        && (m_inputAttributes[index].getAttributeValue() == t_value))
        {
            attributeFound = true;
            m_inputAttributes.erase(m_inputAttributes.begin()+index);
        }
    }
}

/* Clear all attributes in the example */
void Example::clearAttributes()
{
    this->m_inputAttributes.clear();
}

/* Get the name of the example */
std::string const Example::getExampleName()
{
    return m_exampleName;
}

/* Get the attributes in a form a vector */
std::vector<Attribute> const Example::getInputAttributes()
{
    return m_inputAttributes;
}

/* Get the name of the goal as a string */
std::string const Example::getGoalName()
{
    return m_goalName;
}

/* Get the goal of example as a boolean value */
bool const Example::getGoal()
{
    return m_goal;
}

/* Empty constructor for a decision tree */
DecisionTree::DecisionTree(){}

/* DecisionTree constructor that takes in an Attribute object */
DecisionTree::DecisionTree(Attribute t_attribute):
    m_attribute(t_attribute){}

/* Function: decisionTreeLearning(examples, attributes, parentExamples)
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

/* Function: pluralityValue(t_examples)
 * Parameters: vector<Example>
 * Return: DecisionTree
 * Description: Selects the most common output values among a set of examples, 
 *              breaking ties randomly.*/
DecisionTree pluralityValue(std::vector<Example> t_examples)
{
    DecisionTree decisionTree;
    return decisionTree;
}

/* Function: importance(attribute, examples)
 * Parameters: Attribute, vector<Example>
 * Return: int
 * Description: This finds the information gain, which is the attribute test
 *              on an attribute, A, and the expected reduction in entropy.
 *              This returns the amount of bits (from 0 to 1), so it should not
 *              return anything that's not in between that range. */
int importance(Attribute attribute, std::vector<Example> examples)
{
    // Find entropy, H(attribute)
    // Find Remainder(attribute)
    // Find Gain(attribute)
}

/* Function: sameClassification(examples)
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

int main()
{
    return 0;
}