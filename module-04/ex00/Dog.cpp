#include "Dog.hpp"

Dog::Dog() : Animal()
{
    type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &dog) : Animal(dog)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->type = dog.type;
}

Dog  &Dog::operator = (const Dog &dog)
{
    std::cout << "Dog copy operator called" << std::endl;
    if (this != &dog)
    {
        Animal::operator=(dog);
        this->type = dog.type;
    }
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog default destructor called" << std::endl;
}

void    Dog::makeSound() const
{
    std::cout << "Woof" << std::endl;
}

std::string Dog::getType() const
{
    return (this->type);
}