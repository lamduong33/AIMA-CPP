#include "../include/DataSet.hpp"

DataSet::DataSet()
    : m_fileName{std::string{}}, m_labels{std::vector<std::string>{}},
      m_examples{std::vector<Example>{}}, parsed{false}
{}

DataSet::DataSet(std::string& t_fileName)
    : m_fileName{t_fileName}, m_labels{std::vector<std::string>{}},
      m_examples{std::vector<Example>{}}, parsed{false}
{
    auto fileExtension =
        t_fileName.substr(t_fileName.size() - 4, t_fileName.size() - 1);
    if (fileExtension != ".csv")
        throw new NotCSVException;
}

void DataSet::getData()
{
    // Get files
    std::fstream file{this->m_fileName};
    if (!file)
        throw new std::runtime_error("Error opening file " + m_fileName);
    else
        file.open(this->m_fileName);

    int exampleNum = 1;
    std::vector<std::string> attributes; // one row
    std::string line, entry, temp; // for getting each line
    while (file >> temp)
    {
        attributes.clear();
        std::getline(file, line);
        std::stringstream stream(line);
        while (std::getline(stream, entry, ','))
        {
            attributes.push_back(entry);
        }
        std::string exampleName = "x" + std::to_string(exampleNum);
        std::string output = attributes.back();
        attributes.pop_back();
        this->m_examples.push_back(Example{exampleName, attributes, output});
    }

    file.close();        // close to be sure
    this->parsed = true; // hopefully everything is done correctly at this point.
}

std::vector<Example> DataSet::getExamples() { return this->m_examples; }
std::string DataSet::getFileName() { return this->m_fileName; }
std::vector<std::string> DataSet::getLabels() { return this->m_labels; }

void DataSet::addExamples(std::vector<Example> t_examples)
{
    m_examples.insert(m_examples.end(), t_examples.begin(), t_examples.end());
}
