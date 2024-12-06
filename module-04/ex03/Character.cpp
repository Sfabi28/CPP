#include "Character.hpp"

Character::Character()
{
    std::cout << "character default construtor called" << std::endl;
    for (int i = 0; i < 100; i++)
    {
        if (i < 4)
            inventory[i] = NULL;
        floor[i] = NULL;
    }
}

Character::Character(const Character &character)
{
    std::cout << "character copy constructor called" << std::endl;
    this->name = character.name;
    for (int i = 0; i < 100; i++)
    {
        if (i < 4)
            inventory[i] = character.inventory[i]->clone();
        floor[i] = character.floor[i]->clone();
    }
}

Character&  Character::operator = (const Character &character)
{
    std::cout << "character copy operator called" << std::endl;
    if (this != &character)
    {
        this->name = character.name;
        for (int i = 0; i < 100; i++)
        {
            if (i < 4)
            {
                if (this->inventory[i])
                    delete (inventory[i]);
                inventory[i] = character.inventory[i]->clone();
            }
            if (this->floor[i])
                delete (floor[i]);
            floor[i] = character.floor[i]->clone();
        }
    }
    return (*this);
}

Character::~Character()
{
    std::cout << "character destructor called" << std::endl;
    for (int i = 0; i < 100; i++)
    {
        if (i < 4 && inventory[i])
            delete (inventory[i]);
        if(floor[i])
            delete (floor[i]);
    }
}

Character::Character(const std::string name)
{
    std::cout << "character constructor called" << std::endl;
    this->name = name;
    for (int i = 0; i < 100; i++)
    {
        if (i < 4)
            inventory[i] = NULL;
        floor[i] = NULL;
    }
}

void Character::equip(AMateria* m)
{
    int i = 0;

    while (inventory[i])
        i++;
    if (i < 4)
        inventory[i] = m;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4 || !inventory[idx])
        return ;
    int i = 0;
    while (floor[i])
        i++;
    floor[i] = inventory[idx];
    inventory[idx] = NULL;
}

std::string const & Character::getName() const
{
    return (name);
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && this->inventory[idx])
		this->inventory[idx]->use(target);
}