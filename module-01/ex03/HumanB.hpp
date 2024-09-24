#ifndef HumanB_HPP
# define HumanA_HPP

# include "Weapon.hpp"

    class HumanB
    {
        private:
            std::string name;
            Weapon weapon;
        public:
            HumanB(std::string name, Weapon weapon);
            ~HumanB();
    };

#endif