#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include <iomanip>

class   Animal
{
    protected:
        std::string type;
    
    public:
        Animal();
        Animal(const Animal &animal);
        Animal &operator = (const Animal &animal);
        virtual ~Animal();
    
        virtual void makeSound() const;
        virtual std::string getType() const;
};

#endif