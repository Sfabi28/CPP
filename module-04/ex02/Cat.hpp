#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>
# include <string>
# include <iomanip>

class   Cat : public Animal
{
    private:
        std::string type;
        Brain *brain;

    public:
        Cat();
        Cat(const Cat &cat);
        Cat &operator = (const Cat &cat);
        ~Cat();

        void makeSound() const;
        std::string getType() const;
};

#endif