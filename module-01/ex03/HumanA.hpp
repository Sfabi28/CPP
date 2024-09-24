#ifndef HumanA_HPP
# define HumanA_HPP

# include "Weapon.hpp"

    class HumanA
    {
        private:
            std::string name;
            Weapon weapon;
        public:
            HumanA(std::string name, Weapon weapon);
            ~HumanA();
    };

#endif