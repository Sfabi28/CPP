#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Intern intern;
	Bureaucrat bureaucrat("bureaucrat", 1);
	AForm *form;

	std::cout << std::endl;
	form = intern.makeForm("shrubbery", "target");
	bureaucrat.signForm(*form);
	bureaucrat.executeForm(*form);
	if (form)
		delete form;

	form = intern.makeForm("robotomy", "target");
	bureaucrat.signForm(*form);
	bureaucrat.executeForm(*form);
	if (form)
		delete form;

	form = intern.makeForm("presidential", "target");
	bureaucrat.signForm(*form);
	bureaucrat.executeForm(*form);
	if (form)
		delete form;

	form = intern.makeForm("hflghzlsfhglkzhfg", "target");
	if (form)
		delete form;
	std::cout << std::endl;
	return 0;
}