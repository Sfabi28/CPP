#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"
#include <iostream>
#include <string>


class ICharacter;

class AMateria
{
    protected:
        std::string type;
        AMateria();
    public:
        AMateria(const AMateria &materia);
        AMateria &operator = (const AMateria &materia);
        virtual ~AMateria();
        AMateria(std::string const & type);
    
        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif