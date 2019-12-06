#include "DecisionTree.hpp"

/* Empty constructor for a decision tree */
DecisionTree::DecisionTree()
{
    
}

/* DecisionTree constructor that takes in an Attribute object */
DecisionTree::DecisionTree(Attribute t_attribute):
    m_attribute(t_attribute){}