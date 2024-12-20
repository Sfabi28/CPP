#include "Form.hpp"

Form::Form() : name("def"), sign(false), signGrade(150), exeGrade(150)
{
    std::cout << "form default constructor called" << std::endl;
}

Form::Form(const Form &copy) : name(copy.name), sign(copy.sign), signGrade(copy.signGrade), exeGrade(copy.exeGrade)
{
    std::cout << "form copy constructor called";
}


Form &Form::operator = (const Form &copy)
{
    if(this != &copy)
        this->sign = copy.sign;
    std::cout << "form copy operator called" << std::endl;
    return (*this);
}

Form::~Form()
{
    std::cout << "form destructor called" << std::endl;
}

Form::Form(const std::string name, const int signGrade, const int exeGrade) : name(name), sign(false), signGrade(signGrade), exeGrade(exeGrade)
{
    if (signGrade < 1 || exeGrade < 1)
        throw Form::GradeTooHighException();
    if (signGrade > 150 || exeGrade > 150)
        throw Form::GradeTooLowException();
    std::cout << "form constructor called" << std::endl;
}

const std::string Form::getName() const
{
    return (this->name);
}

bool  Form::getSign()
{
    return (this->sign);
}

int Form::getSignGrade() const
{
    return (this->signGrade);
}

int Form::getExeGrade() const
{
    return (this->exeGrade);
}

void Form::beSigned(Bureaucrat &buro)
{
    if (sign == true)
        throw Form::AlreadySigned();
    if (buro.getGrade() > this->signGrade)
        throw Bureaucrat::GradeTooLowException();
    sign = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("form grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("form grade too low");
}

const char *Form::AlreadySigned::what() const throw()
{
    return ("form already signed");
}

std::ostream &operator << (std::ostream &out, const Form &form)
{
    out << form.getName() << " form, grade necessary to be signed: " << form.getSignGrade() << ", grade necessary to be executed: " << form.getExeGrade() << std::endl;
    return (out);
}