#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>
# include <iomanip>

class   WrongAnimal
{
    protected:
        std::string type;
    
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &wrongAnimal);
        WrongAnimal &operator = (const WrongAnimal &wrongAnimal);
        ~WrongAnimal();
    
        virtual void makeSound();
};

#endif