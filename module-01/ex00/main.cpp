#include "Zombie.hpp"

int main()
{
    Zombie  zombie;
    Zombie* abhi;

    abhi = zombie.newZombie("Abhi");
    zombie.randomChump("Abhi4");
    zombie.randomChump("Abhi5");
    zombie.randomChump("Abhi6");
    zombie.randomChump("Abhi7");
    abhi->announce();
    delete(abhi);
    return 0;
}