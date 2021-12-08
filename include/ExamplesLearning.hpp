/*
 * ExamplesLearning.hpp
 *
 *  Created on: Aug 3, 2019
 *      Author: Lam Duong
 */

#ifndef EXAMPLESLEARNING_H_
#define EXAMPLESLEARNING_H_

#include <iostream>
#include "Attribute.hpp"
#include "Example.hpp"
#include "DecisionTree.hpp"

template <class T>
DecisionTree<T> decisionTreeLearning(std::vector<Example>& t_examples,
    std::vector<Attribute>& t_attributes, std::vector<Example>& t_parentExamples);

template <class T>
DecisionTree<T> pluralityValue(std::vector<Example>& t_examples);
int importance(Attribute attribute, std::vector<Example>& examples);
bool sameClassification(std::vector<Example>& examples);

#endif /*EXAMPLESLEARNING_H_*/
