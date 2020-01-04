#ifndef DECISIONTREE_HPP
#define DECISIONTREE_HPP

#include "Attributes.hpp"
#include "Example.hpp"

/* A Decision tree class. This class will have nodes and leaves. It
will recursively add nodes and leaves. Leaves have their own special
class, DecisionTreeLeaf.*/
template <class T>
class DecisionTree
{
public:
    DecisionTree();
    DecisionTree(std::string t_attributeName);
    void addLeaf(std::string t_attributeValue, std::string t_decision);
    void addNode(std::string _attributeValue, DecisionTree t_tree);
    T predict(Example t_example);
private:
    std::map<std::string, DecisionTree> *nodes;
    std::string attributeName;
};


/* A decision tree leaf node that inherits from Decision tree. It will
not go any further. */

class DecisionTreeLeaf : public DecisionTree
{
public:
    DecisionTreeLeaf(std::string t_attributeValue);
    std::string const getAttributeValue();
    void setAttributeValue(std::string t_attributeValue);
    virtual void addLeaf();
    virtual void addNode();
private:
    std::string m_attributeValue;
};


#endif