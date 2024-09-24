#include "Zombie.hpp"

Zombie::Zombie() : name("")
{
    std::cout << "Zombie constructor called" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << name << " destoyed" << std::endl;
}

void    Zombie::announce( void )
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}