#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::cout << "BitcoinExchange constructor called" << std::endl;
}

BitcoinExchange::~BitcoinExchange()
{
    std::cout << "BitcoinExchange destructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
    std::cout << "BitcoinExchange copy constructor called" << std::endl;
    this->exchangeRate = copy.exchangeRate;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
    std::cout << "BitcoinExchange operator= called" << std::endl;
    if (this != &copy)
    {
        this->exchangeRate = copy.exchangeRate;
    }
    return *this;
}

int BitcoinExchange::loadExchangeRate(const char *filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Errore nell'apertura del file data." << std::endl;
        return 1;
    }

    std::string line;
    std::getline(file, line);

    while (!file.eof())
    {
        std::getline(file,line);
        std::stringstream ss(line);
        std::string data;
        float value;

        data = line.substr(0, line.find(","));
        std::stringstream (line.substr(line.find(",") + 1)) >> value;
        exchangeRate[data] = value;
    }
    file.close();
    return 0;
}

bool checkData(std::string data, float value)
{
    if (value < 0)
    {
        std::cerr << "Error: negative value" << std::endl;
        return false;
    }
    else if (value - 1000 > 0)
    {
        std::cerr << "Error: value too high" << std::endl;
        return false;
    }

    std::string line = data.substr(0, data.find("|"));

    short i = 0;

    while (line[i])
    {
        if (!isdigit(line[i]) && line[i] != '-' && isspace(line[i]) == 0)
        {
            std::cerr << "Error: bad input -> " << data << std::endl;
            return false;
        }
        i++;
    }

    int year, month, day;

    std::stringstream(data.substr(0, data.find("-"))) >> year;
    std::string temp = data.substr(data.find("-") + 1);
    std::stringstream(temp.substr(0, temp.find("-"))) >> month;
    std::stringstream(temp.substr(temp.find("-") + 1)) >> day;

    if (!(year && month && day))
    {
        std::cerr << "Error: bad input -> " << data << std::endl;
        return false;
    }

    if (year <= 999 || year > 9999)
    {
        std::cerr << "Error: bad input -> " << data << std::endl;
        return false;
    }

    switch (month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (day < 1 || day > 31)
            {
                std::cerr << "Error: bad input -> " << data << std::endl;
                return false;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (day < 1 || day > 30)
            {
                std::cerr << "Error: bad input -> " << data << std::endl;
                return false;
            }
            break;
        case 2:
            if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
            {
                if (day < 1 || day > 29)
                {
                    std::cerr << "Error: bad input -> " << data << std::endl;
                    return false;
                }
            }
            else
            {
                if (day < 1 || day > 28)
                {
                    std::cerr << "Error: bad input -> " << data << std::endl;
                    return false;
                }
            }
            break;
        default:
            std::cerr << "Error: bad input -> " << data << std::endl;
            return false;
    }
    return true;
}

void BitcoinExchange::convertValue(float value, std::string data)
{
    std::string date;
    
    for (size_t i = 0; i < data.size(); i++)  // remove spaces from data
    {
        if (!isspace(data[i]))
            date += data[i];
    }
    
    std::map<std::string, float>::iterator it;
    for (it = exchangeRate.begin(); it != exchangeRate.end(); ++it)
    {
        if (it->first >= date)
        {
            if (it == exchangeRate.begin())
                it--;
            std::cout << date << " => " << value << " = " << value * it->second << std::endl;
            return;
        }
    }
        it--;
        std::cout << date << " => " << value << " = " << value * it->second << std::endl;
}


