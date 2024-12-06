#include "Cat.hpp"

Cat::Cat() : Animal()
{
    type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
    brain = new Brain;
}

Cat::Cat(const Cat &cat) : Animal(cat)
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->type = cat.type;
    this->brain = new Brain(*cat.brain);
}

Cat  &Cat::operator = (const Cat &cat)
{
    std::cout << "Cat copy operator called" << std::endl;
    if (this != &cat)
    {
        Animal::operator=(cat);
        this->type = cat.type;
        brain = new Brain;
        brain = cat.brain;
    }
    return (*this);
}

Cat::~Cat()
{
    delete brain;
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