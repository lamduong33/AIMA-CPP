#ifndef DECISIONTREE_HPP
#define DECISIONTREE_HPP

#include "Attribute.hpp"
#include "Example.hpp"

/* A Decision tree class. This class will have nodes and leaves. It
will recursively add nodes and leaves. Leaves have their own special
class, DecisionTreeLeaf.*/
template <class T> class DecisionTree
{
public:
    /* Empty Constructor*/
    DecisionTree();

    /* Default constructor that takes in a string */
    explicit DecisionTree(std::string &t_attributeName)
        : attributeName{t_attributeName}, nodes{} {}

    /* Add a leaf to the tree. Just like adding a node, but since the node
     * here ends, it is adding a leaf. */
    virtual void addLeaf(std::string t_attributeValue, std::string t_decision);

    virtual void addNode(std::string _attributeValue, DecisionTree t_tree);
    virtual T predict(Example t_example);

private:
    std::map<std::string, DecisionTree> *nodes;
    std::string attributeName;
};

/* A decision tree leaf node that inherits from Decision tree. It will
not go any further. */
template <class T> class DecisionTreeLeaf : public DecisionTree<T>
{
public:
    /* Default constructor that takes in a string */
    explicit DecisionTreeLeaf(std::string t_attributeValue);

    std::string const getAttributeValue();
    void setAttributeValue(std::string t_attributeValue);
    void addLeaf();
    void addNode();
    T predict();
    std::string toString();

private:
    std::string m_attributeValue;
};

#endif
