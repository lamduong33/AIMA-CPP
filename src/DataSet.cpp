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
    std::ifstream file{this->m_fileName};
    if (!file.is_open())
        throw new std::runtime_error("Error opening file " + m_fileName);

    int exampleNum = 1;
    auto firstLine = true;
    std::vector<std::string> attributes; // one row
    std::string line, entry, temp; // for getting each line

    while (std::getline(file, line))
    {
        attributes.clear();
        std::stringstream stream(line);
        while (std::getline(stream, entry, ','))
        {
            if (firstLine)
                this->m_labels.push_back(entry);
            else
                attributes.push_back(entry);
        }
        if (firstLine)
        {
            firstLine = false;
            continue;
        }
        std::string exampleName = "x" + std::to_string(exampleNum++);
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
