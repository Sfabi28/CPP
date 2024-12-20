#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called\n";
}

Intern::Intern(Intern const &copy)
{
	std::cout << "Intern copy constructor called\n";
	*this = copy;
}

Intern &Intern::operator=(Intern const &copy)
{
	std::cout << "Intern copy operator called\n";
	if (this != &copy)
	{
		*this = copy;
	}
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called\n";
}

AForm* Intern::makeForm(const std::string formName, const std::string target)
{
    std::string names[3] = {"shrubbery", "robotomy", "presidential"};
    short i = 0;

    while(i < 3)
    {
        if (names[i] == formName)
            break ;
		i++;
    }

	switch(i)
	{
		case 0:
			return (new ShrubberyCreationForm(target));
		case 1:
			return new RobotomyRequestForm(target);
		case 2:
			return new PresidentialPardonForm(target);
	}
	std::cout << "Intern cannot create " << formName << " because it is an unknown form" << std::endl;
	std::cout << "please try to create: shrubbery, robotomy, presidential" << std::endl;
	return NULL;
}
