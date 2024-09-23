#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->first = 0;
    this->total = 0;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::add()
{
    std::string str;

    if(this->total > 7)
    {
        this->total = this->first;
        if (this->first < 7)
            this->first++;
        else
            this->first = 0;
    }

    while (true)
    {
        std::cout << "enter contact name: "; //has to be alphabetics only
        std::cin >> str;
        if (std::cin.eof())
            return;
        else if (str.length() < 1)
            std::cout << "Invalid name" << std::endl;
        else if (str.find_first_not_of("abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ") != std::string::npos)
                std::cout << "Invalid name" << std::endl;
        else
        {
            this->arr[this->total].setField(str, 0);
            break;
        }
    }
    while (true)
    {
        std::cout << "enter contact last name: "; //has to be alphabetics only
        std::cin >> str;
        if (std::cin.eof())
            return;
        else if (str.length() < 1)
            std::cout << "Invalid name" << std::endl;
        else if (str.find_first_not_of("abcdefghijklmnopqrstuvwxyz 'ABCDEFGHIJKLMNOPQRSTUVWXYZ") != std::string::npos)
                std::cout << "Invalid name" << std::endl;
        else
        {
            this->arr[this->total].setField(str, 1);
            break;
        }
    }
    while (true)
    {
        std::cin.ignore(10000, '\n');
        std::cout << "enter contact nickname: ";
        std::getline(std::cin, str);
        if (std::cin.eof())
            return;
        else if (str.length() < 1)
            std::cout << "Invalid name" << std::endl;
        else
        {
            this->arr[this->total].setField(str, 2);
            break;
        }
    }
    while (true)
    {
        std::cout << "enter contact number: "; //has to be numeric only
        std::cin >> str;
        if (std::cin.eof())
            return;
        else if (str.length() < 9 || str.length() > 10)
            std::cout << "the phone number has to be 9 or 10 digits long" << std::endl;
        else if (str.find_first_not_of("0123456789") != std::string::npos)
                std::cout << "Invalid number" << std::endl;
        else
        {
            this->arr[this->total].setField(str, 3);
            break;
        }
    }
    while (true)
    {
        std::cin.ignore(10000, '\n');
        std::cout << "enter contact darkest secret: ";
        std::getline(std::cin, str);
        if (std::cin.eof())
            return;
        else if (str.length() < 1)
            std::cout << "Invalid name" << std::endl;
        else
        {
            this->arr[this->total].setField(str, 4);
            break;
        }
    }
    this->total++;
}

void stampContact(Contact contact)
{
    for(int i=0; i < 5; i++)
        std::cout << contact.getField(i) << std::endl;
}


void PhoneBook::search()
{
    int input;

    std::cout << "—————————————————————————————————————————————" << std::endl;
    std::cout << "|  index   |first name| last name| nickname |" << std::endl;
    std::cout << "|——————————|——————————|——————————|——————————|" << std::endl;
    for (int i=0; i < (this->total+(8 - this->total)*(this->first != 0)); i++)
    {
        std::cout << "|" << std::setw(10) << i + 1 << "|";
        for (int j = 0; j < 3; j++)
        {
            if (this->arr[i].getField(j).length() > 10)
                std::cout << this->arr[i].getField(j).substr(0, 9) << ".|";
            else
                std::cout << std::setw(10) << this->arr[i].getField(j) << "|";
        }
        std::cout << std::endl;
    }
    std::cout << "—————————————————————————————————————————————" << std::endl;
    if (this->total +(8 - this->total)*(this->first != 0) == 0)
        return;
    while (true)
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "insert index to view: ";
        std::cin >> input;
        std::cout << input <<std::endl;
        if (std::cin.eof())
            return;
        if (input > 0 && input <= this->total +(8 - this->total)*(this->first != 0))
        {
            stampContact(this->arr[input - 1]);
            break;
        }
        std::cout << "insert a valid index" << std::endl;
    }
}
