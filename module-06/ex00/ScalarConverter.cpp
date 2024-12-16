#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
    std::cout << "ScalarConverter copy constructor called" << std::endl;
    *this = src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
    std::cout << "ScalarConverter copy operator called" << std::endl;
    if (this != &src)
    {
        *this = src;
    }
    return *this;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter destructor called" << std::endl;
}


static void ScalarConverter::convert(const std::string &str)
{
    short flag = -1;

    checkType(str, &flag);
    if (flag == -1)
    {
        std::cout << "Error: invalid input, please inster a char, int, float or double" << std::endl;
        return;
    }
    std::cout << "char: " << convertToChar(str, flag) << std::endl;
    std::cout << "int: " << convertToInt(str, flag) << std::endl;
    std::cout << "float: " << convertToFloat(str, flag) << std::endl;
    std::cout << "double: " << convertToDouble(str, flag) << std::endl;
}

static void checkType(const std::string &str, short *flag)
{
    if (str == "nan" || str == "nanf" || str == "-inf" || str == "+inf" || str == "-inff" || str == "+inff") 
    {
        *flag = 0;
    }
    else if (str.length() == 1 && !isdigit(str[0]) && !isprint(str[0])) //char
    {
        *flag = 1;  
    }
    else if (str.length() == 1 && isdigit(str[0])) //2 int, 3 float, -1 error
    {
        *flag = isNumber(str);
    }
}

static short isNumber(const std::string &str)
{
    int j = 0;
    short dotFlag = 0;
    short floatFlag = 0;


    if (!str[0])
        return -1;
    if (str[j] == '-' || str[j] == '+')
        j++;
    if (str[str.length() - 1] == 'f')
        floatFlag = 1;
    while (str[j] - floatFlag)
    {
        if (str[j] == '.')
        {
            if (dotFlag != 0)
                return -1;
            dotFlag = j;
        }
        if (!isdigit(str[j]) && str[j] != '.')
            return -1;
        j++;
    }
    if (floatFlag)
        return 3;
    return 2;
}

ScalarConverter::convertToChar(const std::string &str, short flag)
{
    char c;

    if (flag == 0)
        return "impossible";
    else if (flag == 1)
        return str;
    else if (flag == 2)
    {
        double num = std::stod(str);
        c = static_cast<char>(num);
        if (isprint(c))
            return std::string("'") + c + "'";
        return "Non displayable";
    }
    else if (flag == 3)
    {
        float num = std::stof(str);
        c = static_cast<char>(num);
        if (isprint(c))
            return std::string("'") + c + "'";
        return "Non displayable";
    }
}

ScalarConverter::convertToInt(const std::string &str, short flag)
{
    int i;

    if (flag == 0)
        return "impossible";
    else if (flag == 1)
    {
        int num = static_cast<int>(str[0]);
        return std::to_string(num);
    }
    else if (flag == 2)
    {
        double num = std::stod(str);
        i = static_cast<int>(num);
        if (i >= std::numeric_limits<int>::min() && i <= std::numeric_limits<int>::max())
            return std::to_string(i);
        else
            return "impossible";
    }
    else if (flag == 3)
    {
        float num = std::stof(str);
        i = static_cast<int>(num);
        if (i >= std::numeric_limits<int>::min() && i <= std::numeric_limits<int>::max())
            return std::to_string(i);
        else
            return "impossible";
    }
}