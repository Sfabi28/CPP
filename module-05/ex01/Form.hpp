#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool    sign;
        const int signGrade;
        const int exeGrade;

    public:
        Form();
        Form(const Form &copy);
        Form &operator = (const Form &copy);
        ~Form();

        Form(const std::string name, const int signGrade, const int exeGrade);

        const std::string getName() const;
        bool  getSign();
        int getSignGrade() const;
        int getExeGrade() const;
        void beSigned(Bureaucrat &buro);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();  
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        
        class AlreadySigned : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator << (std::ostream &out, const Form &form);

#endif