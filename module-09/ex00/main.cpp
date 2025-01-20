#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    BitcoinExchange exchange;

    if (exchange.loadExchangeRate("data.csv"))
        return 1;
    
    std::ifstream file(av[1]);
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    std::string line;
    std::getline(file,line);

    if (line != "date | value")
        std::cerr << "Warning: missing csv format" << std::endl;
    
    while (!file.eof())
    {
        std::getline(file,line);
        std::stringstream ss(line);
        std::string data;
        float value;

        data = line.substr(0, line.find("|"));
        if (line.find("|") == std::string::npos)
        {
            std::cerr << "Error: missing value" << std::endl;
            continue;
        }

        std::stringstream (line.substr(line.find("|") + 1)) >> value;
        if (checkData(data, value))
            exchange.convertValue(value, data);
    }
    
}