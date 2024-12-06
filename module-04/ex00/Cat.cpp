#include "Cat.hpp"

Cat::Cat() : Animal()
{
    type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal(cat)
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->type = cat.type;
}

Cat  &Cat::operator = (const Cat &cat)
{
    std::cout << "Cat copy operator called" << std::endl;
    if (this != &cat)
    {
        Animal::operator=(cat);
        this->type = cat.type;
    }
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat default destructor called" << std::endl;
}

void    Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}

std::string Cat::getType() const
{
    return (this->type);
}