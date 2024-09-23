#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
    private:
        Contact arr[8];
        int     first;
        int     total;

    public:
        PhoneBook();
        ~PhoneBook();
        void add();
        void search();
};

#endif