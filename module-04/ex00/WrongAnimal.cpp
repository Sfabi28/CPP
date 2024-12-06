#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("wrongDefault")
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    this->type = wrongAnimal.type;
}

WrongAnimal  &WrongAnimal::operator = (const WrongAnimal &wrongAnimal)
{
    std::cout << "WrongAnimal copy operator called" << std::endl;
    if (this != &wrongAnimal)
    {
        this->type = wrongAnimal.type;
    }
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal default destructor called" << std::endl;
}

void    WrongAnimal::makeSound()
{
    std::cout << "**CRI CRI CRI CRI**" << std::endl;
}
