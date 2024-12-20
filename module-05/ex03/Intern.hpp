#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern &copy);
        Intern &operator = (const Intern &copy);
        ~Intern();

        AForm* makeForm(const std::string formName, const std::string target);
};

#endif