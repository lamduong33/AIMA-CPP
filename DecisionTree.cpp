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
    DecisionTreeLeaf newLeaf(t_decision);
    nodes->insert(std::pair<std::string, DecisionTree>(t_attributeValue, newLeaf));
}

template <class T> T DecisionTree<T>::predict(Example t_example)
{
    std::string attributeString = t_example.getInputAttributes();
} 

/*Add a node to the Decision Tree. This will continue until it
reaches a leaf, where a decision is made.*/
template <class T> void DecisionTree<T>::addNode(std::string t_attributeValue, DecisionTree t_tree)
{
    nodes->insert(std::pair<std::string, DecisionTree>(t_attributeValue, t_tree));
}

DecisionTreeLeaf::DecisionTreeLeaf(std::string t_attributeValue)
{
    m_attributeValue = t_attributeValue;
}

std::string const DecisionTreeLeaf::getAttributeValue()
{
    return m_attributeValue;
}

void DecisionTreeLeaf::setAttributeValue(std::string t_attributeValue)
{
    m_attributeValue = t_attributeValue;
}

void DecisionTreeLeaf::addLeaf()
{
    std::cout << "Cannot add leaf to a leaf!\n";
}

void DecisionTreeLeaf::addNode()
{
    std::cout << "Cannot add node to a leaf!\n";
}

int main()
{
    return 0;
}