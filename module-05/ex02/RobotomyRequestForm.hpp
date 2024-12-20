#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class AForm;

class RobotomyRequestForm : public AForm
{
    private:
        const std::string target;
    
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &copy);
        RobotomyRequestForm &operator = (const RobotomyRequestForm &copy);
        ~RobotomyRequestForm();

        RobotomyRequestForm(const std::string target);

        void execute(Bureaucrat const &executor) const;
};

#endif