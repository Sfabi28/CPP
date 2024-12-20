#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>
#include <string>

class Data;

class Data
{
    private:
        std::string str;
        int num;

    public:
        Data();
        Data(const Data &copy);
        Data &operator = (const Data &copy);
        ~Data();

        Data(std::string str, int num);

        std::string getStr();
        int getNum();
};

#endif