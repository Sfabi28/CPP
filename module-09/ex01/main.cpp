#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "invalid number of arguments" << std::endl;
        return 1;
    }
    if (checkInput(av[1]))
        return 1;

    RPN rpn(av[1]);

    if (rpn.calculate())
        return 1;

    return 0;
}