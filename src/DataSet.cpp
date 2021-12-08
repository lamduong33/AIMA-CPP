#include "../include/DataSet.hpp"

/* DataSet Constructor
 * ----------------------------------------------------------------------------
 *  Take in string file names for training data and testing data respectively.
 */
DataSet::DataSet(std::string t_testingFileName, std::string t_trainingFileName)
{
    this->m_trainingFileName = t_trainingFileName;
    this->m_testingFileName = t_testingFileName;
}

/* getData()
 * ----------------------------------------------------------------------------
 * modify the DataSet object by opening the testing and training file
 * put them in a 2 dimensional array (vector).
 */
void DataSet::getData()
{
    // Get files
    std::ifstream trainingFile;
    trainingFile.open(this->m_trainingFileName);
    std::ifstream testingFile;
    testingFile.open(this->m_testingFileName);

    // Open training data file
    if (trainingFile.is_open())
    {
        // Add in individual molecule
        std::string moleculeString;
        std::vector<std::string> moleculeData;
        while (std::getline(trainingFile, moleculeString))
        {

            arma::Row<int> rowVector;
            rowVector.load(moleculeString);
            std::cout << rowVector << std::endl;
        }
    }
}
