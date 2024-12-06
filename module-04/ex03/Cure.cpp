#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    this->type = "cure";
    std::cout << "cure default constructor called" << std::endl;
}

Cure::Cure(const Cure &cure)
{
    std::cout << "cure copy constructor called" << std::endl;
    this->type = cure.type;
}

Cure& Cure::operator = (const Cure &cure)
{
    std::cout << "cure copy operator called" << std::endl;
    if (this != &cure)
        this->type = cure.type;
    return (*this);
}

Cure::~Cure()
{
    std::cout << "cure destructor called" << std::endl;
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName()  << "'s wounds *" << std::endl;
}

AMateria *Cure::clone() const
{
	std::cout << "cure clone" << std::endl;
	return (new Cure(*this));
}