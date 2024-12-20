#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("def", 145, 137), target("def")
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), target(copy.target) 
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator = (const ShrubberyCreationForm &copy)
{
	std::cout << "ShrubberyCreationForm copy operator called" << std::endl;
	if (this != &copy)
	{
		this->AForm::operator=(copy);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyForm", 145, 137), target(target)
{
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (getSign() == false)
        throw AForm::NotSigned();
    if (executor.getGrade() > this->getExeGrade())
        throw AForm::GradeTooLowException();
    std::ofstream file((target + "_shrubbery").c_str());
    if (!file)
        throw ShrubberyCreationForm::FileNotOpened();
    file << "         *                            *" << std::endl;
    file << "        ***                          ***" << std::endl;
    file << "       *O***                        ***O*" << std::endl;
    file << "      ****O**                      **O****" << std::endl;
    file << "     *O*******                    *******O*" << std::endl;
    file << "    *******O***                  ****O******" << std::endl;
    file << "   ****O********                **O****O*****" << std::endl;
    file << "  *******O*******              ************O**" << std::endl;
    file << " **O**********O***            ***O******O******" << std::endl;
    file << "*******************          *******************" << std::endl;
    file << "         |                             |" << std::endl;
    file << "         |                             |" << std::endl;
    file << "         |                             |" << std::endl;

    file.close();
}

const char *ShrubberyCreationForm::FileNotOpened::what() const throw()
{
    return ("can't open file");
}