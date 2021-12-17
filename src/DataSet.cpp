#include "../include/DataSet.hpp"

DataSet::DataSet()
    : m_fileName{std::string{}}, m_labels{std::vector<std::string>{}},
      m_examples{std::vector<Example>{}}, parsed{false}
{}

/**
 * @brief Constructor that takes in a file name.
 * @throw NotCSVException if file extension is not .csv */
DataSet::DataSet(std::string& t_fileName)
    : m_fileName{t_fileName}, m_labels{std::vector<std::string>{}},
      m_examples{std::vector<Example>{}}, parsed{false}
{
    auto fileExtension =
        t_fileName.substr(t_fileName.size() - 4, t_fileName.size() - 1);
    if (fileExtension != ".csv")
        throw new NotCSVException;
}

/**
 * getData()
 * @brief modify the DataSet object by opening the testing and training file
 * put them in a 2 dimensional array (vector).
 */
void DataSet::getData()
{
    // Get files
    std::ifstream file;
    file.open(this->m_fileName);

    // Open training data file
    if (file.is_open())
    {
        // Add in individual molecule
        std::string moleculeString;
        std::vector<std::string> moleculeData;
        while (std::getline(file, moleculeString))
        {
        }
    }
}

std::vector<Example> DataSet::getExamples() { return this->m_examples; }

std::string DataSet::getFileName() { return this->m_fileName; }
std::vector<std::string> DataSet::getLabels() { return this->m_labels; }
