#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    type = "WrongCat";
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrongCat) : WrongAnimal(wrongCat)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    this->type = wrongCat.type;
}

WrongCat  &WrongCat::operator = (const WrongCat &wrongCat)
{
    std::cout << "WrongCat copy operator called" << std::endl;
    if (this != &wrongCat)
    {
        WrongAnimal::operator=(wrongCat);
        this->type = wrongCat.type;
    }
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat default destructor called" << std::endl;
}

void    WrongCat::makeSound()
{
    std::cout << "CRI CRI CRI CRI but from WrongCat" << std::endl;
}