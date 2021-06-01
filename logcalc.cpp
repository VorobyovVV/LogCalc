#include <iostream>
#include <string>
#include "calc.h"

int main()
{
    try
    {
        std::string s = " ";
        bool result = calc(s);
        std::cout << "Result: " << result << std::endl;
    }
    catch (const std::string &str)
    {
        std::cout << "Error: " << str << std::endl;
    }

 
}
