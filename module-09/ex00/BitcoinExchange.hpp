#ifndef BITCOINEXCHANGE
# define BITCOINEXCHANGE

# include <iostream>
# include <map>
# include <string>
# include <fstream>
# include <sstream>

class BitcoinExchange
{
    private:
        std::map<std::string, float> exchangeRate;

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &copy);

        int loadExchangeRate(const char *filename);
        void convertValue(float value, std::string data);
};
        bool checkData(std::string data, float value);

#endif
