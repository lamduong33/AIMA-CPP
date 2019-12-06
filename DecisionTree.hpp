#ifndef DECISIONTREE_HPP
#define DECISIONTREE_HPP

#include "Attribute.hpp"

/* A Decision tree class. This class will have nodes and leaves. It
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