#include <iostream>
#include "Attribute.hpp"
#include "Attribute.cpp"

int main()
{
    // Manual testing
    Attributes attributes;
    attributes.addAttribute("Alt", 0);
    attributes.addAttribute("Full", 0);
    attributes.addAttribute("Hungry", 0);

    std::cout << attributes.toString();
    return 0;
}