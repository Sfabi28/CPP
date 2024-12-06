#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
    private:
        AMateria *inventory[4];
        std::string name;
        AMateria *floor[100];

    public:
        Character();
        Character(const Character &character);
        Character &operator = (const Character &character);
        ~Character();
        Character(const std::string name);

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif
