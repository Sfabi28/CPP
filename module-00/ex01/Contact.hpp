#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Contact
{
    private:
        std::string name;
        std::string lastName;
        std::string nickname;
        std::string number;
        std::string darkestSecret;

    public:
        Contact();
        ~Contact();
        std::string getField(int FieldNumber);
        void setField(std::string line, int FieldNumber);
};

#endif