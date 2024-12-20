#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <fstream>
# include <cstdlib>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool    sign;
        const int signGrade;
        const int exeGrade;

    public:
        AForm();
        AForm(const AForm &copy);
        AForm &operator = (const AForm &copy);
        virtual ~AForm();

        AForm(const std::string name, const int signGrade, const int exeGrade);

        const std::string getName() const;
        bool  getSign() const;
        int getSignGrade() const;
        int getExeGrade() const;
        void beSigned(Bureaucrat &buro);

        virtual void execute(Bureaucrat const & executor) const = 0;

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

        class NotSigned : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator << (std::ostream &out, const AForm &form);

#endif