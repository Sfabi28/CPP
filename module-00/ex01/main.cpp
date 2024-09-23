#include "PhoneBook.hpp"

int main()
{
    PhoneBook myPhoneBook;
    std::string input;

    while (true)
    {
        std::cout << "please enter a command: ADD, SEARCH, EXIT: ";
        std::cin >> input;
        if (std::cin.eof())
            break;
        if (input == "EXIT")
            break;
        else if (input == "ADD")
            myPhoneBook.add();
        else if (input == "SEARCH")
            myPhoneBook.search();
        else
            std::cout << "Invalid command" << std::endl; 
    }
    return 0;
}