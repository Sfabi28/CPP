#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>
# include <iomanip>

class   ScavTrap : public ClapTrap
{
    private:
        bool    guard;
    public:
        ScavTrap();
        ScavTrap(const ScavTrap &scavtrap);
        ScavTrap &operator = (const ScavTrap &scavtrap);
        ~ScavTrap();
        ScavTrap(const std::string name);

        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    guardGate();
        bool    getGuard() const;
};

#endif