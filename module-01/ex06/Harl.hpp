#ifndef Harl_HPP
# define Harl_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <iomanip>

class   Harl
{
    private:
        void    debug();
        void    info();
        void    warning();
        void    error();
    public:
        Harl();
        ~Harl();

        void    complain(std::string level);
        void    switchComplain(int level);
};

#endif