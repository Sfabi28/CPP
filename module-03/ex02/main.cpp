#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ScavTrap pino;
    ScavTrap luca("Luca");
    ScavTrap paolo("Paolo");
    ScavTrap gianni("Gianni");
    FragTrap sara("Sara");
    FragTrap alice("Alice");

    pino = gianni;  //pino adesso e' gianni
    std::cout << std::endl;
    pino.attack("Paolo");
    paolo.takeDamage(20);
    paolo.guardGate();
    paolo.beRepaired(20);
    pino.attack("Paolo");
    paolo.takeDamage(20);
    paolo.guardGate();
    std::cout << std::endl;
    for (int i = 0; i < 7; i++)
    {
        paolo.attack("Gianni");
        pino.takeDamage(20);
    }
    std::cout << std::endl;
    luca.attack("Paolo");
    paolo.takeDamage(20);
    paolo.guardGate();
    paolo.beRepaired(10);
    paolo.guardGate();
    std::cout << std::endl;
    for (int i = 0; i < 5; i++)
    {
        paolo.attack("Luca");
        luca.takeDamage(20);
        paolo.guardGate();
        luca.attack("Paolo");
        paolo.takeDamage(20);
        paolo.guardGate();
        std::cout << std::endl;
    }
    sara.attack("Paolo");
    alice.attack("Paolo");
    sara.attack("Paolo");
    paolo.takeDamage(90);
    sara.highFivesGuys();
    alice.highFivesGuys();
    std::cout << std::endl;

    return (0);
}