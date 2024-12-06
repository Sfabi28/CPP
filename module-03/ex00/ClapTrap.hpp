#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP


# include <iostream>
# include <string>
# include <iomanip>

class   ClapTrap
{
    private:
        std::string name;
        int hitPoints;
        int attackDamage;
        int energyPoints;

    public:
        ClapTrap();
        ClapTrap(const ClapTrap &clapTrap);
        ClapTrap &operator = (const ClapTrap &clapTrap);
        ~ClapTrap();
        ClapTrap(const std::string name);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        std::string getName(void) const;
        int getHitPoints() const;
        int getEnergyPoints() const;

};

#endif