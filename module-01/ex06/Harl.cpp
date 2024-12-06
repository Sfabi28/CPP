#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void    Harl::debug()
{
   std::cout << "[ DEBUG ]" << std::endl << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void    Harl::info()
{
    std::cout << "[ INFO ]" << std::endl <<  "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void    Harl::warning()
{
    std::cout << "[ WARNING ]" << std::endl <<  "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void    Harl::error()
{
    std::cout << "[ ERROR ]" << std::endl <<  "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::complain(std::string level)
{
    int flag = 5;

	struct 
	{
		std::string level;
		void (Harl::*function)(void);
	}
    
    levels[] = 
	{
		{"DEBUG", &Harl::debug},
		{"INFO", &Harl::info},
		{"WARNING", &Harl::warning},
		{"ERROR", &Harl::error}
	};

    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i].level)
        {
            flag = i;
            break;
        }
    }

	switch(flag)
	{
		case 0:
			(this->*levels[0].function)();
		case 1:
			(this->*levels[1].function)();
		case 2:
			(this->*levels[2].function)();
		case 3:
			(this->*levels[3].function)();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}