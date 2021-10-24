#ifndef DATASET_HPP
#define DATASET_HPP

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <fstream>
#include <mlpack/core.hpp>

class DataSet
{
public:
	// constructor
	DataSet(std::string t_trainingFileName, std::string t_testingFileName);	
	void getData();
private:
	std::string m_trainingFileName;
	std::string m_testingFileName;

	// 2 Dimensional array of training data
	// std::vector<std::vector<int>> m_trainingData;
	std::vector<arma::Row<int>> m_trainingData;

	// 2-Dimensional array of testing data 
	// std::vector<std::vector<int>> m_testingData;
	std::vector<arma::Row<int>> m_testingData;

	std::vector<int> m_labels;
};

#endif
