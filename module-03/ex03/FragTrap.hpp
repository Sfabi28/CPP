#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>
# include <iomanip>

class   FragTrap : virtual public ClapTrap
{
    public:
        FragTrap();
        FragTrap(const FragTrap &fragtrap);
        FragTrap &operator = (const FragTrap &fragtrap);
        ~FragTrap();
        FragTrap(const std::string name);

        void highFivesGuys(void);
};

#endif