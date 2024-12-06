#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>
# include <string>
# include <iomanip>

class   Dog : public Animal
{
    private:
        std::string type;
        Brain *brain;

    public:
        Dog();
        Dog(const Dog &dog);
        Dog &operator = (const Dog &dog);
        ~Dog();

        void makeSound() const;
        std::string getType() const;
};

#endif