#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("default"), hitPoints(10), attackDamage(0), energyPoints(10)
{
    std::cout << "claptrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap) : attackDamage(0)
{
    this->name = clapTrap.getName();
    this->hitPoints = clapTrap.getHitPoints();
    this->energyPoints = clapTrap.getEnergyPoints();
    std::cout << "claptrap copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator = (const ClapTrap &clapTrap)
{
    std::cout << "claptrap copy operator called" << std::endl;
    if (this != &clapTrap)
    {
        this->name = clapTrap.getName();
        this->hitPoints = clapTrap.getHitPoints();
        this->energyPoints = clapTrap.getEnergyPoints();
    }
    return (*this);
}

ClapTrap::~ClapTrap()
{
     std::cout << "claptrap default destructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : name(name), hitPoints(10), attackDamage(0), energyPoints(10)
{
    std::cout << "claptrap contructor called" << std::endl;
}

std::string ClapTrap::getName(void) const
{
    return (this->name);
}

void    ClapTrap::attack(const std::string& target)
{
    if (this->hitPoints <= 0)
        return;
    if (this->energyPoints)
    {
        std::cout << this->name << " attacks " << target << " causing " << this->attackDamage << " damage" << std::endl;
        this->energyPoints--;
    }
    else
        std::cout << this->name << "'s attack failed, out of energy" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoints <= 0)
        return;
    this->hitPoints -= amount;
    std::cout << this->name << " took " << amount << " damage, they now have " << this->hitPoints << " hp" << std::endl; 
    if (this->hitPoints <= 0)
        std::cout << this->name << " died" << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hitPoints <= 0)
    {
        std::cout << this->name << " can't be repaired, they're dead" << std::endl; 
        return;
    }
    if (this->energyPoints)
    {
        this->hitPoints += amount;
        this->energyPoints--;
        std::cout << "repairing " << this->name << " for " << amount << " hp, they now have " << this->hitPoints << " hp" << std::endl;
    }
    else
        std::cout << this->name << "'s repairing failed, out of energy" << std::endl;
}

int     ClapTrap::getHitPoints() const
{
    return(this->hitPoints);
}

int     ClapTrap::getEnergyPoints() const
{
    return(this->energyPoints);
}