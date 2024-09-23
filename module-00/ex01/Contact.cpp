#include "PhoneBook.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::setField(std::string line, int FieldNumber)
{
    switch(FieldNumber)
    {
        case(0):
        {
            this->name = line;
            break;
        }
        case(1):
        {
            this->lastName = line;
            break;
        }
        case(2):
        {
            this->nickname = line;
            break;
        }
        case(3):
        {
            this->number = line;
            break;
        }
        case(4):
            this->darkestSecret = line;
    }
}

std::string Contact::getField(int FieldNumber)
{
    switch(FieldNumber)
    {
        case(0):
            return (this->name);
        case(1):
            return (this->lastName);
        case(2):
            return (this->nickname);
        case(3):
            return (this->number);
        case(4):
            return (this->darkestSecret);
    }
    return ("");
}