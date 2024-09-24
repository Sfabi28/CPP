#ifndef Weapon_HPP
# define Weapon_HPP

# include <iostream>
# include <string>
# include <iomanip>

    class   Weapon
    {
        private:
            std::string type;
        
        public:
            Weapon(std::string type);
		    ~Weapon();
		    std::string const &getType();
		    void setType(std::string type);
    };

#endif
