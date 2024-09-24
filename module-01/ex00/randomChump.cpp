#include "Zombie.hpp"

void    Zombie::randomChump( std::string name)
{
    Zombie* zombie = newZombie(name);
    zombie->announce();
    delete(zombie);
}
