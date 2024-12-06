#include "Animal.hpp"

Animal::Animal() : type("Animal's")
{
    std::cout << "animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &animal)
{
    std::cout << "animal copy constructor called" << std::endl;
    this->type = animal.type;
}

Animal  &Animal::operator = (const Animal &animal)
{
    std::cout << "animal copy operator called" << std::endl;
    if (this != &animal)
    {
        this->type = animal.type;
    }
    return (*this);
}

Animal::~Animal()
{
    std::cout << "animal default destructor called" << std::endl;
}

void    Animal::makeSound() const
{
    std::cout << "**SILENCE**" << std::endl;
}

std::string Animal::getType() const
{
    return (this->type);
}

