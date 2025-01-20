#include "RPN.hpp"

RPN::RPN() : input(""), result(0)
{
    //std::cout << "Default constructor called" << std::endl;
}

RPN::RPN(std::string input) : input(input), result(0)
{
    //std::cout << "Constructor called" << std::endl;
}

RPN::RPN(const RPN &copy)
{
    //std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

RPN &RPN::operator=(const RPN &copy)
{
    //std::cout << "Assignation operator called" << std::endl;
    if (this != &copy)
    {
        this->input = copy.input;
        this->result = copy.result;
    }
    return *this;
}

RPN::~RPN()
{
    //std::cout << "Destructor called" << std::endl;
}

int checkInput(std::string in)
{
    if (in.empty())
    {
        std::cerr << "empty string" << std::endl;
        return 1;
    }
    for (size_t i = 0; i < in.length(); i++)
    {
        if (!isdigit(in[i]) && in[i] != '+' && in[i] != '-' && in[i] != '*' && in[i] != '/' && !isspace(in[i]))
        {
            std::cerr << "invalid character => " << in[i] << std::endl;
            return 1;
        }
    }
    return 0;
}

int RPN::calculate()
{
    for (size_t i = 0; i < input.length(); i++)
    {
        if (isspace(input[i]))
            continue;
        else if (isdigit(input[i]) && isdigit(input[i + 1]))
        {
            std::cerr << "invalid input: not a single digit number => " << input[i] << input[i+1] << std::endl;
            return 1;
        }
        else if (isdigit(input[i]))
            stack.push(input[i] - '0');
        
        else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
        {
            if (stack.size() < 2)
            {
                std::cerr << "not enough operands" << std::endl;
                return 1;
            }
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            if (input[i] == '+')
                stack.push(b + a);
            else if (input[i] == '-')
                stack.push(b - a);
            else if (input[i] == '*')
                stack.push(b * a);
            else if (input[i] == '/')
            {
                if (a == 0)
                {
                    std::cerr << "division by zero" << std::endl;
                    return 1;
                }
                stack.push(b / a);
            }
        }
    }
    if (stack.size() != 1)
    {
        std::cerr << "too many operands" << std::endl;
        return 1;
    }
    else if (stack.size() == 1)
        result = stack.top();
    
    std::cout << result << std::endl;
    return 0;
}
    
