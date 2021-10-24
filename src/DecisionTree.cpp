#include "DecisionTree.hpp"

// TODO: CHANGE NODES TO A SMART POINTER TO PREVENT MEMORY LEAKS
template <class T> DecisionTree<T>::DecisionTree()
{
    nodes = nullptr;
}

template <class T> DecisionTree<T>::DecisionTree(std::string t_attributeName)
{
    this->attributeName = t_attributeName;
    *nodes = std::map<std::string, DecisionTree>(); //New map object in stack memory
}

/*Add a leaf to the Decision Tree. Each leaf is a terminal node.
This is where the decision of attributes take place.*/
template <class T> void DecisionTree<T>::addLeaf(std::string t_attributeValue, std::string t_decision)
{
    //DecisionTreeLeaf newLeaf(t_decision);
    DecisionTree newLeaf(t_decision);
    nodes->insert(std::pair<std::string, DecisionTree>(t_attributeValue, newLeaf));
}

template <class T> T DecisionTree<T>::predict(Example t_example)
{
    std::string value = t_example.getAttributeValueString(this->attributeName);
    bool found = false;

} 

/*Add a node to the Decision Tree. This will continue until it
reaches a leaf, where a decision is made.*/
template <class T> void DecisionTree<T>::addNode(std::string t_attributeValue, DecisionTree t_tree)
{
    nodes->insert(std::pair<std::string, DecisionTree>(t_attributeValue, t_tree));
}

/*====================DECISION TREE LEAF DEFINITIONS=======================*/

template <class T> DecisionTreeLeaf<T>::DecisionTreeLeaf(std::string t_attributeValue)
{
    m_attributeValue = t_attributeValue;
}

template <class T> std::string const DecisionTreeLeaf<T>::getAttributeValue()
{
    return this->m_attributeValue;
}

template <class T> void DecisionTreeLeaf<T>::setAttributeValue(std::string t_attributeValue)
{
    m_attributeValue = t_attributeValue;
}

/*Override virtual function from Decision Tree class.*/
template <class T> void DecisionTreeLeaf<T>::addLeaf()
{
    std::cout << "Cannot add leaf to a leaf!\n";
}

/*Override virtual function from Decision Tree class.*/
template <class T> void DecisionTreeLeaf<T>::addNode()
{
    std::cout << "Cannot add node to a leaf!\n";
}

/*Override virtual function from Decision Tree class.*/
template <class T> T DecisionTreeLeaf<T>::predict()
{
    return this->m_attributeValue;
}

template <class T> std::string DecisionTreeLeaf<T>::toString()
{
    return "Decision: " + this->m_attributeValue;
}

int main()
{
    return 0;
}
