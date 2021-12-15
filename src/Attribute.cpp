#include "../include/Attribute.hpp"

template <class T> Attribute<T>::Attribute()
{
    this->m_attributeName = "";
    this->m_attributeValue = T{};
}

template <class T> Attribute<T>::Attribute(T& t_value, std::string& t_name)
{
    this->m_attributeName = t_name;
    this->m_attributeValue = t_value;
}

template <class T> T Attribute<T>::getValue() { return this->m_attributeValue; }

template <class T> std::string Attribute<T>::getName()
{
    return this->m_attributeName;
}

template <class T> void Attribute<T>::setName(const std::string t_name)
{
    this->m_attributeName = t_name;
}

template <class T> void Attribute<T>::setValue(T& t_value)
{
    this->m_attributeValue = t_value;
}
