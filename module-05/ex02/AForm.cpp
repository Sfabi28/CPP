#include "AForm.hpp"

AForm::AForm() : name("def"), sign(false), signGrade(150), exeGrade(150)
{
    std::cout << "Aform default constructor called" << std::endl;
}

AForm::AForm(const AForm &copy) : name(copy.name), sign(copy.sign), signGrade(copy.signGrade), exeGrade(copy.exeGrade)
{
    std::cout << "Aform copy constructor called";
}


AForm &AForm::operator = (const AForm &copy)
{
    if(this != &copy)
        this->sign = copy.sign;
    std::cout << "Aform copy operator called" << std::endl;
    return (*this);
}

AForm::~AForm()
{
    std::cout << "Aform destructor called" << std::endl;
}

AForm::AForm(const std::string name, const int signGrade, const int exeGrade) : name(name), sign(false), signGrade(signGrade), exeGrade(exeGrade)
{
    if (signGrade < 1 || exeGrade < 1)
        throw AForm::GradeTooHighException();
    if (signGrade > 150 || exeGrade > 150)
        throw AForm::GradeTooLowException();
    std::cout << "Aform constructor called" << std::endl;
}

const std::string AForm::getName() const
{
    return (this->name);
}

bool  AForm::getSign() const
{
    return (this->sign);
}

int AForm::getSignGrade() const
{
    return (this->signGrade);
}

int AForm::getExeGrade() const
{
    return (this->exeGrade);
}

void AForm::beSigned(Bureaucrat &buro)
{
    if (sign == true)
        throw AForm::AlreadySigned();
    if (buro.getGrade() > this->signGrade)
        throw Bureaucrat::GradeTooLowException();
    sign = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Aform grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Aform grade too low");
}

const char *AForm::AlreadySigned::what() const throw()
{
    return ("form already signed");
}

const char *AForm::NotSigned::what() const throw()
{
    return ("form not signed");
}

std::ostream &operator << (std::ostream &out, const AForm &form)
{
    out << form.getName() << " Aform, grade necessary to be signed: " << form.getSignGrade() << ", grade necessary to be executed: " << form.getExeGrade() << std::endl;
    return (out);
}