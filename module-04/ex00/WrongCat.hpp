#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include <iostream>
# include <string>
# include <iomanip>

class   WrongCat : public WrongAnimal
{
    private:
        std::string type;

    public:
        WrongCat();
        WrongCat(const WrongCat &wrongCat);
        WrongCat &operator = (const WrongCat &wrongCat);
        ~WrongCat();

        void makeSound();
};

#endif