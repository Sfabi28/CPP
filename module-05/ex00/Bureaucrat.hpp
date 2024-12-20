#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat
{
    private:
        const std::string name;
        int grade;

    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat &operator = (const Bureaucrat &copy);
        ~Bureaucrat();

        Bureaucrat(const std::string &name, int grade);

        const std::string getName() const;
		short getGrade() const;
		void incrementGrade();
		void decrementGrade();   



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
};

std::ostream &operator << (std::ostream &out, const Bureaucrat &bureaucrat);

#endif