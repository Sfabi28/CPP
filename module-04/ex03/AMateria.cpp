#include "AMateria.hpp"

AMateria::AMateria()
{
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &materia)
{
    std::cout << "AMateria copy constructor called" << std::endl;
    *this = materia;
}

AMateria&   AMateria::operator = (const AMateria &materia)
{
    std::cout << "AMateria copy operator called" << std::endl;
    if (this != &materia)
        *this = materia;
    return (*this);
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructor called" << std::endl;
}

AMateria::AMateria(std::string const & type)
{
	std::cout << "AMateria constructor" << std::endl;
	this->type = type;
}

const std::string& AMateria::getType() const
{
    return (this->type);
}

void AMateria::use(ICharacter& target)
{
    std::cout << "* uses "<< this->type << " on " << target.getName() << " *" << std::endl;
}

