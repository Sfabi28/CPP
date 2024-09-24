#include "Zombie.hpp"

int main()
{
    Zombie zombie;
    int n = 5;
    Zombie* horde = zombie.zombieHorde(n, "Abhi");
    
    for (int i = 0; i < n; i++)
        horde[i].announce();
    delete [] horde;
    return 0;
}