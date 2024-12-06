#ifndef DIAMODTRAP_HPP
# define DIAMODTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include <iostream>
# include <string>
# include <iomanip>

class   DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string name;
    public:
        DiamondTrap();
        DiamondTrap(const DiamondTrap &diamondtrap);
        DiamondTrap &operator = (const DiamondTrap &diamondtrap);
        ~DiamondTrap();
        DiamondTrap(const std::string name);
    
    void    whoAmI();
    void    attack(const std::string &target);
};

#endif
