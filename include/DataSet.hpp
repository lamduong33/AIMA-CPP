#ifndef DATASET_HPP
#define DATASET_HPP

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <fstream>

class DataSet
{

public:

	// constructor
	DataSet(std::string t_trainingFileName, std::string t_testingFileName);	
	void getData();

private:
	std::string m_trainingFileName;
	std::vector<int> m_labels;
};

#endif
