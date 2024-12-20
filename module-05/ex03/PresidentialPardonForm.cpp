#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("def", 75, 45), target("def")
{
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy), target(copy.target) 
{
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator = (const PresidentialPardonForm &copy)
{
	std::cout << "PresidentialPardonForm copy operator called" << std::endl;
	if (this != &copy)
	{
		this->AForm::operator=(copy);
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialForm", 75, 45), target(target)
{
    std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (this->getSign() == false)
        throw AForm::NotSigned();
    if (executor.getGrade() > this->getExeGrade())
        throw AForm::GradeTooLowException();
    std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
