#include "Data.hpp"

Data::Data()
{
    std::cout << "Data default constructor called" << std::endl;
}

Data::Data(const Data &copy)
{
    std::cout << "Data copy constructor called" << std::endl;
    *this = copy;
}

Data &Data::operator = (const Data &copy)
{
    std::cout << "Data copy operator called " << std::endl;
    if (this != &copy)
    {
        *this = copy;
    }
    return *this;
}

Data::~Data()
{
    std::cout << "Data destructor called" << std::endl;
}

Data::Data(std::string str, int num) : str(str), num(num)
{
    std::cout << "Data constructor called" << std::endl;
}

std::string Data::getStr()
{
    return str;
}

int Data::getNum()
{
    return num;
}

