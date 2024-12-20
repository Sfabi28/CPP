#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class AForm;

class PresidentialPardonForm : public AForm
{
    private:
        const std::string target;
    
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &copy);
        PresidentialPardonForm &operator = (const PresidentialPardonForm &copy);
        ~PresidentialPardonForm();

        PresidentialPardonForm(const std::string target);

        void execute(Bureaucrat const &executor) const;
};

#endif