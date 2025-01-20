#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>

class RPN
{
    private:
        std::stack<int> stack;
        std::string input;
        int result;
    
    public:
        RPN();
        RPN(std::string input);
        RPN(const RPN &copy);
        RPN &operator=(const RPN &copy);
        ~RPN();

        int calculate();
};
    
int checkInput(std::string in);

#endif
