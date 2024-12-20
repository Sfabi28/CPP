#include "easyfind.hpp"

int main()
{
    std::vector <int> vect;
    for (int i = 0; i < 10; i++)
        vect.push_back(i);
    try
    {
        std::cout << "find 1: " << easyfind(vect, 1) << std::endl;
        std::cout << "find 5: " << easyfind(vect, 5) << std::endl;
        std::cout << "find 100: " << easyfind(vect, 100) << std::endl;
    }
    catch (ValueNotFound &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}