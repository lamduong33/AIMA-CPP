#ifndef DECISIONTREE_HPP
#define DECISIONTREE_HPP

#include "Attributes.hpp"
#include "Example.hpp"
#include <vector>

/* A Decision tree class. This class will have nodes and leaves. It
will recursively add nodes and leaves. Leaves have their own special
class, DecisionTreeLeaf.*/
class DecisionTree
{
public:
    DecisionTree();
    DecisionTree(std::vector<Example> t_examples);    
    void addLeaf();
    void addNode();
private:
    std::vector<Attributes> m_attributes;
    DecisionTreeLeaf m_nodes;
};

/* A decision tree leaf node that inherits from Decision tree. It will
not go any further. */
class DecisionTreeLeaf : public DecisionTree
{
public:
    DecisionTreeLeaf(double t_attributeValue);
    double const getAttributeValue();
    void setAttributeValue();
private:
    double m_attributeValue;
};


#endif