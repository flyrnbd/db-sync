#include "config.h"
#include <iostream>
#include "input_schema.h"
using namespace std;

bool setConfig(Config &config)
{
    std::cout << YELLOW << YELLOW << "White text on blue background." << RESET << std::endl;
    std::cout << UNDERLINE << YELLOW << "Underlined yellow text." << RESET << std::endl;
    return true;
}

bool getConfig(Config &config)
{
    return true;
}

bool isConfigValid(Config &config)
{
    return true;
}