#include <iostream>
#include <string>

int main()
{
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;
    std::cout << "string adress: " << &string << std::endl;
    std::cout << "adress held by stringPTR: " << stringPTR << std::endl;
    std::cout << "adress held by stringREF: " << &stringREF << std::endl;
    std::cout << "value of string variable: " << string << std::endl;
    std::cout << "value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "value pointed to by stringREF: " << stringREF << std::endl;
}