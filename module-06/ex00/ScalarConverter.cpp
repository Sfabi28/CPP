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
    while (str[j + floatFlag])
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

static std::string iToString(int num)
{
    std::ostringstream oss;
    oss << num;
    return oss.str();
}

static std::string fToString(float num)
{
    std::ostringstream oss;
    oss << num;
    if (oss.str().find('.') == std::string::npos && oss.str().find('e') == std::string::npos)
        oss << ".0";
    return oss.str();
}

static std::string dToString(double num)
{
    std::ostringstream oss;
    oss << num;
    if (oss.str().find('.') == std::string::npos && oss.str().find('e') == std::string::npos)
        oss << ".0";
    return oss.str();
}

static int stringToInt(const std::string &str)
{
    std::istringstream iss(str);
    int num;
    iss >> num;
    return num;
}

static double stringToDouble(const std::string &str)
{
    std::istringstream iss(str);
    double num;
    iss >> num;
    return num;
}

static float stringToFloat(const std::string &str)
{
    std::istringstream iss(str);
    float num;
    iss >> num;
    return num;
}

static void checkType(const std::string &str, short *flag)
{
    if (str == "nan" || str == "nanf" || str == "-inf" || str == "+inf" || str == "-inff" || str == "+inff" || str == "inf" || str == "inff") 
    {
        *flag = 0;
    }
    else if (str.length() == 1 && !isdigit(str[0]) && !isprint(str[0])) //char
    {
        *flag = 1;  
    }
    else //2 int, 3 float, -1 error
    {
        *flag = isNumber(str);
    }
}


std::string convertToChar(const std::string &str, short flag)
{
    char c;

    if (flag == 0)
        return "impossible";
    else if (flag == 1)
        return std::string("'") + str + "'";
    else if (flag == 2)
    {
        int num = stringToInt(str);
        if (num < 0 || num > 255)
            return "impossible";
        c = static_cast<char>(num);
        if (isprint(c))
            return std::string("'") + c + "'";
        return "Non displayable";
    }
    else if (flag == 3)
    {
        int num = stringToInt(str);
        if (num < 0 || num > 255)
            return "impossible";
        c = static_cast<char>(num);
        if (isprint(c))
            return std::string("'") + c + "'";
        return "Non displayable";
    }
    return "impossible";
}

std::string convertToInt(const std::string &str, short flag)
{
    int i;

    if (flag == 0)
        return "impossible";
    else if (flag == 1)
    {
        int num = static_cast<int>(str[0]);
        return iToString(num);
    }
    else if (flag == 2)
    {
        double num = stringToDouble(str);
        if (num >= std::numeric_limits<int>::min() && num <= std::numeric_limits<int>::max())
        {
            i = static_cast<int>(num);
            return iToString(i);
        }
        else
            return "impossible";
    }
    else if (flag == 3)
    {
        float num = stringToFloat(str);
        if (num >= static_cast<float>(std::numeric_limits<int>::min()) &&
            num <= static_cast<float>(std::numeric_limits<int>::max()))
        {
            i = static_cast<int>(num);
            if (i != -2147483648)
                return iToString(i);
        }
        else
            return "impossible";
    }
    return "impossible";
}

std::string convertToFloat(const std::string &str, short flag)
{
    float f;

    if (flag == 0)
    {
        if (str == "nan" || str == "nanf")
            return "nanf";
        else if (str == "-inf" || str == "-inff")
            return "-inff";
        else if (str == "+inf" || str == "+inff" || str == "inf" || str == "inff")
            return "inff";
    }
    else if (flag == 1)
    {
        float num = static_cast<float>(str[0]);
        return fToString(num) + "f";
    }
    else if (flag == 2 || flag == 3)
    {
        float num = stringToFloat(str);
        if (num < std::numeric_limits<float>::max() && num > -std::numeric_limits<float>::max())
        {
            f = static_cast<float>(num);
            return fToString(f) + "f";
        }
        if (num >= std::numeric_limits<float>::max())
            return "inff";
        if (num <= -std::numeric_limits<float>::min())
            return "-inff";
    }
    return "impossible";
}

std::string convertToDouble(const std::string &str, short flag)
{
    double d;

    if (flag == 0)
    {
        if (str == "nan" || str == "nanf")
            return "nan";
        else if (str == "-inf" || str == "-inff")
            return "-inf";
        else if (str == "+inf" || str == "+inff" || str == "inf" || str == "inff")
            return "inf";
    }
    else if (flag == 1)
    {
        double num = static_cast<double>(str[0]);
        return dToString(num);
    }
    else if (flag == 2 || flag == 3)
    {
        double num = stringToDouble(str);
        if (num < std::numeric_limits<double>::max() && num > -std::numeric_limits<double>::max())
        {
            d = static_cast<double>(num);
            return dToString(d);
        }
        if (num >= std::numeric_limits<double>::max())
            return "inf";
        if (num <= -std::numeric_limits<double>::max())
            return "-inf";
    }
    return "impossible";
}



void ScalarConverter::convert(const std::string &str)
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
