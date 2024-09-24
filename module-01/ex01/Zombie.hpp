#ifndef Zombie_HPP
# define Zombie_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Zombie
{
    private:
        std::string name;
    
    public:
        Zombie();
        Zombie(std::string name);
        ~Zombie();
        Zombie* zombieHorde( int N, std::string name);
        void    announce( void );
};

#endif