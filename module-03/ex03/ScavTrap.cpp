#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "scavtrap default constructor called" << std::endl;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    guard = false;
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap)
{
    std::cout << "scavtrap copy constructor called" << std::endl;
    this->name = scavtrap.getName();
    this->hitPoints = scavtrap.getHitPoints();
    this->energyPoints = scavtrap.getEnergyPoints();
    this->guard = scavtrap.getGuard();
}

ScavTrap &ScavTrap::operator = (const ScavTrap &scavtrap)
{
    std::cout << "scavtrap copy operator called" << std::endl;
    if (this != &scavtrap)
    {
        this->name = scavtrap.getName();
        this->hitPoints = scavtrap.getHitPoints();
        this->energyPoints = scavtrap.getEnergyPoints();
        this->guard = scavtrap.getGuard();
    }
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "scavtrap default destructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name)
{
    std::cout << "scavtrap constructor called" << std::endl;
    this->name = name;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    guard = false;
}

bool    ScavTrap::getGuard() const
{
    return (this->guard);
}

void    ScavTrap::guardGate()
{
    if (this->guard == false)
    {
        std::cout << this->name << " is now in guard mode 🛡️" << std::endl;
        this->guard = true;
        return;
    }
    if (this->guard == true)
    {
        std::cout << this->name << " ended their guard mode ⚔️" << std::endl;
        this->guard = false;
    }
}

void    ScavTrap::attack(const std::string& target)
{
    if (this->hitPoints <= 0)
        return;
    if (this->guard == true)
    {
        std::cout << this->name << " can't attack, they are in guard mode " << std::endl;
        return;
    }
    if (this->energyPoints)
    {
        std::cout << this->name << " attacks " << target << " with a " << this->attackDamage << " damage attack " << std::endl;
        this->energyPoints--;
    }
    else
        std::cout << this->name << "'s attack failed, out of energy" << std::endl;
}

void    ScavTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoints <= 0)
    {
        std::cout << this->name << " is already dead " << std::endl;
        return;
    }
    if (this->guard == true)
    {
        std::cout << this->name << " took 0 damage, their guard is active " << std::endl;
        return;
    }
    this->hitPoints -= amount;
    std::cout << this->name << " took " << amount << " damage, they now have " << this->hitPoints << " hp" << std::endl; 
    if (this->hitPoints <= 0)
        std::cout << this->name << " died" << std::endl;
}