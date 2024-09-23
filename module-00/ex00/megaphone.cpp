
#include <string>
#include <iostream>

int main(int argc, char **argv)
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        int i = 1;
        int j = 0;
        while (i < argc)
        {
            j = 0;
            while (argv[i][j])
            {
                std::cout << (char)std::toupper(argv[i][j]);
                j++;
            }
            i++;
        }
    }
    std::cout << std::endl;
    return (0);
}