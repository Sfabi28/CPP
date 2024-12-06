#include "replace.hpp"

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "wrong number of arguments" << std::endl;
        return 0;
    }
    std::string str;
    std::string buffer;
    std::string replaced;
    std::ifstream infileFd;
    std::ofstream outfileFd;
    std::string outfile;
    size_t  position;

    replaced = av[2];
    infileFd.open(av[1]);
    if (!infileFd.is_open())
    {
        std::cout << "Error during input file opening" << std::endl;
        return 1;
    }
    outfile = av[1];
    outfile += ".replace";
    outfileFd.open(outfile.c_str());
    if (!outfileFd.is_open())
    {
        std::cout << "Error during output file opening" << std::endl;
        infileFd.close();
        return 1;
    }
    while (getline(infileFd, buffer))
    {
        buffer += "\n";
        str += buffer;
    }
    infileFd.close();
    str = str.substr(0, str.length() - 1);
    do
    {
        position = str.find(replaced);
        if (position == 0)
            outfileFd << av[3];
        outfileFd << str.substr(0, position);
        if (position > 0 && position != std::string::npos)
            outfileFd << av[3];
        if ((long long int)str.length() - (long long int)replaced.length() > 0 )
            str = str.substr(position + replaced.length(), str.length());
    } while (position != std::string::npos);
    outfileFd.close();
    std::cout << std::endl << "replace succeded" << std::endl;
    return 0;
}