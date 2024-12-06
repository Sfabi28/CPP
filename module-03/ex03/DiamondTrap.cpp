#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name")
{
    std::cout << "diamondtrap default constructor called" << std::endl;
    name = "default";
    hitPoints = FragTrap::hitPoints;
    energyPoints = ScavTrap::energyPoints;
    attackDamage = FragTrap::attackDamage;
    guard = false;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondtrap) : ClapTrap(diamondtrap.name + "_clap_name")
{
    std::cout << "diamondtrap copy constructor called" << std::endl;
    this->name = diamondtrap.getName();
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    this->guard = ScavTrap::guard;
}

DiamondTrap &DiamondTrap::operator = (const DiamondTrap &diamondtrap)
{
    std::cout << "DiamondTrap copy operator called" << std::endl;
    if (this != &diamondtrap)
    {
        ClapTrap::name = diamondtrap.name + "_clap_name";
        this->hitPoints = diamondtrap.getHitPoints();
        this->energyPoints = diamondtrap.getEnergyPoints();
        this->guard = diamondtrap.getGuard();
    }
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "diamondtrap default destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name")
{
    std::cout << "diamondtrap constructor called" << std::endl;
    this->name = name;
    hitPoints = FragTrap::hitPoints;
    energyPoints = ScavTrap::energyPoints;
    attackDamage = FragTrap::attackDamage;
    guard = false;
}

void    DiamondTrap::whoAmI()
{
    std::cout << "I am " << this->name << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}

void    DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}