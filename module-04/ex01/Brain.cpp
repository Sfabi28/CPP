#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &brain)
{
    for (int i = 0; i < 100; i++)
        ideas[i] = brain.ideas[i];
    std::cout << "brain copy constructor called" << std::endl;
}

Brain&  Brain::operator=(const Brain &brain)
{
    std::cout << "brain copy operator called" << std::endl;
    if (this != &brain)
    {
        for (int i = 0; i < 100; i++)
            ideas[i] = brain.ideas[i];
    }
    return (*this);
}  

Brain::~Brain()
{
    std::cout << "brain default destructor called" << std::endl;
}

void Brain::setIdea(std::string idea, int i)
{
	ideas[i] = idea;
}

std::string Brain::getIdea(int i) const
{
	return (ideas[i]);
}