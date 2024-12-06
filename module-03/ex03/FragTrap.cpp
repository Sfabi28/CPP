#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "fragtrap default constructor called" << std::endl;
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &fragtrap)
{
    std::cout << "fragtrap copy constructor called" << std::endl;
    this->name = fragtrap.getName();
    this->hitPoints = fragtrap.getHitPoints();
    this->energyPoints = fragtrap.getEnergyPoints();
}

FragTrap &FragTrap::operator = (const FragTrap &fragtrap)
{
    std::cout << "fragtrap copy operator called" << std::endl;
    if (this != &fragtrap)
    {
        this->name = fragtrap.getName();
        this->hitPoints = fragtrap.getHitPoints();
        this->energyPoints = fragtrap.getEnergyPoints();
    }
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "fragtrap default destructor called" << std::endl;
}

FragTrap::FragTrap(const std::string name)
{
    std::cout << "fragtrap constructor called" << std::endl;
    this->name = name;
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;   
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << this->name << " gave their friend an high five" << std::endl;
}