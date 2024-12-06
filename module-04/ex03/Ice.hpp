#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"


class   Ice : public AMateria
{
    private:
        std::string type;
    public:
        Ice();
        Ice(const Ice &ice);
        Ice &operator = (const Ice &ice);
        ~Ice();

        AMateria *clone() const;
        void use(ICharacter& target);
};

#endif