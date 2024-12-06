#include "ClapTrap.hpp"

int main()
{
    ClapTrap pino;
    ClapTrap luca("Luca");
    ClapTrap paolo("Paolo");
    ClapTrap gianni("Gianni");

    pino = gianni;  //pino adesso e' gianni
    pino.attack("abhi"); 
    for (int i = 0; i <= 11 ; i++)
    {
        luca.attack("Paolo");
    }
    paolo.takeDamage(9);
    paolo.beRepaired(100);
    luca.takeDamage(8);
    luca.beRepaired(8);
    paolo.takeDamage(110);
    paolo.beRepaired(10);
    return (0);
}