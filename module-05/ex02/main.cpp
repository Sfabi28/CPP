#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat *ugo = new Bureaucrat("Ugo", 140);
    Bureaucrat *paolo = new Bureaucrat("Paolo", 70);
    Bureaucrat *giuseppe = new Bureaucrat("Giuseppe", 1);  
	
    ShrubberyCreationForm shrubbery("Sbongebob");
	RobotomyRequestForm robotomy("Squidward");
	PresidentialPardonForm presidential("Mr. Krab");

    try
	{
		std:: cout << std::endl;
		ugo->signForm(shrubbery);
		ugo->executeForm(shrubbery);
		paolo->executeForm(shrubbery);
		paolo->signForm(robotomy);
		paolo->executeForm(robotomy);
		giuseppe->executeForm(robotomy);
		// giuseppe->executeForm(robotomy);
		// giuseppe->executeForm(robotomy);
		// giuseppe->executeForm(robotomy);
		giuseppe->signForm(presidential);
		giuseppe->executeForm(presidential);
		std:: cout << std::endl;
	}

	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

    delete paolo;
    delete giuseppe;
	delete ugo;

    return (0);
}