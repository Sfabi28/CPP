#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("def", 75, 45), target("def")
{
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), target(copy.target) 
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator = (const RobotomyRequestForm &copy)
{
	std::cout << "RobotomyRequestForm copy operator called" << std::endl;
	if (this != &copy)
	{
		this->AForm::operator=(copy);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyForm", 75, 45), target(target)
{
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (this->getSign() == false)
        throw AForm::NotSigned();
    if (executor.getGrade() > this->getExeGrade())
        throw AForm::GradeTooLowException();
    std::cout << "brrrrrr bzzzzz trrrrrr prrrrr crrrrr zzzzzzzzzzzzzzzzzzz" << std::endl;
    if (rand() % 2)
        std::cout << target << " has been robotomized" << std::endl;
    else
        std::cout << target << " robotomization has failed" << std::endl;
}
