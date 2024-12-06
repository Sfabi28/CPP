#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    this->type = "ice";
    std::cout << "ice default constractor called" << std::endl;
}

Ice::Ice(const Ice &ice)
{
    std::cout << "ice copy constractor called" << std::endl;
    this->type = ice.type;
}

Ice& Ice::operator = (const Ice &ice)
{
    std::cout << "ice copy operator called" << std::endl;
    if (this != &ice)
        this->type = ice.type;
    return (*this);
}

Ice::~Ice()
{
    std::cout << "ice destructor called" << std::endl;
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria *Ice::clone() const
{
	std::cout << "ice clone" << std::endl;
	return (new Ice(*this));
}